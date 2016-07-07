define(
  [
    'angular',
    'components/components-module'
  ],
  function (angular, componentsModule) {
	  componentsModule.controller('NavController', function($scope, $modal) {
	    $scope.openModal = function(type) {
	      $modal({
	        templateUrl: 'scripts/components/directives/nav/modals/' + type + '.modal.html',
	        show: true
	      });
	    };
	  });
  }
);
