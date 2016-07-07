<?php

$plugin = array(
  'label' => t('File upload'),
  'resource' => 'files',
  'name' => 'files__1_0',
  'entity_type' => 'file',
  'description' => t('A file upload wrapped with RESTful.'),
  'class' => 'RestfulFilesResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
