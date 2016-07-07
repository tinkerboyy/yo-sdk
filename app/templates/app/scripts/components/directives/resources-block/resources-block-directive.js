define([
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
    .config(function($routeProvider) {
      $routeProvider.when('/content/:label', {
        controller: 'PodcastArticleController',
        templateUrl: 'scripts/components/directives/resources-block/podcast-article/podcast-article.html'
      })
      .when('/content/footer/:label/',{
        controller: 'FooterContentController',
        templateUrl: 'scripts/components/directives/resources-block/footer-content/footer-article.html'
      })
      .otherwise({
        redirectTo: '/'
      });
    })
    .controller('PodcastArticleController', function ($scope, DataService, $routeParams, $location, GatewaysService,$filter) {
      GatewaysService.init();
      DataService.Podcast.get({ 'filter[label]':$filter('stringReplace')($routeParams.label,'-',' ') }, function(data) {
        $scope.podcastResources = data.data[0];
      });
     })
    .filter('trustUrl',function($sce) {
        return function(url) {
          return $sce.trustAsResourceUrl(url);
        };
    })
    .controller('FooterContentController', function ($scope, DataService, $routeParams, $location, GatewaysService,$filter) {
      GatewaysService.init();
       DataService.Footer.get({ 'filter[label]':$filter('stringReplace')($routeParams.label,'-',' ') }, function(data) {
        $scope.footerResources = data.data[0];
       });
     })
    .controller('ResourcesBlockController', function ($scope, DataService) {
  	  DataService.HallwaysResource.get(function(data) {
         $scope.resources = data.data;
      });
   })
   .directive('agResourcesBlock', function() {
      return {
        restrict: 'AE',
        controller: 'ResourcesBlockController',
        templateUrl: 'scripts/components/directives/resources-block/resources-block.html'
      };
    });
  });
