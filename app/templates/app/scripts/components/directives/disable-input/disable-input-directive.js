define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
    .directive('agDisableInput', function() {
      return {
        restrict: 'A',
        link: function(scope, elem) {
          var allowedKeys = [ 9, 13, 16, 37, 38, 39, 40 ];
          elem.bind('keydown paste', function(e) {
            if (allowedKeys.indexOf(e.which) === -1) {
              e.preventDefault();
              e.stopPropagation();
              return false;
            }
          });
        }
      };
    });
  }
);
