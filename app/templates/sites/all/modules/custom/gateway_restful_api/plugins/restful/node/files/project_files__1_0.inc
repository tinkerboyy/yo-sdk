<?php

$plugin = array(
  'label' => t('Project file upload'),
  'resource' => 'project-file-upload',
  'name' => 'project_files__1_0',
  'entity_type' => 'file',
  'description' => t('A file upload wrapped with RESTful with project file validation.'),
  'class' => 'RestfulFilesResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'options' => array(
    'validators' => array(
      'file_validate_extensions' => array( 'doc docx xls xlsx pdf' ),
      'file_validate_size' => array( 2000000 )
    ),
    'scheme' => 'private'
  ),
  'allow_origin' => $GLOBALS['base_url']
);
