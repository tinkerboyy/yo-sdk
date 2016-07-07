define(
  [
    'angular',
    'angularStrap',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('NavigationCtrl', function($scope, DataService, AGService, $modal, $window, $location, $cookies) {
        $scope.publicUser = AGService.data.publicUser;

        //Get main menu items
        DataService.Navigation.get({ menuName: 'menu-acquisition-gateway' }, function(data) {
          if (data.data && data.data.length > 0) {
            $scope.mainMenuItems = data.data[0].menuItems;
          }
        });

        $scope.navigation = AGService.data.navigation;
        $scope.agData = AGService.data;

        $scope.logout = function() {
          DataService.Auth.logout(function() {
            $modal({
              templateUrl: 'scripts/components/directives/navigation/signout-modal.html',
              show: true,
              backdrop: 'static'
            });
          });
        };

        $scope.promptLogin = function() {
          $scope.modalOpen = true;
          $modal({
            templateUrl: 'scripts/components/directives/navigation/signin-modal.html',
            show: true,
            scope: $scope,
            backdrop: 'static'
          });
        };

        $scope.login = function() {
          $cookies.referrerUrl = $location.absUrl();
          DataService.Auth.logout(function() {
            $window.location.replace('/cas?destination=' + $location.absUrl());
          });
        };

        $scope.closeModal = function(cb) {
          $scope.modalOpen = false;
          cb();
        };
      })
      .directive('agNavigation', function() {
        return {
          restrict: 'AE',
          replace: 'true',
          controller: 'NavigationCtrl',
          templateUrl: 'scripts/components/directives/navigation/navigation.html'
        };
      });
  }
);
