<?php
  define('DRUPAL_ROOT', './');
  require_once('./includes/bootstrap.inc');
  require_once("./includes/common.inc");
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  //Get path if redirected to login page
  $path = isset($_GET['url']) ? $_GET['url'] : '/app/#/';

  //Check for public user cookie
  $username = $_COOKIE['uid'];

  if (!$username) {
    $username = md5($_SERVER['REMOTE_ADDR'] . time() . rand(0, 100000));
    $role = user_role_load_by_name('Public User');
    $role = $role->rid;
    $user = array(
      'name' => $username,
      'pass' => $username,
      'mail' => $username . '@example.com',
      'status' => 1,
      'ini' => $username . '@example.com',
      'roles' => array(
        DRUPAL_AUTHENTICATED_RID => TRUE,
        $role => TRUE
      )
    );
    user_save('', $user);
    setcookie('uid', $username);
  }

  $username= str_replace(' ', '', $username);
  $uid = user_authenticate($username, $username);
  if ($uid) {
    $obj = array('uid' => $uid, 'redirect' => $path);
    user_login_submit(array(), $obj);
  }

  //redirect the user to their original destination
  header("Location: $path");

  ?>
