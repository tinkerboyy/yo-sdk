<?php
/**
 * @file
 * hallways_historical_prices.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hallways_historical_prices_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hallways_historical_prices_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hallways_historical_prices_node_info() {
  $items = array(
    'hallways_historical_prices' => array(
      'name' => t('Hallways Historical Prices'),
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
