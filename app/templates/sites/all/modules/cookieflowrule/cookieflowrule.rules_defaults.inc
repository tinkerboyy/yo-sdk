<?php
/**
 * @file
 * cookieflowrule.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function cookieflowrule_default_rules_configuration() {
  $items = array();
  $items['rules_cookieset'] = entity_import('rules_config', '{ "rules_cookieset" : {
      "LABEL" : "cookieSet",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules" ],
      "ON" : {
        "node_view--page" : { "bundle" : "page" },
        "node_view--portfolio" : { "bundle" : "portfolio" }
      },
      "DO" : [
        { "php_eval" : { "code" : "setcookie(\\u0022visited\\u0022,\\u00221\\u0022,time()+86400 * 3650,\\u0022\\/\\u0022, null, true, true);" } }
      ]
    }
  }');
  return $items;
}
