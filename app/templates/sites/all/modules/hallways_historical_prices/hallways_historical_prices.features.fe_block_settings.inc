<?php
/**
 * @file
 * hallways_historical_prices.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hallways_historical_prices_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-99616cda690f345f972593dffa5e2126'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '99616cda690f345f972593dffa5e2126',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
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
