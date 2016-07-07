/**
 * Created by Madhukar on 12/21/15.
 */
define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/help/help-directive',
    'components/directives/help/help.html'
  ],
  function(angular) {
    describe('Help Directive', function() {
      var $compile
        , $controller
        , scope
        , ele
        , helpController
        , $httpBackend
        , $filter
        , $rootScope;

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      beforeEach(inject(function(_$compile_, _$rootScope_, _$controller_, _$httpBackend_, _$filter_) {
        $compile = _$compile_;
        $rootScope = _$rootScope_;
        scope = $rootScope.$new();
        $controller = _$controller_;
        $httpBackend = _$httpBackend_;
        $filter = _$filter_;

        helpController = $controller('HelpController', {
          $scope: scope,
          $filter: $filter
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should display the compiled HTML', function() {
        scope.collection = [
          {
            id: "1242",
            label: "My Agency",
            path: "http://hallways.localhost/content/my-agency",
          },
          {
            id: "1243",
            label: "My Agency",
            path: "http://hallways.localhost/content/test-item",
          }
        ];

        scope.item = 'test-item';
        ele = angular.element('<ag-help collection="collection" item="item"></ag-help>');
        $compile(ele)(scope);
        scope.$digest();
        var result = ele[0].querySelectorAll('.help');
        expect(angular.element(result)).toBeDefined();
      });

      it('should assign the right help item', function() {
        scope.collection = [
          {
            id: "1242",
            label: "My Agency",
            path: "http://hallways.localhost/content/my-agency",
          },
          {
            id: "1243",
            label: "My Agency",
            path: "http://hallways.localhost/content/test-item",
          }
        ];

        scope.item = 'test-item';
        scope.init();
        expect(scope.helpItem).toEqual(scope.collection[1]);
      });

    });
  }
);
