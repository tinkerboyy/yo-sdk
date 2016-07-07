define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('stringReplace', function() {
        return function(string, oldSubStr, newSubStr) {
          if (typeof string !== 'string') {
            return null;
          }
          return string.replace(new RegExp(oldSubStr, 'g'), newSubStr);
        };
    });
});
