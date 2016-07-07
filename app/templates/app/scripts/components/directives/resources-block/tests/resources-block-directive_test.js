define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/resources-block/resources-block-directive',
    'components/directives/resources-block/resources-block.html'

  ],
  function (angular) {
      var returnedPodcastArticle = {
        data: [
          {
            id: "244",
            name: "This is my project",
            uid: "1540",
            created: 1444703471,
            changed: null,
            status: "1",
            description: "test",
            notes: "",
            due: 1444622400
          }
        ]
      };

      var returnedFooterArticle = {
        data: [
          {
            id: "244",
            label: "This is my project",
            uid: "1540",
            body:"body content"
          }
        ]
      };

      var testResourceData = {
        data: [
          {
            id: "1234",
            label: "Resource title",
            self: "http://hallways.localhost/api/v1.0/hallway_resources/1234",
            interaction_mode: ["ACT"],
            image:null,
            link: {
              url:"#/resourceUrlLink",
              title: "Link Title",
              attributes:[],
             },
             modal_content: null,
             display_locations:[]
          }
        ]
      };

    describe('Controller: PodcastArticle', function() {
      var scope
      ,httpBackend
      ,DataService
      ,AGService
      ,GatewaysService
      ,routeParams;

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      beforeEach(inject(function( $rootScope, $controller, _$httpBackend_ , DataService , _AGService_, _GatewaysService_, _$routeParams_ ) {
      $scope = $rootScope.$new();
      $httpBackend = _$httpBackend_;
      DataService = DataService;
      AGService = _AGService_;
      GatewaysService = _GatewaysService_;

      $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
      $httpBackend.when('GET', '/api/v1.0/podcast-article?filter%5Blabel%5D=test').respond(returnedPodcastArticle);

      $controller('PodcastArticleController', {
        $scope: $scope,
        DataService: DataService,
        AGService: AGService,
        GatewaysService:GatewaysService,
        $routeParams : {label:'test'}
      });
          $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should initialize GatewaysService', function() {
        GatewaysService.init();
        expect(AGService.data.banner.env).toEqual( ['learn', 'connect', 'act'] );
        expect(AGService.data.banner.klass).toEqual( 'upperClass' );
        expect(AGService.data.banner.title).toEqual( 'Acquisition Gateway' );
        expect(AGService.data.banner.subtitle).toEqual( '<h3>Act as One for smarter acquisition</h3><p>Our vision is to provide a workspace with accurate, useful, and unbiased advice. Check back often to see the latest progress.</p>' );
        expect(AGService.data.navigation.myProfile).toEqual( true );
        expect(AGService.data.navigation.signOut).toEqual( true );
        expect(AGService.data.search.show).toEqual( false );
     });

      it('should get podcast-article data', function() {
        expect($scope.podcastResources).toEqual(returnedPodcastArticle.data[0]);
      });

      });

    describe('Controller: FooterContent',function(){
      var $scope
        ,$httpBackend
        ,DataService
        ,AGService
        ,GatewaysService
        ,routeParams;

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      beforeEach(inject(function( $rootScope, $controller, _$httpBackend_ , DataService , _AGService_, _GatewaysService_, _$routeParams_ ) {
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        DataService = DataService;
        AGService = _AGService_;
        GatewaysService = _GatewaysService_;

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/footers?filter%5Blabel%5D=test').respond(returnedFooterArticle);
        $controller('FooterContentController', {
          $scope: $scope,
          DataService: DataService,
          AGService: AGService,
          GatewaysService:GatewaysService,
          $routeParams : {label:'test'}
        });
          $httpBackend.flush();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should set AGService data property', function() {
        expect(AGService.data.banner.env).toEqual(['learn', 'connect', 'act']);
        expect(AGService.data.banner.title).toEqual('Acquisition Gateway');
        expect(AGService.data.banner.klass).toEqual('upperClass');
        expect(AGService.data.banner.subtitle).toEqual('<h3>Act as One for smarter acquisition</h3><p>Our vision is to provide a workspace with accurate, useful, and unbiased advice. Check back often to see the latest progress.</p>');
        expect(AGService.data.navigation.myProfile).toEqual(true);
        expect(AGService.data.navigation.signOut).toEqual(true);
        expect(AGService.data.search.show).toEqual(false);
      });

      it('should get footerContent data', function() {
       expect($scope.footerResources).toEqual(returnedFooterArticle.data[0]);
      });
    });

    describe('Controller: ResourcesBlock',function(){
      var $scope
        , element
        , $compile
        , $httpBackend
        , DataService
        , AGService
        , GatewaysService
        , routeParams;

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      beforeEach(inject(function( $rootScope, $controller, _$httpBackend_ , _$q_,  _$http_, _DataService_ , _AGService_, _GatewaysService_, _$routeParams_, _$compile_ ) {
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        DataService =_DataService_;
        AGService = _AGService_;
        GatewaysService = _GatewaysService_;
        $compile = _$compile_;

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', '/api/v1.0/hallway_resources').respond(testResourceData);

        $controller('ResourcesBlockController', {
          $scope: $scope,
          DataService: DataService,
          AGService: AGService,
          GatewaysService: GatewaysService,
          $routeParams : {label:'test'}
        });

        $httpBackend.flush();

      }));

      afterEach(function() {
      //  $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-resources-block></ag-resources-block>');
        $compile(element)($scope);
        $scope.$digest();
        var result = element[0].querySelectorAll('.resources');
        expect(angular.element(result)).toBeDefined();
      });

      it('should get resources data', function() {
       // $scope.resources = [];
        expect($scope.resources).toEqual(testResourceData.data);
      });
    });

    describe('trustUrl Filter', function() {
      var $filter;

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      beforeEach(inject(function(_$filter_){
        $filter= _$filter_;
      }));

      it('should safely output url links', function() {
        var result = $filter('trustUrl')('https://audiolink.mp3');
        expect(result.$$unwrapTrustedValue()).toEqual('https://audiolink.mp3');
      });

    });
  }
);
