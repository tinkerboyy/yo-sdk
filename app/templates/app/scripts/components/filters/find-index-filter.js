define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('gateways.components')
      .filter('findIndex', function () { return _.findIndex; });
});
