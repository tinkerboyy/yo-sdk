<?php
/**
 * @file
 * hallways_modal_content.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hallways_modal_content_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-administrative_resources'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'administrative_resources',
    'module' => 'boxes',
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
        'region' => '',
        'status' => 0,
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
    'visibility' => 1,
  );

  $export['boxes-education_resource_content'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'education_resource_content',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'TalentDevelopment',
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

  $export['boxes-professional_resource_content'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'professional_resource_content',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'ProfessionalServices',
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

  $export['boxes-resources_ithardware_content'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'resources_ithardware_content',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'ITHardware
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

  $export['boxes-resources_itsoftware_content'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'resources_itsoftware_content',
    'module' => 'boxes',
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
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -44,
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

  $export['boxes-small_package_modal'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'small_package_modal',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'SmallPackageDelivery',
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
