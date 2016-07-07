define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('PinCtrl', function($scope, $analytics, DataService, AGNotifications) {
        $scope.pin = function(item) {
          var type;

          if (item.pinned) {
            type = 'unpin';
            DataService.Preferences.remove({
              itemId: item.id,
              'filter[type]': $scope.type ,
              'filter[action]': 'pin'
            }, function() {
              delete item.pinned;

              if ($scope.analyticsOn) {
                $analytics.eventTrack($scope.type + '.unpinned', {
                  label: item.name,
                  value: item.id,
                  category: $scope.analyticsCategory
                });
              }

              if ($scope.callback) {
                $scope.callback(item);
              }
            });

          } else {
            type = 'pin';
            DataService.Preferences.create({
              itemId: item.id,
              action: 'pin',
              type: $scope.type
            }, function() {
              item.pinned = true;
              AGNotifications.getNotification();
          //    $scope.$emit('pinned.notify'); // Notify pinned == true using event

              // Notify pinned == true using callback
              //if ($scope.notify) {
              //  $scope.notify(true);
              //}

              if ($scope.analyticsOn) {
                $analytics.eventTrack($scope.type + '.pinned', {
                  label: item.name,
                  value: item.id,
                  category: $scope.analyticsCategory
                });
              }

              if ($scope.callback) {
                $scope.callback(item);
              }
            });
          }

          //Set GTM Data
          DataService.setDataLayer({
            agEvent: {
              type: type,
              itemType: 'solution',
              item: {
                id: item.id,
                name: item.name
              }
            }
          });
          DataService.setDataLayer({ 'event': 'pin' });

        };
      })
      .directive('agPin', function() {
        return {
          restrict: 'AE',
          replace: true,
          controller: 'PinCtrl',
          templateUrl: 'scripts/components/directives/pin/pin.html',
          scope: {
            analyticsOn: '@',
            analyticsCategory: '@',
            type: '@',
            item: '=',
            callback: '=',
            notify: '=?'
          }
        };
      });
  }
);
