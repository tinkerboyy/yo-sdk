define(
  [
    'jquery',
    'angular',
    'angularMocks',
    'jqueryAsScrollable',
    'components/components-module',
    'components/directives/as-scrollable/as-scrollable-directive'
  ],
  function($, angular) {
    describe('As-Scrollable Directive', function() {
      var $scope
        , $rootScope
        , $timeout
        , element
        , $compile;

      beforeEach(module('gateways.components'));
      
      beforeEach(inject(function(_$compile_, _$rootScope_, _$timeout_) {
        $rootScope = _$rootScope_;
        $compile = _$compile_;
        $scope = $rootScope.$new();
        $timeout = _$timeout_;
      }));

      it('should compile the directive', function() {
        element = angular.element('<div ag-as-scrollable><div class="test"></div></div>');
        $compile(element)($scope);
        $scope.$digest();
        expect(element.html()).toContain('<div><div><div class="scroll-content-container"><div class="test"></div></div></div></div>');
      });

      it('should handle the contentUpdated event', function() {
        element = angular.element('<div ag-as-scrollable><div class="test"></div></div>');
        $(element).appendTo(document.body);
        $compile(element)($scope);
        $scope.$digest();
        $rootScope.$broadcast('agContentUpdated');
        $timeout.flush();
        $rootScope.$broadcast('agContentUpdated');
        $timeout.flush();
        //expect(element.asScrollable).toHaveBeenCalled();
      });
    });
  }
);
