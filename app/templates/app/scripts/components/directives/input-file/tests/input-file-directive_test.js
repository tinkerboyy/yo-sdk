define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/input-file/input-file-directive'
  ], 
  function(angular) {
    describe('Input File Directive', function() {
      var $scope
        , $compile
        , $window
        , $rootScope;

      beforeEach(module('gateways.components'));
      beforeEach(inject(function(_$compile_, _$rootScope_, _$window_) {
        $compile = _$compile_;
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $window = _$window_;
      }));

      it('should compile the directive', function() {
        var element = angular.element('<div ag-input-file ng-model="model.test"></div>');
        $scope.model = { test: 'test' };
        $compile(element)($scope);
        $scope.$digest();
      });

      it('should use the ReadFile API if available', function() {
        $window.FileReader = jasmine.createSpy();
        var element = angular.element('<div ag-input-file ng-model="model.test"></div>');
        $scope.model = { test: 'test' };
        $compile(element)($scope);
        $scope.$digest();
      });
    });
  }
);
