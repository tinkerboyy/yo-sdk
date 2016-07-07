define(
  [
    'angular',
    'angularStrap',
    'angulartics',
    'angulartics-google-analytics',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('GroupsListController', function($scope, $agLoader, DataService, $filter, $analytics, $location) {
        $scope.init = function() {
          $scope.communitiesMap = {};
          $scope.pageLoader = $scope.pageLoader || $agLoader.getLoader();

          //Get list of communities for left nav
          var communitiesLoader = $scope.pageLoader.add();
          DataService.Communities.get( function (data) {
            var map = {};
            $scope.communities = data.data;//Get user groups from Preferences API
            angular.forEach($scope.communities, function(group) {
              $scope.makeSlug(group);
              map[group.id] = group;
            });

            $scope.communitiesMap = map;

            //If on a specific community page, set page parameters
            var community;
            if ($scope.communitySlug) {
              community = $filter('filter')($scope.communities, { url: $scope.communitySlug })[0];
              $scope.community = community;
              $scope.activeCommunity = $scope.communitySlug;
            }

            $scope.pageLoader.finish(communitiesLoader);
          });
        };

        $scope.makeSlug = function(community) {
          var slug = community.url.split('/');
          community.slug = slug[slug.length - 1];
        };

        $scope.setActiveCommunity = function(slug) {
          if ($scope.communitySlug === 'user') {
            $location.url('/communities/' + slug);
          } else {
            $scope.communitySlug = slug;
            $scope.activeCommunity = slug;
            var community = slug ? $filter('filter')($scope.communities, { slug: slug }, true)[0] : null;
            $scope.community = community;
            $scope.singleTopic = false;

            if ($scope.community) {
              $analytics.eventTrack('Load Topics', {
                label: community.label,
                category: 'Communities'
              });
            }

            $scope.$emit('menuGroupChange', slug);
          }
        };

        $scope.$on('groupChange', function(e, group) {
          $scope.setActiveCommunity(group);
        });

        $scope.init();
      })
      .directive('agGroupsList', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'GroupsListController',
          templateUrl: 'scripts/components/directives/groups-list/groups-list.html',
          scope: {
            communitySlug: '=?',
            community: '=?',
            pageLoader: '=?'
          },
          link: function(scope) {
            scope.$watch('communitySlug', function() {
              if (scope.communities) {
                scope.setActiveCommunity(scope.communitySlug);
              }
            }, true);
          }
        };
      });
  }
);
