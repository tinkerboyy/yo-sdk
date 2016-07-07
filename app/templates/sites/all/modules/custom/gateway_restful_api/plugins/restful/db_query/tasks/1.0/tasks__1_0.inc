<?php

$plugin = array(
  'label' => t('Tasks'),
  'resource' => 'tasks',
  'name' => 'tasks__1_0',
  'data_provider_options' => array(
    'table_name' => 'gateway_task',
    'id_column' => 'id',
  ),
  'description' => t('Expose tasks data to the REST API.'),
  'class' => 'RestfulTasksResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
