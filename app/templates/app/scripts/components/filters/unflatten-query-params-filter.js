define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('unflattenQueryParams', function() {
        return function(queryParams) {
          if (typeof string !== 'object') {
            return null;
          }
          angular.forEach(queryParams, function(value, key) {
            if (value.indexOf(',') >= 0) {
              queryParams[key] = value.split(',');
            }
          });
          return queryParams;
        };
    });
});
