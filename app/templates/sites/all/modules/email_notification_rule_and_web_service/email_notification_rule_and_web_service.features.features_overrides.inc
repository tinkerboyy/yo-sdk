<?php
/**
 * @file
 * email_notification_rule_and_web_service.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function email_notification_rule_and_web_service_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: ds_layout_settings
  $overrides["ds_layout_settings.comment|comment_node_forum|default.settings|fields|field_hw"] = 'ds_content';
  $overrides["ds_layout_settings.comment|comment_node_forum|form.settings|fields|field_hw"] = 'hidden';

 return $overrides;
}
