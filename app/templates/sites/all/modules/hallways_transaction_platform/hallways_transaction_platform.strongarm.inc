<?php
/**
 * @file
 * hallways_transaction_platform.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hallways_transaction_platform_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_hallways_transactional_platforms';
  $strongarm->value = '0';
  $export['comment_anonymous_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_hallways_transactional_platforms';
  $strongarm->value = 1;
  $export['comment_default_mode_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_hallways_transactional_platforms';
  $strongarm->value = '50';
  $export['comment_default_per_page_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_hallways_transactional_platforms';
  $strongarm->value = 1;
  $export['comment_form_location_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_hallways_transactional_platforms';
  $strongarm->value = '1';
  $export['comment_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_hallways_transactional_platforms';
  $strongarm->value = '1';
  $export['comment_preview_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_hallways_transactional_platforms';
  $strongarm->value = 1;
  $export['comment_subject_field_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hallways_transactional_platforms';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'workbench_access' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hallways_transactional_platforms';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hallways_transactional_platforms';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hallways_transactional_platforms';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hallways_transactional_platforms';
  $strongarm->value = '1';
  $export['node_preview_hallways_transactional_platforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hallways_transactional_platforms';
  $strongarm->value = 1;
  $export['node_submitted_hallways_transactional_platforms'] = $strongarm;

  return $export;
}
