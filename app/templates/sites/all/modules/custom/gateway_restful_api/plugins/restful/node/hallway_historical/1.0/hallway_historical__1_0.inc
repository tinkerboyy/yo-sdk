<?php

$plugin = array(
  'label' => t('Hallway Historical'),
  'resource' => 'hallway-historical',
  'name' => 'hallway_historical__1_0',
  'entity_type' => 'node',
  'bundle' => 'hallways_historical_prices',
  'description' => t('Export the Hallway Historical Prices content type with "cookie" authentication.'),
  'class' => 'RestfulHallwayHistoricalResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
