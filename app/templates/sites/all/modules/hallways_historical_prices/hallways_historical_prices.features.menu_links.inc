<?php
/**
 * @file
 * hallways_historical_prices.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hallways_historical_prices_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_hallways-historical-prices:node/add/hallways-historical-prices
  $menu_links['navigation_hallways-historical-prices:node/add/hallways-historical-prices'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/hallways-historical-prices',
    'router_path' => 'node/add/hallways-historical-prices',
    'link_title' => 'Hallways Historical Prices',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'navigation_hallways-historical-prices:node/add/hallways-historical-prices',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Hallways Historical Prices');


  return $menu_links;
}
