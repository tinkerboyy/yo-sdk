<?php
/**
 * @file
 * cms_hallway_resources_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cms_hallway_resources_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cms_hallway_resources_ct_node_info() {
  $items = array(
    'hallways_resources' => array(
      'name' => t('Hallway Resources'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Hallways Resources'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
