define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('flattenForQueryParams', function() {
        return function(queryParams) {
          if (typeof queryParams !== 'object') {
            return null;
          }
          angular.forEach(queryParams, function(value, key) {
            if (angular.isArray(value)) {
              queryParams[key] = value.join(',');
            }
          });
          return queryParams;
        };
    });
});
