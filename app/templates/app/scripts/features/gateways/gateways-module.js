define(
  [
    'angular',
    'lodash',
    'angularRoute',
    'angularStrap',
    'angularStrapTpl',
    'components/components-module',
    'components/directives/resources-block/resources-block-directive',
    'features/solutions-finder/solutions-finder-module',
    'features/project-center/project-center-module',
    'features/feeds/feed-module'
  ],
  function(angular, _) {
    angular.module('gateways.gateways', [ 'ngRoute', 'mgcrea.ngStrap','gateways.components'])
    .config(function($routeProvider) {
      $routeProvider.when('/', {
        controller: 'GatewaysController',
        templateUrl: 'scripts/features/gateways/gateways.html'
      });
      $routeProvider.otherwise({
        redirectTo: '/'
      });
    })
    .factory('GatewaysService', function (AGService) {
      function init () {
        AGService.data.banner.env = ['learn', 'connect', 'act'];
        AGService.data.banner.klass = 'upperClass';
        AGService.data.banner.title = 'Acquisition Gateway';
        AGService.data.banner.subtitle = '<h3>Act as One for smarter acquisition</h3><p>Our vision is to provide a workspace with accurate, useful, and unbiased advice. Check back often to see the latest progress.</p>';
        AGService.data.navigation.myProfile = true;
        AGService.data.navigation.signOut = true;
        AGService.data.search.show = false;
        AGService.data.footer.visible = true;
      }
      return {
        init:init
      };
    })
    .controller('GatewaysController', function($scope, AGService, GatewaysService) {
      GatewaysService.init();
    })
    .controller('GatewayHallwaysController', function($scope, DataService) {
      //Conditionally switches icon ( expand - collapse ) based on icon beign set value.
      $scope.icon = false;
        DataService.Hallways.get(function(data) {
          $scope.hallways = data.data;
        });
        DataService.Projects.get(function(data) {
           if ($scope.projects) {
               $scope.projects.push.apply($scope.projects, data.data);
           } else {
               $scope.projects = data.data;
           }
        });
      })
      .filter('listFilter', function() {
        return function(string) {

           function capitalizeEachWord(str) {
            return str.replace(/\w\S*/g, function(txt) {
                return txt.charAt(0).toUpperCase() + txt.substr(1);
            });
            }

          if (string) {

            string = capitalizeEachWord(string);
            string = string.replace(/&Amp;/g, '&');
            var newString = string.split('.');
            newString = _.map(newString, _.trim); //trim extra whitespace
            newString = _.compact(newString); //remove empty array indexes

            return newString;
          }
          return null;
        };
      })
      .directive('agGatewayHallways', function() {
      return {
        restrict: 'AE',
        controller: 'GatewayHallwaysController',
        templateUrl: 'scripts/features/gateways/gatewayHallways.html'
      };
    });
  }
);
