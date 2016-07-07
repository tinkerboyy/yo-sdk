<?php
/**
 * @file
 * hallways_article_file_upload.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hallways_article_file_upload_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hallways_article_file_upload_node_info() {
  $items = array(
    'article_file_upload' => array(
      'name' => t('Article File Upload'),
      'base' => 'node_content',
      'description' => t('This Content Type is used to upload Documents related to Article'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
