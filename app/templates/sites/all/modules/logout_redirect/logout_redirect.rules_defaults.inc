<?php
/**
 * @file
 * logout_redirect.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function logout_redirect_default_rules_configuration() {
  $items = array();
  $items['rules_logout'] = entity_import('rules_config', '{ "rules_logout" : {
      "LABEL" : "Logout",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_logout" : [] },
      "DO" : [ { "redirect" : { "url" : "homepage\\/welcome.php" } } ]
    }
  }');
  return $items;
}
