<?php
/**
 * @file
 * sow_content_package_2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sow_content_package_2_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
