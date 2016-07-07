var allTestFiles = [];
var TEST_REGEXP = /(spec|test)\.js$/i;

var pathToModule = function(path) {
  return path.replace(/^\/base\/app\/scripts\//, '').replace(/\.js$/, '');
};

Object.keys(window.__karma__.files).forEach(function(file) {
  if (TEST_REGEXP.test(file)) {
    // Normalize paths to RequireJS module names.
    allTestFiles.push(pathToModule(file));
  }
});

require.config({
  // Karma serves files under /base, which is the basePath from your config file
  baseUrl: '/base/app/scripts',
  paths: {
    //vendor
    angular: '../vendor/angular/angular',
    angularResource: '../vendor/angular-resource/angular-resource',
    angularRoute: '../vendor/angular-route/angular-route',
    angularSanitize: '../vendor/angular-sanitize/angular-sanitize',
    angularAnimate: '../vendor/angular-animate/angular-animate',
    angularCookies: '../vendor/angular-cookies/angular-cookies',
    angularStrap: '../vendor/angular-strap/dist/angular-strap',
    angularStrapTpl: '../vendor/angular-strap/dist/angular-strap.tpl',
    angularToasty: '../vendor/angular-toasty/dist/angular-toasty',
    angularMocks: '../vendor/angular-mocks/angular-mocks',
    lodash: '../vendor/lodash/lodash',
    angulartics: '../vendor/angulartics/src/angulartics',
    'angulartics-google-analytics': '../vendor/angulartics-google-analytics/lib/angulartics-google-analytics',
    jquery: '../vendor/jquery/dist/jquery',
    jqueryUi: '../vendor/jquery-ui/ui/jquery-ui',
    angularScroll: '../vendor/angular-scroll/angular-scroll',
    filesize: '../vendor/filesize/lib/filesize',
    angularUpload: '../vendor/angular-upload/angular-upload',
    jqueryAsScrollable: '../vendor/jquery-asScrollable/dist/jquery.asScrollable.all',
    moment: '../vendor/moment/moment',
  },
  shim: {
    angular: { exports: 'angular' },
    angularResource: { deps: [ 'angular' ] },
    angularRoute: { deps: [ 'angular' ] },
    angularSanitize: { deps: [ 'angular' ] },
    angularAnimate: { deps: [ 'angular' ] },
    angularMocks: { deps: [ 'angular' ] },
    angularCookies: { deps: [ 'angular' ] },
    angularScoll: { deps: [ 'angular' ] },
    angularStrap: { deps: [ 'angular'] },
    angularStrapTpl: { deps: [ 'angular', 'angularStrap' ] },
    angularToasty: { deps: ['angular'] },
    angulartics: { deps: ['angular'] },
    'angulartics-google-analytics': { deps: ['angulartics'] },
    filesize: { exports: 'filesize' },
    angularUpload: { deps: ['angular'] },
    lodash: {
      exports: '_'
    },
    jquery: { exports: '$' },
    jqueryUi: { deps: ['jquery'] },
    jqueryAsScrollable: { deps: ['jquery'] },
    'features/communities/communities-widget.html': { deps: ['angular'] },
    'components/directives/groups-list/groups-list.html': { deps: ['angular'] },
    'components/directives/accordion-light/accordion-light.html': { deps: ['angular'] },
    'components/directives/help/help.html': { deps: ['angular'] },
    'components/directives/smart-select/smart-select.html': { deps: ['angular'] },
    'components/directives/smart-select/smart-select-dropdown.html': { deps: ['angular'] },
    'components/directives/my-connections/my-connections.html': { deps: ['angular'] },
    'components/directives/my-groups/my-groups.html': { deps: ['angular'] },
    'components/directives/create-project/create-project.html': { deps: ['angular'] },
    'components/directives/share/share.html': { deps: ['angular'] },
    'components/directives/project-list/project-list.html': { deps: ['angular'] },
    'components/directives/add-to-project/add-to-project.html': { deps: ['angular'] },
    'components/directives/loader/loader.html': { deps: ['angular'] },
    'components/directives/resources-block/resources-block.html': { deps: ['angular'] },
    'components/directives/pagination/pagination.html': { deps: ['angular'] },
    'features/feeds/news.html': { deps: ['angular'] },
    'features/feeds/events.html': { deps: ['angular'] },
    'components/directives/pin/pin.html': { deps: ['angular'] },
    'components/directives/user-search/user-search.html': { deps: ['angular'] },
    'components/directives/applied-filters/applied-filters.html': { deps: ['angular'] },
    'components/directives/search/search.html': { deps: ['angular'] },
    'components/directives/topics/topics-list.html': { deps: ['angular'] },
    'features/gateways/gatewayHallways.html': { deps: ['angular'] },
    'features/gateways/gatewayHallways.html': { deps: ['angular'] },
    'components/directives/comments/comments.html': { deps: ['angular'] },
    'components/directives/banner/banner.html': { deps: ['angular'] },
    'components/directives/user-profile/user-profile.html': { deps: ['angular'] },
    'features/solutions-finder/solutions-finder-directive.html': { deps: ['angular'] }
  },
  // dynamically load all test files
  deps: allTestFiles,

  // we have to kickoff jasmine, as it is asynchronous
  callback: window.__karma__.start
});
