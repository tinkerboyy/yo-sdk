<?php

$plugin = array(
  'label' => t('Project File upload'),
  'resource' => 'project-files',
  'name' => 'project_file_upload__1_0',
  'entity_type' => 'node',
  'bundle' => 'project_file_upload',
  'description' => t('A project file upload wrapped with RESTful.'),
  'class' => 'RestfulProjectFilesResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
