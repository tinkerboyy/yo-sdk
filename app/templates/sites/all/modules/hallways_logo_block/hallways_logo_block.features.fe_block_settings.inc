<?php
/**
 * @file
 * hallways_logo_block.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hallways_logo_block_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-header_logo'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'header_logo',
    'module' => 'boxes',
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
        'weight' => -29,
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
