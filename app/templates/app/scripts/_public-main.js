requirejs.config({
    paths: {
      //bower
      angular: '../vendor/angular/angular',
      angularResource: '../vendor/angular-resource/angular-resource',
      angularRoute: '../vendor/angular-route/angular-route',
      angularSanitize: '../vendor/angular-sanitize/angular-sanitize',
      angularCookies: '../vendor/angular-cookies/angular-cookies',
      angularAnimate: '../vendor/angular-animate/angular-animate',
      angularStrap: '../vendor/angular-strap/dist/angular-strap',
      angularStrapTpl: '../vendor/angular-strap/dist/angular-strap.tpl',
      angularToasty: '../vendor/angular-toasty/dist/angular-toasty',
      lodash: '../vendor/lodash/lodash',
      angularScroll: '../vendor/angular-scroll/angular-scroll',
      angulartics: '../vendor/angulartics/src/angulartics',
      'angulartics-google-analytics': '../vendor/angulartics-google-analytics/lib/angulartics-google-analytics',
      jquery: '../vendor/jquery/dist/jquery',
      jqueryUi: '../vendor/jquery-ui/ui/jquery-ui',
      filesize: '../vendor/filesize/lib/filesize',
      angularUpload: '../vendor/angular-upload/angular-upload',
      jqueryAsScrollable: '../vendor/jquery-asScrollable/dist/jquery.asScrollable.all',
      moment: '../vendor/moment/moment',

      //app
      app: 'public'
    },
    shim: {
      angular: { exports: 'angular', deps: ['jquery'] },
      angularResource: { deps: [ 'angular' ] },
      angularRoute: { deps: [ 'angular' ] },
      angularSanitize: { deps: [ 'angular' ] },
      angularCookies: { deps: [ 'angular' ] },
      angularAnimate: { deps: [ 'angular' ] },
      angularStrap: { deps: [ 'angular', 'angularAnimate' ] },
      angularStrapTpl: { deps: [ 'angular', 'angularStrap' ] },
      angularToasty: { deps: ['angular'] },
      angulartics: { deps: ['angular'] },
      'angulartics-google-analytics': { deps: ['angulartics'] },
      filesize: { exports: 'filesize' },
      angularScroll: { deps: [ 'angular' ] },
      angularUpload: { deps: ['angular'] },
      lodash: {
        exports: '_'
      },
      jquery: { exports: '$' },
      jqueryUi: { deps: ['jquery'] },
      jqueryAsScrollable: { deps: ['jquery'] }
    },
    waitSeconds: 60
});

define('public-main', ['angular',
    'app',
    'components/directives/nav/nav-controller',
    'components/services/public-data-service',
    'components/services/ag-service'
  ],
  function (angular) {
    angular.element(document).ready(function() {
      if (!window.Drupal) {
        angular.bootstrap(document, [ 'gateway-public' ]);
      }
    });
  }
);
