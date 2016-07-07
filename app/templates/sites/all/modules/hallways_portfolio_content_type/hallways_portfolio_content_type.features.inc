<?php
/**
 * @file
 * hallways_portfolio_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hallways_portfolio_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hallways_portfolio_content_type_node_info() {
  $items = array(
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('Use this content type to create content for your Portfolio blocks. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
