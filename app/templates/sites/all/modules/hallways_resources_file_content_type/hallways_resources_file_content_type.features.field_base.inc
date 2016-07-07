<?php
/**
 * @file
 * hallways_resources_file_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hallways_resources_file_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_resource_file_upload'
  $field_bases['field_resource_file_upload'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_resource_file_upload',
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
