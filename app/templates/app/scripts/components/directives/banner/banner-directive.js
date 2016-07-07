
define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
     angular.module('gateways.components')
      .controller('AgbannerCtrl',function ($scope, AGService) {
        $scope.banner = AGService.data.banner;
        $scope.search = AGService.data.search;

        $scope.getClass = function(size) {
          var cols = 12 / size;
          return 'col-xs-' + cols + ' col-sm-' +  cols;
        };
      })
      .directive('agBanner',function () {
        return {
          restrict: 'AE',
          controller:'AgbannerCtrl',
          templateUrl: 'scripts/components/directives/banner/banner.html',
          replace: true
        };
      });
  }
);
