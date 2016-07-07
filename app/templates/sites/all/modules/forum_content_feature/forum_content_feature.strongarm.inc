<?php
/**
 * @file
 * forum_content_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function forum_content_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_forum';
  $strongarm->value = array();
  $export['node_options_forum'] = $strongarm;

  return $export;
}
