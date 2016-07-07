<?php

class RestfulNewsResource extends AGRestfulEntityBase {

  public function publicFieldsInfo(){
    
    $public_fields = parent::publicFieldsInfo();
    $intFormatter = array( $this, 'intval' );

    $public_fields['expiration'] = array(
      'property' => 'field_expiration_date',
      'process_callbacks' => array($intFormatter)
    );

    $public_fields['shortdescription'] = array(
      'property' => 'field_short_description_1',
    );

    $public_fields['created'] = array(
      'property' => 'created',
      'process_callbacks' => array($intFormatter)
    );

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value'
    );

    return $public_fields;
  }
}