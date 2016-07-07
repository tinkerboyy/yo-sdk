<?php
/**
 * @file
 * hallways_roles_and_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hallways_roles_and_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Gateway Author.
  $roles['Gateway Author'] = array(
    'name' => 'Gateway Author',
    'weight' => 6,
  );

  // Exported role: Gateway Moderator.
  $roles['Gateway Moderator'] = array(
    'name' => 'Gateway Moderator',
    'weight' => 8,
  );

  // Exported role: Gateway Publisher.
  $roles['Gateway Publisher'] = array(
    'name' => 'Gateway Publisher',
    'weight' => 7,
  );

  // Exported role: HW Admin Support Author.
  $roles['HW Admin Support Author'] = array(
    'name' => 'HW Admin Support Author',
    'weight' => 64,
  );

  // Exported role: HW Admin Support Moderator.
  $roles['HW Admin Support Moderator'] = array(
    'name' => 'HW Admin Support Moderator',
    'weight' => 66,
  );

  // Exported role: HW Admin Support Publisher.
  $roles['HW Admin Support Publisher'] = array(
    'name' => 'HW Admin Support Publisher',
    'weight' => 65,
  );

  // Exported role: HW Card Services Author.
  $roles['HW Card Services Author'] = array(
    'name' => 'HW Card Services Author',
    'weight' => 58,
  );

  // Exported role: HW Card Services Moderator.
  $roles['HW Card Services Moderator'] = array(
    'name' => 'HW Card Services Moderator',
    'weight' => 60,
  );

  // Exported role: HW Card Services Publisher.
  $roles['HW Card Services Publisher'] = array(
    'name' => 'HW Card Services Publisher',
    'weight' => 59,
  );

  // Exported role: HW Cleaning Supplies Author.
  $roles['HW Cleaning Supplies Author'] = array(
    'name' => 'HW Cleaning Supplies Author',
    'weight' => 31,
  );

  // Exported role: HW Cleaning Supplies Moderator.
  $roles['HW Cleaning Supplies Moderator'] = array(
    'name' => 'HW Cleaning Supplies Moderator',
    'weight' => 33,
  );

  // Exported role: HW Cleaning Supplies Publisher.
  $roles['HW Cleaning Supplies Publisher'] = array(
    'name' => 'HW Cleaning Supplies Publisher',
    'weight' => 32,
  );

  // Exported role: HW Education and Training Author.
  $roles['HW Education and Training Author'] = array(
    'name' => 'HW Education and Training Author',
    'weight' => 16,
  );

  // Exported role: HW Education and Training Moderator.
  $roles['HW Education and Training Moderator'] = array(
    'name' => 'HW Education and Training Moderator',
    'weight' => 20,
  );

  // Exported role: HW Education and Training Publisher.
  $roles['HW Education and Training Publisher'] = array(
    'name' => 'HW Education and Training Publisher',
    'weight' => 18,
  );

  // Exported role: HW Employee Relocation Author.
  $roles['HW Employee Relocation Author'] = array(
    'name' => 'HW Employee Relocation Author',
    'weight' => 40,
  );

  // Exported role: HW Employee Relocation Moderator.
  $roles['HW Employee Relocation Moderator'] = array(
    'name' => 'HW Employee Relocation Moderator',
    'weight' => 42,
  );

  // Exported role: HW Employee Relocation Publisher.
  $roles['HW Employee Relocation Publisher'] = array(
    'name' => 'HW Employee Relocation Publisher',
    'weight' => 41,
  );

  // Exported role: HW Facilities Maintenance Services Author.
  $roles['HW Facilities Maintenance Services Author'] = array(
    'name' => 'HW Facilities Maintenance Services Author',
    'weight' => 61,
  );

  // Exported role: HW Facilities Maintenance Services Moderator.
  $roles['HW Facilities Maintenance Services Moderator'] = array(
    'name' => 'HW Facilities Maintenance Services Moderator',
    'weight' => 63,
  );

  // Exported role: HW Facilities Maintenance Services Publisher.
  $roles['HW Facilities Maintenance Services Publisher'] = array(
    'name' => 'HW Facilities Maintenance Services Publisher',
    'weight' => 62,
  );

  // Exported role: HW Freight Author.
  $roles['HW Freight Author'] = array(
    'name' => 'HW Freight Author',
    'weight' => 43,
  );

  // Exported role: HW Freight Moderator.
  $roles['HW Freight Moderator'] = array(
    'name' => 'HW Freight Moderator',
    'weight' => 45,
  );

  // Exported role: HW Freight Publisher.
  $roles['HW Freight Publisher'] = array(
    'name' => 'HW Freight Publisher',
    'weight' => 44,
  );

  // Exported role: HW IT Hardware Author.
  $roles['HW IT Hardware Author'] = array(
    'name' => 'HW IT Hardware Author',
    'weight' => 12,
  );

  // Exported role: HW IT Hardware Moderator.
  $roles['HW IT Hardware Moderator'] = array(
    'name' => 'HW IT Hardware Moderator',
    'weight' => 15,
  );

  // Exported role: HW IT Hardware Publisher.
  $roles['HW IT Hardware Publisher'] = array(
    'name' => 'HW IT Hardware Publisher',
    'weight' => 14,
  );

  // Exported role: HW IT Security Author.
  $roles['HW IT Security Author'] = array(
    'name' => 'HW IT Security Author',
    'weight' => 46,
  );

  // Exported role: HW IT Security Moderator.
  $roles['HW IT Security Moderator'] = array(
    'name' => 'HW IT Security Moderator',
    'weight' => 48,
  );

  // Exported role: HW IT Security Publisher.
  $roles['HW IT Security Publisher'] = array(
    'name' => 'HW IT Security Publisher',
    'weight' => 47,
  );

  // Exported role: HW IT Services Author.
  $roles['HW IT Services Author'] = array(
    'name' => 'HW IT Services Author',
    'weight' => 49,
  );

  // Exported role: HW IT Services Moderator.
  $roles['HW IT Services Moderator'] = array(
    'name' => 'HW IT Services Moderator',
    'weight' => 51,
  );

  // Exported role: HW IT Services Publisher.
  $roles['HW IT Services Publisher'] = array(
    'name' => 'HW IT Services Publisher',
    'weight' => 50,
  );

  // Exported role: HW IT Software Author.
  $roles['HW IT Software Author'] = array(
    'name' => 'HW IT Software Author',
    'weight' => 9,
  );

  // Exported role: HW IT Software Moderator.
  $roles['HW IT Software Moderator'] = array(
    'name' => 'HW IT Software Moderator',
    'weight' => 11,
  );

  // Exported role: HW IT Software Publisher.
  $roles['HW IT Software Publisher'] = array(
    'name' => 'HW IT Software Publisher',
    'weight' => 10,
  );

  // Exported role: HW Motor Vehicles Author.
  $roles['HW Motor Vehicles Author'] = array(
    'name' => 'HW Motor Vehicles Author',
    'weight' => 52,
  );

  // Exported role: HW Motor Vehicles Moderator.
  $roles['HW Motor Vehicles Moderator'] = array(
    'name' => 'HW Motor Vehicles Moderator',
    'weight' => 54,
  );

  // Exported role: HW Motor Vehicles Publisher.
  $roles['HW Motor Vehicles Publisher'] = array(
    'name' => 'HW Motor Vehicles Publisher',
    'weight' => 53,
  );

  // Exported role: HW Professional Services Author.
  $roles['HW Professional Services Author'] = array(
    'name' => 'HW Professional Services Author',
    'weight' => 22,
  );

  // Exported role: HW Professional Services Moderator.
  $roles['HW Professional Services Moderator'] = array(
    'name' => 'HW Professional Services Moderator',
    'weight' => 24,
  );

  // Exported role: HW Professional Services Publisher.
  $roles['HW Professional Services Publisher'] = array(
    'name' => 'HW Professional Services Publisher',
    'weight' => 23,
  );

  // Exported role: HW Security Protection Author.
  $roles['HW Security Protection Author'] = array(
    'name' => 'HW Security Protection Author',
    'weight' => 67,
  );

  // Exported role: HW Security Protection Moderator.
  $roles['HW Security Protection Moderator'] = array(
    'name' => 'HW Security Protection Moderator',
    'weight' => 69,
  );

  // Exported role: HW Security Protection Publisher.
  $roles['HW Security Protection Publisher'] = array(
    'name' => 'HW Security Protection Publisher',
    'weight' => 68,
  );

  // Exported role: HW Small Package Delivery Author.
  $roles['HW Small Package Delivery Author'] = array(
    'name' => 'HW Small Package Delivery Author',
    'weight' => 25,
  );

  // Exported role: HW Small Package Delivery Moderator.
  $roles['HW Small Package Delivery Moderator'] = array(
    'name' => 'HW Small Package Delivery Moderator',
    'weight' => 27,
  );

  // Exported role: HW Small Package Delivery Publisher.
  $roles['HW Small Package Delivery Publisher'] = array(
    'name' => 'HW Small Package Delivery Publisher',
    'weight' => 26,
  );

  // Exported role: HW Talent Development Author.
  $roles['HW Talent Development Author'] = array(
    'name' => 'HW Talent Development Author',
    'weight' => 17,
  );

  // Exported role: HW Talent Development Moderator.
  $roles['HW Talent Development Moderator'] = array(
    'name' => 'HW Talent Development Moderator',
    'weight' => 21,
  );

  // Exported role: HW Talent Development Publisher.
  $roles['HW Talent Development Publisher'] = array(
    'name' => 'HW Talent Development Publisher',
    'weight' => 19,
  );

  // Exported role: HW Telecommunications Author.
  $roles['HW Telecommunications Author'] = array(
    'name' => 'HW Telecommunications Author',
    'weight' => 37,
  );

  // Exported role: HW Telecommunications Moderator.
  $roles['HW Telecommunications Moderator'] = array(
    'name' => 'HW Telecommunications Moderator',
    'weight' => 39,
  );

  // Exported role: HW Telecommunications Publisher.
  $roles['HW Telecommunications Publisher'] = array(
    'name' => 'HW Telecommunications Publisher',
    'weight' => 38,
  );

  // Exported role: HW Tools Hardware Author.
  $roles['HW Tools Hardware Author'] = array(
    'name' => 'HW Tools Hardware Author',
    'weight' => 28,
  );

  // Exported role: HW Tools Hardware Moderator.
  $roles['HW Tools Hardware Moderator'] = array(
    'name' => 'HW Tools Hardware Moderator',
    'weight' => 30,
  );

  // Exported role: HW Tools Hardware Publisher.
  $roles['HW Tools Hardware Publisher'] = array(
    'name' => 'HW Tools Hardware Publisher',
    'weight' => 29,
  );

  // Exported role: HW Travel Author.
  $roles['HW Travel Author'] = array(
    'name' => 'HW Travel Author',
    'weight' => 55,
  );

  // Exported role: HW Travel Moderator.
  $roles['HW Travel Moderator'] = array(
    'name' => 'HW Travel Moderator',
    'weight' => 57,
  );

  // Exported role: HW Travel Publisher.
  $roles['HW Travel Publisher'] = array(
    'name' => 'HW Travel Publisher',
    'weight' => 56,
  );

  // Exported role: HW Workplace Environment Author.
  $roles['HW Workplace Environment Author'] = array(
    'name' => 'HW Workplace Environment Author',
    'weight' => 34,
  );

  // Exported role: HW Workplace Environment Moderator.
  $roles['HW Workplace Environment Moderator'] = array(
    'name' => 'HW Workplace Environment Moderator',
    'weight' => 36,
  );

  // Exported role: HW Workplace Environment Publisher.
  $roles['HW Workplace Environment Publisher'] = array(
    'name' => 'HW Workplace Environment Publisher',
    'weight' => 35,
  );

  // Exported role: Public Access Gatekeeper.
  $roles['Public Access Gatekeeper'] = array(
    'name' => 'Public Access Gatekeeper',
    'weight' => 70,
  );

  // Exported role: Public User.
  $roles['Public User'] = array(
    'name' => 'Public User',
    'weight' => 71,
  );

  // Exported role: Site Manager.
  $roles['Site Manager'] = array(
    'name' => 'Site Manager',
    'weight' => 5,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  return $roles;
}
