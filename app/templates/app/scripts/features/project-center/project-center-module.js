define(
  [
    'angular',
    'angularRoute',
    'angularStrap',
    'angularStrapTpl',
    'angularScroll',
    'angularToasty',
    'components/components-module',
    'components/services/collection-factory',
    'components/directives/input-file/input-file-directive',
    'components/directives/collection/collection-directive',
    'components/directives/create-project/create-project-directive'
  ],
  function(angular) {
    angular.module('gateways.projectCenter', [ 'ngRoute', 'mgcrea.ngStrap', 'angular-toasty', 'gateways.components' , 'duScroll', 'angulartics'])
    .config(function($routeProvider) {
      $routeProvider.when('/project-center/:activeCenter', {
        controller: 'ProjectCenterFullController',
        templateUrl: 'scripts/features/project-center/project-center-full/project-center-full.html'
      });
    })
    .service('MyProjectsService', function($q, $timeout, $collection, $analytics) {
      var service = {
          active: { },
          tabs: { },
          resourceTypeMap: {
            'Uploaded Document': $collection('ProjectFileUpload'),
            'Event': $collection('PrivateEvents'),
            'Task': $collection('Tasks')
          }
        },
        ProjectEntities = $collection('ProjectEntities');

      function onCreate(e) {
        $analytics.eventTrack('Create ' + e.type, {
          label: e.type + ': ' + e.data.name,
          category: 'Project Center',
          value: e.data.id
        });
      }

      function onAddToProject(e) {
        $analytics.eventTrack('Add to Project', {
          label: e.data.type,
          category: 'Project Center',
          value: e.data.entity_id
        });
      }

      ProjectEntities.on('create', onAddToProject);
      service.resourceTypeMap.Task.on('create', onCreate);
      service.resourceTypeMap.Event.on('create', onCreate);
      $collection('Projects').on('create', onCreate);

      service.setActive = function(id) {
        if (id) {
          var projectElem = document.getElementById('Project' + id),
          container = angular.element(document.getElementById('scrollcontainer')),
          indexVal = projectElem.getAttribute('index');
          service.active.index = indexVal;
          service.tabs.active = 'My Projects';
          $timeout(function() {
            container.scrollTo(projectElem, 0, 1000);
          }, 25);
        }
      };

      service.saveAsAssociate = function(entity, type) {
        var collection = service.resourceTypeMap[type],
          newEntity;

        return collection.save(entity).then(function(data) {
          newEntity = data;
          if (entity.projectId) {
            return ProjectEntities.save({
              id: data.prid,
              pid: entity.projectId,
              type: type,
              name: data.label,
              entity_id: data.id
            });
          } else if (data.prid) {
            return ProjectEntities.remove({ id: data.prid });
          } else {
            return {};
          }
        }).then(function() {
          return collection.get({ id: newEntity.id });
        });
      };

      $collection('Projects').on('edit', function(e) {
        var tasksData = $collection('Tasks').data.collection,
            eventData = $collection('PrivateEvents').data.collection,
            tLength = tasksData.length,
            eLength = eventData.length;

        for (var i = 0; i < tLength; i++) {
          if (e.data.id === tasksData[i].projectId) {
            tasksData[i].projectName = e.data.name;
            tasksData[i].projectStatus = e.data.status;
          }
        }
        for (var j = 0; j < eLength; j++) {
          if (e.data.id === eventData[j].projectId) {
            eventData[j].projectName = e.data.name;
            eventData[j].projectStatus = e.data.status;
          }
        }
      });

      return service;
    })
    .controller('ProjectCenterController', function( $scope, $element, $templateRequest, $compile, AGService, MyProjectsService, DataService ) {
      DataService.setDataLayerContext('Project Center');
      $scope.publicUser = AGService.data.publicUser;

      var pageStack = [];
      $scope.tabs = MyProjectsService.tabs;
      $scope.tabs.active = $scope.tabs.active || 'My Projects';

      $scope.pushPage = function(page) {
        $templateRequest(page.templateUrl).then(function(template) {
          var scope = page.scope ? page.scope.$new() : $scope.$new(),
            lastNode = angular.element($element[0].querySelector('.content:last-of-type')),
            compiledNode = $compile('<div class="content">' + template + '</div>')(scope);
          lastNode.after(compiledNode);
          pageStack.push(compiledNode);
        });
      };

      $scope.popPage = function() {
        pageStack.length > 0 && pageStack.pop().remove();
      };
    })
    .controller('MyProjectUploadController', function($scope, $collection, $timeout, toasty, AGService) {
      $scope.publicUser = AGService.data.publicUser;

      var ProjectEntities = $collection('ProjectEntities'),
        ProjectFileUpload = $collection('ProjectFileUpload'),
        timeoutPromise;

      $scope.saved = false;

      $scope.projectFileUpload = {
        save: function(entity, project, fileFieldCtrl, callback) {
          ProjectFileUpload.save(entity).then(function(data) {
            ProjectEntities.save({
              pid: project.id,
              type: 'Uploaded Document',
              name: data.label,
              entity_id: data.id
            }).then(function() {
            //  AGNotifications.getNotification();
              $scope.saved = true;
              toasty.success({
                msg: 'Congratulations, your file was successfully added to your project!'
              });

              callback && callback();
              $scope.saved = false;
            });
          }, function(errResp) {
            if (errResp.status === 400) {
              fileFieldCtrl.$setValidity(errResp.data.errors.file[0], false);
            }
          });
        }
      };

      $scope.$root.$on('project.fileupload.modal.hide.before', function() {
        if (timeoutPromise) {
          $timeout.cancel(timeoutPromise);
        }
      });
    })
    .controller('MyProjectsController', function($scope, $controller, MyProjectsService, AGService, DataService, $filter) {
      //Conditionally switches icon ( expand - collapse ) based on this value.
      $scope.icon = true;
      $scope.publicUser = AGService.data.publicUser;
      $controller('MyProjectsContentController', { $scope: $scope });
      $scope.activeAccordion = MyProjectsService.active;

      DataService.Help.get({ featureName: 'project-center' }, function (data) {
        $scope.welcome = $filter('filter')(data.data, { 'label': $scope.publicUser ? 'Project Center Welcome Public' : 'Project Center Welcome' }, true)[0];
      });
    })
    .controller('MyProjectsContentController', function($scope, $window, $modal, $collection, $location, AGService) {
      $scope.publicUser = AGService.data.publicUser;

      var ProjectFileUpload = $collection('ProjectFileUpload'),
        //Map of content type to URL base for the content type
        contentMap = {
          solution: 'solutionsfinder'
        };

      $scope.filter = { status: '1' };
      if ($scope.project) {
        $scope.filter.pid = $scope.project.id;
      }

      $scope.openFileUploadModal = function(project) {
        var scope = $scope.$new();
        scope.projectEntity = project;
        $modal({
          templateUrl: 'scripts/features/project-center/projects/file-upload-modal.html',
          controller: 'MyProjectUploadController',
          prefixEvent: 'project.fileupload.modal',
          container: 'body',
          scope: scope,
          show: true
        });
      };

      $scope.openProjectEntity = function(entity) {
        switch (entity.type) {
          case 'Uploaded Document':
            ProjectFileUpload.get({ id: entity.entity_id }).then(function(data) {
              $window.open(data.file.url, data.file.filemime === 'application/pdf' ? '_blank' : '_self');
            });
            break;
          case 'SOW Document':
            $location.url('sowl/document/' + entity.entity_id);
            break;
          case 'Solutions Finder Search':
            var hsh = $location.url(entity.data).hash();
            $location.url(hsh);
            break;
          case 'SOWL Search':
            $location.url(entity.data);
            break;
          case 'Community Discussion':
            var topicId = entity.data.split('/').pop();
            $location.url('communities/topic/' + topicId);
            break;
          default:
            $location.url((contentMap[entity.type] || entity.type) + '/' + entity.entity_id);
            break;
        }
      };
    })
    .controller('MyEventsController', function($scope, MyProjectsService, AGNotifications) {
      //Conditionally switches icon ( expand - collapse ) based on icon beign set value.
      $scope.icon = true;
      var timeExtractionConstant = 24 * 60 * 60;

      function stdTimezoneOffset(date) {
        var jan = new Date(date.getFullYear(), 0, 1),
          jul = new Date(date.getFullYear(), 6, 1);
        return Math.max(jan.getTimezoneOffset(), jul.getTimezoneOffset());
      }

      function isDst(date) {
        return date.getTimezoneOffset() < stdTimezoneOffset(date);
      }

      $scope.filter = { status: '1' };
      if ($scope.project) {
        $scope.filter.projectId = $scope.project.id;
        $scope.defaultEntity = { projectId: $scope.project.id };
      }

      $scope.privateEvents = {
        transformAndCopy: function(entity) {
          entity = angular.copy(entity || {});
          return angular.extend(entity, {
            startDate: entity.start_date,
            startTime: entity.start_date,
            endDate: entity.end_date,
            endTime: entity.end_date
          });
        },
        saveAsAssociate: function(entity, callback) {
          var startTimeSeconds = entity.startTime % timeExtractionConstant,
            startDateWithoutTime = entity.startDate - (entity.startDate % timeExtractionConstant),
            endTimeSeconds = entity.endTime % timeExtractionConstant,
            endDateWithoutTime = entity.endDate - (entity.endDate % timeExtractionConstant),
            startIsDst = isDst(new Date(1000 * startDateWithoutTime)),
            endIsDst = isDst(new Date(1000 * startDateWithoutTime));

          entity.start_date = startDateWithoutTime + startTimeSeconds +
            (entity.startTime <= timeExtractionConstant && startIsDst ? (-60 * 60) : 0);
          entity.end_date = endDateWithoutTime + endTimeSeconds +
            (entity.endTime <= timeExtractionConstant && endIsDst ? (-60 * 60) : 0);

          MyProjectsService.saveAsAssociate(entity, 'Event').then(function() {
            AGNotifications.getNotification();
            if (callback) callback();
          });
        }
      };
    })
    .controller('MyTasksController', function($scope, MyProjectsService, AGNotifications) {
      $scope.filter = { status: '1' };
      if ($scope.project) {
        $scope.filter.projectId = $scope.project.id;
        $scope.defaultEntity = { projectId: $scope.project.id };
      }
      $scope.tasks = {
        saveAsAssociate: function(entity, callback) {
          MyProjectsService.saveAsAssociate(entity, 'Task').then(function() {

            AGNotifications.getNotification();
            if (callback) callback();
          });
        }
      };
    })
    .controller('ProjectCenterFullController', function($scope, $controller, $routeParams, $timeout, $collection, AGService) {
      AGService.data.banner.env = ['learn', 'connect', 'act'];
      AGService.data.banner.klass = 'ag-banner-align-left';
      AGService.data.banner.title = null;
      AGService.data.search.show = false;
      AGService.data.banner.subtitle = null;
      AGService.data.navigation.myProfile = true;
      AGService.data.navigation.signOut = true;

      $scope.publicUser = AGService.data.publicUser;

      $controller('MyEventsController', { $scope: $scope });

      $scope.active = {
        center: $routeParams.activeCenter,
        entities: []
      };

      if ($routeParams.activeCenter === 'projects' && $routeParams.activeEntities) {
        $scope.active.entities = $routeParams.activeEntities.split(',');

        var watch = $scope.$watch(function() {
          return document.getElementById('Project' + $scope.active.entities[0]);
        }, function(elem) {
          if (elem) {
            $timeout(function() {
              angular.element(document.body).scrollTo(document.getElementById('Project' + $scope.active.entities[0]), window.pageYOffset + 50, 1000);
            }, 0);
            watch();
          }
        });
      }

      $scope.toggle = function(id) {
        var index = $scope.active.entities.indexOf(id);
        if (index === -1) {
          $scope.active.entities.push(id);
        } else {
          $scope.active.entities.splice(index, 1);
        }
      };
    })
    .filter('myProjectContentFilter', function($filter) {
      return function (list, query) {
        var results = [];

        if (!list) {
          return [];
        }

        if (query) {
          list = $filter('filter')(list, query);
        }

        for (var i = 0, length = list.length; i < length; i++) {
          if (list[i].type !== 'Event' && list[i].type !== 'Task') {
            results.push(list[i]);
          }
        }

        return results;
      };
    })
    .directive('projectLink', function() {
      return {
        restrict: 'AE',
        controller: function($scope, $element, $attrs, MyProjectsService) {
          $element.on('click', function() {
            MyProjectsService.setActive($attrs.projectLink);
            $scope.$apply();
          });
        }
      };
    })
    .directive('agProjectCenter', function() {
      return {
        restrict: 'AE',
        templateUrl: 'scripts/features/project-center/project-center.html',
        controller: 'ProjectCenterController'
      };
    })
    .directive('agMyProjects', function() {
      return {
        restrict: 'AE',
        templateUrl: 'scripts/features/project-center/projects/my-projects.html',
        controller:'MyProjectsController'
      };
    })
    .directive('agMyEvents', function() {
      return {
        restrict: 'AE',
        scope: {
          project: '=',
          popoverContainer: '@'
        },
        templateUrl: 'scripts/features/project-center/events/my-events.html',
        controller: 'MyEventsController'
      };
    })
    .directive('agMyTasks', function() {
      return {
        restrict: 'AE',
        scope: {
          project: '=',
          fullView: '@fullView',
          popoverContainer: '@'
        },
        templateUrl: 'scripts/features/project-center/tasks/my-tasks.html',
        controller: 'MyTasksController'
      };
    })
    .directive('agMyProjectContent', function() {
      return {
        restrict: 'AE',
        scope: {
          project: '=',
          popoverContainer: '@'
        },
        templateUrl: 'scripts/features/project-center/project-content/my-project-content.html',
        controller: 'MyProjectsContentController'
      };
    });
  }
);
