<?php
  define('DRUPAL_ROOT', '../../');
  $base_url = stripos($_SERVER['SERVER_PROTOCOL'], 'HTTPS') >= 0 ? 'https://' : 'http';
  $base_url .= $_SERVER['SERVER_NAME'];
  require_once('../../includes/bootstrap.inc');
  require_once("../../includes/common.inc");
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  $publicUser = array_search('Public User', $GLOBALS['user']->roles);
?>
<!doctype html>
<html lang="en">
  <head>
    <!-- build:appVersion -->
    <!-- endbuild -->
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <meta http-equiv="cache-control" content="max-age=0" />
    <meta http-equiv="cache-control" content="no-cache" />
    <meta http-equiv="expires" content="0" />
    <meta http-equiv="expires" content="Tue, 01 Jan 1980 1:00:00 GMT" />
    <meta http-equiv="pragma" content="no-cache" />

    <title>Acquisition Gateway</title>
    <link rel="shortcut icon" href="/sites/default/files/favicon.ico" type="image/vnd.microsoft.icon" />
      <!-- BOWER STUFF -->
    <!-- build:vendorcss -->
    <link rel="stylesheet" href="assets/css/vendor.css">
    <!-- endbuild -->
    <!-- build:maincss -->
    <link rel="stylesheet" href="assets/css/main.css">
    <!-- endbuild -->
    <link rel="stylesheet" href="../../sites/all/themes/bootstrap/css/cap-os.css">
    <link rel="stylesheet" href="assets/fonts/myriad-pro-bold/MyriadPro-Bold.css">
  </head>
  <body ng-controller="AppController">
    <div ng-cloak>
      <a href="#content" class="sr-only">Skip to content</a>
      <ag-navigation data-name="'main-menu'"></ag-navigation>
      <ag-banner></ag-banner>
      <toasty></toasty>
      <div class="container-fluid" ng-if="authenticated && dataLoader.requests.length === 0" ng-view></div>

      <ag-footer></ag-footer>
    </div>

    <div class="loader" ng-show="!authenticated || dataLoader.requests.length > 0" ng-cloak>
      <h1><center>Loading ...</center></h1>
    </div>

    <div class="help-container"></div>

      <!-- build:js -->
      <script src="vendor/requirejs/require.js?version=1.0" data-main='scripts/<?php if ($publicUser) echo 'public-'; ?>main'></script>
      <!-- endbuild -->
      <!-- Google Analytics -->
      <script>
      (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
      (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
      m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
      })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
      </script>
      <!-- End Google Analytics -->
      <noscript>Your browser does not support javascript or it is not enabled.</noscript>
  </body>
</html>
