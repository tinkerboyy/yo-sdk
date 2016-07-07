define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('ProjectListCtrl', function($scope, DataService) {
        $scope.init = function() {
          DataService.Projects.get({ range: 'all' }, function(data) {
            if ($scope.projects) {
              $scope.projects.push.apply($scope.projects, data.data);
            } else {
              $scope.projects = data.data;
            }
          });
        };

        $scope.selectProject = function(project) {
          $scope.targetItem = project;
        };

        $scope.init();
      })
      .directive('agProjectList', function() {
        return {
          restrict: 'AE',
          controller: 'ProjectListCtrl',
          templateUrl: 'scripts/components/directives/project-list/project-list.html',
          replace: true,
          scope: {
            targetItem: '=',
            projects: '=?'
          }
        };
      });
  }
);
