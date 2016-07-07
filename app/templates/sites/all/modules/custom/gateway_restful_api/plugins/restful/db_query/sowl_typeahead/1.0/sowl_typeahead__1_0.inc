<?php

$plugin = array(
  'label' => t('SOWL Typeahead'),
  'resource' => 'sowl-typeahead',
  'name' => 'sowl_typeahead__1_0',
  'data_provider_options' => array(
    'table_name' => 'search_logging',
    'id_column' => 'slid',
  ),
  'description' => t('Expose SOW library search queries to the REST API.'),
  'class' => 'RestfulSowlTypeaheadResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
