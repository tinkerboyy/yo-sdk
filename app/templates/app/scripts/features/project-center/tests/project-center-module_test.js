define(
  [
    'angular',
    'components/components-module',
    'features/project-center/project-center-module'
  ],
  function (angular) {
    var testProjects = { data: [ { id: 1 } ] };

    beforeEach(module('gateways.components'));
    beforeEach(module('gateways.projectCenter', function($analyticsProvider) {
      $analyticsProvider.settings.pageTracking.autoTrackVirtualPages = false;
      $analyticsProvider.settings.pageTracking.autoTrackFirstPage = false;
      $analyticsProvider.settings.developerMode = true;
    }));

    describe('Project Center Controller', function () {
      var $scope
      , $element
      , $httpBackend;

      beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        $element = angular.element('<div><div class="content"></div></div>');
        $httpBackend.when('GET', '/test').respond("<span>template</span>");
        $httpBackend.when('GET', '/api/session/token').respond({ token: 't' });
        $httpBackend.when('GET', '/api/v1.0/preferences').respond({});
        $httpBackend.when('GET', '/api/v1.0/help/project-center').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/projects?range=all').respond({ data: [{}] });
        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Btype%5D=project+welcome&range=1').respond({ data: [] });
        $httpBackend.when('POST', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', 'scripts/features/project-center/get-started.modal.html').respond('<div></div>');

        $controller('ProjectCenterController', {
          $scope: $scope,
          $element: $element
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should add compiled template to element', function() {
        var page = {
          templateUrl: '/test',
          scope: $scope.$new()
        };

        $scope.pushPage(page);
        $httpBackend.flush();

        expect($element[0].getElementsByTagName('span').length).toEqual(1);
      });

      it('should remove compiled template from element', function() {
        var page = {
          templateUrl: '/test',
        };

        $scope.pushPage(page);
        $httpBackend.flush();
        expect($element[0].getElementsByTagName('span').length).toEqual(1);

        $scope.popPage();
        expect($element.find('span').length).toEqual(0);
      });

    });

    describe('My Projects Controller', function () {
      var $scope
      , $element
      , $httpBackend
      , $window
      , $location
      , AGService
      , DataService;

      beforeEach(inject(function(_$rootScope_, _$controller_, _$httpBackend_, _$location_, _$window_, _DataService_, _AGService_, _$filter_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        $window = _$window_;
        $location = _$location_;
        DataService = _DataService_;
        AGService = _AGService_;
        $filter = _$filter_;

        spyOn($window, 'open');
        spyOn($location, 'url');

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({});
        $httpBackend.when('GET', '/api/v1.0/help/project-center').respond({ data: []});
        $httpBackend.when('GET', '/api/session/token').respond({ token: 't' });

        _$controller_('MyProjectsController', {
          $scope: $scope,
          $window: _$window_,
          $location : _$location_,
          DataService: DataService,
          AGService: AGService,
          $filter : $filter,
          AgConfirmation: jasmine.createSpyObj('AgConfirmation', [ 'open' ])
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should open file in new window/tab', function() {
        $httpBackend.expect('GET', '/api/v1.0/project-files/1').respond({ data: [ { file: { url: 'hi' } } ] })
        $scope.openProjectEntity({ entity_id: 1, type: 'Uploaded Document' });
        $httpBackend.flush();

        expect($window.open).toHaveBeenCalledWith('hi', '_self');
      });

      it('should open link to SOW Document', function() {
        $scope.openProjectEntity({ entity_id: 2, type: 'SOW Document' });
        expect($location.url).toHaveBeenCalledWith('sowl/document/2');
      });

      xit('should open link to Solutions Finder Search', function() {
        $scope.openProjectEntity({ entity_id: 3, type: 'Solutions Finder Search', data:'solutionSearch' });
        expect($location.url).toHaveBeenCalledWith('solutionSearch');
      });

      it('should open link to SOWL Search', function() {
        $scope.openProjectEntity({ entity_id: 4, type: 'SOWL Search', data:'sowlSearch' });
        expect($location.url).toHaveBeenCalledWith('sowlSearch');
      });

      it('should open dafault link', function() {
        $scope.openProjectEntity({ entity_id: 5, type: 'NewContent' });
        expect($location.url).toHaveBeenCalledWith('NewContent/5');
      });

      xit('should save file to a project', function() {
        $httpBackend.expect('POST', '/api/v1.0/project-files').respond({ data: [ { id: 1 } ] });
        $httpBackend.expect('POST', '/api/v1.0/projects-entity').respond({ data: [ { id: 1 } ] });
        $scope.projectFileUpload.save({}, {}, {});
        $httpBackend.flush();
      });
    });
    describe('My Events Controller', function () {
      var $scope
      , $controller
      , $element
      , $httpBackend
      , $window;

      beforeEach(inject(function(_$rootScope_, _$controller_, _$httpBackend_, _$window_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        $window = _$window_;
        $controller = _$controller_;

        spyOn($window, 'open');

        $httpBackend.when('GET', '/api/session/token').respond({ token: 't' });

        _$controller_('MyEventsController', {
          $scope: $scope,
          $window: _$window_
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should set filter and default entity object with projectId when project is given', function() {
        $scope.project = { id: 1 };
        $controller('MyEventsController', {
          $scope: $scope
        });

        expect($scope.filter).toEqual({ status: '1', projectId: 1 });
        expect($scope.defaultEntity).toEqual({ projectId: 1 });
      });

      it('should save event', function() {
        $httpBackend.expect('POST', '/api/v1.0/private-events').respond({ data: [ { id: 1 } ] });
        $httpBackend.expect('GET', '/api/v1.0/private-events/1').respond({ data: [ { id: 1 } ] });
        $scope.privateEvents.transformAndCopy({});
        $scope.privateEvents.saveAsAssociate({});
        $httpBackend.flush();
      });

    });

    describe('My Tasks Controller', function () {
      var $scope
      , $controller
      , $httpBackend;

      beforeEach(inject(function(_$rootScope_, _$controller_, _$httpBackend_, _$window_) {
        $scope = _$rootScope_.$new();
        $controller = _$controller_;
        $httpBackend = _$httpBackend_;

        $httpBackend.when('GET', '/api/session/token').respond({ token: 't' });

        _$controller_('MyTasksController', {
          $scope: $scope
        });
      }));

      it('should set filter and default entity object with projectId when project is given', function() {
        $scope.project = { id: 1 };
        $controller('MyTasksController', {
          $scope: $scope
        });

        expect($scope.filter).toEqual({ status: '1', projectId: 1 });
        expect($scope.defaultEntity).toEqual({ projectId: 1 });
      });

    });

    describe('My Projects Content Controller', function () {
      var $scope
      , $controller;

      beforeEach(inject(function(_$rootScope_, _$controller_, _$httpBackend_, _$window_) {
        $scope = _$rootScope_.$new();
        $controller = _$controller_;
        $httpBackend = _$httpBackend_;

        $httpBackend.when('GET', '/api/session/token').respond({ token: 't' });

        _$controller_('MyProjectsContentController', {
          $scope: $scope
        });
      }));

      it('should set filter with pid when project is given', function() {
        $scope.project = { id: 1 };
        $controller('MyProjectsContentController', {
          $scope: $scope
        });
        expect($scope.filter).toEqual({ status: '1', pid: 1 });
      });

    });

  }
);
