define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/<%= path %>/<%= directiveName %>-directive',
  'components/directives/<%= path %>/<%= template %>.html'
], function(angular) {
  describe('<%= name %> Directive', function() {
    var $scope
    , $compile
    , element;

    beforeEach(angular.mock.module('gateways.components'));
    beforeEach(angular.mock.module('templates'));

    beforeEach(angular.mock.inject(function(_$compile_, $rootScope) {
      $scope = $rootScope.$new();
      $compile = _$compile_;
    }));

    it('should compile the directive', function() {
     // add test case
    });
  });
});