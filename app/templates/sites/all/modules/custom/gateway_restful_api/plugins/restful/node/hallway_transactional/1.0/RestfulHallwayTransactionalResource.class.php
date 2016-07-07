<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulHallwayTransactionalResource extends AGRestfulEntityBase {
  /**
  * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
  *
  * @SWG\Definition(
  *   definition="hallway-transactional",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="Id of user"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Display name of the transaction"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="Permalink to a specific transaction's api"
  *   ),
  *   @SWG\Property(
  *     property="author",
  *     type="object",
  *     description="Discription of author of a specific transaction"
  *   ),
  *   @SWG\Property(
  *     property="uid",
  *     type="string",
  *     description="Drupal user id"
  *   ),
  *   @SWG\Property(
  *     property="status",
  *     type="string",
  *     description="Status of a specfic transaction"
  *   ),
  *   @SWG\Property(
  *     property="tranurl",
  *     type="object",
  *     description="Permalink to a specific transaction"
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="string",
  *     description="Content of the transaction"
  *   ),
  *   @SWG\Property(
  *     property="url",
  *     type="string",
  *     description="Url to the hallways transaction"
  *   ),
  * )
  *
  */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    
    $public_fields['tranurl'] = array(
      'property' => 'field_transactional_url',
      'full_view' => TRUE,
    );

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );

    $public_fields['url'] = array(
      'property' => 'url',
      'full_view' => TRUE,
    );

  /**
   *
   * @SWG\Path(
   *   path="/hallway-transactional/",
   *   @SWG\Get(
   *     tags={"hallway-transactional"},
   *     summary="Performs a list of hallway transactions",
   *     @SWG\Response(
   *       response=200,
   *       description="List of hallway transactions",
   *       @SWG\Schema(
   *         type="object",
   *          @SWG\Property(
   *            property="data",
   *            type="array",
   *          )
   *       )
   *     )
   *   )
   * )
   */
    
    return $public_fields;
  }
}