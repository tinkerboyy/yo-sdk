<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulSowlTypeaheadResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'slid',
    );

    return $public_fields;
  }

  /**
    * Returns search suggestions 

    @SWG\Definition(
      definition="SearchSuggestion",
      @SWG\Property(
        type="string",
        property="query",
        description="Search term" 
      ),
      @SWG\Property(
        type="string",
        property="results_returned",
        description="Number of results returned for that search term at last use" 
      ),
      @SWG\Property(
        type="string",
        property="count",
        description="Number of times this term has been used" 
      ),
    )
    @SWG\Path(
      path="/sowl-typeahead",
      @SWG\Get(
        tags={"Search", "SOWL"},
        summary="Returns search terms to use in building a search typeahead dropdown",
        @SWG\Response(
          response=200,
          description="List of commonly used search terms",
          @SWG\Schema(
            type="object",
            @SWG\Property(
              property="data",
              type="array",
              @SWG\Items(
                ref="#/definitions/SearchSuggestion"
              )
            )
          )
        )
      )
    )
   */
  public function index() {

    $query = db_query('SELECT DISTINCT(search_query) as query, MAX(search_results_count) as results_returned, count(search_query) AS count
          FROM {search_logging}
          GROUP BY search_query
          ORDER BY search_results_count DESC, count DESC')->fetchAll();

    return $query;
  }
}
