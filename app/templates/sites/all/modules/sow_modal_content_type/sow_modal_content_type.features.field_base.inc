<?php
/**
 * @file
 * sow_modal_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sow_modal_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_public_private'
  $field_bases['field_public_private'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_public_private',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => 'Public',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
