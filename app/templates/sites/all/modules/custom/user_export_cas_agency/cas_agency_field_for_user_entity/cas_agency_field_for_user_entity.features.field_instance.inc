<?php
/**
 * @file
 * cas_agency_field_for_user_entity.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cas_agency_field_for_user_entity_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_user_cas_agency'
  $field_instances['user-user-field_user_cas_agency'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_user_cas_agency',
    'label' => 'CAS Agency',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 51,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CAS Agency');

  return $field_instances;
}
