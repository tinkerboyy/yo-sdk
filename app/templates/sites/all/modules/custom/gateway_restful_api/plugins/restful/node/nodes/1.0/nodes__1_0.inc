<?php

$plugin = array(
  'label' => t('Nodes'),
  'resource' => 'nodes',
  'name' => 'nodes__1_0',
  'entity_type' => 'node',
  'bundles' => array(
    'hallways_document' => 'hallway-documents',
    'video_article' => 'hallway-videoarticles',
    'article' => 'hallway-articles',
    'news_item' => 'news'
  ),
  'description' => t('Export the nodes content type with "cookie" authentication.'),
  'class' => 'RestfulNodesResource',
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
