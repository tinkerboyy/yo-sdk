//require all dependencies or rely on module to have all the dependencies included?
//currently missing data-service.js
define(
  [
    'angular',
    'lodash',
    'angulartics',
    'angularRoute',
    'angularSanitize',
    'angularStrap',
    'angularStrapTpl',
    'angularToasty',
    'components/components-module',
    'components/directives/pagination/pagination-directive',
    'components/directives/applied-filters/applied-filters-directive',
    'components/services/filter-count-tracker',
    'components/directives/sort/sort-directive',
    'components/directives/as-scrollable/as-scrollable-directive',
    'components/directives/smart-select/smart-select-directive'
  ],
  function (angular, _) {
    var dependencies = [ 'ngRoute', 'mgcrea.ngStrap', 'angulartics', 'angular-toasty', 'gateways.components' ],
      feature = angular.module('gateways.solutionFinder', dependencies);
      feature.config(function($routeProvider) {
        $routeProvider.when('/solutionsfinder/:id?', {
          controller: 'SolutionsFinderController',
          templateUrl: 'scripts/features/solutions-finder/solutions-finder.html',
          reloadOnSearch: false
        });
        $routeProvider.otherwise({
          redirectTo: '/'
        });
      });
      /**
        * Searches Solutions by Category for a solution that matches the complete set of selected categories
        * @param solutions {array} List of solutions
        * @param categories {array} Categories to match
        * @return out {array} List of solutions matching search criteria
        */
      feature.filter('categorySearch', function() {
        return function(solutions, categories) {
          var out = [];
          angular.forEach(solutions, function(solution) {
            if ( _.intersection(categories, solution.categories).length === categories.length) {
              out.push(solution);
            }
          });

          return out;
        };
      })

      /**
        * Searches Solutions by SubCategory for a solution that matches the complete set of selected categories
        * @param solutions {array} List of solutions
        * @param subcategories {array} Categories to match
        * @return out {array} List of solutions matching search criteria
        */
      .filter('subcategorySearch', function() {
        return function(solutions, subcategories) {
          var subcats = _.map(subcategories, function(subcat) {
              return subcat.id;
            })
            , out = [];

          angular.forEach(solutions, function(solution) {
            if ( _.intersection(subcats, solution.categories).length === subcategories.length) {
              out.push(solution);
            }
          });

          return out;
        };
      })

      /**
        * Filters by Solution Types for a match containing one or more of the selected solution types
        * @param data {array} List of solutions to search
        * @param moreSearch {object} Extra search criteria not automatically applied
        * @return solutions {array} List of solutions filtered by solution type
        */
      .filter('searchTypes', function() {
        return function(data, moreSearch) {
          var solutions = []
            , programTypes = moreSearch.programTypes
            , contractTypes = moreSearch.contractTypes;

          if ((programTypes && programTypes.length > 0) || (contractTypes && contractTypes.length > 0)) {
            angular.forEach(data, function(solution) {
              if ((_.intersection(solution.type, programTypes)).length > 0 ||
                  (_.intersection(solution.type, contractTypes)).length > 0) {
                solutions.push(solution);
              }
            });
          } else {
            solutions = data;
          }
          return solutions;
        };
      })
      /**
        * Searches solutions by agency
        * @param data {array} List of solutions to search
        * @param moreSearch {object} Extra search criteria not automatically applied
        * @return solutions {array} list of solutions matching search criteria
        */
      .filter('agencySearch', function($filter) {
        return function(solutions, moreSearch) {
          var availableTo = moreSearch.availableTo
            , out = [];

          //If available to is selected
          if (availableTo && availableTo.name) {

            //filter options based on the parent
            if (availableTo.fkOptionParentId) {
              out = out.concat($filter('filter')(solutions, { availableToId: availableTo.fkOptionParentId }, true));
            }

            //Filter results based on All Agencies
            out = out.concat($filter('filter')(solutions, { availableToId: '1' }, true));

            //Filter results based on selected option
            out = out.concat($filter('filter')(solutions, { availableToId: availableTo.id }, true));

          } else {
            out = solutions;
          }
          return out;
        };
      })

      /**
        * Searches solutions by all search parameters
        * @param solutions {array} List of solutions
        * @param moreSearch {array} Search object to use in searching
        * @return out {array} List of solutions matching search criteria
        */
      .filter('searchSolutions', function($filter) {
        return function(solutions, moreSearch) {

          //Remove pinned solutions
          solutions = $filter('filter')(solutions, { pinned: '!true' });

          //Filter by availableTo
          if (moreSearch.availableTo) {
            solutions = $filter('agencySearch')(solutions, moreSearch);
          }

          //Filter by Category
          if (moreSearch.categories && moreSearch.categories.length > 0) {
            solutions = $filter('categorySearch')(solutions, moreSearch.categories);
          }

          //Filter by Subcategory
          if (moreSearch.subcategories && moreSearch.subcategories.length > 0) {
            solutions = $filter('subcategorySearch')(solutions, moreSearch.subcategories);
          }

          //Filter by Contract Types/Program Types
          if ((moreSearch.contractTypes && moreSearch.contractTypes.length > 0) ||
              (moreSearch.programTypes && moreSearch.programTypes.length >0)) {
            solutions = $filter('searchTypes')(solutions, moreSearch);
          }

          //Apply Search
          if (moreSearch.search) {
            solutions = $filter('filter')(solutions,  moreSearch.search);
          }

          return solutions;
        };
      })

      /**
        * Retrieves all the subcategories for a given category
        @param subcategories {array} List of all subcategories
        @param categories {array} List of categories to filter by
        @return out {array} List of subcategories filtered by selected categories
        */
      .filter('getSubcats', function() {
        return function(subcategories, category) {
          if (category) {
            var out = [];
            angular.forEach(subcategories, function(subcategory) {
              if (subcategory.categoryId === category) {
                out.push(subcategory);
              }
            });

            return out;
          }
        };
      })

      /**
        * Returns the list of categories from the combined category / subcategory collection
        * @param categories {array} List of category objects to filter
        * @param filter {array} list of categories for a specific solution
        * @return out {array} list of filtered categories
        */
      .filter('sfGetCategories', function($filter) {
        return function(categories, filter) {
          var out = [];
          //Loop through the categories for the specific solution
          if (filter) {
            for (var i = 0; i < filter.length; i++) {
              var id = filter[i].trim();
              //Check for and skip empty values in the filter array
              if (id.length > 0) {
                //Search for a category matching the ID, eliminates subcategories
                var cat = $filter('filter')(categories, { id: id }, true);
                if (cat.length > 0) {
                  out.push(cat[0]);
                }
              }
            }
          }
          return out;

        };
      })
      /**
        * Returns the list of subcategories from the combined category / subcategory collection
        * @param categories {array} List of subcategory objects to filter
        * @param filter {array} list of categories for a specific solution
        * @param categoryId {int} ID of the category to fetch subcategories for
        * @return out {array} list of filtered categories
        */
      .filter('getSubCategories', function($filter) {
        return function(categories, filter, categoryId) {
          var out = [];
          if (filter) {
            for (var i = 0; i < filter.length; i++) {
              var id = filter[i].trim();
              //Eliminate empty category Ids
              if (id.length > 0) {
                //retrieve subcategories with parentId mathing the categoryId
                var cat = $filter('filter')(categories, { id: id, categoryId: categoryId }, true);
                if (cat && cat.length > 0) {
                  out.push(cat[0]);
                }
              }
            }
          }
          return out;

        };
      })
      .controller('SolutionsFinderController', function ($scope, DataService, AGService, FilterCountTracker, $filter, $location, $modal, toasty, $analytics, $appliedFilters, $routeParams, $agVotes, $window) {
        DataService.setDataLayerContext('Solutions Finder');
        $scope.publicUser = AGService.data.publicUser;
        $scope.init = function() {
          if (!$scope.isDirective) {
            $window.scrollTo(0,0);
          }

          //Set Feature Header
          AGService.data.banner.title = '';
          AGService.data.banner.subtitle = '';
          AGService.data.search.show = false;
          AGService.data.banner.env = ['learn', 'connect', 'act'];
          AGService.getMenu('menu-solutions-finder');
          AGService.data.banner.klass = 'upperClass';
          AGService.data.navigation.myProfile = true;
          AGService.data.navigation.signOut = true;

          $scope.search = { categories: [] };
          $scope.solutionType = { id: 1 };
          $scope.moreSearch = {};
          $scope.allSubcategories = [];
          $scope.categories = [];
          $scope.availableTo = [];
          $scope.solutionsPage = [];
          $scope.solutions = [];
          $scope.allSolutions = [];
          $scope.state = {};
          $scope.accordianSelects = {
            agency: {
              expanded: false
            }
          };
          $scope.sortedSolutions = [];
          $scope.pageSolutions = [];

          //Options dropdown menu
          $scope.optionsDropdown = [
            {
              text: '<i class="fa fa-share-square-o"></i> Add to a project',
              click: 'addToProject($item)'
            },
            {
              text: '<i class="fa fa-exclamation-triangle"></i> Report Data Issue',
              click: 'reportDataIssue($item)'
            }
          ];

          //Sorting
          $scope.sort = {
            field: 'name',
            reverseOrder: false
          };
          $scope.sortOptions = [
            {
              field: 'availableTo',
              label: 'Availability',
              defaultOrder: false
            },
            {
              field: 'managingAgencyShortName',
              label: 'Managed by agency',
              defaultOrder: false
            }
          ];

          if (!$scope.publicUser) {
            $scope.sortOptions.push({
              field: 'votes',
              label: 'Recommend Count',
              defaultOrder: true,
              getSortValue: function(item) {
                return item.votes ? item.votes : 0;
              }
            });
          }

          $scope.sortOptions.push({
            field: 'name',
            label: 'Solution name',
            defaultOrder: false
          });

          //Initialize Filter Count Tracker
          $scope.filterCountUpdater = FilterCountTracker;
          $scope.filterCountUpdater.reset();
          $scope.filterCountUpdater.addFilterGroup('availableTo', false, null, {
            getFilterOptionKey: function(item) {
              return item.id;
            },
            getItemsForSelectedFiltersInGroup: function(groupKey, filterGroup, selectedFilters) {
              if (selectedFilters.availableTo) {
                return _.union(
                  this.itemSets.availableTo['1'],
                  this.itemSets.availableTo[selectedFilters.availableTo.fkOptionParentId],
                  this.itemSets.availableTo[selectedFilters.availableTo.id]
                );
              }
              return this.itemSets.all;
            },
            getItemsForFilter: function(groupKey, filterGroup, filterOption) {
              return _.union(
                this.itemSets.availableTo[filterOption.id],
                this.itemSets.availableTo['1'],
                this.itemSets.availableTo[filterOption.fkOptionParentId]
              );
            }
          });
          $scope.filterCountUpdater.addFilterGroup('categories', true, 'AND');
          $scope.filterCountUpdater.addFilterGroup('subcategories', true, 'AND');
          $scope.filterCountUpdater.addFilterGroup('type', true, 'OR', {
            selectedFilterKey: 'solutionTypes'
          });

          //Set up applied filter directive
          $appliedFilters.addFilterGroup('availableTo', { multiple: false });
          $appliedFilters.addFilterGroup('programTypes', { multiple: true });
          $appliedFilters.addFilterGroup('contractTypes', { multiple: true });
          $appliedFilters.addFilterGroup('categories', { multiple: true });
          $appliedFilters.addFilterGroup('subcategories', { multiple: true });

          var addSolutionToFilterUpdater = function(solution) {
            var alwaysShown = false,
              matchingFilters = {};

            if (solution.pinned) {
              alwaysShown = true;
            }

            if (solution.availableToId) {
              matchingFilters.availableTo = [solution.availableToId];
            }

            if (solution.categories) {
              matchingFilters.categories = solution.categories;
              matchingFilters.subcategories = solution.categories;
            }

            if (solution.type) {
              matchingFilters.type = solution.type;
            }

            $scope.filterCountUpdater.addItem(solution.id, matchingFilters, alwaysShown);
          };

          //If we have search param in URL then add it to moreSearch object
          if ($location.search().search) {
            $scope.moreSearch.search = $location.search().search;
          }

          //Get all solutions
          DataService.Solutions.query(function(data) {
            //get User Preferences
            DataService.Preferences.get({
              'filter[type]': 'solution' ,
              'filter[action]': 'pin'
            }, function(pinned) {
              var pins = _.map(pinned.data, function(item) {
                return item.itemId.toString();
              });
              angular.forEach(data, function(solution) {
                if (pins.indexOf(solution.id) >= 0) {
                  solution.pinned = 'true';
                }
                addSolutionToFilterUpdater(solution);
              });
              $scope.allSolutions = data;
              if ($routeParams.id) {
                $scope.singleSolution = true;
                $scope.solutions = $filter('filter')(data, { id: $routeParams.id }, true);
                $scope.solutions[0].details = true;
                $scope.viewStatus = $scope.solutions.length > 0;
              }
              //For sorting we need all votes
              $agVotes.mergeVotesWithCollection('solution', $scope.allSolutions).then(function() {
                $scope.changeFilter();
              });
            });
          });

          //Get all solution types
          DataService.SolutionTypes.query(function(data) {
            if ($location.search().programTypes) {
              $scope.moreSearch.programTypes = $location.search().programTypes.split(',');
            }

            if ($location.search().contractTypes) {
              $scope.moreSearch.contractTypes = $location.search().contractTypes.split(',');
            }

            //initializes solution types filter to select all if any other filters are selected
            $scope.solutionTypes = data;
            //initializes contract types/program types filters to select all if any other filters are selected
            $scope.solutionTypeNameMap = {};
            $scope.contractTypes = [];
            $scope.programTypes = [];
            angular.forEach(data, function(item) {
              //Create map of full name to short names for contract/program types
              $scope.solutionTypeNameMap[item.name] = item;

              if (item.Type === 'Contract') {
                $scope.contractTypes.push(item);
                $appliedFilters.addFilterDisplayName('contractTypes', item.name, item.shortName);
              } else if (item.Type === 'Program') {
                $scope.programTypes.push(item);
                $appliedFilters.addFilterDisplayName('programTypes', item.name, item.shortName);
              }
              $scope.filterCountUpdater.addFilterOption('type', item.name);
            });
          });

          //Get all Available to options
          DataService.AvailableTo.query(function(data) {
            for (var i = 0; i < data.length; i++) {
              $scope.filterCountUpdater.addFilterOption('availableTo', data[i]);
              $appliedFilters.addFilterDisplayName('availableTo', data[i].id, data[i].name);
            }
            $scope.availableTo = data;

            //If available to Id is available in the URL query, apply
            if ($location.search().agency) {
              $scope.moreSearch.availableTo = $filter('filter')(data, { id: $location.search().agency }, true)[0];
            }

            //Get User Agency Guess
            if (!$scope.publicUser) {
              if ($location.search().agency !== 'false') {
                var userAgency = AGService.data.user.user_info.cas ? AGService.data.user.user_info.cas['Org-Agency-Name'] : null;
                //if match for agency in agencies list is not found, ask for guess
                if (userAgency && $filter('filter')(data, { name: userAgency }).length === 0 && !$scope.moreSearch.availableTo) {
                  DataService.SolutionsFinderUserAgency.get({ agency: userAgency }, function(userData) {
                    if (userData.data.length > 0) {
                      $scope.moreSearch.availableTo = $filter('filter')(data, { id: userData.data[0].fkOptionId }, true)[0];
                    }
                    $scope.userAgency = $scope.moreSearch.availableTo;
                    $scope.changeFilter();
                  });
                } else if (userAgency && !$scope.moreSearch.availableTo) {
                  $scope.moreSearch.availableTo = $filter('filter')(data, { name: userAgency }, true)[0];
                  $scope.userAgency = $scope.moreSearch.availableTo;
                }
              }
            }
          });

          //Get all categories
          DataService.Categories.query(function(data) {
            for (var i = 0; i < data.length; i++) {
              $scope.filterCountUpdater.addFilterOption('categories', data[i].id);
              $appliedFilters.addFilterDisplayName('categories', data[i].id, data[i].name);
            }

            $scope.categories = $filter('orderBy')(data, 'name');

            //If a category is available in the URL query
            if ($location.search().category) {
              $scope.moreSearch.categories = $location.search().category.split(',');
            }

            if ($location.search().search) {
              $scope.moreSearch.search = $location.search().search;

            }

          });

          //Get all subcategories
          DataService.SubCategories.query(function(data) {
            for (var i = 0; i < data.length; i++) {
              $scope.filterCountUpdater.addFilterOption('subcategories', data[i].id);
              $appliedFilters.addFilterDisplayName('subcategories', data[i].id, data[i].name);
            }
            $scope.allSubcategories = $filter('orderBy')(data, 'name');

            //If a subcategory is available in the URL query
            if ($location.search().subcategory) {
              var subcats = $location.search().subcategory.split(',')
                , subcategories = [];

              for (var j = 0; j < subcats.length; j++) {
                subcategories.push($filter('filter')($scope.allSubcategories, { id: subcats[j] }, true)[0]);
              }

              $scope.moreSearch.subcategories = subcategories;
            }
          });

          //Get Help Articles
          DataService.Help.get({ featureName: 'solutions-finder' }, function(data) {
            $scope.help = data.data;
          });

          DataService.SearchSuggestions.get(function(data) {
            $scope.suggestions = data.data;
          });
        };

        //Set the view status based on the status of various components
        $scope.setViewStatus = function() {
          $scope.viewStatus = true;
        };

        //Clear search terms
        $scope.toggleSearch = function() {
          //Our call to changeFilter is going to run update on filterCountUpdater
          //so disable to keep it from running before then
          $scope.filterCountUpdater.enabled = false;
          //If showing single solution
          if ($routeParams.id) {
            delete $scope.solutions[0].details;
            $scope.singleSolution = false;
          }

          $scope.moreSearch = {};
          $scope.moreSearch.contractTypes = [];
          $scope.moreSearch.programTypes = [];
          $scope.moreSearch.categories = [];
          $scope.moreSearch.subcategories = [];
          $scope.moreSearch.availableTo = null;
          $scope.solutions = [];
          $scope.setSolutions($scope.solutions);
          $scope.setSubcategories();
          $scope.filterCountUpdater.enabled = true;
          $scope.changeFilter();
        };

        /**
          * Gets the string name of a category from the Id
          * @param categoryId {int} ID of the category to check for
          */
        $scope.getCategoryName = function(categoryId) {
          return $filter('filter')($scope.categories.concat($scope.allSubcategories), { id: categoryId })[0].name;
        };

        /**
          * Clears search terms for a specific filter when the 'Select' option is selected
          */
        $scope.firstChangeFilter = true;
        $scope.changeFilter = function() {
          //If displaying a single solution, do not filter
          if ($scope.singleSolution) {
            return false;
          }

          if (($scope.userAgency !== $scope.moreSearch.availableTo) && $scope.moreSearch.availableTo && !$scope.publicUser) {
            DataService.SolutionsFinderUserAgency.create({
              agency: AGService.data.user.user_info.cas ? AGService.data.user.user_info.cas['Org-Agency-Name'] : 'dev',
              availableTo: $scope.moreSearch.availableTo.id
            });
          }

          $scope.solutions = $filter('searchSolutions')($scope.allSolutions, $scope.moreSearch);

          $scope.numSolutions = $filter('filter')($scope.solutions, function(solution) { return solution.pinned !== true; }).length +
            $filter('filter')($scope.allSolutions, { pinned: true }).length;

          var selectedFilters = _.clone($scope.moreSearch);
          if ($scope.moreSearch.contractTypes || $scope.moreSearch.programTypes) {
            selectedFilters.solutionTypes = _.union(
              $scope.moreSearch.contractTypes,
              $scope.moreSearch.programTypes
            );
            delete selectedFilters.contractTypes;
            delete selectedFilters.programTypes;
          }
          if (selectedFilters.subcategories) {
            selectedFilters.subcategories = _.map(selectedFilters.subcategories, function(sc) {
              return sc.id;
            });
          }
          $scope.filterCountUpdater.update(selectedFilters);
          if ($scope.solutions.length === 0) {
            $scope.setSolutions([]);
          }

          $scope.setViewStatus();

          //If on solution finder page, update URL with search terms
          if (!$scope.isDirective) {
            AGService.data.banner.lcaFixed = true;
            var out = []
              , allKeys = ['availableTo', 'programTypes', 'contractTypes', 'categories', 'subcategories', 'search']
              , map = {
                  availableTo: 'agency',
                  categories: 'category',
                  subcategories: 'subcategory'
                };
            _.forEach(allKeys, function(key) {
              var value = $scope.moreSearch[key];
              key = map[key] || key;
              if (angular.isArray(value)) {
                value = _.map(value, function(val) {
                  return val.id || val;
                });
                value = value.join(',');
              }
              if (angular.isObject(value) && !angular.isArray(value)) {
                value = value.id;
              }
              if (key === 'agency' && !value) {
                value = 'false';
              }
              $location.search(key, value || null);
              out.push(key + '=' + encodeURI(value));
            });

            if ($scope.firstChangeFilter) {
              //First time changeFilter is called only when page is loaded
              //Trigger analytics event whenever solutions finder is opened
              $analytics.eventTrack('View Solution Finder', {
                label: angular.toJson($location.search()),
                category: 'Solutions Finder'
              });
              $scope.firstChangeFilter = false;
            }
          }

          $window.scrollTo(0,0);
          DataService.setDataLayer({ solutionsFinderFilters: $scope.moreSearch });
        };

        $scope.triggerAnalyticsEventForSolution = function(eventName, solution, additionalEventData) {
          var eventData = {};

          if (typeof additionalEventData === 'undefined') {
            additionalEventData = {};
          }

          angular.extend(eventData, $location.search(), additionalEventData);

          eventData.solution = solution.name;

          $analytics.eventTrack(eventName, {
            label: angular.toJson(eventData),
            value: solution.id,
            category: 'Solutions Finder'
          });
        };

        /**
         * Callback for ag-pin directive for when pin is toggled
         */
        $scope.togglePinned = function(solution) {
          var eventName = solution.pinned ? 'pinned' : 'unpinned',
            additionalEventData = {};

          additionalEventData['Total Solutions Pinned'] = $filter('filter')($scope.allSolutions, { pinned: true }).length;

          //Events for when solution is pinned/unpinned
          $scope.triggerAnalyticsEventForSolution('solution.' + eventName, solution, additionalEventData);

          if (solution.pinned) {
            FilterCountTracker.addAlwaysShownItem(solution.id);
          } else {
            FilterCountTracker.removeAlwaysShownItem(solution.id);
          }
          $scope.changeFilter();
        };

        //$scope.$on('pinned.notify', function() {
        //  toasty.success({
        //    msg: 'Your solution has been pinned to the top of the results!'
        //  });
        //});

          //$scope.notifyPinned = function() {
          //  toasty.success({
          //    msg: 'Your solution has been pinned to the top of the results!'
          //  });
          //};

        $scope.toggleShowMore = function(solution) {
          var eventName = solution.details ? 'hideDetails' : 'showDetails';

          solution.details = !solution.details;

          $scope.triggerAnalyticsEventForSolution('solution.' + eventName, solution);
        };

        $scope.setSubcategories = function() {
          var out = [],
            categories = $filter('sfGetCategories')($scope.categories, $scope.moreSearch.categories);
          angular.forEach(categories, function(category) {
            out.push(category);
            out = out.concat($filter('filter')($scope.allSubcategories, { categoryId: category.id }, true));
          });

          //Make sure only subcategories that have a currently selected parent are selected
          var newSelectedSubcats = [];
          angular.forEach($scope.moreSearch.subcategories, function(subcategory) {
            if (out.indexOf(subcategory) !== -1) {
              newSelectedSubcats.push(subcategory);
            }
          });

          $scope.subCategories = out;
          if (newSelectedSubcats.length) {
            $scope.moreSearch.subcategories = newSelectedSubcats;
          } else {
            delete $scope.moreSearch.subcategories;
          }

          $scope.changeFilter();
        };

        $scope.setSolutions = function(solutions) {
          $scope.pageSolutions = solutions;
        };

        $scope.setSortedSolutions = function(solutions) {
          $scope.sortedSolutions = solutions;
        };

        $scope.reportDataIssue = function() {
          $scope.issue = {
            solutionName: $scope.state.currentSolution.name,
            solutionId: $scope.state.currentSolution.id,
            userEmail: AGService.data.user.mail
          };

          $modal({
            title: 'Report Data Issue',
            scope: $scope,
            show: true,
            contentTemplate: 'scripts/features/solutions-finder/data-issue-form.html',
            placement: 'left'
          });
        };

        $scope.submitDataIssue = function(cb) {
          toasty.clear();
          $scope.processing = true;
          DataService.DataIssue.create($scope.issue, function() {
            $scope.issue = {};
            cb();
            $scope.processing = false;
            toasty.success({
              msg: 'Thank you for your submission, we appreciate you helping us keep the app current!'
            });
          });
        };

        $scope.getShortName = function(name) {
          if (!_.isUndefined($scope.solutionTypeNameMap[name])) {
            return $scope.solutionTypeNameMap[name].shortName;
          }
          return '';
        };

        $scope.isSolutionTypeProgramType = function(name) {
          if (!_.isUndefined($scope.solutionTypeNameMap[name])) {
            return $scope.solutionTypeNameMap[name].Type === 'Program';
          }
          return false;
        };

        $scope.exportSolutions = function() {
          var output = []
            , solutions = $filter('filter')($scope.allSolutions, { pinned: 'true' }).concat($scope.solutions)
            , keys = Object.keys(solutions[0]);

          //remove hashkey from list of keyts
          keys.splice(keys.indexOf('$$hashKey'), 1);

          //Remove servicesProvidedText field
          keys.splice(keys.indexOf('servicesProvidedText'));

          output.push(keys);

          //Loop through solutions and convert to csv string
          angular.forEach(solutions, function(solution) {
            var soln = [],
            workingSolution = angular.copy(solution),
            categories = [],
            subcategories = [];

            //convert category IDs to category names
            angular.forEach(solution.categories, function(category) {
              categories.push($scope.getCategoryName(category));
            });
            workingSolution.categories = categories.join(', ');

            //convert subcategory IDs to subcategory names
            angular.forEach(solution.subcategories, function(subcategory) {
              subcategories.push($scope.getCategoryName(subcategory));
            });
            workingSolution.subcategories = subcategories.join(', ');

            //convert solution object to CSV String
            for (var i = 0; i < keys.length; i++) {
              var data = (keys[i] === 'servicesProvided' && workingSolution.servicesProvidedText) ? workingSolution.servicesProvidedText.replace(/(\r\n|\n|\r)/gm, '') : workingSolution[keys[i]];
              soln.push('"' + data + '"');
            }

            //Add Solution CSV string to output array
            output.push(soln.join(','));
          });

          var out = output.join('\n\r')
            , blob = new Blob([out], { type: 'text/csv;charset=utf-8;' });

          if (navigator.msSaveBlob) { // IE 10+
            navigator.msSaveBlob(blob, 'solutions.csv');
          } else {
            var link = document.createElement('a');
            if (link.download !== undefined) {
              var url = URL.createObjectURL(blob);
              link.setAttribute('href', url);
              link.setAttribute('download', 'solutions.csv');
              link.style.visibility = 'hidden';
              document.body.appendChild(link);
              link.click();
              document.body.removeChild(link);
            }
          }

          if (navigator.appName === 'Microsoft Internet Explorer') {
            var oWin = window.open();
            oWin.document.write('sep=,\r\n' + out);
            oWin.document.close();
            oWin.document.execCommand('SaveAs', true, 'solutions.csv');
            oWin.close();
          }
        };

        $scope.submitSearchTerm = function() {
          DataService.SearchSuggestions.create({ search: $scope.moreSearch.search }, function(data) {
            if (data.data.length === 0) {
              $scope.suggestions.push({
                query: $scope.moreSearch.search
              });
            }
          });
        };

        $scope.addToProject = function() {
          $scope.addToProjectDetails = {
            item: $scope.state.currentSolution,
            itemNameField: 'name',
            itemType: 'solution',
            analytics: {
              category: 'Solutions Finder',
              label: angular.toJson($location.search()),
              value: $scope.state.currentSolution.id
            }
          };
          $modal({
            title: 'Add this solution to a project',
            scope: $scope,
            templateUrl: 'scripts/components/directives/add-to-project/add-to-project-modal.html',
            show: true
          });
        };

        $scope.$on('addProject.solution', function() {
          toasty.success({
            msg: 'Congratulations, your solution was successfully added to your project!'
          });
        });

        $scope.$on('addProject.SolutionsFinderSearch', function() {
          toasty.success({
            msg: 'Congratulations, your saved search was successfully added to your project!'
          });
        });

        $scope.$on('addProject.error.solution', function(evt, args) {
          toasty.clear();
          toasty.error({
            msg: 'There was an error adding your ' + args + 'to the project This ' + args + 'may already be located in the selected project'
          });
        });

        $scope.init();

      }
    )
    .controller('SolutionsFinderDirectiveController',
      function($scope, $controller, $location, $filter, AGService) {

        var agServiceBkupData = angular.copy(AGService.data);

        //instantiating ContractSolutionSearchController.
        $scope.isDirective = true;
        $controller('SolutionsFinderController', { $scope: $scope });

        AGService.data.banner.title = agServiceBkupData.banner.title;
        AGService.data.banner.subtitle = agServiceBkupData.banner.subtitle;
        AGService.data.banner.env = agServiceBkupData.banner.env;
        AGService.data.banner.klass = agServiceBkupData.banner.klass;
        AGService.data.navigation = agServiceBkupData.navigation;
        AGService.getMenu(agServiceBkupData.menu);

        $scope.autoSelect = function() {
          if ($scope.defaults && $scope.defaults.categories) {
            $scope.moreSearch.categories = $scope.defaults.categories;
            $scope.setSubcategories();
            if ($scope.defaults.subcategories) {
              $scope.moreSearch.subcategories = _.filter($scope.allSubcategories, function(sc) {
                return $scope.defaults.subcategories.indexOf(sc.id) > -1;
              });
            }
          }
        };

        //SubmitQuery event handler.
        $scope.submitQuery = function(params) {
          for (var key in params) {
            if (params.hasOwnProperty(key) && angular.isObject(params[key])) {
              params[key] = (_.map(params[key], function(param) {
                return (angular.isObject(param) ? param.id : param).toString();
              })).toString();
            }
          }
          if (!params.agency) {
            params.agency = 'false';
          }
          $location.path('solutionsfinder');
          $location.search(params);
        };

        var clearDefaultWatch = $scope.$watch('defaults', function() {
          if ($scope.defaults) {
        //    $scope.autoSelect();
            clearDefaultWatch();
          }
        });
      }
    )
    .directive('agSolutionsFinder', function() {
      return {
        restrict: 'AE',
        scope: { defaults: '=' },
        controller:'SolutionsFinderDirectiveController',
        templateUrl: 'scripts/features/solutions-finder/solutions-finder-directive.html'
      };
    });
  }
);
