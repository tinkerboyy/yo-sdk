/**
 * Created by Madhukar on 12/23/15.
 */

define([
  'angular',
  'angularStrap',
  'angularMocks',
  'components/components-module',
  'components/directives/create-project/create-project-directive',
  'components/directives/create-project/create-project.html'
], function(angular) {
  describe('Create Project Directive', function() {
    var scope
      , cEl
      , $controller
      , createProjectController
      , $compile
      , $element = {}
      , $rootScope
      , $httpBackend
      , $popover = jasmine.createSpy();


    beforeEach(module('gateways.components'));
    beforeEach(module('templates'));

    beforeEach(inject(function(_$controller_, _$rootScope_, _$compile_, _$httpBackend_) {
      $rootScope = _$rootScope_;
      scope = $rootScope.$new();
      $compile = _$compile_;
      $httpBackend = _$httpBackend_;
      $controller = _$controller_;
      scope.project = { title: 'TEst Project' };

      createProjectController = $controller('CreateProjectDirectiveCtrl', {
        $scope: scope,
        $element: $element,
        $popover: $popover
      });
    }));

    afterEach(function() {
      $httpBackend.verifyNoOutstandingExpectation();
      $httpBackend.verifyNoOutstandingRequest();
    });

    it('should compile the directive', function() {
      cEl = angular.element('<ag-create-project></ag-create-project>');
      $compile(cEl)(scope);
      scope.$digest();
      var result = cEl[0].querySelectorAll('.add-project');
      expect(angular.element(result)).toBeDefined();
    });

    it('should have the controller defined', function() {
      expect(createProjectController).toBeDefined();
    });

    it('should open form and save the project', function() {
      scope.openForm();
      expect(scope.project).toEqual({});

      expect($popover).toHaveBeenCalledWith($element, {
        title: 'Add Project',
        contentTemplate: 'scripts/components/directives/create-project/my-projects-entry.html',
        container: '.my-projects .popover-container',
        scope: scope,
        placement: 'right',
        show: true
      });
    });

    it('should save the created project successfully', function() {
      var testProject = { title: 'Test Project' };
      $httpBackend.expect('POST', '/api/v1.0/projects').respond({ data: [testProject] });
      var cb = jasmine.createSpy();
      scope.project = angular.copy(testProject);

      scope.saveProject(cb);
      expect(scope.projectError).toBe(false);
      expect(scope.processing).toBe(true);
      
      $httpBackend.flush();
      
      expect(scope.processing).toBe(false);
      expect(cb).toHaveBeenCalled();
    });

    it('should call callback method after sucessful save of new project', function() {
      var testProject = { title: 'Test Project' };
      scope.callback = jasmine.createSpy();
      $httpBackend.expect('POST', '/api/v1.0/projects').respond({ data: [testProject] });
      var cb = jasmine.createSpy();
      scope.project = angular.copy(testProject);

      scope.saveProject(cb);
      $httpBackend.flush();
      expect(scope.callback).toHaveBeenCalled();
    });

    it('should handle project creation API errors gracefully', function() {
      $httpBackend.expect('POST', '/api/v1.0/projects').respond(500, {});
      var testProject = { title: 'Test Project' };
      scope.project = angular.copy(testProject);
      var cb = jasmine.createSpy();

      scope.saveProject(cb);
      $httpBackend.flush();

      expect(scope.projectError).toBe(true);
      expect(scope.processing).toBe(false);
    });
  });
});

