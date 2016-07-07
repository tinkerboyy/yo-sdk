<?php
/**
 * @file
 * lca_bar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lca_bar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
