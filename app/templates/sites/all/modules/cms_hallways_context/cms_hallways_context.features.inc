<?php
/**
 * @file
 * cms_hallways_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cms_hallways_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}