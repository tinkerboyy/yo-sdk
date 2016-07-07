define([
    'angular',
    'angularSanitize',
  	'angularResource',
  	'angularStrap',
  	'angularAnimate',
    'angularRoute',
    'angularUpload',
    'angularToasty'
  ],
  function (angular) {
  	return angular.module('gateways.components',
      [ 'ngResource', 'ngSanitize', 'ngAnimate', 'ngRoute', 'mgcrea.ngStrap', 'lr.upload', 'angular-toasty' ]);
  }
);
