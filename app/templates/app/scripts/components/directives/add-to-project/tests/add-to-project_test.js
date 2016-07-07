/**
 * Created by Madhukar on 12/23/15.
 */

define([
  'angular',
  'angularStrap',
  'angularToasty',
  'angularMocks',
  'components/components-module',
  'components/directives/add-to-project/add-to-project-directive',
  'components/directives/add-to-project/add-to-project.html',
  'components/directives/loader/loader.html'
], function(angular) {
  describe('Add to Project Directive', function() {
    var $scope
      , element
      , $controller
      , addToProjectCtrl
      , $compile
      , $rootScope
      , $agLoader
      , analytics
      , $httpBackend;

    beforeEach(module('gateways.components'));
    beforeEach(module('templates'));

    beforeEach(inject(function(_$controller_, _$rootScope_, _$compile_, _$httpBackend_, _$analytics_, _$agLoader_) {
      $rootScope = _$rootScope_;
      $scope = $rootScope.$new();
      $compile = _$compile_;
      $httpBackend = _$httpBackend_;
      $controller = _$controller_;
      analytics = _$analytics_;
      $agLoader = _$agLoader_;

      $scope.hide = jasmine.createSpy();
      $scope.type = jasmine.createSpy();

      $httpBackend.when('GET', '/api/v1.0/projects?range=all').respond({});
      $httpBackend.when('POST', '/api/v1.0/projects-entity').respond(200);

      addToProjectCtrl = $controller('AddToProjectCtrl', {
        $scope: $scope,
        $analytics: analytics,
        $agLoader: $agLoader
      });
    }));

    afterEach(function() {
      $httpBackend.verifyNoOutstandingExpectation();
      $httpBackend.verifyNoOutstandingRequest();
    });

    it('should compile the directive', function() {
      $scope.testItem = {
        label: 'Test Item'
      };
      $scope.testNameField = 'label';
    //  $scope.testAnalytics = 'Test Analytics';


      element = angular.element('<ag-add-to-project data-name-field="testNameField" data-item="testItem" data-analytics-category="analyticsCategory"></ag-add-to-project>');
      $compile(element)($scope);
      $scope.$digest();
      $httpBackend.flush();
      var result = element[0].querySelectorAll('.add-to-project');
      expect(angular.element(result)).toBeDefined();
    });

    it('should have the controller defined', function() {
      expect(addToProjectCtrl).toBeDefined();
    });

    it('should have the controller defined', function() {
      expect(addToProjectCtrl).toBeDefined();
    });

    it('should add project', function() {
      var project = { id: 11 };
      $scope.addProject(project);
      $scope.projects.push(project);
    });

    it('should hide', function() {
      spyOn($scope, '$emit');

      $scope.doHide();
      expect($scope.addToProjectModal).toBe(false);
      expect($scope.$emit).toHaveBeenCalledWith('addProject.modal', $scope.addToProjectModal);
      expect($scope.hide).toHaveBeenCalled();
    });

    it('should be able add to project', function() {
      $httpBackend.expect('POST', '/api/v1.0/projects-entity').respond(200);
      var loaderSpy = spyOn($agLoader, 'getLoader').and.callThrough();
      var analyticsSpy = spyOn(analytics, 'eventTrack');
      var emitSpy = spyOn($scope, '$emit');
      $scope.analyticsLabel = 'testItem';
      $scope.analyticsValue = 'testValue';
      $scope.analyticsCategory = 'test category';
      $scope.data = {
        project: {
          id: 11
        }
      };

      $scope.item = {
        id: 112
      };

      var data = {
        pid: 2345,
        entity_id: 1234,
        type: 'solution',
        name: '18F',
        data: 'test Data'
      };
      $scope.analyticsOn = true;
      $scope.type = 'solution';

      var test = {
        label: 'testItem',
        action: "pin",
        type: "solution"
      };

      var testData = {
        label: 'testItem',
        value: 'testValue',
        category: 'test category'
      };

      $scope.addToProject();
      expect(loaderSpy).toHaveBeenCalledWith(true);
      expect($scope.processing).toBe(true);

      $httpBackend.flush();

      expect(analyticsSpy).toHaveBeenCalledWith('Add To Project', testData );
      expect($scope.hide).toHaveBeenCalled();
      expect(emitSpy).toHaveBeenCalledWith('addProject.solution');
    });

    it('should not submit analytics if no category is provided', function() {
      var analyticsSpy = spyOn(analytics, 'eventTrack');
      $scope.data = {
        project: {
          id: 11
        }
      };

      $scope.item = {
        id: 112
      };
      $scope.type = 'test';

      $scope.addToProject();
      $httpBackend.flush();
      expect(analyticsSpy).not.toHaveBeenCalled();
    });

    it('should see a Solutions Finder search being added', function() {
      var emitSpy = spyOn($scope, '$emit');
      $scope.data = {
        project: {
          id: 11
        }
      };

      $scope.item = {
        id: 112
      };
      $scope.type = 'Solutions Finder Search';

      $scope.addToProject();
      $httpBackend.flush();

      expect(emitSpy).toHaveBeenCalledWith('addProject.SolutionsFinderSearch');

    });

    it('should see a SOWL search being added', function() {
      var emitSpy = spyOn($scope, '$emit');
      $scope.data = {
        project: {
          id: 11
        }
      };

      $scope.item = {
        id: 112
      };
      $scope.type = 'SOWL Search';

      $scope.addToProject();
      $httpBackend.flush();

      expect(emitSpy).toHaveBeenCalledWith('addProject.SOWLSearch');

    });

    it('should see a SOWL Document being added', function() {
      var emitSpy = spyOn($scope, '$emit');
      $scope.data = {
        project: {
          id: 11
        }
      };

      $scope.item = {
        id: 112
      };
      $scope.type = 'SOW Document';

      $scope.addToProject();
      $httpBackend.flush();

      expect(emitSpy).toHaveBeenCalledWith('addProject.SOWDocument');

    });

    it('should handle API failure gracefully', function() {
      $httpBackend.expect('POST', '/api/v1.0/projects-entity').respond(500);
      spyOn($scope, 'doHide');
      var emitSpy = spyOn($scope, '$emit');
      $scope.data = {
        project: {
          id: 11
        }
      };

      $scope.item = {
        id: 112
      };
      $scope.type = ' test ';

      $scope.addToProject();
      spyOn($scope.addLoader, 'finish');
      $httpBackend.flush();

      expect($scope.addLoader.finish).toHaveBeenCalledWith($scope.addLoader.requests[0]);
      expect(emitSpy).toHaveBeenCalledWith('addProject.error.solution', 'test');
      expect($scope.doHide).toHaveBeenCalled();
    });
  });
});

