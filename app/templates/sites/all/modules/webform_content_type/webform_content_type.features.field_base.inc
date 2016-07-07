<?php
/**
 * @file
 * webform_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function webform_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_no_of_days_tag'
  $field_bases['field_no_of_days_tag'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_no_of_days_tag',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_no_of_days_to_expire_date'
  $field_bases['field_no_of_days_to_expire_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_no_of_days_to_expire_date',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
