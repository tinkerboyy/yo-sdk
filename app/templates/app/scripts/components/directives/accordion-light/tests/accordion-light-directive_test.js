/**
 * Created by Madhukar on 10/12/15.
 */

define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/accordion-light/accordion-light-directive',
    'components/directives/accordion-light/accordion-light.html'
  ],
  function(angular) {
    var element
    , $compile
    , $rootScope
    , element
    , scope
    , controller
    , AGService
    , $httpBackend;

    var responseData = {
      "data": [{
        "id": "1937",
        "userId": "2078",
        "itemId": "0",
        "type": "project welcome",
        "action": "accepted",
        "data": null
      }, {
        "id": "3183",
        "userId": "2078",
        "itemId": "942",
        "type": "group",
        "action": "follow",
        "data": null
      }],
      "count": 15,
      "self": {
        "title": "Self",
        "href": "http:\/\/hallways.localhost\/api\/v1.0\/preferences"
      }
    };

    describe('Accordion Light: Directive', function() {
      beforeEach(angular.mock.module('gateways.components'));
      beforeEach(angular.mock.module('templates'));

      beforeEach(angular.mock.inject(function($controller, _$compile_, _$rootScope_, _$httpBackend_, DataService, _AGService_) {
        $rootScope = _$rootScope_;
        scope = _$rootScope_.$new();
        $compile = _$compile_;
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;

        scope.id = 'test';
        AGService = _AGService_;
        AGService.data.user.preferences.screen.test = {};

        $httpBackend.when('GET', '/api/v1.0/preferences').respond(responseData);

        controller = $controller('AccordionLightCtrl', {
          $scope: scope,
          AGService: AGService
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the directive', function() {
        $httpBackend.flush();
        element = angular.element('<ag-accordion-light></ag-accordion-light>');
        $compile(element)(scope);
        scope.$digest();
        var result = element[0];
        expect(result.children.length > 0).toBeTruthy();
      });

      it('should have expanded with default user settings', function() {
        var test = {
          data: [
            {
              action: 'screen',
              data: 'Test Data'
            }
          ]
        };

        $httpBackend.expect('POST', '/api/v1.0/preferences').respond(200, test);
        scope.model.expanded = true;
        scope.toggle();
        expect(scope.model.expanded).toBe(false);
        $httpBackend.flush();
        expect(AGService.data.user.preferences.screen.test).toEqual('Test Data');
      });

      it('should see user preference collapsed state and use that', function() {
        AGService.data.user.preferences.screen.test.expanded = false;
        $httpBackend.flush();
        scope.init();
        expect(scope.model.expanded).toBe(false);
      });
    });
  }
);
