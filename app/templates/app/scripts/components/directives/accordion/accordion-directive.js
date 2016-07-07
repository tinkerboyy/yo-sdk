define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('AccordionContainerController', function($scope) {
        $scope.expanded = this.expanded = null;
      })
      .directive('agAccordionContainer', function() {
        return {
          restrict: 'AE',
          transclude: true,
          controller: 'AccordionContainerController',
          template: '<ng-transclude bs-collapse start-collapsed="true" class="accordion-container" ng-model="activeAccordion.index"></ng-transclude>',
          scope: { activeAccordion: '=?' }
        };
      })
      .directive('agAccordion', function() {
        return {
          restrict: 'AE',
          require: '^^agAccordionContainer',
          transclude: true,
          scope: { moreOptions: '=' },
          templateUrl: 'scripts/components/directives/accordion/accordion.html',
          controller: function($scope) {
            this.moreOptions = $scope.moreOptions;
            $scope.$watch('moreOptions', function(newVal) {
              this.moreOptions = newVal;
            });
          }
        };
      })
      .directive('agAccordionHeader', function() {
        return {
          restrict: 'AE',
          require: [ '^^agAccordion', '^^agAccordionContainer' ],
          transclude: true,
          templateUrl: 'scripts/components/directives/accordion/accordion-header.html',
          link: function(scope, elem, attrs, ctrl) {
            scope.accordionModel = ctrl[0];
            scope.accordionContainerModel = ctrl[1];
          }
        };
      })
      .directive('agAccordionBody', function() {
        return {
          restrict: 'AE',
          require: '^^agAccordion',
          transclude: true,
          templateUrl: 'scripts/components/directives/accordion/accordion-body.html'
        };
      });
  }
);
