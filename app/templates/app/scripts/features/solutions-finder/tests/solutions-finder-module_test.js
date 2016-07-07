define(
  [
    'angular',
    'angularMocks',
    'features/solutions-finder/solutions-finder-module',
    'angulartics',
    'angulartics-google-analytics',
    'components/services/notifications',
    'components/services/data-service',
    'components/services/ag-service',
    'components/directives/smart-select/smart-select-directive',
    'components/directives/smart-select/smart-select.html',
    'components/directives/smart-select/smart-select-dropdown.html',
    'components/directives/help/help.html',
    'features/solutions-finder/solutions-finder-directive.html'
  ],
  function(angular) {
    var solutionTypes = [
      { name: 'Type 1', Type: 'Contract', shortName: 'Type1' },
      { name: 'Type 2', Type: 'Program', shortName: 'Type2' },
      { name: 'Type 3', Type: 'Contract', shortName: 'Type3' },
      { name: 'Type 4', Type: 'unknowm', shortName: 'Type4' }
    ];

    var testCategories = [
      { name: 'Category 1', id: '1' },
      { name: 'Category 2', id: '2' },
      { name: 'Category 3', id: '3' },
      { name: 'Category 4', id: '4' }
    ];

    var testSubCategories = [
      { name: 'SubCategory 1', id: '20' },
      { name: 'SubCategory 2', id: '21' },
      { name: 'SubCategory 3', id: '22' },
      { name: 'SubCategory 4', id: '23' }
    ];

    var testSolutions = [
      { 
        id: '987', 
        name: 'Solution 1', 
        type: ['Type 2'], 
        categories: ['1', '21'], 
        subcategories: ['20', '21'],
        servicesProvided: 'Test services\n provided',
        servicesProvidedText: 'Test services\n provided',
        availableToId: 1 
      },
      { 
        id: 567, 
        name: 'Solution 2', 
        type: ['Type 1', 'Type 2'], 
        categories: ['20', '2'], 
        subcategories: ['22'],
        availableToId: 2, 
        servicesProvided: 'Test services\n provided',
        servicesProvidedText: 'Test services\n provided',
        pinned: true 
      }
    ];

    var testAvailableTo = [
      { name: 'AvailableTo 1', id: 1 },
      { name: 'AvailableTo 2', id: 2 }
    ];

    describe('Solutions Finder Controller', function() {
      var $scope
        , $rootScope
        , $httpBackend
        , $filter
        , AGService
        , $location
        , AGNotifications
        , $analyticsStub
        , FilterCountTracker
        , FilterCountTracker
        , $modal = jasmine.createSpy()
        , toasty
        , $routeParams = {}
        , $agVotes;

      beforeEach(module('gateways.solutionFinder'));
      beforeEach(module('gateways.components'));

      beforeEach(inject(function(_$rootScope_, DataService, FilterCountTracker, $controller, _$filter_, _$httpBackend_, _$location_, _AGService_, $cacheFactory, _$agVotes_, _AGNotifications_, _toasty_, _FilterCountTracker_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        $filter = _$filter_;
        AGNotifications = _AGNotifications_;
        $location = _$location_;
        AGService = _AGService_;
        $analyticsStub = {
          eventTrack: angular.noop
        };
        $agVotes = _$agVotes_;
        toasty = _toasty_;
        FilterCountTracker = _FilterCountTracker_;

        //TODO: Remove this and debug why adding angulartics breaks unit tests and adds an expectation for this tpl file
        $httpBackend.when('GET', 'scripts/features/gateways/gateways.html').respond('');
        //END TODO

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/solutions-finder-user-agency/dev').respond({ data: [ { id: 1234 }]});
        $httpBackend.when('POST', '/api/v1.0/solutions-finder-user-agency?agency=dev').respond({ data: [ { id: 1234 }]});
        $httpBackend.when('GET', '/api-old/Categories/retrieve').respond(testCategories);
        $httpBackend.when('GET', '/api-old/SubCategories/retrieve').respond(testSubCategories);
        $httpBackend.when('GET', '/api-old/SolutionTypes/retrieve').respond(solutionTypes);
        $httpBackend.when('GET', '/api-old/ContractSolutions/retrieve').respond(testSolutions);
        $httpBackend.when('GET', '/api-old/AvailableTo/retrieve').respond(testAvailableTo);
        $httpBackend.when('GET', '/api/v1.0/navigation/menu-solutions-finder').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/search-suggestions').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/help/solutions-finder').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=pin&filter%5Btype%5D=solution').respond({ data: [{ itemId: 987 }]});
        //$httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=pin&filter%5Btype%5D=solution').respond({ data: []});

        AGService.data.user = {
          user_info: {
          },
          preferences: { follow: {} }
        }
        filterCountTrackerSpy = jasmine.createSpyObj(FilterCountTracker, ['reset', 'addFilterGroup', 'addFilterOption', 'addItem', 'update', 'addAlwaysShownItem', 'removeAlwaysShownItem'])

        spyOn($agVotes, 'mergeVotesWithCollection').and.callFake(function() {
          return {
            then: function (callback) {
                return callback();
            }
          };
        });

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
            field: 'availableTo',
            defaultOrder: false
          }
        ];

        $controller('SolutionsFinderController', {
          $scope: $scope,
          $filter: $filter,
          $location: $location,
          AGService: AGService,
          AGNotifications: AGNotifications,
          FilterCountTracker: FilterCountTracker,
          $analytics: $analyticsStub,
          $agVotes: _$agVotes_,
          $modal: $modal,
          toasty: toasty,
          $routeParams: $routeParams
        });

        $httpBackend.flush();
        $cacheFactory.get('$http').removeAll();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should filter solutions by exact category match', function() {
        var solutions = [
          { name: 'solution1', categories: [1, 2, 3, 4] },
          { name: 'solution2', categories: [1, 2] },
          { name: 'solution3', categories: [3, 4] },
          { name: 'solution4', categories: [5] }
        ];

        var test = $filter('categorySearch')(solutions, [1,2]);
        expect(test.length).toBe(2);
        expect(test[0]).toEqual(solutions[0]);
        expect(test[1]).toEqual(solutions[1]);
      });

      it('should filter solutions by exact subcategory match', function() {
        var solutions = [
          { name: 'solution1', categories: [1, 2, 3, 4] },
          { name: 'solution2', categories: [1, 2] },
          { name: 'solution3', categories: [3, 4] },
          { name: 'solution4', categories: [5] }
        ];

        var subcats = [
          { name: 'subcat1', id: 3 },
          { name: 'subcat2', id: 4 }
        ];

        var test = $filter('subcategorySearch')(solutions, subcats);
        expect(test.length).toBe(2);
        expect(test[0]).toEqual(solutions[0]);
        expect(test[1]).toEqual(solutions[2]);
      });

      it('should get all subcategories for a given category', function() {
        var subcats = [
          { name: 'subcat 1', categoryId: 1, id: 1 },
          { name: 'subcat 2', categoryId: 2, id: 2 },
          { name: 'subcat 3', categoryId: 3, id: 3 },
          { name: 'subcat 4', categoryId: 1, id: 4 },
          { name: 'subcat 5', categoryId: 2, id: 5 },
        ];

        var test = $filter('getSubcats')(subcats, 1); 

        expect(test.length).toBe(2);
        expect(test).toEqual([ subcats[0], subcats[3] ]);

      });

      it('should only try to get all subcategories if a category is defined', function() {
        var subcats = [
          { name: 'subcat 1', categoryId: 1, id: 1 },
          { name: 'subcat 2', categoryId: 2, id: 2 },
          { name: 'subcat 3', categoryId: 3, id: 3 },
          { name: 'subcat 4', categoryId: 1, id: 4 },
          { name: 'subcat 5', categoryId: 2, id: 5 },
        ];

        var test = $filter('getSubcats')(subcats); 

        expect(test).toBe(undefined);
      });

      it('should get categories from a combined list of categories and subcategories', function() {
        var categories = ['1', '2', ' ', '21', '22'];
        var test;

        test = $filter('sfGetCategories')(testCategories);
        expect(test).toEqual([]);

        test = $filter('sfGetCategories')(testCategories, categories);
        expect(test.length).toBe(2);
        expect(test).toEqual([ testCategories[0], testCategories[1] ]);
      });

      it('should get subcategories from a combined list of categories and subcategories', function() {
        var categories = ['1', '2', ' ', '20', '21'];
        var test;

        test = $filter('getSubCategories')(testSubCategories);
        expect(test).toEqual([]);

        test = $filter('getSubCategories')(testSubCategories, categories);
        expect(test.length).toBe(2);
        expect(test).toEqual([ testSubCategories[0], testSubCategories[1] ]);
      });

      it('should have \'Votes\' sort option for authenticated users', function() {
        $scope.init();
        $httpBackend.flush();
        expect($scope.sortOptions[2].field).toEqual('votes');
      });

      it('should not have \'Votes\' sort option for public users', function() {
        $scope.publicUser = true;
        $scope.init();
        $httpBackend.flush();
        expect($scope.sortOptions.length).toEqual(3);
      });

      it('should retrieve votes sort order for item with vote count defined', function() {
        $scope.publicUser = false;
        $scope.init();
        $httpBackend.flush();
        var test = $scope.sortOptions[2].getSortValue({ votes: 3 });
        expect(test).toEqual(3);
      });

      it('should retrieve votes sort order for item with no vote count defined', function() {
        $scope.publicUser = false;
        $scope.init();
        $httpBackend.flush();
        var test = $scope.sortOptions[2].getSortValue({});
        expect(test).toEqual(0);
      });

      it('should see query string category filter parameters', function() {
        $location.search('category', '1,2');
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.categories).toEqual(['1', '2']);
      });

      it('should see query string subcategory filter parameters', function() {
        $location.search('category', '1,2');
        $location.search('subcategory', '20,21');
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.subcategories).toEqual([$scope.allSubcategories[0], $scope.allSubcategories[1]]);
      });

      it('shoudl see query string search term', function() {
        $location.search('search', 'test');
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.search).toEqual('test');
      });

      it('should see query string Program Type', function() {
        $location.search('programTypes', '2,3');
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.programTypes).toEqual(['2', '3']);
      });

      it('should see query string Contract Type', function() {
        $location.search('contractTypes', '2,3');
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.contractTypes).toEqual(['2', '3']);
      });

      it('should do nothing if no agency info is available in the search', function() {
        delete $location.$$search.agency;
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.availableTo).toEqual(undefined);
      });

      it('should see query string agency filter parameters', function() {
        $location.search('agency', 1);
        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.availableTo).toEqual($scope.availableTo[0]);
      });

      it('should find a matching user agency without making a guess', function() {
        $location.search('agency', undefined);
        AGService.data.user = {
          user_info: {
            cas: { 'Org-Agency-Name': testAvailableTo[0].name }
          }
        };

        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.availableTo).toEqual($scope.availableTo[0]);
      });

      it('should guess a users agency', function() {
        $location.search('agency', undefined);
        $httpBackend.expect('GET', '/api/v1.0/solutions-finder-user-agency/test').respond({ data: [ { fkOptionId: 1 }] });
        AGService.data.user = {
          user_info: {
            cas: { 'Org-Agency-Name': 'test' }
          }
        };

        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.availableTo).toEqual($scope.availableTo[0]);
      });

      it('should see no matching agency', function() {
        $location.search('agency', undefined);
        $httpBackend.expect('GET', '/api/v1.0/solutions-finder-user-agency/test').respond({ data: [] });
        AGService.data.user = {
          user_info: {
            cas: { 'Org-Agency-Name': 'test' }
          }
        };

        $scope.init();
        $httpBackend.flush();
        expect($scope.moreSearch.availableTo).toBe(undefined);
      });

      it('should mark solutions as pinned based on preferences API results', function() {
        $scope.init();
        $httpBackend.flush();
        expect($filter('filter')($scope.allSolutions, { id: '987' })[0].pinned).toBe('true');
        
      });

      it('should set singe solution mode when solution ID is provided in URL', function() {
        $routeParams.id = '987';
        $scope.init();
        $httpBackend.flush();
        expect($scope.singleSolution).toBe(true);
        expect($scope.solutions).toEqual([ $scope.allSolutions[0] ]);
        expect($scope.solutions[0].details).toBe(true);
        expect($scope.viewStatus).toBe(true);

        delete $routeParams.id;
      });

      it('should get all Categories', function() {
        $scope.isDirective = true;
        $scope.init();
        $httpBackend.flush();
        expect($scope.categories.length).toEqual(testCategories.length);
      });

      it('should show all solutions', function() {
        $scope.toggleSearch(true);
        expect($scope.moreSearch.contractTypes.length).toBe(0);
        expect($scope.moreSearch.programTypes.length).toBe(0);
      });

      it('should show all solutions when previously in single solution mode', function() {
        $routeParams.id = '987';
        $scope.init();
        $httpBackend.flush();
        $scope.toggleSearch();
        expect($scope.singleSolution).toBe(false);
        expect($scope.solutions).toEqual([]);
        delete $routeParams.id;
      });

      it('should add solution to filter updater', function() {
        var newTestSolutions = angular.copy(testSolutions);
        newTestSolutions.push({ id: 123456 });
        $httpBackend.expect('GET', '/api-old/ContractSolutions/retrieve').respond(newTestSolutions);
        $scope.init();
        $httpBackend.flush();

      });

      it('should get a category name', function() {
        var name = $scope.getCategoryName(1);
        expect(name).toEqual('Category 1');
      });

      it('should initialize the filter count tracker', function() {
        spyOn($scope.filterCountUpdater, 'addFilterGroup');
        spyOn($scope.filterCountUpdater, 'addFilterOption');
        spyOn($scope.filterCountUpdater, 'addItem');

        $scope.init();
        $httpBackend.flush();

        expect($scope.filterCountUpdater.addFilterGroup.calls.count()).toEqual(4);

        expect($scope.filterCountUpdater.addFilterGroup.calls.argsFor(0)).toEqual(['availableTo', false, null, {
          getFilterOptionKey: jasmine.any(Function),
          getItemsForSelectedFiltersInGroup: jasmine.any(Function),
          getItemsForFilter: jasmine.any(Function)
        }]);
        expect($scope.filterCountUpdater.addFilterGroup.calls.argsFor(1)).toEqual(['categories', true, 'AND'])
        expect($scope.filterCountUpdater.addFilterGroup.calls.argsFor(2)).toEqual(['subcategories', true, 'AND'])
        expect($scope.filterCountUpdater.addFilterGroup.calls.argsFor(3)).toEqual(['type', true, 'OR', {
          selectedFilterKey: 'solutionTypes'
        }]);

        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(0)).toEqual(['type', 'Type 1']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(1)).toEqual(['type', 'Type 2']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(2)).toEqual(['type', 'Type 3']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(3)).toEqual(['type', 'Type 4']);

        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(4)[0]).toEqual('availableTo');
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(4)[1].name).toEqual('AvailableTo 1');
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(4)[1].id).toEqual(1);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(5)[0]).toEqual('availableTo');
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(5)[1].name).toEqual('AvailableTo 2');
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(5)[1].id).toEqual(2);

        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(6)).toEqual(['categories', '1']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(7)).toEqual(['categories', '2']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(8)).toEqual(['categories', '3']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(9)).toEqual(['categories', '4']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(10)).toEqual(['subcategories', '20']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(11)).toEqual(['subcategories', '21']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(12)).toEqual(['subcategories', '22']);
        expect($scope.filterCountUpdater.addFilterOption.calls.argsFor(13)).toEqual(['subcategories', '23']);

        expect($scope.filterCountUpdater.addItem.calls.argsFor(0)).toEqual(['987', {
          availableTo: [1],
          categories: ['1', '21'],
          subcategories: ['1', '21'],
          type: ['Type 2']
        }, true]);

        expect($scope.filterCountUpdater.addItem.calls.argsFor(1)).toEqual([567, {
          availableTo: [2],
          categories: ['20', '2'],
          subcategories: ['20', '2'],
          type: ['Type 1', 'Type 2']
        }, true]);

      });

      it('should return filter option key', function() {
        $scope.init();
        $httpBackend.flush();
        var tester = $scope.filterCountUpdater.filterGroups.availableTo;
        var test = tester.overrides.getFilterOptionKey( { id: 1234 });
        expect(test).toBe(1234);
      });

      it('should update filter counts as filters are changed', function() {
        spyOn($scope.filterCountUpdater, 'update');

        $scope.init();
        $httpBackend.flush();

        $scope.moreSearch = {
          availableTo: ['Type 1'],
          categories: [20, 1]
        };

        $scope.changeFilter();
        //$httpBackend.flush();

        $httpBackend.flush();

        expect($scope.filterCountUpdater.update).toHaveBeenCalledWith($scope.moreSearch);
      });

      it('should pass selected solutionTypes and subcategories for filter count updater', function() {
        spyOn($scope.filterCountUpdater, 'update');

        $scope.init();
        $httpBackend.flush();

        $scope.moreSearch = {
          contractTypes: ['123', '456'],
          programTypes: ['789'],
          categories: ['20'],
          subcategories: [
            { id: '201' },
            { id: '202' }
          ]
        };

        $scope.changeFilter();

        var expectedSelectedFilters = {
          solutionTypes: ['123', '456', '789'],
          categories: ['20'],
          subcategories: ['201', '202']
        };

        expect($scope.filterCountUpdater.update).toHaveBeenCalledWith(expectedSelectedFilters);
      });

      it('should submit user agency selection for machine learning', function() {
        AGService.data.user.user_info.cas = {
          'Org-Agency-Name': 'Test Agency'
        };
        $scope.moreSearch.availableTo = { id: 123, name: 'GSA' };
        $scope
        $httpBackend.expect('POST', '/api/v1.0/solutions-finder-user-agency?agency=Test+Agency').respond({ data: [ { id: 1234 }]});
        $scope.changeFilter();
        $httpBackend.flush();
      });

      it('should select subcategories that are children of selected categories', function() {
        $scope.categories = [
          {
            id: "123",
            name: 'Parent 1'
          },
          {
            id: "234",
            name: 'Parent 2'
          }
        ];
        var subcategories = [
          {
            id: "345",
            name: 'Child of Parent 1',
            categoryId: "123"
          },
          {
            id: "456",
            name: 'Child of Parent 2',
            categoryId: "234"
          }
        ];

        $scope.allSubcategories = [subcategories[1]];

        $scope.moreSearch = {
          categories: ["234"],
          subcategories: subcategories
        };

        $scope.moreSearch.categories = ["234"];
        $scope.setSubcategories();
        expect($scope.subCategories).toEqual([
          {
            id: "234",
            name: 'Parent 2'
          },
          {
            id: "456",
            name: 'Child of Parent 2',
            categoryId: "234"
          }
        ]);
      });

      it('should deselect sub categories that are not children of selected category', function() {
        $scope.categories = [
          {
            id: "123",
            name: 'Parent 1'
          },
          {
            id: "234",
            name: 'Parent 2'
          }
        ];
        $scope.allSubcategories = [
          {
            id: "345",
            name: 'Child of Parent 1',
            categoryId: "123"
          },
          {
            id: "456",
            name: 'Child of Parent 2',
            categoryId: "234"
          }
        ];

        $scope.moreSearch = {
          categories: ["123", "234"]
        };
        $scope.setSubcategories();
        expect($scope.subCategories).toEqual([
          {
            id: "123",
            name: 'Parent 1'
          },
          {
            id: "345",
            name: 'Child of Parent 1',
            categoryId: "123"
          },
          {
            id: "234",
            name: 'Parent 2'
          },
          {
            id: "456",
            name: 'Child of Parent 2',
            categoryId: "234"
          }
        ]);

        $scope.moreSearch.categories = ["234"];
        $scope.setSubcategories();
        expect($scope.subCategories).toEqual([
          {
            id: "234",
            name: 'Parent 2'
          },
          {
            id: "456",
            name: 'Child of Parent 2',
            categoryId: "234"
          }
        ]);
      });

      it('should trigger analytics event when solution pinned/unpinnded', function() {
        spyOn($scope.filterCountUpdater, 'addAlwaysShownItem');
        spyOn($scope.filterCountUpdater, 'removeAlwaysShownItem');
        var solution = {
          id: 123,
          pinned: true,
          details: false
        };

        $scope.allSolutions = [
          {
            id: 123,
            pinned: true
          },
          {
            id: 456,
            pinned: true
          },
          {
            id: 789,
            pinned: false
          }
        ];

        spyOn($scope, 'triggerAnalyticsEventForSolution');

        $scope.togglePinned(solution);

        expect($scope.triggerAnalyticsEventForSolution).toHaveBeenCalledWith('solution.pinned', solution, {'Total Solutions Pinned': 2});
        expect($scope.filterCountUpdater.addAlwaysShownItem).toHaveBeenCalledWith(123);

        solution.pinned = false;
        $scope.allSolutions[0].pinned = false;

        $scope.togglePinned(solution);

        expect($scope.triggerAnalyticsEventForSolution).toHaveBeenCalledWith('solution.unpinned', solution, {'Total Solutions Pinned': 1});
        expect($scope.filterCountUpdater.removeAlwaysShownItem).toHaveBeenCalledWith(123);
      });

      it('should toggle show/more flag and send analytics event', function() {
        var solution = {
          id: 123,
          details: false
        };

        spyOn($scope, 'triggerAnalyticsEventForSolution');

        $scope.toggleShowMore(solution);

        expect($scope.triggerAnalyticsEventForSolution).toHaveBeenCalledWith('solution.showDetails', solution);
        expect(solution.details).toBe(true);

        $scope.toggleShowMore(solution);

        expect($scope.triggerAnalyticsEventForSolution).toHaveBeenCalledWith('solution.hideDetails', solution);
        expect(solution.details).toBe(false);
      });

      it('should send analytics event when triggerAnalyticsEventForSolution is called', function() {
        var solution = {
          id: 123,
          name: 'Test Solution'
        };

        spyOn($location, 'search').and.returnValue({
          agency: 8,
          category: 987
        });

        spyOn($analyticsStub, 'eventTrack');

        $scope.triggerAnalyticsEventForSolution('someEvent', solution);

        expect($analyticsStub.eventTrack).toHaveBeenCalledWith('someEvent', {
          label: '{"agency":8,"category":987,"solution":"Test Solution"}',
          value: 123,
          category: 'Solutions Finder'
        });
      });

      it('should send analytics event with additional data when triggerAnalyticsEventForSolution is called', function() {
        var solution = {
          id: 123,
          name: 'Test Solution'
        };

        spyOn($location, 'search').and.returnValue({
          agency: 8,
          category: 987
        });

        spyOn($analyticsStub, 'eventTrack');

        $scope.triggerAnalyticsEventForSolution('someEvent', solution, { test: 'test' });

        expect($analyticsStub.eventTrack).toHaveBeenCalledWith('someEvent', {
          label: '{"agency":8,"category":987,"test":"test","solution":"Test Solution"}',
          value: 123,
          category: 'Solutions Finder'
        });
      });

      it('should set sort solutions', function() {
        $scope.setSortedSolutions($scope.allSolutions);
        expect($scope.sortedSolutions).toEqual($scope.allSolutions);
      });

      it('should open report data issue modal', function() {
        $scope.state = {
          currentSolution: {
            name: 'Test Solution',
            id: 1234
          }
        };

        $scope.reportDataIssue();
        var issue = {
          solutionName: 'Test Solution',
          solutionId: 1234,
          userEmail: AGService.data.user.mail
        };

        expect($scope.issue).toEqual(issue);
        expect($modal).toHaveBeenCalled();
      });

      it('should submit data issue', function() {
        var cb = jasmine.createSpy();
        var toastyClearSpy = spyOn(toasty, 'clear');
        var successSpy = spyOn(toasty, 'success');
        $httpBackend.expect('POST', '/api/v1.0/data-issue').respond({});
        $scope.state = {
          currentSolution: {
            name: 'Test Solution',
            id: 1234
          }
        };
        
        $scope.submitDataIssue(cb);
        expect($scope.processing).toBe(true);
        expect(toastyClearSpy).toHaveBeenCalled();

        $httpBackend.flush();
        expect($scope.processing).toBe(false);
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Thank you for your submission, we appreciate you helping us keep the app current!' });

      });

      it('should get Program Type / Contract Type short name', function() {
        var test = $scope.getShortName('Type 1');
        expect(test).toEqual('Type1');

        var test2 = $scope.getShortName('unknown type');
        expect(test2).toEqual('');
      });

      it('should tell if a Solution Type is a Program Type', function() {
        var test = $scope.isSolutionTypeProgramType('Type 1');
        expect(test).toBe(false);

        var test2 = $scope.isSolutionTypeProgramType('Type 2');
        expect(test2).toBe(true);

        var test3 = $scope.isSolutionTypeProgramType();
        expect(test3).toBe(false);
      });

      it('should submit search term', function() {
        $httpBackend.expect('POST', '/api/v1.0/search-suggestions').respond({ data: []});
        $scope.suggestions = [];
        $scope.moreSearch.search = 'test';
        $scope.submitSearchTerm();
        $httpBackend.flush();

        expect($scope.suggestions.length).toBeGreaterThan(0);
        expect($scope.suggestions[$scope.suggestions.length - 1]).toEqual({ query: 'test' });

        $httpBackend.expect('POST', '/api/v1.0/search-suggestions').respond({ data: [{}]});
        $scope.submitSearchTerm();
        $httpBackend.flush();

        expect($scope.suggestions.length).toBeGreaterThan(0);
        expect($scope.suggestions[$scope.suggestions.length - 1]).toEqual({ query: 'test' });
      });

      it('should open the \'Add to Project\' modal', function() {
        $scope.state = {
          currentSolution: {
            name: 'Test Solution',
            id: 1234
          }
        };
        
        var test = {
          item: $scope.state.currentSolution,
          itemNameField: 'name',
          itemType: 'solution',
          analytics: {
            category: 'Solutions Finder',
            label: angular.toJson($location.search()),
            value: $scope.state.currentSolution.id
          }
        }; 

        $scope.addToProject();

        expect($scope.addToProjectDetails).toEqual(test);
        expect($modal).toHaveBeenCalledWith({
          title: 'Add this solution to a project',
          scope: $scope,
          templateUrl: 'scripts/components/directives/add-to-project/add-to-project-modal.html',
          show: true
        });
      });

      it('should export solutions in non-IE Browsers', function() {
        $scope.init();
        $httpBackend.flush();

        function Blob(data, options) {
        }
        window.Blob = Blob;
        window.URL = {
          createObjectURL: jasmine.createSpy()
        }

        var ceBackup = angular.copy(document.createElement);
        var acBackup = angular.copy(document.body.appendChild);
        var rcBackup = angular.copy(document.body.removeChild);

        var appendChildSpy = spyOn(document.body, 'appendChild');
        var removeChildSpy = spyOn(document.body, 'removeChild');

        var mockDom = {
          download: true,
          setAttribute: jasmine.createSpy(),
          style: { visibility: '' },
          click: jasmine.createSpy()
        };

        document.createElement = function(type) {
          return mockDom;
        }

        $scope.exportSolutions();

        expect(appendChildSpy).toHaveBeenCalledWith(mockDom);
        expect(mockDom.click).toHaveBeenCalled();
        expect(mockDom.style.visibility).toBe('hidden');
        //expect(mockDom.setAttribute).toHaveBeenCalledWith('href', 'testUrl');
        expect(mockDom.setAttribute).toHaveBeenCalledWith('download', 'solutions.csv');
        expect(removeChildSpy).toHaveBeenCalledWith(mockDom);

        document.body.appendChild = acBackup;
        document.body.removeChild = rcBackup;
        document.createElement = ceBackup;
      });

      it('should export solutions in older IE', function() {
        $scope.init();
        $httpBackend.flush();
        var navBackup = angular.copy(navigator);

        navigator = { appName: 'Microsoft Internet Explorer' };

        function Blob(data, options) {
        }
        window.Blob = Blob;
        window.URL = {
          createObjectURL: jasmine.createSpy()
        }

        var mockWindow = {
          document: {
            write: function() {},
            close: function() {},
            execCommand: function() {}
          },
          close: function() {}
        };
        var woBackup = angular.copy(window.open);

        window.open = function() {
          return mockWindow;
        }

        var write = spyOn(mockWindow.document, 'write');
        var close = spyOn(mockWindow.document, 'close');
        var execCommand = spyOn(mockWindow.document, 'execCommand');
        var windowClose = spyOn(mockWindow, 'close');

        $scope.exportSolutions();

        expect(write).toHaveBeenCalled();
        expect(execCommand).toHaveBeenCalledWith('SaveAs', true, 'solutions.csv');
        expect(close).toHaveBeenCalled();
        expect(windowClose).toHaveBeenCalled();

        navigator = navBackup;
        window.open = woBackup;
      });

      it('should export solutions in IE 10', function() {
        $scope.init();
        $httpBackend.flush();

        function Blob(data, options) {
        }
        window.Blob = Blob;
        window.URL = {
          createObjectURL: jasmine.createSpy()
        }

        navigator.msSaveBlob = jasmine.createSpy();
        $scope.exportSolutions();

        expect(navigator.msSaveBlob).toHaveBeenCalledWith(new Blob(), 'solutions.csv');


      });

      it('should handle the addProject.solution event', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('addProject.solution');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Congratulations, your solution was successfully added to your project!' });
      });

      it('should handle the addProject.error.solution event', function() {
        var errorSpy = spyOn(toasty, 'error');
        var clearSpy = spyOn(toasty, 'clear');
        var args = 'Test Solution';
        $rootScope.$broadcast('addProject.error.solution', args);
        expect(clearSpy).toHaveBeenCalled();
        expect(errorSpy).toHaveBeenCalledWith({ msg: 'There was an error adding your ' + args + 'to the project This ' + args + 'may already be located in the selected project' });
      });

      it('should handle the addProject.SolutionsFinderSearch event', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('addProject.SolutionsFinderSearch');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Congratulations, your saved search was successfully added to your project!' });
      });
    });

    describe('searchSolutions Filter', function() {
      var $filter;

      var testSolutions = [
        { name: 'Solution 1', categories: [1, 2, 5]},
        { name: 'Solution 11', categories: [2, 3, 4]},
        { name: 'Solution 2', categories: [1, 7, 8]}
      ];

      beforeEach(module('gateways.solutionFinder'));
      beforeEach(inject(function(_$filter_) {
        $filter = _$filter_;
      }));

      xit('should search for solutions matching a specific subcategory', function() {
        var moreSearch = { subCategory: 8};
        var test = $filter('searchSolutions')(testSolutions, moreSearch);
        expect(test).toEqual([ testSolutions[2] ]);

      });

      it('should return all solutions if no filter criteria is provided', function() {
        var test = $filter('searchSolutions')(testSolutions, {});
        expect(test).toEqual(testSolutions);

      });

      it('should return all solutions that match the search keyword', function() {
        var test = $filter('searchSolutions')(testSolutions, { search: 'solution 1' });
        expect(test.length).toEqual(2);
        expect(test[0]).toEqual(testSolutions[0]);
      });

    });

    describe('searchTypes Filter', function() {
      var $filter;


      var testSolutions = [
        { name: 'Solution 1', type: [1, 2, 5]},
        { name: 'Solution 1', type: [2, 3, 4]},
        { name: 'Solution 1', type: [1, 7, 8]},
        { name: 'Solution 1', type: [4, 11, 9]}
      ];

      beforeEach(module('gateways.solutionFinder'));
      beforeEach(inject(function(_$filter_) {
        $filter = _$filter_;
      }));

      it('should search for solutions matching a specific program type', function() {
        var moreSearch = { programTypes: [8, 3]};
        var test = $filter('searchTypes')(testSolutions, moreSearch);
        expect(test).toEqual([ testSolutions[1], testSolutions[2] ]);
      });

      it('should search for solutions matching a specific contract type', function() {
        var moreSearch = { contractTypes: [1, 11]};
        var test = $filter('searchTypes')(testSolutions, moreSearch);
        expect(test).toEqual([ testSolutions[0], testSolutions[2], testSolutions[3] ]);
      });

      it('should return all solutions if no filter criteria is provided', function() {
        var test = $filter('searchTypes')(testSolutions, {});
        expect(test).toEqual(testSolutions);

      });

    });

    describe('agencySearch  Filter', function() {
      var $filter;

      var testSolutions = [
        { name: 'Solution 1', availableToId: 2},
        { name: 'Solution 1', availableToId: 3 },
        { name: 'Solution 1', availableToId: 5}
      ];

      beforeEach(module('gateways.solutionFinder'));
      beforeEach(inject(function(_$filter_) {
        $filter = _$filter_;
      }));

      it('should search for solutions matching a specific agency', function() {
        var moreSearch = {
          availableTo: {
            id: 3,
            fkOptionParentId: 2,
            name: 'Agency 1'

          }
        };
        var test = $filter('agencySearch')(testSolutions, moreSearch);
        expect(test).toEqual([ testSolutions[0], testSolutions[1] ]);
      });

      it('should search for solutions matching a specific agency group', function() {
        var moreSearch = {
          availableTo: {
            id: 3,
            name: 'Agency 1'
          }
        };
        var test = $filter('agencySearch')(testSolutions, moreSearch);
        expect(test).toEqual([ testSolutions[1] ]);
      });

      it('should return all solutions if no filter criteria is provided', function() {
        var test = $filter('agencySearch')(testSolutions, {});
        expect(test).toEqual(testSolutions);
      });

    });

    describe("Contract Solutions Search Directive Controller", function() {
      var $scope,
        $controller,
        $compile,
        $locationSpy,
        $httpBackend, 
        AGServiceSpy;

      beforeEach(module('gateways.solutionFinder'));
      beforeEach(module('templates'));

      beforeEach(inject(function(_$controller_, _$rootScope_, AGService, $cacheFactory, _$httpBackend_, _$compile_) {
        $scope = _$rootScope_.$new();
        $controller = _$controller_
        $locationSpy = jasmine.createSpyObj('$location', [ 'path', 'search' ]);
        AGServiceSpy = AGService;
        spyOn(AGService, 'getMenu').
          and.callFake(function(val) {
            AGService.data.menu = val;
          });
        $cacheFactory.get('$http').removeAll();
        $httpBackend = _$httpBackend_;
        $compile = _$compile_;

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/solutions-finder-user-agency/dev').respond({ data: [ { id: 1234 }]});
        $httpBackend.when('POST', '/api/v1.0/solutions-finder-user-agency?agency=dev').respond({ data: [ { id: 1234 }]});
        $httpBackend.when('GET', '/api-old/Categories/retrieve').respond(testCategories);
        $httpBackend.when('GET', '/api-old/SubCategories/retrieve').respond(testSubCategories);
        $httpBackend.when('GET', '/api-old/SolutionTypes/retrieve').respond(solutionTypes);
        $httpBackend.when('GET', '/api-old/ContractSolutions/retrieve').respond(testSolutions);
        $httpBackend.when('GET', '/api-old/AvailableTo/retrieve').respond(testAvailableTo);
        $httpBackend.when('GET', '/api/v1.0/navigation/menu-solutions-finder').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/search-suggestions').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/help/solutions-finder').respond({ data: []});
        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=pin&filter%5Btype%5D=solution').respond({ data: [{ itemId: 987 }]});

        $controller('SolutionsFinderDirectiveController', {
          $scope: $scope,
          $location: $locationSpy
        });
      }));
        
      it('should compile the Solutions Finder Widget directive', function() {
        var element = $compile('<div ag-solutions-finder></div>')($scope);
        $scope.$digest();
        expect(element.html()).toContain('<form class="widget solutions-finder form-horizontal ng-pristine ng-valid">');
      });

      it('should revert to AGService data to the state before initializing ContractSolutionSearchController', function() {
        var original = {
            banner: {
              env: [ 'hi' ],
              title: 'hi',
              subtitle: 'hi',
              klass: 'hi'
            },
            navigation: { 'hi': 'hi' }
          },
          changed = {
            banner: {
              env: [ 'bye' ],
              title: 'bye',
              subtitle: 'bye'
            },
            navigation: { 'bye': 'bye' }
          },
          $controllerSpy = jasmine.createSpy('$controller').
            and.callFake(function() {
              AGServiceSpy.data.banner.env = [ 'bye' ];
              AGServiceSpy.data.banner.title = 'bye';
              AGServiceSpy.data.banner.subtitle = 'bye';
              AGServiceSpy.data.banner.klass = 'bye';
              AGServiceSpy.data.navigation = { 'bye': 'bye' };
              AGServiceSpy.getMenu('bye');
            }),
          expected;

        AGServiceSpy.data = original;
        AGServiceSpy.getMenu('hi');

        expected = angular.copy(original);
        expected.menu = 'hi';

        expect(AGServiceSpy.data).toEqual(expected);

        AGServiceSpy.getMenu.calls.reset();

        $controller('SolutionsFinderDirectiveController', {
          $scope: $scope,
          $location: $locationSpy,
          $controller: $controllerSpy
        });

        expect($controllerSpy).toHaveBeenCalledWith('SolutionsFinderController', jasmine.any(Object));

        expect(AGServiceSpy.getMenu.calls.count()).toEqual(2);
        expect(AGServiceSpy.getMenu.calls.argsFor(0)).toEqual([ 'bye' ]);
        expect(AGServiceSpy.getMenu.calls.argsFor(1)).toEqual([ 'hi' ]);
        expect(AGServiceSpy.data).toEqual(expected);
      });

      it('should redirect with given params', function() {
        var params = {
          string: 's',
          array: [ 'a', 'b', 'c' ],
          object: { string: 'os' },
          nestedObject: { object: { id: 1 } },
          agency: 'GSA'
        },
        expectedCallParams = {
          string: 's',
          array: 'a,b,c',
          object: 'os',
          nestedObject: '1',
          agency: 'GSA'
        };

        $scope.submitQuery(angular.copy(params));

        expect($locationSpy.path).toHaveBeenCalledWith('solutionsfinder');
        expect($locationSpy.search).toHaveBeenCalledWith(expectedCallParams);

        delete params.agency;
        expectedCallParams.agency = 'false';
        $locationSpy.search.calls.reset();

        $scope.submitQuery(angular.copy(params));
        expect($locationSpy.search).toHaveBeenCalledWith(expectedCallParams);
      });

      it('should set categories and subcategories by default', function() {
        $scope.defaults = { categories: [ "1" ], subcategories: [ "2" ] };
        $scope.allSubcategories = [ { id: "2" } ];
        $scope.autoSelect();
        expect($scope.moreSearch.categories).toEqual($scope.defaults.categories);
        expect($scope.moreSearch.subcategories).toEqual($scope.allSubcategories);
      });

      it('should do no autoselect if data is not available', function() {
        $scope.autoSelect();
        expect($scope.moreSearch.categories).toEqual(undefined);
        expect($scope.moreSearch.subcategories).toEqual(undefined);

        $scope.defaults = { categories: [ "1" ]};
        $scope.autoSelect();
        expect($scope.moreSearch.categories).toEqual($scope.defaults.categories);
        expect($scope.moreSearch.subcategories).toEqual(undefined);
      });

      it('should clear default watch', function() {
        $scope.$digest();
        $scope.defaults = { categories: [ "1" ], subcategories: [ "2" ] };
        $scope.$digest();
      });

    });

  }
);
