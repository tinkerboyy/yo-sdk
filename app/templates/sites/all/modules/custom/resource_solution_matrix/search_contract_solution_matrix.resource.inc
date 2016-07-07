<?php
/**
*
* @SWG\Definition(
*   definition="ContractSolutions",
*   @SWG\Property(
*     property="id",
*     type="integer",
*     description="Id of Solution"
*   ),
*   @SWG\Property(
*     property="managingAgency",
*     type="string",
*     description="Agency Name of Solution"
*   ),
*   @SWG\Property(
*     property="managingAgencyShortName",
*     type="string",
*     description="Short name of Agency"
*   ),
*   @SWG\Property(
*     property="fkFundingOrganizationId",
*     type="integer",
*     description="Foreign key of Funding Organization"
*   ),
*   @SWG\Property(
*     property="name",
*     type="string",
*     description="Name of Solution"
*   ),
*   @SWG\Property(
*     property="categories",
*     type="array",
*     description="List of categories associated with a solution"
*   ),
*   @SWG\Property(
*     property="type",
*     type="string",
*     description="Type of Solution"
*   ),
*   @SWG\Property(
*     property="shortName",
*     type="string",
*     description="short name of Solution Type"
*   ),
*   @SWG\Property(
*     property="expiration",
*     type="string",
*     description="Expiration date of Solution"
*   ),
*   @SWG\Property(
*     property="expirationNote",
*     type="string",
*     description="More notes for Expiration date"
*   ),
*   @SWG\Property(
*     property="description",
*     type="string",
*     description="Description of a solution"
*   ),
*   @SWG\Property(
*     property="feeInfo",
*     type="string",
*     description="Fee Information of a solution"
*   ),
*   @SWG\Property(
*     property="availableToId",
*     type="integer",
*     description="Organization id of a solution"
*   ),
*   @SWG\Property(
*     property="termsAndConditions",
*     type="string",
*     description="Terms And Conditions of a solution"
*   ),
*   @SWG\Property(
*     property="uncontrolledProductList",
*     type="string",
*     description="Uncontrolled ProductList of a solution"
*   ),
*   @SWG\Property(
*     property="servicesProvided",
*     type="array",
*     @SWG\Items(ref="#/definitions/servicesprovided")
*   ),
*   @SWG\Property(
*     property="servicesProvidedText",
*     type="string",
*     description="Text of Services Provided"
*   ),
*   @SWG\Property(
*     property="onlineOrderingUrl",
*     type="string",
*     description="online Ordering Url of a solution"
*   ),
*   @SWG\Property(
*     property="pocInfo",
*     type="string",
*     description="POC Info of a solution"
*   ),
*   @SWG\Property(
*     property="minOrderQty",
*     type="string",
*     description="Minimum Order Quantity of a solution"
*   ),
*   @SWG\Property(
*     property="additionalAvailabilityInfo",
*     type="string",
*     description="Additional Availability Information of a solution"
*   ),
*   @SWG\Property(
*     property="availableTo",
*     type="string",
*     description="Name of organization"
*   ),
*   @SWG\Property(
*     property="contractUrl",
*     type="string",
*     description="Contract Url of a solution"
*   ),
*   @SWG\Property(
*     property="pricesPaidUrl",
*     type="string",
*     description="prices Paid Url of a solution"
*   )
* )
*
* @SWG\Definition(
*   definition="servicesprovided",
*   @SWG\Property(
*     property="text",
*     type="string",
*     description="Text for services Provided"
*   ),
*   @SWG\Property(
*     property="offerings",
*     type="string",
*     description="Offerings information for services Provided"
*   )
* )
*/

/**
 * Get a list of entities.
 *
 * @return array
 *   Array of entities, as passed to RestfulEntityBase::viewEntity().
 *
 * @throws RestfulBadRequestException
 *
 * @SWG\Path(
 *   path="/contractsolutions",
 *   @SWG\Get(
 *     tags={"contractsolutions"},
 *     summary="Retrieve all Contract Solutions",
 *     @SWG\Response(
 *       response=200,
 *       description="Lists all Contract Solutions",
 *       @SWG\Schema(
 *         type="array",
 *           @SWG\Items(ref="#/definitions/ContractSolutions")
 *       )
 *     )
 *   )
 * )
 *
 */

function contract_solutions_solution_matrix() {
  // make sure we have a logged in user
  is_user_anonymous();
  // set database to solution matrix
  db_set_active('solution_matrix');

  // declare global user
  global $user;

  // dynamically create sql statement

  $sql = "SELECT cs.pkContractSolutionId AS id, cs.fkManagingOrganizationId AS managingAgency, o.shortName AS managingAgencyShortName, cs.fkFundingOrganizationId, cs.name, GROUP_CONCAT(DISTINCT cspc.fkProductCategoryId) AS categories, GROUP_CONCAT(DISTINCT st.name) AS type, cs.shortName, cs.expiration, cs.expirationNote, cs.description, cs.feeInfo, cs.availableToId, cs.termsAndConditions, cs.uncontrolledProductList, cs.servicesProvidedEncoded as servicesProvided, cs.servicesProvided as servicesProvidedText, cs.onlineOrderingUrl, cs.pocInfo, cs.minOrderQty, cs.additionalAvailabilityInfo, o.name AS managingAgency, a.name AS availableTo";

  if(array_search('Public User', $user->roles) === false) $sql .=", cs.contractUrl, cs.pricesPaidUrl";


  $sql .= " FROM tbContractSolutions cs
          LEFT JOIN tbOrganizations o ON cs.fkManagingOrganizationId = o.pkOrganizationId
          LEFT JOIN tbAvailableToOptions a ON cs.availableToId = a.pkOptionId
          LEFT JOIN tbContractSolutionToSolutionType csst ON cs.pkContractSolutionId = csst.fkContractSolutionId
          LEFT JOIN tbSolutionTypes st ON csst.fkSolutionTypeId = st.pkSolutionTypeId
          LEFT JOIN tbContractSolutionToProductCategory cspc ON cs.pkContractSolutionId = cspc.fkContractSolutionId
          LEFT JOIN tbProductCategories pc ON cspc.fkProductCategoryId = pc.pkProductCategoryId
          WHERE cs.published=1";

  if(array_search('Public User', $user->roles)) $sql .=" AND public=1";

  $sql .= " GROUP BY cs.pkContractSolutionId";

  // run query
  $result = db_query($sql);

  // fetch all results
  $results = $result->fetchAll();

  // if type is more than one, split type into types array
  foreach ($results as &$row) {
    $row->type = explode(',', $row->type);
    $row->categories = explode(',', $row->categories);
    $row->servicesProvided = unserialize($row->servicesProvided);
  }

  // set database back to drupal default
  db_set_active();

  // return results array
  return $results;
}
