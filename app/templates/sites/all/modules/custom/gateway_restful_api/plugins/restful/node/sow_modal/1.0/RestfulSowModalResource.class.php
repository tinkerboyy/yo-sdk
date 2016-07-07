<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulSowModalResource extends AGRestfulEntityBaseNode {
  /**
   * Overrides RestfulHelpResource::publicFieldsInfo().
  * 
  *
  * @SWG\Definition(
  *   definition="Sow-modal",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="id of the modal content been displayed"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Title of the modal content"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="The URL of the specific content been displayed"
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="string",
  *     description="Main content of the modal window"
  *   ), 
  * )
  *
  */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function create() {
    $this->notImplementedCrudOperation(__FUNCTION__);
  }

  /**
   * {@inheritdoc}
   */
  public function update($ids, $full_replace = FALSE) {
    $this->notImplementedCrudOperation(__FUNCTION__);
  }
  /**
   *
   * @SWG\Path(
   *   path="/sow-modal/",
   *   @SWG\Get(
   *     tags={"sow-modal"},
   *     summary="Performs a display of sow-modal content",
   *     @SWG\Response(
   *       response=200,
   *       description="Displays content of sow-modal content",
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
  /**
   * {@inheritdoc}
   */
  public function remove($id) {
    $this->notImplementedCrudOperation(__FUNCTION__);
  }
}
