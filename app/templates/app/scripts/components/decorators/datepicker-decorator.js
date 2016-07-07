define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components').config(function($provide) {
      $provide.decorator('bsDatepickerDirective', function($delegate) {
        var directive = $delegate[0],
          link = directive.link;

        directive.compile = function() {
          return function(scope, elem, attrs) {
            link.apply(this, arguments);

            if (attrs.disableKeyboard) {
              elem.bind('keydown paste', function(e) {
                e.preventDefault();
                e.stopPropagation();
                return false;
              });
            }
          };
        };
        return $delegate;
      });
    });
  }
);

