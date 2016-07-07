/**
 * Created by Madhukar on 12/23/15.
 */
define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/pin/pin-directive',
  'components/directives/pin/pin.html'
], function(angular) {
  describe('Pin Directive', function() {
    var scope
    , analytics
    , pinController
    , $compile
    , $httpBackend
    , element;

    beforeEach(angular.mock.module('gateways.components'));
    beforeEach(angular.mock.module('templates'));

    beforeEach(angular.mock.inject(function($templateCache, _$compile_, $rootScope, $controller, _$httpBackend_, _$analytics_, DataService, AGNotifications) {
      scope = $rootScope.$new();
      $httpBackend = _$httpBackend_;
      analytics = _$analytics_;
      $compile = _$compile_;

      pinController = $controller('PinCtrl', {
        $scope: scope,
        notifications: AGNotifications,
        $analytics: analytics
      });
    }));

    afterEach(function() {
      $httpBackend.verifyNoOutstandingExpectation();
      $httpBackend.verifyNoOutstandingRequest();
    });

    var responseData = {"data":[{"itemId":"1","action":"pin","type":"solution","userId":"2078","id":"3438"}],"self":{"title":"Self","href":"http:\/\/hallways.localhost\/api\/v1.0\/preferences"}};

    it('should compile the directive', function() {
      element = angular.element('<ag-pin></ag-pin>');
      $compile(element)(scope);
      scope.$digest();
      var result = element[0].querySelectorAll('.ag-pin');
      expect(angular.element(result)).toBeDefined();
    });

    it('should have the controller defined', function() {
      expect(pinController).toBeDefined();
    });

    it('should pin the solution', function() {
      var url = '/api/v1.0/preferences';
      $httpBackend.expect('POST', url).respond(200, responseData);

      var test = {
        action: "pin",
        itemId: "1",
        type: "solution"
      };
      scope.pin(test);
      $httpBackend.flush();

    });

    it('should unpin the solution', function() {
      var callbackSpy = jasmine.createSpy();
      var test = {
        action: "pin",
        itemId: "1",
        type: "solution",
        pinned: true
      };

      $httpBackend.expect('DELETE', '/api/v1.0/preferences?filter%5Baction%5D=pin').respond(200);

      scope.pin(test);
      $httpBackend.flush();

    });

    it('should call callback method for unpin', function() {
      var callbackSpy = jasmine.createSpy();
      scope.callback = callbackSpy;
      var test = {
        action: "pin",
        itemId: "1",
        type: "solution",
        pinned: true
      };

      $httpBackend.expect('DELETE', '/api/v1.0/preferences?filter%5Baction%5D=pin').respond(200);

      scope.pin(test);
      $httpBackend.flush();

      expect(callbackSpy).toHaveBeenCalledWith(test);
    });

    it('should track pinning analytics', function() {
      var callbackSpy = jasmine.createSpy();
      scope.callback = callbackSpy;
      $httpBackend.when('POST', '/api/v1.0/preferences').respond(200, responseData);
      scope.analyticsOn = true;
      scope.type = 'test';
      scope.analyticsCategory = 'testCategory';
      var test = {
        name: 'testItem',
        action: "pin",
        id: "1",
        type: "solution"
      };

      var testData = {
        label: test.name,
        value: test.id,
        category: scope.analyticsCategory
      }
      var analyticsSpy = spyOn(analytics, 'eventTrack');
      scope.pin(test);
      $httpBackend.flush();

      expect(analyticsSpy).toHaveBeenCalledWith('test.pinned', testData );
      expect(callbackSpy).toHaveBeenCalledWith(test);
    });

    it('should track unpinning analytics', function() {
      $httpBackend.expect('DELETE', '/api/v1.0/preferences/1?filter%5Baction%5D=pin&filter%5Btype%5D=test').respond(200);
      scope.analyticsOn = true;
      scope.type = 'test';
      scope.analyticsCategory = 'testCategory';
      var test = {
        name: 'testItem',
        action: "pin",
        id: "1",
        type: "solution",
        pinned: true
      };

      var testData = {
        label: test.name,
        value: test.id,
        category: scope.analyticsCategory
      }
      var analyticsSpy = spyOn(analytics, 'eventTrack');
      scope.pin(test);
      $httpBackend.flush();

      expect(analyticsSpy).toHaveBeenCalledWith('test.unpinned', testData );
    });

  });

});
