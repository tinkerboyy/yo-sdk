define(
  [
    'angular',
    'angulartics',
    'angulartics-google-analytics',
    'components/components-module',
    'components/services/ag-service',
    'components/services/data-service',
    'components/directives/loader/loader-directive',
    'components/directives/topics/topics-directive',
    'components/directives/vote-up-down/vote-up-down.html',
    'components/directives/topics/topics-list.html'
  ],
  function (angular) {
    describe('Topics List Directive', function () {
      var $scope
        , $httpBackend
        , AGService
        , DataService
        , $compile
        , $routeParams = {}
        , $analytics
        , $rootScope
        , $filter
        , $location
        , $analyticsStub;

      var mockTopics = {
        data: [ 
          { id: 1, name: 'Topic 1', community_category_id: 1234, uid: 12, author: { name: 'Author 1', agency: 'Agency 1', jobTitle: 'Job', mail: 'email@test.com'  } }, 
          { id: 2, name: 'Topic 2', community_category_id: 1234, uid: 12, author: { name: 'Author 1', agency: 'Agency 1', jobTitle: 'Job', mail: 'email@test.com'  }  }, 
          { id: 3, name: 'Topic 3', community_category_id: 1234, uid: 34, author: { name: 'Author 2', agency: 'Agency 1', jobTitle: 'Job', mail: 'email2@test.com'  }  }, 
        ]
      };

      var testComments = {
        data: [
          { id: 1, body: 'Comment 1' },
          { id: 2, body: 'Comment 2' },
          { id: 3, body: 'Comment 3' },
        ]
      };


      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.communities'));
      beforeEach(module('templates'));
      beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_, _AGService_, _DataService_, $agLoader, $cacheFactory, _$compile_, _$analytics_, _$location_) {
        $rootScope = _$rootScope_;
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;
        DataService = _DataService_;
        $compile = _$compile_;
        $analytics = _$analytics_;
        $location = _$location_;

        $httpBackend.when('GET', '/api/v1.0/topics?range=all').respond(mockTopics);
        $httpBackend.when('GET', '/api/session/token').respond({});
        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/comments?filter%5Bnid%5D=2&range=all').respond(testComments);

        $controller('TopicsListController', {
          $scope: $scope,
          DataService: DataService,
          AGService: AGService,
          $routeParams: $routeParams,
          $analytics: $analytics,
          $location: $location
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });


      it('should compile the directive', function() {
        var element = angular.element('<div ag-topics-list></div>');
        $compile(element)($scope);
        $scope.$digest();
        $httpBackend.flush();
        expect(element.html()).toContain('id="communities-tabs"');

      });

      it('should load topics for a group', function() {
        var entity = {
          id: 1234
        };

        $httpBackend.expect('GET', '/api/v1.0/topics?filter%5Bcommunity_category_id%5D=1234&range=all').respond(mockTopics);
        spyOn($scope, 'setTopics');
        $scope.loadTopics(entity);

        expect($scope.topics).toEqual([]);
        expect($scope.setTopics).toHaveBeenCalledWith([]);

        $httpBackend.flush();
        expect($scope.topics).toEqual(mockTopics.data);
        
      });

      it('should load a single topic', function() {
        $routeParams.topic = 1;
        spyOn($scope, 'toggleExpand').and.callThrough();
        var entity = {
          id: 1234
        };

        $scope.singleTopic = true;
        var test = [angular.copy(mockTopics.data[0])];
        test[0].expanded = true;

        var test2 = angular.copy(test);
        delete test2.expanded;

        $httpBackend.expect('GET', '/api/v1.0/topics?filter%5Bcommunity_category_id%5D=1234&range=all').respond(mockTopics);
        $scope.loadTopics(entity);
        spyOn($scope, 'setTopics');

        $httpBackend.flush();
        expect($scope.toggleExpand).toHaveBeenCalledWith($scope.topics[0]);
        expect($scope.setTopics).toHaveBeenCalledWith($scope.topics);
        expect($scope.topics).toEqual(test);
        
      });

      it('should handle an invalid topic ID gracefully', function() {
        $routeParams.topic = 'unknown';
        var entity = {
          id: 1234
        };

        $scope.singleTopic = true;
        var test = [angular.copy(mockTopics.data[0])];
        test[0].expanded = true;
        test[0].comments = testComments.data;
        $scope.loadTopics(entity);

        $httpBackend.expect('GET', '/api/v1.0/topics?filter%5Bcommunity_category_id%5D=1234&range=all').respond(mockTopics);
        $httpBackend.flush();

        expect($scope.topics).toEqual([]);
      });

      it('should load a user activity feed', function() {
        $routeParams.topic = 1;
        $scope.entityType = 'user';
        var entity = {
          id: 1234
        };
        spyOn($scope, '$emit');

        var test = [angular.copy(mockTopics.data[0])];
        test[0].expanded = true;
        test[0].comments = testComments.data;
        $scope.loadTopics(entity);

        $httpBackend.expect('GET', '/api/v1.0/comments?filter%5Buid%5D=1234').respond(testComments);
        $httpBackend.expect('GET', '/api/v1.0/topics?filter%5Buid%5D=1234&range=all').respond(mockTopics);
        $httpBackend.flush();
        expect($scope.$emit).toHaveBeenCalledWith('agContentUpdated');


        expect($scope.topics).toEqual(mockTopics.data);
      });

      it('should toggle expanded state of a topic', function() {
        var topic = angular.copy(mockTopics.data[0]);
        $scope.toggleExpand(topic);
        expect(topic.expanded).toBe(true);

        topic.type = 'comment';
        topic.nid = 1234;
        spyOn($location, 'url');

        topic.parentType = 'forum';
        $scope.toggleExpand(topic, true);
        expect($location.url).toHaveBeenCalledWith('/communities/topic/1234');

        topic.parentType = 'sow';
        $scope.toggleExpand(topic, true);
        expect($location.url).toHaveBeenCalledWith('/sowl/document/1234');

        topic.parentType = 'article';
        $scope.toggleExpand(topic, true);
        expect($location.url).toHaveBeenCalledWith('/gateway/article/1234');
      });

      it('should change group', function() {
        spyOn($scope, '$emit');
        var test = 'test';
        $scope.changeGroup(test);
        expect($scope.$emit).toHaveBeenCalledWith('myGroupChange', test);
      });

      it('should prepare feed', function() {
        $scope.comments = angular.copy(testComments.data);
        $scope.topics = angular.copy(mockTopics.data);
        $scope.prepFeed();
        expect($scope.topics).toEqual(mockTopics.data.concat(testComments.data));
      });

      it('should handle the newTopic event', function() {
        $scope.topics = mockTopics.data;
        $scope.pageTopics = mockTopics.data;
        var topic = angular.copy(mockTopics.data[0]);
        topic.id = 5;
        $rootScope.$broadcast('newTopic', topic);
        expect($scope.topics[0]).toEqual(topic);
        expect($scope.pageTopics[0]).toEqual(topic);
      });

      it('should update the user data when the user profile is updated', function() {
        var test = {
          name: 'Test User',
          agency: 'Test Agency',
          id: 12
        };
        $scope.topics = mockTopics.data;

        $rootScope.$broadcast('update-profile', test);
        $scope.$digest();
        $httpBackend.flush();

        expect($scope.topics[0].author.name).toEqual(test.name);
        expect($scope.topics[0].author.mail).toEqual(test.mail);
        expect($scope.topics[0].author.jobTitle).toEqual(test.jobTitle);
        expect($scope.topics[0].author.agency).toEqual(test.agency);
        expect($scope.topics[1].author.name).toEqual(test.name);
        expect($scope.topics[1].author.mail).toEqual(test.mail);
        expect($scope.topics[1].author.jobTitle).toEqual(test.jobTitle);
        expect($scope.topics[1].author.agency).toEqual(test.agency);
      });
    });
  }
);
