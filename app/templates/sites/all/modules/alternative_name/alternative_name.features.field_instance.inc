<?php
/**
 * @file
 * alternative_name.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function alternative_name_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_user_alternative_name'
  $field_instances['user-user-field_user_alternative_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you want to use an My Connect Username please update here',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_user_alternative_name',
    'label' => 'My Connect Username',
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
      'weight' => 12,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('If you want to use an My Connect Username please update here');
  t('My Connect Username');

  return $field_instances;
}
