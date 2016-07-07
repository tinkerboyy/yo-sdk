<?php
/**
 * @file
 * hallways_transaction_platform.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hallways_transaction_platform_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-710f91bdf972a08822e4f77e72b6b624'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '710f91bdf972a08822e4f77e72b6b624',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'AdministrativeSupport',
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
    'visibility' => 1,
  );

  $export['views-d6d07bc5edd47cfd959fbb23b73ed195'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'd6d07bc5edd47cfd959fbb23b73ed195',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'ITSoftware',
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
    'visibility' => 1,
  );

  $export['views-f586abec6e985374e8df826768ff5086'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'f586abec6e985374e8df826768ff5086',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'ITHardware',
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
    'visibility' => 1,
  );

  return $export;
}
