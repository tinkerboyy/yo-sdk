<?php
/**
 * @file
 * cas_agency_field_for_user_entity.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cas_agency_field_for_user_entity_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_user_cas_agency'
  $field_bases['field_user_cas_agency'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_user_cas_agency',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
