define(
  [
    'angular',
    'components/components-module',
    'components/services/notifications',
    'features/hallways/hallways-module',
  ],
  function (angular) {

    var testhallwaysData = {
        data: [
          {
            label: "Hallway One",
            portfolioheadertextareanew: { "value" : "testdata", "summary": "" },
            portfoliocategory: [{ "tid": "003"}, {"tid": "004" }],
            slug: 'hallway-one',
            communityhallway: { "tid" : "1" }
          },
           {
            label: "Hallway Label Two",
            portfolioheadertextareanew: { "value" : "testdata", "summary": "" },
            portfoliocategory: [{ "tid": "001"}, {"tid": "002" }],
            slug: 'hallway-label-two',
            communityhallway: { "tid" : "2" }
          }
        ]
    };

    var testHistData = {
        data: [
          {
            "id": "1255",
            "label": "test",
            "histlinkabletitle": {},
            "histtitlefilelabel": "test data",
            "body": "test",
            "url": "http://hallways.localhost/hallway-one/test"
          },
          {
            "id": "1256",
            "label": "test2",
            "histlinkabletitle": {},
            "histtitlefilelabel": "test data",
            "body": "test2",
            "url": "http://hallways.localhost/hallway-label-two/test2"
          }
        ]
    };

    var testTransData = {
        data: [
          {
            "id": "1255",
            "label": "test",
            "tranurl": {},
            "body": "test data",
            "url": "http://hallways.localhost/hallway-one/test"
          },
           {
            "id": "1256",
            "label": "test2",
            "histlinkabletitle": {},
            "histtitlefilelabel": "test data",
            "body": "test2",
            "url": "http://hallways.localhost/hallway-label-two/test2"
          }
        ]
    };

var testNodesData = {
       data: [
          {
           "id": "1",
            "label": "Test Node",
            "self": "http://sand.hallways.com/api/v1.0/nodes/1",
            "shortdescription": "description",
            "created" : "33222",
            "status" : "1",
            "portfoliohallway" : {},
            author: {
              name: 'Author 1',
              uid: 1
            },
            "expiration": Math.ceil(Date.now() / 1000) - 1000
          }
          ,
           {
            "id": "1258",
            "label": "Test Article",
            "shortdescription": "test data",
            "created" : "33222",
            "status" : "1",
            "portfoliocategory": [{ "tid": "003"}, {"tid": "004" }],
            "portfoliohallway" : ["003", "004"],
            author: {
              name: 'Author 1',
              uid: 2
            },
            "expiration": Math.ceil(Date.now() / 1000) + 1000
          },
          {
            "id": "1257",
            "label": "Test Document",
            "shortdescription": "test data",
            "created" : "33222",
            "status" : "1",
            "documentupload": { "url" : "http://www.site.pdf"},
            "portfoliocategory": [{ "tid": "002"}, {"tid": "001"}],
            "portfoliohallway" : ["002", "001"],
            author: {
              name: 'Author 1',
              uid: 3
            },
            "expiration": Math.ceil(Date.now() / 1000) + 1000

          }
        ]
    };

    var testAuthors = [
      { name: 'Author 1', id: 1 },
      { name: 'Author 2', id: 2 },
      { name: 'Author 3', id: 3 },
    ];

    var testlcaObject = [{'id':'2', 'name':'Act'}, {'id':'1', 'name':'Learn'}];
    var testlcaString = "lrn-act";
    var testlcaTextString = "Act, Learn";

   beforeEach(module('gateways.components'));
   beforeEach(module('gateways.hallways'));

   describe('Hallways Controller', function () {
      var $scope
      , $httpBackend
      , AGService
      , $http
      , $filter
      , $routeParams = {}
      , toasty
      , $rootScope
      , DataService;

      beforeEach(inject(function(_$rootScope_, $controller, _$http_,  _$httpBackend_, _AGService_, _DataService_,  _$filter_, _toasty_) {
      $rootScope = _$rootScope_;
      $scope = _$rootScope_.$new();
      $httpBackend = _$httpBackend_;
      $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
      $httpBackend.when('GET', '/api/v1.0/hallways').respond(testhallwaysData);
      $httpBackend.when('POST', '/api/v1.0/history').respond({ data: [] });
      $httpBackend.when('GET', '/api/v1.0/nodes?filter%5Bportfoliohallway%5D%5Boperator%5D%5B0%5D=IN&filter%5Bportfoliohallway%5D%5Boperator%5D%5B1%5D=IN&filter%5Bportfoliohallway%5D%5Bvalue%5D%5B0%5D=003&filter%5Bportfoliohallway%5D%5Bvalue%5D%5B1%5D=004&range=all').respond(testNodesData);
      $httpBackend.when('GET', '/api/v1.0/user-profile/1').respond({ data: [testAuthors[0]] });
      $httpBackend.when('GET', '/api/v1.0/user-profile/2').respond({ data: [testAuthors[1]] });
      $httpBackend.when('GET', '/api/v1.0/user-profile/3').respond({ data: [testAuthors[2]] });
      $httpBackend.flush();

      AGService = _AGService_;
      DataService = _DataService_;
      $http = _$http_;
      $filter = _$filter_;
      $routeParams.hallway = 'hallway-one';
      toasty = _toasty_;

      $controller('HallwaysController', {
        $scope: $scope,
        DataService: DataService,
        AGService: AGService,
        $http : $http,
        $routeParams : $routeParams
      });

      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should get all hallways', function (){
        delete $routeParams.hallway;
        $scope.init();
        $httpBackend.flush();
        expect($scope.hallways).toEqual(testhallwaysData.data);
      });

      it('should get all hallways when a hallways is defined in the route', function() {
        $scope.init();
        $httpBackend.flush();
        expect($scope.hallways).toEqual(testhallwaysData.data);
        expect($scope.hallway).toEqual(testhallwaysData.data[0]);
        expect($scope.hallway.label).toEqual('Hallway One');
        expect(AGService.data.hallway).toEqual($scope.hallway);
      });

      it('should retrieve hallway articles', function() {
        $scope.init();
        $httpBackend.flush();
        expect($scope.articles).toEqual(testNodesData.data);
      });

      it('should load a specific article', function() {
        $scope.init();
        $httpBackend.flush();
        $httpBackend.expect('GET', '/api/v1.0/user-profile/2').respond({ data: [testAuthors[1]] });
        $scope.setActiveArticle($scope.articles[1]);
        $httpBackend.flush();

        expect($scope.singleArticle).toEqual(true);
        expect($scope.article).toEqual($scope.articles[1]);

        //It should set the article as active
        expect($scope.articles[1].active).toBe(true);
        expect($scope.hasNext).toBe(true);
        expect($scope.hasPrevious).toBe(true);

        //It should set the right author profile
        expect($scope.authorProfile).toEqual(testAuthors[1]);
      });

      it('should filter out expired articles', function() {
        var test = $filter('removeExpired')(testNodesData.data);
        expect(test.length).toEqual(2);
        expect(test[1]).toEqual(testNodesData.data[2]);
      });

      it('should see article ID in the route and load that article', function() {
        $routeParams.articleId = '1258';
        spyOn($scope, 'setActiveArticle').and.callThrough();
        $httpBackend.expect('GET', '/api/v1.0/user-profile/2').respond({ data: [testAuthors[1]] });
        $scope.init();
        $httpBackend.flush();

        expect($scope.setActiveArticle).toHaveBeenCalledWith($scope.articles[1]);
        expect($scope.singleArticle).toEqual(true);

        //It should set the right author profile
        expect($scope.authorProfile).toEqual(testAuthors[1]);
      });

      it('should load previous article', function() {
        $scope.init();
        $httpBackend.flush();
        $scope.setActiveArticle($scope.articles[1]);
        $httpBackend.expect('GET', '/api/v1.0/user-profile/1').respond({ data: [testAuthors[0]] });
        $scope.previousArticle();
        $httpBackend.flush();
        expect($scope.article).toEqual($scope.articles[0]);
        expect($scope.articles[1].active).toBe(undefined);

        //It should set the right author profile
        expect($scope.authorProfile).toEqual(testAuthors[0]);
      });

      it('should not try to load next if no next article is available', function() {
        $scope.hasPrevious = false;
        spyOn($scope, 'setActiveArticle');
        $scope.previousArticle();
        expect($scope.setActiveArticle).not.toHaveBeenCalled();
      });

      it('should load next article', function() {
        $scope.init();
        $httpBackend.flush();
        $httpBackend.expect('GET', '/api/v1.0/user-profile/3').respond({ data: [testAuthors[2]] });
        $scope.setActiveArticle($scope.articles[1]);

        $scope.nextArticle();
        expect($scope.article).toEqual($scope.articles[2]);
        expect($scope.articles[1].active).toBe(undefined);

        //It should set the right author profile
        expect($scope.authorProfile).toEqual(testAuthors[1]);
      });

      it('should not try to load next if no next article is available', function() {
        $scope.hasNext = false;
        spyOn($scope, 'setActiveArticle');
        $scope.nextArticle();
        expect($scope.setActiveArticle).not.toHaveBeenCalled();
      });

      it('should detect and set if no previous article is available', function() {
        $scope.init();
        $httpBackend.flush();
        $httpBackend.when('GET', '/api/v1.0/user-profile/1').respond({ data: [testAuthors[1]] });
        $scope.setActiveArticle($scope.articles[0]);
        $httpBackend.flush();

        expect($scope.hasPrevious).toBe(false);
      });

      it('should detect and set if no Next article is available', function() {
        $scope.init();
        $httpBackend.flush();
        $httpBackend.when('GET', '/api/v1.0/user-profile/3').respond({ data: [testAuthors[1]] });
        $scope.setActiveArticle($scope.articles[2]);
        $httpBackend.flush();

        expect($scope.hasNext).toBe(false);
      });

      it('should show all articles (Hallway Homepage) from single article view', function() {
        $scope.init();
        $httpBackend.flush();
        $scope.setActiveArticle($scope.articles[2]);
        $httpBackend.flush();

        $scope.viewAll();
        expect($scope.singleArticle).toBe(false);
        expect($scope.article).toBe(undefined);
      });

      it('should see environment title', function() {
        expect(AGService.data.banner.env).toEqual([ 'learn', 'connect', 'act' ]);
      });

      it('should clean document links', function() {
        $routeParams.articleId = '1258';
        $scope.init();
        $httpBackend.flush();
        $scope.setActiveArticle($scope.articles[2]);
        $httpBackend.flush();
        
        expect($scope.file).toEqual('../sites/all/libraries/pdf.js/web/viewer.html?file=http%3A%2F%2Fwww.site.pdf');
      });

      it('should toggle views', function() {
        $scope.articleView = false;
        $scope.singleArticle = true;

        $scope.toggleArticleView();
            
        expect($scope.articleView).toEqual(true);
        expect($scope.singleArticle).toEqual(false);
      });

      it('should call toasty Comments submission', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('add-comments');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your comment was successfully submitted!' });
      });

      it('should call toasty Comments edit', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('update-comments');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your comment was successfully updated!' });
      });

      it('should call toasty Comments delete', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('delete-comments');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your comment was successfully deleted.' });
      });
      
      it('should call set Single Article View', function() {
        $scope.article = {};   
        $scope.setSingleArticleView();
        expect($scope.articleView).toBe(false);
        expect($scope.singleArticle).toBe(true);
        expect($scope.article.active).toBe(true);
      });
      
    });

    describe('HallwayResource Controller', function () {
      var $scope
      , $httpBackend
      , DataService
      , modalSpy
      , AGService;

      beforeEach(inject(function(_$rootScope_, _$modal_, _$http_, _$q_, $controller, _$httpBackend_, _DataService_, _AGService_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        DataService = _DataService_;
        AGService = _AGService_;
        modalSpy = jasmine.createSpy('$modal', _$modal_);

        AGService.data.hallway = testhallwaysData.data[0];

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/hallway-historical?range=all').respond(testHistData);
        $httpBackend.when('GET', '/api/v1.0/hallway-transactional?range=all').respond(testTransData);

        $scope.$apply();
        $controller('HallwayResourceController', {
          $scope: $scope,
          DataService: DataService,
          AGService: AGService,
          $modal: modalSpy
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should get historical pricing data', function(){
        $httpBackend.flush();
        expect($scope.historical).toEqual(testHistData.data);
      });

      it('should get tranactional data', function(){
        $httpBackend.flush();
        expect($scope.transactional).toEqual(testTransData.data);
      });

      it('should open create modal', function() {
        $httpBackend.flush();
        $scope.openModalWindow();
        expect(modalSpy).toHaveBeenCalled();
      });

    })
    describe('urlFilter filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should append correct protocol to url link', function() {
        expect($filter('urlFilter')('www.somelink.com')).toEqual('http://www.somelink.com');
        expect($filter('urlFilter')('https://www.somelink.com')).toEqual('https://www.somelink.com');
        expect($filter('urlFilter')(null)).toEqual(null);
      });
    })

    describe('descFilter filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should format hallway description text', function() {
        expect($filter('descFilter')('text1. text2.')).toEqual('text1 and text2.');
        expect($filter('descFilter')('text1. text2. text3.')).toEqual('text1, text2, and text3.');
      });
    })
    describe('charLimitTo filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should convert long text to ellispes', function() {
        expect($filter('charLimitTo')('this is my long text', 5)).toEqual('this  ...');
        expect($filter('charLimitTo')('this is my long text', 50)).toEqual('this is my long text');
      });
    })
    describe('uri filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should strip public text from uri', function() {
        expect($filter('uriFilter')('public://mylink')).toEqual('mylink');
      });
    })
    describe('modifiedDate filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should calculate time from now', function() {
        expect($filter('modifiedDateFilter')((Date.now() / 1000) - 120)).toEqual('2 minutes ago');
      });
    })
    describe('videoUrl filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should calculate time from now', function() {
        expect($filter('videoUrlFilter')('https://www.youtube.com/watch?v=UgMM_TySVMs')).toEqual('https://www.youtube.com/embed/UgMM_TySVMs');
        expect($filter('videoUrlFilter')('https://youtu.be/UgMM_TySVMs')).toEqual('https://www.youtube.com/embed/UgMM_TySVMs');
        expect($filter('videoUrlFilter')('mylink.com')).toEqual('http://www.mylink.com');
        expect($filter('videoUrlFilter')(null)).toEqual(null);

      });
    })
    describe('trustResource filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.hallways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should calculate time from now', function() {
        var result = $filter('trustResource')('https://documentlink.com');
        expect(result.$$unwrapTrustedValue()).toEqual('https://documentlink.com');
      });
    });
}
);

