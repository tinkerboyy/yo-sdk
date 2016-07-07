define(
  [
    'angular',
    'angularRoute',
    'angularResource',
    'angularAnimate',
    'angularSanitize',
    'angularCookies',
    'angulartics',
    'angulartics-google-analytics',
    'components/components-module',
    'components/services/notifications',
    'components/filters/ag-date-format-filter',
    'components/filters/days-count-filter',
    'components/filters/email-format-filter',
    'components/filters/get-blurb',
    'components/filters/kebab-case-filter',
    'components/filters/string-replace-filter',
    'components/filters/unix-timestamp-to-date-filter',
    'components/filters/label-to-url-filter',
    'components/filters/trust-filter',
    'components/filters/find-index-filter',
    'components/filters/stripHTML-filter',
    'components/directives/navigation/navigation-directive',
    'components/directives/disable-input/disable-input-directive',
    'components/directives/banner/banner-directive',
    'components/directives/footer/footer-directive',
    'components/directives/help/help-directive',
    'components/directives/footer/footer-directive',
    'components/directives/pin/pin-directive',
    'components/directives/search/search-directive',
    'components/directives/accordion/accordion-directive',
    'components/directives/confirmation/confirmation-directive',
    'components/directives/accordion-select/accordion-select-directive',
    'components/directives/accordion-light/accordion-light-directive',
    'components/directives/loader/loader-directive',
    'components/directives/share/share-directive',
    'components/directives/create-project/create-project-directive',
    'components/directives/project-list/project-list-directive',
    'components/directives/add-to-project/add-to-project-directive',
    'components/directives/follow/follow-directive',
    'components/directives/vote-up-down/vote-up-down-directive',
    'components/decorators/collapse-decorator',
    'components/decorators/datepicker-decorator',
    'components/decorators/select-decorator',
    'components/directives/accordion-select/accordion-select-directive',
    'features/sowl/search-controller',
    'features/solutions-finder/solutions-finder-module',
    'features/gateways/gateways-module',
    'features/hallways/hallways-module',
    'features/sowl/sowl-module',
    'features/sowl/document-controller',
    'features/project-center/project-center-module',
    'features/feeds/feed-module',
    'features/news/news-page-module',
    'features/tutorials/tutorials-module'
  ],
  function (angular) {
    var app = angular.module('gateway-public', [
      'ngRoute',
      'ngResource',
      'ngAnimate',
      'ngSanitize',
      'ngCookies',
      'mgcrea.ngStrap',
      'angulartics',
      'angulartics.google.analytics',
      'gateways.components',
      'gateways.solutionFinder',
      'gateways.gateways',
      'gateways.hallways',
      'gateways.sowl',
      'gateways.projectCenter',
      'gateways.feeds',
      'gateways.news',
      'gateways.tutorials'
    ]);
    app.config(function($modalProvider, $alertProvider, $popoverProvider, $datepickerProvider, $timepickerProvider) {
      $modalProvider.defaults.animation = 'am-slide-top';
      $alertProvider.defaults.animation = 'am-slide-top';
      angular.extend($popoverProvider.defaults, {
        animation: null,
        autoClose: true
      });
      angular.extend($datepickerProvider.defaults, {
        iconLeft: 'fa fa-chevron-left',
        iconRight: 'fa fa-chevron-right',
        dateFormat: 'MM/dd/yyyy',
        dateType: 'unix',
        autoclose: true
      });

      angular.extend($timepickerProvider.defaults, {
        iconUp: 'fa fa-chevron-up',
        iconDown: 'fa fa-chevron-down',
        dateFormat: 'hh:mm a',
        timeType: 'unix',
        minuteStep: 1
      });
    });
    app.controller('AppController', function($scope, DataService, AGService, $window, $http, $cookies) {
      //If user is returning, forward them to their destination
      var url = $cookies.referrerUrl;
      if (url) {
        $window.location.replace(url);
      }

      //Configure/init Google Analytics
      $window.ga('create', DataService.GoogleAnalytics.trackingId, 'auto');

      //Define user as public
      AGService.data.publicUser = true;

      //Check that user is authenticated, treat any failure asa auth fail
      DataService.Auth.get(function(data) {
        $scope.authenticated = true;
        $scope.dataLoader = AGService.dataLoader;
        AGService.data.user = angular.extend(AGService.data.user, data.data[0]);

        $http.get('/api/session/token')
          .success(function(resp) {
            angular.extend($http.defaults.headers.common, resp);
          });

        $window.datalayer = [];

        //Configure/init Google Tag Manager
        angular.element(document).ready(function () {
          // jscs:disable
          // jshint ignore:start
          (function(w,d,s,l,i){
            w[l]=w[l]||[];w[l].push({'gtm.start':
            new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
            j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
            '//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
          })($window, document, 'script', 'tm', data.data[0].container_id);

          // jscs:enable
          // jshint ignore:end

          //Add user information to dataLayer
          $window.tm.push({
            user: {
              agency: data.data[0].user_info.field_user_cas_agenc ? data.data[0].user_info.field_user_cas_agency.und[0].value : null,
              jobTitle: data.data[0].user_info.field_job_title.und ? data.data[0].user_info.field_job_title.und[0].value : null,
              roles: data.data[0].user_info.roles
            }
          });
        });
      }, function() {
        $window.location.replace('/public-gateway.php');
        AGService.data.user = {};
      });

      //Default footer to not be visible, controller will specifically have to enable footer
      $scope.$on('$routeChangeStart', function () {
        AGService.data.footer.visible = false;
        AGService.data.banner.lcaFixed = false;
      });

    });
    return app;
  }
);
