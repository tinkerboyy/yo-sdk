define([
  'angular',
  'angularMocks',
  'components/components-module',
  'features/<%= path %>/<%= featureName %>-module',
  'features/<%= path %>/<%= template %>.html'
], function(angular) {
  describe('Controller: <%= controller %>', function() {
    var $scope
    , $compile
    , element;

    beforeEach(angular.mock.module('gateways.components'));
    beforeEach(angular.mock.module('templates'));

    beforeEach(angular.mock.inject(function(_$compile_, $rootScope) {
      $scope = $rootScope.$new();
      $compile = _$compile_;
    }));

    it('should have awesome things', function() {
     // add test case
    });
  });
});