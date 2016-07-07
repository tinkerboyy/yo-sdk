define(
  [
    'angular',
    'angularStrap',
    'angularToasty',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('AddToProjectCtrl', function($scope, DataService, $timeout, $agLoader, $analytics) {
        $scope.data = {};
        $scope.projects = [];
        if ($scope.item) {
          $scope.itemName = $scope.item[$scope.nameField];
        }

        $scope.addProject = function(project) {
          $scope.projects.push(project);
        };

        $scope.doHide = function() {
          $scope.addToProjectModal = false;
          $scope.$emit('addProject.modal', $scope.addToProjectModal);
          $scope.hide();
        };

        $scope.addToProject = function() {
          $scope.addLoader = $agLoader.getLoader(true);
          $scope.processing = true;
          var data = {
            pid: $scope.data.project.id,
            entity_id: $scope.item.id,
            type: $scope.type,
            name: $scope.item[$scope.nameField],
            data: $scope.item.data
          };
          DataService.ProjectEntities.save(data, function() {
            $scope.success = true;

            //Trigger analytics event for adding to project
            if ($scope.analyticsCategory) {
              $analytics.eventTrack('Add To Project', {
                label: $scope.analyticsLabel,
                value: $scope.analyticsValue,
                category: $scope.analyticsCategory
              });
            }

            $scope.addLoader.finish($scope.addLoader.requests[0]);
            $scope.doHide();

            var solutionType = $scope.type;
            solutionType = solutionType.replace(/\s/g, ''); // trim the whitespace

            if (solutionType.trim() === 'SolutionsFinderSearch') {
              $scope.$emit('addProject.SolutionsFinderSearch');
            }

            if (solutionType.trim() === 'solution') {
              $scope.$emit('addProject.solution');
            }

            if (solutionType.trim() === 'SOWLSearch') {
              $scope.$emit('addProject.SOWLSearch');
            }

            if (solutionType.trim() === 'SOWDocument') {
              $scope.$emit('addProject.SOWDocument');
            }
          }, function() {
            $scope.addLoader.finish($scope.addLoader.requests[0]);
            $scope.$emit('addProject.error.solution', $scope.type.trim());
            $scope.doHide();
          });
        };
      })
      .directive('agAddToProject', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'AddToProjectCtrl',
          templateUrl: 'scripts/components/directives/add-to-project/add-to-project.html',
          scope: {
            item: '=',
            nameField: '=',
            hide: '=',
            type: '=',
            analyticsCategory: '=?',
            analyticsLabel: '=',
            analyticsValue: '=',
            addToProjectModal: '=',
            notifyAddToProject: '=?'
          }
        };
      });
  }
);
