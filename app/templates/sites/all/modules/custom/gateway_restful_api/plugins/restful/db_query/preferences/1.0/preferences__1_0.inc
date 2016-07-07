<?php

$plugin = array(
  'label' => t('User Preferences'),
  'resource' => 'preferences',
  'name' => 'preferences__1_0',
  'data_provider_options' => array(
    'table_name' => 'user_preferences',
    'id_column' => 'uid',
  ),
  'description' => t('Expose user preferences to the REST API.'),
  'class' => 'RestfulUserPreferencesResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
