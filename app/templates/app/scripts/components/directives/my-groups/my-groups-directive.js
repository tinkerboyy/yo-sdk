/**
 * Created by Madhukar on 9/16/15.
 */

define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('MyGroupsController', function($scope, DataService, AGService) {
        $scope.followed = AGService.data.user.preferences.follow.group;
        $scope.$watch('followed', function() {
          if ($scope.followed.length > 0) {
          DataService.Communities.get({ id: $scope.followed }, function(data) {
            $scope.groups = data.data;
            $scope.$emit('agContentUpdated');
          });
          } else {
            $scope.groups = [];
          }
        }, true);

        $scope.changeGroup = function(group) {
          $scope.$emit('myGroupChange', group);
        };

      })
      .directive('agMyGroups', function() {
        return {
          restrict: 'EA',
          controller: 'MyGroupsController',
          scope: {
            title: '@?',
            linkAction: '=',
            community: '='
          },
         templateUrl: 'scripts/components/directives/my-groups/my-groups.html'
        };
      });
  }
);
