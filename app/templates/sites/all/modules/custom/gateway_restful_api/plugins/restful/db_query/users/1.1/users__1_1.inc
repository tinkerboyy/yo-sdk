<?php

$plugin = array(
  'label' => t('Users'),
  'resource' => 'users',
  'name' => 'users__1_1',
  'data_provider_options' => array(
    'table_name' => 'users',
    'id_column' => 'uid',
  ),
  'description' => t('Expose public information concerning users.'),
  'class' => 'RestfulUsersResource',
  'minor_version' => 1,
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
