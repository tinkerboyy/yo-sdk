define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('HelpController', function($scope, $filter) {
        $scope.init = function() {
          if ($scope.collection && $scope.collection.length) {
            $scope.helpItem = $filter('filter')($scope.collection, { path: $scope.item })[0];
          }
        };

        $scope.init();
      })
      .directive('agHelp', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'HelpController',
          templateUrl: 'scripts/components/directives/help/help.html',
          scope: {
            item: '=',
            collection: '='
          }
        };
      });
  }
);
