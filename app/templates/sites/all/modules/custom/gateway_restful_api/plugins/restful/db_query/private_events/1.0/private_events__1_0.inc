<?php

$plugin = array(
  'label' => t('Private Events'),
  'resource' => 'private-events',
  'name' => 'private_events__1_0',
  'data_provider_options' => array(
    'table_name' => 'gateway_event',
    'id_column' => 'id',
  ),
  'description' => t('Expose private event data to the REST API.'),
  'class' => 'RestfulPrivateEventsResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
