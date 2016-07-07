<?php

/**
 * @file
 * Contains \RestfulEntityTaxonomyTermCommunities.
 */
class RestfulEntityTaxonomyTermCommunities extends \AGRestfulEntityBaseTaxonomyTerm {

  /**
  *
  * @SWG\Definition(
  *   definition="Communities",
  *   @SWG\Property(
  *     property="revision",
  *     type="object",
  *     ref="#/definitions/DrupalRevision",
  *     description="Revision information"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Title of Group"
  *   ),
  * 	@SWG\Property(
  * 	  property="body",
  * 	  type="string",
  * 	  description="Body text of Group"
  * 	)
  * )
*/

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $intFormatter = array($this, 'intval');

    $public_fields_extend = array(
      'url' => array(
        'property' => 'url'
      ),
      'slug' => array(
        'property' => 'url',
        'process_callbacks' => array(array($this, 'makeSlug'))
      ),
      'description' => array(
        'property' => 'description'
      ),
      'icon' => array(
        'property' => 'field_icon'
      ),
      'weight' => array(
      	'property' => 'weight',
        'process_callbacks' => array( $intFormatter )
      ),
      'topic_count' => array(
        'callback' => array($this, 'topicCount')
      ),
      'new_topic_count' => array(
        'callback' => array($this, 'newTopicsCount')
      ),
      'post_count' => array(
        'callback' => array($this, 'postCount')
      )
    );

    return array_merge($public_fields, $public_fields_extend);
  }

  protected function makeSlug($url) {
    $slug = explode('/', $url);
    return $slug[count($slug) - 1];
  }

  protected function intval($value = NULL) {
    return $value == NULL ? NULL : intval($value);
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
     *   path="/communities",
     *   @SWG\Get(
     *     tags={"Communities"},
     *     summary="Retrieve all Community Groups",
     *     @SWG\Parameter(
     *       name="Group",
     *       description="Name of Group",
     *       in="path",
     *       required=false,
     *       type="string"
     *     ),
     *     @SWG\Response(
     *       response=200,
     *       description="List of community Groups",
     *       @SWG\Schema(
     *         type="object",
     *         @SWG\Property(
     *         	 property="data",
     *         	 type="array",
     *           @SWG\Items(ref="#/definitions/Communities")
     *         )
     *       )
     *     )
     *   )
     * )
     *
   *
   */

  protected function relatedTopicIds($wrapper) {
    $info = array(
      'property' => 'tid',
      'wrapper_method' => 'value'
    );
    $id = $this->getValueFromProperty($wrapper, $wrapper->tid, $info, NULL);

    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'forum')
      ->fieldCondition('taxonomy_forums', 'tid', $id)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->execute();

    if(isset($result['node'])) {
      return array_keys($result['node']);
    }

    return array();
  }

  protected function topicCount($wrapper) {
    return count($this->relatedTopicIds($wrapper));
  }

  protected function newTopicsCount($wrapper) {
    $info = array(
      'property' => 'tid',
      'wrapper_method' => 'value'
    );

    $id = $this->getValueFromProperty($wrapper, $wrapper->tid, $info, NULL);

    return intVal(_forum_topics_unread($id, $this->getAccount()->uid));
  }

  protected function postCount($wrapper) {
    $relatedTopicIds = $this->relatedTopicIds($wrapper);
    $topic_count = $this->topicCount($wrapper);
    if($topic_count > 0) {
      $query = db_select('node_comment_statistics', 'ncs');
      $query->addExpression('SUM(ncs.comment_count)', 'community_comment_count');
      $query->fields(array('community_comment_count'));
      $query->condition('nid', $relatedTopicIds);
      $result = $query->execute();

      $comment_count = intVal($result->fetchField());

      if(isset($comment_count)) {
        return $comment_count + $topic_count;
      }
    }

    return $topic_count;
  }

}
