<?php
/**
 * @file
 * homepage_random_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function homepage_random_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 * Renaming Content Type.
 */
function homepage_random_content_type_node_info() {
  $items = array(
    'homepage_random_content' => array(
      'name' => t('Hallways Sorting'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
