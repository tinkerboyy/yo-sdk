define(
  [
    'angular',
    'lodash',
    'components/components-module',
    'components/filters/unflatten-query-params-filter',
    'components/filters/flatten-for-query-params-filter',
    'components/directives/sort/sort-directive',
    'features/sowl/sowl-module'
  ],
  function(angular, _) {
    angular.module('gateways.sowl')
        .filter('prepareSearchParams', function($filter) {
          var moreSearchKeyMap = {
              workStatementType: 'sow_types',
              relatedSolutions: 'related_solutions',
              contractFormats: 'contract_formats',
              additionalOptions: 'document_types'
            };

          return function(moreSearch) {
            if (typeof moreSearch !== 'object') {
              return null;
            }
            var searchParams = {};
            angular.forEach(moreSearch, function(value, key) {
              if (value && (typeof value.length === 'undefined' || value.length)) {
                if (typeof moreSearchKeyMap[key] !== 'undefined') {
                  searchParams[moreSearchKeyMap[key]] = value;
                } else {
                  searchParams[key] = value;
                }
              }
            });
            if (searchParams.categories || searchParams.subcategories) {
              var subcategories = [];
              if (searchParams.subcategories) {
                subcategories = _.map(searchParams.subcategories, function(sc) { return sc.id; });
              }
              searchParams.categories = _.union(searchParams.categories, subcategories);
              delete searchParams.subcategories;
            }
            return $filter('flattenForQueryParams')(searchParams);
          };
      })
      .controller('SOWLSearchController', function($scope, DataService, AGService, SOWLService, $location, $routeParams, $filter, $window, $agLoader, $agVotes) {
        $scope.publicUser = AGService.data.publicUser;
        $window.scrollTo(0,0);

        $scope.settings = {
          listMode: 'list'
        };
        $scope.icons = SOWLService.data.icons;
        $scope.sortedResults = [];
        $scope.pagedResults = [];
        $scope.count = 0;

        //Sorting
        $scope.sort = {
          field: 'relevance',
          reverseOrder: true
        };
        $scope.sortOptions = [
          {
            field: 'relevance',
            label: 'Relevance',
            defaultOrder: true
          },
          {
            field: 'title',
            label: 'Alphabetically',
            defaultOrder: false
          },
          {
            field: 'created',
            label: 'Date Uploaded',
            defaultOrder: true
          },
          {
            field: 'views',
            label: 'View Count',
            defaultOrder: true
          },
          {
            field: 'downloads',
            label: 'Download Count',
            defaultOrder: true
          },
          {
            field: 'downloads_to_views',
            label: 'Downloads to View Ratio',
            defaultOrder: true,
            getSortValue: function(item) {
              return item.views > 0 ? item.downloads / item.views : 0;
            }
          }
        ];

        if (!$scope.publicUser) {
          $scope.sortOptions.push({
            field: 'votes',
            label: 'Vote Count',
            defaultOrder: true,
            getSortValue: function(item) {
              return typeof item.votes !== 'undefined' ? item.votes : 0;
            }
          });
        }

        $scope.doSearch = function() {
          $window.scrollTo(0,0);
          $scope.sowl.returnTo = 'search-results';
          $scope.resultsLoader = $agLoader.getLoader(true);

          if (!_.isUndefined($scope.moreSearch)) {
            var searchParams;

            if (!$scope.moreSearch.labels) {
              delete $scope.label;

              searchParams = $filter('prepareSearchParams')($scope.moreSearch);

              if (angular.isArray($scope.moreSearch.categories)) {
                $scope.categoryNames = SOWLService.data.categoryNames;
              }
            } else {
              searchParams = { categories: $scope.moreSearch.labels };
            }

            DataService.SOWLSearch.get(searchParams, function(data) {
              if (data.data) {
                $scope.results = data.data;

                //Load votes for SOWL for sorting
                $agVotes
                  .mergeVotesWithCollection('solution', $scope.results)
                  .then(function() {
                    $scope.resultsLoader.finish($scope.resultsLoader.requests[0]);
                  });

              } else {
                $scope.results = [];
                $scope.setResults($scope.results);
                $scope.resultsLoader.finish($scope.resultsLoader.requests[0]);
              }
              $scope.count = data.count || 0;
              $scope.searchError = false;
            }, function() {
              $scope.resultsLoader.finish($scope.resultsLoader.requests[0]);
              $scope.results = [];
              $scope.setResults($scope.results);
              $scope.count = 0;
              $scope.searchError = true;
            });
            //If on statement of work library results page, update URL with search terms
            var out = []
                , allKeys = ['categories', 'subcategories', 'workStatementType', 'relatedSolutions', 'contractFormats', 'additionalOptions', 'search']
                , map = { };

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
                $location.search(key, value || null);
                out.push(key + '=' + encodeURI(value));
              });
              $location.path('/sowl/search');
            }
          DataService.setDataLayer({ sowlFilters: $scope.moreSearch });
        };

        $scope.$on('sowl.doSearch', function() {
          $scope.doSearch();
        });

        $scope.setSortedResults = function(results) {
          $scope.sortedResults = results;
        };

        $scope.setResults = function(results) {
          $scope.pagedResults = results;
        };

        $scope.init = function() {
          $scope.doSearch();
        };

        $scope.init();
      });
  }
);
