define(
  [
    'angular',
    'lodash',
    'angularToasty',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('gateways.components')
    .directive('agComments', function() {
      return {
        restrict: 'AE',
        scope: {
          item: '=',
          nameField: '@',
          notifyTopic: '=?'
        },
        controller: 'AgCommentsController',
        templateUrl: 'scripts/components/directives/comments/comments.html'
      };
    })
    .controller('AgCommentsController', function($scope, AGService, DataService) {

      $scope.processing = true;
      $scope.data = AGService.data;

      //Retrieve comments for the current item
      DataService.Comments.get({ 'filter[nid]': $scope.item.id, range: 'all' }, function(data) {
        $scope.comments = data.data;
        $scope.item.comments = $scope.comments;
        $scope.processing = false;
      });

      $scope.postComment = function(comment) {
        comment.processing = true;
        comment.$save(function(data) {
          comment.success = true;
          delete comment.processing;

          $scope.$emit('add-comments');

          //Increment comment_count by 1;
          if ($scope.item.comment_count || $scope.item.comment_count === 0 ) {
              $scope.item.comment_count++;
          }

          $scope.$emit('topicReply.notify');

          $scope.$broadcast('clear-comment');

          // Notify success reply to topic callback
          if ($scope.notifyTopic) {
            $scope.notifyTopic();
          }

          $scope.item.comments.push(data.data[0]);
          $scope.clearComment();
        }, function() {
          comment.error = true;
          delete comment.processing;
        });

        //Set GTM Data
        DataService.setDataLayer({
          agEvent: {
            type: 'comment',
            itemType: 'article',
            item: {
              id: $scope.item.id,
              name: $scope.item.name || $scope.item.label || null
            }
          }
        });
        DataService.setDataLayer({ 'event': 'comment' });
      };

      $scope.updateComment = function(comment) {
        DataService.Comments.update({ id: comment.id, body: comment.body }, function() {
          comment.success = true;
          delete comment.processing;

          comment.editing = !comment.editing;

          $scope.$emit('update-comments');

          $scope.$emit('topicReplyEdit.notify');

          // Notify success reply to topic callback
          if ($scope.notifyTopic) {
            $scope.notifyTopic();
          }
        }, function() {
          comment.error = true;
          delete comment.processing;
        });
      };

       $scope.removeComment = function(comment) {
        DataService.Comments.remove({ id: comment.id }, function() {
          comment.success = true;
          delete comment.processing;

          $scope.$emit('delete-comments');

          $scope.$emit('topicReplyDelete.notify');

          // Notify success reply to topic callback
          if ($scope.notifyTopic) {
            $scope.notifyTopic();
          }
         _.remove($scope.comments, function(com) {
            return com.id === comment.id;
          });

        }, function() {
          comment.error = true;
          delete comment.processing;
        });
      };

      $scope.clearComment = function() {
        $scope.$broadcast('clear-comment');
        $scope.newComment = new DataService.Comments({ nid: $scope.item.id });
      };

      $scope.clearComment();
    });
  }
);
