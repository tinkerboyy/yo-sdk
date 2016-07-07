<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

/**
 * 
 * 
 */
class RestfulCertificationsResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {
  /**
   * @SWG\Definition(
   *   definition="certifications",
   *   @SWG\Property(
   *      property="id",
   *      type="integer",
   *      description="Users Certification Id "
   *   ),
   *    @SWG\Property(
   *       property="name",
   *       type="string",
   *       description="Users Certification name "
   *    )
   * )
   * 
   */
  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'id',
    );

    $public_fields['name'] = array(
      'property' => 'name',
    );
    return $public_fields;
  }
    /**
   * @SWG\Get(
   *   path="/products",
   *   summary="list products",
   *   @SWG\Response(
   *     response=200,
   *     description="A list with products"
   *   ),
   *   @SWG\Response(
   *     response="default",
   *     description="an ""unexpected"" error"
   *   )
   * )
   */
  /**
   * 
   *  @SWG\Path(
   *    path="/certifications",
   *    @SWG\Get(
   *      tags={"certifications"},
   *      summary="Retrieves list of certifications",
   *        @SWG\Response(
   *          response=200,
   *           description="List of certifications",
   *            @SWG\Schema(
   *            type="object",
   *               @SWG\Property(
   *                 property="data",
   *                 type="array",
   *                    @SWG\Items(
   *                      ref="#/definitions/certifications"
   *                  )
   *               )
   *            )
   *        )
   *    ),
   *  )
   */
  /**
    * Submits a new certifications for entry
    * @SWG\Path(
    *   path="/certifications",
    *   @SWG\Post(
    *     tags={"certifications"},
    *     operationId="",
    *     summary="Created new Certification object",
    *     description="Certification to add",
    *     consumes={"application/json"},
    *     produces={"application/json"},
    *     @SWG\Parameter(
    *       name="certification",
    *       type="string",
    *       in="path",
    *       description="Certification to add",
    *       @SWG\Schema(
    *         ref="#/definitions/certifications"
    *       ),
    *     ),
    *     @SWG\Parameter(
    *         name="key",
    *         in="header",
    *         description="",
    *         required=true,
    *         type="string"
    *     ),
    *     @SWG\Response(
    *       response=405,
    *       description="Invalid input",
    *     )
    *   )
    * )
    */
  
  /**
   * {@inheritdoc}
   */
  public function create() {
  	
    $request = $this->getRequest();
    static::cleanRequest($request);
   
    //Check if 'name ' already esixt;
    if (!empty($request['name'])) {
      $results = db_select('ag_certifications', 'ac')
        ->fields('ac', array())
        ->condition('name', $request['name'])
        ->execute()
        ->fetchAll();

      //If the term is not found, add it to the search logs
      if(count($results) === 0) {
        $result = db_insert('ag_certifications')
          ->fields(
            array(
              name => $request['name'],
            )
          )
          ->execute();
        
        $results = array(array( 'id' => $result,  'name' => $request['name'] ));

      }
    }

    return $results;
  }
}
