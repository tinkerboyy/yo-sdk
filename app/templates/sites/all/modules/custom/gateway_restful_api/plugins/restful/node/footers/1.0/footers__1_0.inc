<?php

$plugin = array(
  'label' => t('Footers'),
  'resource' => 'footers',
  'name' => 'footers__1_0',
  'entity_type' => 'node',
  'bundle' => 'footer_content',
  'description' => t('Export the footers content type with "cookie" authentication.'),
  'class' => 'RestfulFootersResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
