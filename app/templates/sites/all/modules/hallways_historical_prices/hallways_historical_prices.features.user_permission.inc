<?php
/**
 * @file
 * hallways_historical_prices.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hallways_historical_prices_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create hallways_historical_prices content'.
  $permissions['create hallways_historical_prices content'] = array(
    'name' => 'create hallways_historical_prices content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hallways_historical_prices content'.
  $permissions['delete any hallways_historical_prices content'] = array(
    'name' => 'delete any hallways_historical_prices content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own hallways_historical_prices content'.
  $permissions['delete own hallways_historical_prices content'] = array(
    'name' => 'delete own hallways_historical_prices content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any hallways_historical_prices content'.
  $permissions['edit any hallways_historical_prices content'] = array(
    'name' => 'edit any hallways_historical_prices content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hallways_historical_prices content'.
  $permissions['edit own hallways_historical_prices content'] = array(
    'name' => 'edit own hallways_historical_prices content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  return $permissions;
}
