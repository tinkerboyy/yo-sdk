<?php
/**
 * @file
 * homepage_gateways_views_and_nodequeues.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function homepage_gateways_views_and_nodequeues_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function homepage_gateways_views_and_nodequeues_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
