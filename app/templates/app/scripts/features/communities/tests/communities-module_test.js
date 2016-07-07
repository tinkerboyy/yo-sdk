define(
  [
    'angular',
    'angularMocks',
    'angulartics',
    'angulartics-google-analytics',
    'components/components-module',
    'components/filters/get-blurb',
    'components/services/ag-service',
    'components/services/data-service',
    'components/services/notifications',
    'components/directives/loader/loader-directive',
    'components/filters/kebab-case-filter',
    'components/filters/label-to-url-filter',
    'components/filters/ag-date-format-filter',
    'features/communities/communities-module',
    'features/communities/communities-widget.html'
  ],
  function (angular) {

    describe('Communities Controller', function () {
      var $scope
        , $httpBackend
        , AGService
        , DataService
        , $filter
        , $http
        , $location
        , $timeout
        , $rootScope
        , toasty
        , $analyticsStub;

    var mockCommunities = {
        data: [
          { id: 123, name: 'Community 1', url: 'example.com/community-one', slug: 'community-one' },
          { id: 456, name: 'Community 2', url: 'example.com/community-two', slug: 'community-two' },
          { id: 789, name: 'Community 3', url: 'example.com/community-three', slug: 'community-three' },
        ]
      },
      mockTopics = {
        data: [ {} ]
      },
      $routeParams = {}
      , testUser = {
        id: 1234,
        name: 'Test User'
      }

    beforeEach(module('gateways.components'));
    beforeEach(module('gateways.communities'));

    beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_,
      _AGService_, _DataService_, _$http_, $agLoader, $cacheFactory, _$location_, _$timeout_, _$filter_, _toasty_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;
        DataService = _DataService_;
        $http = _$http_;
        $location = _$location_;
        $timeout = _$timeout_;
        $filter = _$filter_;
        toasty = _toasty_;
        $analyticsStub = {
          eventTrack: angular.noop
        };

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/communities').respond(mockCommunities);
        $httpBackend.when('GET', '/api/v1.0/topics?range=100000').respond(mockTopics);
        $httpBackend.when('GET', '/api/session/token').respond({});
        $httpBackend.when('GET', '/api/v1.0/user-profile/1234').respond({ data: [testUser] });
        $cacheFactory.get('$http').removeAll();

        spyOn($http, 'get').and.returnValue({
          success: function(callback) {
            callback({});

            return {
              success: function(callback) {
                callback();
              }
            };
          }
        });

        $controller('CommunitiesController', {
          $scope: $scope,
          DataService: DataService,
          AGService: AGService,
          $http: $http,
          $routeParams: $routeParams,
          $analytics: $analyticsStub,
          $timeout: $timeout,
          toasty: toasty
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should set AG Service properties', function() {
        expect(AGService.data.banner.env).toEqual([ 'learn', 'connect', 'act' ]);
        expect(AGService.data.banner.title).toEqual('');
        expect(AGService.data.search.show).toBe(false);
      });

      it('should submit a new topic', function() {
        $httpBackend.expect('POST', '/api/v1.0/topics').respond({ data: [{ id: 123 }] });
        $scope.newTopic = {
          processing: false,
          createNewTopicExpanded: true,
          success: false,
          community: {
            id: 123456
          },
          label: 'This is a test',
          body: 'Test content'
        };

        $scope.submitNewTopic();
        $httpBackend.flush();
        $timeout.flush();

        expect($scope.newTopic.processing).toEqual(false);
        expect($scope.newTopic.success).toEqual(true);
        expect($scope.newTopic.label).toEqual('');
        expect($scope.newTopic.body).toEqual('');
        expect($scope.newTopic.createNewTopicExpanded).toBe(false);
      });

      it('should see a topic submission API error', function() {
        $httpBackend.expect('POST', '/api/v1.0/topics').respond(500, { data: [] });
        $scope.newTopic = {
          processing: false,
          createNewTopicExpanded: true,
          success: false,
          community: {
            id: 123456
          },
          label: 'This is a test',
          body: 'Test content'
        };

        $scope.submitNewTopic();
        $httpBackend.flush();

        expect($scope.newTopic.processing).toEqual(false);
        expect($scope.newTopic.error).toEqual(true);
      });

      it('should do nothing if already processing the submission of a new topic', function() {
        $scope.newTopic = { processing: true };
        $scope.submitNewTopic();
        expect($scope.newTopic.processing).toBe(true);
      });

      xit('should set the active community', function() {
        $httpBackend.flush();
        $scope.setActiveCommunity('community-one');
        expect($scope.community).toEqual($scope.communities[0]);
      });

      it('should see a single topic in the URL and set Single Topic Mode', function() {
        $routeParams.topic = 1234;
        $scope.init();
        expect($scope.singleTopic).toBe(true);
      });

      it('should see a specific Group slug and set that in the scope', function() {
        $routeParams.community = 'community-one';
        $scope.init();
        expect($scope.communitySlug).toEqual('community-one');
      });

      it('should see route to current user profile and redirect accordingly', function() {
        AGService.data.user.id = 1234;
        $routeParams.community = 'user';
        var locationSpy = spyOn($location, 'url');
        $scope.init();
        expect(locationSpy).toHaveBeenCalledWith('/communities/user/1234');
      });

      it('should load a user profile', function() {
        $routeParams.user = 1234;
        $httpBackend.expect('GET', '/api/v1.0/user-profile/1234').respond({ data: [testUser] });
        $scope.init();
        $httpBackend.flush();
        expect($scope.me).toBe(false);
        expect($scope.curUser).toEqual(testUser);
      });

      it('should see that the currently logged in user profile is loaded', function() {
        AGService.data.user.id = 1234;
        $routeParams.user = 1234;
        $scope.init();
        $httpBackend.flush();
        expect($scope.me).toBe(true);
      });

      it('should set defined Group as current group', function() {
        $scope.myGroupAction({ slug: 'test-group' });
        expect($scope.communitySlug).toEqual('test-group');
      });

      it('should switch to All Topics mode from Single Topic view', function() {
        $scope.viewAllTopics();
        expect($scope.singleTopic).toBe(false);
      });

      it('should initialize a new Topic object in the general feed', function() {
        var newTopic = {
          processing: false,
          createNewTopicExpanded: true,
          success: false,
          error: false,
          community: null,
          label: '',
          body: '',
          status: 1
        };

        $scope.createNewTopic();

        expect($scope.newTopic).toEqual(newTopic);
      });

      it('should initialize a new Topic object in a specific Group feed', function() {
        $scope.activeCommunity = 'community-one';
        $scope.communities = mockCommunities.data;
        var newTopic = {
          processing: false,
          createNewTopicExpanded: true,
          success: false,
          error: false,
          community: mockCommunities.data[0],
          label: '',
          body: '',
          status: 1
        };

        $scope.createNewTopic(mockCommunities.data[0]);

        expect($scope.newTopic).toEqual(newTopic);
      });

      it('should get a blurb string from plain text with ellipses of a certain length', function() {
        var str = 'This is a test string';
        var test = $filter('getBlurb')(str, 15);
        expect(test).toEqual('This is a test ...');
      });

      it('should get a blurb string from html text with ellipses of a certain length', function() {
        var str = '<div>This is a test string</div>';
        var test = $filter('getBlurb')(str, 15);
        expect(test).toEqual('This is a test ...');
      });

      xit('should strip out html', function() {
        var str = '<div></div>';
        var test = $filter('getBlurb')(str, 15);
        expect(test).toEqual('');
      });

      it('should return the string without ellipses if the blurb is shorter than the length', function() {
        var str = 'This is a test string';
        var test = $filter('getBlurb')(str, 24);
        expect(test).toEqual(str);
      });

      it('should vierw all community topics', function() {
        var broadcastSpy = spyOn($scope, '$broadcast');
        $scope.viewAll();
        expect($scope.communitySlug).toEqual('');
        expect(broadcastSpy).toHaveBeenCalledWith('groupChange', null);
      });

      it('should respond to menu group change event', function() {
        $rootScope.$broadcast('menuGroupChange', 'test-menu');
        expect($scope.singleTopic).toBe(false);
      });

      it('should respond to menu group change event when topic creation is open', function() {
        $scope.init();
        $httpBackend.flush();
        var createTopicSpy = spyOn($scope, 'createNewTopic');
        $scope.newTopic.createNewTopicExpanded = true;
        $rootScope.$broadcast('menuGroupChange', 'community-one');
        expect($scope.singleTopic).toBe(false);
        expect(createTopicSpy).toHaveBeenCalledWith($scope.communities[0]);
      });

      it('should respond to myGroupChange event', function() {
        var broadcastSpy = spyOn($scope, '$broadcast');
        $rootScope.$broadcast('myGroupChange', 'test-group');
        expect(broadcastSpy).toHaveBeenCalledWith('groupChange', 'test-group');
      });

      it('should show topic reply notification', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('topicReply.notify');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your reply was successfully submitted!' });
      });

       it('should show topic reply edit notification', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('topicReplyEdit.notify');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your reply was successfully updated!' });
      });

      it('should show topic reply delete notification', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('topicReplyDelete.notify');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your reply was successfully deleted.' });
      });

      //it('should show follow notification', function() {
      //  var successSpy = spyOn(toasty, 'success');
      //  var args = 'test-follow';
      //  $rootScope.$broadcast('follow.notify', args);
      //  expect(successSpy).toHaveBeenCalledWith({ msg: 'Congratulations, you are now following ' + args});
      //});

      //it('should show unfollow notification', function() {
      //  var successSpy = spyOn(toasty, 'success');
      //  var args = 'test-follow';
      //  $rootScope.$broadcast('unfollow.notify', args);
      //  expect(successSpy).toHaveBeenCalledWith({ msg: 'You are no longer following ' + args});
      //});
    });

    describe('Communities Widget Controller', function () {
      var $scope
      , $rootScope
      , $httpBackend
      , AGService
      , $compile
      , $filter;

      var testData = {
        data: [
          { topics: 'val 1' },
          { topics: 'val 2' },
          { topics: 'val 3' }
        ]
      };

      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.communities'));
      beforeEach(module('templates'));
      beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_, _AGService_,DataService, _$compile_, $templateCache) {
        $rootScope = _$rootScope_;
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;
        $compile = _$compile_;

        var dataCommunity = {
          id: 1234,
          name: 'Test Community',
          url: '/community/test-community'
        };

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/communities/1234').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/topics?filter%5Bcommunity_category_id%5D=1234&range=50').respond(testData);
        $httpBackend.when('GET', '/api/v1.0/topics').respond(testData);

        $controller('CommunitiesWidgetController', {
          $scope: $scope,
          AGService: AGService,
          DataService: DataService
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should compile the communities directive', function() {
        var element = $compile(angular.element('<ag-communities-widget></ag-communities-widget>'))($scope);
        $scope.$digest();
        $httpBackend.flush();
        expect(element.find('h5').length).toBe(1);
        expect(element.find('h5').text()).toBe('Community');

      });

      it('should get the Topics', function() {
        $httpBackend.expect('GET', '/api/v1.0/topics').respond(testData);
        $httpBackend.flush();
        expect($scope.topics).toEqual(testData.data);
      });

      it('should get topics for a specific community', function() {
        $scope.communityId = 1234;
        var dataCommunity = {
          id: 1234,
          name: 'Test Community',
          url: '/community/test-community'
        };
        var testCommunity = dataCommunity;
        testCommunity.slug = 'test-community';
        $httpBackend.expect('GET', '/api/v1.0/communities/1234').respond({ data: [dataCommunity] });
        $httpBackend.expect('GET', '/api/v1.0/topics?filter%5Bcommunity_category_id%5D=1234&range=50').respond(testData);
        $scope.init();
        $httpBackend.flush();

        expect($scope.community).toEqual(testCommunity);
        expect($scope.community.slug).toEqual('test-community');
        expect($scope.topics).toEqual(testData.data);
      });

      it('should gracefully handle an invalid community ID', function() {
        $scope.communityId = 1234;
        $httpBackend.expect('GET', '/api/v1.0/communities/1234').respond({ data: [] });
        $scope.init();
        $httpBackend.flush();
        expect($scope.community).toBe(undefined);
      });
    });
  }
);
