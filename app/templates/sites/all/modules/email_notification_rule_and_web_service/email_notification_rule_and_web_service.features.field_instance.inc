<?php
/**
 * @file
 * email_notification_rule_and_web_service.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function email_notification_rule_and_web_service_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_forum-field_hw'
  $field_instances['comment-comment_node_forum-field_hw'] = array(
    'bundle' => 'comment_node_forum',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'comment',
    'field_name' => 'field_hw',
    'label' => 'HW',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('HW');

  return $field_instances;
}
