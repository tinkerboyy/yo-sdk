<?php

$plugin = array(
  'label' => t('Help'),
  'resource' => 'help',
  'name' => 'help__1_0',
  'entity_type' => 'node',
  'bundle' => 'help',
  'description' => t('Export the help content type with "cookie" authentication.'),
  'class' => 'RestfulHelpResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
