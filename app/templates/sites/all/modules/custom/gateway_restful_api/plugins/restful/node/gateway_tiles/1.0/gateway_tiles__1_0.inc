<?php

$plugin = array(
  'label' => t('Gateway Tiles'),
  'resource' => 'gateway-tiles',
  'name' => 'gateway_tiles__1_0',
  'entity_type' => 'node',
  'bundle' => 'homepage_gateways',
  'description' => t('Export the Homepage Gateways content type with "cookie" authentication.'),
  'class' => 'RestfulGatewayTilesResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
