/**
 * Created by Madhukar on 12/21/15.
 */
define([
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/banner/banner-directive',
    'components/directives/banner/banner.html'
], function(angular) {

    describe('Banner Directive', function() {
      var scope
      , bannerController
      , $compile
      , element
      , $httpBackend;

      beforeEach(angular.mock.module('gateways.components'));
      beforeEach(angular.mock.module('templates'));

      beforeEach(angular.mock.inject(function(_$httpBackend_, _$templateCache_, _$compile_, $rootScope, $controller, AGService) {
        scope = $rootScope.$new();
        $compile = _$compile_;
        $httpBackend = _$httpBackend_;

        bannerController = $controller('AgbannerCtrl', {
          $scope: scope
        });

        $httpBackend.when('GET', '/api/v1.0/preferences').respond(200);
       // $httpBackend.when('GET', 'scripts/components/directives/search/search.html').respond(200);
        $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-banner></ag-banner>');
        $compile(element)(scope);
        scope.$digest();
        var result = element[0].querySelectorAll('.ag-banner');
        expect(angular.element(result)).toBeDefined();
       // var result = element[0].querySelectorAll('.user-search-link');
       // expect(angular.element(result)).toBeDefined();
      });

      it('should have the controller defined', function() {
        expect(bannerController).toBeDefined();
      });

      it('should adjust the col size', function() {
        var size = 3;
        scope.getClass(size);
        var cols = 12 / size;

        expect(cols).toBe(4);
      });
    });
  }
);
