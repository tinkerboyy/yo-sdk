<?php

/**
 * @file
 * Contains RestfulFootersResource.
 */

class RestfulProjectFilesResource extends AGRestfulEntityBase {

  /**
  * 
  * @SWG\Definition(
  *   definition="Project-files",
  *   @SWG\Property(
  *     property="id",
  *     type="string",
  *     description="id of the project"
  *   ),
  *   @SWG\Property(
  *     property="description",
  *     type="string",
  *     description="Description of the project"
  *   ),
  *   @SWG\Property(
  *     property="due",
  *     type="integer",
  *     description="Timestamp of when the project is due"
  *   ),
  *   @SWG\Property(
  *     property="name",
  *     type="string",
  *     description="The name of the project"
  *   ), 
  *   @SWG\Property(
  *     property="changed",
  *     type="integer",
  *     description="Timestamp of when the project was changed"
  *   ),
  *   @SWG\Property(
  *     property="created",
  *     type="integer",
  *     description="Timestamp of when the project was created"
  *   ),
  *   @SWG\Property(
  *     property="notes",
  *     type="string",
  *     description="Project note"
  *   ), 
  *   @SWG\Property(
  *     property="status",
  *     type="string",
  *     description="Project status"
  *   ),
  *   @SWG\Property(
  *     property="uid",
  *     type="string",
  *     description="Project uid"
  *   ), 
  * )
  *
  */


  public function publicFieldsInfo(){
    
    $processFile = array(array($this, 'processFile') );
    $public_fields = parent::publicFieldsInfo();

    $public_fields['file'] = array(
      'property' => 'field_project_file',
      'process_callbacks' => $processFile,
      'create_or_update_passthrough' => TRUE
    );  

    return $public_fields;
  }

  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    if ($_FILES) {
      $handler = restful_get_restful_handler('project-file-upload');
      $result = $handler->post('', array($_FILES));
      $field_value = $this->propertyValuesPreprocess('field_project_file', $result[0]['id'], 'file');
      $wrapper->field_project_file->set($field_value);
    }
  }

/**
   *
   * @SWG\Path(
   *   path="/project-files/",
   *   @SWG\Get(
   *     tags={"project-files"},
   *     summary="Performs a display of project-files content",
   *     @SWG\Response(
   *       response=200,
   *       description="Displays content of project-files content",
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
  
  public function getQueryForList() {
    return parent::getQueryForList()
      ->propertyCondition('status', array(NODE_PUBLISHED, NODE_NOT_PUBLISHED))
      ->propertyCondition('uid', $this->getAccount()->uid);
  }
}