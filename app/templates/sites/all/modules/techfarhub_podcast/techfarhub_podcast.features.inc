<?php
/**
 * @file
 * techfarhub_podcast.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function techfarhub_podcast_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function techfarhub_podcast_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function techfarhub_podcast_node_info() {
  $items = array(
    'podcast_article' => array(
      'name' => t('Podcast Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
