<?php

class RestfulProjectEntity extends \AGProjectCenterDbQueryBase {

	/**
	*
	* @SWG\Definition(
	*   definition="ProjectsEntity",
	*   @SWG\Property(
	*     property="id",
	*     type="integer",
	*     description="ID of the Project entity"
	*   ),
	*   @SWG\Property(
	*     property="name",
	*     type="string",
	*     description="Name of the Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="uid",
	*     type="integer",
	*     description="User id of the Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="created",
	*     type="integer",
	*     description="Created date of Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="changed",
	*     type="integer",
	*     description="changed date of Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="status",
	*     type="boolean",
	*     description="Status of Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="pid",
	*     type="integer",
	*     description="Process Id of Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="entity_id",
	*     type="integer",
	*     description="Entity id of Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="type",
	*     type="string",
	*     description="Type of Content added for the Project Entity"
	*   ),
	*   @SWG\Property(
	*     property="data",
	*     type="string",
	*     description="Content type URL added for the Project"
	*   ),
	*   @SWG\Property(
	*     property="count",
	*     type="integer",
	*     description="count/number of Projects avialable"
	*   ),
	*   @SWG\Property(
	* 	  property="self",
	* 	  type="string",
	* 	  description="Self Url of User"
	* 	),
	* )
	*
	*/

	public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['pid'] = array(
      'property' => 'pid',
    );

    $public_fields['entity_id'] = array(
      'property' => 'entity_id',
    );

    $public_fields['type'] = array(
      'property' => 'type',
    );

    $public_fields['data'] = array(
      'property' => 'data',
    );

		return $public_fields;
	}

	 /**
   * @SWG\Path(
   *   path="/projectsentity/",
   *   @SWG\Get(
   *     tags={"projectsentity"},
   *     summary="List of project entities",
   *     @SWG\Response(
   *       response=200,
   *       description="List of project entities",
   *       @SWG\Schema(
   *         type="object",
   *          @SWG\Property(
   *            property="data",
   *            type="array",
   *            @SWG\Items(ref="#/definitions/ProjectsEntity")
   *          )
   *       )
   *     )
   *   )
   * )
   **/

  public function create() {
    $request = $this->getRequest();
    static::cleanRequest($request);
    $save = FALSE;

    $public_fields = $this->getPublicFields();
    $id_columns = $this->getIdColumn();

    $record = array(
      'uid' => $this->getAccount()->uid,
      'created' => REQUEST_TIME,
      'updated' => REQUEST_TIME
    );

    foreach ($public_fields as $public_field_name => $info) {
      // Ignore passthrough public fields.
      // If this is the primary field, skip.
      if (!empty($info['create_or_update_passthrough']) || $this->isPrimaryField($info['property'])) {
        continue;
      }

      if (isset($request[$public_field_name])) {
        $record[$info['property']] = $request[$public_field_name];
      }

      $save = TRUE;
    }

    // No request was sent.
    if (!$save) {
      throw new \RestfulBadRequestException('No valid values were sent with the request.');
    }
    // Once the record is built, write it and view it.
    //if (drupal_write_record($this->getTableName(), $record)) {
    //  // Handle multiple id columns.
    //  $id_values = array();
    //  foreach ($id_columns as $id_column) {
    //    $id_values[$id_column] = $record[$id_column];
    //  }
    //  $id = implode(self::COLUMN_IDS_SEPARATOR, $id_values);

    //  return $this->view($id);
    //}
    $results = db_insert('gateway_project_entity_reference')
                ->fields($record)
                ->execute();
    $id = Database::getConnection()->lastInsertId();
    return $id ?  $this->view($id) : false;

  }
}
