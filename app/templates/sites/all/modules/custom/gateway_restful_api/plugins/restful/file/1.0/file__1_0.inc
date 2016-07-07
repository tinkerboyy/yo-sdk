<?php

$plugin = array(
  'label' => t('Files'),
  'resource' => 'file',
  'name' => 'file__1_0',
  'entity_type' => 'file',
  'bundle' => 'file',
  'description' => t('Process User Uploaded files'),
  'class' => 'RestfulFileResource',
  'authentication_types' => TRUE,
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
