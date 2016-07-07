<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermTags.
 */

class RestfulEntityTaxonomyTermSowCategories extends AGRestfulEntityBaseTaxonomyTerm {
  /**
  *
  * @SWG\Definition(
  *   definition="Sow-Categories",
  *   @SWG\Property(
  *     property="id",
  *     type="string",
  *     description="Id of user"
  *   ),
  *   @SWG\Property(
  *     property="name",
  *     type="string",
  *     description="Display name of the sow category"
  *   ),
  *   @SWG\Property(
  *     property="category_icon",
  *     type="string",
  *     description="Display category icon"
  *   ),
  *   @SWG\Property(
  *     property="children",
  *     type="array",
  *     description="User system roles",
  *      @SWG\Items(
  *        type="string"
  *      )
  *   ),
  *   
  * )
  *
  */
  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'tid',
    );
    $public_fields['name'] = array(
      'property' => 'name',
    );
    $public_fields['category_icon'] = array(
      'property' => 'field_category_icon',
    );

    return $public_fields;
  }

  /**
   * Prepare a query for RestfulEntityBase::getList().
   *
   * @return EntityFieldQuery
   *   The EntityFieldQuery object.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();

    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function viewEntities($ids_string) {
    $output = parent::viewEntities($ids_string);

    return $output;
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
    $request = $this->getRequest();

    $autocomplete_options = $this->getPluginKey('autocomplete');
    if (!empty($autocomplete_options['enable']) && isset($request['autocomplete']['string'])) {
      // Return autocomplete list.
      return $this->getListForAutocomplete();
    }

    $entity_type = $this->entityType;
    $result = $this
      ->getQueryForList()
      ->execute();

    foreach ($result['taxonomy_term'] as $tid => $term) {
      // see if term has parent
      $parent = taxonomy_get_parents($tid);

      // if it has parent, remove it
      if (count($parent) > 0) {
        // save the child and parent id
        $children[key($parent)][] = $result['taxonomy_term'][$tid];

        unset($result['taxonomy_term'][$tid]);
      }
    }
    if (empty($result[$entity_type])) {
      return array();
    }

    $ids = array_keys($result[$entity_type]);

    // Pre-load all entities if there is no render cache.
    $cache_info = $this->getPluginKey('render_cache');
    if (!$cache_info['render']) {
      entity_load($entity_type, $ids);
    }

    $return = array();

    // If no IDs were requested, we should not throw an exception in case an
    // entity is un-accessible by the user.
    foreach ($ids as $id) {
      if ($row = $this->viewEntity($id)) {
        $return[] = $row;
      }
    }

    foreach ($return as $parent_key => $parent) {
      if (array_key_exists($parent['id'], $children)) {
        foreach ($children[$parent['id']] as $key => $term) {
          $return[$parent_key]['children'][$key] = $this->viewEntity($term->tid);
        }
      }
    }
  /**
   *
   * @SWG\Path(
   *   path="/sow-categories/",
   *   @SWG\Get(
   *     tags={"sow-categories"},
   *     summary="Performs a list of sow categories",
   *     @SWG\Response(
   *       response=200,
   *       description="List of sow categories",
   *       @SWG\Schema(
   *         type="object",
   *          @SWG\Property(
   *            property="data",
   *            type="array",
   *            @SWG\Items(ref="#/definitions/sow-categories")
   *          )
   *       )
   *     )
  *   )
  * )
  */

    return $return;
  }
}
