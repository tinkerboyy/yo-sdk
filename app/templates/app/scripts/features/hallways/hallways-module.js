define(
  [
    'angular',
    'lodash',
    'moment',
    'angularScroll',
    'angularRoute',
    'angularStrap',
    'angularStrapTpl',
    'angularToasty',
    'components/components-module'
  ],
  function(angular, _, moment) {
    angular.module('gateways.hallways', [ 'ngRoute', 'mgcrea.ngStrap', 'gateways.components', 'duScroll' ])
      .config(function($routeProvider) {
        $routeProvider.when('/gateway/:hallway', {
          controller: 'HallwaysController',
          templateUrl: 'scripts/features/hallways/hallways.html'
        });

        $routeProvider.when('/gateway/article/:articleId', {
          controller: 'HallwaysController',
          templateUrl: 'scripts/features/hallways/hallways.html'
        });

        $routeProvider.when('/gateway/:hallway/:articleId/:articleLabel', {
          controller: 'HallwaysController',
          templateUrl: 'scripts/features/hallways/hallways.html'
        });

        $routeProvider.otherwise({
          redirectTo: '/'
        });
      })
      .filter('removeExpired', function() {
        return function(articles) {
          var currentDate = Math.ceil(Date.now() / 1000)
            , out = [];
          angular.forEach(articles, function(article) {
            if (parseInt(article.expiration, 10) > currentDate) {
              out.push(article);
            }
          });

          return out;
        };
      })
      .filter('videoUrlFilter', function() {
        return function(oldurl) {
          if (oldurl) {
            var n1 = oldurl.search('youtube.com')
              , n2 = oldurl.search('youtu.be')
              , n3 = oldurl.search('www')
              , n4 = oldurl.search('http://')
              , n5 = oldurl.search('https://');

            if ((n4 === -1) && (n5 === -1)) {
              oldurl = 'http://' + oldurl;
            }
            if (n3 === -1) {
              oldurl = oldurl.replace('//', '//www.');
            }
            //if video is from youtube
            if (n1 !== -1) {
              oldurl = oldurl.replace('youtube.com', 'youtube.com/embed');
              }
            if (n2 !== -1) {
              oldurl = oldurl.replace('youtu.be', 'youtube.com/embed');
            }

            oldurl = oldurl.replace('watch?v=', '');

            return oldurl;
          } else {
            return null;
          }
        };
      })
      .filter('trustResource', function($sce) {
        return function(source) {
          if (source) {
            return $sce.trustAsResourceUrl(source);
          }
        };
      })
      .filter('modifiedDateFilter', function() {
        return function(date) {
          return moment.unix(date).fromNow();
        };
      })
      .filter('uriFilter', function() {
        return function(uri) {
          return uri.replace('public://', '');
        };
      })
      .controller('HallwaysController', function($scope, AGService, DataService, $routeParams, $filter, $timeout, toasty) {
        DataService.setDataLayerContext('Hallway');
        AGService.data.banner.env = ['learn', 'connect', 'act'];
        AGService.data.banner.klass = 'ag-banner-align-left';
        AGService.data.banner.title = null;
        AGService.data.search.show = false;
        AGService.data.banner.subtitle = null;
        AGService.data.navigation.myProfile = true;
        AGService.data.navigation.signOut = true;
        AGService.data.footer.visible = false;

        $scope.publicUser = AGService.data.publicUser;

      //Define singleArticle mode immediately if an article route to prevent flash of Hallway Homepage
        if ($routeParams.articleId) {
          $scope.singleArticle = true;
        }

        $scope.init = function() {
          DataService.Hallways.get(function(d) {
            $scope.hallways = d.data;

          //Only try to load hallway data if a hallway is specified in the route
            if ($routeParams.hallway) {
              $scope.hallway = $filter('filter')(d.data, { slug: $routeParams.hallway }, true)[0];
              AGService.data.hallway = $scope.hallway;
              $scope.hallway.communityhallway = $scope.hallway.communityhallway || { tid: 932 };
              $scope.solutionsFinderDefaults = { categories: [$scope.hallway.solutionfindercat], subcategories: [$scope.hallway.solutionfindersubcat] };

              //Set the category team opject
              $scope.categoryTeam = {
                publisher: $scope.hallway.publisher,
                moderator: $scope.hallway.moderator,
                isData: ($scope.hallway.publisher||$scope.hallway.moderator),
                isSame: ($scope.hallway.publisher&&$scope.hallway.moderator) &&
                  ($scope.hallway.publisher.uid === $scope.hallway.moderator.uid)
              };

            //Create filters for retrieving hallway articles
              var params = {
                range: 'all'
              };
              for (var n = 0; n < $scope.hallway.portfoliocategory.length; n++) {
                params['filter[portfoliohallway][value][' + n + ']'] = $scope.hallway.portfoliocategory[n].tid;
                params['filter[portfoliohallway][operator][' + n + ']'] = 'IN';
              }

            //Get hallway articles
              DataService.Nodes.get(params, function(data) {
                $scope.articles = data.data;

                //If article Id is in the route, load single article view
                if ($routeParams.articleId) {
                  $scope.setActiveArticle($filter('filter')($scope.articles, { id: $routeParams.articleId }, true)[0]);

                  //If call to a single article is to an article without a portfolio category
                  if (!$scope.article) {
                    //Look for the article in the hallway-articles API

                    DataService.Nodes.get({ 'filter[id]': $routeParams.articleId }, function(data) {
                      if (data.data.length > 0) {
                        $scope.setActiveArticle(data.data[0]);
                      }
                    });

                    $scope.embeddedArticle = true;
                  }

                  $scope.articleView = false;

                }
              });
            }
          });
        };

        $scope.hallwayPage = true;
        $scope.hideBtn = true;
        $scope.articleView = false;

        $scope.setActiveArticle = function(article) {
          if (article) {

            //Clear active flag on all previously active articles
            angular.forEach($filter('filter')($scope.articles, { active: true }), function(activeArticle) {
              delete activeArticle.active;
            });

            article.active = true;
            $scope.article = article;
            $scope.singleArticle = true;

            if ($scope.article.documentupload) {
              $scope.file = '../sites/all/libraries/pdf.js/web/viewer.html?file=' + encodeURIComponent($scope.article.documentupload.url);
            }

            DataService.NodeHistory.save({ nid: $scope.article.id });

            //Get Article Author profile details if user is not a Public User
            if (!$scope.publicUser) {
              DataService.User.get({ id: $scope.article.author.uid }, function (data2) {
                $scope.authorProfile = data2.data[0];
              });
            }

            //Set if theres a previous article for the current article
            $scope.hasPrevious = $scope.articles.indexOf(article) > 0;

            //Set if theres a next article for the current article
            $scope.hasNext = $scope.articles.indexOf(article) < ($scope.articles.length - 1);

            if (!$scope.embeddedArticle){
              $timeout(function() {
                //scroll to active article within Article Index
                var articleElem = angular.element(document.getElementById('article' + $scope.article.id))
                , container = angular.element(document.getElementById('scrollcontainer'));

                container.scrollTo(articleElem, 20, 900);

                //remove custom floats from users
                $('blockquote').closest('div[style*="float:right"]').css({ 'float': 'none' });
                $('blockquote').closest('div[style*="float:left"]').css({ 'float': 'none' });

              }, 25);
             }
            //Set GTM Data
            DataService.setDataLayer({
              agEvent: {
                type: 'view',
                itemType: 'hallway article',
                item: {
                  id: $scope.article.id,
                  name: $scope.article.label || null
                }
              }
            });
            DataService.setDataLayer({ 'event': 'view' });
          }
        };

        $scope.previousArticle = function() {
          if ($scope.hasPrevious) {
            $scope.setActiveArticle($scope.articles[$scope.articles.indexOf($scope.article) - 1]);
          }

        };

        $scope.nextArticle = function() {
          if ($scope.hasNext) {
            $scope.setActiveArticle($scope.articles[$scope.articles.indexOf($scope.article) + 1]);
          }
        };

        $scope.viewAll = function() {
          $scope.singleArticle = false;
          delete $scope.article;
        };

        $scope.toggleArticleView = function() {
          $scope.articleView = !$scope.articleView;
          $scope.singleArticle = false;

          //Clear active flag on all previously active articles
            angular.forEach($filter('filter')($scope.articles, { active: true }), function(activeArticle) {
              delete activeArticle.active;
          });
        };

        $scope.setSingleArticleView = function() {
          $scope.articleView = false;
          $scope.singleArticle = true;
          if ($scope.article) $scope.article.active = true;
        };

        $scope.$on('delete-comments', function() {
          toasty.success({
            msg: 'Your comment was successfully deleted.'
          });
        });

        $scope.$on('add-comments', function() {
          toasty.success({
            msg: 'Your comment was successfully submitted!'
          });
        });

        $scope.$on('update-comments', function() {
          toasty.success({
            msg: 'Your comment was successfully updated!'
          });
        });

        $scope.init();
      })
      .controller('HallwayResourceController', function($scope, DataService, $modal, AGService) {

        $scope.publicUser = AGService.data.publicUser;
        $scope.hallway = AGService.data.hallway;

        $scope.resourceBtn;

        $scope.openModalWindow = function(resource) {
          $scope.resourceBtn = resource;
          var scope = $scope.$new();
          $modal({ templateUrl: 'scripts/features/hallways/resource-modal.html',
            scope: scope,
            show: true
          });
        };

        //Only display historical pricing data if user is not a Public User
        if (!$scope.publicUser) {
          DataService.Historical.get({ range: 'all' }, function (data) {
            $scope.historical = data.data;
          });
        }

        DataService.Transactional.get({ range: 'all' }, function (data) {
          $scope.transactional = data.data;
        });
     })
      .filter('urlFilter', function() {
        return function(oldurl) {
          if (oldurl) {
            var n1 = oldurl.search('http://')
            , n2 = oldurl.search('https://');
            if ((n1 === -1) && (n2 === -1)) {
              return 'http://' + oldurl;
            } else return oldurl;
          }
          return null;
        };
      })
      .filter('descFilter', function() {
        return function (text) {
          if (text) {
            var newText = text.replace(/\./g, ',').replace(/,(?=[^,]*$)/, '.').replace(/,(?=[^,]*$)/, ', and'),
                commaCount = (newText.match(/,/g) || []).length;

            if (commaCount === 1) {
              newText = newText.replace(',', '');
            }

            return newText;
          }
        };
      })
      .filter('charLimitTo',function($filter) {
        return function ( string, limit) {
          if ( !string ) return;
          if ( string.length <= limit ) {
            return string;
          }
        return $filter('limitTo')( string, limit ) + ' ...';
        };
      })
      .directive('hwResourcesBlock', function() {
          return {
            restrict: 'AE',
            controller: 'HallwayResourceController',
            templateUrl: 'scripts/features/hallways/resources.html'
          };
      });
    }
);
