define(
  [
    'jquery',
    'angular',
    'lodash',
    'jqueryAsScrollable',
    'components/components-module'
  ],
  function($, angular) {
    angular.module('gateways.components')
      .directive('agAsScrollable', function($timeout) {
        return {
          restrict: 'A',
          link: function(scope, elem) {
            var scrollbarInitialized = false;

            elem.children().wrap('<div class="scroll-content-container"></div>');
            elem.children().wrap('<div></div>');
            elem.children().wrap('<div></div>');
            $timeout(function() {
              $(elem).asScrollable({
                namespace: 'asScrollable',
                skin: 'scrollable-inverse',
                direction: 'vertical',
                contentSelector: '>',
                containerSelector: '>',
                scrollbar: {
                  skin: 'scrollable-inverse',
                  direction: 'vertical',
                  keyboard: false,
                  namespace: 'scrollable-bar',
                  useCssTransitions: false
                }
              });

              scrollbarInitialized = true;
            }, 0);

            scope.$on('agContentUpdated', function() {
              if (scrollbarInitialized) {
                $timeout(function() {
                  $(elem).asScrollable('update');
                }, 500);
              }
            });
          }
        };
      });
  }
);
