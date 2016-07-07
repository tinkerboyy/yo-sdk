/**
 * Created by Madhukar on 10/7/15.
 */
define(
  [
    'angular',
    'components/components-module',
    'components/directives/accordion-select/accordion-select-directive'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('MyListCtrl', function($scope, DataService, AGService) {
        $scope.id = 'my-connections';
        $scope.model = { expanded: true };
        var ids = AGService.data.user.preferences.follow.user;
        $scope.watching = AGService.data.user.preferences.follow.user;

        $scope.$watch('watching', function() {
          if (ids.length > 0) {
            $scope.processing = true;
            DataService.User.get({ id: ids }, function(data) {
              $scope.collection = $scope.connections = data.data;
              $scope.$emit('agContentUpdated');
              $scope.processing = false;
            });
          } else {
            $scope.collection = $scope.connections = [];
          }

        }, true);
      })
      .directive('agMyConnections', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'MyListCtrl',
          templateUrl: 'scripts/components/directives/my-connections/my-connections.html'
        };
      });
  }
);
