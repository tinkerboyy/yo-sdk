<?php

/**
 * @file
 * Contains RestfulSowResource.
 */

class RestfulSowResource extends AGRestfulEntityBaseNode {
  /**
* Overrides RestfulExampleArticlesResource::publicFieldsInfo().
* @SWG\Definition(
*   definition="keywords",
*   @SWG\Property(
*     property="tid",
*     type="string",
*     description="tid"
*   ),
*   @SWG\Property(
*     property="vid",
*     type="string",
*     description="vid"
*   ),
*   @SWG\Property(
*     property="name",
*     type="string",
*     description="Name of keyword"
*   ),
*   @SWG\Property(
*     property="description",
*     type="string",
*     description="Description of the keyword"
*   ),
*   @SWG\Property(
*     property="format",
*     type="string",
*     description="The format of the keyword"
*   ),
*   @SWG\Property(
*     property="weight",
*     type="string",
*     description="weight of keyword"
*   ),
*   @SWG\Property(
*     property="uuid",
*     type="string",
*     description="Uuid"
*   ),
*   @SWG\Property(
*     property="vocabulary_machine_name",
*     type="string",
*     description="vocabulary machine name"
*   ),
*   @SWG\Property(
*     property="rdf_mapping",
*     type="object",
*     description=""
*   ),
* )
*
* @SWG\Definition(
*   definition="Categories",
*   @SWG\Property(
*     property="tid",
*     type="string",
*     description="tid"
*   ),
*   @SWG\Property(
*     property="vid",
*     type="string",
*     description="vid"
*   ),
*   @SWG\Property(
*     property="name",
*     type="string",
*     description="Name of category"
*   ),
*   @SWG\Property(
*     property="description",
*     type="string",
*     description="Description of the category"
*   ),
*   @SWG\Property(
*     property="format",
*     type="string",
*     description="The format of the category"
*   ),
*   @SWG\Property(
*     property="weight",
*     type="string",
*     description="The weight of the category"
*   ),
*   @SWG\Property(
*     property="uuid",
*     type="string",
*     description="Uuid"
*   ),
*   @SWG\Property(
*    property="vocabulary_machine_name",
*     type="string",
*     description="vocabulary machine name"
*   ),
*   @SWG\Property(
*     property="rdf_mapping",
*     type="object",
*     description=""
*   ),
* )
*
*    @SWG\Definition(
*      definition="Sow",
*      @SWG\Property(
*        property="id",
*        type="integer",
*        description="ID of sow resource"
*      ),
*      @SWG\Property(
*        property="label",
*        type="string",
*        description="Label of specific sow"
*      ),
*      @SWG\Property(
*        property="self",
*        type="string",
*        description="Url of the sow api"
*      ),
*      @SWG\Property(
*        property="body",
*        type="string",
*        description="Content of the SOW"
*      ),
*      @SWG\Property(
*        property="agency",
*        type="string",
*        description="Displays agency name"
*      ),
*      @SWG\Property(
*        property="categories",
*        type="object",
*        description="Displays list of categories",
*        ref="#/definitions/categories"
*      ),
*      @SWG\Property(
*        property="keywords",
*        type="object",
*        description="Display list of keywords",
*        ref="#/definitions/keywords"
*      ),
*      @SWG\Property(
*        property="pdf",
*        type="object",
*        description="Displays the property-value pairs for the pdf object"
*      ),
*      @SWG\Property(
*        property="word",
*        type="object",
*        description="Displays the property-value pairs for the word object"
*      ),
*      @SWG\Property(
*        property="sow_type",
*        type="string",
*        description="Sow type"
*      ),
*      @SWG\Property(
*        property="views",
*        type="integer",
*        description="Number of views"
*      ),
*      @SWG\Property(
*        property="downloads",
*        type="integer",
*        description="Number of downloads",
*        ref="#/definitions/UserInfo"
*      ),
*      @SWG\Property(
*        property="sow_type_name",
*        type="string",
*        description="Current session details",
*     ),
*    )
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'field_description',
      );

    $public_fields['agency'] = array(
      'property' => 'field_agency',
      );

    $public_fields['categories'] = array(
      'property' => 'field_sow_category2',
      );

    $public_fields['keywords'] = array(
      'property' => 'field_sow_keywords',
      );

    $public_fields['pdf'] = array(
      'property' => 'field_upload',
      );

    $public_fields['word'] = array(
      'property' => 'field_word_document_upload',
      );

    $public_fields['sow_type'] = array(
      'property' => 'field_sow_type',
      );

    return $public_fields;
  }


  /**
   * {@inheritdoc}
   */
  public function viewEntity($id) {
    $entity = parent::viewEntity($id);

      $nid = $entity['id'];
      // get total view count of node
      $statistics = statistics_get($nid);

      $entity['views'] = (int) $statistics['totalcount'];
      // get word downloads count
      $pdf = _get_file_count($entity['pdf']);
      // get word downloads count
      $word = _get_file_count($entity['word']);
      $downloads = $pdf + $word;

      $entity['downloads'] = $downloads;

      // set the url absolute path for both pdf and word docs
      if (isset($entity['pdf'])) {
        $entity['pdf']['url'] = $this->fileProcess($nid, $entity['pdf']);
        $entity['pdf']['embed_url'] = $this->fileProcess($nid, $entity['pdf'], true);
      }
      if (isset($entity['word'])) {
        $entity['word']['url'] = $this->fileProcess($nid, $entity['word']);
      }

    //Get full name of SOW Type
    $sow_type_field = field_info_field('field_sow_type');
    $sow_type_name = $sow_type_field['settings']['allowed_values'][$entity['sow_type']];
    //Remove the sow_type in parenthesis from name
    list($sow_type_name) = explode('(', $sow_type_name);
    $entity['sow_type_name'] = $sow_type_name;

    $this->statistics_set($id);

    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function createEntity() {
    GLOBAL $user;
    $entity_info = $this->getEntityInfo();
    $bundle_key = $entity_info['entity keys']['bundle'];
    $values = $bundle_key ? array($bundle_key => $this->bundle) : array();

    if (!($_GET['word'] || $_GET['pdf'])) {
      throw new RestfulBadRequestException('Must provide file ID for PDF or Word document');
    }

    if ($_GET['word']) {
      $wordFile = file_load($_GET['word']);
      if (!$wordFile) {
        throw new RestfulBadRequestException('Invalid Word file ID');
      }
    }

    if ($_GET['pdf']) {
      $pdfFile = file_load($_GET['pdf']);
      if (!$pdfFile) {
        throw new RestfulBadRequestException('Invalid PDF file ID');
      }
    }

    $entity = entity_create($this->entityType, $values);
    $entity->status = 0;

    if ($this->checkEntityAccess('create', $this->entityType, $entity) === FALSE) {
      // User does not have access to create entity.
      $params = array('@resource' => $this->getPluginKey('label'));
      throw new RestfulForbiddenException(format_string('You do not have access to create a new @resource resource.', $params));
    }

    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    if ($wordFile) {
      $wrapper->field_word_document_upload->file->set($wordFile);
    }

    if ($pdfFile) {
      $wrapper->field_upload->file->set($pdfFile);
    }

    $this->setPropertyValues($wrapper);

    return array($this->viewEntity($wrapper->getIdentifier()));
  }

  /**
   * Get a list of entities.
   *
   * @return array
   *   Array of entities, as passed to RestfulEntityBase::viewEntity().
   *
   * @throws RestfulBadRequestException
   */
  public function getList() {
    $results = parent::getList();

    foreach ($results as $key => $result) {
      $nid = $result['id'];
      // get total view count of node
      $statistics = statistics_get($nid);

      $results[$key]['views'] = (int) $statistics['totalcount'];
      // get word downloads count
      $pdf = _get_file_count($result['pdf']);
      // get word downloads count
      $word = _get_file_count($result['word']);
      $downloads = $pdf + $word;

      $results[$key]['downloads'] = $downloads;

      // set the url absolute path for both pdf and word docs
      if (isset($result['pdf'])) {
        //$results[$key]['pdf']['url'] = $this->fileProcess($nid, $result['pdf']['filename']);
        $results[$key]['pdf']['url'] = $this->fileProcess($nid, $result['pdf']);
        $results[$key]['pdf']['embed_url'] = $this->fileProcess($nid, $result['pdf'], true);
      }
      if (isset($result['word'])) {
        //$results[$key]['word']['url'] = $this->fileProcess($nid, $result['word']['filename']);
        $results[$key]['word']['url'] = $this->fileProcess($nid, $result['word']);
      }
    }

    return $results;
  }

  /**
   * Process callback, Get Drupal full url file path.
   *
   * @param int $nid
   *   The node id.
   *
   * @param string $file
   *   The file name.
   *
   * @return string
   *   A cleaned file tracking path.
   */
  private function fileProcess($nid, $file, $embed = false) {
    if (!$embed) {
      $file_url = track_da_files_create_url($file['uri']);
      $file_url .= '?file=1';
      if (isset($file['type'])) {
        $file_url .= '&type=' . $file['type'];
      }
      if (isset($file['id'])) {
        $file_url .= '&id=' . $file['id'];
      }
    } else {
      $file_url = file_create_url($file['uri']);
    }
    return $file_url;
  }
 /**
*
*      @SWG\Path(
*        path="/sow",
*        @SWG\Get(
*          tags={"Sow"},
*          summary="Provides List of Sow",
*          @SWG\Response(
*            response=200,
*            description="List of Sow",
*            @SWG\Schema(
*              type="object",
*              @SWG\Property(
*                property="data",
*                type="array",
*                @SWG\Items(ref="#/definitions/Auth")
*              )
*            )
*          )
*        ),
*      )
*  
*/

  private function _get_file_count($file) {
    $query = "SELECT t.pid FROM {track_da_files_paths} t " .
    "WHERE t.fid = :fid AND t.path = :uri ";
    $result = db_query($query, array(':fid' => $file['fid'], ':uri' => $file['uri']))->fetch();
    if (!empty($result)) {
      $pid = $result->pid;
      $query2 = "SELECT COUNT(t.recid) counter FROM {track_da_files} t " .
      "WHERE t.pid = :pid GROUP BY t.pid ";
      $result2 = db_query($query2, array(':pid' => $pid))->fetch();
      if (!empty($result2)) {
        return $result2->counter;
      } else {
        return 0;
      }
    }
  }

  /**
   * Save a node's "view statistics" per hit.
   *
   * @param $nid
   *   The node ID.
   *
   */
  private function statistics_set($nid) {
    if (is_numeric($nid)) {
      db_merge('node_counter')
      ->key(array('nid' => $nid))
      ->fields(array(
        'daycount' => 1,
        'totalcount' => 1,
        'timestamp' => REQUEST_TIME,
        ))
      ->expression('daycount', 'daycount + 1')
      ->expression('totalcount', 'totalcount + 1')
      ->execute();
    }
  }
}
