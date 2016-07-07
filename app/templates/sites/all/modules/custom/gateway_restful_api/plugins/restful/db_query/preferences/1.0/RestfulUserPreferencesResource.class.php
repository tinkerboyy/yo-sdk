<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulUserPreferencesResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  /**
    @SWG\Definition(
      definition="UserPreference",
      @SWG\Property(
        property="id", 
        type="integer",
        description="Unique ID of the User Preference entry"
      ),
      @SWG\Property(
        property="userId", 
        type="integer",
        description="Unique ID of the User"
      ),
      @SWG\Property(
        property="itemId", 
        type="integer",
        description="Unique ID of the item the preference is being stored for"
      ),
      @SWG\Property(
        property="type", 
        type="string",
        description="Type of preference being stored"
      ),
      @SWG\Property(
        property="action", 
        type="string",
        description="The action being stored for the type"
      ),
      @SWG\Property(
        property="data", 
        type="string",
        description="Extra data needed for the preference being stored"
      ),
    )
    */
  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'upid',
    );
    $public_fields['userId'] = array(
      'property' => 'uid',
    );
    $public_fields['itemId'] = array(
      'property' => 'item_id',
    );

    $public_fields['type'] = array(
      'property' => 'type',
    );

    $public_fields['action'] = array(
      'property' => 'action',
    );

    $public_fields['data'] = array(
      'callback' => array($this, 'unserializeData')
    );

    return $public_fields;
  }

  protected function unserializeData($data) {
    return !empty($data->data) ? unserialize($data->data) : null;
  }

  /**
   * Create an item from the request object.
   *
   * @return array
   *   The structured array for the item ready to be rendered.

      * @SWG\Path(
      *   path="/preferences",
      *   @SWG\Get(
      *     summary="Returns list of User Preferences for currently logged in user",
      *     tags={"Users"},
      *     @SWG\Response(
      *       response=200,
      *       description="List of user preferences",
      *       @SWG\Schema(
      *         type="object",
      *         @SWG\Property(
      *           property="data",
      *           type="array",
      *           @SWG\Items(
      *             ref="#/definitions/UserPreference"
      *           )
      *         )
      *       )
      *     )
      *   ),
        @SWG\Post(
          tags={"Users"},
          summary="Registers a new user preference",
          consumes={"application/json"},
          @SWG\Response(
            response=200,
            description="List of user preferences",
            @SWG\Schema(
              type="object",
              @SWG\Property(
                property="data",
                type="array",
                @SWG\Items(
                  ref="#/definitions/UserPreference"
                )
              )
            )
          ),
          @SWG\Parameter(
            name="itemId", 
            type="integer",
            in="formData",
            required=true,
            description="Unique ID of the item the preference is being stored for"
          ),
          @SWG\Parameter(
            name="type", 
            type="string",
            in="formData",
            required=true,
            description="Type of preference being stored"
          ),
          @SWG\Parameter(
            name="action", 
            type="string",
            in="formData",
            required=true,
            description="The action being stored for the type"
          ),
          @SWG\Parameter(
            name="data", 
            type="string",
            in="formData",
            description="Extra data needed for the preference being stored"
          ),
        )
      * )
   */
  public function create() {
    // get logged in user uid
    $uid = $GLOBALS['user']->uid;

    // get query string and convert to array
    $data = drupal_get_query_parameters();

    if (empty($query_string)) {
      $request = $this->getRequest();
      static::cleanRequest($request);

      $data = $request;
    }

    //if data preferences are being stored (eg screen settings), clean out old setting
    if (isset($data['data'])) {
      db_delete($this->tableName)
        ->condition('action', $data['action'])
        ->condition('type', $data['type'])
        ->condition('uid', $uid)
        ->execute();
    }

    $upid = db_insert($this->tableName)
        ->fields(array(
          'uid' => $uid,
          'item_id' => $data['itemId'],
          'type' => $data['type'],
          'action' => $data['action'],
          'data' => serialize($data['data'])
        ))->execute();

    $data['userId'] = $uid;
    $data['id'] = $upid;

    return array($data);
  }

  /**
    * @SWG\Path(
    *   path="/preferences?filter[action]={action}",
    *   @SWG\Get(
    *     summary="Returns list of User Preferences for currently logged in user",
    *     tags={"Users"},
    *     @SWG\Response(
    *       response=200,
    *       description="List of user preferences",
    *       @SWG\Schema(
    *         type="object",
    *         @SWG\Property(
    *           property="data",
    *           type="array",
    *           @SWG\Items(
    *             ref="#/definitions/UserPreference"
    *           )
    *         )
    *       )
    *     ),
    *     @SWG\Parameter(
    *       name="action", 
    *       type="string",
    *       in="path",
    *       required=true,
    *       description="The preference action being retrieved"
    *     ),
    *   )
    * )
    */

  /**
    * To find preferences by type
    * @SWG\Path(
    *   path="/preferences?filter[type]={type}",
    *   @SWG\Get(
    *     summary="Returns list of User Preferences for currently logged in user",
    *     tags={"Users"},
    *     @SWG\Response(
    *       response=200,
    *       description="List of user preferences",
    *       @SWG\Schema(
    *         type="object",
    *         @SWG\Property(
    *           property="data",
    *           type="array",
    *           @SWG\Items(
    *             ref="#/definitions/UserPreference"
    *           )
    *         )
    *       )
    *     ),
    *     @SWG\Parameter(
    *       name="type", 
    *       type="string",
    *       in="path",
    *       required=true,
    *       description="The preference type being retrieved"
    *     ),
    *   )
    * )
  */

  /**
   * Remove the item from the data source.
   *
   * @param mixed $id
   *   The unique ID for the item.
    @SWG\Path(
      path="/preferences/{itemId}",
      @SWG\Delete(
        tags={"Users"},
        summary="Unregisters a specific user preference",
        @SWG\Response(
          response=200,
          description="List of user preferences",
          @SWG\Schema(
            type="object",
            @SWG\Property(
              property="data",
              type="array",
              @SWG\Items(
                ref="#/definitions/UserPreference"
              )
            )
          )
        ),
        @SWG\Parameter(
          name="itemId", 
          type="integer",
          in="path",
          required=true,
          description="Unique ID of the item the preference is being stored for"
        ),
        @SWG\Parameter(
          name="type", 
          type="string",
          in="query",
          required=true,
          description="Type of preference to be deleted"
        ),
        @SWG\Parameter(
          name="action", 
          type="string",
          in="query",
          required=true,
          description="The action to be deleted"
        ),
      )
    )
   */
  public function remove($itemId) {
    // get logged in user uid
    $uid = $GLOBALS['user']->uid;

    // get query string and convert to array
    $querystring = drupal_get_query_parameters();

    // If it's a delete method we will want a 204 response code.
    // Set the HTTP headers.
    $this->setHttpHeaders('Status', 204);

    // get the upid based on the itemId
    $id = db_select($this->tableName, 'up')
              ->fields('up', array('upid'))
              ->condition('item_id', $itemId,'=')
              ->condition('uid', $uid,'=')
              ->condition('type', $querystring['filter']['type'],'=')
              ->condition('action', $querystring['filter']['action'],'=')
              ->execute()
              ->fetchAssoc();
    $id = $id['upid'];

    // set the id column to upid
    $this->setIdColumn('upid');

    // use tableName method
    $query = db_delete($this->tableName);
    foreach ($this->getIdColumn() as $index => $column) {
      $query->condition($column, current($this->getColumnFromIds(array($id), $index)));
    }

    $query->execute();
  }

  /**
   * Get a basic query object.
   *
   * @return SelectQuery
   *   A new SelectQuery object for this connection.
   */
  protected function getQuery() {
    // get logged in user uid
    $uid = $GLOBALS['user']->uid;

    $query = parent::getQuery();

    $query->condition('uid', $uid,'=');

    return $query;
  }
}
