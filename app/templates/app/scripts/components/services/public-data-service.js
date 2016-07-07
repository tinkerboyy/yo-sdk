define([
    'angular',
    'components/components-module'
  ],
  function (angular, componentsModule) {
    var cacheExpiry = {};
    componentsModule.config(function($resourceProvider, $httpProvider) {
      $resourceProvider.defaults.actions.update = { method: 'PUT' };
      $httpProvider.defaults.withCredentials = true;
      $httpProvider.defaults.cache = true;

      //Create interceptor for API calls
      $httpProvider.interceptors.push(function($q, $window) {
        return {
          'request': function(config) {
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
          'responseError': function(response) {
            if (response.status === 403 || response.status === 401) {
              $window.location.replace('/public-gateway.php');
            } else if (response.status === 200) {
              return response.data;
            } else {
              return $q.reject(response);
            }
          }
        };
      });
    })

    .factory('DataService', function($http, $resource, $interval, $cacheFactory, $location, $window) {

      var baseUrl = '/api/v1.0/'
        , oldBaseUrl = '/api-old/';

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
        GoogleAnalytics: {
          trackingId: gaTrackingId
        },
        Solutions: $resource(oldBaseUrl + 'ContractSolutions/retrieve'),
        Categories: $resource(oldBaseUrl + 'Categories/retrieve'),
        SubCategories: $resource(oldBaseUrl + 'SubCategories/retrieve'),
        SolutionTypes: $resource(oldBaseUrl + 'SolutionTypes/retrieve'),
        AvailableTo: $resource(oldBaseUrl + 'AvailableTo/retrieve'),
        Auth: $resource(baseUrl + 'auth', {}, {
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
            cache: false
          }
        }),
        Tiles: $resource(baseUrl + 'gateway-tiles', {}, {
          get: {
            method: 'GET',
            ttl: 1
          }
        }),
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
        })
      };
    });
  }
);
