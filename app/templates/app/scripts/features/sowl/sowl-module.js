//require all dependencies or rely on module to have all the dependencies included?
//currently missing data-service.js
define(
  [
    'angular',
    'lodash',
    'angularRoute',
    'angularCookies',
    'angularStrap',
    'angularStrapTpl',
    'angularToasty',
    'components/components-module',
    'components/directives/file-upload/file-upload-directive',
    'components/directives/share/share-directive'
  ],
  function (angular, _) {
    var dependencies = [ 'ngRoute', 'mgcrea.ngStrap', 'angular-toasty', 'gateways.components' ];
    angular.module('gateways.sowl', dependencies)
      .config(function($routeProvider) {
          $routeProvider.when('/sowl', {
            controller: 'SowlController',
            templateUrl: 'scripts/features/sowl/sowl.html'
          });

          $routeProvider.when('/sowl/search/:search?', {
            controller: 'SowlController',
            templateUrl: 'scripts/features/sowl/sowl.html',
            reloadOnSearch: false
          })
          .when('/sowl/search/label/:label/sublabel/:sublabel', {
            controller: 'SowlController',
            templateUrl: 'scripts/features/sowl/sowl.html'
          })
          .when('/sowl/search/label/:label', {
            controller: 'SowlController',
            templateUrl: 'scripts/features/sowl/sowl.html'
          });

          $routeProvider.when('/sowl/document/:documentId', {
            controller: 'SowlController',
            templateUrl: 'scripts/features/sowl/sowl.html'
          });

          $routeProvider.otherwise({
            redirectTo: '/'
          });
      })
      /**
        * Returns the list of categories from the combined category / subcategory collection
        * @param categories {array} List of category objects to filter
        * @param filter {array} list of categories for a specific solution
        * @return out {array} list of filtered categories
        */
      .filter('getCategories', function($filter) {
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
      .factory('SOWLService', function(AGService, DataService, $modal, $http, $filter, $agFileUpload, $q, toasty) {
        DataService.setDataLayerContext('SOWL');

        var categoryNames = {}
          , init = function($scope) {
            AGService.data.banner.title = '';
            AGService.data.banner.subtitle = '';
            AGService.data.banner.env = ['learn', 'connect', 'act'];
            AGService.data.search.show = false;
            AGService.data.navigation.myProfile = true;
            AGService.data.navigation.signOut = true;
            AGService.data.search.filters = [];
            AGService.data.search.selectedFilters = [];
            AGService.data.banner.klass = 'upperClass';
            AGService.data.banner.lcaFixed = true;

            var suggestionsLoader = $scope.pageLoader.add();
            DataService.SearchSuggestions.get(function(data) {
              $scope.suggestions = data.data;
              $scope.pageLoader.finish(suggestionsLoader);
            });

            $scope.categories = [];
            $scope.allSubcategories = [];
            $scope.categoryIcons = {};
            $scope.subCategories = [];
            $scope.workStatementTypes = [
              { id: 'SOW', name: 'Statement of Work (SOW)' },
              { id: 'SOO', name: 'Statement of Objectives (SOO)' },
              { id: 'PWS', name: 'Performance Work Statement (PWS)' }
            ];
            $scope.relatedSolutions = [];
            $scope.contractFormats = [
              { id: 'Commercial', name: 'Commercial' },
              { id: 'Non-Commercial', name: 'Non-Commercial' },
              { id: 'FSS (Schedules)', name: 'FSS (Schedules)' },
              { id: 'GWAC', name: 'GWAC' },
              { id: 'MAC', name: 'MAC' },
              { id: 'Others', name: 'Others' }
            ];
            $scope.additionalOptions = [
              { id: 'TEMPLATE', name: 'Template' },
              { id: 'USEDINRFP', name: 'Used in RFP' },
              { id: 'SAMPLE', name: 'Sample' }
            ];

            var categoriesLoader = $scope.pageLoader.add();
            DataService.SOWCategories.get(function(data) {
              angular.forEach(data.data, function(category) {
                angular.forEach(category.children, function(childCategory) {
                  childCategory.categoryId = category.id;
                  $scope.allSubcategories.push(childCategory);
                  $scope.categoryNames[childCategory.id] = childCategory.name;
                });
                $scope.categories.push(category);
                $scope.categoryNames[category.id] = category.name;
                $scope.categoryIcons[category.id] = category.category_icon;
              });
              $scope.categories = $filter('orderBy')($scope.categories, 'name');
              $scope.subcategories = $filter('orderBy')($scope.subcategories, 'name');

              /**
               * This block of code is for when we finish loading categories we
               * have to check to see if we have subcategories set already from
               * the incoming URL. If so we need to update the
               * $scope.moreSearch.subcategories array so that the items in it
               * are exact matches to the subcategory objects from the service
               * so that the accordion select will be able to check the appropriate
               * options
               */
              if ($scope.moreSearch.subcategories) {
                var moreSearchSubcategories = [];
                for (var i = 0, len = $scope.moreSearch.subcategories.length; i < len; i++) {
                  moreSearchSubcategories.push(
                    $filter('filter')($scope.allSubcategories, $scope.moreSearch.subcategories[i])[0]
                  );
                }
                $scope.moreSearch.subcategories = moreSearchSubcategories;
              }

              $scope.setSubcategories();

              $scope.pageLoader.finish(categoriesLoader);
            });

            var solutionsLoader = $scope.pageLoader.add();
            DataService.Solutions.query(function(data) {
              $scope.relatedSolutions = $filter('orderBy')(data, 'name');

              $scope.pageLoader.finish(solutionsLoader);
            });

          $scope.performSearch = function() {
            $scope.sowl.currentPage = 'search-results';
            $scope.sowl.labelSearch = false;
            $scope.$broadcast('sowl.doSearch');
          };

          $scope.viewAll = function() {
            $scope.moreSearch = {};
            $scope.setSubcategories();
            $scope.performSearch();
          };

          $scope.backToSearch = function() {
            $scope.performSearch();
          };

          /*$scope.gotoLandingPage = function() {
            $scope.moreSearch = {};
            $scope.setSubcategories();
            $scope.sowl.currentPage = 'landing';
          };*/

          $scope.setSubcategories = function() {
            var out = [],
              categories = $filter('getCategories')($scope.categories, $scope.moreSearch.categories);
            angular.forEach(categories, function(category) {
              if (category.children) {
                out.push(category);
                out = out.concat($filter('filter')($scope.allSubcategories, { categoryId: category.id }, true));
              }
            });

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
          };

          $scope.changeCategory = function() {
            $scope.setSubcategories();
            $scope.performSearch();
          };

          $scope.viewDocument = function(id) {
            $scope.currentDocument.id = id;
            $scope.shareUrl = '/sowl/document/' + $scope.currentDocument.id;
            $scope.sowl.currentPage = 'document';
            $scope.$broadcast('sowl.viewDocument');
          };

          $scope.uploadSow = function() {
            $scope.error = false;
            delete $scope.wordError;
            delete $scope.pdfError;
            $scope.sow = {};
            $modal({
              templateUrl: 'scripts/features/sowl/upload-modal.html',
              scope: $scope,
              show: true
            });
          };

          $scope.doUpload = function(cb) {
            $scope.processing = true;

            var filePromises = [];

            if ($scope.sow.word && $scope.sow.word[0].value) {
              filePromises.push(
                $agFileUpload.uploadFile(
                  'sow-document',
                  $scope.sow.word,
                  {
                    'word': true
                  }
                )
              );
            }

            if ($scope.sow.pdf && $scope.sow.pdf[0].value) {
              filePromises.push(
                $agFileUpload.uploadFile(
                  'sow-document',
                  $scope.sow.pdf,
                  {
                    'pdf': true
                  }
                )
              );
            }

            $q.all(filePromises).then(function(data) {
              var wordFid
              , pdfFid;

              angular.forEach(data, function(value) {

                if (value.config.data.word) {
                  wordFid = value.data.data[0].fid;
                } else if (value.config.data.pdf) {
                  pdfFid = value.data.data[0].fid;
                }
              });

              DataService.SOWDocument.save(
                {
                  label: $scope.sow.title,
                  agency: $scope.sow.agency,
                  word: wordFid,
                  pdf: pdfFid
                },
                function() {
                  cb();
                  $scope.processing = false;
                  toasty.success({
                    msg: 'Congratulations, you have successfully uploaded your SOW!'
                  });
                },
                function() {
                  $scope.processing = false;
                  $scope.error = true;
                  toasty.error({
                    msg: 'There was an error uploading your document, please try again'
                  });
                }
              );

            }, function() {
              $scope.processing = false;
              $scope.error = true;
              toasty.error({
                msg: 'There was an error uploading your document, please try again'
              });
            });
          };
        };

        return {
          data: {
            categoryNames: categoryNames,
            init: init
          }
        };
      })
      .filter('slice', function() {
        return function(data, offset, size) {
          return data.slice(offset, offset + size);
        };
      })
      .controller('SowlController', function ($scope, DataService, SOWLService, AGService, $location, $cookies, $modal, $routeParams, $window, $agLoader, toasty) {
        $window.scrollTo(0,0);
        $scope.pageLoader = $agLoader.getLoader();

        $scope.something = {
          appear: true,
          attentionHide: true
        };

        SOWLService.data.init($scope);
        $scope.sowl = {
          currentPage: '',
          returnTo: 'search-results'
        };
        $scope.moreSearch = {};
        $scope.currentDocument = {};
        $scope.categoryNames = {};

        $scope.welcome = {};
        $scope.toggleWelcome = function(visible) {
          $scope.welcome.visible = visible;
          if (visible) {
            delete $cookies.welcome;
          } else {
            $cookies.welcome = Date.now();
          }
        };

        $scope.init = function() {
          //Set Feature Header

          //Check cookies for welcome modal cookie
          DataService.WelcomeModal.get(function(data) {
            $scope.modalContent = data.data[0];
            $scope.welcome.visible = !$cookies.welcome;
          });

          //Check route params and route to correct part of app
          if ($routeParams.label) {

            $scope.sowl.currentPage = 'search-results';
            $scope.sowl.labelSearch = true;
            $scope.sowl.label = $routeParams.label;
            $scope.moreSearch = {
              categories: $routeParams.label.split(',')
            };
            if ($routeParams.sublabel) {
              $scope.sowl.label = $routeParams.sublabel;
              $scope.moreSearch.subcategories = _.map($routeParams.sublabel.split(','), function(scId) {
                return {
                  id: scId
                };
              });
            }
          } else if ($location.path() === '/sowl/search') {
            var categories, subcategories, workStatementType, relatedSolutions, contractFormats, additionalOptions;

            $scope.sowl.currentPage = 'search-results';
            $scope.sowl.labelSearch = false;
            $scope.moreSearch = {
              search: $routeParams.search === '*' ? '' : $routeParams.search
            };

            if ($location.search().categories) {
              categories = $location.search().categories.split(',');
            }

            if (categories) {
              $scope.moreSearch.categories = categories;
            }

            if ($location.search().subcategories) {
              subcategories = $location.search().subcategories.split(',');
            }

            if (subcategories) {
              $scope.moreSearch.subcategories = subcategories;
            }

            if ($location.search().workStatementType) {
              workStatementType = $location.search().workStatementType.split(',');
            }

            if (workStatementType) {
              $scope.moreSearch.workStatementType = workStatementType;
            }

            if ($location.search().relatedSolutions) {
              relatedSolutions = $location.search().relatedSolutions.split(',');
            }

            if (relatedSolutions) {
              $scope.moreSearch.relatedSolutions = relatedSolutions;
            }

            if ($location.search().contractFormats) {
              contractFormats = $location.search().contractFormats.split(',');
            }

            if (contractFormats) {
              $scope.moreSearch.contractFormats = contractFormats;
            }

            if ($location.search().additionalOptions) {
              additionalOptions = $location.search().additionalOptions.split(',');
            }

            if (additionalOptions) {
              $scope.moreSearch.additionalOptions = additionalOptions;
            }

          } else if ($routeParams.documentId) {
            $scope.sowl.currentPage = 'document';
            $scope.sowl.returnTo = 'landing';
            $scope.currentDocument.id = $routeParams.documentId;
          } else {
            $scope.sowl.currentPage = 'search-results';
          }
        };

        $scope.getRows = function(number) {
          if (number) {
            return new Array(Math.ceil(number / 3));
          }
        };

        $scope.addToProject = function(doc) {
          $scope.addToProjectModal = true;
          $scope.addToProjectDetails = {
            item: doc,
            itemNameField: 'label',
            itemType: 'SOW Document',
            analytics: {
              category: 'SOWL',
              value: doc.id
            }
          };

          $scope.$on('addProject.modal', function(event, args) {
            $scope.addToProjectModal = args;
          });

          $modal({
            title: 'Add this solution to a project',
            scope: $scope,
            templateUrl: 'scripts/components/directives/add-to-project/add-to-project-modal.html',
            backdrop: 'static',
            show: true
          });
        };

        $scope.$on('addProject.SOWLSearch', function() {
          toasty.success({
            msg: 'Congratulations, your saved search was successfully added to your project!'
          });
        });

        $scope.$on('addProject.SOWDocument', function() {
          toasty.success({
            msg: 'Congratulations, your SOW was successfully added to your project!'
          });
        });

        $scope.$on('add-comments', function() {
          toasty.success({
            msg: 'Your comment was successfully submitted!',
            position: 'bottom-right'
          });
        });

        $scope.$on('update-comments', function() {
          toasty.success({
            msg: 'Your comment was successfully updated!',
            position: 'bottom-right'
          });
        });

        $scope.$on('delete-comments', function() {
          toasty.success({
            msg: 'Your comment was successfully deleted.',
            position: 'bottom-right'
          });
        });

        $scope.init();
      });
  }
);
