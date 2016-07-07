<?php
/**
 * @file
 * hallways_article_sorting_views.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hallways_article_sorting_views_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-246fb6d1ef57fba541875e03b253d0fb'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '246fb6d1ef57fba541875e03b253d0fb',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/sorting-it-software',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => -45,
      ),
      'other_sub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'other_sub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-7370b344d1494e2ee277189bb1de8246'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '7370b344d1494e2ee277189bb1de8246',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/sorting-it-hardware',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => -46,
      ),
      'other_sub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'other_sub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-d5661c6d85890a1dc9a769c7076129f3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'd5661c6d85890a1dc9a769c7076129f3',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/sorting-administrative-support',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => -47,
      ),
      'other_sub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'other_sub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
