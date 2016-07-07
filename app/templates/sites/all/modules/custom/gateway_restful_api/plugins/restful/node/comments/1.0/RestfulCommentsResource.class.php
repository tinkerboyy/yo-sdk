<?php

class RestfulCommentsResource extends \AGRestfulEntityBase {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */

   /**
   *
   * @SWG\Definition(
   *   definition="comments",
   *   @SWG\Property(
   *     property="id",
   *     type="integer",
   *     description="Id of comments"
   *   ),
   *   @SWG\Property(
   *     property="nid",
   *     type="integer",
   *     description="Drupal Node Id of comments"
   *   ),
   *   @SWG\Property(
   *     property="parentType",
   *     type="string",
   *     description="Type of Parent Item (Forum, articles, etc.,)"
   *   ),
   *   @SWG\Property(
   *     property="parentTitle",
   *     type="string",
   *     description="Title of Parent Item (Forum, articles, etc.,)"
   *   ),
   *   @SWG\Property(
   *     property="pid",
   *     type="string",
   *     description=" "
   *   ),
   *   @SWG\Property(
   *     property="uid",
   *     type="integer",
   *     description="User Id for the comments"
   *   ),
   *   @SWG\Property(
   *     property="author",
   *     type="object",
   *     ref="#/definitions/User",
   *     description="Provides author/user information for the comments"
   *   ),
   *   @SWG\Property(
   *     property="is_new",
   *     type="boolean",
   *     description="Represents whether its new comment or not"
   *   ),
   *   @SWG\Property(
   *     property="has_children",
   *     type="boolean",
   *     description="Represents whether comment has children or not"
   *   ),
   *   @SWG\Property(
   *     property="created",
   *     type="integer",
   *     description="Comment created date"
   *   ),
   *   @SWG\Property(
   *     property="edited",
   *     type="integer",
   *     description="Comment edited date"
   *   ),
   * 	@SWG\Property(
   * 	  property="body",
   * 	  type="string",
   * 	  description="Body text of comment"
   * 	),
   * 	@SWG\Property(
   * 	  property="status",
   * 	  type="integer",
   * 	  description="Status of comment"
   * 	),
   * 	@SWG\Property(
   * 	  property="type",
   * 	  type="string",
   * 	  description="Type of comment"
   * 	)
   * )
   */
  public function publicFieldsInfo() {
    $intFormatter = array( $this, 'intval' );
    $entity_info = $this->getEntityInfo();

    return array(
      'id' => array('property' => 'cid'),
      'nid' => array(
        'property' => 'node',
        'sub_property' => 'nid'
      ),
      'parentType' => array(
        'property' => 'node',
        'sub_property' => 'type'
      ),
      'parentTitle' => array(
        'property' => 'node',
        'sub_property' => 'title'
      ),
      'pid' => array(
        'property' => 'parent',
        'sub_property' => 'cid'
      ),
      'uid' => array(
        'property' => 'author',
        'sub_property' => 'uid'
      ),
      'author' => array(
        'property' => 'author',
        'process_callbacks' => array( array( $this, 'processUser' ) )
      ),
      'is_new' => array(
        'callback' => array($this, 'isNew'),
        'process_callbacks' => array( array( $this, 'stripTags' ) )
      ),
      'has_children' => array(
        'callback' => array($this, 'hasChildren')
      ),
      'created' => array(
        'property' => 'created',
        'process_callbacks' => array($intFormatter)
      ),
      'edited' => array(
        'callback' => array($this, 'changed')
      ),
      'body' => array(
        'property' => 'comment_body',
        'process_callbacks' => array( array( $this, 'stripTags' ) )
      ),
      'status' => array(
        'property' => 'status'
      ),
      'type' => array(
        'property' => 'node',
        'process_callbacks' => array( array($this, getType) )
      )

    );
  }
  
  public function stripTags($value) {
    $value = parent::stripTags($value);
    $newValue = str_replace("<div><br></div>", "<br>", $value);
    $newValue = str_replace("<div>", "<br>", str_replace("</div>", "", $newValue));
    return $newValue;
  }

  protected function getType($parent) {
    return $parent->type === 'forum' ? 'reply' : 'comment';
  }

  private function getFromWrapper($wrapper, $property) {
    $info = array(
      'property' => $property,
      'wrapper_method' => 'value'
    );
    return $this->getValueFromProperty($wrapper, $wrapper->{$property}, $info, NULL);
  }

  protected function isNew($wrapper) {
    $node = $this->getFromWrapper($wrapper, 'node');
    $changed = $this->changed($wrapper);
    return node_mark($node->nid, $changed) !== 0;
  }

  protected function hasChildren($wrapper) {
    $cid = $this->getFromWrapper($wrapper, 'cid');
    $result = db_select('comment', 'c')
      ->fields('c', array('cid'))
      ->condition('pid', intval($cid))
      ->execute()
      ->fetchAll();

    return count($result) > 0;
  }

  protected function changed($wrapper) {
    $cid = $this->getFromWrapper($wrapper, 'cid');
    return intval(db_select('comment')
      ->fields('comment', array('changed'))
      ->condition('cid', intval($cid))
      ->execute()
      ->fetchObject()
      ->changed);
  }

  protected function getEntityFieldQuery() {
    $query = parent::getEntityFieldQuery()
      ->propertyCondition('status', COMMENT_PUBLISHED);
    return $query;
  }

  protected function queryForListPagination(\EntityFieldQuery $query) {
    // Get the sorting options from the request object.
    $sorts = $this->parseRequestForListSort();

    if(!empty($sorts)) {
      list($offset, $range) = $this->parseRequestForListPagination();
      $query->range($offset, $range);
    }
  }

   /**
    * Get a list of entities.
    *
    * @return array
    *   Array of entities, as passed to RestfulEntityBase::viewEntity().
    *
    * @throws RestfulBadRequestException
      *
      * @SWG\Path(
      *   path="/comments",
      *   @SWG\Get(
      *     tags={"comments"},
      *     summary="Retrieves list of comments",
      *     @SWG\Response(
      *       response=200,
      *       description="List of Comments",
      *       @SWG\Schema(
      *         type="object",
      *         @SWG\Property(
      *         	 property="data",
      *         	 type="array",
      *           @SWG\Items(ref="#/definitions/comments")
      *         )
      *       )
      *     )
      *   ),
      *   @SWG\Post(
      *     tags={"comments"},
      *     summary="Creates new comment",
      *     @SWG\Parameter(
      *       name="comment",
      *       description="Comment to add",
      *       in="body",
      *       required=true,
      *       type="object",
      *       @SWG\Schema(
      *         type="object",
      *         ref="#/definitions/comments"
      *       )
      *     ),
      *     @SWG\Response(
      *       response="200",
      *       description="New comment created successfully"
      *     )
      *   )
      * )
    *
    */
  public function getList() {
    $request = $this->getRequest();
    $autocomplete_options = $this->getPluginKey('autocomplete');
    if (!empty($autocomplete_options['enable']) && isset($request['autocomplete']['string'])) {
      // Return autocomplete list.
      return $this->getListForAutocomplete();
    }

    $entity_type = $this->entityType;
    $result = $this->getQueryForList()
      ->execute();

    if (empty($result[$entity_type])) {
      return array();
    }

    $ids = array_keys($result[$entity_type]);

    // Pre-load all entities if there is no render cache.
    $cache_info = $this->getPluginKey('render_cache');
    if (!$cache_info['render']) {
      entity_load($entity_type, $ids);
    }

    // Get the sorting options from the request object.
    $sorts = $this->parseRequestForListSort();

    if(empty($sorts)) {
      list($offset, $range) = $this->parseRequestForListPagination();

      $query = db_select('comment', 'c');
      $query->fields('c', array('cid'));
      $query->condition('cid', $ids, 'IN');
      $query->addExpression('SUBSTRING(c.thread, 1, (LENGTH(c.thread) - 1))', 'torder');
      $query->orderBy('torder', 'ASC');
      $query->range($offset, $range);

      $results = $query->execute()
        ->fetchAll();

      $ids = [];

      foreach ($results as $result) {
        $ids[] = intVal($result->cid);
      }

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

  /**
   * {@inheritdoc}
   */
  public function createEntity() {
    $entity_info = $this->getEntityInfo();
    $bundle_key = $entity_info['entity keys']['bundle'];
    $values = $bundle_key ? array($bundle_key => $this->bundle) : array();
   
    /*
    * Clear an entry from the rendered cache.
    * {@inheritdoc}
    */
    
    $nid = $this->request['nid'];
    $context = $this->getEntityCacheTags($nid);
    $this->clearRenderedCache($context);
    
    if(isset($this->request['pid'])) {
      $values['pid'] = intVal($this->request['pid']);
      unset($this->request['pid']);
    }

    $entity = entity_create($this->entityType, $values);

    if ($this->checkEntityAccess('create', $this->entityType, $entity) === FALSE) {
      // User does not have access to create entity.
      $params = array('@resource' => $this->getPluginKey('label'));
      throw new RestfulForbiddenException(format_string('You do not have access to create a new @resource resource.', $params));
    }

    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    $this->setPropertyValues($wrapper);   
    return array($this->viewEntity($wrapper->getIdentifier()));
  }

  public function entityPreSave($wrapper) {
    parent::entityPreSave($wrapper);
    $wrapper->status->set(1);
  }
}
