define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('trust', function($sce) {
        return function(html) {
          if (html) {
            return $sce.trustAsHtml(html);
          }
        };
      });
});
