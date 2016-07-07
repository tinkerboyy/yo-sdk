define(
  [
  'angular',
  'angularStrap',
  'components/components-module'
  ],
  function( angular ) {
    angular.module( 'gateways.components' )
   .directive('agConfirmation',function () {
      return {
        restrict: 'AE',
        templateUrl: 'scripts/components/directives/confirmation/confirmation.html',
        scope: {

        }
      };
   });
  }
);

