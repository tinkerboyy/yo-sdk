<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulHelpResource extends AGRestfulEntityBaseNode {

  protected $nid = NULL;
  /**
   * Overrides RestfulHelpResource::publicFieldsInfo().
    *
    * @SWG\Definition(
    *   definition="HelpResource",
    *   @SWG\Property(
    *     property="id",
    *     type="integer",
    *     description="Id of Help Item"
    *   ),
    *   @SWG\Property(
    *     property="label",
    *     type="string",
    *     description="Label of Help Item"
    *   ),
    *   @SWG\Property(
    *     property="body",
    *     type="string",
    *     description="Description of Help Item",
    *   ),
    *   @SWG\Property(
    *     property="flag",
    *     type="string",
    *     description="The feature/application to which this help Item belongs to",
    *   ),
    *   @SWG\Property(
    *     property="path",
    *     type="String",
    *     description="View/edit link for the shown up Help Item"
    *   ),
    *   @SWG\Property(
    *     property="lc",
    *     type="String",
    *     description=""
    *   ),
    *   @SWG\Property(
    *     property="count",
    *     type="integer",
    *     description="The number of available Menu Items",
    *   ),
    *   @SWG\Property(
    *     property="self",
    *     type="Object",
    *     description="permalink to the currently shown up Help Item"
    *   ),
    * )
  */

  /**
   * Get a list of entities.
   *
   * @return array
   *   Array of entities, as passed to RestfulEntityBase::viewEntity().
   *
   * @throws RestfulBadRequestException
   *
   * @SWG\Path(
   *   path="/help",
   *   @SWG\Get(
   *     tags={"HelpResource"},
   *     summary="Returns all available Help Items",
   *     @SWG\Response(
   *       response=200,
   *       description="List of Help Items",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/HelpResource")
   *         )
   *       )
   *     )
   *   ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of Help Items",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/HelpResource")
   *         )
   *       )
   *     )
   * )
   *
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );
    $public_fields['flag'] = array(
      'property' => 'field_flag',
      'sub_property' => 'name'
    );
    $public_fields['path'] = array(
      'property' => 'url'
    );

    $public_fields['lc'] = array(
      'property' => 'field_lc'
    );

     $public_fields['public'] = array(
      'property' => 'field_public_private'
    );

    return $public_fields;
  }

  /**
   * Overrides RestfulEntityBase::getQueryForList().
   *
   * Expose only published nodes.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();

    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function viewEntities($ids_string) {
    $efq = new EntityFieldQuery();
    $vid = taxonomy_get_term_by_name($ids_string);

    $vid = key($vid);

    $entities = $efq->entityCondition('entity_type', 'node', '=')
      ->entityCondition('bundle', 'help', '=')
      ->propertyCondition('status', 1, '=')
      ->fieldCondition('field_flag', 'tid', $vid, '=')->execute();

    if (isset($entities['node'])) {
      foreach($entities['node'] as $entity) {
        $ids[] = $entity->nid;
      }
    }

    if (is_null($ids)) {
      $ids = array_unique(array_filter(explode(',', $ids_string)));
    }

    $output = array();

    foreach ($ids as $id) {
      $output[] = $this->viewEntity($id);
    }
    return $output;
  }
}
