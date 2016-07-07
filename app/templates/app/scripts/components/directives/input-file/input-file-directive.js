define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
     angular.module('gateways.components')
      .directive('agInputFile', function($window) {
        return {
          restrict: 'AE',
          require: 'ngModel',
          scope: {
            allowedMimes: '=',
            maxSize: '='
          },
          link: function(scope, elem, attrs, ngModel) {
            elem.bind('change', function(e) {
              ngModel.$setViewValue(e.currentTarget.files[0]);
            });

            if (angular.isFunction($window.FileReader)) {
              ngModel.$validators.size = function(modelValue, viewValue) {
                var value = modelValue || viewValue;
                return !value || !scope.maxSize ||
                  !angular.isNumber(value.size) || value.size <= scope.maxSize;
              };

              ngModel.$validators.mime = function(modelValue, viewValue) {
                var value = modelValue || viewValue;
                return !value || !scope.allowedMimes ||
                  angular.isUndefined(value.type) || scope.allowedMimes.indexOf(value.type) !== -1;
              };
            }
          }
        };
      });
  }
);
