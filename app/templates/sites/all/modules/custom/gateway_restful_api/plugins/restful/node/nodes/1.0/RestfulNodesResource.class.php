<?php

class RestfulNodesResource extends AGRestfulEntityBaseMultipleBundles {
  public function publicFieldsInfo(){
    $public_fields = parent::publicFieldsInfo();
    $intFormatter = array( $this, 'intval' );


     $public_fields['created'] = array(
      'property' => 'created',
      'create_or_update_passthrough' => TRUE
    );

    $public_fields['status'] = array(
      'property' => 'status',
      'create_or_update_passthrough' => TRUE
    );

    $public_fields['portfoliohallway'] = array(
      'property' => 'field_portfolio_category',
      'sub_property' => 'tid',
      'create_or_update_passthrough' => TRUE
    );

    $public_fields['expiration'] = array(
      'property' => 'field_expiration_date',
      'process_callbacks' => array($intFormatter)
    );

    return $public_fields;
  }
   
  protected function getBundles() {
    $request = $this->getRequest();

    static::cleanRequest($request);

    $allBundles = $this->bundles;
    $requestedBundles = explode(',', $request['bundles']);
    $bundles = array();

    foreach ($requestedBundles as $bundle) {
      if ($allBundles[$bundle]) {
        $bundles[$bundle] = $allBundles[$bundle];
      }
    }

    if (empty($bundles)) {
      return $allBundles;
    }

    return $bundles;
  }

  /**
   * Overrides RestfulEntityBase::getQueryForList().
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    $query->propertyCondition('status', NODE_PUBLISHED);
    $query->fieldCondition('field_expiration_date', 'value', date("Y-m-d"), '>');
    $query->addMetadata('account', user_load(1));


    return $query;
  }
   public function getList() {
    $return = parent::getList();
    //Sort results
    # get a list of sort columns and their data to pass to array_multisort
    $sort = array();
    foreach($return as $k=>$v) {
        $sort['weight'][$k] = $v['weight'];
        $sort['created'][$k] = $v['created'];
    }
    # sort by WEIGHT asc, then CREATED desc
    array_multisort($sort['weight'], SORT_ASC, $sort['created'], SORT_DESC,$return);
 
    return $return;
  }

   /**
   * @Override
   * Set correct page (i.e. range) for the query for list.
   *
   * Determine the page that should be seen. Page 1, is actually offset 0 in the
   * query range.
   *
   * @param \SelectQuery $query
   *   The query object.
   *
   * @throws \RestfulBadRequestException
   *
   * @see \RestfulEntityBase::getQueryForList
   */
  protected function queryForListPagination(\EntityFieldQuery $query) {
    $request = $this->getRequest();

    if (!(isset($request['range']) && strcasecmp($request['range'], 'all') === 0)) {
      parent::queryForListPagination($query);
    }
  }

  /**
   * @Override
   * Overrides the range parameter with the URL value if any.
   *
   * @throws RestfulBadRequestException
   */
  protected function overrideRange() {
    $request = $this->getRequest();
    if (!empty($request['range'])) {
      $url_params = $this->getPluginKey('url_params');
      if (!$url_params['range']) {
        throw new \RestfulBadRequestException('The range parameter has been disabled in server configuration.');
      }
      if (strcasecmp($request['range'], 'all') !== 0) {
        if (!ctype_digit((string) $request['range']) || $request['range'] < 1) {
          throw new \RestfulBadRequestException('"Range" property should be numeric and higher than 0.');
        }
        // If there is a valid range property in the request override the range.
        $this->setRange($request['range']);
      }
    }
  }

}
