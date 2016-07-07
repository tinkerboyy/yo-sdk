define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .factory('$agLoader', function() {
        var loaders = {};

        function getLoader(single) {
          function getId() {
            return Date.now() + '' + Math.ceil(Math.random() * 100);
          }

          function Loader(id) {
            this.id = id;
            this.getId = getId;
            this.requests = [];

            this.add = function() {
              var reqId = this.getId();
              this.requests.push(reqId);
            };

            this.finish = function(reqId) {
              this.requests.splice(this.requests.indexOf(reqId), 1);
            };
          }

          var loaderId = getId()
            , loader = new Loader(loaderId);

          loaders[loaderId] = loader;
          if (single) {
            loader.add();
          }

          return loader;
        }

        return {
          loaders: loaders,
          getLoader:getLoader
        };
      })
      .controller('LoaderController', function($scope) {
        $scope.text = $scope.text || 'loading... please wait';
      })
      .directive('agLoader', function() {
        return {
          restrict: 'AE',
          replace: true,
          transclude: true,
          controller: 'LoaderController',
          templateUrl: 'scripts/components/directives/loader/loader.html',
          scope: {
            requests: '=',
            callback: '=',
            targetType: '@',
            text: '@'
          }
        };
      });
  }
);
