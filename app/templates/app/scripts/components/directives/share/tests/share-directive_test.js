define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/share/share-directive',
    'components/directives/share/share.html'
    ],
    function(angular) {

      describe('Share Directive Controller', function() {
        var $scope
        , element
        , $httpBackend
        , $compile
        , $controller
        , $location
        , $rootScope
        , $modal = jasmine.createSpy();

        beforeEach(module('gateways.components'));
        beforeEach(module('templates'));

        beforeEach(inject(function(_$rootScope_, AGService, _$location_, _$compile_, _$controller_, _$httpBackend_) {
          $rootScope = _$rootScope_;
          $scope = $rootScope.$new();
          $location = _$location_;
          $compile = _$compile_;
          $controller = _$controller_;
          $httpBackend = _$httpBackend_;

          $httpBackend.when('GET', '/api/v1.0/preferences').respond(200);
          $httpBackend.flush();

          $controller('ShareController', {
            $scope: $scope,
            $location: _$location_,
            $modal: $modal
          });
        }));

        afterEach(function() {
          $httpBackend.verifyNoOutstandingExpectation();
          $httpBackend.verifyNoOutstandingRequest();
        });

        it('should compile the directive', function() {
          element = angular.element('<ag-share></ag-share>');
          $compile(element)($scope);
          $scope.$digest();
          var result = element[0].querySelectorAll('.ag-share');
          expect(angular.element(result)).toBeDefined();
        });

        it('should hide popover by default', function() {
          expect($scope.showShare).toEqual(false);
        });

        it('should show popover when share icon is clicked and set share URL to current absolute URL', function() {
          spyOn($location, 'absUrl').and.returnValue('http://www.somewebsite.com');
          $scope.doShare();

          expect($scope.showShare).toEqual(true);
          expect($location.absUrl).toHaveBeenCalled();
          expect($scope.shareUrl).toEqual('http://www.somewebsite.com');
        });

        it('should use existing scope URL in share', function() {
          spyOn($location, 'absUrl').and.returnValue('http://www.somewebsite.com');
          spyOn($location, 'url').and.returnValue('http://www.somewebsite.com');
          $scope.url = 'test-url';
          $scope.doShare();
          expect($scope.shareUrl).toEqual('test-url');
        });

        it('should select contents of URL input', function() {
          var $event = {
            target: {
              select: function() { }
            }
          };
          spyOn($event.target, 'select');

          $scope.selectUrl($event);

          expect($event.target.select).toHaveBeenCalled();
        });

        it('should set add search params to URL', function() {
          spyOn($location, 'url').and.returnValue('http://www.somewebsite.com');
          $scope.searchParams = '?abc=123';

          $scope.setUrl();
          expect($location.url).toHaveBeenCalledWith('http://www.somewebsite.com?abc=123');
        });

        it('should set URL without search params', function() {
          spyOn($location, 'url').and.returnValue('http://www.somewebsite.com');

          $scope.setUrl();
          expect($location.url).toHaveBeenCalledWith('http://www.somewebsite.com');
        });

        it('should set URL to defined link', function() {
          $scope.link = 'test-url';
          spyOn($location, 'url');

          $scope.setUrl();
          expect($location.url).toHaveBeenCalledWith('test-url');
        });


        it('should add to the project', function() {
          var item = {
            data: 'http://wwww.somewebsite.com',
            id: '123456'
          };

          $scope.addToProject();
          $scope.showShare = false;
          expect($modal).toHaveBeenCalledWith(jasmine.objectContaining({
            title: 'Add this solution to a project',
            scope: $scope,
            templateUrl: 'scripts/components/directives/add-to-project/add-to-project-modal.html',
            show: true
          }));
        });
      });
    }
);
