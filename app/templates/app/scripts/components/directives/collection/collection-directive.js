define(
  [
    'angular',
    'lodash',
    'components/components-module',
    'components/services/collection-factory'
  ],
  function(angular, _) {
    angular.module('gateways.components')
    .directive('agCollection', function() {
      return {
        restrict: 'AE',
        controller: 'AgCollectionController'
      };
    })
    .controller('AgCollectionController', function($scope, $attrs, $parse, $collection) {
      var collections = $parse($attrs.agCollection)($scope);

      $scope.getEditCopy = angular.copy;

      angular.forEach(collections, function(collection) {
        var resource = $collection(collection.resourceName, collection.params),
          collectionName = _.camelCase(collection.resourceName);

        $scope[collectionName] = angular.extend({
          data: resource.data,
          save: function(entity, callback, ignoreAdd) {
            resource.save(entity, ignoreAdd).then(function() {
              callback && callback();
            });
          },
          remove: function(entity, callback) {
            resource.remove(entity).then(function() {
              callback && callback();
            });
          }
        }, $scope[collectionName]);

        resource.get(null, false, collection.ignoreChangedFilterOptimization);
      });
    });
  }
);
