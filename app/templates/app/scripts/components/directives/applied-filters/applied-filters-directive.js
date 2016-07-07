define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .factory('$appliedFilters', function($filter) {
        var filterDisplayNames = {},
            filterGroups = [];
        /**
         * Sets the name that should display in Applied Filters list for the given filter group and value
         *
         * @param {string} filterGroup Group name supplied to addFilterGroup
         * @param {string|int} filterValue The value of the filter that should have this display name
         * @param {string} displayName User friendly display name for filter value
         */
        function addFilterDisplayName(filterGroup, filterValue, displayName) {
          if (typeof filterDisplayNames[filterGroup] === 'undefined') {
            filterDisplayNames[filterGroup] = {};
          }

          filterDisplayNames[filterGroup][filterValue] = displayName;
        }

        /**
         * Adds a filter group to the applied filters directive. Applied filter values will
         * be displayed grouped with other values from the same group. Each group will
         * be displayed in the order added to the applied filter directive.
         *
         * @param {string} filterGroup Name to identify group
         * @param {object} options     Options for group
         *   multiple - If the filter group allows multiple filter values selected at once
         *   value_is_object - If the filter value is an object rather than a scalar
         */
        function addFilterGroup(filterGroup, options) {
          var filterExists = $filter('filter')(filterGroups, { groupName: filterGroup });
          if (filterExists.length === 0) {
            filterGroups.push({
              groupName: filterGroup,
              options: options
            });
          }
        }

        return {
          filterDisplayNames: filterDisplayNames,
          filterGroups: filterGroups,
          addFilterDisplayName: addFilterDisplayName,
          addFilterGroup: addFilterGroup
        };
      })
      .controller('AppliedFiltersController', function($scope, $appliedFilters) {
        $scope.filterDisplayNames = $appliedFilters.filterDisplayNames;
        $scope.filterGroups = $appliedFilters.filterGroups;

        /**
         * Removes applied filter and calls optional callback to allow controller
         * using directive to perform any additional action after filter is removed
         *
         * @param  {string} filterGroup  Name of the filter group as supplied to $appliedFilters.addFilterGroup
         * @param  {string|int|object} filterOption Applied filter that we want to remove
         */
        $scope.removeAppliedFilter = function(filterGroup, filterOption) {
          var index;

          if (filterGroup.options.multiple) {
            if (filterGroup.options.value_is_object) {
              index = $scope.appliedFilters[filterGroup.groupName].map(function(sc) {return sc.id; }).indexOf(filterOption.id);
              if (index >= 0) {
                $scope.appliedFilters[filterGroup.groupName].splice(index, 1);
              }
            } else {
              index = $scope.appliedFilters[filterGroup.groupName].indexOf(filterOption);
              if (index >= 0) {
                $scope.appliedFilters[filterGroup.groupName].splice(index, 1);
              }
            }
          } else {
            $scope.appliedFilters[filterGroup.groupName] = null;
          }

          if ($scope.removeFilterCallback) {
            $scope.removeFilterCallback(filterGroup, filterOption);
          }
        };

        $scope.updateHasAppliedFilters = function() {
          var i,
            len,
            filterGroup,
            hasAppliedFilters = false;
          for (i = 0, len = $scope.filterGroups.length; i < len; i++) {
            filterGroup = $scope.filterGroups[i];

            if (typeof $scope.appliedFilters[filterGroup.groupName] !== 'undefined') {
              if (angular.isArray($scope.appliedFilters[filterGroup.groupName])) {
                if ($scope.appliedFilters[filterGroup.groupName].length > 0) {
                  hasAppliedFilters = true;
                }
              } else if ($scope.appliedFilters[filterGroup.groupName] !== null) {
                hasAppliedFilters = true;
              }
            }
          }
          $scope.hasAppliedFilters = hasAppliedFilters;
        };

        $scope.$watch('appliedFilters', function() {
          $scope.updateHasAppliedFilters();
        }, true);
      })
      .directive('agAppliedFilters', function() {
        return {
          restrict: 'AE',
          replace: true,
          transclude: true,
          controller: 'AppliedFiltersController',
          templateUrl: 'scripts/components/directives/applied-filters/applied-filters.html',
          scope: {
            appliedFilters: '=',
            removeFilterCallback: '='
          }
        };
      });
  }
);
