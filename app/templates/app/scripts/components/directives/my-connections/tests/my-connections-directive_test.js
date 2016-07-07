/**
 * Created by Madhukar on 12/23/15.
 */

define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/my-connections/my-connections-directive',
  'components/directives/my-connections/my-connections.html'
], function(angular) {
    describe('My Connections Directive', function() {
      var scope
      , $controller
      , $httpBackend
      , element
      , myconnectionsController
      , AGService
      , DataService
      , $compile;

      var users = [
        {
          agency: 'GSA',
          email: 'user_1@localhost.com',
          id: '1',
          jobTitle: 'Random Fellow',
          label: 'Test Name',
          name: 'Test Name'
        },
        {
          agency: 'GSA',
          email: 'user_1@localhost.com',
          id: '2',
          jobTitle: 'Random Fellow',
          label: 'Test Name',
          name: 'Test Name'
        },
        {
          agency: 'GSA',
          email: 'user_1@localhost.com',
          id: '3',
          jobTitle: 'Random Fellow',
          label: 'Test Name',
          name: 'Test Name'
        }
      ];

      beforeEach(angular.mock.module('gateways.components'));
      beforeEach(angular.mock.module('templates'));

      beforeEach(angular.mock.inject(function($rootScope, _$controller_, _$httpBackend_, _DataService_, _AGService_, _$compile_) {
        scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        $controller = _$controller_;
        AGService = _AGService_;
        DataService = _DataService_;
        $compile = _$compile_;

        $httpBackend.when('GET', '/api/v1.0/preferences').respond(200);
        $httpBackend.flush();

        myconnectionsController = $controller('MyListCtrl', {
          $scope: scope
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-my-connections></ag-my-connections>')
        $compile(element)(scope);
        scope.$digest();
        expect(element.html()).toContain('no-connections-message');
      });

      it('should have the controller defined', function() {
        expect(myconnectionsController).toBeDefined();
        scope.collection = scope.connections = users;
      });

      it('should handle the watch', function() {
        $httpBackend.expect('GET', '/api/v1.0/user-profile/1,2,3').respond({ data: []});
        var emitSpy = spyOn(scope, '$emit');
        scope.watching.push(1, 2, 3);
        scope.$digest();
        $httpBackend.flush();
        expect(emitSpy).toHaveBeenCalledWith('agContentUpdated');
      })

    });
});
