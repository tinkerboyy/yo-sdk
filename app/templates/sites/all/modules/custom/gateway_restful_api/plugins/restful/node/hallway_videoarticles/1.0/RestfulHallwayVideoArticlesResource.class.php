<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulHallwayVideoArticlesResource extends AGRestfulEntityBase {
  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
    /**
   *     @SWG\Definition(
   *        definition="hallwayvideoarticles",
   *         @SWG\Property(
   *             property="id",
   *             type="integer",
   *             description="Hallway Videoarticles Id"
   *         ),
   *         @SWG\Property(
   *             property="label",
   *             type="string",
   *             description="label text of Hallway Videoarticles"
   *         ),
   *         @SWG\Property(
   *             property="views",
   *             type="string",
   *             description="node views"
   *         ),
   *        @SWG\Property(
   *          property="author",
   *          type="object",
   *          ref="#/definitions/author",
   *          description="User details for currently logged in user",
   *        ), 
   *        @SWG\Property(
   *          property="videoarticlevideoembed",
   *          type="object",
   *          ref="#/definitions/videoarticlevideoembed",
   *          description="videoarticlevideoembed object",
   *        ), 
   *         @SWG\Property(
   *             property="status",
   *             type="integer",
   *              description="node status"
   *         ),
   *         @SWG\Property(
   *             property="newtagexpiration",
   *             type="integer",
   *              description="node newtagexpiration date"
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
   *          property="portfoliocategory",
   *          type="array",
   *          @SWG\Items(ref="#/definitions/portfoliocategory")
   *           ),
   *         @SWG\Property(
   *          property="portfoliohallway",
   *          type="array",
   *          @SWG\Items(ref="#/definitions/portfoliohallway")
   *      ),
   *      @SWG\Property(
   *          property="interaction",
   *          type="array",
   *          @SWG\Items(ref="#/definitions/interaction")
   *      ),
   *       @SWG\Property(
   *         property="shortdescription",
   *         type="string",
   *         description="description"
   *      ),
   *       @SWG\Property(
   *         property="image",
   *         type="object",
   *         description="user image"
   *      ),
   *     )
   *
   *   @SWG\Definition(
   *      definition="videoarticlevideoembed",
   *         @SWG\Property(
   *             property="video_url",
   *             type="string",
   *             description="video url"
   *         ),
   *         @SWG\Property(
   *             property="thumbnail_path",
   *             type="string",
   *             description="thumbnail path"
   *         ),
   *       @SWG\Property(
   *             property="video_data",
   *             type="string",
   *             description="video_data object"
   *         ),
   *      @SWG\Property(
   *             property="embed_code",
   *             type="string",
   *             description="embed code"
   *         ),
   *       @SWG\Property(
   *             property="description",
   *             type="string",
   *             description="description"
   *         ),
   *     ),
   *  )
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $intFormatter = array( $this, 'intval' );


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
    );

    $public_fields['shortdescription'] = array(
      'property' => 'field_short_description',
      'full_view' => TRUE,
    );

    $public_fields['image'] = array(
      'property' => 'field_image',
      'process_callbacks' => array(array($this, 'getImageUrl'))
    );  

    $public_fields['videoarticlevideoembed'] = array(
      'property' => 'field_video_embed',
      'full_view' => TRUE,
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

    $public_fields['summary'] = array(
      'sub_property' => 'summary',
      'sub_property' => 'summary',
      'property' => 'body',
    );

    $public_fields['views'] = array(
      'property' => 'day_views',
    ); 
    return $public_fields;
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
     *    path="/hallway-videoarticles/",
     *   @SWG\Get(
     *     tags={"Hallway Videoarticles"},
     *     summary="Retrieves list of Hallway Video Articles",
     *     @SWG\Response(
     *       response=200,
     *       description="list of Hallway Video Articles",
     *       @SWG\Schema(
     *         type="array",
     *         ref="#/definitions/hallwayvideoarticles"
     *       )
     *     )
     *   )
     * )
     * */
     /**
     * @SWG\Path(
     *   path="/hallway-videoarticles/{id}",
     *   @SWG\Get(
     *     tags={"Hallway Videoarticles"},
     *     summary="Retrieve a single Hallway Video Articles",
     *     @SWG\Parameter(
     *       name="id",
     *       description="ID of Hallway Video Articles",
     *       in="path",
     *       required=true,
     *       type="integer"
     *     ),
     *     @SWG\Response(
     *       response=200,
     *       description="Hallway Videoarticles",
     *       @SWG\Schema(
     *         type="object",
     *         ref="#/definitions/hallwayvideoarticles"
     *       )
     *     )
     *   )
     * )
     * */
}