<?php
/**
 * @file
 * hallways_roles_and_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hallways_roles_and_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'Solution Manager' => 'Solution Manager',
      'Solutions Finder Admin' => 'Solutions Finder Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'Solution Manager' => 'Solution Manager',
      'Solutions Finder Admin' => 'Solutions Finder Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access advuser'.
  $permissions['access advuser'] = array(
    'name' => 'access advuser',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'advuser',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Public User' => 'Public User',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access statistics'.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'access workbench access by role'.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced forum'.
  $permissions['administer advanced forum'] = array(
    'name' => 'administer advanced forum',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'administer advuser'.
  $permissions['administer advuser'] = array(
    'name' => 'administer advuser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advuser',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer boxes'.
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'boxes',
  );

  // Exported permission: 'administer browscap'.
  $permissions['administer browscap'] = array(
    'name' => 'administer browscap',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'browscap',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Gateway Moderator' => 'Gateway Moderator',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer custom content'.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: 'administer exclude node title'.
  $permissions['administer exclude node title'] = array(
    'name' => 'administer exclude node title',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'forum',
  );

  // Exported permission: 'administer front page'.
  $permissions['administer front page'] = array(
    'name' => 'administer front page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'front_page',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer pdf reader'.
  $permissions['administer pdf reader'] = array(
    'name' => 'administer pdf reader',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pdf_reader',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer private files download permission'.
  $permissions['administer private files download permission'] = array(
    'name' => 'administer private files download permission',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'private_files_download_permission',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer statistics'.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'administer string overrides'.
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer track da files'.
  $permissions['administer track da files'] = array(
    'name' => 'administer track da files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'track_da_files',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench access'.
  $permissions['administer workbench access'] = array(
    'name' => 'administer workbench access',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'assign workbench access'.
  $permissions['assign workbench access'] = array(
    'name' => 'assign workbench access',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'batch update workbench access'.
  $permissions['batch update workbench access'] = array(
    'name' => 'batch update workbench access',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bulk upload media'.
  $permissions['bulk upload media'] = array(
    'name' => 'bulk upload media',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bulk_media_upload',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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

  // Exported permission: 'bypass private files download permission'.
  $permissions['bypass private files download permission'] = array(
    'name' => 'bypass private files download permission',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'private_files_download_permission',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create article_file_upload content'.
  $permissions['create article_file_upload content'] = array(
    'name' => 'create article_file_upload content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create basic_page_without_workbench content'.
  $permissions['create basic_page_without_workbench content'] = array(
    'name' => 'create basic_page_without_workbench content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create comparison_wizard content'.
  $permissions['create comparison_wizard content'] = array(
    'name' => 'create comparison_wizard content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contact content'.
  $permissions['create contact content'] = array(
    'name' => 'create contact content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create downloadable_article content'.
  $permissions['create downloadable_article content'] = array(
    'name' => 'create downloadable_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create events content'.
  $permissions['create events content'] = array(
    'name' => 'create events content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create footer_content content'.
  $permissions['create footer_content content'] = array(
    'name' => 'create footer_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create forum content'.
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create group content'.
  $permissions['create group content'] = array(
    'name' => 'create group content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create hallways_document content'.
  $permissions['create hallways_document content'] = array(
    'name' => 'create hallways_document content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create hallways_resources content'.
  $permissions['create hallways_resources content'] = array(
    'name' => 'create hallways_resources content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create hallways_transactional_platforms content'.
  $permissions['create hallways_transactional_platforms content'] = array(
    'name' => 'create hallways_transactional_platforms content',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create help content'.
  $permissions['create help content'] = array(
    'name' => 'create help content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create homepage_random_content content'.
  $permissions['create homepage_random_content content'] = array(
    'name' => 'create homepage_random_content content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create podcast_article content'.
  $permissions['create podcast_article content'] = array(
    'name' => 'create podcast_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create portfolio content'.
  $permissions['create portfolio content'] = array(
    'name' => 'create portfolio content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create pricing_table content'.
  $permissions['create pricing_table content'] = array(
    'name' => 'create pricing_table content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project_file_upload content'.
  $permissions['create project_file_upload content'] = array(
    'name' => 'create project_file_upload content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create resources_file content'.
  $permissions['create resources_file content'] = array(
    'name' => 'create resources_file content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Solution Manager' => 'Solution Manager',
      'Solutions Finder Admin' => 'Solutions Finder Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create solutions_matrix content'.
  $permissions['create solutions_matrix content'] = array(
    'name' => 'create solutions_matrix content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create sow content'.
  $permissions['create sow content'] = array(
    'name' => 'create sow content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create sow_modals content'.
  $permissions['create sow_modals content'] = array(
    'name' => 'create sow_modals content',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create team content'.
  $permissions['create team content'] = array(
    'name' => 'create team content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create test_content content'.
  $permissions['create test_content content'] = array(
    'name' => 'create test_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create video_article content'.
  $permissions['create video_article content'] = array(
    'name' => 'create video_article content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create view_page content'.
  $permissions['create view_page content'] = array(
    'name' => 'create view_page content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article_file_upload content'.
  $permissions['delete any article_file_upload content'] = array(
    'name' => 'delete any article_file_upload content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any basic_page_without_workbench content'.
  $permissions['delete any basic_page_without_workbench content'] = array(
    'name' => 'delete any basic_page_without_workbench content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any comparison_wizard content'.
  $permissions['delete any comparison_wizard content'] = array(
    'name' => 'delete any comparison_wizard content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact content'.
  $permissions['delete any contact content'] = array(
    'name' => 'delete any contact content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any downloadable_article content'.
  $permissions['delete any downloadable_article content'] = array(
    'name' => 'delete any downloadable_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any events content'.
  $permissions['delete any events content'] = array(
    'name' => 'delete any events content',
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

  // Exported permission: 'delete any footer_content content'.
  $permissions['delete any footer_content content'] = array(
    'name' => 'delete any footer_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any forum content'.
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete any group content'.
  $permissions['delete any group content'] = array(
    'name' => 'delete any group content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete any hallways_document content'.
  $permissions['delete any hallways_document content'] = array(
    'name' => 'delete any hallways_document content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hallways_resources content'.
  $permissions['delete any hallways_resources content'] = array(
    'name' => 'delete any hallways_resources content',
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

  // Exported permission: 'delete any hallways_transactional_platforms content'.
  $permissions['delete any hallways_transactional_platforms content'] = array(
    'name' => 'delete any hallways_transactional_platforms content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any help content'.
  $permissions['delete any help content'] = array(
    'name' => 'delete any help content',
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

  // Exported permission: 'delete any homepage_random_content content'.
  $permissions['delete any homepage_random_content content'] = array(
    'name' => 'delete any homepage_random_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete any podcast_article content'.
  $permissions['delete any podcast_article content'] = array(
    'name' => 'delete any podcast_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any portfolio content'.
  $permissions['delete any portfolio content'] = array(
    'name' => 'delete any portfolio content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any pricing_table content'.
  $permissions['delete any pricing_table content'] = array(
    'name' => 'delete any pricing_table content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project_file_upload content'.
  $permissions['delete any project_file_upload content'] = array(
    'name' => 'delete any project_file_upload content',
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

  // Exported permission: 'delete any resources_file content'.
  $permissions['delete any resources_file content'] = array(
    'name' => 'delete any resources_file content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete any solutions_matrix content'.
  $permissions['delete any solutions_matrix content'] = array(
    'name' => 'delete any solutions_matrix content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any sow content'.
  $permissions['delete any sow content'] = array(
    'name' => 'delete any sow content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete any sow_modals content'.
  $permissions['delete any sow_modals content'] = array(
    'name' => 'delete any sow_modals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any team content'.
  $permissions['delete any team content'] = array(
    'name' => 'delete any team content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any test_content content'.
  $permissions['delete any test_content content'] = array(
    'name' => 'delete any test_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any video_article content'.
  $permissions['delete any video_article content'] = array(
    'name' => 'delete any video_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any view_page content'.
  $permissions['delete any view_page content'] = array(
    'name' => 'delete any view_page content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article_file_upload content'.
  $permissions['delete own article_file_upload content'] = array(
    'name' => 'delete own article_file_upload content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own basic_page_without_workbench content'.
  $permissions['delete own basic_page_without_workbench content'] = array(
    'name' => 'delete own basic_page_without_workbench content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own comments'.
  $permissions['delete own comments'] = array(
    'name' => 'delete own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commentdelete',
  );

  // Exported permission: 'delete own comparison_wizard content'.
  $permissions['delete own comparison_wizard content'] = array(
    'name' => 'delete own comparison_wizard content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact content'.
  $permissions['delete own contact content'] = array(
    'name' => 'delete own contact content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own downloadable_article content'.
  $permissions['delete own downloadable_article content'] = array(
    'name' => 'delete own downloadable_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own events content'.
  $permissions['delete own events content'] = array(
    'name' => 'delete own events content',
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

  // Exported permission: 'delete own footer_content content'.
  $permissions['delete own footer_content content'] = array(
    'name' => 'delete own footer_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own forum content'.
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete own group content'.
  $permissions['delete own group content'] = array(
    'name' => 'delete own group content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete own hallways_document content'.
  $permissions['delete own hallways_document content'] = array(
    'name' => 'delete own hallways_document content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hallways_resources content'.
  $permissions['delete own hallways_resources content'] = array(
    'name' => 'delete own hallways_resources content',
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

  // Exported permission: 'delete own hallways_transactional_platforms content'.
  $permissions['delete own hallways_transactional_platforms content'] = array(
    'name' => 'delete own hallways_transactional_platforms content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own help content'.
  $permissions['delete own help content'] = array(
    'name' => 'delete own help content',
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

  // Exported permission: 'delete own homepage_random_content content'.
  $permissions['delete own homepage_random_content content'] = array(
    'name' => 'delete own homepage_random_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete own podcast_article content'.
  $permissions['delete own podcast_article content'] = array(
    'name' => 'delete own podcast_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own portfolio content'.
  $permissions['delete own portfolio content'] = array(
    'name' => 'delete own portfolio content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own pricing_table content'.
  $permissions['delete own pricing_table content'] = array(
    'name' => 'delete own pricing_table content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project_file_upload content'.
  $permissions['delete own project_file_upload content'] = array(
    'name' => 'delete own project_file_upload content',
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

  // Exported permission: 'delete own resources_file content'.
  $permissions['delete own resources_file content'] = array(
    'name' => 'delete own resources_file content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'Solution Manager' => 'Solution Manager',
      'Solutions Finder Admin' => 'Solutions Finder Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own solutions_matrix content'.
  $permissions['delete own solutions_matrix content'] = array(
    'name' => 'delete own solutions_matrix content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own sow content'.
  $permissions['delete own sow content'] = array(
    'name' => 'delete own sow content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'delete own sow_modals content'.
  $permissions['delete own sow_modals content'] = array(
    'name' => 'delete own sow_modals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own team content'.
  $permissions['delete own team content'] = array(
    'name' => 'delete own team content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own test_content content'.
  $permissions['delete own test_content content'] = array(
    'name' => 'delete own test_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own video_article content'.
  $permissions['delete own video_article content'] = array(
    'name' => 'delete own video_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own view_page content'.
  $permissions['delete own view_page content'] = array(
    'name' => 'delete own view_page content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in category'.
  $permissions['delete terms in category'] = array(
    'name' => 'delete terms in category',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in categoryclassification'.
  $permissions['delete terms in categoryclassification'] = array(
    'name' => 'delete terms in categoryclassification',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in forums'.
  $permissions['delete terms in forums'] = array(
    'name' => 'delete terms in forums',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in help'.
  $permissions['delete terms in help'] = array(
    'name' => 'delete terms in help',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in interaction_mode'.
  $permissions['delete terms in interaction_mode'] = array(
    'name' => 'delete terms in interaction_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in portfolio'.
  $permissions['delete terms in portfolio'] = array(
    'name' => 'delete terms in portfolio',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in sow_keywords_list'.
  $permissions['delete terms in sow_keywords_list'] = array(
    'name' => 'delete terms in sow_keywords_list',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in workbenchhallwaygroups'.
  $permissions['delete terms in workbenchhallwaygroups'] = array(
    'name' => 'delete terms in workbenchhallwaygroups',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article_file_upload content'.
  $permissions['edit any article_file_upload content'] = array(
    'name' => 'edit any article_file_upload content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any basic_page_without_workbench content'.
  $permissions['edit any basic_page_without_workbench content'] = array(
    'name' => 'edit any basic_page_without_workbench content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any comparison_wizard content'.
  $permissions['edit any comparison_wizard content'] = array(
    'name' => 'edit any comparison_wizard content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact content'.
  $permissions['edit any contact content'] = array(
    'name' => 'edit any contact content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any downloadable_article content'.
  $permissions['edit any downloadable_article content'] = array(
    'name' => 'edit any downloadable_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any events content'.
  $permissions['edit any events content'] = array(
    'name' => 'edit any events content',
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

  // Exported permission: 'edit any footer_content content'.
  $permissions['edit any footer_content content'] = array(
    'name' => 'edit any footer_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any forum content'.
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit any group content'.
  $permissions['edit any group content'] = array(
    'name' => 'edit any group content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit any hallways_document content'.
  $permissions['edit any hallways_document content'] = array(
    'name' => 'edit any hallways_document content',
    'roles' => array(
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hallways_resources content'.
  $permissions['edit any hallways_resources content'] = array(
    'name' => 'edit any hallways_resources content',
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

  // Exported permission: 'edit any hallways_transactional_platforms content'.
  $permissions['edit any hallways_transactional_platforms content'] = array(
    'name' => 'edit any hallways_transactional_platforms content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any help content'.
  $permissions['edit any help content'] = array(
    'name' => 'edit any help content',
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

  // Exported permission: 'edit any homepage_random_content content'.
  $permissions['edit any homepage_random_content content'] = array(
    'name' => 'edit any homepage_random_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit any podcast_article content'.
  $permissions['edit any podcast_article content'] = array(
    'name' => 'edit any podcast_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any portfolio content'.
  $permissions['edit any portfolio content'] = array(
    'name' => 'edit any portfolio content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any pricing_table content'.
  $permissions['edit any pricing_table content'] = array(
    'name' => 'edit any pricing_table content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project_file_upload content'.
  $permissions['edit any project_file_upload content'] = array(
    'name' => 'edit any project_file_upload content',
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

  // Exported permission: 'edit any resources_file content'.
  $permissions['edit any resources_file content'] = array(
    'name' => 'edit any resources_file content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit any solutions_matrix content'.
  $permissions['edit any solutions_matrix content'] = array(
    'name' => 'edit any solutions_matrix content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any sow content'.
  $permissions['edit any sow content'] = array(
    'name' => 'edit any sow content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any sow_modals content'.
  $permissions['edit any sow_modals content'] = array(
    'name' => 'edit any sow_modals content',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any team content'.
  $permissions['edit any team content'] = array(
    'name' => 'edit any team content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any test_content content'.
  $permissions['edit any test_content content'] = array(
    'name' => 'edit any test_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any video_article content'.
  $permissions['edit any video_article content'] = array(
    'name' => 'edit any video_article content',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any view_page content'.
  $permissions['edit any view_page content'] = array(
    'name' => 'edit any view_page content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit boxes'.
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'boxes',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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

  // Exported permission: 'edit own article_file_upload content'.
  $permissions['edit own article_file_upload content'] = array(
    'name' => 'edit own article_file_upload content',
    'roles' => array(
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own basic_page_without_workbench content'.
  $permissions['edit own basic_page_without_workbench content'] = array(
    'name' => 'edit own basic_page_without_workbench content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own comparison_wizard content'.
  $permissions['edit own comparison_wizard content'] = array(
    'name' => 'edit own comparison_wizard content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own contact content'.
  $permissions['edit own contact content'] = array(
    'name' => 'edit own contact content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own downloadable_article content'.
  $permissions['edit own downloadable_article content'] = array(
    'name' => 'edit own downloadable_article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own events content'.
  $permissions['edit own events content'] = array(
    'name' => 'edit own events content',
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

  // Exported permission: 'edit own footer_content content'.
  $permissions['edit own footer_content content'] = array(
    'name' => 'edit own footer_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own forum content'.
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit own group content'.
  $permissions['edit own group content'] = array(
    'name' => 'edit own group content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit own hallways_document content'.
  $permissions['edit own hallways_document content'] = array(
    'name' => 'edit own hallways_document content',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hallways_resources content'.
  $permissions['edit own hallways_resources content'] = array(
    'name' => 'edit own hallways_resources content',
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

  // Exported permission: 'edit own hallways_transactional_platforms content'.
  $permissions['edit own hallways_transactional_platforms content'] = array(
    'name' => 'edit own hallways_transactional_platforms content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own help content'.
  $permissions['edit own help content'] = array(
    'name' => 'edit own help content',
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

  // Exported permission: 'edit own homepage_random_content content'.
  $permissions['edit own homepage_random_content content'] = array(
    'name' => 'edit own homepage_random_content content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
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

  // Exported permission: 'edit own podcast_article content'.
  $permissions['edit own podcast_article content'] = array(
    'name' => 'edit own podcast_article content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own portfolio content'.
  $permissions['edit own portfolio content'] = array(
    'name' => 'edit own portfolio content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own pricing_table content'.
  $permissions['edit own pricing_table content'] = array(
    'name' => 'edit own pricing_table content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project_file_upload content'.
  $permissions['edit own project_file_upload content'] = array(
    'name' => 'edit own project_file_upload content',
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

  // Exported permission: 'edit own resources_file content'.
  $permissions['edit own resources_file content'] = array(
    'name' => 'edit own resources_file content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'Solution Manager' => 'Solution Manager',
      'Solutions Finder Admin' => 'Solutions Finder Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own solutions_matrix content'.
  $permissions['edit own solutions_matrix content'] = array(
    'name' => 'edit own solutions_matrix content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sow content'.
  $permissions['edit own sow content'] = array(
    'name' => 'edit own sow content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Freight Author' => 'HW Freight Author',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Travel Author' => 'HW Travel Author',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sow_modals content'.
  $permissions['edit own sow_modals content'] = array(
    'name' => 'edit own sow_modals content',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own team content'.
  $permissions['edit own team content'] = array(
    'name' => 'edit own team content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own test_content content'.
  $permissions['edit own test_content content'] = array(
    'name' => 'edit own test_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own video_article content'.
  $permissions['edit own video_article content'] = array(
    'name' => 'edit own video_article content',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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

  // Exported permission: 'edit own view_page content'.
  $permissions['edit own view_page content'] = array(
    'name' => 'edit own view_page content',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in category'.
  $permissions['edit terms in category'] = array(
    'name' => 'edit terms in category',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in categoryclassification'.
  $permissions['edit terms in categoryclassification'] = array(
    'name' => 'edit terms in categoryclassification',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in forums'.
  $permissions['edit terms in forums'] = array(
    'name' => 'edit terms in forums',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in help'.
  $permissions['edit terms in help'] = array(
    'name' => 'edit terms in help',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in interaction_mode'.
  $permissions['edit terms in interaction_mode'] = array(
    'name' => 'edit terms in interaction_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in portfolio'.
  $permissions['edit terms in portfolio'] = array(
    'name' => 'edit terms in portfolio',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in sow_keywords_list'.
  $permissions['edit terms in sow_keywords_list'] = array(
    'name' => 'edit terms in sow_keywords_list',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in workbenchhallwaygroups'.
  $permissions['edit terms in workbenchhallwaygroups'] = array(
    'name' => 'edit terms in workbenchhallwaygroups',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'exclude any node title'.
  $permissions['exclude any node title'] = array(
    'name' => 'exclude any node title',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'exclude own node title'.
  $permissions['exclude own node title'] = array(
    'name' => 'exclude own node title',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'execute comment_publish_action'.
  $permissions['execute comment_publish_action'] = array(
    'name' => 'execute comment_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_save_action'.
  $permissions['execute comment_save_action'] = array(
    'name' => 'execute comment_save_action',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_unpublish_action'.
  $permissions['execute comment_unpublish_action'] = array(
    'name' => 'execute comment_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_unpublish_by_keyword_action'.
  $permissions['execute comment_unpublish_by_keyword_action'] = array(
    'name' => 'execute comment_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_assign_owner_action'.
  $permissions['execute node_assign_owner_action'] = array(
    'name' => 'execute node_assign_owner_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_sticky_action'.
  $permissions['execute node_make_sticky_action'] = array(
    'name' => 'execute node_make_sticky_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_unsticky_action'.
  $permissions['execute node_make_unsticky_action'] = array(
    'name' => 'execute node_make_unsticky_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_promote_action'.
  $permissions['execute node_promote_action'] = array(
    'name' => 'execute node_promote_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_save_action'.
  $permissions['execute node_save_action'] = array(
    'name' => 'execute node_save_action',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpromote_action'.
  $permissions['execute node_unpromote_action'] = array(
    'name' => 'execute node_unpromote_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute og_membership_delete_action'.
  $permissions['execute og_membership_delete_action'] = array(
    'name' => 'execute og_membership_delete_action',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute og_set_state_action'.
  $permissions['execute og_set_state_action'] = array(
    'name' => 'execute og_set_state_action',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute og_user_roles_action'.
  $permissions['execute og_user_roles_action'] = array(
    'name' => 'execute og_user_roles_action',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_node_update_action'.
  $permissions['execute pathauto_node_update_action'] = array(
    'name' => 'execute pathauto_node_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_taxonomy_term_update_action'.
  $permissions['execute pathauto_taxonomy_term_update_action'] = array(
    'name' => 'execute pathauto_taxonomy_term_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_user_update_action'.
  $permissions['execute pathauto_user_update_action'] = array(
    'name' => 'execute pathauto_user_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_block_ip_action'.
  $permissions['execute system_block_ip_action'] = array(
    'name' => 'execute system_block_ip_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_goto_action'.
  $permissions['execute system_goto_action'] = array(
    'name' => 'execute system_goto_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_message_action'.
  $permissions['execute system_message_action'] = array(
    'name' => 'execute system_message_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_send_email_action'.
  $permissions['execute system_send_email_action'] = array(
    'name' => 'execute system_send_email_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute user_block_user_action'.
  $permissions['execute user_block_user_action'] = array(
    'name' => 'execute user_block_user_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_archive_action'.
  $permissions['execute views_bulk_operations_archive_action'] = array(
    'name' => 'execute views_bulk_operations_archive_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_argument_selector_action'.
  $permissions['execute views_bulk_operations_argument_selector_action'] = array(
    'name' => 'execute views_bulk_operations_argument_selector_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_item'.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_revision'.
  $permissions['execute views_bulk_operations_delete_revision'] = array(
    'name' => 'execute views_bulk_operations_delete_revision',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_modify_action'.
  $permissions['execute views_bulk_operations_modify_action'] = array(
    'name' => 'execute views_bulk_operations_modify_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_script_action'.
  $permissions['execute views_bulk_operations_script_action'] = array(
    'name' => 'execute views_bulk_operations_script_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_cancel_action'.
  $permissions['execute views_bulk_operations_user_cancel_action'] = array(
    'name' => 'execute views_bulk_operations_user_cancel_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_roles_action'.
  $permissions['execute views_bulk_operations_user_roles_action'] = array(
    'name' => 'execute views_bulk_operations_user_roles_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute workbench_moderation_set_state_action'.
  $permissions['execute workbench_moderation_set_state_action'] = array(
    'name' => 'execute workbench_moderation_set_state_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'export nodes'.
  $permissions['export nodes'] = array(
    'name' => 'export nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'export own nodes'.
  $permissions['export own nodes'] = array(
    'name' => 'export own nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'grant content access'.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'grant own content access'.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'initialize tracked files displays datas'.
  $permissions['initialize tracked files displays datas'] = array(
    'name' => 'initialize tracked files displays datas',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'track_da_files',
  );

  // Exported permission: 'loft_data_grids:BootstrapHTMLExporter'.
  $permissions['loft_data_grids:BootstrapHTMLExporter'] = array(
    'name' => 'loft_data_grids:BootstrapHTMLExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:CSVExporter'.
  $permissions['loft_data_grids:CSVExporter'] = array(
    'name' => 'loft_data_grids:CSVExporter',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:DrupalTableExporter'.
  $permissions['loft_data_grids:DrupalTableExporter'] = array(
    'name' => 'loft_data_grids:DrupalTableExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:FlatTextExporter'.
  $permissions['loft_data_grids:FlatTextExporter'] = array(
    'name' => 'loft_data_grids:FlatTextExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:HTMLExporter'.
  $permissions['loft_data_grids:HTMLExporter'] = array(
    'name' => 'loft_data_grids:HTMLExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:JSONExporter'.
  $permissions['loft_data_grids:JSONExporter'] = array(
    'name' => 'loft_data_grids:JSONExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:MarkdownExporter'.
  $permissions['loft_data_grids:MarkdownExporter'] = array(
    'name' => 'loft_data_grids:MarkdownExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:MarkdownTableExporter'.
  $permissions['loft_data_grids:MarkdownTableExporter'] = array(
    'name' => 'loft_data_grids:MarkdownTableExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:TabTextExporter'.
  $permissions['loft_data_grids:TabTextExporter'] = array(
    'name' => 'loft_data_grids:TabTextExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:TextListExporter'.
  $permissions['loft_data_grids:TextListExporter'] = array(
    'name' => 'loft_data_grids:TextListExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:ValuesOnlyExporter'.
  $permissions['loft_data_grids:ValuesOnlyExporter'] = array(
    'name' => 'loft_data_grids:ValuesOnlyExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:XLSXExporter'.
  $permissions['loft_data_grids:XLSXExporter'] = array(
    'name' => 'loft_data_grids:XLSXExporter',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:XMLExporter'.
  $permissions['loft_data_grids:XMLExporter'] = array(
    'name' => 'loft_data_grids:XMLExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'loft_data_grids:YAMLExporter'.
  $permissions['loft_data_grids:YAMLExporter'] = array(
    'name' => 'loft_data_grids:YAMLExporter',
    'roles' => array(),
    'module' => 'loft_data_grids',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as any user'.
  $permissions['masquerade as any user'] = array(
    'name' => 'masquerade as any user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Moderator' => 'HW Talent Development Moderator',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'media library add to library'.
  $permissions['media library add to library'] = array(
    'name' => 'media library add to library',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'media_library',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'receive email advuser'.
  $permissions['receive email advuser'] = array(
    'name' => 'receive email advuser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advuser',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Public User' => 'Public User',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'send email advuser'.
  $permissions['send email advuser'] = array(
    'name' => 'send email advuser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advuser',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'sow_submit'.
  $permissions['sow_submit'] = array(
    'name' => 'sow_submit',
    'roles' => array(
      'SOW Librarian' => 'SOW Librarian',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'sow_user_submit',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use PHP to import nodes'.
  $permissions['use PHP to import nodes'] = array(
    'name' => 'use PHP to import nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use exclude node title'.
  $permissions['use exclude node title'] = array(
    'name' => 'use exclude node title',
    'roles' => array(
      'Public User' => 'Public User',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'users_export:export as BootstrapHTMLExporter'.
  $permissions['users_export:export as BootstrapHTMLExporter'] = array(
    'name' => 'users_export:export as BootstrapHTMLExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as CSVExporter'.
  $permissions['users_export:export as CSVExporter'] = array(
    'name' => 'users_export:export as CSVExporter',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as DrupalTableExporter'.
  $permissions['users_export:export as DrupalTableExporter'] = array(
    'name' => 'users_export:export as DrupalTableExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as FlatTextExporter'.
  $permissions['users_export:export as FlatTextExporter'] = array(
    'name' => 'users_export:export as FlatTextExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as HTMLExporter'.
  $permissions['users_export:export as HTMLExporter'] = array(
    'name' => 'users_export:export as HTMLExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as JSONExporter'.
  $permissions['users_export:export as JSONExporter'] = array(
    'name' => 'users_export:export as JSONExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as MarkdownExporter'.
  $permissions['users_export:export as MarkdownExporter'] = array(
    'name' => 'users_export:export as MarkdownExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as MarkdownTableExporter'.
  $permissions['users_export:export as MarkdownTableExporter'] = array(
    'name' => 'users_export:export as MarkdownTableExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as TabTextExporter'.
  $permissions['users_export:export as TabTextExporter'] = array(
    'name' => 'users_export:export as TabTextExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as TextListExporter'.
  $permissions['users_export:export as TextListExporter'] = array(
    'name' => 'users_export:export as TextListExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as ValuesOnlyExporter'.
  $permissions['users_export:export as ValuesOnlyExporter'] = array(
    'name' => 'users_export:export as ValuesOnlyExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as XLSXExporter'.
  $permissions['users_export:export as XLSXExporter'] = array(
    'name' => 'users_export:export as XLSXExporter',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as XMLExporter'.
  $permissions['users_export:export as XMLExporter'] = array(
    'name' => 'users_export:export as XMLExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'users_export:export as YAMLExporter'.
  $permissions['users_export:export as YAMLExporter'] = array(
    'name' => 'users_export:export as YAMLExporter',
    'roles' => array(),
    'module' => 'users_export',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'Public User' => 'Public User',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view forum statistics'.
  $permissions['view forum statistics'] = array(
    'name' => 'view forum statistics',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'view last edited notice'.
  $permissions['view last edited notice'] = array(
    'name' => 'view last edited notice',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Author' => 'HW Talent Development Author',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'Public User' => 'Public User',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view post access counter'.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Gateway Author' => 'Gateway Author',
      'Gateway Moderator' => 'Gateway Moderator',
      'Gateway Publisher' => 'Gateway Publisher',
      'HW Admin Support Author' => 'HW Admin Support Author',
      'HW Admin Support Moderator' => 'HW Admin Support Moderator',
      'HW Admin Support Publisher' => 'HW Admin Support Publisher',
      'HW Card Services Author' => 'HW Card Services Author',
      'HW Card Services Moderator' => 'HW Card Services Moderator',
      'HW Card Services Publisher' => 'HW Card Services Publisher',
      'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
      'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
      'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
      'HW Education and Training Author' => 'HW Education and Training Author',
      'HW Education and Training Moderator' => 'HW Education and Training Moderator',
      'HW Education and Training Publisher' => 'HW Education and Training Publisher',
      'HW Employee Relocation Author' => 'HW Employee Relocation Author',
      'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
      'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Moderator' => 'HW Facilities Maintenance Services Moderator',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
      'HW Freight Author' => 'HW Freight Author',
      'HW Freight Moderator' => 'HW Freight Moderator',
      'HW Freight Publisher' => 'HW Freight Publisher',
      'HW IT Hardware Author' => 'HW IT Hardware Author',
      'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
      'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
      'HW IT Security Author' => 'HW IT Security Author',
      'HW IT Security Moderator' => 'HW IT Security Moderator',
      'HW IT Security Publisher' => 'HW IT Security Publisher',
      'HW IT Services Author' => 'HW IT Services Author',
      'HW IT Services Moderator' => 'HW IT Services Moderator',
      'HW IT Services Publisher' => 'HW IT Services Publisher',
      'HW IT Software Author' => 'HW IT Software Author',
      'HW IT Software Moderator' => 'HW IT Software Moderator',
      'HW IT Software Publisher' => 'HW IT Software Publisher',
      'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
      'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
      'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
      'HW Professional Services Author' => 'HW Professional Services Author',
      'HW Professional Services Moderator' => 'HW Professional Services Moderator',
      'HW Professional Services Publisher' => 'HW Professional Services Publisher',
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Moderator' => 'HW Security Protection Moderator',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
      'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
      'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
      'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
      'HW Talent Development Publisher' => 'HW Talent Development Publisher',
      'HW Telecommunications Author' => 'HW Telecommunications Author',
      'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
      'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
      'HW Tools Hardware Author' => 'HW Tools Hardware Author',
      'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
      'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
      'HW Travel Author' => 'HW Travel Author',
      'HW Travel Moderator' => 'HW Travel Moderator',
      'HW Travel Publisher' => 'HW Travel Publisher',
      'HW Workplace Environment Author' => 'HW Workplace Environment Author',
      'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
      'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
      'Public Access Gatekeeper' => 'Public Access Gatekeeper',
      'SOW Librarian' => 'SOW Librarian',
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view tracked files displays datas'.
  $permissions['view tracked files displays datas'] = array(
    'name' => 'view tracked files displays datas',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'track_da_files',
  );

  // Exported permission: 'view workbench access information'.
  $permissions['view workbench access information'] = array(
    'name' => 'view workbench access information',
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
      'HW Facilities Maintenance Services Author' => 'HW Facilities Maintenance Services Author',
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Author' => 'HW Security Protection Author',
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
    'module' => 'workbench_access',
  );

  // Exported permission: 'view workbench taxonomy pages'.
  $permissions['view workbench taxonomy pages'] = array(
    'name' => 'view workbench taxonomy pages',
    'roles' => array(
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
      'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
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
      'HW Security Protection Publisher' => 'HW Security Protection Publisher',
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
      'Site Manager' => 'Site Manager',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_access',
  );

  return $permissions;
}
