<?php


/**
 * @file
 * Contains RestfulHistoryResource.
 */

class RestfulHistoryResource extends \RestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

   /**
  *
  * @SWG\Definition(
  *   definition="History",
  *   @SWG\Property(
  *     property="nid",
  *     type="string",
  *     description="Drupal node id"
  *   ),
  *   @SWG\Property(
  *     property="uid",
  *     type="string",
  *     description="Drupal user id"
  *   ),
  *   @SWG\Property(
  *     property="timestamp",
  *     type="string",
  *     description="Timestamp of user access to specific node"
  *   ),
  * )
  *
  */

  public function publicFieldsInfo() {
    
    $public_fields['nid'] = array(
      'property' => 'nid',
    );

    $public_fields['uid'] = array(
      'property' => 'uid',
    );

    $public_fields['timestamp'] = array(
      'property' => 'timestamp',
    );

    return $public_fields;
  }

  /**
   *
   * @SWG\Path(
   *   path="/history/",
   *   @SWG\Get(
   *     tags={"history"},
   *     summary="Performs a list of user ids and timestamps of the specific nodes accessed by users",
   *     @SWG\Response(
   *       response=200,
   *       description="List of users with timestamps of node access",
   *       @SWG\Schema(
   *         type="object",
   *          @SWG\Property(
   *            property="data",
   *            type="array",
   *            @SWG\Items(ref="#/definitions/History")
   *          )
   *       )
   *     )
   *   )
   * )
   */

  

  public function create() {

    $table = $this->getTableName();

    $uid = $GLOBALS['user']->uid;
    $timestamp = REQUEST_TIME;

    $request = $this->getRequest();
    static::cleanRequest($request);
    $data = $request;

    $record = array(
      'uid' => $uid,
      'nid' => $data['nid'],
      'timestamp' => $timestamp,
    );

    db_merge('history')
      ->key(array('nid' => intVal($data['nid']), 'uid' => $uid))
      ->fields($record)
      ->execute();

    db_merge('node_counter')
      ->key(array('nid' => intVal($data['nid'])))
      ->fields(array(
        'daycount' => 1,
        'totalcount' => 1,
        'timestamp' => REQUEST_TIME,
      ))
      ->expression('daycount', 'daycount + 1')
      ->expression('totalcount', 'totalcount + 1')
      ->execute();

    $data['id'] = $upid;

    return array($data);

  }
 }
