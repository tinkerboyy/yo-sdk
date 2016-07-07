define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components').config(function($provide) {
      $provide.decorator('bsCollapseToggleDirective', function($delegate) {
        var directive = $delegate[0],
          link = directive.link;

        directive.compile = function() {
          return function(scope, elem, attrs, ctrls) {
            link.apply(this, arguments);
            var bsCollapseCtrl = ctrls[1];

            scope.isActive = function() {
              var index = attrs.bsCollapseToggle && attrs.bsCollapseToggle !== 'bs-collapse-toggle' ? attrs.bsCollapseToggle : bsCollapseCtrl.$toggles.indexOf(elem),
                activeItems = bsCollapseCtrl.$targets.$active;
              return activeItems.indexOf(index) === -1 && activeItems.indexOf(parseInt(index, 10)) === -1 ? false : true;
            };
          };
        };
        return $delegate;
      });
    });
  }
);
