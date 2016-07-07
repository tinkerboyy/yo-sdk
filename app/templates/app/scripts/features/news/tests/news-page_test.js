define(
  [
    'angular',
    'components/components-module',
    'features/news/news-page-module'
  ],
  function (angular) {

    var testNewsData = {
        data: [
          {
            "id": "1",
            "label": "test",
            "shortdescription": "description",
          }
        ]
    };
    var testHallwaysData = {
        data: [
          {
            "id": "1255",
            "label": "test",
            "portfolioheadertextareanew": {},
            "self": "http://sand.hallways.com/api/v1.0/hallway_resources/1255",
            "url": "name",
            "description": "test data",
            "communityhallway": { tid: 1 },
            "description": "test data",
            "portfoliocategory": "name"
          }
        ]
    };

   beforeEach(module('gateways.components'));
   beforeEach(module('gateways.news'));

   describe('News Item Controller', function () {
      var $scope
      , $httpBackend
      , AGService
      , DataService;

      beforeEach(inject(function(_$rootScope_, _$modal_, $controller, _$httpBackend_,
      _AGService_, _DataService_) {
      $scope = _$rootScope_.$new();
      $httpBackend = _$httpBackend_;
      AGService = _AGService_;
      DataService = _DataService_;

      $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
      $httpBackend.when('GET', '/api/v1.0/hallways').respond(testHallwaysData);
      $httpBackend.when('GET', '/api/v1.0/news').respond(testNewsData);

      $controller('NewsPageController', {
        $scope: $scope,
        DataService: DataService,
      });
          $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should see environment title', function() {
        expect(AGService.data.banner.env).toEqual([ 'learn', 'connect', 'act' ]);
      });

      it('should set custom banner class', function(){
        expect(AGService.data.banner.klass).toEqual('ag-banner-align-left');
      });

      it('should see banner title & subtitle', function() {
        expect(AGService.data.banner.title).toEqual('My News');
        expect(AGService.data.banner.subtitle).toEqual('Your look at the latest news, content, and data on the Acquisition Gateway.');
      });

      it('should get hallways data', function(){
          expect($scope.hallways).toEqual(testHallwaysData.data);
      });

      it('should get News Item data', function(){
        expect($scope.news).toEqual(testNewsData.data[0]);
      });
    });
}
);
