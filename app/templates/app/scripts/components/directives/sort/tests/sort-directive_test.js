define(
  [
    'angular',
    'components/components-module',
    'components/directives/sort/sort-directive'
  ],
	function(angular) {
		describe('Sort Directive',function() {
			var $scope
        , $httpBackend
        , element
        , $compile
        , sortController
		  	, $rootScope;

    	beforeEach(module('gateways.sowl'));
    	beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

    	beforeEach(inject(function(_$rootScope_, $controller, $filter, _$httpBackend_, _$compile_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        $compile = _$compile_;

        $scope.collection = [
          {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
          {title: 'Result 2', relevance: 2, downloads: 4, views: 10},
          {title: 'Result 3', relevance: 1, downloads: 6, views: 12},
          {title: 'Result 4', relevance: 3, downloads: 1, views: 20}
        ];

        $scope.target = [];

        $scope.currentSort = {
          field: 'title',
          reverseOrder: false
        };

        $scope.sortOptions = [
          {
            field: 'title',
            defaultOrder: false
          },
          {
            field: 'relevance',
            defaultOrder: true
          },
          {
            field: 'downloads_to_views',
            defaultOrder: true,
            getSortValue: function(item) {
              return item.downloads / item.views;
            }
          }
        ];

        sortController = $controller('SortDirectiveController', {
          $scope: $scope,
          $filter: $filter
        });
			}));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      xit('should compile the directive', function() {
        element = angular.element('<ag-sort></ag-sort>')
        $httpBackend.expectGET('scripts/components/directives/sort/sort-button.html').respond('<div class="sort-toggle"></div>');
        $compile(element)($scope);
        $scope.$digest();
        $httpBackend.flush();
        var result = element[0].querySelectorAll('.sort-toggle');
        expect(angular.element(result)).toBeDefined();
      });

      it('should sort results', function() {
        var expectedResults = [
            {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
            {title: 'Result 4', relevance: 3, downloads: 1, views: 20},
            {title: 'Result 2', relevance: 2, downloads: 4, views: 10},
            {title: 'Result 3', relevance: 1, downloads: 6, views: 12}
          ];

        $scope.changeSortField('relevance');

        expect($scope.target).toEqual(expectedResults);
        expect($scope.currentSort.field).toEqual('relevance');
        expect($scope.currentSort.reverseOrder).toEqual(true);
      });

      it('should reverse the sort order when changeSortField called twice with same field', function() {
        var expectedResults = [
            {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
            {title: 'Result 2', relevance: 2, downloads: 4, views: 10},
            {title: 'Result 3', relevance: 1, downloads: 6, views: 12},
            {title: 'Result 4', relevance: 3, downloads: 1, views: 20}
          ],
          expectedResultsReversed = angular.copy(expectedResults).reverse();

        $scope.currentSort = {
          field: '',
          reverseOrder: false
        };

        $scope.changeSortField('title');
        expect($scope.target).toEqual(expectedResults);
        expect($scope.currentSort.reverseOrder).toEqual(false);
        $scope.changeSortField('title');
        expect($scope.target).toEqual(expectedResultsReversed);
        expect($scope.currentSort.reverseOrder).toEqual(true);
      });

      it('should use custom sort function', function() {
        var expectedResults = [
            {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
            {title: 'Result 3', relevance: 1, downloads: 6, views: 12},
            {title: 'Result 2', relevance: 2, downloads: 4, views: 10},
            {title: 'Result 4', relevance: 3, downloads: 1, views: 20}
          ];

        $scope.changeSortField('downloads_to_views');
        expect($scope.target).toEqual(expectedResults);
      });

      it('should sort case insensitive for strings', function() {
        $scope.collection = [
          {title: 'REsult 3', relevance: 1, downloads: 6, views: 12},
          {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
          {title: 'Result 4', relevance: 3, downloads: 1, views: 20},
          {title: 'ResuLt 2', relevance: 2, downloads: 4, views: 10}
        ];

        $scope.currentSort = {
          field: '',
          reverseOrder: false
        };

        var expectedResults = [
          {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
          {title: 'ResuLt 2', relevance: 2, downloads: 4, views: 10},
          {title: 'REsult 3', relevance: 1, downloads: 6, views: 12},
          {title: 'Result 4', relevance: 3, downloads: 1, views: 20}
        ];

        $scope.changeSortField('title');
        expect($scope.target).toEqual(expectedResults);
      });

      it('should use callback if set', function() {
        var expectedResults = [
            {title: 'Result 1', relevance: 4, downloads: 10, views: 12},
            {title: 'Result 4', relevance: 3, downloads: 1, views: 20},
            {title: 'Result 2', relevance: 2, downloads: 4, views: 10},
            {title: 'Result 3', relevance: 1, downloads: 6, views: 12}
          ],
          sortedResults;

        $scope.callback = function(data) {
          sortedResults = data;
        }
        $scope.changeSortField('relevance');

        expect(sortedResults).toEqual(expectedResults);
      });
    });
  }
);
