define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('unixTimestampToDate', function() {
        return function(unixts) {
          return unixts ? new Date(parseInt(unixts, 10) * 1000) : null;
      	};
    });
});
