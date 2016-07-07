define(
  [
    'angular',
    'angularStrap',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('CreateProjectDirectiveCtrl', function($scope, $popover, $element, DataService) {
        if (!$scope.project) {
          $scope.project = {};
        }
        $scope.openForm = function() {
          $scope.project = {};
          $popover($element, {
            title: 'Add Project',
            contentTemplate: 'scripts/components/directives/create-project/my-projects-entry.html',
            container: '.my-projects .popover-container',
            scope: $scope,
            placement: 'right',
            show: true
          });
        };

        $scope.saveProject = function(cb) {
          $scope.projectError = false;
          $scope.processing = true;
          DataService.Projects.save($scope.project, function(data) {
            $scope.processing = false;
            if ($scope.callback) {
              $scope.callback(data.data[0]);
            }
            cb();
          }, function() {
            $scope.processing = false;
            $scope.projectError = true;
          });
        };
      })
      .directive('agCreateProject', function() {
        return {
          restrict: 'AE',
          replace: true,
          templateUrl: 'scripts/components/directives/create-project/create-project.html',
          controller: 'CreateProjectDirectiveCtrl',
          scope: {
            callback: '='
          }
        };
      });
  }
);
