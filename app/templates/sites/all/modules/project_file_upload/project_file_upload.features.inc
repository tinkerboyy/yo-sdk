<?php
/**
 * @file
 * project_file_upload.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function project_file_upload_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function project_file_upload_node_info() {
  $items = array(
    'project_file_upload' => array(
      'name' => t('Project File Upload'),
      'base' => 'node_content',
      'description' => t('Wrapper content type for file upload field. '),
      'has_title' => '1',
      'title_label' => t('Name '),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
