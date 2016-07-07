<?php

class RestfulTasksResource extends \AGProjectCenterDbQueryBase {
 	/**
  	* Overrides \RestfulDataProviderDbQuery::publicFieldsInfo().
	* @SWG\Definition(
	* 	definition="Task",
	* @SWG\Property(
	*   property="id",
	*   type="integer",
	*   description="Task id"
	* ),
	* @SWG\Property(
	* 	property="name",
	* 	type="string",
	* 	 description="Task name"
	*   ),
	* @SWG\Property(
	*     property="uid",
	*     type="integer",
	*     description="ID of currently logged in user"
	*   ),
	* @SWG\Property(
	*     property="created",
	*     type="integer",
	*     description="Timestamp of when the user task was created"
	*   ),
	* @SWG\Property(
	*     property="changed",
	*     type="integer",
	*     description="Timestamp of when the user task was changed"
	*   ),
	* @SWG\Property(
	*     property="status",
	*     type="integer",
	*     description="User created task status"
	*	),
	* @SWG\Property(
	*	    property="due",
	*	    type="integer",
	*	    description="Task due date"
	*		),
	* @SWG\Property(
	*	    property="completed",
	*	    type="integer",
	*	    description="Task stauts"
	*		),
	* @SWG\Property(
	*	    property="prid",
	*	    type="string",
	*	    description="Refrence id to project from task"
	*		),
	* @SWG\Property(
	*	    property="projectId",
	*	    type="string",
	*	    description="Project this task belongs to"
	*		),
	* @SWG\Property(
	*     property="projectName",
	*     type="string",
	*     description="Project name"
	* 	),
	*  @SWG\Property(
	*     property="projectStatus",
	*     type="string",
	*     description="Project status"
	* 	),
	* )
  */
	public function publicFieldsInfo() {
	$public_fields = parent::publicFieldsInfo();
    $intFormatter = array( array($this, 'intval') );

    $public_fields['due'] = array(
      'property' => 'due_date',
      'process_callbacks' => $intFormatter,
    );

    $public_fields['completed'] = array(
      'property' => 'completed',
    );
    $public_fields['prid'] = array(
      'property' => 'prid'
    );
	$public_fields['projectId'] = array(
		'property' => 'projectId'
	);
	$public_fields['projectName'] = array(
		'property' => 'projectName'
	);

	$public_fields['projectStatus'] = array(
		'property' => 'projectStatus'
	);
		return $public_fields;
	}

	/**
	* @Override
	* Get a basic query object.
	*
	* @return SelectQuery
	*   A new SelectQuery object for this connection.
	*
	* Join with the Projects table.
	*
	*  @SWG\Path(
	*    path="/tasks",
	*    @SWG\Get(
	*      tags={"Tasks"},
	*      summary="Returns Tasks list",
	*      @SWG\Response(
	*        response=200,
	*        description="List of Project Center Tasks",
	*        @SWG\Schema(
	*          type="object",
	*           @SWG\Property(
	*            property="data",
	*            type="array",
	*            @SWG\Items(
	*            ref="#/definitions/Task"
	*            )
	*          )
	*        )
	*      )
	*    )
	* ),
	*/

	/**
	*
	*  @SWG\Path(
	*    path="/tasks/{id}",
	*     @SWG\Get(
	*     tags={"Tasks"},
	*     summary="Finds Task by Id",
	*     @SWG\Parameter(
    *      name="id",
    *      description="The Id that needs to be fetched. Use 8 for testing.",
    *      in="path",
    *      required=true,
    *      type="string",
    *      @SWG\Schema(ref="#/definitions/Task"),
    *     ),
    *     @SWG\Response(
	*     response=400,
	*     description="Invalid ID supplied"
	*     ),
	*    @SWG\Response(
	*     response=404,
	*     description="Task not found"
	*     ) 
	*   )
	* )
	*/
	
	/**
	* @SWG\Path(
	* path="/tasks/{id}",
	*  @SWG\Delete(
	*    tags={"Tasks"},
	*    summary="Delete Task using ID",
	*    description="This can only be done if current UID matches task UID",
	*    @SWG\Parameter(
    *      name="id",
    *      description="ID of the Task that needs to be deleted",
    *      in="path",
    *      required=true,
    *      type="string",
    *     ),
	*    @SWG\Response(
	*     response=400,
	*     description="Invalid ID supplied"
	*     ),
	*    @SWG\Parameter(
	*     name="key",
	*     in="header",
	*     description="",
	*     required=true,
	*     type="string"
    *     ),
	*    @SWG\Response(
	*     response=403,
	*     description="Access denied"
	*     ),
	*    @SWG\Response(
	*     response=404,
	*     description="Task not found"
	*     )    
	*   )
	*  )
	*/

  /**
    * Submits a new search term for entry into the suggestions list
    * @SWG\Path(
    *   path="/tasks",
    *   @SWG\Post(
    *     tags={"Tasks"},
    *     operationId="addPet",
    *     summary="Created new Task object",
    *     description="This can only be done if current UID matches task UID",
    *     consumes={"application/json"},
    *     produces={"application/json"},
    *     @SWG\Parameter(
    *       name="task",
    *       type="string",
    *       in="path",
    *       description="Task object to be added ",
    *       @SWG\Schema(ref="#/definitions/Task"),
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
    * Submits a new search term for entry into the suggestions list
    * @SWG\Path(
    *   path="/tasks",
    *   @SWG\Put(
    *     tags={"Tasks"},
    *     operationId="updateTask",
    *     summary="Update an existing task",
    *     description="This can only be done if current UID matches task UID",
    *     consumes={"application/json"},
    *     produces={"application/json"},
    *     @SWG\Parameter(
    *       name="name",
    *        in="name",
    *       type="string",
    *       in="formData",
    *       required=false,
    *       description="Updated task name",
    *       @SWG\Schema(ref="#/definitions/Task"),
    *     ),
    *     @SWG\Parameter(
    *       name="due",
    *        in="due",
    *       type="integer",
    *       in="formData",
    *       required=false,
    *       description="Updated task due date",
    *     ),
    *     @SWG\Parameter(
    *         name="key",
    *         in="header",
    *         description="",
    *         required=true,
    *         type="string"
    *     ),
    *      @SWG\Response(
    *         response=400,
    *         description="Invalid ID supplied",
    *     ),
    *     @SWG\Response(
    *         response=404,
    *         description="Task not found",
    *     ),
    *     @SWG\Response(
    *         response=405,
    *         description="Validation exception",
    *     ),
    *     @SWG\Response(
    *       response=200,
    *       description="Acknowleges Task was successfully added to list"
    *     ),
    *     security={
     *       {"auth": {"write:task", "read:task"}}
     *     }
    *   )
    * )
    */
	 protected function getQuery() {
		 $query = parent::getQuery();

		 $query->leftJoin('gateway_project_entity_reference', 'gper', "gper.type = 'Task' AND gateway_task.id = gper.entity_id AND gateway_task.uid = gper.uid");
	   $query->leftJoin('gateway_project', 'project', 'gper.pid = project.id AND gateway_task.uid = project.uid');
     $query->addField('gper', 'id', 'prid');
		 $query->addField('project', 'id', 'projectId');
		 $query->addField('project', 'name', 'projectName');
		 $query->addField('project', 'status', 'projectStatus');

		 return $query;
	 }
}