<?php
/**
 * @file
 * ag_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_help_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ag_help_node_info() {
  $items = array(
    'help' => array(
      'name' => t('Help'),
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
