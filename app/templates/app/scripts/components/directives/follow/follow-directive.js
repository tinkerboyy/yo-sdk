/**
 * Created by Madhukar on 9/16/15.
 */

define(
  [
    'angular',
    'lodash',
    'angularToasty',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('FollowController', function($scope, DataService, AGService, toasty) {
        $scope.init = function() {
          var itemId = $scope.idField ? $scope.item[$scope.idField] : $scope.item.id;
          $scope.itemId = itemId.toString();
          $scope.follows = AGService.data.user.preferences.follow;

          //If following this type is tracked in the user preferences of AG Service, set followed state based on that
          $scope.item.followed = AGService.data.user.preferences.follow[$scope.type].indexOf($scope.itemId) >= 0;
        };

        $scope.toggleFollow = function(item) {
          var type;
          item.followed = AGService.data.user.preferences.follow[$scope.type].indexOf($scope.itemId) >= 0;
          $scope.processing = true;
         // toasty.clear();
         //  stop following if it's followed
          if (item.followed) {
            type = 'unfollow';
            DataService.Preferences.remove({
              itemId: $scope.itemId,
              'filter[action]': 'follow',
              'filter[type]': $scope.type
            }, function() {
              item.followed = false;
              $scope.processing = false;
              AGService.data.user.preferences.follow[$scope.type].splice(AGService.data.user.preferences.follow[$scope.type].indexOf($scope.itemId), 1);

              var message = $scope.type === 'user' ? (($scope.item.name !== null) ? $scope.item.name : $scope.item.label ): $scope.item.label;
              $scope.$emit('unfollow.notify', message);
              toasty.success({
                msg: 'You are no longer following ' + message
              });
            });
          } else {
            type = 'follow';
            DataService.Preferences.create({
              itemId: $scope.itemId,
              action: 'follow',
              type: $scope.type
            }, function () {
              item.followed = true;
              $scope.processing = false;
              AGService.data.user.preferences.follow[$scope.type].push($scope.itemId);

           var message = $scope.type === 'user' ? (($scope.item.name !== null) ? $scope.item.name : $scope.item.label ): $scope.item.label;
             $scope.$emit('follow.notify', message);
              toasty.success({
                msg: 'Congratulations, you are now following ' + message
              });
            });
          }

          //Set GTM Data
          DataService.setDataLayer({
            agEvent: {
              type: type,
              itemType: $scope.type,
              item: {
                id: $scope.itemId,
                name: item.name || item.label || null
              }
            }
          });
          DataService.setDataLayer({ 'event': 'follow' });
        };
      })
      .directive('agFollow', function() {
        return {
          restrict: 'EA',
          replace: true,
          scope: {
            item: '=',
            followText: '@',
            unfollowText: '@',
            type: '@',
            noIcon: '=',
            idField: '@',
            callback: '=',
            notify: '=?'
          },
          templateUrl: 'scripts/components/directives/follow/follow.html',
          controller: 'FollowController',
          link: function(scope) {
            scope.$watch('item', function() {
              scope.init();
            }, true);
          }
        };
      });
  }
);
