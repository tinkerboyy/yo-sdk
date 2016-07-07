<?php
/**
 * @file
 * sow_modal_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sow_modal_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sow_modal_content_type_node_info() {
  $items = array(
    'sow_modals' => array(
      'name' => t('SOW Modals'),
      'base' => 'node_content',
      'description' => t('Add content for the welcome screen of the SOW Library modal.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
