<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulUsersResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  /**
  * Overrides \RestfulBase::controllerInfo().
  * Returns the default controllers for the entity.
  *
  * @return array
  *   Nested array that provides information about what method to call for each
  *   route pattern.
  */
  public static function controllersInfo() {
    // Provide sensible defaults for the HTTP methods. These methods (index,
    // create, view, update and delete) are not implemented in this layer but
    // they are guaranteed to exist because we are enforcing that all restful
    // resources are an instance of \RestfulDataProviderInterface.
    return array(
      '' => array(
        // GET returns a list of entities.
        \RestfulInterface::GET => 'index',
        \RestfulInterface::HEAD => 'index',
      ),
      // We don't know what the ID looks like, assume that everything is the ID.
      '^.*$' => array(
        \RestfulInterface::GET => 'view',
        \RestfulInterface::HEAD => 'view',
      ),
    );
  }

  protected function intval($value = NULL) {
    return $value == NULL ? NULL : intval($value);
  }

  /**
  *
  * @SWG\Definition(
  *   definition="Users",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="ID of User"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Title of the User"
  *   ),
  *   @SWG\Property(
  * 	  property="self",
  * 	  type="string",
  * 	  description="Self Url of User"
  * 	),
  * 	@SWG\Property(
  * 	  property="mail",
  * 	  type="string",
  * 	  description="Email id of User"
  * 	),
  * )
  *
  */
  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $integerFormatter = array(
      array($this, 'intval'),
    );

    $public_fields['id'] = array(
      'property' => 'uid'
    );

    $public_fields['username'] = array(
      'property' => 'name',
    );

    $public_fields['email'] = array(
      'property' => 'mail',
    );

    $public_fields['created'] = array(
      'property' => 'created',
      'process_callbacks' => $integerFormatter
    );

    $public_fields['last_seen'] = array(
      'property' => 'login',
      'process_callbacks' => $integerFormatter
    );

    $public_fields['login_status'] = array(
      'property' => 'status',
      'process_callbacks' => $integerFormatter
    );

    $public_fields['connect_username'] = array(
      'property' => 'realname',
      'column_for_query' => 'realname.realname'
    );

    return $public_fields;
  }

  /**
   * Get a list of entities.
   *
   * @return array
   *   Array of entities, as passed to RestfulEntityBase::viewEntity().
   *
   * @throws RestfulBadRequestException
   *
   * @SWG\Path(
   *   path="/users",
   *   @SWG\Get(
   *     tags={"Users"},
   *     summary="Returns all available Users",
   *     @SWG\Response(
   *       response=200,
   *       description="List of Users",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Users")
   *         )
   *       )
   *     )
   *   ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of Users",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Users")
   *         )
   *       )
   *     )
   * )
   *
   */

  /**
   * Overrides \RestfulDataProviderDbQuery::getQueryForList().
   *
   * Make sure only privileged users may see a list of users.
   */
  public function getQueryForList() {
    $account = $this->getAccount();
    if (!user_access('administer users', $account) && !user_access('access user profiles', $account)) {
      throw new \RestfulForbiddenException('You do not have access to listing of users.');
    }
    return parent::getQueryForList();
  }

  /**
   * Overrides \RestfulBase::view().
   *
   * Make sure only privileged users may see a list of users.
   */
  public function view($id) {
    $account = $this->getAccount();
    if (!user_access('administer users', $account) && !user_access('access user profiles', $account)) {
      throw new \RestfulForbiddenException('You do not have access to listing of users.');
    }
    return parent::view($id);
  }

  /**
   * Overrides \RestfulDataProviderDbQuery::getQuery().
   *
   * Join with the terms table.
   */
  protected function getQuery() {
    $query = parent::getQuery();

    $query->condition('users.uid', 0, '>');
    $query->innerJoin('realname', NULL, 'users.uid = realname.uid');

    $query->addField('realname', 'realname', 'realname');

    return $query;
  }


}
