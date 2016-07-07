<?php

/**
 * Implements hook_services_resources().
 */
function resource_solution_matrix_services_resources() {

  /**
  *
  * @SWG\Definition(
  *   definition="AvailableTo",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="Id of organization"
  *   ),
  *   @SWG\Property(
  *     property="name",
  *     type="string",
  *     description="Name of organization"
  *   ),
  *   @SWG\Property(
  *     property="fkOptionParentId",
  *     type="integer",
  *     description="Parent Id of organization"
  *   )
  * )
  */

  $resources = array(
    // search
    'ContractSolutions' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all NAICS.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'search_contract_solution_matrix.resource',
        ),
       'callback' => 'contract_solutions_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
       'args' => array(
          array(
            'name' => 'fn',
            'type' => 'string',
            'description' => 'Function to perform',
            'source' => array('path' => '0'),
            'optional' => TRUE,
            'default' => '0',
          ),
        ),
      ),
    ),
  ),
    // contract types
    'ContractTypes' => array(
      'operations'  => array(
        'retrieve' => array(
          'help' => t('API calls for a list of all contract types.'),
          'file' => array(
            'type' => 'inc',
            'module' => 'resource_solution_matrix',
            'name' => 'contracts_solution_matrix.resource',
          ),
          'callback' => 'contracts_solution_matrix',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'fn',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => '0'),
              'optional' => TRUE,
              'default' => '0',
            ),
          ),
        ),
      ),
    ),
    // contract fee types
    'FeeTypes' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API calls for a list of all contract fee types.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'contracts_solution_matrix.resource',
          ),
         'callback' => 'fee_types_solution_matrix',
         'access callback' => 'user_access',
         'access arguments' => array('access content'),
         'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'fn',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => '0'),
              'optional' => TRUE,
              'default' => '0',
            ),
          ),
        ),
      ),
    ),
    // solution types
    'SolutionTypes' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API calls for a list of all solution types.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'contracts_solution_matrix.resource',
        ),
       'callback' => 'solution_types_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'fn',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => '0'),
              'optional' => TRUE,
              'default' => '0',
            ),
          ),
        ),
      ),
    ),
    // organizations
    'Organizations' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all organizations.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'organizations_solution_matrix.resource',
        ),
       'callback' => 'organizations_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
        'args' => array(
          array(
            'name' => 'fn',
            'type' => 'string',
            'description' => 'Function to perform',
            'source' => array('path' => '0'),
            'optional' => TRUE,
            'default' => '0',
          ),
        ),
      ),
    ),
  ),
    // organization types
    'OrganizationCategories' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all organizations types.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'organizations_solution_matrix.resource',
        ),
       'callback' => 'organization_categories_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'fn',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => '0'),
              'optional' => TRUE,
              'default' => '0',
            ),
          ),
        ),
      ),
    ),
    // product categories
    'ProductCategories' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all product categories.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'organizations_solution_matrix.resource',
        ),
       'callback' => 'product_categories_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'fn',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => '0'),
              'optional' => TRUE,
              'default' => '0',
            ),
          ),
        ),
      ),
    ),
    // NAICS
    'NAICS' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all NAICS.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'organizations_solution_matrix.resource',
        ),
       'callback' => 'naics_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
       'args' => array(
          array(
            'name' => 'fn',
            'type' => 'string',
            'description' => 'Function to perform',
            'source' => array('path' => '0'),
            'optional' => TRUE,
            'default' => '0',
          ),
        ),
      ),
    ),
  ),
    // Categories
    'Categories' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all Categories.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'organizations_solution_matrix.resource',
        ),
       'callback' => 'categories_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
       'args' => array(
          array(
            'name' => 'fn',
            'type' => 'string',
            'description' => 'Function to perform',
            'source' => array('path' => '0'),
            'optional' => TRUE,
            'default' => '0',
          ),
        ),
      ),
    ),
  ),
    // Subcategories
    'SubCategories' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all Categories.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'resource_solution_matrix',
          'name' => 'organizations_solution_matrix.resource',
        ),
       'callback' => 'subcategories_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
       'args' => array(
          array(
            'name' => 'fn',
            'type' => 'string',
            'description' => 'Function to perform',
            'source' => array('path' => '0'),
            'optional' => TRUE,
            'default' => '0',
          ),
        ),
      ),
    ),
  ),
    // auth
    'Auth' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all Categories.'),
         'callback' => 'auth_solution_matrix',
         'access callback' => 'user_access',
         'access arguments' => array('access content'),
         'access arguments append' => FALSE,
         'args' => array(
            array(
              'name' => 'fn',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => '0'),
              'optional' => TRUE,
              'default' => '0',
            ),
          ),
        ),
    ),
  ),
    // Avialable to
    'AvailableTo' => array(
      'operations'  => array(
        'retrieve' => array(
        'help' => t('API call to get all available to options.'),
       'callback' => 'available_to_solution_matrix',
       'access callback' => 'user_access',
       'access arguments' => array('access content'),
       'access arguments append' => FALSE,
        'args' => array(
          array(
            'name' => 'fn',
            'type' => 'string',
            'description' => 'Function to perform',
            'source' => array('path' => '0'),
            'optional' => TRUE,
            'default' => '0',
          ),
        ),
      ),
    ),
  ),
);

  return $resources;
}

function auth_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  global $user;

  if (!user_is_logged_in()) {
    return services_error(t('This user is not logged in.'), 403);
  }

  /*
   * If a user id other than the current user's ID is passed, validate that the
   * authenticated user has the correct permissions to read another user's
   * messages.
   */
  if (is_numeric($uid) && ($uid != $user->uid)) {
    if (user_access("read all private messages")) {
      $account = user_load($uid);
    }
    else {
      return services_error(
        t('This user does not have permissions to use this service.'),
        403
      );
    }
  }
  else {
    $account = $user;
  }

  // Return unread count.
  return $account;
}

/**
 * Get a list of entities.
 *
 * @return array
 *   Array of entities, as passed to RestfulEntityBase::viewEntity().
 *
 * @throws RestfulBadRequestException
 *
 * @SWG\Path(
 *   path="/availableto",
 *   @SWG\Get(
 *     tags={"availableto"},
 *     summary="Retrieve all Organizations",
 *     @SWG\Response(
 *       response=200,
 *       description="List of Organizations",
 *       @SWG\Schema(
 *         type="array",
 *           @SWG\Items(ref="#/definitions/AvailableTo")
 *       )
 *     )
 *   )
 * )
 *
 */

function available_to_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkOptionId AS id, name, longName, fkOptionParentId  FROM tbAvailableToOptions WHERE adminOnly IS NULL ORDER By orderBy";
  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}
