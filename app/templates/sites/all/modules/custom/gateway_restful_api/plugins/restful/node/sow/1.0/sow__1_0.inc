<?php

$plugin = array(
  'label' => t('Statement of Work'),
  'resource' => 'sow',
  'name' => 'sow__1_0',
  'entity_type' => 'node',
  'bundle' => 'sow',
  'description' => t('Export the Statement of Work content type with "cookie" authentication.'),
  'class' => 'RestfulSowResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'render_cache' => array(
    // Enables the render cache.
    'render' => variable_get('gateway_restful_api_render_cache_enable', TRUE),
    // Defaults to 'cache_restful' (optional).
    'bin' => 'cache_gateway_restful_api_render',
    // Expiration time in seconds
    'expire' => 300, //5 minutes
    // Enable cache invalidation for entity based resources. Defaults to TRUE (optional).
    'simple_invalidate' => TRUE,
    // Use a different cache backend for this resource. Defaults to variable_get('cache_default_class', 'DrupalDatabaseCache') (optional).
    'class' => variable_get('gateway_restful_api_render_cache_backend', 'AGDatabaseCache'),
    // Account cache granularity. Instead of caching per user you can choose to cache per role. Default: DRUPAL_CACHE_PER_USER.
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
