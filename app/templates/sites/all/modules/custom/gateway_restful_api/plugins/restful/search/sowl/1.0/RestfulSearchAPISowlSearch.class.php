<?php

/**
 * @file
 * Contains \RestfulSearchAPIBasicSearch.
 */

class RestfulSearchAPISowlSearch extends \AGRestfulDataProviderSearchAPI implements \RestfulInterface {

  private $nid = NULL;
  /**
   * Overrides \RestfulBase::publicFieldsInfo().
   *
   * @SWG\Definition(
   *   definition="SOWLSearchResultItem",
   * 	 @SWG\Property(
   * 	   property="id",
   * 	   type="integer",
   * 	   description="ID of SOWL document"
   * 	 ),
   * 	 @SWG\Property(
   * 	   property="title",
   * 	   type="string",
   * 	   description="Title of SOWL document"
   * 	 ),
   * 	 @SWG\Property(
   * 	   property="body",
   * 	   type="string",
   * 	   description="Body text of SOWL document"
   * 	 )
   * )
   */
  public function publicFieldsInfo() {
    return array(
      'id' => array(
        'property' => 'nid',
        ),
      'title' => array(
        'property' => 'title',
        ),
      'body' => array(
        'property' => 'field_description',
        'sub-property' => LANGUAGE_NONE . '::0::value',
        ),
      'category' => array(
        'property' => 'field_sow_category2',
        ),
      'keywords' => array(
        'property' => 'field_sow_keywords',
        ),
      'pdf' => array(
        'property' => 'field_upload',
        ),
      'word' => array(
        'property' => 'field_word_document_upload',
        ),
      'node_type' => array(
        'property' => 'type',
        ),
      'entity_id' => array(
        'property' => 'search_api_id',
        'process_callbacks' => array(
          'intVal',
          ),
        ),
      'sow_type' => array(
        'property' => 'field_sow_type'
        ),
      'related_solutions' => array(
        'property' => 'field_related_solutions'
        ),
      'contract_format' => array(
        'property' => 'field_contract_format'
        ),
      'document_type' => array(
        'property' => 'field_document_type'
        ),
      'version_id' => array(
        'property' => 'vid',
        'process_callbacks' => array(
          'intVal',
          ),
        ),
      'relevance' => array(
        'property' => 'search_api_relevance',
        ),
      );
}

  /**
   *
   * @SWG\Path(
   *   path="/sowl/{keyword}",
   *   @SWG\Get(
   *     tags={"sowl"},
   *     summary="Performs search on SOWL documents",
   *     @SWG\Parameter(
   *       name="keyword",
   *       description="Keywords to use to search SOWL library",
   *       in="path",
   *       required=false,
   *       type="string"
   *     ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of search results",
   *       @SWG\Schema(
   *         type="array",
   *          @SWG\Items(ref="#/definitions/SOWLSearchResultItem")
   *       )
   *     )
   *   )
   * )
   */
  public function index() {
    $output = $this->view(NULL);

    return $output;
  }

  /**
   * View an item from the data source.
   *
   * @param mixed $id
   *   The unique ID for the item.
   *
   * @return array
   *   The structured array ready to be rendered for the current item.
   */
  public function view($id) {
    // get query string and convert to array
    // $data = drupal_get_query_parameters();

    $this->setRange();
    $outputs = parent::view($id);

    // if categories exist
    // if (isset($data['categories'])) {
    //   // create categories array with the possibility of their being more than one
    //   $categories = explode(',', $data['categories']);
    // }

    foreach ($outputs as $key => $output) {
      if (!$this->checkEntityAccess('view', 'node', $output)) {
        continue;
      }

      $nid = $output['id'];

      // get total view count of node
      $statistics = statistics_get($nid);
      $output['views'] = (int) $statistics['totalcount'];

      // get word downloads count
      $pdf = _get_file_count($output['pdf']['und'][0]);

      // get word downloads count
      $word = _get_file_count($output['word']['und'][0]);

      $downloads = $pdf + $word;
      $output['downloads'] = $downloads;

      // set the url absolute path for both pdf and word docs
      if (isset($output['pdf']['und'])) {
        $output['pdf']['und'][0]['url'] = $this->fileProcess($nid, $output['pdf']['und'][0]);
      }
      if (isset($output['word']['und'])) {
        $output['word']['und'][0]['url'] = $this->fileProcess($nid, $output['word']['und'][0]);
      }

      if(isset($output['category']['und'])) {
        foreach ($output['category']['und'] as $index => $category) {
          // check to see if term has a parent term
          $parent_tid = taxonomy_get_parents($category['tid']);

          if (count($parent_tid) > 0) {
            // add parent id and name
            $output['category']['und'][$index]['tid'] = $parent_tid[key($parent_tid)]->tid;
            $output['category']['und'][$index]['name'] = $parent_tid[key($parent_tid)]->name;

            // move sub category to children area
            $output['category']['und'][$index]['children'][0]['tid'] = $category['tid'];
            $output['category']['und'][$index]['children'][0]['name'] = $this->termProcess($category['tid']);
          } else {
            $output['category']['und'][$index]['name'] = $this->termProcess($category['tid']);
          }
        }
      }

      if(isset($output['keywords']['und'])) {
        foreach ($output['keywords']['und'] as $index => $category) {
          $output['keywords']['und'][$index]['name'] = $this->termProcess($category['tid']);
        }
      }

      $tid = $output['category']['und'][0]['tid'];

      $child_tid = (isset($output['category']['und'][0]['children']) ? $output['category']['und'][0]['children'][0]['tid'] : 0);

      //Get full name of SOW Type
      $sow_type = $output['sow_type']['und'][0]['value'];
      if ($sow_type) {
        $sow_type_field = field_info_field('field_sow_type');
        $sow_type_name = $sow_type_field['settings']['allowed_values'][$sow_type];
        //Remove the sow_type in parenthesis from name
        list($sow_type_name) = explode('(', $sow_type_name);
        $output['sow_type_name'] = $sow_type_name;
      }

      // if categories querystring has been passed
      // if (isset($categories)) {
      //   $remove = TRUE;
      //   if (in_array($tid, $categories)) {
      //     $remove = FALSE;
      //   } else if ($child_tid > 0 && in_array($child_tid, $categories)) {
      //     $remove = FALSE;
      //   }

      //   if ($remove) {
      //     unset($output);
      //   }
      // }

      if (isset($output)) {
        $final_output[] = $output;
      }
    }

    return $final_output;
  }

  protected function checkEntityAccess($op, $entity_type, $entity) {
    if($this->isPublicUser()) {
      $wrappedEntity = entity_metadata_wrapper($entity_type, $entity['id']);
      $publicFlag = $wrappedEntity->field_public_private->value();
      if ($publicFlag !== true) return false;
    }

    return true;
  }

  /**
   * Executes the Search API query and stores the total count.
   *
   * @param string $keywords
   *   Keywords to search.
   * @param array $options
   *   An array of options passed to search_api_query.
   *
   * @throws \RestfulServerConfigurationException
   *   For invalid indices.
   *
   * @return array
   *   The array of results.
   *
   * @see search_api_query()
   */
  protected function executeQuery($keywords, array $options) {
    // get query string and convert to array
    $querystring = drupal_get_query_parameters();

    // if categories exist
    if (isset($querystring['categories'])) {
      // create categories array with the possibility of their being more than one
      $categories = explode(',', $querystring['categories']);
    }
    // if sow_type exist
    if (isset($querystring['sow_types'])) {
      // create categories array with the possibility of their being more than one
      $sowTypes = explode(',', $querystring['sow_types']);
    }
    // if related_solutions exist
    if (isset($querystring['related_solutions'])) {
      // create categories array with the possibility of their being more than one
      $relatedSolutions = explode(',', $querystring['related_solutions']);
    }
    // if contract_format exist
    if (isset($querystring['contract_formats'])) {
      // create categories array with the possibility of their being more than one
      $contractFormats = explode(',', $querystring['contract_formats']);
    }
    // if document_types exist
    if (isset($querystring['document_types'])) {
      // create categories array with the possibility of their being more than one
      $documentTypes = explode(',', $querystring['document_types']);
    }

    $index = search_api_index_load($this->getSearchIndex());

    if (!$index) {
      throw new \RestfulServerConfigurationException(format_string('Search API Exception: Unknown index with ID @id.', array(
        '@id' => $this->getSearchIndex(),
      )));
    }

    $query = $index->query($options);

    $this->queryForListSort($query);
    $this->queryForListFilter($query);
    $query->keys($keywords);

    if (count($categories) > 0) {
      $categoryFilter = $query->createFilter('OR');
      foreach($categories as $tid) {
        $term = taxonomy_term_load($tid);
        $terms[] = $term->name;

        $categoryFilter->condition('field_sow_category2:name', $term->name, '=');
      }
      $query->filter($categoryFilter);
    }

    if (count($sowTypes) > 0) {
      $sowTypeFilter = $query->createFilter('OR');
      foreach($sowTypes as $sowType) {
        $sowTypeFilter->condition('field_sow_type', $sowType, '=');
      }
      $query->filter($sowTypeFilter);
    }

    if (count($relatedSolutions) > 0) {
      $relatedSolutionsFilter = $query->createFilter('OR');
      foreach($relatedSolutions as $solutionId) {
        $relatedSolutionsFilter->condition('field_related_solutions', $solutionId, '=');
      }
      $query->filter($relatedSolutionsFilter);
    }

    if (count($contractFormats) > 0) {
      $contractFormatFilter = $query->createFilter('OR');
      foreach($contractFormats as $contractFormat) {
        $contractFormatFilter->condition('field_contract_format', $contractFormat, '=');
      }
      $query->filter($contractFormatFilter);
    }

    if (count($documentTypes) > 0) {
      $documentTypeFilter = $query->createFilter('OR');
      foreach($documentTypes as $documentType) {
        $documentTypeFilter->condition('field_document_type', $documentType, '=');
      }
      $query->filter($documentTypeFilter);
    }

    if($this->isPublicUser()) {
      $query->condition('field_public_private', true, '=');
    }

    $resultsObj = $query->execute();

    $this->setTotalCount($resultsObj['result count']);
    $results = $index->loadItems(array_keys($resultsObj['results']));

    // Add the index id and the relevance.
    foreach ($resultsObj['results'] as $id => $result) {
      $results[$id]->search_api_id = $result['id'];
      $results[$id]->search_api_relevance = $result['score'];
    }
    if (!empty($resultsObj['search_api_facets'])) {
      $this->hateoas['facets'] = $resultsObj['search_api_facets'];
    }
    $this->hateoas['count'] = $resultsObj['result count'];

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
   * Process callback, Get Drupal term name by tid.
   *
   * @param int $tid
   *   The term id.
   *
   * @return string
   *   The term name.
   */
  protected function termProcess($tid) {
    $term_object = taxonomy_term_load($tid);
    return $term_object->name;
  }

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

  private function in_array_recursive($needle, $haystack, $strict = false) {
    foreach ($haystack as $item) {
      if (($strict ? $item === $needle : $item == $needle) || (is_array($item) && in_array_r($needle, $item, $strict))) {
        return true;
      }
    }

    return false;
  }
}
