define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('gateways.components')
      .filter('kebabCase', function () { return _.kebabCase; });
});
