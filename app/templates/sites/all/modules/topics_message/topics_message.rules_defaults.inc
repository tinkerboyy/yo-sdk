<?php
/**
 * @file
 * topics_message.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function topics_message_default_rules_configuration() {
  $items = array();
  $items['rules_community_topic_message'] = entity_import('rules_config', '{ "rules_community_topic_message" : {
      "LABEL" : "Community Topic Message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--forum" : { "bundle" : "forum" } },
      "DO" : [
        { "drupal_message" : { "message" : "Thank You! Your Topic has been sent to Moderator for Approval." } },
        { "redirect" : { "url" : "communities" } }
      ]
    }
  }');
  return $items;
}
