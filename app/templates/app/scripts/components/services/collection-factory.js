define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('gateways.components')
      .factory('$collection', function($q, $http, DataService) {
        var tokenPromise = $http.get('/api/session/token')
          .success(function(resp) {
            angular.extend($http.defaults.headers.common, resp);
          });

        function insertIntoCollection(collection, entity) {
          var originalIndex = _.findIndex(collection, { id: entity.id });
          if (!collection) {
            collection = [];
          }

          if (originalIndex !== -1) {
            collection.splice(originalIndex, 1);
          }

          collection.push(entity);
        }

        function CollectionFactory(type, params) {
          this.resource = DataService[type];
          this.meta = {
            type: type,
            params: angular.copy(params || {}),
            timestamps: {
              getCollectionRequest: 0,
              getCollectionResponse: 0,
              getCollectionFullRequest: 0
            },
            events: {
              create: [],
              edit: [],
              get: [],
              remove: []
            }
          };
          this.meta.params.range = this.meta.params.range || 'all';
          this.data = { collection: null };
        }

        CollectionFactory.prototype.get = function(params, force, ignoreOpt) {
          var self = this,
            defer = $q.defer(),
            defaultParams = angular.copy(self.meta.params);

          if (!ignoreOpt &&
            new Date().getTime() - self.meta.timestamps.getCollectionFullRequest < 15 * 60 * 1000) {
            defaultParams['filter[changed][value]'] = Math.floor(self.meta.timestamps.getCollectionRequest / 1000);
            defaultParams['filter[changed][operator]'] = '>=';
          } else {
            self.meta.timestamps.getCollectionFullRequest = new Date().getTime();
          }

          params = angular.extend(defaultParams, params);

          if (params.id) {
            delete params.range;
          }

          if (force || params.id ||
            (self.meta.timestamps.getCollectionRequest <= self.meta.timestamps.getCollectionResponse)) {

            if (!params.id) {
              self.meta.timestamps.getCollectionRequest = new Date().getTime();
            }

            self.resource.get(params, function(resp) {
              if (self.data.collection) {
                resp.data.forEach(function(item) {
                  insertIntoCollection(self.data.collection, item);
                });
              } else {
                self.data.collection = resp.data;
              }

              if (params.id) {
                self.meta.events.get.forEach(function (fn) {
                  fn({ type: self.meta.type, data: resp.data[0] });
                });
                defer.resolve(resp.data[0]);
              } else {
                self.meta.events.get.forEach(function (fn) {
                  fn({ type: self.meta.type,data: resp.data });
                });
                self.meta.timestamps.getCollectionResponse = new Date().getTime();
                defer.resolve(self.data.collection);
              }
            }, function(err) { defer.reject(err); });
          } else {
            defer.resolve(self.data.collection);
          }

          return defer.promise;
        };

        CollectionFactory.prototype.save = function(entity, ignoreAdd) {
          var self = this,
            defer = $q.defer();

          if (!entity.saving) {
            entity.saving = true;
            tokenPromise.then(function() {
              if (entity.id) {
                self.resource.update({ id: entity.id }, entity, function(resp) {
                  insertIntoCollection(self.data.collection, resp.data[0]);
                  entity.saving = false;
                  self.meta.events.edit.forEach(function(fn) {
                    fn({ type: self.meta.type, data: resp.data[0] });
                  });
                  defer.resolve(resp.data[0]);
                }, function(error) {
                  entity.saving = false;
                  defer.reject(error);
                });
              } else {
                self.resource.save(entity, function(resp) {
                  var newEntity = resp.data[0];
                  if (newEntity) {
                    ignoreAdd || insertIntoCollection(self.data.collection, newEntity);
                    entity.id = newEntity.id;
                  }
                  entity.saving = false;
                  self.meta.events.create.forEach(function(fn) {
                    fn({ type: self.meta.type, data: newEntity });
                  });
                  defer.resolve(newEntity);
                }, function(error) {
                  entity.saving = false;
                  defer.reject(error);
                });
              }
            });
          } else {
            defer.reject({ saving: true });
          }

          return defer.promise;
        };

        CollectionFactory.prototype.remove = function(entity) {
          var self = this,
            defer = $q.defer();

          tokenPromise.then(function() {
            self.resource.remove({ id: entity.id }, function() {
              var removed = _.remove(self.data.collection, { id: entity.id });

              self.meta.events.remove.forEach(function(fn) {
                fn({ type: self.meta.type, data: removed });
              });

              defer.resolve(removed);
            });
          });

          return defer.promise;
        };

        CollectionFactory.prototype.on = function(type, fn) {
          this.meta.events[type].push(fn);
        };

        return _.memoize(function(type, params) {
          return new CollectionFactory(type, params);
        }, function() {
          var params = '';
          angular.forEach(arguments[1], function(value, key) {
            params += (key + value);
          });
          return arguments[0] + params;
        });
      });
  }
);
