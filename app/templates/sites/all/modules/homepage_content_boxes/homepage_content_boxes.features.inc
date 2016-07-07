<?php
/**
 * @file
 * homepage_content_boxes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function homepage_content_boxes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
