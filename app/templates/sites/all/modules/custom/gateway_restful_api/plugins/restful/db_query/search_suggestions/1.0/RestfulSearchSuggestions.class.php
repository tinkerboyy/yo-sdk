<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulSearchSuggestions extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'slid',
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function index() {

    $query = db_query('SELECT DISTINCT(search_query) as query, MAX(search_results_count) as results_returned, count(search_query) AS count
          FROM {search_logging}
          GROUP BY search_query
          ORDER BY search_results_count DESC, count DESC')->fetchAll();

    return $query;
  }

  /**
    * Submits a new search term for entry into the suggestions list
    * @SWG\Path(
    *   path="/search-suggestions",
    *   @SWG\Post(
    *     tags={"Search"},
    *     consumes={"application/json"},
    *     @SWG\Parameter(
    *       name="search",
    *       type="string",
    *       in="formData",
    *       description="Search Term to add to Search Suggestions"
    *     ),
    *     @SWG\Response(
    *       response=200,
    *       description="Acknowleges suggestion was successfully added to list"
    *     )
    *   )
    * )
    */
  public function create() {
    global $user;
    $request = $this->getRequest();
    static::cleanRequest($request);

    //Search if the term already exists
    $results = db_select('search_logging', 's')
      ->fields('s', array())
      ->condition('uid', $user->uid)
      ->condition('search_query', $request['search'])
      ->execute()
      ->fetchAll();


    //If the term is not found, add it to the search logs
    if (count($results === 0)) {
      db_insert('search_logging')
        ->fields(
          array(
            search_query => $request['search'],
            uid => $user->uid,
            created => time()
          )
        )
        ->execute();
    }

    return $results;
  }
}
