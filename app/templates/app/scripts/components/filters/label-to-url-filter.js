define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('labelToUrl', function() {
        return function(string, reverse) {
          if (typeof string !== 'string') {
            return null;
          }
          if (reverse) {
            return string.replace(/\-and\-/g, '-&-').replace(/\-/g, ' ');
          } else {
            return string.toLowerCase().replace(/\ /g, '-').replace(/\-\&\-/g, '-and-');
          }
        };
    });
});
