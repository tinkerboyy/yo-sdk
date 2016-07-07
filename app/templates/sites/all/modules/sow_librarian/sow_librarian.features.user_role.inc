<?php
/**
 * @file
 * sow_librarian.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sow_librarian_user_default_roles() {
  $roles = array();

  // Exported role: SOW Librarian.
  $roles['SOW Librarian'] = array(
    'name' => 'SOW Librarian',
    'weight' => 13,
  );

  return $roles;
}
