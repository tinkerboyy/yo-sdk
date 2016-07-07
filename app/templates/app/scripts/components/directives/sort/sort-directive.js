define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('SortDirectiveController', function($scope, $filter) {
        $scope.sortCollection = function() {
          var sortedCollection,
            sortOption = $filter('filter')($scope.sortOptions, { field: $scope.currentSort.field }, true)[0],
            sortExpression = $scope.currentSort.field;

          if (sortOption.getSortValue) {
            sortExpression = sortOption.getSortValue;
          }

          sortedCollection = $filter('orderBy')($scope.collection, sortExpression, $scope.currentSort.reverseOrder);

          if ($scope.callback) {
            $scope.callback(sortedCollection);
          }

          if ($scope.target) {
            $scope.target = sortedCollection;
          }
        };

        $scope.changeSortField = function(field) {
          var sortOption = $filter('filter')($scope.sortOptions, { field: field }, true)[0];

          //If we're changing which field we're sorting then set reverseOrder to the default order for this field
          //If we're sorting by the same field this means the user clicked the same sort option twice so switch sort order
          if ($scope.currentSort.field !== field) {
            $scope.currentSort.reverseOrder = sortOption.defaultOrder;
          } else {
            $scope.currentSort.reverseOrder = !$scope.currentSort.reverseOrder;
          }

          $scope.currentSort.field = field;
          $scope.sortCollection();
        };
      })
      .directive('agSort', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'SortDirectiveController',
          templateUrl: 'scripts/components/directives/sort/sort-button.html',
          scope: {
            currentSort: '=',
            sortOptions: '=',
            collection: '=',
            callback: '=?',
            target: '=?'
          },
          link: function($scope) {
            $scope.$watch('collection', function() {
              $scope.sortCollection();
            });
          }
        };
      });
  }
);
