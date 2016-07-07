<?php
/**
 * @file
 * solution_matrix_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solution_matrix_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
