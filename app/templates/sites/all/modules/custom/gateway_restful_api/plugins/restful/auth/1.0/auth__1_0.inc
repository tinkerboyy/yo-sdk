<?php

// By checking the variable, we allow implementing modules to easily implement
// their own "users" resource.
if (variable_get('restful_enable_users_resource', TRUE)) {

  $plugin = array(
    'label' => t('Auth'),
    'description' => t('Export the "Auth" logged in user entity.'),
    'resource' => 'auth',
    'name' => 'auth__1_0',
    'class' => 'RestfulEntityAuth__1_0',
    'entity_type' => 'user',
    'bundle' => 'user',
    // Try to authenticate users with all available authentication types.
    'authentication_types' => array('ag_cookie'),
    // Allow anonymous users to access the resource, given they have the right
    // permissions.
    'authentication_optional' => FALSE,
    'allow_origin' => $GLOBALS['base_url']
  );
}
