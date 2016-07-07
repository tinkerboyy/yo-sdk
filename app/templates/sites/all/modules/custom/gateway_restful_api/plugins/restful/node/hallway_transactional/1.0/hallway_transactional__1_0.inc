<?php

$plugin = array(
  'label' => t('Hallway Transactional'),
  'resource' => 'hallway-transactional',
  'name' => 'hallway_transactional__1_0',
  'entity_type' => 'node',
  'bundle' => 'hallways_transactional_platforms',
  'description' => t('Export the Hallway Transactional Prices content type with "cookie" authentication.'),
  'class' => 'RestfulHallwayTransactionalResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
