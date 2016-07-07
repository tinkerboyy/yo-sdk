define(
  [
    'angular',
    'angularMocks',
    'angulartics',
    'angulartics-google-analytics',
    'jqueryAsScrollable',
    'components/components-module',
    'components/directives/groups-list/groups-list-directive',
    'components/directives/as-scrollable/as-scrollable-directive',
    'components/directives/groups-list/groups-list.html'
  ],
  function(angular) {
    describe('Groups List Directive', function() {
      var $scope
        , $rootScope
        , $compile
        , $httpBackend
        , $filter
        , element
        , $analyticsStub
        , controller
        , $analytics
        , $location;

    var mockCommunities = {
        data: [
          { id: 123, label: 'Community 1', url: 'example.com/community-one', slug: 'community-one' },
          { id: 456, label: 'Community 2', url: 'example.com/community-two', slug: 'community-two' },
          { id: 789, label: 'Community 3', url: 'example.com/community-three', slug: 'community-three' },
        ]
      },
      mockTopics = {
        data: [ {} ]
      };

      beforeEach(module('templates'));
      beforeEach(module('gateways.components'));

      beforeEach(inject(function(_$rootScope_, _$compile_, DataService, _$httpBackend_, AGService, $controller, _$filter_, _$location_, $agLoader) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $compile = _$compile_;
        $filter = _$filter_;
        $location = _$location_;
        $httpBackend = _$httpBackend_;
        $analytics = {
          eventTrack: angular.noop
        };

        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=follow&filter%5Btype%5D=user').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=follow&filter%5Btype%5D=group').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/communities').respond(mockCommunities);
        $httpBackend.when('GET', '/api/v1.0/preferences').respond({});

        controller = $controller('GroupsListController', {
          $scope: $scope,
          $agLoader: $agLoader,
          DataService: DataService,
          $filter: $filter,
          $analytics: $analytics,
          $location: $location
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the Groups List Directive', function() {
        $scope.init();
        $httpBackend.flush();
        element = angular.element('<ag-groups-list community-slug="slug"></ag-groups-list>');
        $compile(element)($scope);
        $scope.$digest();
        expect(element.html()).toContain('<nav class="communities-list');
        spyOn($scope, 'setActiveCommunity');
        $scope.communitySlug = 'community-one';
        $scope.$digest();
      });

      it('should compile the Groups List Directive with no communities initially', function() {
        element = angular.element('<ag-groups-list></ag-groups-list>');
        $compile(element)($scope);
        $scope.$digest();
        expect(element.html()).toContain('<nav class="communities-list');
        $httpBackend.flush();
        $scope.communitySlug = 'community-one';
        $scope.$digest();
      });

      it('should have a list of communities', function() {
        $scope.init();
        $httpBackend.flush();
        expect($scope.communities.length).toEqual(mockCommunities.data.length);
      });

      it('should set an active community if a community slug is defined', function() {
        $scope.communitySlug = 'community-one';
        $scope.init();
        $httpBackend.flush();
        expect($scope.activeCommunity).toEqual('community-one');
      });

      it('should set an active community', function() {
        spyOn($analytics, 'eventTrack');
        $scope.init();
        $httpBackend.flush();
        $scope.setActiveCommunity('community-one');
        expect($scope.communitySlug).toEqual('community-one');
        expect($scope.singleTopic).toEqual(false);
        expect($scope.community).toEqual($scope.communities[0]);
        expect($scope.activeCommunity).toEqual('community-one');
        expect($analytics.eventTrack).toHaveBeenCalledWith('Load Topics', {
          label: 'Community 1',
          category: 'Communities'
        });
      });

      it('sdhould not set an unknown community', function() {
        $scope.init();
        $httpBackend.flush();
        $scope.setActiveCommunity('unknown');
        expect($scope.community).toBe(undefined);
      });

      it('should detect when the active community is actually a user profile', function() {
        spyOn($location, 'url');
        $scope.init();
        $httpBackend.flush();
        $scope.communitySlug = 'user';
        $scope.setActiveCommunity(1234);
        expect($location.url).toHaveBeenCalledWith('/communities/1234');
      });

      it('should do nothing if setActiveCommunity is called without a slug', function() {
        $scope.init();
        $httpBackend.flush();
        $scope.setActiveCommunity();
        expect($scope.community).toBe(null);
      });

      it('should make a slug', function() {
        $scope.init();
        $httpBackend.flush();
        $scope.makeSlug($scope.communities[0]);
        expect($scope.communities[0].slug).toEqual('community-one');
      });

      it('should handle the groupChange event', function() {
        $scope.init();
        $httpBackend.flush();
        spyOn($scope, 'setActiveCommunity');
        $rootScope.$broadcast('groupChange', 'community-one');
        expect($scope.setActiveCommunity).toHaveBeenCalledWith('community-one');
      });
    });
  }
);
