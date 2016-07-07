/**
 * Created by Madhukar on 10/7/15.
 */
define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('TopicsListController', function($scope, CommunitiesService, DataService, $routeParams, $filter, $timeout, $agLoader, $analytics, AGService, AGNotifications, $location) {
       // initialize the page number for the pagination
        $scope.currentPageNumber = {
          value: 1
        };
        // initialize the page size for the pagination
       $scope.pageSize = {
         value: 25
       };
        //Map of parent types
        $scope.typeMap = {
          'sow': { label: 'Statement of Work Library', icon: 'fa-bank' },
          'forum': { label: 'Communities', icon: 'fa-comments-o' },
          'article': { label: 'Article', icon: 'fa-newspaper-o' },
          'hallways_document': { label: 'Hallways Article', icon: 'fa-newspaper-o' }
        };

        //map ofi feed item  types
        $scope.map = {
          topic: 'Discussion',
          comment: 'Comment',
          reply: 'Reply'
        };

        $scope.mode = 'latest';

        $scope.loadTopics = function(entity) {
          $scope.topicsLoader = $agLoader.getLoader();
          var topicsParams = { range: 'all' };
          if (entity) {
            if ($scope.entityType === 'user') {
              $scope.me = entity.id === AGService.data.user.id;
              topicsParams['filter[uid]'] = entity.id;

              //get user comments
              var commentsLoad = $scope.topicsLoader.add();
              DataService.Comments.get({ 'filter[uid]': entity.id }, function(data) {
                $scope.comments = data.data;
                $scope.$emit('agContentUpdated');
                $scope.topicsLoader.finish(commentsLoad);
              });
            } else {
              topicsParams['filter[community_category_id]'] =  entity.id;
            }
          }

          //Get the latest topics
          $scope.topics = [];
          $scope.setTopics([]);
          var topicsLoad = $scope.topicsLoader.add();
          DataService.Topics.get( topicsParams, function ( data ) {
            if ($scope.singleTopic) {
              var topicId = parseInt($routeParams.topic, 10);
              if (isNaN(topicId)) {
                topicId = 0;
              }

              //Using == instead of === because data sometimes comes back as string and sometimes as int
              $scope.topics = $filter('filter')(data.data, { id: topicId }, function(actual, expected) { return actual == expected; }); // jshint ignore:line
              $scope.setTopics($scope.topics);
              if (typeof $scope.topics[0] !== 'undefined') {
                $scope.toggleExpand($scope.topics[0]);
              }
            } else {
              $scope.topics = data.data;
            }

            $scope.$emit('agContentUpdated');
            $scope.topicsLoader.finish(topicsLoad);
          });
        };

        $scope.addReply = function(topic) {
          topic.showReply = !topic.showReply;
          if (!topic.expanded && topic.showReply) {
            //Set to inverse of show reply because toggleExpanded will reverse it again
            topic.expanded = !topic.showReply;
            $scope.toggleExpand(topic);
          }
        };

        $scope.setTopics = function(topics) {
          $scope.pageTopics = topics;
        };

        $scope.toggleExpand = function(topic, tryLink) {
          //if try link, attempt to open parent page
          if (tryLink && topic.type !== 'topic') {
            switch (topic.parentType) {
              case 'forum':
                $location.url('/communities/topic/' + topic.nid);
                break;
              case 'sow':
                $location.url('/sowl/document/' + topic.nid);
                break;
              case 'article':
                $location.url('/gateway/article/' + topic.nid);
                break;
            }
          } else {
            topic.expanded = !topic.expanded;
          }
        };

        $scope.changeGroup = function(group) {
          $scope.$emit('myGroupChange', group);
        };

        $scope.prepFeed = function() {
          if ($scope.comments) {
            var feed = $scope.topics.concat($scope.comments);
            $scope.topics = $filter('orderBy')(feed, 'created', true);
          }
        };

        $scope.$on('newTopic', function(e, topic) {
          $scope.topics.unshift(topic);
          $scope.pageTopics.unshift(topic);
          e = null;
        });

        $scope.$watch('topics', function() {
          if ($scope.entity) {
            angular.forEach($filter('filter')($scope.topics, { uid: $scope.entity.id }, true), function(topic) {
              topic.author.name = $scope.entity.name;
            });
          }
        });

        $scope.$on('update-profile', function(e, user) {
          angular.forEach($filter('filter')($scope.topics, { uid: user.id }, true), function(topic) {
            topic.author = user;
          });
        });
      })
      .directive('agTopicsList', function() {
        return {
          restrict: 'AE',
          controller: 'TopicsListController',
          templateUrl: 'scripts/components/directives/topics/topics-list.html',
          replace: true,
          scope: {
            entity: '=',
            singleTopic: '=',
            setActiveCommunity: '=',
            entityType: '@',
            notifyTopic: '=?'
          },
          link: function(scope) {
            scope.$watch('entity', function(entity) {
              scope.loadTopics(entity);
            }, true);
          }
        };
      });
  }
);
