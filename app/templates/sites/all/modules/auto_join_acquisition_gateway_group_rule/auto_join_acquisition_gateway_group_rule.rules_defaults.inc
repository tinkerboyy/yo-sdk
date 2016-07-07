<?php
/**
 * @file
 * auto_join_acquisition_gateway_group_rule.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function auto_join_acquisition_gateway_group_rule_default_rules_configuration() {
  $items = array();
  $items['rules_auto_join_acquisition_gateway_group'] = entity_import('rules_config', '{ "rules_auto_join_acquisition_gateway_group" : {
      "LABEL" : "Auto Join Acquisition Gateway Group",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "title",
              "value" : "Acquisition Gateway Group",
              "limit" : [ "" ]
            },
            "PROVIDE" : { "entity_fetched" : { "acquisition_gateway_groups" : "Acquisition Gateway Groups" } }
          }
        },
        { "og_subcribe_user" : { "user" : [ "account" ], "group" : [ "acquisition-gateway-groups:0" ] } }
      ]
    }
  }');
  return $items;
}
