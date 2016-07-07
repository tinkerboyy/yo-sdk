define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
     angular.module('gateways.components')
      .controller('searchCtrl', function ($scope, $timeout) {

        $scope.doSearch = function(e) {
          e.preventDefault();

          // If filters are open then trigger click on filter button to close
          if ($scope.filterExpanded) {
            $timeout(function () {
              angular.element(document.getElementById('search-filter-toggle')).triggerHandler('click');
              $scope.filterExpanded = false;
            }, 0);
          }
          $scope.action($scope.search, $scope.selectedFilters);
        };

        $scope.getRows = function(number) {
          if (number) {
            return new Array(Math.ceil(number / 3));
          }
        };

        /**
         * Checkboxes are bound to this function, when clicked this will toggle the selection
         * of a single filter
         */
        $scope.toggleSelection = function(filterId) {
          var i = $scope.selectedFilters.indexOf(filterId);

          if (i > -1) {
            $scope.selectedFilters.splice(i, 1);
          } else {
            $scope.selectedFilters.push(filterId);
          }
        };
      })
      .directive('agSearch',function () {
        return {
          restrict: 'AE',
          replace: true,
          controller:'searchCtrl',
					scope: {
            action: '=',
            search: '=',
            filters: '=',
            selectedFilters: '=',
            suggestions: '='
          },
          templateUrl: 'scripts/components/directives/search/search.html'
        };
      });
  }
);
