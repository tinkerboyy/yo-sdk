define(
  [
    'angular',
    'components/components-module',
    'features/gateways/gateways-module',
    'components/filters/stripHTML-filter',
    'features/gateways/gatewayHallways.html'
  ],
  function (angular) {

    var testhallwaysData = {
        data: [
          {
            "id": "1255",
            "label": "test",
            "portfolioheadertextareanew": {},
            "self": "http://sand.hallways.com/api/v1.0/hallway_resources/1255",
             "description": "test data",
          }
        ]
    };

    var testString = 'teststringA. teststringB ';
    var testList = ['TeststringA','TeststringB'];

    beforeEach(module('gateways.components'));
    beforeEach(module('templates'));
    beforeEach(module('gateways.gateways'));

    describe('GatewayHallways Controller', function () {
      var $scope
      , $httpBackend
      , $compile
       , DataService;

      beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_, _DataService_, _$compile_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        DataService = _DataService_;
        $compile = _$compile_;

        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=follow&filter%5Btype%5D=user').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/preferences?filter%5Baction%5D=follow&filter%5Btype%5D=group').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/hallways').respond(testhallwaysData);
        $httpBackend.when('GET', '/api/v1.0/projects').respond({ data: [] });

        $controller('GatewayHallwaysController', {
          $scope: $scope,
          DataService: DataService,
        });
        $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should get hallways data', function(){
          expect($scope.hallways).toEqual(testhallwaysData.data);
      });

      it('should compile the Hallways Directive', function() {
        var element = angular.element('<div ag-gateway-hallways></div>');
        $compile(element)($scope);
        $scope.$digest();
        expect(element.html()).toContain('hallways-nav widget');
        $httpBackend.flush();
      });

    });

    describe('listFilter filter', function() {
      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.gateways'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should split a string into an array using period as delimiter', function() {
        expect($filter('listFilter')(testString)).toEqual(testList);
      });

      it('should return null if there is no data', function() {
        expect($filter('listFilter')(null)).toEqual(null);
      });
    });

    describe('Gateways Controller', function () {
      var $scope
        , $httpBackend
        , GatewaysService
        , AGService
        , DataService;

      beforeEach(module('gateways.gateways'));
      beforeEach(inject(function(_$rootScope_, $controller, _$httpBackend_, _DataService_, _GatewaysService_, _AGService_) {
        $scope = _$rootScope_.$new();
        $httpBackend = _$httpBackend_;
        DataService = _DataService_;
        AGService = _AGService_;
        GatewaysService = _GatewaysService_;

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });

        $controller('GatewaysController', {
          $scope: $scope,
          GatewaysService:GatewaysService,
          AGService: AGService,
          DataService: DataService,
        });
        $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should initialize GatewaysService', function() {
        expect(AGService.data.banner.env).toEqual( ['learn', 'connect', 'act'] );
        expect(AGService.data.banner.klass).toEqual( 'upperClass' );
        expect(AGService.data.banner.title).toEqual( 'Acquisition Gateway' );
        expect(AGService.data.banner.subtitle).toEqual( '<h3>Act as One for smarter acquisition</h3><p>Our vision is to provide a workspace with accurate, useful, and unbiased advice. Check back often to see the latest progress.</p>' );
        expect(AGService.data.navigation.myProfile).toEqual( true );
        expect(AGService.data.navigation.signOut).toEqual( true );
        expect(AGService.data.search.show).toEqual( false );
      });
    });
  }
);
