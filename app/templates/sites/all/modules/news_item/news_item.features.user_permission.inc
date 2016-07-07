<?php
/**
 * @file
 * news_item.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function news_item_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create news_item content'.
  $permissions['create news_item content'] = array(
    'name' => 'create news_item content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_item content'.
  $permissions['delete any news_item content'] = array(
    'name' => 'delete any news_item content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_item content'.
  $permissions['delete own news_item content'] = array(
    'name' => 'delete own news_item content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news_item content'.
  $permissions['edit any news_item content'] = array(
    'name' => 'edit any news_item content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news_item content'.
  $permissions['edit own news_item content'] = array(
    'name' => 'edit own news_item content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
