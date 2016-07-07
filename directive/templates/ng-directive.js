define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('<%= controller %>', function($scope) {
       
      })
      .directive('<%= directiveName %>', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: '<%= controller %>',
          templateUrl: 'scripts/components/directives/<%= path %>/<%= template %>.html',
          scope: {}
        };
      });
  }
);
