<?php
/**
 * @file
 * hallways_logo_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hallways_logo_block_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
