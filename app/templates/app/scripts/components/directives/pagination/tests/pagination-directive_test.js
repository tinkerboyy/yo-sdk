/**
 * Created by Madhukar on 12/23/15.
 */

define([
  'angular',
  'angularStrap',
  'angularMocks',
  'components/components-module',
  'components/directives/pagination/pagination-directive',
  'components/directives/pagination/pagination.html'
], function(angular) {
  describe('Pagination Directive', function() {
    var $scope
      , element
      , $controller
      , paginationCtrl
      , $compile
      , $element = {}
      , $rootScope
      , $httpBackend
      , $popover = jasmine.createSpy();


    beforeEach(module('gateways.components'));
    beforeEach(module('templates'));

    beforeEach(inject(function(_$controller_, _$rootScope_, _$compile_, _$httpBackend_) {
      $rootScope = _$rootScope_;
      $scope = $rootScope.$new();
      $compile = _$compile_;
      $httpBackend = _$httpBackend_;
      $controller = _$controller_;

      paginationCtrl = $controller('AgPaginationCtrl', {
        $scope: $scope
      });
    }));

    afterEach(function() {
      $httpBackend.verifyNoOutstandingExpectation();
      $httpBackend.verifyNoOutstandingRequest();
    });

    it('should compile the directive', function() {
      $scope.items = ['a', 'b', 'c'];
      $scope.pageSizes = [1];
      element = angular.element('<ag-pagination data-items="[ 1, 2, 3]" data-page-sizes="[1]"></ag-pagination>');
      $compile(element)($scope);
      $scope.$digest();
      expect($scope.pageSizes).toEqual([1]);
      //expect($scope.pageSize).toEqual(1);
    });

    it('should initize scope defaults', function() {
      expect($scope.pageSize).toEqual(25);
      expect($scope.offeringSize).toEqual(10);
      expect($scope.currentPage).toEqual(1);
    });

    it('should paginate items to specified page', function() {
      $scope.target = {};
      $scope.callback = jasmine.createSpy();
      $scope.pages = [1, 2, 3, 4];
      $scope.items = [1, 2, 3, 4, 5, 6, 7, 8];
      $scope.pageSize = 2;
      $scope.paginate(2);
      expect($scope.callback).toHaveBeenCalledWith([3, 4]);
      expect($scope.target).toEqual([3, 4]);
    });

    it('should paginate and sort items', function() {
      $scope.callback = jasmine.createSpy();
      $scope.items = [
        { name: 'a' },
        { name: 'c' },
        { name: 'd' },
        { name: 'b' },
      ];

      var test = [
        { name: 'a' },
        { name: 'b' },
        { name: 'c' },
        { name: 'd' },
      ];

      $scope.pages = [1];
      $scope.pageSize = 4;
      $scope.order = 'name';
      $scope.paginate(1);

      expect($scope.callback).toHaveBeenCalledWith(test);
    });

    it('should change page size', function() {
      spyOn($scope, 'setPages');
      $scope.pages = [1, 2, 3, 4];
      $scope.currentPage = 4;
      $scope.items = [1, 2, 3, 4, 5, 6, 7, 8];
      $scope.pageSize = 2;
      $scope.changeSize(4);

      expect($scope.count).toEqual(8);
      expect($scope.pageSize).toEqual(4);
      expect($scope.setPages).toHaveBeenCalledWith(2);
      expect($scope.currentPage).toEqual(2);
    });


    it('should do nothing if there are no items to paginate', function() {
      spyOn($scope, 'setPages');
      delete $scope.items;
      $scope.pages = [1, 2, 3, 4];
      $scope.currentPage = 4;
      $scope.pageSize = 2;
      $scope.changeSize(4);

      expect($scope.setPages).not.toHaveBeenCalled();
    });

    it('should exit paginate if current page is greater that total pages', function() {
      $scope.pages = [1, 2, 3, 4];
      expect($scope.paginate(5)).toEqual(undefined);
    });

  });
});

