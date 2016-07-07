<?php

$plugin = array(
  'label' => t('Projects'),
  'resource' => 'projects',
  'name' => 'projects__1_0',
  'data_provider_options' => array(
    'table_name' => 'gateway_project',
    'id_column' => 'id',
  ),
  'description' => t('Expose Projects data to the REST API.'),
  'class' => 'RestfulProjectsResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
