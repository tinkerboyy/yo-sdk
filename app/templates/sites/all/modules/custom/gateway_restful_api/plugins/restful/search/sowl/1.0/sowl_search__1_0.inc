<?php

$plugin = array(
  'resource' => 'sowl',
  'name' => 'sowl_search__1_0',
  'label' => t('SOWL Search'),
  'description' => t('Provides sowl info doing Search API searches.'),
  'data_provider_options' => array(
    'search_index' => 'default_node_index',
  ),
  'class' => 'RestfulSearchAPISowlSearch',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  // Use pass_through to expose the complete search result objects. This is
  // useful while developing to allow you to know how to do the field mappings.
  // 'pass_through' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
