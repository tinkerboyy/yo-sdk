define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular, _) {
     angular.module('gateways.components')
      .controller('AgfooterCtrl',function ($scope, AGService, DataService,$modal) {
        DataService.Footer.get(function(data) {
          $scope.footers = data.data;
        });

        $scope.footer = AGService.data.footer;

      $scope.openModal = function(type) {
        $modal({
          templateUrl: 'scripts/components/directives/footer/modals/' + _.kebabCase(type) + '.modal.html',
          show: true
        });
      };

      })
      .directive('agFooter',function () {
        return {
          restrict: 'AE',
          controller:'AgfooterCtrl',
          templateUrl: 'scripts/components/directives/footer/footer.html',
          replace: true
        };
      });
  }
);
