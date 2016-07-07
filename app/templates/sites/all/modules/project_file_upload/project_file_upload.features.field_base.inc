<?php
/**
 * @file
 * project_file_upload.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function project_file_upload_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_project_file'
  $field_bases['field_project_file'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_file',
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
