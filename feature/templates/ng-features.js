define(
  [
    'angular',
    'lodash',
    'angularRoute',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('<%= appName %>.<%= featureName %>', [ 'ngRoute', 'gateways.components'])
      .config(function($routeProvider) {
      $routeProvider.when('/<%= route %>', {
        controller: '<%= controller %>',
        templateUrl: 'scripts/features/<%= path %>/<%= template %>.html'
      });

      $routeProvider.otherwise({
        redirectTo: '/'
      });
    })
    .controller('<%= controller %>', function($scope) {

    });

  }
);
