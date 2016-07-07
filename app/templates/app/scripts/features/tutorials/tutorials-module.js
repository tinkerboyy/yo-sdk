define(
  [
    'angular',
    'angularStrap',
    'components/components-module',
    'features/communities/communities-module'
  ],
  function(angular) {
    angular.module('gateways.tutorials', [])
      .config(function($routeProvider) {
        $routeProvider.when('/tutorials/:feature?', {
          controller: 'TutorialsController',
          templateUrl: 'scripts/features/tutorials/tutorials.html'
        });
      })
      .controller('TutorialsController', function($scope, AGService, DataService, $filter, $routeParams, $aside) {
        DataService.setDataLayerContext('Tutorials');
        AGService.data.banner.title = '';
        AGService.data.banner.subtitle = '';
        AGService.data.search.show = false;
        AGService.data.banner.env = ['learn', 'connect', 'act'];
        AGService.data.banner.klass = 'upperClass';

        $scope.features = [
          { name: 'sowl', icon: 'fa-bank', label: 'Statement of Work Library' },
          { name: 'solutions-finder', icon: 'fa-th-large', label: 'Solutions Finder' }
        ];

        DataService.Help.get({
          'filter[lc]': 1
        }, function(data) {
          $scope.tutorials = data.data;
        });

        if ($routeParams.feature) {
          $scope.currentFeature = $filter('filter')($scope.features, { name: $routeParams.feature }, true)[0];
          $scope.currentFeature.expanded = true;
        }

        $scope.setActiveFeature = function(feature) {
          feature.expanded = !feature.expanded;
          angular.forEach($filter('filter')($scope.features, { expanded: true }, true), function(f) {
            if (f !== feature) {
              f.expanded = false;
            }
          });

          $scope.currentFeature = feature.expanded ? feature : null;
        };

        $scope.loadArticle = function(article) {
          $scope.currentArticle = article;
          $aside({
            title: '<i class="fa ' + $scope.currentFeature.icon + '"></i> ' + $scope.currentFeature.label,
            templateUrl: 'scripts/features/tutorials/article-details.html',
            content: '<h3>' + article.label + '</h3>' + article.body,
            show: true
          });
        };
      });
  }
);
