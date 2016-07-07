define(
  [
    'angular',
    'angularRoute',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.news', [ 'ngRoute', 'mgcrea.ngStrap', 'gateways.components' ])
    .config(function($routeProvider) {
      $routeProvider.when('/news/:id/:newsLabel', {
        controller: 'NewsPageController',
        templateUrl: 'scripts/features/news/news-page.html'
      });
      $routeProvider.otherwise({
        redirectTo: '/'
      });
    })
    .factory('NewsPageService', function (AGService) {
      function init () {
        AGService.data.banner.env = ['learn', 'connect', 'act'];
        AGService.data.banner.klass = 'ag-banner-align-left';
        AGService.data.banner.title = 'My News';
        AGService.data.search.show = false;
        AGService.data.banner.subtitle = 'Your look at the latest news, content, and data on the Acquisition Gateway.';
        AGService.data.navigation.myProfile = true;
        AGService.data.navigation.signOut = true;
        AGService.data.footer.visible = true;
      }
      return {
        init:init
      };
    })
    .controller('NewsPageController', function($scope, $controller, DataService, $routeParams, NewsPageService) {
      DataService.setDataLayerContext('News');
      NewsPageService.init();

      DataService.Hallways.get(function (data) {
          $scope.hallways = data.data;
       });

      DataService.News.get({ 'filter[id]': $routeParams.id },function (data) {
        $scope.news = data.data[0];
      });
    });
  }
);
