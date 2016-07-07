<?php

/**
 * @file
 * Contains RestfulTopicsResource.
 */

class RestfulTopicsResource extends \AGRestfulEntityBase {

  public function setRequest(array $request = array()) {
    unset($request['comment_count']);
    //unset($request['new_comment_count']);
    //unset($request['view_count']);

    parent::setRequest($request);
  }

  /**
  *
  * @SWG\Definition(
  *   definition="Topics",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="ID of Community Topic"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Title of the community topic"
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="string",
  *     description="Body content of the Community Topic"
  *   ),
  * 	@SWG\Property(
  * 	  property="comment_count",
  * 	  type="integer",
  * 	  description="Number of comments on the Community Topic"
  * 	),
  * 	@SWG\Property(
  * 	  property="community_category_id",
  * 	  type="integer",
  * 	  description="ID of the Group the Community Topic belongs to"
  * 	),
  * 	@SWG\Property(
  * 	  property="community_category_name",
  * 	  type="string",
  * 	  description="Name of the Group the Community Topic belongs to"
  * 	),
  * 	@SWG\Property(
  * 	  property="group",
  * 	  type="string",
  * 	  description="Slug of the Group the Community Topic belongs to"
  * 	),
  * 	@SWG\Property(
  * 	  property="is_new",
  * 	  type="boolean",
  * 	  description="Indicates if the Community Topic is new"
  * 	),
  * 	@SWG\Property(
  * 	  property="created",
  * 	  type="integer",
  * 	  description="Timestamp of when the Community Topic was created"
  * 	),
  * 	@SWG\Property(
  * 	  property="changed",
  * 	  type="integer",
  * 	  description="Timestamp of when the Community Topic was last updated"
  * 	),
  * 	@SWG\Property(
  * 	  property="last_activity",
  * 	  type="integer",
  * 	  description="Timestamp of when the last activity on the Community Topic"
  * 	),
  * 	@SWG\Property(
  * 	  property="type",
  * 	  type="string",
  * 	  description="Indicates the type of entity this is"
  * 	),
  * )
  *
  */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $intFormatter = array($this, 'intval');

    $public_fields_extend = array(
      'body' => array(
        'property' => 'body',
        'sub_property' => 'value',
        'process_callbacks' => array( array( $this, 'stripTags' ) )
      ),
      'comment_count' => array(
        'property' => 'comment_count',
        'process_callbacks' => array( $intFormatter )
      ),
      'community_category_id' => array(
        'property' => 'taxonomy_forums',
        'sub_property' => 'tid'
      ),
      'community_cagetory_name' => array(
        'property' => 'taxonomy_forums',
        'sub_property' => 'name'
      ),
      'group' => array(
        'property' => 'taxonomy_forums',
        'sub_property' => 'url',
        'process_callbacks' => array(array($this, 'getGroupSlug'))
      ),
      'is_new' => array( 'callback' => array( $this, 'isNew' ) ),
      'created' => array(
        'property' => 'created',
        'process_callbacks' => array( $intFormatter )
      ),
      'changed' => array(
        'property' => 'changed',
        'process_callbacks' => array( $intFormatter )
      ),
      'last_activity' => array(
        'callback' => array( $this, 'lastActivity' )
      ),
      'status' => array(
        'property' => 'status'
      ),
      'type' => array(
        'callback' => array($this, getType)
      )
    );


    return array_merge($public_fields, $public_fields_extend);
  }

//Commented out part of H sprint since we are not retrieving data now. we can enable this if impliment this feature in future.
  /*protected function viewCount($wrapper) {
    return intval(db_select('node_counter')
      ->fields('node_counter', array('totalcount'))
      ->condition('nid', intval($wrapper->nid->value()))
      ->execute()
      ->fetchCol()[0]);
  }*/

 
  public function stripTags($value) {
   $value = parent::stripTags($value);
    $newValue = str_replace("<div><br></div>", "<br>", $value);
    $newValue = str_replace("<div><br /></div>", "<br>", $newValue);
    $newValue = str_replace("</p>", "<br>", str_replace("<p>", "", $newValue));
    $newValue = str_replace("</div>", "<br>", str_replace("<div>", "", $newValue));
    return $newValue;
  }

  protected function getType() {
    return 'topic';
  }

  protected function getGroupSlug($url) {
    $slug = explode('/', $url);
    return $slug[count($slug) - 1];
  }

  protected function isNew($wrapper) {
    $info = array(
      'property' => 'nid',
      'wrapper_method' => 'value'
    );

    $nid = $this->getValueFromProperty($wrapper, $wrapper->nid, $info, NULL);

    $history = _forum_user_last_visit($nid);
    $new_replies = comment_num_new($nid, $history);
    return $new_replies || ($this->lastActivity($wrapper) > $history);
  }

  protected function lastActivity($wrapper) {
    $nid = $wrapper->nid->value();
    $changed = $wrapper->changed->value();

    $last_activity = intval(db_select('node_comment_statistics', 'ncs')
      ->fields('ncs', array('last_comment_timestamp'))
      ->condition('nid', $nid, '=')
      ->execute()
      ->fetchField());

    return $last_activity > $changed ? $last_activity : $changed;
  }

  protected function queryForListSort(\EntityFieldQuery $query) {
    $sorts = $this->parseRequestForListSort();

    if(isset($sorts['last_activity'])) {
      $this->request['sort'] = str_replace(array('-last_activity', 'last_activity'), '', $this->request['sort']);
      $this->request['sort'] = str_replace(',,', ',', $this->request['sort']);

      parent::queryForListSort($query);

      $this->request['sort'] .= strlen($this->request['sort']) > 0 ? ',' : '';
      $this->request['sort'] .= $sorts['last_activity'] === 'DESC' ? '-' : '';
      $this->request['sort'] .= 'last_activity';
    } else {
      parent::queryForListSort($query);
    }
  }

  protected function queryForListPagination(\EntityFieldQuery $query) {
    // Get the sorting options from the request object.
    $sorts = $this->parseRequestForListSort();

    if(!empty($sorts) && is_null($sorts['last_activity'])) {
      list($offset, $range) = $this->parseRequestForListPagination();
      $query->range($offset, $range);
    }
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
   *   path="/topics",
   *   @SWG\Get(
   *     tags={"Communities"},
   *     summary="Returns all available Community Topics",
   *     @SWG\Response(
   *       response=200,
   *       description="List of Community Topics",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Topics")
   *         )
   *       )
   *     )
   *   ),
      @SWG\Post(
        tags={"Communities"},
        summary="Creates a new Community Topic",
        consumes={"application/json"},
        @SWG\Parameter(
          name="group",
          in="formData",
          type="integer",
          description="ID of the Community Group",
          required=true
        ),
        @SWG\Parameter(
          name="label",
          in="formData",
          type="string",
          description="Title of the Community Group",
          required=true
        ),
        @SWG\Parameter(
          name="body",
          in="formData",
          type="string",
          description="Body content of the Community Group",
          required=true
        ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of Community Topics",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/Topics")
   *         )
   *       )
   *     )
      )
   * )
   *
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

    if (empty($result[$entity_type])) {
      return array();
    }

    $ids = array_keys($result[$entity_type]);

    // Pre-load all entities if there is no render cache.
    $cache_info = $this->getPluginKey('render_cache');
    if (!$cache_info['render']) {
      entity_load($entity_type, $ids);
    }

    // Get the sorting options from the request object.
    $sorts = $this->parseRequestForListSort();

    if(empty($sorts) || isset($sorts['last_activity'])) {
      list($offset, $range) = $this->parseRequestForListPagination();
      $query = db_select('node_comment_statistics', 'ncs');
      $query->join('node', 'n', 'n.nid = ncs.nid');
      $query->fields('ncs', array('nid'));
      $query->condition('ncs.nid', $ids, 'IN');
      $query->addExpression('GREATEST(n.changed, ncs.last_comment_timestamp)', 'last_activity');
      $query->orderBy('last_activity', 'DESC');
      //$query->range($offset, $range);
      $results=$query->execute()
        ->fetchAll();
      $ids = [];

      foreach ($results as $result) {
        $ids[] = intVal($result->nid);
      }

    }

    $return = array();

    // If no IDs were requested, we should not throw an exception in case an
    // entity is un-accessible by the user.
    foreach ($ids as $id) {
      if ($row = $this->viewEntity($id)) {
        $return[] = $row;
      }
    }

    return $return;
  }

  public function entityPreSave($wrapper) {
    parent::entityPreSave($wrapper);
    $wrapper->status->set(1);
  }
}
