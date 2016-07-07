define(
  [
    'angular',
    'angularStrap',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('ShareController', function($scope, $location, $modal) {
        $scope.showShare = false;
        $scope.doShare = function() {
          $scope.showShare = !$scope.showShare;
          $scope.shareUrl = $scope.url ? $location.absUrl().replace($location.url(), $scope.url) : $location.absUrl();
        };

        $scope.selectUrl = function($event) {
          $event.target.select();
        };

        $scope.setUrl = function() {
          var url = $scope.link ? $scope.link : $location.url() + ($scope.searchParams || '');
          $location.url(url);
        };

        $scope.addToProject = function() {
          var item = {
            data: $location.url(),
            id: Date.now().toString().substr(0, 10)
          };

          $scope.showShare = false;

          $scope.addToProjectDetails = {
            item: item,
            itemNameField: 'name',
            itemType: $scope.type
          };
          $modal({
            title: 'Add this solution to a project',
            scope: $scope,
            templateUrl: 'scripts/components/directives/add-to-project/add-to-project-modal.html',
            show: true
          });
        };

      })
      .directive('agShare', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'ShareController',
          templateUrl: 'scripts/components/directives/share/share.html',
          scope: {
            params: '=',
            paramsMap: '=',
            title: '@',
            type: '@',
            hideAddToProject: '=',
            url: '='
          }
        };
      });
  }
);
