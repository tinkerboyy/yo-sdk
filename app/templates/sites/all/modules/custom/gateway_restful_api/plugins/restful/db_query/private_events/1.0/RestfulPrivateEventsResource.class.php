<?php

	class RestfulPrivateEventsResource extends \AGProjectCenterDbQueryBase {

		public function publicFieldsInfo() {
			$public_fields = parent::publicFieldsInfo();
	    $intFormatter = array( array($this, 'intval') );

	   	$public_fields['name'] = array(
	      'property' => 'name'
	    );

	    $public_fields['start_date'] = array(
	      'property' => 'start_date',
        'process_callbacks' => $intFormatter,
	    );

	    $public_fields['end_date'] = array(
	      'property' => 'end_date',
        'process_callbacks' => $intFormatter,
	    );

	    $public_fields['location'] = array(
	      'property' => 'location'
	    );

	    $public_fields['description'] = array(
	      'property' => 'description'
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
			*/
		 protected function getQuery() {
			 $query = parent::getQuery();

			 $query->leftJoin('gateway_project_entity_reference', 'gper', "gper.type = 'Event' AND gateway_event.id = gper.entity_id AND gateway_event.uid = gper.uid");
			 $query->leftJoin('gateway_project', 'project', 'gper.pid = project.id AND gateway_event.uid = project.uid');
	     $query->addField('gper', 'id', 'prid');
			 $query->addField('project', 'id', 'projectId');
			 $query->addField('project', 'name', 'projectName');
			 $query->addField('project', 'status', 'projectStatus');


			 return $query;
		 }
	}
