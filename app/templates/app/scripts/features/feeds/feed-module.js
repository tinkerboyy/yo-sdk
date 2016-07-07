define(
[
  'angular',
  'lodash',
  'components/components-module',
  'components/services/collection-factory'
],
function(angular, _) {
  angular.module('gateways.feeds',['gateways.components'])

  .controller('AgNewsFeedController', function ($scope, DataService, AGService) {
    DataService.setDataLayerContext('Feeds');
    $scope.publicUser = AGService.data.publicUser;
    $scope.currentDate = new Date();

    DataService.Hallways.get(function (data) {
      $scope.hallways = data.data;

      DataService.Nodes.get({ sort: '-created' }, function(data2) {
        $scope.nodes = data2.data;
        $scope.nodeArray = [];
        for (var i = 0; i < $scope.nodes.length; i++) {
          var articleExpDate = new Date(parseInt($scope.nodes[i].expiration, 10) * 1000);
          //check if nodes are not expired and are published
          if (articleExpDate > $scope.currentDate && parseInt($scope.nodes[i].status, 10) === 1) {
            //Add nodes that are articles that have portfolio categories
            if ($scope.nodes[i].self.search('articles') !== -1 || $scope.nodes[i].self.search('hallway-documents') !== -1) {
              if ($scope.nodes[i].portfoliocategory) {
                // only include nodes with valid portfoliocategories. Exclude non matches.
                for (var n = 0; n < $scope.hallways.length; n++) {
                  for (var j = 0; j < $scope.hallways[n].portfoliocategory.length; j++) {
                    if (_.findIndex($scope.nodes[i].portfoliocategory, 'tid', $scope.hallways[n].portfoliocategory[j].tid) !== -1) {
                      $scope.nodeArray.push($scope.nodes[i]);
                      break;
                    }
                  }
                }
              }
            } else $scope.nodeArray.push($scope.nodes[i]); //add everything else that are not articles
          }
        }
      });
    });
  })

  .controller('AgFeedController', function ($scope, $collection, AGService) {
    $scope.publicUser = AGService.data.publicUser;
    $scope.init = function() {
      var feedResource = $collection($scope.resource);

      function pollEvents() {
        feedResource.get().then(function(data) {
          $scope.feeds = data;
        });
      }

      if ($scope.resource) {
        pollEvents();
      }
    };

    $scope.init();
  })

  .filter('upcoming', function () {
    return function(items) {
      var upcoming = [],
      eventEndDate,
      dateToday = Math.round((new Date()).getTime() / 1000);
      angular.forEach(items, function(item) {
        eventEndDate = item.event.value2;
        if ( dateToday < eventEndDate ) {
            upcoming.push(item);
        }
      });

      return upcoming.length > 0 ? upcoming : null;
    };
  })
  .filter('nodeURLFilter', function () {
    return function(node, hallways) {
      var newurl,
        hallway,
        articleLabel = _.kebabCase(node.label.toLowerCase());

      for (var i = 0; i < hallways.length; i++) {
        for (var j = 0; j < hallways[i].portfoliocategory.length; j++) {
          if (node.self.search('articles') !== -1 || node.self.search('hallway-documents') !== -1) {
            if (_.findIndex(node.portfoliocategory, 'tid', hallways[i].portfoliocategory[j].tid) !== -1) {
              hallway = hallways[i].label.toLowerCase().replace(/\ /g, '-').replace(/\-\&\-/g, '-and-');
              newurl = '#/gateway/' + hallway + '/' + node.id + '/' + articleLabel;
              break;
            }
          } else newurl = '#/news/' + node.id + '/' + articleLabel;
        }
      }
      return newurl;
    };
  })
  .filter('timezoneFilter', function() {
    var timezoneOffset = 60 * (new Date().getTimezoneOffset());
    return function(seconds) {
      return parseInt(seconds, 10) + timezoneOffset;
    };
  })
  .directive('agFeed',function() {
    return {
      restrict: 'EA',
      controller:'AgFeedController',
      scope: { resource: '=' },
      templateUrl: 'scripts/features/feeds/events.html'
    };
  })
  .directive('agNewsFeed',function() {
    return {
      restrict: 'EA',
      controller:'AgNewsFeedController',
      templateUrl: 'scripts/features/feeds/news.html'
      };
    });
});
