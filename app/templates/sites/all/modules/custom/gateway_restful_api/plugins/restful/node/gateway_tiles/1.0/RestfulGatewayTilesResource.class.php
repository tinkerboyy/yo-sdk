<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulGatewayTilesResource extends AGRestfulEntityBaseNode {

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
  *
  *  @SWG\Definition(
  *    definition="gatewayimage",
  *   @SWG\Property(
  *      property="fid",
  *      type="string",
  *      description="username"
  *    ),
  *    @SWG\Property(
  *      property="uid",
  *      type="string",
  *      description="Drupal User's id"
  *    ),
  *    @SWG\Property(
  *      property="filename",
  *      type="string",
  *      description="Filename of the image"
  *    ),
  *    @SWG\Property(
  *      property="uri",
  *      type="string",
  *      description="Timestamp of when the user was created"
  *    ),
  *    @SWG\Property(
  *      property="filemime",
  *      type="string",
  *      description="Mime type of image"
  *    ),
  *    @SWG\Property(
  *      property="filesize",
  *      type="string",
  *      description="Filesize of the image"
  *    ),
  *    @SWG\Property(
  *      property="status",
  *      type="string",
  *      description="Status of the image"
  *    ),
  *    @SWG\Property(
  *      property="timestamp",
  *      type="string",
  *      description="Timestamp of when the image was created"
  *    ),
  *    @SWG\Property(
  *      property="origname",
  *      type="string",
  *      description="original name of the image"
  *    ),
  *    @SWG\Property(
  *      property="type",
  *      type="object",
  *      description="Type of medium"
  *    ),
  *    @SWG\Property(
  *      property="uuid",
  *      type="string",
  *      description="Drupals's uuid for the image"
  *    ),
  *    @SWG\Property(
  *      property="rdf_mapping",
  *      type="array",
  *      description="",
  *      @SWG\Items(
  *        type="string"
  *      )
  *    ),
  *    @SWG\Property(
  *      property="image_dimensions",
  *      type="object",
  *      description="Displays dimension of the image"
  *    ),
  *    @SWG\Property(
  *      property="alt",
  *      type="string",
  *      description="Displays alternative text for image"
  *    ),
  *    @SWG\Property(
  *      property="title",
  *      type="string",
  *      description="Displays the title of the image"
  *    ),
  *    @SWG\Property(
  *      property="width",
  *      type="string",
  *      description="The width of the image"
  *    ),
  *    @SWG\Property(
  *      property="height",
  *      type="string",
  *      description="The height of the image"
  *    ),
  *   )
  *
  * @SWG\Definition(
  *   definition="gateway-tiles",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="Id of the gateway tile"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Title of the gateway tile"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="Permalink to a specific gateway tile's api"
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="string",
  *     description="Content of the gateway tile"
  *   ),
  *   @SWG\Property(
  *     property="gatewayimage",
  *     type="object",
  *     description="Discription of the gateway image",
  *     ref="#/definitions/gatewayimage"
  *   ),
  *   @SWG\Property(
  *     property="gatewaylink",
  *     type="object",
  *     description="Timestamp of user access to specific node"
  *   ),
  * )
  *
  */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );

    $public_fields['gatewayimage'] = array(
      'property' => 'field_gateway_homepage_image',
      'full_view' => TRUE,
    );

    $public_fields['gatewaylink'] = array(
      'property' => 'field_gateway_homepage_link',
      'full_view' => TRUE,
    );
  /**
   *
   * @SWG\Path(
   *   path="/gateway-tiles/",
   *   @SWG\Get(
   *     tags={"gateway-tiles"},
   *     summary="Performs a list of created gateway tiles",
   *     @SWG\Response(
   *       response=200,
   *       description="List of created gateway tiles",
   *       @SWG\Schema(
   *         type="object",
   *          @SWG\Property(
   *            property="data",
   *            type="array",
   *            @SWG\Items(ref="#/definitions/gateway-tiles")
   *          )
   *       )
   *     )
  *   )
  * )
  */

    return $public_fields;
  }
}
