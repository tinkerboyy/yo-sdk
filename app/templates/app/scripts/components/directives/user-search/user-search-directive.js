/**
 * Created by Madhukar on 10/23/15.
 */
define(
  [
    'angular',
    'angularStrap',
    'angularStrapTpl',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('UserSearchCtrl', function($scope, $modal, DataService, $agLoader, $filter) {

        $scope.searchText = '';
        $scope.loader = $agLoader.getLoader(true);
        var users = [];
        $scope.users = [];
        $scope.processing = true;

        DataService.User.query(function(data) {
          users = $filter('filter')(data.data, { id: '' });
          $scope.loader.finish($scope.loader.requests[0]);
          $scope.processing = false;
        });

        $scope.showUserSearchModal = function() {
          $modal({
            template: 'scripts/components/directives/user-search/user-search-modal.html',
            scope: $scope,
            backdrop: 'static',
            show: true
          });
        };

        $scope.setUsers = function(users) {
          $scope.pageUsers = users;
        };

        $scope.searchResults = function(search) {
          $scope.users = search ? $filter('filter')(users, search) : [];
          if ($scope.users.length === 0) {
            $scope.setUsers([]);
          }
        };
      })
      .directive('agUserSearch', function() {
        return {
          restrict: 'EA',
          replace: true,
          scope: {},
          controller: 'UserSearchCtrl',
          templateUrl: 'scripts/components/directives/user-search/user-search.html'
        };
      });
  }
);
