<?php
/**
 * @file
 * cms_video_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cms_video_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cms_video_content_type_node_info() {
  $items = array(
    'video_article' => array(
      'name' => t('Video Article'),
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
