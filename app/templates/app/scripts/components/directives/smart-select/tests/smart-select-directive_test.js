/**
 * Created by Madhukar on 12/23/15.
 */

define([
  'angular',
  'angularStrap',
  'angularMocks',
  'components/components-module',
  'components/directives/smart-select/smart-select-directive',
  'components/directives/smart-select/smart-select.html'
], function(angular) {
  describe('Smart Select Directive', function() {
    var $scope
      , $rootScope
      , $httpBackend
      , $compile
      , element
      , smartSelectController;

    beforeEach(module('gateways.components'));
    beforeEach(module('templates'));


    beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_, _$compile_) {
      $rootScope = _$rootScope_;
      $scope = $rootScope.$new();
      $httpBackend = _$httpBackend_;
      $compile = _$compile_;

      smartSelectController = $controller('AgSmartSelectController', {
        $scope: $scope
      });
    }));

    afterEach(function() {
      $httpBackend.verifyNoOutstandingExpectation();
      $httpBackend.verifyNoOutstandingRequest();
    });

    it('should compile the directive', function() {
      element = angular.element('<ag-smart-select></ag-smart-select>')
      $compile(element)($scope);
      $scope.$digest();
      var result = element[0].querySelectorAll('.ag-smart-select');
      expect(angular.element(result)).toBeDefined();
    });

    it('should use defaults if none are provided', function() {
      $scope.init();
      expect($scope.multiple).toBe(false);
      expect($scope.optionExpression).toEqual($scope.optionExpression = 'option as option.name for option in options');
    });

    it('should see and use provided scope defaults', function() {
      $scope.optionValueKey = 'testValue';
      $scope.optionLabelKey = 'testLabel';
      $scope.multiple = true;
      $scope.init();
      expect($scope.optionExpression).toEqual($scope.optionExpression = 'option.testValue as option.testLabel for option in options');
    });

  });
});
