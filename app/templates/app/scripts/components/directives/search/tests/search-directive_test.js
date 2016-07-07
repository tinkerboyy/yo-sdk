define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/search/search-directive',
    'components/directives/search/search.html'
  ],
  function(angular) {
    describe('Search Directive', function() {
      // we declare some global vars to be used in the tests
      var element // our directive jqLite element
        , $scope
        , $httpBackend
        , $controller
        , searchController
        , $timeout
        , $compile; //the scope where our directive is inserted

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      // before each test, creates a new fresh scope
      beforeEach(inject(function ($rootScope, _$compile_, _$httpBackend_, _$controller_, _$timeout_) {
        $scope = $rootScope.$new();
        $compile = _$compile_;
        $httpBackend = _$httpBackend_;
        $controller = _$controller_;
        $timeout = _$timeout_;

        searchController = $controller('searchCtrl', {
          $scope: $scope
        });

        $scope.search = 'Test';
        $scope.selectedFilters = 'selected filter';
      }));

      afterEach(function () {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should implement this directive', function () {
        element = angular.element('<ag-search></ag-search>')
        $compile(element)($scope);
        $scope.$digest();
        var result = element[0].querySelectorAll('.search-form');
        expect(angular.element(result)).toBeDefined();
      });

      it('should have the controller defined', function () {
        expect(searchController).toBeDefined();
      });

      it('should have the search results when filter expanded', function () {
        $scope.action = jasmine.createSpy();
        var e = jasmine.createSpyObj('e', ['preventDefault']);

        $scope.filterExpanded = true;
        $scope.doSearch(e);
        expect(e.preventDefault).toHaveBeenCalled();
        //expect(timeoutSpy).toHaveBeenCalledWith(function () {
        //  angular.element(document.getElementById('search-filter-toggle')).triggerHandler('click');
        //  $scope.filterExpanded = false;
        //}, 0);
        $timeout.flush();
        expect($scope.filterExpanded).toBe(false);

        expect($scope.action).toHaveBeenCalledWith('Test', 'selected filter');
      });

      it('should have the search results when filter not expanded', function () {
        $scope.action = jasmine.createSpy();
        var e = jasmine.createSpyObj('e', ['preventDefault']);

        $scope.filterExpanded = false;
        $scope.doSearch(e);
        expect(e.preventDefault).toHaveBeenCalled();

        expect($scope.action).toHaveBeenCalledWith('Test', 'selected filter');
      });

      it('should get the rows', function() {
        var number = 9;
        $scope.getRows(number);
        expect(Math.ceil(number / 3)).toBe(3);
      });

      it('should toggle selected state off', function() {
        var filterId = 1;
        $scope.selectedFilters = [1, 2, 3];
        $scope.toggleSelection(filterId);
        expect($scope.selectedFilters).toEqual([2, 3]);
      });

      it('should toggle selected state off', function() {
        var filterId = 4;
        $scope.selectedFilters = [1, 2, 3];
        $scope.toggleSelection(filterId);
        expect($scope.selectedFilters).toEqual([1, 2, 3, 4]);
      });

    });
  }
);
