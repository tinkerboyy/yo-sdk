/**
 * Created by Madhukar on 12/23/15.
 */
define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/loader/loader-directive',
  'components/directives/loader/loader.html'
], function(angular) {
  describe('Loader Directive', function() {
    var scope
    , element
    , $controller
    , loaderController
    , $compile
    , $rootScope
    , $httpBackend;


    beforeEach(angular.mock.module('gateways.components'));
    beforeEach(angular.mock.module('templates'));

    beforeEach(angular.mock.inject(function(_$controller_, _$rootScope_, _$compile_, _$httpBackend_) {
      $rootScope = _$rootScope_;
      scope = $rootScope.$new();
      $compile = _$compile_;
      $httpBackend = _$httpBackend_;
      $controller = _$controller_;

      loaderController = $controller('LoaderController', {
        $scope: scope
      });
    }));

    afterEach(function() {
      $httpBackend.verifyNoOutstandingExpectation();
      $httpBackend.verifyNoOutstandingRequest();
    });

    it('should compile the directive', function() {
      element = angular.element('<ag-loader></ag-loader>');
      $compile(element)(scope);
      scope.$digest();
      var result = element[0].querySelectorAll('.ag-loader');
      expect(angular.element(result)).toBeDefined();
    });

    it('should have the controller defined', function() {
      var text = 'loading... please wait';
      scope.text = text || 'loading... please wait';
      expect(loaderController).toBeDefined();
      expect(scope.text).toEqual('loading... please wait');
    });
  });
});
