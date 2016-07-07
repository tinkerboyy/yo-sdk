<?php
/**
 * @file
 * cms_downloadable_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cms_downloadable_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cms_downloadable_article_node_info() {
  $items = array(
    'downloadable_article' => array(
      'name' => t('Downloadable Article'),
      'base' => 'node_content',
      'description' => t('Articles to be downloaded for use.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Don\'t do anything bad.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
