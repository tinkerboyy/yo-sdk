define(
  [
    'angular',
    'angularStrap',
    'angulartics',
    'angulartics-google-analytics',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('AccordionLightCtrl', function($scope, AGService, DataService) {
        var screenData = AGService.data.user.preferences.screen[$scope.id];
        $scope.init = function() {
          $scope.model = {
            expanded: screenData && screenData.expanded === false ? screenData.expanded : true
          };
        };

        $scope.toggle = function() {
          $scope.model.expanded = !$scope.model.expanded;
          DataService.Preferences.create({
            action: 'screen',
            type: $scope.id,
            itemId: Date.now().toString().substr(0, 10),
            data: { expanded: $scope.model.expanded }
          }, function(data) {
            AGService.data.user.preferences.screen[$scope.id] = data.data[0].data;
          });

          $scope.$emit('agContentUpdated');
        };

        $scope.init();
      }
    )
    .directive('agAccordionLight', function() {
      return {
        restrict: 'E',
        replace: true,
        transclude: true,
        scope: {
          title: '@?',
          item: '=?',  // pass a single object
          collection: '=?', // pass a collection object
          id: '@'
        },
        controller: 'AccordionLightCtrl',
        templateUrl: 'scripts/components/directives/accordion-light/accordion-light.html'
      };
    });
  }
);
