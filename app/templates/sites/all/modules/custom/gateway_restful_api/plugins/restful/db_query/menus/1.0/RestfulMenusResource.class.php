<?php
/**
 * @file
 * Contains RestfulEntityBase.
 */
class RestFulMenusResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {
  /**
   * {@inheritdoc}
   */

   /**
    * Overrides \RestfulEntityBase::publicFieldsInfo().
   @SWG\Definition(
     definition="Navigation",
     @SWG\Property(
       property="label",
       type="string",
       description="Display label of Menu"
     ),
     @SWG\Property(
       property="description",
       type="string",
       description="Description of menu label",
     ),
     @SWG\Property(
       property="menuName",
       type="string",
       description="Displays the Menu Name",
     ),
     @SWG\Property(
       property="count",
       type="integer",
       description="Displays the number of available Menu Items",
     ),
     @SWG\Property(
       property="self",
       type="Object",
       description="permalink to the currently shown up Navigation label"
     ),
   )
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
   *   path="/navigation",
   *   @SWG\Get(
   *     tags={"Navigation"},
   *     summary="Returns all available Menu Labels",
   *     @SWG\Response(
   *       response=200,
   *       description="List of Menu Labels",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Navigation")
   *         )
   *       )
   *     )
   *   ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of Menu Labels",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Navigation")
   *         )
   *       )
   *     )
   * )
   *
   */
  public function publicFieldsInfo() {
    $public_fields['label'] = array(
      'property' => 'title',
    );
    $public_fields['description'] = array(
      'property' => 'description',
    );
    $public_fields['menuName'] = array(
      'property' => 'menu_name',
    );
    if (arg(3) !== NULL) {
      $public_fields['menuItems'] = array(
        'callback' => array($this, 'menuItems')
      );
    }
    return $public_fields;
  }
  protected function menuItems() {
    if (arg(3) !== NULL) {
      $query = db_select('menu_links', 'ml');
      $query->fields('ml', array('mlid', 'link_title', 'link_path', 'options', 'has_children', 'weight', 'p1', 'p2', 'p3', 'p4', 'p5'));
      $query->condition('menu_name', arg(3),'=');
      $query->condition('hidden', 0,'=');
      $output = $query->execute()->fetchAll();
    }
    return $output;
  }
}
