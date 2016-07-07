<?php

/**
 * @file
 * Contains RestfulGatewayEventsResource.
 */

class RestfulGatewayEventsResource extends AGRestfulEntityBase {
  /**
   * Overrides RestfulGatewayEventsResource::publicFieldsInfo().
   */
 
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
   
    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );
    $public_fields['event'] = array(
      'property' => 'field_date'
    );

    $public_fields['event_timezone'] = array(
      'property' => 'field_event_time_zone'
    );
    
    $public_fields['changed'] = array(
      'property' => 'changed'
    );
    
    $public_fields['location'] = array(
      'property' => 'field_event_location'
    );

    return $public_fields;
  }


}

