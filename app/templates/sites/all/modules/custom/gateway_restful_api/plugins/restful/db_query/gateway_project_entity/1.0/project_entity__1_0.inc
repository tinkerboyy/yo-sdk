<?php

$plugin = array(
  'label' => t('Projects Entity'),
  'resource' => 'projects-entity',
  'name' => 'project_entity__1_0',
  'data_provider_options' => array(
    'table_name' => 'gateway_project_entity_reference',
    'id_column' => 'id',
  ),
  'description' => t('Expose Projects Entity data to the REST API.'),
  'class' => 'RestfulProjectEntity',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
