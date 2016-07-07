<?php
require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

class AGRestfulEntityBaseUser extends RestfulEntityBaseUser {
  use AGPublicUserAccessCheck;

  public function getPublicFields() {
    $publicFields = parent::getPublicFields();
    unset($publicFields['mail']);
    return $publicFields;
  }

  /**
   * Override RestfulEntityBase to add patch to clear the entity from render cache
   */
  protected function updateEntity($id, $null_missing_fields = FALSE, $ignore = array()) {
    $entity_id = $this->getEntityIdByFieldId($id);
    $this->isValidEntity('update', $entity_id);

    $wrapper = entity_metadata_wrapper($this->entityType, $entity_id);

    $this->setPropertyValues($wrapper, $null_missing_fields, $ignore);

    // Set the HTTP headers.
    $this->setHttpHeaders('Status', 201);

    //if (!empty($wrapper->url) && $url = $wrapper->url->value()) {
    //  $this->setHttpHeaders('Location', $url);
    //}

    //US6140: Patch to clear cache entry for this entity
    //Clear the cache for this user/role so update request will return updated
    //entity not the cached one
    $cacheContext = $this->getEntityCacheTags($entity_id);
    $cid = $this->generateCacheId($cacheContext);
    $this->cacheInvalidate($cid);
    //End patch

    return array($this->viewEntity($wrapper->getIdentifier()));
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
   * @param array $ignoreFields Fields to ignore in the payload
   *
   * @throws RestfulBadRequestException
   */
  protected function setPropertyValues(EntityMetadataWrapper $wrapper, $null_missing_fields = FALSE, $ignore = array()) {
    $request = $this->getRequest();

    static::cleanRequest($request);
    $save = FALSE;

    foreach ($this->getPublicFields() as $public_field_name => $info) {
      if (!empty($info['create_or_update_passthrough']) || empty($info['property']) || in_array($public_field_name, $ignore)) {
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

}
