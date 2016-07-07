define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .factory('$agVotes', function(DataService, $filter, AGService, $q) {
        function mergeVotesWithCollection(entityType, collection) {
          //Exit if public user
          if (AGService.data.publicUser) {
            var defer = $q.defer();
            defer.resolve(true);
            return defer.promise;
          }

          //Load votes
          return DataService.Votes.get({
            'type': entityType
          }).$promise.then(function(response) {
            var highestVote = 0,
              votes,
              highestVotedItemId = 0,
              vote,
              collectionIdMap = {},
              item;

            for (var i = 0, len = collection.length; i < len; i++) {
              item = collection[i];
              collectionIdMap[item.id] = item;

              vote = $filter('filter')(response.data, { itemId: item.id }, true);

              votes = 0;
              if (vote.length) {
                votes = parseInt(vote[0].votes, 10);
                if (isNaN(votes)) {
                  votes = 0;
                }
              }
              item.votes = votes;

              if (votes > highestVote) {
                highestVotedItemId = item.id;
                highestVote = votes;
              }
            }

            if (highestVotedItemId) {
              collectionIdMap[highestVotedItemId].highestVoted = true;
            }

            return true;
          });
        }

        return {
          mergeVotesWithCollection: mergeVotesWithCollection
        };
      })
      .controller('VoteUpDownController', function($scope, $filter, $attrs, $location, DataService, AGService) {

          //Exit if public user
          $scope.publicUser = AGService.data.publicUser;
          if ($scope.publicUser) {
            return false;
          }
        $scope.processing = true;

        DataService.Votes.getForItem({ id: $scope.item.id, type: $scope.type }, function(data) {
          $scope.item.votes = parseInt(data.data[0].votes, 10);
          $scope.item.myVote = parseInt(data.data[0].myVote, 10);
          if (isNaN($scope.item.votes)) {
            $scope.item.votes = 0;
          }
          $scope.processing = false;
        });

        $scope.vote = function(direction) {
          var vote = {
            type: $scope.type,
            itemId: $scope.item.id,
            vote: direction
          };

          DataService.Votes.create(vote, function(data) {
            $scope.item.votes = parseInt(data.data[0].votes, 10);
            $scope.item.myVote = parseInt(data.data[0].myVote, 10);
            if (isNaN($scope.item.votes)) {
              $scope.item.votes = 0;
            }
          });

          //Set GTM Data
          DataService.setDataLayer({
            agEvent: {
              type: 'vote-' + direction,
              itemType: $scope.type,
              item: {
                id: $scope.item.id,
                name: $scope.item.name || $scope.item.label || null
              }
            }
          });
          DataService.setDataLayer({ 'event': 'vote' });
        };
      })
      .directive('agVoteUpDown', function() {
        return {
          restrict: 'AE',
          controller: 'VoteUpDownController',
          replace: true,
          templateUrl: 'scripts/components/directives/vote-up-down/vote-up-down.html',
          scope: {
            type: '@',
            item: '=',
            collection: '=',
            text: '@'
          }
        };
      });

  }
);
