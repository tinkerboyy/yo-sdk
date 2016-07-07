define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components').config(function($provide) {
      $provide.decorator('bsSelectDirective', function($delegate, $select) {
        var directive = $delegate[0],
          link = directive.link,
          defaults = $select.defaults;

        directive.compile = function() {
          return function(scope, elem, attr, ctrl) {
            link.apply(this, arguments);

            var originalRender = ctrl.$render;

            ctrl.$render = function () {
              var caret = attr.caretHtml ? attr.caretHtml : defaults.caretHtml;
              originalRender();
              elem.html('<span>' + elem.html().replace(caret, '') + '</span>' + caret);
            };
          };
        };
        return $delegate;
      });
    });
  }
);

