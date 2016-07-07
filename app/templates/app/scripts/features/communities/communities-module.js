define(
  [
    'angular',
    'angularRoute',
    'angularStrap',
    'angularStrapTpl',
    'angulartics',
    'angularToasty',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.communities', [ 'ngRoute', 'mgcrea.ngStrap', 'angular-toasty', 'gateways.components'])
      .config(function($routeProvider) {
      $routeProvider.when('/communities/:community?', {
        controller: 'CommunitiesController',
        templateUrl: 'scripts/features/communities/communities.html'
      });
      $routeProvider.when('/communities/user/:user?', {
        controller: 'CommunitiesController',
        templateUrl: 'scripts/features/communities/user/user.html'
      });
      $routeProvider.when('/communities/:community/:topic', {
        controller: 'CommunitiesController',
        templateUrl: 'scripts/features/communities/communities.html'
      });
      $routeProvider.when('/communities/topic/:topic', {
        controller: 'CommunitiesController',
        templateUrl: 'scripts/features/communities/communities.html'
      });
      $routeProvider.otherwise({
        redirectTo: '/'
      });
    })
      .factory('CommunitiesService', function(AGService) {
      function init() {
        AGService.data.banner.title = '';
        AGService.data.banner.subtitle = null;
        AGService.data.banner.env = ['learn', 'connect', 'act'];
        AGService.data.search.show = false;
        AGService.data.navigation.myProfile = true;
        AGService.data.navigation.signOut = true;
        AGService.data.banner.klass = 'ag-banner-align-left';
        AGService.data.banner.lcaFixed = true;
      }
      return {
        init: init
      };
    })
    .controller('CommunitiesController', function($scope, $rootScope, CommunitiesService, DataService, $routeParams, $filter, $timeout, $agLoader, $analytics, $location, AGService, toasty, AGNotifications) {
      DataService.setDataLayerContext('Communities');
      CommunitiesService.init();
      $scope.newTopic = {};
      $scope.pageLoader = $agLoader.getLoader();

      $scope.init = function() {
        if ($routeParams.topic) {
          $scope.singleTopic = true;
        }

        if ($routeParams.community) {
          if ($routeParams.community === 'user') {
            $location.url('/communities/user/' + AGService.data.user.id);
          }
          $scope.communitySlug = $routeParams.community;
        }

        if ($routeParams.user) {
          DataService.User.get({ id: $routeParams.user }, function(data) {
            $scope.curUser = data.data[0];
            $scope.me = $scope.curUser.id === AGService.data.user.id;
          });
        }

        DataService.Communities.get( function (data) {
          $scope.communities = data.data;
        });
      };

      $scope.myGroupAction = function(community) {
        $scope.communitySlug = community.slug;
      };

      /**
       * Turns off single topic view and loads all topics for the currently
       * selected community
       */
      $scope.viewAllTopics = function() {
        $scope.singleTopic = false;
      };

      /**
       * New Topic Creation Logic
       */
      $scope.createNewTopic = function(community) {
        if (community) {
          community = $filter('filter')($scope.communities, { id: community.id }, true)[0];
        }
        $scope.newTopic = {
          processing: false,
          createNewTopicExpanded: true,
          success: false,
          error: false,
          community: community ? community : null,
          label: '',
          body: '',
          status: 1
        };
      };

      $scope.submitNewTopic = function() {
        if (!$scope.newTopic.processing) {
          $scope.newTopic.processing = true;

          var topic = {
            label: $scope.newTopic.label,
            body: $scope.newTopic.body,
            community_category_id: $scope.newTopic.community.id,
            status: 1
          };

          DataService.Topics.save(topic, function(data) {
            $scope.newTopic.success = true;
            $scope.newTopic.processing = false;
            $scope.newTopic.label = '';
            $scope.newTopic.body = '';
            $scope.newTopic.id = data.data[0].id;

            $analytics.eventTrack('New Topic Added', {
              label: $scope.newTopic.community.label,
              category: 'Communities'
            });

            AGNotifications.getNotification();

            $scope.newTopic.createNewTopicExpanded = false;
            $scope.$broadcast('newTopic', data.data[0]);
          }, function() {
            $scope.newTopic.processing = false;
            $scope.newTopic.error = true;
          });
        }
      };

      $scope.viewAll = function() {
        $scope.$broadcast('groupChange', null);
        $scope.communitySlug = '';
      };

      $scope.init();

      $scope.$on('menuGroupChange', function(e, slug) {
        if ($scope.newTopic.createNewTopicExpanded) {
          $scope.createNewTopic($filter('filter')($scope.communities, { slug: slug }, true)[0]);
        }
        $scope.singleTopic = false;
      });

      $scope.$on('topicReply.notify', function() {
        toasty.success({
          msg: 'Your reply was successfully submitted!'
        });
      });

      $scope.$on('topicReplyEdit.notify', function() {
        toasty.success({
          msg: 'Your reply was successfully updated!'
        });
      });

      $scope.$on('topicReplyDelete.notify', function() {
        toasty.success({
          msg: 'Your reply was successfully deleted.'
        });
      });

        $scope.$on('topicReply.notify', function() {
          toasty.success({
            msg: 'Your reply was submitted!'
          });
        });

        $scope.$on('myGroupChange', function(e, group) {
          $scope.$broadcast('groupChange', group);
        });

        $rootScope.$on('update-profile', function(evt, args) {
          $scope.curUser = args;
        });
      })
      .controller('CommunitiesWidgetController', function ($scope, DataService, AGService) {
        $scope.publicUser = AGService.data.publicUser;
        $scope.init = function() {
          //Identify if the call is from a hallway
          if ($scope.communityId) {
            DataService.Communities.get({ id: $scope.communityId }, function(data) {
            $scope.community = data.data[0];
              if ($scope.community) {
                var slug = $scope.community.url.split('/');
                $scope.community.slug = slug[slug.length - 1];
              }
            });

            DataService.Topics.get({ 'filter[community_category_id]': $scope.communityId, range: 50 }, function ( data ) {
              $scope.topics = data.data;
            });
          } else {
            DataService.Topics.get(function (data) {
              $scope.topics = data.data;
            });
          }
        };

        $scope.init();
      })
      .directive('agCommunitiesWidget', function () {
        return {
          restrict: 'EA',
          scope: {
            communityId: '=community'
          },
          templateUrl: 'scripts/features/communities/communities-widget.html',
          controller: 'CommunitiesWidgetController'
        };
      });
  }
);
