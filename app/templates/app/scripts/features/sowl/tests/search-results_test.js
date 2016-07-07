define(
  [
    'angular',
    'components/components-module',
    'features/sowl/sowl-module',
    'components/services/data-service',
    'components/services/ag-service',
    'components/services/notifications',
    'features/sowl/search-controller',
  ],
	function(angular) {
		describe('Statement of Work Library Search Controller',function() {
			var $scope
		  	, $rootScope
      	, DataService
      	, AGService
        , SOWLService
        , $routeParams = {}
        , $location
        , $agVotes;

      var testData = {
      	data: [
      		{ title: 'Data 1' },
      		{ title: 'Data 2' }
      	]
      };

      var voteResults = {
        data: [
          {type: 'sow', itemId: 123, votes: 35, count: 2001},
          {type: 'sow', itemId: 234, votes: 12, count: 136},
          {type: 'sow', itemId: 345, votes: 99, count: 5026},
          {type: 'sow', itemId: 456, votes: -102, count: 3059}
        ]
      };

    	beforeEach(module('gateways.sowl'));
    	beforeEach(module('gateways.components'));

    	beforeEach(inject(function(_$rootScope_, DataService, $controller, _$httpBackend_, _AGService_, $filter, _$agVotes_, _$location_, _SOWLService_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;
        $agVotes = _$agVotes_;
        $location = _$location_;
        SOWLService = _SOWLService_;

        $scope.sowl = {};

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/sowl/sow-search').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/sowl-typeahead').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/votes/sow').respond(voteResults);
        $httpBackend.when('GET', '/api/v1.0/search-suggestions').respond({ data: []});
        $httpBackend.when('GET', '/api-old/ContractSolutions/retrieve').respond([]);

        spyOn($agVotes, 'mergeVotesWithCollection').and.callFake(function() {
          return {
            then: function (callback) {
                return callback();
            }
          };
        });

     	$controller('SOWLSearchController', {
          $scope: $scope,
          DataService: DataService,
          AGService: AGService,
          SOWLService: SOWLService,
          $routeParams: $routeParams,
          $filter: $filter,
          $location: $location,
          $agVotes: _$agVotes_
        });

        $httpBackend.flush();
			}));

			afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
    	});

      it('should add label icons to the $scope', function() {
        expect($scope.icons).toEqual(SOWLService.data.icons);
      });

     	it('should perform a SOWL Search for a search phrase', function() {
          $scope.moreSearch = {
            search: 'test'
          };
    			$httpBackend.expect('GET', '/api/v1.0/sowl/test').respond(testData);

          $scope.sort = {
            field: 'title',
            reverseOrder: false
          };
          $scope.sortOptions = [
            {
              field: 'title',
              defaultOrder: false
            },
            {
              field: 'downloads',
              defaultOrder: true
            }
          ];

          $scope.doSearch();
    			$httpBackend.flush();
          expect($scope.results).toEqual(testData.data);
          expect($agVotes.mergeVotesWithCollection).toHaveBeenCalledWith('solution', jasmine.any(Array));
      });

      it('should perform a seach for a label', function() {
        $scope.moreSearch = {
          labels: 'testLabel'
        };
        $scope.categories = [
          {id: 123, name: 'testLabel'}
        ];
    		$httpBackend.expect('GET', '/api/v1.0/sowl?categories=testLabel').respond(testData);
        $scope.doSearch();
        $httpBackend.flush();
        expect($scope.results).toEqual(testData.data);
      });

    	it('should see sowl search Pagination results', function() {
    		var results = [
    			'result 1',
    			'result 2'
    		];

    		$scope.setResults(results);
        expect($scope.pagedResults).toEqual(results);
      });

      it('should see sowl search sorted results', function() {
    		var results = [
    			'result 1',
    			'result 2'
    		];

    		$scope.setSortedResults(results);
        expect($scope.sortedResults).toEqual(results);
      });

      it('should set an empty result set when no results are returned', function() {
    			$httpBackend.when('GET', '/api/v1.0/sowl/test').respond({});
    			$scope.moreSearch = {
            search: 'test'
          };
          $scope.doSearch();
    			$httpBackend.flush();
          expect($scope.results).toEqual([]);

      });

      it('should call search API with selected categories', function() {
          $httpBackend.when('GET', '/api/v1.0/sowl/test?categories=123,456').respond({});
          $scope.moreSearch = {
            search: 'test',
            categories: ['123', '456']
          };
          $scope.doSearch();
          $httpBackend.flush();
          expect($scope.categoryNames).toEqual(SOWLService.data.categoryNames);
      });

    });
  }
);
