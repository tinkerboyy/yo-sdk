<?php
/**
 * @file
 * hallways_article_file_upload.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hallways_article_file_upload_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_article_files_upload'
  $field_bases['field_article_files_upload'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_article_files_upload',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
