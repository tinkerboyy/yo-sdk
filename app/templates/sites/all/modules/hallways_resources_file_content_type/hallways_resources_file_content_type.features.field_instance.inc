<?php
/**
 * @file
 * hallways_resources_file_content_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hallways_resources_file_content_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-resources_file-field_public_private'
  $field_instances['node-resources_file-field_public_private'] = array(
    'bundle' => 'resources_file',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'If this Box Un-checked it is Private Content. 
If this Box Checked then its a Public Content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_public_private',
    'label' => 'Public / Private',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-resources_file-field_resource_file_upload'
  $field_instances['node-resources_file-field_resource_file_upload'] = array(
    'bundle' => 'resources_file',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_resource_file_upload',
    'label' => 'Resource File Upload',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt xlsx pdf doc docx csv xls xlsb',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('If this Box Un-checked it is Private Content. 
If this Box Checked then its a Public Content.');
  t('Public / Private');
  t('Resource File Upload');

  return $field_instances;
}
