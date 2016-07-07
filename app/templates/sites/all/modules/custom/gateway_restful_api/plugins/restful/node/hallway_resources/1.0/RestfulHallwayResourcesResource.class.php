<?php

/**
 * @file
 * Contains RestfulHallwayResourcesResource.
 */

class RestfulHallwayResourcesResource extends AGRestfulEntityBaseNode {

  /**
  *
  * @SWG\Definition(
  *   definition="Resources",
  *   @SWG\Property(
  *     property="id",
  *     type="string",
  *     description="ID of resource"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Title of Resource"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="URL api endpoint"
  *   ),
  *   @SWG\Property(
  *     property="description",
  *     type="string",
  *     description="Resource description"
  *   ),
  *   @SWG\Property(
  *     property="interaction_mode",
  *     type="array",
  *     description="Selection of Learn, Connect, or Act interaction",
        @SWG\Items(
          type="string"
        )
  *   ),
  *   @SWG\Property(
  *     property="link",
  *     type="object",
  *     description="relative url"
  *   ),
  *   @SWG\Property(
  *     property="modal_content",
  *     type="object",
  *     description="modal content"
  *   ),
  *   @SWG\Property(
  *     property="display_locations",
  *     type="object",
  *     description="modal content"
  *   )
  * )
  * @SWG\Definition(
  *   definition="modal_content",
  *   @SWG\Property(
  *     property="title",
  *     type="string",
  *     description="title of modal content"
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="string",
  *     description="body of modal content"
  *   ),
  * ) 
  *
  * @SWG\Definition(
  *   definition="link",
  *   @SWG\Property(
  *     property="url",
  *     type="string",
  *     description="url link of resource"
  *   ),
  *   @SWG\Property(
  *     property="title",
  *     type="string",
  *     description="title of resource"
  *   ),
  *   @SWG\Property(
  *     property="attributes",
  *     type="array",
  *     description="resource link attributes",
        @SWG\Items(
          type="string"
        )
  *   ),
  * ) 
*/

  /**
   * Overrides RestfulFootersResource::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    $public_fields_extend = array(
    	'id' => array( 'property' => 'nid' ),
    	'description' => array(
        'property' => 'body',
        'sub_property' => 'value'
      ),
    	'interaction_mode' => array(
        'property' => 'field_interaction_mode',
        'sub_property' => 'name'
      ),
    	'image' => array(
        'property' => 'field_image',
        'process_callbacks' => array( array( $this, 'processImage' ) ) ),
    	'link' => array( 'property' => 'field_link' ),
      'modal_content' => array(
        'property' => 'field_modal_content',
        'process_callbacks' => array( array( $this, 'processModalContent' ) )
      ),
    	'display_locations' => array(
        'property' => 'field_display_locations',
        'sub_property' => 'name'
      )
    );
    return array_merge($public_fields, $public_fields_extend);
  }

    /**
     * @SWG\Path(
     *   path="/hallway_resources",
     *   @SWG\Get(
     *     tags={"Resources"},
     *     summary="Retrieve all Resources",
     *     @SWG\Parameter(
     *       name="Group",
     *       description="Name of Group",
     *       in="path",
     *       required=false,
     *       type="string"
     *     ),
     *     @SWG\Response(
     *       response=200,
     *       description="List of Resources",
     *       @SWG\Schema(
     *         type="object",
     *         @SWG\Property(
     *           property="data",
     *           type="array",
     *           @SWG\Items(ref="#/definitions/Resources")
     *         )
     *       )
     *     )
     *   )
     * )
     *
     *
     */

  protected function processModalContent($modalContent) {
    return array(
      'title' => $modalContent->title,
      'body' => $modalContent->body['und'][0]['value']
    );
  }

  protected function processImage($image) {
    $newImages = [];
    foreach($image as $value) {
      $newImages[] = array(
        'url' => file_create_url($value['uri']),
        'filename' => $value['filename'],
        'filemime' => $value['filemime'],
        'filesize' => $value['filesize'],
        'type' => $value['type'],
        'alt' => $value['alt'],
        'title' => $value['title'],
        'height' => $value['height'],
        'width' => $value['width']
      );
    }
    return $newImages;
  }

}
