define([
    'angular',
    'components/components-module'
  ],
  function (angular, componentsModule) {
    var cacheExpiry = {}
      , sessionRefreshLength = 1800 //30 minutes
      , sessionWarningThreshold = 300 //5 minutes
      , sessionMode = 'local'
      , sessionModal
      , sessionExpiry = Math.ceil(Date.now() / 1000) + sessionRefreshLength;

    componentsModule.config(function($resourceProvider, $httpProvider) {
      $resourceProvider.defaults.actions.update = { method: 'PUT' };
      $httpProvider.defaults.withCredentials = true;
      $httpProvider.defaults.cache = true;
      $httpProvider.interceptors.push('agHttpInterceptor');

    })
      .factory('agHttpInterceptor', function($q, toasty, $window, AGNotifications) {
        var builder = {
          title: function(status) {
            switch (status) {
              case 400: return 'Bad Request';
              case 401: return 'Not Authorized';
              case 403: return 'Not Allowed';
              case 404: return 'Resource Not Found';
              case 412: return 'Precondition Not Met';
              case 503: return 'Service Unavailable';
              case 500: return 'Your request could not be processed. Please try again';
              default: return 'Your request could not be processed. Please try again.';
            }
          },
          errorMessage: function(status, error) {
            var msg;
            if (error.data && error.data.consumerMessage) {
              msg = error.data.consumerMessage;
            } else if (error.data && error.data.title) {
              msg = error.data.title;
            } else if (error.statusText) {
              msg = error.statusText;
            } else {
              msg = 'Unknown Error';
            }
            if (msg.length > 256) {
              msg = msg.substring(0,256);
            }
            return msg;
          }
        };

        return {
          'request': function(config) {
            //Refresh local session timer
            sessionExpiry = Math.ceil(Date.now() / 1000) + sessionRefreshLength;

            if (config.ttl) {
              var params = [];
              if (angular.isObject(config.params)) {
                angular.forEach(Object.keys(config.params).sort(), function(key) {
                  params.push(encodeURI(key + '=' + config.params[key]));
                });
              }

              var url = config.url + ( params.length > 0 ? '?' + params.join('&') : '');

              if (!cacheExpiry[url]) {
                cacheExpiry[url] = Date.now() + (config.ttl * 60000);
              }
            }
            return config;
          },
          'response': function(response) {
              AGNotifications.setNotification(response);
            return response;
          },
          'requestError': function(rejection) {

            return $q.reject(rejection);
          },
          'responseError': function(error) {
            var status = error.status || 0,
              msg = {
                title: builder.title(status, error),
              //  msg: builder.errorMessage(status, error),
                showClose: true,
                clickToClose: true,
                timeout: false
              };

            if ((status === 500 || status === 503) && error.config.method !== 'GET' ) {
              toasty.error(msg);
              return $q.reject(error);
            }

            if (status === 403 || status === 401) {
              $window.location.replace('/login-information?url=' + encodeURIComponent(window.location.href));
            } else {
              return $q.reject(error);
            }
          }
        };
      })
      .filter('formatMinSec', function() {
      return function(seconds) {
        function formatLeading(num) {
          if (num < 10) {
            num = '0' + num;
          }

          return num;
        }

        var mins = Math.floor(seconds / 60)
          , secs = seconds % 60;

        return formatLeading(mins) + ':' + formatLeading(secs);
      };
    })
    .factory('DataService', function($http, $resource, $interval, $cacheFactory, $location, $modal, $rootScope, $window) {

      var baseUrl = '/api/v1.0/'
        , $scope = $rootScope.$new()
        , oldBaseUrl = '/api-old/'
        , sessionTimeLeft = 0
        , fileUploadConfig = {
          headers: { 'Content-Type': undefined },
          transformRequest: function(data) {
            var fd = new FormData();
            angular.forEach(data, function(value, key) {
              fd.append(key, value);
            });
            return fd;
          }
        };

      function pruneCache() {
        var time = Date.now()
          , cache = $cacheFactory.get('$http');

        angular.forEach(cacheExpiry, function(expires, url) {
          if (time > expires) {
            cache.remove(url);
            delete cacheExpiry[url];
          }
        });
      }

      $interval(pruneCache, 60000);

      var modal
        , sessionTimer;
      function popup(type) {
        var time = Math.ceil(Date.now() / 1000)
          , timeLeft = sessionExpiry - time;
        $scope.sessionModal = sessionModal;
        $scope.sessionExpiry = sessionExpiry;
        $scope.extendSession = function(cb) {
          $interval.cancel($scope.countdown);
          $scope.sessionExpiry = Math.ceil(Date.now() / 1000) + sessionRefreshLength;
          $resource('/api/v1.0/auth').get();
          $scope.sessionModal = null;
          cb();
        };
        $scope.timeLeft = timeLeft > sessionTimeLeft ? sessionTimeLeft : timeLeft;

        $scope.startTimer = function() {
          $scope.countdown = $interval(function() {
            if ($scope.timeLeft === 0) {
              $interval.cancel($scope.countdown);
              popup('expired');
            }
            $scope.timeLeft--;
          }, 1000);
        };

        $scope.redirectToUrl = function() {
         $window.location.replace('/login-information?url=' + encodeURIComponent($location.absUrl()));
        };

        function showLogoutModal() {
          modal = $modal({
            templateUrl: 'scripts/components/services/session-expired-modal.html',
            show: true,
            scope: $scope,
            backdrop: 'static'
          });
        }

        switch (type) {
          case 'expiryWarning':
            if (sessionModal !== 'expiryWarning') {
              if (modal) {
                modal.hide();
              }
              sessionModal = 'expiryWarning';
              modal = $modal({
                templateUrl: 'scripts/components/services/session-expiring-modal.html',
                show: true,
                scope: $scope,
                backdrop: 'static'
              });
            }
            break;

          case 'finalExpiryWarning':
            if (sessionModal !== 'finalExpiryWarning') {
              if (modal) {
                modal.hide();
              }
              sessionModal = 'finalExpiryWarning';
              modal = $modal({
                templateUrl: 'scripts/components/services/final-expiring-modal.html',
                show: true,
                scope: $scope,
                backdrop: 'static'
              });
            }
            break;

          case 'expired':
            $interval.cancel(sessionTimer);
            if (sessionModal !== 'expired') {
              sessionModal = 'expired';
              if (modal) {
                modal.hide();
              }

              $http({
                url: '/api/v1.0/auth',
                method: 'DELETE'
              }).then(function() {
                showLogoutModal();
              }, function() {
                showLogoutModal();
              });
            }
            break;
        }
      }

      //Check the state of the current session and give a warning or log the user out
      function checkSession(minutes) {
        var time = Math.ceil(Date.now() / 1000);
        if (sessionMode === 'local') {
          //Refreshable
          if ((sessionExpiry > time) && (sessionExpiry - time <= sessionWarningThreshold)) {
            popup('expiryWarning');
          } else if (sessionExpiry - time <= 0) {
            popup('expired');
          }
        } else {
          //Not refreshable
          if ((sessionTimeLeft > minutes * 60) && (sessionTimeLeft - (minutes * 60) <= sessionWarningThreshold)) {
            popup('finalExpiryWarning');
          } else if (sessionTimeLeft - (minutes * 60) <= 0) {
            popup('expired');
          }
        }
      }

      function setSessionProperties(session) {
        session.timeLeft = 7200;
        session.refreshLenth = 1800;
        sessionMode = session.timeLeft <= 1800 ? 'server' : 'local';
        sessionTimeLeft = parseInt(session.timeLeft, 10);
        sessionRefreshLength = 1800;
        sessionExpiry = Math.ceil(Date.now() / 1000) + sessionRefreshLength;
        checkSession(0);
      }

      var elapsedMinutes = 0;
      sessionTimer = $interval(function() {
        elapsedMinutes++;
        checkSession(elapsedMinutes);
      }, 60000);

      //Detect environment based on URL
      function detectEnvironment() {
        var subdomainEnvironmentMappings = {
            'hallways': 'prod',
            'hallways-staging': 'staging',
            'hallways-test': 'test'
          },
          host = $location.host(),
          subdomain = host.indexOf('.') !== -1 ? host.split('.')[0] : host,
          isLocal = host.indexOf('.local') !== -1;

        if (isLocal) {
          return 'local';
        }

        return subdomainEnvironmentMappings[subdomain] || 'dev';
      }

      //Set Google Analytics tracking ID based on the environment
      var environment = detectEnvironment(),
        gaTrackingIds = {
          'prod': 'UA-51490338-1',
          'staging': 'UA-51490338-4',
          'test': 'UA-51490338-3',
          'dev': 'UA-51490338-2 '
        },
        gaTrackingId = gaTrackingIds[environment] || gaTrackingIds.dev;

      //Pass the current filters on to GTM Data Layer
      function setDataLayer(data) {
        if ($window.tm) {
          $window.tm.push(data);
        }
      }

      //Sets the App state on the Data Layer
      function setDataLayerContext(app) {
        if ($window.tm) {
          $window.tm.push({
            appState: {
              appName: app,
              search: $location.search(),
              path: $location.path()
            }
          });
        }
      }

      return {
        setDataLayer: setDataLayer,
        setDataLayerContext: setDataLayerContext,
        sessionTimeLeft: sessionTimeLeft,
        setSessionProperties: setSessionProperties,
        sessionRefreshLength: sessionRefreshLength,
        GoogleAnalytics: {
          trackingId: gaTrackingId
        },
        Solutions: $resource(oldBaseUrl + 'ContractSolutions/retrieve'),
        Categories: $resource(oldBaseUrl + 'Categories/retrieve'),
        SubCategories: $resource(oldBaseUrl + 'SubCategories/retrieve'),
        SolutionTypes: $resource(oldBaseUrl + 'SolutionTypes/retrieve'),
        AvailableTo: $resource(oldBaseUrl + 'AvailableTo/retrieve'),
        Authw: $resource(baseUrl + 'auth'),
        Auth: $resource(baseUrl + 'auth', {}, {
          get: {
            method: 'GET',
            cache: false
          },
          logout: {
            method: 'DELETE'
          }
        }),
        Hallways: $resource(baseUrl + 'hallways/:id', { id: '@id' }),
        Podcast: $resource(baseUrl + 'podcast-article/:id',{ id: '@id' }),
        News: $resource(baseUrl + 'news'),
        Articles: $resource(baseUrl + 'hallway-articles', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Documents: $resource(baseUrl + 'hallway-documents', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        VideoArticles: $resource(baseUrl + 'hallway-videoarticles', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Historical: $resource(baseUrl + 'hallway-historical', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Transactional: $resource(baseUrl + 'hallway-transactional', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Help: $resource(baseUrl + 'help/:featureName', { featureName: '@featureName' }),
        Footer: $resource(baseUrl + 'footers'),
        SOWDocument: $resource(baseUrl + 'sow/:id', { id: '@id' }, {
          get: {
            method: 'GET',
            cache: false
          },
          save: {
            method: 'POST',
            url: baseUrl + 'sow?word=:word&pdf=:pdf',
            params: {
              word: '@word',
              pdf: '@pdf'
            }
          }
        }),
        Navigation: $resource(baseUrl + 'navigation/:menuName', { menuName: '@menuName' }, {
          query: {
            method: 'GET',
            isArray: false
          }
        }),
        Preferences: $resource(baseUrl + 'preferences', {}, {
          get: {
            method: 'GET',
            cache: false
          },
          create: {
            method: 'POST'
          },
          remove: {
            method: 'DELETE',
            url: baseUrl + 'preferences/:itemId',
            params: { itemId: '@itemId' }
          }
        }),
        DataIssue: $resource(baseUrl + 'data-issue', {}, {
          create: {
            method: 'POST'
          }
        }),
        SOWLSearch: $resource(baseUrl + 'sowl/:search', { search: '@search' }, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        SOWCategories: $resource(baseUrl + 'sow-categories'),
        hresource: $resource(baseUrl + 'hallway_resources'),
        HallwaysResource: $resource(baseUrl + 'hallway_resources', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        GatewaysEventsFeed: $resource(baseUrl + 'gateway-events', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Nodes: $resource(baseUrl + 'nodes', {}, {
          get: {
            method: 'GET',
            ttl: 3
          }
        }),
        Tiles: $resource(baseUrl + 'gateway-tiles', {}, {
          get: {
            method: 'GET',
            ttl: 1
          }
        }),
        Comments: $resource(baseUrl + 'comments/:id', { id:'@id' }, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Topics: $resource(baseUrl + 'topics/:id', { id:'@id' }, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Communities: $resource(baseUrl + 'communities/:id', { id:'@id' }),
        NodeHistory: $resource(baseUrl + 'history', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        WelcomeModal: $resource(baseUrl + 'sow-modal', {}, {
          get: {
            method: 'GET',
            cache: false
          }
        }),
        SolutionsFinderUserAgency: $resource(baseUrl + 'solutions-finder-user-agency/:agency', { agency: '@agency' }, {
          create: {
            method: 'POST',
            url: baseUrl + 'solutions-finder-user-agency'
          }
        }),
		    SearchSuggestions: $resource(baseUrl + 'search-suggestions', {}, {
          create: {
            method: 'POST'
          }
        }),
		    SOWLSuggestions: $resource(baseUrl + 'sowl-typeahead'),
        Projects: $resource(baseUrl + 'projects/:id', { id: '@id' }, {
          get:{
            method:'GET',
            cache:false
          }
        }),
        PrivateEvents:$resource(baseUrl + 'private-events/:id', { id: '@id' }, {
          get:{
            method:'GET',
            cache:false
          },
          query:{
            method:'GET',
            cache:false,
            isArray: false
          }
        }),
        Tasks: $resource(baseUrl + 'tasks/:id', { id: '@id' }, {
          get:{
            method:'GET',
            cache:false
          },
          query:{
            method:'GET',
            cache:false,
            isArray: false
          }
        }),
        ProjectEntities: $resource(baseUrl + 'projects-entity/:id', { id: '@id' }, {
          query:{
            method:'GET',
            cache:false,
            isArray: false
          },
          save: {
            method: 'POST',
            cache: false
          }
        }),
        ProjectFileUpload: $resource(baseUrl + 'project-files/:id', { id: '@id' }, {
          save: angular.extend({ method: 'POST' }, fileUploadConfig),
          update: angular.extend({ method: 'PUT' }, fileUploadConfig),
          get: {
            method: 'GET',
            cache: false
          }
        }),
        Certifications: $resource(baseUrl + 'certifications', {}, {
          query:{
            method:'GET',
            cache:false,
            isArray: false
          }
        }),
        Votes: $resource(baseUrl + 'votes/:type', { type: '@type' }, {
          getForItem: {
            method: 'GET',
            url: baseUrl + 'votes/:type/:id',
            params: {
              type: '@type',
              itemId: '@id'
            },
            cache: false
          },
          create: {
            method: 'POST',
            url: baseUrl + 'votes',
            params: {}
          }
        }),
        User: $resource(baseUrl + 'user-profile/:id', { id: '@id' }, {
          query: {
            method: 'GET',
            isArray: false
          },
          get: {
            method: 'GET',
            cache: false
          },
          update: {
            method: 'PUT',
            transformRequest: function(data) {
              delete data.id;
              return angular.toJson(data);
            },
            cache: false
          }
        })
      };
    });
  }
);
