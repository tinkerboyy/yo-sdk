<?php
/**
 * @file
 * hallways_modal_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hallways_modal_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
