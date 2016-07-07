<?php
/**
 * @file
 * cms_footer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cms_footer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cms_footer_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function cms_footer_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: footer_block
  $nodequeues['footer_block'] = array(
    'name' => 'footer_block',
    'title' => 'Footer Block',
    'subqueue_title' => '',
    'size' => 4,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'footer_content',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: footer_block_content
  $nodequeues['footer_block_content'] = array(
    'name' => 'footer_block_content',
    'title' => 'Footer Block Content',
    'subqueue_title' => '',
    'size' => 5,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'footer_content',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function cms_footer_node_info() {
  $items = array(
    'footer_content' => array(
      'name' => t('Footer Content'),
      'base' => 'node_content',
      'description' => t('Create a Content for Footer'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
