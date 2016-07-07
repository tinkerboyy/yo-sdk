<?php

/**
 * @file
 * Contains RestfulTopicsResource.
 */

require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

class AGRestfulEntityBase extends RestfulEntityBase {
  use AGPublicUserAccessCheck;

  public function stripTags($value) {
    return strip_tags($value, '<a><b><strong><i><u><em><ul><ol><li><a><br><p><div>');
  }

  public function entity_load($entity_type, $ids = FALSE, $conditions = array(), $reset = FALSE) {
    if ($reset) {
      entity_get_controller($entity_type)->resetCache();
    }

    $getCtrl = entity_get_controller($entity_type);

    $cacheGet = new ReflectionMethod(get_class($getCtrl), 'cacheGet');
    $cacheSet = new ReflectionMethod(get_class($getCtrl), 'cacheSet');
    $buildQuery = new ReflectionMethod(get_class($getCtrl), 'buildQuery');

    $cacheGet->setAccessible(true);
    $cacheSet->setAccessible(true);
    $buildQuery->setAccessible(true);

    $entityInfo = entity_get_info($entity_type);
    $revisionKey = $entityInfo['entity keys']['revision'] ? $entityInfo['entity keys']['revision'] : FALSE;
    $idKey = $entityInfo['entity keys']['id'];
    $cache = !empty($entityInfo['static cache']);

    $entities = array();

    // Revisions are not statically cached, and require a different query to
    // other conditions, so separate the revision id into its own variable.
    if ($revisionKey && isset($conditions[$revisionKey])) {
      $revision_id = $conditions[$revisionKey];
      unset($conditions[$revisionKey]);
    }
    else {
      $revision_id = FALSE;
    }

    // Create a new variable which is either a prepared version of the $ids
    // array for later comparison with the entity cache, or FALSE if no $ids
    // were passed. The $ids array is reduced as items are loaded from cache,
    // and we need to know if it's empty for this reason to avoid querying the
    // database when all requested entities are loaded from cache.
    $passed_ids = !empty($ids) ? array_flip($ids) : FALSE;
    // Try to load entities from the static cache, if the entity type supports
    // static caching.
    if ($cache && !$revision_id) {
      $entities += $cacheGet->invoke($getCtrl, $ids, $conditions);
      // If any entities were loaded, remove them from the ids still to load.
      if ($passed_ids) {
        $ids = array_keys(array_diff_key($passed_ids, $entities));
      }
    }

    // Load any remaining entities from the database. This is the case if $ids
    // is set to FALSE (so we load all entities), if there are any ids left to
    // load, if loading a revision, or if $conditions was passed without $ids.
    if ($ids === FALSE || $ids || $revision_id || ($conditions && !$passed_ids)) {
      // Build the query.
      $query = $buildQuery->invoke($getCtrl, $ids, $conditions, $revision_id);
      $queried_entities = $query
        ->execute()
        ->fetchAllAssoc($idKey);
    }



    // Pass all entities loaded from the database through $this->attachLoad(),
    // which attaches fields (if supported by the entity type) and calls the
    // entity type specific load callback, for example hook_node_load().
    if (!empty($queried_entities)) {
      // Attach fields.
      if ($entityInfo['fieldable']) {
        if ($revision_id) {
          field_attach_load_revision($entity_type, $queried_entities);
        }
        else {
          field_attach_load($entity_type, $queried_entities);
        }
      }

      // Call hook_entity_load().
      foreach (module_implements('entity_load') as $module) {
        if($module === 'workbench_moderation') {
          continue;
        }
        $function = $module . '_entity_load';
        $function($queried_entities, $entity_type);
      }
      // Call hook_TYPE_load(). The first argument for hook_TYPE_load() are
      // always the queried entities, followed by additional arguments set in
      // $this->hookLoadArguments.
      $args = array($queried_entities);
      foreach (module_implements($entityInfo['load hook']) as $module) {
        if($module === 'workbench_moderation') {
          continue;
        }
        call_user_func_array($module . '_' . $entityInfo['load hook'], $args);
      }

      $entities += $queried_entities;
    }

    if ($cache) {
      // Add entities to the cache if we are not loading a revision.
      if (!empty($queried_entities) && !$revision_id) {
        $cacheSet->invoke($getCtrl, $queried_entities);
      }
    }

    // Ensure that the returned array is ordered the same as the original
    // $ids array if this was passed in and remove any invalid ids.
    if ($passed_ids) {
      // Remove any invalid ids from the array.
      $passed_ids = array_intersect_key($passed_ids, $entities);
      foreach ($entities as $entity) {
        $passed_ids[$entity->{$idKey}] = $entity;
      }
      $entities = $passed_ids;
    }

    return $entities;

  }

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields_extend = array(
      'author' => array(
        'property' => 'author',
        'process_callbacks' => array( array( $this, 'processUser' ) )
      ),
      'uid' => array(
        'property' => 'author',
        'process_callbacks' => array(array($this, 'getUserId'))
      ),
      'status' => array(
        'property' => 'status'
      )
    );

    return array_merge($public_fields, $public_fields_extend);
  }

  public function intval($value = NULL) {
    return $value == NULL ? NULL : intval($value);
  }

  public function getUserId($user) {
    return $user->uid;
  }

  public function processUser($user) {
    $processedUser = array();

    $realname = db_select('realname')
      ->fields('realname', array('realname'))
      ->condition('uid', intVal($user->uid))
      ->execute()
      ->fetchField();

    $agency = db_select('field_data_field_user_cas_agency')
    ->fields('field_data_field_user_cas_agency', array('field_user_cas_agency_value'))
    ->condition('entity_id', intVal($user->uid))
    ->execute()
    ->fetchField();

    $processedUser = array(
      'uid' => $user->uid,
      'agency' => isset($agency) && $agency !== ''  && $agency !== false ? $agency : null,
      'name' => isset($realname) && $realname !== '' ? $realname : $user->name,
      'mail' => $user->mail,
      'created' => intval($user->created),
      'access' => intval($user->access),
      'login' => intval($user->login),
      'online' => _author_pane_is_user_online($user->uid),
      'picture' => isset($user->picture) ? $this->processFile($user->picture) : $user->picture
    );

    return $processedUser;
  }

  public function processFile($file) {
    $file = (array) $file;
    return array(
      'url' => file_create_url($file['uri']),
      'filename' => $file['filename'],
      'filemime' => $file['filemime'],
      'filesize' => $file['filesize'],
      'type' => $file['type']
    );
  }

  public function draggableWeight($wrapper) {
    $nid = $wrapper->nid->value();
    $queryString = 'SELECT weight FROM draggableviews_structure WHERE entity_id = :nid';

    $weight = db_query($queryString, array(':nid' => $nid))
      ->fetchCol()[0];

    return ($weight === null ? 100000 : intval($weight));
  }

   public function since_modified($wrapper) {
      $changed = $wrapper->changed->value(); 
      return time() - $changed;
    }

    public function expired($wrapper) {
      $expiration = $wrapper->field_expiration_date->value(); 
      return time() > $expiration;
    }

  public function putEntity($entity_id) {
    return $this->updateEntity($entity_id, FALSE);
  }

  /**
   * Override RestfulEntityBase to add patch to clear the entity from render cache
   */
  protected function updateEntity($id, $null_missing_fields = FALSE) {
    $entity_id = $this->getEntityIdByFieldId($id);
    $this->isValidEntity('update', $entity_id);

    $wrapper = entity_metadata_wrapper($this->entityType, $entity_id);

    $this->setPropertyValues($wrapper, $null_missing_fields);

    // Set the HTTP headers.
    $this->setHttpHeaders('Status', 201);

    if (!empty($wrapper->url) && $url = $wrapper->url->value()) {
      $this->setHttpHeaders('Location', $url);
    }

    //US6140: Patch to clear cache entry for this entity
    //Clear the cache for this user/role so update request will return updated
    //entity not the cached one
    $cacheContext = $this->getEntityCacheTags($entity_id);
    $cid = $this->generateCacheId($cacheContext);
    $this->cacheInvalidate($cid);
    //End patch

    return array($this->viewEntity($wrapper->getIdentifier()));
  }

  public function entityPreSave($wrapper) {
    $entity_info = $this->getEntityInfo();
    $id_key = $entity_info['entity keys']['id'];
    $id = $wrapper->{$id_key}->value();
    if (!empty($id)) {
      // Node is already saved.
      return;
    }
    $wrapper->author->set($this->getAccount());
    $wrapper->status->set(0);
  }



  /**
   * @Override
   * Overrides the range parameter with the URL value if any.
   *
   * @throws RestfulBadRequestException
   */
  protected function overrideRange() {
    $request = $this->getRequest();
    if (!empty($request['range'])) {
      $url_params = $this->getPluginKey('url_params');
      if (!$url_params['range']) {
        throw new \RestfulBadRequestException('The range parameter has been disabled in server configuration.');
      }
      if (strcasecmp($request['range'], 'all') !== 0) {
        if (!ctype_digit((string) $request['range']) || $request['range'] < 1) {
          throw new \RestfulBadRequestException('"Range" property should be numeric and higher than 0.');
        }
        // If there is a valid range property in the request override the range.
        $this->setRange($request['range']);
      }
    }
  }

   /**
   * @Override
   * Set correct page (i.e. range) for the query for list.
   *
   * Determine the page that should be seen. Page 1, is actually offset 0 in the
   * query range.
   *
   * @param \SelectQuery $query
   *   The query object.
   *
   * @throws \RestfulBadRequestException
   *
   * @see \RestfulEntityBase::getQueryForList
   */
  protected function queryForListPagination(\EntityFieldQuery $query) {
    $request = $this->getRequest();

    if (!(isset($request['range']) && strcasecmp($request['range'], 'all') === 0)) {
      parent::queryForListPagination($query);
    }
  }

  /**
   * Overrides RestfulEntityBase::getQueryForList().
   *
   * Expose only published nodes. 
   * If user has public role then only display content marked as public
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    $query->propertyCondition('status', NODE_PUBLISHED);

    if($this->isPublicUser()) {
      $query->addMetaData('account', user_load(1) );
      $query->fieldCondition('field_public_private', 'value', true, '=');
    }
    return $query;
  }

  protected function checkEntityAccess($op, $entity_type, $entity) {
    if($this->isPublicUser()) {
      $wrappedEntity = entity_metadata_wrapper($entity_type, $entity);
      $publicFlag = $wrappedEntity->field_public_private->value();
      if ($publicFlag !== true) return false;
    }

    if($op === 'create') {
      $account = $this->getAccount();
      return isset($account);
    }

    if($op === 'delete') {
      $account = $this->getAccount();
      return isset($account);
    }

    return parent::checkEntityAccess($op, $entity_type, $entity);
  }

  protected function checkPropertyAccess($op, $public_field_name, EntityMetadataWrapper $property_wrapper, EntityMetadataWrapper $wrapper) {
    $entity_info = $this->getEntityInfo();
    $id_key = $entity_info['entity keys']['id'];
    $id = $wrapper->{$id_key}->value();

    if(empty($id) && $op === 'edit') {
      $account = $this->getAccount();
      return isset($account);
    }

    return parent::checkPropertyAccess($op, $public_field_name, $property_wrapper, $wrapper);
  }

  public function setRequest(array $request = array()) {
    unset($request['created']);
    unset($request['changed']);
    unset($request['timestamp']);
    unset($request['author']);
    unset($request['id']);

    parent::setRequest($request);
  }

  /**
   * @Override
   * Set properties of the entity based on the request, and save the entity.
   *
   * @param EntityMetadataWrapper $wrapper
   *   The wrapped entity object, passed by reference.
   * @param bool $null_missing_fields
   *   Determine if properties that are missing form the request array should
   *   be treated as NULL, or should be skipped. Defaults to FALSE, which will
   *   set the fields to NULL.
   *
   * @throws RestfulBadRequestException
   */
  protected function setPropertyValues(EntityMetadataWrapper $wrapper, $null_missing_fields = FALSE) {
    $request = $this->getRequest();

    static::cleanRequest($request);
    $save = FALSE;

    foreach ($this->getPublicFields() as $public_field_name => $info) {
      if (!empty($info['create_or_update_passthrough']) || empty($info['property'])) {
        // Allow passing the value in the request.
        //  +
        // We may have for example an entity with no label property, but with a
        // label callback. In that case the $info['property'] won't exist, so
        // we skip this field.
        continue;
      }

      $property_name = $info['property'];
      if (!isset($request[$public_field_name])) {
        // No property to set in the request.
        if ($null_missing_fields && $this->checkPropertyAccess('edit', $public_field_name, $wrapper->{$property_name}, $wrapper)) {
          // We need to set the value to NULL.
          $wrapper->{$property_name}->set(NULL);
        }
        continue;
      }

      if (!$this->checkPropertyAccess('edit', $public_field_name, $wrapper->{$property_name}, $wrapper)) {
        throw new \RestfulBadRequestException(format_string('Property @name cannot be set.', array('@name' => $public_field_name)));
      }

      $field_value = $this->propertyValuesPreprocess($property_name, $request[$public_field_name], $public_field_name);

      $wrapper->{$property_name}->set($field_value);
      $save = TRUE;
    }

    if (!$save) {
      // No request was sent.
      throw new \RestfulBadRequestException('No valid values were sent with the request');
    }

    // Allow changing the entity just before it's saved. For example, setting
    // the author of the node entity.
    $this->entityPreSave($wrapper);

    $this->entityValidate($wrapper);

    $wrapper->save();
  }

  /**
   * {@inheritdoc}
   */
  public function viewEntity($id) {
    $entity_id = $this->getEntityIdByFieldId($id);
    $request = $this->getRequest();

    $cached_data = $this->getRenderedCache(array(
      'et' => $this->getEntityType(),
      'ei' => $entity_id,
    ));
    if (!empty($cached_data->data)) {
      return $cached_data->data;
    }

    if (!$this->isValidEntity('view', $entity_id)) {
      return;
    }

    $wrapper = entity_metadata_wrapper($this->entityType, $entity_id);
    $wrapper->language($this->getLangCode());
    $values = array();

    $limit_fields = !empty($request['fields']) ? explode(',', $request['fields']) : array();

    foreach ($this->getPublicFields() as $public_field_name => $info) {
      if ($limit_fields && !in_array($public_field_name, $limit_fields)) {
        // Limit fields doesn't include this property.
        continue;
      }

      $value = NULL;

      if ($info['callback']) {
        $value = static::executeCallback($info['callback'], array($wrapper));
      }
      else {
        // Exposing an entity field.
        $property = $info['property'];
        $sub_wrapper = $info['wrapper_method_on_entity'] ? $wrapper : $wrapper->{$property};

        // Check user has access to the property.
        if ($property && !$this->checkPropertyAccess('view', $public_field_name, $sub_wrapper, $wrapper)) {
          continue;
        }

        if (empty($info['formatter'])) {
          if ($sub_wrapper instanceof EntityListWrapper) {
            // Multiple values.
            foreach ($sub_wrapper as $item_wrapper) {
              $value[] = $this->getValueFromProperty($wrapper, $item_wrapper, $info, $public_field_name);
            }
          }
          else {
            // Single value.
            $value = $this->getValueFromProperty($wrapper, $sub_wrapper, $info, $public_field_name);
          }
        }
        else {
          // Get value from field formatter.
          $value = $this->getValueFromFieldFormatter($wrapper, $sub_wrapper, $info);
        }
      }

      if ($info['process_callbacks']) {
        foreach ($info['process_callbacks'] as $process_callback) {
          $value = static::executeCallback($process_callback, array($value));
        }
      }

      $values[$public_field_name] = $value;
    }

    $this->setRenderedCache($values, array(
      'et' => $this->getEntityType(),
      'ei' => $entity_id,
    ));
    return $values;
  }

  /**
   * Get a list of entities.
   *
   * @return array
   *   Array of entities, as passed to RestfulEntityBase::viewEntity().
   *
   * @throws RestfulBadRequestException
   */
  public function getList() {
    $request = $this->getRequest();
    $autocomplete_options = $this->getPluginKey('autocomplete');
    if (!empty($autocomplete_options['enable']) && isset($request['autocomplete']['string'])) {
      // Return autocomplete list.
      return $this->getListForAutocomplete();
    }

    $entity_type = $this->entityType;
    $result = $this
      ->getQueryForList()
      ->execute();

    if (empty($result[$entity_type])) {
      return array();
    }

    $ids = array_keys($result[$entity_type]);

    // Pre-load all entities if there is no render cache.
    $cache_info = $this->getPluginKey('render_cache');
    if (!$cache_info['render']) {
      $this->entity_load($entity_type, $ids);
    }

    $return = array();

    // If no IDs were requested, we should not throw an exception in case an
    // entity is un-accessible by the user.
    foreach ($ids as $id) {
      if ($row = $this->viewEntity($id)) {
        $return[] = $row;
      }
    }

    return $return;
  }


}
