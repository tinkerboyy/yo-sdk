define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .factory('AGService', function(DataService, $agLoader) {
        var svc = {
          banner: {
            env: [],
            klass:'',
            lcaFixed: false
          },
          footer: {
            visible: false
          },
          navigation: {},
          user: {
            preferences: {
              follow: {
                user: [],
                group: []
              },
              screen: {}
            }
          },
          search: {
            search: '',
            filters: []
          },
          menu: null,
          hallway: null
        }

        //Initialize loader
          , dataLoader = $agLoader.getLoader(true);

        //get screen preferences
        DataService.Preferences.get(function(data) {
          angular.forEach(data.data, function(dat) {
            if (dat.data) {
              svc.user.preferences[dat.action][dat.type] = dat.data;
            } else {
              if (svc.user.preferences[dat.action]) {
                svc.user.preferences[dat.action][dat.type].push(dat.itemId);
              }
            }
          });
          dataLoader.finish(dataLoader.requests[0]);
        });

        //Gets specified menu collection and sets it on the service
        function getMenu(menu) {
          DataService.Navigation.get({ menuName: menu }, function(data) {
            if (data.data && data.data.length > 0) {
              svc.navigation.sectionMenu = data.data[0].menuItems;
            }
          });
        }

        //Return service object including getMEnu method
        return {
          data: svc,
          getMenu: getMenu,
          dataLoader: dataLoader
        };
      });
  }
);
