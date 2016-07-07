<?php

/**
*
* @SWG\Definition(
*   definition="SolutionTypes",
*   @SWG\Property(
*     property="id",
*     type="integer",
*     description="Id of Solution Type"
*   ),
*   @SWG\Property(
*     property="name",
*     type="string",
*     description="Name of Solution Type"
*   ),
* 	@SWG\Property(
* 	  property="shortName",
* 	  type="string",
* 	  description="Short Name of Solution Type"
* 	),
* 	@SWG\Property(
* 	  property="Type",
* 	  type="string",
* 	  description="Provides Type info as Contract"
* 	)
* )
*/

function contracts_solution_matrix($fn) {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkContractTypeId, name, shortName FROM tbContractTypes";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}

function fee_types_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkContractFeeTypeId, name, shortName FROM tbContractFeeTypes";

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
   *   path="/solutiontypes",
   *   @SWG\Get(
   *     tags={"solutiontypes"},
   *     summary="Retrieve all solutiontypes",
   *     @SWG\Response(
   *       response=200,
   *       description="List of solutiontypes",
   *       @SWG\Schema(
   *         type="array",
   *           @SWG\Items(ref="#/definitions/SolutionTypes")
   *       )
   *     )
   *   )
   * )
   *
   */
function solution_types_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare sql statement
  $sql = "SELECT pkSolutionTypeId AS id, name, shortName, Type FROM tbSolutionTypes";
  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}
