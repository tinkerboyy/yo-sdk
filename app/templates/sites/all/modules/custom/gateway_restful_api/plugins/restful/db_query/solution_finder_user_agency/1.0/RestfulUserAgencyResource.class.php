<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulUserAgencyResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {
  /**
  *  @SWG\Definition(
  *    definition="UserAgency",
  *    @SWG\Property(
  *      property="id",
  *      type="string",
  *      description="Unigue ID"
  *    ),
  *    @SWG\Property(
  *      property="availableTo",
  *      type="string",
  *      description="Solutions Finder Available To agency value"
  *    ),
  *    @SWG\Property(
  *      property="agency",
  *      type="string",
  *      description="CAS Agency of users that selected this availableTo value"
  *    ),
  *    @SWG\Property(
  *      property="count",
  *      type="string",
  *      description="Number of users that made this selection"
  *    )
  *  )
  */
  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'id',
    );
    $public_fields['availableTo'] = array(
      'property' => 'fkOptionId',
    );
    $public_fields['agency'] = array(
      'property' => 'user_agency',
    );
    $public_fields['count'] = array(
      'property' => 'count',
    );

    return $public_fields;
  }

  /**
    * {@inheritdoc}
    * @SWG\Path(
    *   path="/solutions-finder-user-agency",
    *   @SWG\Get(
    *     tags={"Solutions Finder"},
    *     summary="Machine-Learning endpoint for guessing user agency in Solutions Finder",
    *     @SWG\Response(
    *       response=200,
    *       description="List of agency selections",
    *       @SWG\Schema(
    *         type="object",
    *         @SWG\Property(
    *           property="data",
    *           type="array",
    *           @SWG\Items(
    *             ref="#/definitions/UserAgency"
    *           )
    *         )
    *       )
    *     ),
    *   ),
    *   @SWG\Post(
    *     tags={"Solutions Finder"},
    *     summary="Submits a new selection to machine learning",
    *     consumes={"application/json"},
    *     @SWG\Response(
    *       response=200,
    *       description="List of agency selections",
    *       @SWG\Schema(
    *         type="object",
    *         @SWG\Property(
    *           property="data",
    *           type="array",
    *           @SWG\Items(
    *             ref="#/definitions/UserAgency"
    *           )
    *         )
    *       )
    *     ),
    *     @SWG\Parameter(
    *       name="availableTo",
    *       type="integer",
    *       required=true,
    *       in="formData",
    *       description="ID of the availableTo option selected in Solutions Finder"
    *     ),
    *     @SWG\Parameter(
    *       name="agency",
    *       type="string",
    *       required=true,
    *       in="formData",
    *       description="CAS Agency string of the user that made the selection"
    *     )
    *   ),
    * )
   */
  public function index() {
    $results = $this
      ->getQueryForList()
      ->execute();

    $return = array();

    // set database to solution matrix
    db_set_active('solution_matrix');

    foreach ($results as $result) {
      $availableTo = db_select('tbAvailableToOptions')
        ->fields('tbAvailableToOptions', array('name'))
        ->condition('pkOptionId', $result->fkOptionId,'=')
        ->execute()
        ->fetchAssoc();

      $result->fkOptionId = $availableTo['name'];

      $return[] = $this->mapDbRowToPublicFields($result);
    }

    // set database back to drupal default
    db_set_active();

    return $return;
  }

  /**
   * Create an item from the request object.
   *
   * @return array
   *   The structured array for the item ready to be rendered.
   */
  public function create() {
    $table = 'tbUserAgencyPreferences';

    // set database to solution matrix
    db_set_active('solution_matrix');

    $request = $this->getRequest();

    static::cleanRequest($request);

    $data = $request;
    $optionId = (int) $data['availableTo'];
    $agency = $data['agency'];

    $search = db_select($table, 'uap')
        ->fields('uap', array('id', 'count'))
        ->condition('fkOptionId', $optionId, '=')
        ->condition('user_agency', $agency, '=')
        ->execute()
        ->fetch();

    if ($search) {
      db_update($table)
      ->fields(
        array(
        'fkOptionId' => $optionId,
        'user_agency' => $agency,
        'count' => $search->count + 1
        )
      )
      ->condition('fkOptionId', $optionId, '=')
      ->condition('user_agency', $agency, '=')
      ->execute();
      $id = $search->id;
    } else {
      $id = db_insert($table)
        ->fields(
          array(
          'fkOptionId' => $optionId,
          'user_agency' => $agency,
          'count' => 1
          )
        )
        ->execute();

      $count = 1;
    }

    $data['id'] = $id;
    $data['count'] = $search->count + 1;

    // set database back to drupal default
    db_set_active();

    return array($data);
  }

  /**
    * @SWG\Path(
    *   path="/solutions-finder-user-agency/{agency}",
    *   @SWG\Get(
    *     summary="Retrieves user agency guessses for defined agency",
    *     tags={"Solutions Finder"},
    *     @SWG\Parameter(
    *       name="agency",
    *       type="string",
    *       in="path",
    *       description="Name of the CAS agency to find suggestions for"
    *     ),
    *     @SWG\Response(
    *       response=200,
    *       description="List of agency selections",
    *       @SWG\Schema(
    *         type="object",
    *         @SWG\Property(
    *           property="data",
    *           type="array",
    *           @SWG\Items(
    *             ref="#/definitions/UserAgency"
    *           )
    *         )
    *       )
    *     ),
    *   ),
    * )
   */
  public function view($agency) {
    $table = 'tbUserAgencyPreferences';

    // set database to solution matrix
    db_set_active('solution_matrix');

    $query = db_select($table)
      ->fields($table)
      ->condition('user_agency', $agency, '=')
      ->orderBy('count', 'DESC');

    $results = $query->execute()->fetchAll();
    // set database back to drupal default
    db_set_active();

    return $results;
  }

  /**
   * Get a basic query object.
   *
   * @return SelectQuery
   *   A new SelectQuery object for this connection.
   */
  protected function getQuery() {
    $table = $this->getTableName();

    // set database to solution matrix
    db_set_active('solution_matrix');

    $query = db_select($table)->fields($table);

    // set database back to drupal default
    db_set_active();

    return $query;
  }
}
