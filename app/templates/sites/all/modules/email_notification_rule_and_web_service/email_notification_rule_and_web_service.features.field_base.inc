<?php
/**
 * @file
 * email_notification_rule_and_web_service.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function email_notification_rule_and_web_service_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_hw'
  $field_bases['field_hw'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hw',
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
