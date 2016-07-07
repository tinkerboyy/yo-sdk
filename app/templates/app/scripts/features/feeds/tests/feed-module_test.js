define(
  [
    'angular',
    'components/components-module',
    'components/services/collection-factory',
    'features/feeds/feed-module',
    'components/filters/trust-filter',
    'features/feeds/news.html',
    'features/feeds/events.html'
  ],
  function (angular) {

    var testNodesData = {
       data: [
          {
           "id": "1",
            "label": "Test Node",
            "self": "http://sand.hallways.com/api/v1.0/nodes/1",
            "shortdescription": "description",
            "created" : "33222",
            'expiration' : '1652462400',
            'status' : '1'

          },
           {
            "id": "1257",
            "label": "Test Article",
            "self": "http://sand.hallways.com/api/v1.0/hallway-articles/1257",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": [{ "tid": "003"}, {"tid": "004" }],
            'expiration' : '1652462400',
            'status' : '1'

          },
          {
            "id": "1258",
            "label": "Test Document",
            "self": "http://sand.hallways.com/api/v1.0/hallway-documents/1258",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": [{ "tid": "002"}, {"tid": "001"}],
            'expiration' : '1652462400',
            'status' : '1'

          },
          {
            "id": "1259",
            "label": "Test Video Article",
            "self": "http://sand.hallways.com/api/v1.0/hallway-videoarticles/1259",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": [{ "tid": "002"}, {"tid": "001"}],
            'expiration' : '1652462400',
            'status' : '1'

          },
          {
            "id": "1260",
            "label": "Test Expired Document",
            "self": "http://sand.hallways.com/api/v1.0/hallway-documents/1260",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": [{ "tid": "001"}, {"tid": "002"}],
            'expiration' : '1449993600',
            'status' : '0'
          },
           {
            "id": "1261",
            "label": "Test wrong categories Document",
            "self": "http://sand.hallways.com/api/v1.0/hallway-documents/1261",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": [{ "tid": "005"}, {"tid": "006"}],
            'expiration' : '1652462400',
            'status' : '1'
          },
          {
            "id": "1262",
            "label": "Test null categories video article ",
            "self": "http://sand.hallways.com/api/v1.0/hallway-videoarticles/1262",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": null,
            'expiration' : '1652462400',
            'status' : '1'
          },
          {
            "id": "1263",
            "label": "Test null categories document article ",
            "self": "http://sand.hallways.com/api/v1.0/hallway-documents/1263",
            "shortdescription": "test data",
            "created" : "33222",
            "portfoliocategory": null,
            'expiration' : '1652462400',
            'status' : '1'
          },

        ]
    };

    var testFeedData = {
        data: [
          {
            "id": "1255",
            "event": {"value": "1443103200", "value2": "1443497400", "timezone" : "ssss", "timezone_db": "UTC", "date_type" : "datestamp"},
            "location": "test data",
            "body": "test",
            "changed" : "1212"
          },
          {
            "id": "1256",
            "event": {"value": "1653100200", "value2": "1653103200", "timezone" : "ssss", "timezone_db": "UTC", "date_type" : "datestamp"},
            "location": "test data",
            "body": "test",
            "changed" : "1212"
          }
        ]
    };

var testhallwaysData = {
        data: [
          {
            "id": "1255",
            "label": "IT Hardware",
            "self": "http://sand.hallways.com/api/v1.0/hallway-portfolio/1255",
            "portfoliocategory": [{ 'tid': '001'}, {'tid': '002'}]
          },
          {
            "id": "1256",
            "label": "Tools & Hardware",
            "self": "http://sand.hallways.com/api/v1.0/hallway-portfolio/1256",
            "portfoliocategory": [{ 'tid': '003'}, {"tid": '004'}]
          }
        ]
    };

   beforeEach(module('gateways.components'));
   beforeEach(module('gateways.feeds'));
   beforeEach(module('templates'));

   describe('Feeds Controller', function () {
     var $scope
       , $httpBackend
       , DataService
       , element
     , $compile;


      beforeEach(inject(function(_$rootScope_, _$collection_, _$interval_, $controller, _$httpBackend_, _DataService_, _$compile_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        DataService = _DataService_;
        $collection = _$collection_;
        $interval = _$interval_;
        $compile = _$compile_;
        $scope.resource = 'GatewaysEventsFeed';

      $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
      $httpBackend.when('GET', '/api/v1.0/nodes?sort=-created').respond(testNodesData);
      $httpBackend.when('GET', '/api/v1.0/gateway-events?range=all').respond(testFeedData);
      $httpBackend.when('GET', '/api/v1.0/hallways').respond(testhallwaysData);
      $httpBackend.when('GET', '/api/session/token').respond({'id': 'yyyyy'});

      $controller('AgNewsFeedController', {
        $scope: $scope,
        DataService: DataService,
        $collection: $collection,
        $interval : $interval
      });
        $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

     it('should compile the directive', function() {
       element = angular.element('<ag-news-feed></ag-news-feed>')
       $compile(element)($scope);
       $scope.$digest();
       var result = element[0].querySelectorAll('.feeds-widget');
       expect(angular.element(result)).toBeDefined()
     });

      it('should get Nodes data', function() {
        expect($scope.nodes).toEqual(testNodesData.data);
      });

       it('should get Hallway data', function() {
        expect($scope.hallways).toEqual(testhallwaysData.data);
      });

      it('should only include published news and articles with correct portfoliio categories', function() {

        expect($scope.nodeArray).toContain(testNodesData.data[0]);
        expect($scope.nodeArray).toContain(testNodesData.data[1]);
        expect($scope.nodeArray).toContain(testNodesData.data[2]);
        expect($scope.nodeArray).toContain(testNodesData.data[3]);
        expect($scope.nodeArray).not.toContain(testNodesData.data[4]);
        expect($scope.nodeArray).not.toContain(testNodesData.data[5]);
        expect($scope.nodeArray).not.toContain(testNodesData.data[6]);
        expect($scope.nodeArray).not.toContain(testNodesData.data[7]);

      });

    });

    describe('AgFeed Controller', function () {
      var $scope
      , $httpBackend
      , DataService
      , $compile
      , element;

      beforeEach(inject(function(_$rootScope_, _$collection_, $controller, _$httpBackend_, _DataService_, _$compile_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        DataService = _DataService_;
        $collection = _$collection_;
        $compile = _$compile_;
        $scope.resource = 'GatewaysEventsFeed';

      $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
      $httpBackend.when('GET', '/api/v1.0/gateway-events?range=all').respond(testFeedData);
      $httpBackend.when('GET', '/api/session/token').respond({'id': 'yyyyy'});

      $controller('AgFeedController', {
        $scope: $scope,
        DataService: DataService,
        $collection: $collection,
        $interval : $interval
      });
        $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-feed></ag-feed>')
        $compile(element)($scope);
        $scope.$digest();
        var result = element[0].querySelectorAll('.feeds-widget');
        expect(angular.element(result)).toBeDefined()
      });

      it('should get event feed data', function(){
        expect($scope.feeds).toEqual(testFeedData.data);
      });

      it('should not call pollEvents if no resource is available', function() {
        delete $scope.resource;
        delete $scope.feeds;
        $scope.init();
        expect($scope.feeds).toBe(undefined);
      });
    });
    describe('upcoming filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.feeds'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should only include events with future or present dates', function() {

        expect($filter('upcoming')(testFeedData.data)).toContain(testFeedData.data[1]);
        expect($filter('upcoming')(testFeedData.data)).not.toContain(testFeedData.data[0]);
        expect($filter('upcoming')()).toBe(null);

      });

    });
    describe('timezone filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.feeds'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should  convert UTC time to local EST time', function() {
        expect($filter('timezoneFilter')(testFeedData.data[0].event.value)).toEqual(1443103200 + 18000 - 3600);
      });

    });

    describe('nodeURLFilter filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.feeds'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should return correct url for articles', function() {
        var testArticleURL = '#/gateway/tools-and-hardware/1257/test-article';
        expect($filter('nodeURLFilter')(testNodesData.data[1], testhallwaysData.data)).toEqual(testArticleURL);

      });

      it('should return correct url for non articles (news items)', function() {
        var testNewsURL = '#/news/1/test-node';
        expect($filter('nodeURLFilter')(testNodesData.data[0], testhallwaysData.data)).toEqual(testNewsURL);
      });

    });
}
);
