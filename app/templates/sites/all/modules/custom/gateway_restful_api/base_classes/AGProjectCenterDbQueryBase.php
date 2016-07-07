<?php

/**
 * @file
 * Contains AGProjectCenterBase
 */

require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

class AGProjectCenterDbQueryBase extends \RestfulDataProviderDbQuery {
  use AGPublicUserAccessCheck;

  public function checkAccess($id) {
    $count = count($this->getQuery()
      ->condition($this->tableName . '.id', $id)
      ->execute()
      ->fetchAll());

    if($count === 0) {
      throw new \RestfulForbiddenException();
    }
  }

  public function getIdColumn() {
    return is_array($this->idColumn) ? $this->idColumn : array($this->idColumn);
  }

  public function publicFieldsInfo() {
    $intFormatter = array( array($this, 'intval') );

    return array(
      'id' => array(
        'property' => 'id',
        'column_for_query' => $this->tableName . '.id'
      ),
      'name' => array(
        'property' => 'name',
        'column_for_query' => $this->tableName . '.name'
      ),
      'uid' => array(
        'property' => 'uid',
        'column_for_query' => $this->tableName .'.uid',
        'create_or_update_passthrough' => TRUE
      ),
      'created' => array(
        'property' => 'created',
        'column_for_query' => $this->tableName . '.created',
        'process_callbacks' => $intFormatter,
        'create_or_update_passthrough' => TRUE
      ),
      'changed' => array(
        //reference name of item
        'property' => 'changed',
        'column_for_query' => $this->tableName . '.updated',
        'process_callbacks' => $intFormatter,
        'create_or_update_passthrough' => TRUE
      ),
      'status' => array(
        'property' => 'status',
        'column_for_query' => $this->tableName . '.status'
      )
    );
  }

  public function intval($value) {
    return isset($value) ? intval($value) : $value;
  }

  /**
   * @Override
   * {@inheritdoc}
   */
  public function view($ids) {
    return $this->viewMultiple(explode(',', $ids));
  }

   /**
   * @Override
   * Create an item from the request object.
   *
   * @return array
   *   The structured array for the item ready to be rendered.
   */
  /**
   * {@inheritdoc}
   */
  public function create() {
    $request = $this->getRequest();
    static::cleanRequest($request);
    $save = FALSE;

    $public_fields = $this->getPublicFields();
    $id_columns = $this->getIdColumn();

    $record = array(
      'uid' => $this->getAccount()->uid,
      'created' => REQUEST_TIME,
      'updated' => REQUEST_TIME
    );

    foreach ($public_fields as $public_field_name => $info) {
      // Ignore passthrough public fields.
      // If this is the primary field, skip.
      if (!empty($info['create_or_update_passthrough']) || $this->isPrimaryField($info['property'])) {
        continue;
      }

      if (isset($request[$public_field_name])) {
        $record[$info['property']] = $request[$public_field_name];
      }

      $save = TRUE;
    }

    // No request was sent.
    if (!$save) {
      throw new \RestfulBadRequestException('No valid values were sent with the request.');
    }
    // Once the record is built, write it and view it.
    if (drupal_write_record($this->getTableName(), $record)) {
      // Handle multiple id columns.
      $id_values = array();
      foreach ($id_columns as $id_column) {
        $id_values[$id_column] = $record[$id_column];
      }
      $id = implode(self::COLUMN_IDS_SEPARATOR, $id_values);

      return $this->view($id);
    }
    return;

  }

  /**
   * @Override
   * @param $full_replace is ignored
   *
   * {@inheritdoc}
   */
  public function update($id, $full_replace = FALSE) {
    // Build the update array.
    $this->checkAccess($id);
    $request = $this->getRequest();

    static::cleanRequest($request);
    $save = FALSE;
    $public_fields = $this->getPublicFields();

    $id_columns = $this->getIdColumn();

    $record = array( 'updated' => REQUEST_TIME );
    foreach ($public_fields as $public_field_name => $info) {
      // Ignore passthrough public fields.
      // If this is the primary field, skip.
      if (!empty($info['create_or_update_passthrough']) || $this->isPrimaryField($info['property'])) {
        continue;
      }

      if (isset($request[$public_field_name])) {
        $record[$info['property']] = $request[$public_field_name];
      }

      $save = TRUE;
    }

    // No request was sent.
    if (!$save) {
      throw new \RestfulBadRequestException('No valid values were sent with the request.');
    }

    // Add the id column values into the record.
    foreach ($this->getIdColumn() as $index => $column) {
      $record[$column] = current($this->getColumnFromIds(array($id), $index));
    }

    // Once the record is built, write it.
    if (!drupal_write_record($this->getTableName(), $record, $id_columns)) {
      throw new \RestfulServiceUnavailable('Record could not be updated to the database.');
    }

    // Clear the rendered cache before calling the view method.
    $this->clearRenderedCache(array(
      'tb' => $this->getTableName(),
      'cl' => implode(',', $this->getIdColumn()),
      'id' => $id,
    ));

    return $this->view($id);
  }


  /**
   * @Override
   * {@inheritdoc}
   */
  public function mapDbRowToPublicFields($row) {
    if ($this->getMethod() == \RestfulInterface::GET) {
      // For read operations cache the result.
      $output = $this->staticCache->get(__CLASS__ . '::' . __FUNCTION__ . '::' . $this->getUniqueId($row));
      if (isset($output)) {
        return $output;
      }
    }
    else {
      // Clear the cache if the request is not GET.
      $this->staticCache->clear(__CLASS__ . '::' . __FUNCTION__ . '::' . $this->getUniqueId($row));
    }
    $output = array();
    // Loop over all the defined public fields.
    foreach ($this->getPublicFields() as $public_field_name => $info) {
      $value = NULL;
      // If there is a callback defined execute it instead of a direct mapping.
      if ($info['callback']) {
        $value = static::executeCallback($info['callback'], array($row));
      }
      // Map row names to public properties.
      elseif ($info['property']) {
        $value = $row->{$info['property']};
      }

      // Execute the process callbacks.
      if ($info['process_callbacks']) {
        foreach ($info['process_callbacks'] as $process_callback) {
          $value = static::executeCallback($process_callback, array($value));
        }
      }

      $output[$public_field_name] = $value;
    }

    return $output;
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
  protected function queryForListPagination(\SelectQuery $query) {
    $request = $this->getRequest();
    if (!(isset($request['range']) && strcasecmp($request['range'], 'all') === 0)) {
      parent::queryForListPagination($query);
    }
  }

 /**
   * @Override
   * Get a basic query object.
   *
   * @return SelectQuery
   *   A new SelectQuery object for this connection.
   */
  protected function getQuery() {
    // get logged in user uid
    $query = parent::getQuery();
    $query->condition($this->tableName . '.uid', $this->getAccount()->uid);

    return $query;
  }

}
