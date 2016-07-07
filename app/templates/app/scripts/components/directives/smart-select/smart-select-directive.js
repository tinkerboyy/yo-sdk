define(
  [
  'angular',
  'angularStrap',
  'components/components-module'
  ],
  function( angular ) {
    angular.module( 'gateways.components' )
    .controller('AgSmartSelectController', function($scope) {
      $scope.init = function() {
        var optionValueKey = $scope.optionValueKey ? '.' + $scope.optionValueKey : '',
          optionLabelKey = $scope.optionLabelKey ? $scope.optionLabelKey : 'name';

        $scope.optionExpression = 'option' + optionValueKey + ' as option.' + optionLabelKey + ' for option in options';
        if (!$scope.filterCountKey) {
          $scope.filterCountKey = 'id';
        }
        if (!$scope.multiple) {
          $scope.multiple = false;
        }
      };

      $scope.init();
    })
    .directive('agSmartSelect',function () {
      return {
        restrict: 'AE',
        templateUrl: 'scripts/components/directives/smart-select/smart-select.html',
        controller: 'AgSmartSelectController',
        scope: {
          title: '=',
          id: '@',
          target: '=',
          targetField: '@',
          options: '=',
          multiple: '=?',
          optionFlagKey: '@?',
          optionValueKey: '@?',
          optionLabelKey: '@?',
          changeCallback: '=?',
          filterCounts: '=?',
          filterCountKey: '@?'
        }
      };
   });
  }
);
