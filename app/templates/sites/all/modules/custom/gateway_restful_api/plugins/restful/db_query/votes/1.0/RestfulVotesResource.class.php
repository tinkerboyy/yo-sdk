<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulVotesResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  /**
  *
  * @SWG\Definition(
  *   definition="Votes",
  *   @SWG\Property(
  *     property="itemId",
  *     type="integer",
  *     description="Item Id of votes"
  *   ),
  *   @SWG\Property(
  *     property="type",
  *     type="string",
  *     description="Provides the type of Vote (Solution, sowl, community, etc.,)"
  *   ),
  *   @SWG\Property(
  *     property="count",
  *     type="integer",
  *     description="Provides the total number of Votes (Solution, sowl, community, etc.,)"
  *   ),
  *   @SWG\Property(
  *     property="Votes",
  *     type="integer",
  *     description="Provides the number of Votes (Solution, sowl, community, etc.,)"
  *   ),
  *   @SWG\Property(
  *     property="myVote",
  *     type="integer",
  *     description="Provides the number of Votes per User (Solution, sowl, community, etc.,)"
  *   )
  * )
  */

  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'id',
    );

    $public_fields['type'] = array(
      'property' => 'type',
    );

    $public_fields['itemId'] = array(
      'property' => 'itemId',
    );

    $public_fields['vote'] = array(
      'property' => 'vote',
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function index() {

    $query = db_query('SELECT itemId, type, SUM(vote) AS votes, COUNT(*) AS count FROM ag_votes GROUP BY type, itemId ORDER BY votes DESC')->fetchAll();

    return $query;
  }

  /**
  * Get a list of entities.
  *
  * @return array
  *   Array of entities, as passed to RestfulEntityBase::viewEntity().
  *
  * @throws RestfulBadRequestException
  *
  *  @SWG\Path(
  *    path="/Votes/{type}/{id}",
  *     @SWG\Get(
  *     tags={"Votes"},
  *     summary="Retrieves Votes information",
  *     @SWG\Parameter(
  *      name="type",
  *      description="The type that needs to be fetched. Use 'solution' for testing.",
  *      in="path",
  *      required=true,
  *      type="string",
  *      @SWG\Schema(ref="#/definitions/Votes"),
  *     ),
  *     @SWG\Parameter(
  *      name="id",
  *      description="The Id that needs to be fetched. Use 105 for testing.",
  *      in="path",
  *      required=true,
  *      type="string",
  *      @SWG\Schema(ref="#/definitions/Votes"),
  *     ),
  *     @SWG\Response(
  *     response=400,
  *     description="Invalid ID supplied"
  *     ),
  *    @SWG\Response(
  *     response=404,
  *     description="Vote Information is not found"
  *     )
  *   )
  * )
  *
  **/

  protected function getQuery($type, $itemId = NULL) {
    global $user;
    $query = db_select('ag_votes', 'v')
      ->fields('v', array('itemId', 'type'))
      ->condition('type', $type)
      ->groupBy('itemId')
      ->orderBy('votes', 'DESC');

    if($itemId) $query->condition('itemId', $itemId);

    $query->addExpression('COUNT(*)', 'count');
    $query->addExpression('SUM(vote)', 'votes');

    $results = $query->execute()->fetchAll();


    //Get user vote for this item
    if ($itemId) {
      if (count($results) === 0) $results = array(array("itemId"=>$itemId, "type"=>$type, "votes"=>0, "Count"=>0));

      $query = db_select('ag_votes', 'v')
        ->fields('v', array('vote'))
        ->condition('uid', $user->uid)
        ->condition('itemId', $itemId)
        ->execute()
        ->fetchAll();

      $results[0]->myVote = count($query) > 0 ? $query[0]->vote : NULL;
    }

    return $results;
  }

  public function view($type) {
    $data = explode('/', $type);
    $type = $data[0];
    $itemId = null;

    if(count($data) == 2) $itemId = (int)$data[1];

    return $this->getQuery($type, $itemId);
  }

  public function create() {
    global $user;
    $request = $this->getRequest();
    static::cleanRequest($request);

    $vote = $request['vote'] === 'up' ? 1 : -1;

    $query = db_select('ag_votes', 'v')
      ->fields('v', array())
      ->condition('uid', $user->uid)
      ->condition('type', $request['type'])
      ->condition('itemId', $request['itemId'])
      ->execute()
      ->fetchAll();

    if(count($query) == 0) {
      $sql = db_insert('ag_votes')
        ->fields(
          array(
            'uid'     => $user->uid,
            'itemId'  => $request['itemId'],
            'type'    => $request['type'],
            'vote'    => $vote
          )
        );

        $sql->execute();
    }
    else {
      $currentVote = $query[0];
      if ($currentVote->vote != $vote) {
        db_delete('ag_votes')
          ->condition('uid', $user->uid)
          ->condition('type', $request['type'])
          ->condition('itemId', $request['itemId'])
          ->execute();
      }
      else {
        db_update('ag_votes')
          ->condition('uid', $user->uid)
          ->condition('type', $request['type'])
          ->condition('itemId', $request['itemId'])
          ->fields(
            array(
              'vote' => $vote
            )
          )
          ->execute();
      }

    }

    return $this->getQuery($request['type'], $request['itemId']);
  }
}
