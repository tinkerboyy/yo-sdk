<?php

/**
*
* @SWG\Definition(
*   definition="Categories",
*   @SWG\Property(
*     property="id",
*     type="integer",
*     description="Id of Category"
*   ),
*   @SWG\Property(
*     property="name",
*     type="string",
*     description="Name of Category"
*   ),
* )
*
* @SWG\Definition(
*   definition="SubCategories",
*   @SWG\Property(
*     property="id",
*     type="integer",
*     description="Id of SubCategory"
*   ),
*   @SWG\Property(
*     property="categoryId",
*     type="string",
*     description="Id of Category"
*   ),
*   @SWG\Property(
*     property="name",
*     type="string",
*     description="Name of SubCategory"
*   ),
* )
*/

function organizations_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkOrganizationId, fkParentOrganizationId, name, shortName FROM tbOrganizations";
  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}

function organization_categories_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkOrganizationTypeId, fkParentOrganizationTypeId, name, shortName, description FROM tbOrganizationTypes";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}

function product_categories_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkProductCategoryId, fkParentProductCategoryId, name, shortName FROM tbProductCategories";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}

function naics_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkNaics2012Id, fkParentNacis2012Id, NAICS_id, name FROM tbNaics2012";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
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
 *   path="/categories",
 *   @SWG\Get(
 *     tags={"categories"},
 *     summary="Retrieve all Categories",
 *     @SWG\Response(
 *       response=200,
 *       description="List of Categories",
 *       @SWG\Schema(
 *         type="array",
 *           @SWG\Items(ref="#/definitions/Categories")
 *       )
 *     )
 *   )
 * )
 *
 * @SWG\Path(
 *   path="/subcategories",
 *   @SWG\Get(
 *     tags={"subcategories"},
 *     summary="Retrieve all SubCategories",
 *     @SWG\Response(
 *       response=200,
 *       description="List of SubCategories",
 *       @SWG\Schema(
 *         type="array",
 *           @SWG\Items(ref="#/definitions/SubCategories")
 *       )
 *     )
 *   )
 * )
 */

function categories_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkProductCategoryId AS id, name
          FROM tbProductCategories
          WHERE fkParentProductCategoryId IS NULL";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}

function subcategories_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pc.pkProductCategoryId AS id, pc.fkParentProductCategoryId AS categoryId, pc.name
          FROM tbProductCategories pc
          WHERE pc.fkParentProductCategoryId IS NOT NULL";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}
