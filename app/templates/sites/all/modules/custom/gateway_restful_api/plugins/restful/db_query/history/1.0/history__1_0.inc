<?php

$plugin = array(
  'label' => t('History'),
  'resource' => 'history',
  'name' => 'history__1_0',
  'data_provider_options' => array(
    'table_name' => 'history',
    'id_column' => array('uid','nid')
  ),
  'description' => t('Expose public information concerning history.'),
  'class' => 'RestfulHistoryResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
