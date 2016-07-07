//Configure requirejs before beginning any process within our app. 
requirejs.config({
	//source path for our scritps;
  baseUrl: 'ag-app/app/scripts'
});

require([ 
		'angular',
		'main',
		'../../../sites/all/modules/custom/solution_finder/js/solution_finder'
	],
	function (angular) {
		angular.element(document).ready(function () {
			var element = document.getElementById('solutionFinderWidget');
			if (element) {
				angular.bootstrap(element, [ 'gateways' ]);
			}
		});
	}
);