define(
  [
    'angular',
    'components/components-module',
    'features/sowl/sowl-module',
    'components/services/data-service',
    'components/services/ag-service',
    'features/sowl/document-controller'
  ],
  function(angular) {
    describe('Statement of Work Library Document Controller',function() {
      var $scope
        , $rootScope
        , $q
        , DataService
        , AGService
        , SOWLService
        , $location
        , $routeParams = {};

      var returnedTestData = {
        data: [
          {
            id: 403,
            title: 'Test Document',
            categories: [
              {id: 123, name: 'Test Category'},
              {id: 456, name: 'Top Level Category'}
            ]
          }
        ]
      };

      var expectedTestData = {
        data: [
          {
            id: 403,
            title: 'Test Document',
            categories: [
              {id: 123, name: 'Test Category', topLevelCategory: 'Parent Category'},
              {id: 456, name: 'Top Level Category', topLevelCategory: 'Top Level Category'}
            ],
          }
        ]
      };

      var categoriesTestData = {
        data: [
          {
            id: 234,
            name: 'Parent Category',
            children: [
              {id: 123, name: 'Test Category'}
            ]
          },
          {
            id: 456,
            name: "Top Level Category"
          }
        ]
      };

      beforeEach(module('gateways.sowl'));
      beforeEach(module('gateways.components'));

      beforeEach(inject(function(_$rootScope_, _$q_, DataService, $controller, _$httpBackend_, _AGService_, _$location_, _SOWLService_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;
        SOWLService = _SOWLService_;
        $location = _$location_;
        $q = _$q_;

        $scope.categoryNames = {};
        $scope.moreSearch = {};

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/sow/403').respond(returnedTestData);
        $httpBackend.when('GET', '/api/v1.0/votes/sow?itemId=403').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/sow-categories').respond(categoriesTestData);

        $controller('DocumentCtrl', {
          $scope: $scope,
          $q: $q,
          DataService: DataService,
          AGService: AGService,
          SOWLService: SOWLService,
          $routeParams: $routeParams
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should see the document ID and load the document', function() {
        $httpBackend.expect('GET', '/api/v1.0/votes/sow?itemId=403').respond({
          data: [
            { type: 'sow', itemId: 403, votes: 5, count: 3 }
          ]
        });
        $httpBackend.expect('GET', '/api/v1.0/sow/403').respond(returnedTestData);
        $httpBackend.expect('GET', '/api/v1.0/sow-categories').respond(categoriesTestData);
        $scope.currentDocument = {
          id: 403
        };
        $scope.init();
        $httpBackend.flush();

        expect($scope.document).toEqual(expectedTestData.data[0]);
      });
    });
  }
);
