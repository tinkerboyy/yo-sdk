<?php
/**
 * @file
 * environment_indicator_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function environment_indicator_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'environment_indicator_git_support';
  $strongarm->value = 0;
  $export['environment_indicator_git_support'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'environment_indicator_integration';
  $strongarm->value = array(
    'toolbar' => 0,
    'admin_menu' => 0,
    'navbar' => 0,
  );
  $export['environment_indicator_integration'] = $strongarm;

  return $export;
}
