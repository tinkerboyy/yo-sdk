<?php
/**
 * @file
 * lca_bar.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function lca_bar_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-lca_bar'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'lca_bar',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'login-information
caphallwaysrules
AdministrativeSupport
ITHardware
ITSoftware
<front>
content/contact-us',
    'roles' => array(
      'authenticated user' => 2,
    ),
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
        'weight' => -39,
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

  $export['boxes-lcabar_hallways'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'lcabar_hallways',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'AdministrativeSupport
ITHardware
ITSoftware
<front>',
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
    'visibility' => 1,
  );

  return $export;
}
