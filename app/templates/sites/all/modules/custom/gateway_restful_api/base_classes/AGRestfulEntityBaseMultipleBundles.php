<?php

require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

class AGRestfulEntityBaseMultipleBundles extends RestfulEntityBaseMultipleBundles {
  use AGPublicUserAccessCheck;

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

    return parent::checkEntityAccess($op, $entity_type, $entity);
  }
  
}
