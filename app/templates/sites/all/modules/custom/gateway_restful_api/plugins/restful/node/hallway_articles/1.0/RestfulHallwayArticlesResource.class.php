<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulHallwayArticlesResource extends AGRestfulEntityBase {
  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
  /**
   *     @SWG\Definition(
   *        definition="hallwayArticles",
   *         @SWG\Property(
   *             property="id",
   *             type="integer",
   *             description="Hallway Articles id"
   *         ),
   *         @SWG\Property(
   *             property="expired",
   *             type="boolean",
   *             description="Check on expiration of articles"
   *         ),
   *         @SWG\Property(
   *             property="since_modified",
   *             type="integer",
   *             description="Timestamp since modified"
   *         ),
   *         @SWG\Property(
   *             property="label",
   *             type="string",
   *             description="label text of Hallway Articles"
   *         ),
   *         @SWG\Property(
   *             property="self",
   *             type="string",
   *             description="Url of hallway Article api"
   *         ),
   *        @SWG\Property(
   *          property="author",
   *          type="object",
   *          ref="#/definitions/author",
   *          description="User details for currently logged in user",
   *        ), 
   *         @SWG\Property(
   *             property="uid",
   *             type="integer",
   *             description="Drupal user id"
   *         ),
   *         @SWG\Property(
   *             property="status",
   *             type="integer",
   *             description="node status"
   *         ),
   *         @SWG\Property(
   *             property="created",
   *             type="integer",
   *             description="node Public/Private status"
   *         ),
   *         @SWG\Property(
   *             property="url",
   *             type="integer",
   *             description="node newtagexpiration date"
   *         ),
   *         @SWG\Property(
   *             property="weight",
   *             type="integer",
   *             description="node weight"
   *         ),
   *         @SWG\Property(
   *             property="expiration",
   *             type="integer",
   *             description="node expiration date"
   *         ),
   *         @SWG\Property(
   *             property="body ",
   *             type="string",
   *             description="Node body"
   *         ),
   *       @SWG\Property(
   *          property="portfoliocategory",
   *          type="array",
   *          @SWG\Items(ref="#/definitions/portfoliocategory")
   *      ),
   *     @SWG\Property(
   *          property="portfoliohallway",
   *          type="array",
   *          @SWG\Items(ref="#/definitions/portfoliohallway")
   *      ),
   *    @SWG\Property(
   *          property="interaction",
   *          type="array",
   *          @SWG\Items(ref="#/definitions/interaction")
   *      ),
   *     @SWG\Property(
   *         property="shortdescription",
   *         type="string",
   *         description="description"
   *      ),
   *     @SWG\Property(
   *         property="image",
   *         type="object",
   *         description="user image"
   *      ),
   *     ),
   *  )
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    $intFormatter = array( $this, 'intval' );
    
    $public_fields['expired'] = array(
      'callback' => array($this, 'expired')
    );

    $public_fields['since_modified'] = array(
      'callback' => array($this, 'since_modified')
    ); 
   
    $public_fields['created'] = array(
      'property' => 'created',
      'process_callbacks' => array($intFormatter)
    );

    $public_fields['changed'] = array(
      'property' => 'changed',
      'full_view' => TRUE,
    );

    $public_fields['url'] = array(
      'property' => 'url',
      'full_view' => TRUE,
    );

    $public_fields['portfoliocategory'] = array(
      'property' => 'field_portfolio_category',
      'full_view' => TRUE,
    );

     $public_fields['portfoliohallway'] = array(
      'property' => 'field_portfolio_category',
      'sub_property' => 'tid',
      'full_view' => TRUE,
    );

    $public_fields['shortdescription'] = array(
      'property' => 'field_short_description',
      'full_view' => TRUE,
    );

    $public_fields['image'] = array(
      'property' => 'field_image',
      'process_callbacks' => array(array($this, 'getImageUrl'))
    );  

    $public_fields['interaction'] = array(
      'property' => 'field_interaction_mode',
      'full_view' => TRUE,
    );

    $public_fields['expiration'] = array(
      'property' => 'field_expiration_date',
      'full_view' => TRUE,
    );

    $public_fields['newtagexpiration'] = array(
      'property' => 'field_new_tag_expiration_date_1',
      'full_view' => TRUE,
    );

    $public_fields['weight'] = array(
      'callback' => array($this, 'draggableWeight')
    );

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );

    $public_fields['views'] = array(
      'property' => 'day_views',
    ); 

    $public_fields['Public'] = array(
      'property' => 'field_public_private',
    ); 

    return $public_fields;
  }


  /**
    * Overrides parent getList to add sorting of returned data
    * @return [array] - Articles Sorted by weight, date
    */
  public function getList() {
    $return = parent::getList();
    //Sort results
    # get a list of sort columns and their data to pass to array_multisort
    $sort = array();
    foreach($return as $k=>$v) {
        $sort['weight'][$k] = $v['weight'];
        $sort['created'][$k] = $v['created'];
    }
    # sort by WEIGHT asc, then CREATED desc
    array_multisort($sort['weight'], SORT_ASC, $sort['created'], SORT_DESC,$return);
 

    return $return;
  }

  protected function getImageUrl($image) {
    if (!$image) return null;
	if ($image[0])$image = $image[0]; 
    return array( 
      'uri' => file_create_url($image['uri']),
      'filename' => $image['filename'],
      'origname' => $image['origname'],
      'title' => $image['title'],
      'alt' => $image['alt'],
      'height' => $image['height'],
      'width' => $image['width']
    ); 
  }
    
     /**
     * @SWG\Path(
     *   path="/hallway-articles",
     *   @SWG\Get(
     *     tags={"Hallway Articles"},
     *     summary="Retrieves list of Hallway Articles",
     *     @SWG\Response(
     *       response=200,
     *       description="list of Hallway Articles",
     *       @SWG\Schema(
     *         type="array",
     *         ref="#/definitions/hallwayArticles"
     *       )
     *     )
     *   )
     * )
     * */
     /**
     * @SWG\Path(
     *   path="/hallway-articles/{id}",
     *   @SWG\Get(
     *     tags={"Hallway Articles"},
     *     summary="Retrieve a single Hallway Article",
     *     @SWG\Parameter(
     *       name="id",
     *       description="ID ofhallwayArticles",
     *       in="path",
     *       required=true,
     *       type="integer"
     *     ),
     *     @SWG\Response(
     *       response=200,
     *       description="hallway Articles",
     *       @SWG\Schema(
     *         type="object",
     *         ref="#/definitions/hallwayArticles"
     *       )
     *     )
     *   )
     * )
     * */
}

