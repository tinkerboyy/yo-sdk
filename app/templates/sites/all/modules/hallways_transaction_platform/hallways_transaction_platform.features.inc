<?php
/**
 * @file
 * hallways_transaction_platform.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hallways_transaction_platform_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hallways_transaction_platform_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hallways_transaction_platform_node_info() {
  $items = array(
    'hallways_transactional_platforms' => array(
      'name' => t('Hallways Transactional Platforms'),
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
