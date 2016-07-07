<?php 
  

class RestfulProjectsResource extends \AGProjectCenterDbQueryBase {
  /**
  * Overrides RestfulHelpResource::publicFieldsInfo().
  * 
  *
  * @SWG\Definition(
  *   definition="projects",
  *   @SWG\Property(
  *     property="id",
  *     type="string",
  *     description="id of a specific project"
  *   ),
  *   @SWG\Property(
  *     property="name",
  *     type="string",
  *     description="Name of the project created"
  *   ),
  *   @SWG\Property(
  *     property="uid",
  *     type="string",
  *     description="User id of the user that created the project"
  *   ),
  *   @SWG\Property(
  *     property="created",
  *     type="integer",
  *     description="Timestamp of project creation"
  *   ), 
  *   @SWG\Property(
  *     property="changed",
  *     type="integer",
  *     description="Timestamp of project changed"
  *   ),
  *   @SWG\Property(
  *     property="status",
  *     type="string",
  *     description="Status of the project"
  *   ),
  *   @SWG\Property(
  *     property="description",
  *     type="string",
  *     description="The description of the project"
  *   ),
  *   @SWG\Property(
  *     property="notes",
  *     type="string",
  *     description="A note on the project"
  *   ), 
  *   @SWG\Property(
  *     property="due",
  *     type="integer",
  *     description="Timestamp of project due time"
  *   ), 
  * )
  *
  */
	
	public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
		
    $intFormatter = array( array($this, 'intval') );

    $public_fields['description'] = array(
      'property' => 'description',
    );

    $public_fields['notes'] = array(
      'property' => 'notes',
    );

    $public_fields['due'] = array(
      'property' => 'due',
      'process_callbacks' => $intFormatter
    );
  /**
   *
   * @SWG\Path(
   *   path="/projects/",
   *   @SWG\Get(
   *     tags={"projects"},
   *     summary="Performs a list of projects and timestamps of the specific project creatio, changes and due times",
   *     @SWG\Response(
   *       response=200,
   *       description="list of projects",
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
