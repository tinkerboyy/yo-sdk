<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulFootersResource extends AGRestfulEntityBaseNode {
  /**
   * Overrides RestfulFootersResource::publicFieldsInfo().
   */

   /**
    * Overrides \RestfulEntityBase::publicFieldsInfo().
   @SWG\Definition(
     definition="Footer",
     @SWG\Property(
       property="id",
       type="integer",
       description="ID of footer label"
     ),
     @SWG\Property(
       property="label",
       type="string",
       description="Display name of footer"
     ),
     @SWG\Property(
       property="self",
       type="string",
       description="permalink to the currently shown up footer label"
     ),
     @SWG\Property(
       property="body",
       type="string",
       description="Body Description of footer label with HTML tags",
     ),
     @SWG\Property(
       property="description",
       type="string",
       description="Header Description of footer label",
     ),
     @SWG\Property(
       property="status",
       type="string",
       description="Status of enable/disable",
     ),
     @SWG\Property(
       property="public",
       type="string",
       description="Whether its accessible to public user ot not",
     ),
   )
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
   *   path="/footers",
   *   @SWG\Get(
   *     tags={"Footer"},
   *     summary="Returns all available Footer Labels",
   *     @SWG\Response(
   *       response=200,
   *       description="List of Footer Labels",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Footer")
   *         )
   *       )
   *     )
   *   ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of Footer Labels",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Footer")
   *         )
   *       )
   *     )
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

    $public_fields['description'] = array(
      'property' => 'field_cms_footer_description',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );

    $public_fields['status'] = array(
      'property' => 'status',
    );

    $public_fields['public'] = array(
      'property' => 'field_public_private',
    );

    return $public_fields;
  }
}
