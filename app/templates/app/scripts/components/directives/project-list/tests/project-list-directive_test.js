/**
 * Created by Madhukar on 12/23/15.
 */

define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/project-list/project-list-directive',
  'components/directives/project-list/project-list.html'
], function(angular) {
    describe('Project List Directive', function() {
      var scope
      , $compile
      , projectListController
      , $httpBackend
      , element
      , $templateCache;

      var responseData = {
        "data": [
          {
            "id": "341",
            "name": "pro1",
            "uid": "2078",
            "created": 1449255251,
            "changed": null,
            "status": "0",
            "description": "",
            "notes": "",
            "due": null
          }, 
          {
            "id": "342",
            "name": "pro2",
            "uid": "2078",
            "created": 1449506026,
            "changed": null,
            "status": "0",
            "description": "",
            "notes": "",
            "due": null
          }
        ],
        "count": 17,
        "self": {
          "title": "Self",
          "href": "http:\/\/hallways.localhost\/api\/v1.0\/projects"
        }
      };

      var test = {
        "id": "357",
        "name": "test project",
        "uid": "2078",
        "created": 1450378206,
        "changed": null,
        "status": "1",
        "description": "",
        "notes": "",
        "due": 1451019600
      };

      beforeEach(angular.mock.module('gateways.components'));
      beforeEach(angular.mock.module('templates'));
      beforeEach(angular.mock.inject(function(_$templateCache_, _$compile_, $rootScope, DataService, _$httpBackend_, $controller) {
        scope = $rootScope.$new();
        $compile = _$compile_;
        $httpBackend = _$httpBackend_;
        $templateCache = _$templateCache_;

        $httpBackend.when('GET', '/api/v1.0/projects?range=all').respond(responseData);

        projectListController = $controller('ProjectListCtrl', {
          $scope: scope
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-project-list></ag-project-list>');
        $compile(element)(scope);
        scope.$digest();
        var result = element[0];
        $httpBackend.flush();
        expect(result).toBeTruthy();
      });

      it('should handle no project binding gracefully', function() {
        $httpBackend.flush();
        expect(scope.projects.length).toEqual(responseData.data.length);
        expect(scope.projects[0]).toEqual(responseData.data[0]);
      });

      it('should add retrieved projects to existing projects', function() {
        scope.init();
        $httpBackend.flush();
        expect(scope.projects.length).toEqual(responseData.data.length * 2);
        expect(scope.projects[0]).toEqual(responseData.data[0]);
      });


      it('should have the selected project in projects', function() {
        $httpBackend.when('GET', '/api/v1.0/projects?range=all').respond(200, responseData);
        $httpBackend.flush();

        scope.selectProject(test);
        expect(scope.targetItem).toBe(test);
      });
    });
  }
);
