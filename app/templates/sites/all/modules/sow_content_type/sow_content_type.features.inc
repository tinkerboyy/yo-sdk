<?php
/**
 * @file
 * sow_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sow_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sow_content_type_node_info() {
  $items = array(
    'sow' => array(
      'name' => t('Statement of Work'),
      'base' => 'node_content',
      'description' => t('Upload a Statement of Work in PDF and Microsoft Word format.'),
      'has_title' => '1',
      'title_label' => t('SOW Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
