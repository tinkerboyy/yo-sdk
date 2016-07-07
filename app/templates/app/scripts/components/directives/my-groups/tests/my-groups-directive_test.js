/**
 * Created by Madhukar on 12/23/15.
 */
define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/my-groups/my-groups-directive',
    'components/directives/my-groups/my-groups.html'
  ],
  function(angular) {
    describe('My Groups Directive', function() {
      var scope
        , element
        , $httpBackend
        , $rootScope
        , $compile
        , AGService
        , myGroupsController
        , $controller;

      var groups = [];
      var followedGroup = [
        {
          followed: true,
          icon: "fa-paperclip",
          id: 940,
          label: "Administrative Support & Office Supplies",
          slug: "administrative-support-office-supplies"
        },
        {
          followed: true,
          icon: "fa-paperclip",
          id: 941,
          label: "Freight",
          slug: "administrative-support-office-supplies"
        },
        {
          followed: false,
          icon: "fa-paperclip",
          id: 942,
          label: "IT Services",
          slug: "administrative-support-office-supplies"
        }
      ];

      var data = [
        {
          description: "",
          icon: null,
          id: 942,
          label: "Category Management",
          new_topic_count: 1,
          post_count: 26,
          self: "http://hallways.localhost/api/v1.0/communities/942",
          slug: "category-management",
          topic_count: 4,
          url: "http://hallways.localhost/communities/category-management",
          weight: 11
        }
      ];


      beforeEach(angular.mock.module('gateways.components'));
      beforeEach(angular.mock.module('templates'));

      beforeEach(angular.mock.inject(function(_$rootScope_, _$controller_, _$httpBackend_, _DataService_, _AGService_, _$compile_) {
        $rootScope = _$rootScope_;
        scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        $controller = _$controller_;
        AGService = _AGService_;

        //  DataService = _DataService_;
        $compile = _$compile_;

        $httpBackend.when('GET', '/api/v1.0/preferences').respond(200);
        $httpBackend.flush();

        myGroupsController = $controller('MyGroupsController', {
          $scope: scope,
          AGService: AGService
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-my-groups></ag-my-groups>');
        $compile(element)(scope);
        scope.$digest();
        var result = element[0].querySelectorAll('.my-groups-container');
        expect(angular.element(result)).toBeDefined();
      });

      it('should watch for followed groups', function() {
        $httpBackend.expect('GET', '/api/v1.0/communities/1,2,3').respond({ data: [] });
        spyOn(scope, '$emit');
        scope.followed.push(1, 2, 3);
        $httpBackend.flush();
        expect(scope.$emit).toHaveBeenCalledWith('agContentUpdated');
        expect(scope.groups).toEqual([]);
      });

      it('should change the active group', function() {
        var group = { title: 'Test Group' };
        spyOn(scope, '$emit');
        scope.changeGroup(group);
        expect(scope.$emit).toHaveBeenCalledWith('myGroupChange', group);
      });

    });
  }
);
