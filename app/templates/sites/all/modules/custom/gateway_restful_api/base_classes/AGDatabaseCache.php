<?php

class AGDatabaseCache extends DrupalDatabaseCache
{

  function set($cid, $data, $expire = CACHE_PERMANENT) {
    if (!in_array($expire, array(CACHE_PERMANENT, CACHE_TEMPORARY))) {
      $expire = time() + $expire;
    }
    return parent::set($cid, $data, $expire);
  }

  function getMultiple(&$cids) {
    try {
      // Garbage collection necessary when enforcing a minimum cache lifetime.
      $this->garbageCollection($this->bin);

      // When serving cached pages, the overhead of using db_select() was found
      // to add around 30% overhead to the request. Since $this->bin is a
      // variable, this means the call to db_query() here uses a concatenated
      // string. This is highly discouraged under any other circumstances, and
      // is used here only due to the performance overhead we would incur
      // otherwise. When serving an uncached page, the overhead of using
      // db_select() is a much smaller proportion of the request.
      $expireWhere = ' AND expire >= :now ';
      $now = time();
      $sql = 'SELECT cid, data, created, expire, serialized FROM {' . db_escape_table($this->bin) . '} WHERE cid IN (:cids) '. $expireWhere;
      $result = db_query($sql, array(':cids' => $cids, ':now' => $now));
      $cache = array();
      foreach ($result as $item) {
        $item = $this->prepareItem($item);
        if ($item) {
          $cache[$item->cid] = $item;
        }
      }
      $cids = array_diff($cids, array_keys($cache));
      return $cache;
    }
    catch (Exception $e) {
      // If the database is never going to be available, cache requests should
      // return FALSE in order to allow exception handling to occur.
      return array();
    }
  }
}
