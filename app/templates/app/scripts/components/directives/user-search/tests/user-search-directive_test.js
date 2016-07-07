/**
 * Created by Madhukar on 10/26/15.
 */
define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/user-search/user-search-directive',
    'components/directives/user-search/user-search.html'
  ],
  function(angular) {
    describe('User Search directive', function() {
      var $scope
        , $rootScope
        , $location
        , $httpBackend
        , mockData
        , DataService
        , $compile
        , element
        , userSearchController
        , $modal = jasmine.createSpy();


      var data = {
        data: [
          { id: null, name: 'drupal anonymous user', agency: 'unknown', email: 'unknown' },
          { id: 1, name: 'Alpha', agency: 'General Services Administration', email: 'alpha@gsa.gov' },
          { id: 1, name: 'Beta', agency: 'General Services Administration', email: 'beta@gsa.gov' },
          { id: 1, name: 'Gamma', agency: 'General Services Administration', email: 'gamma@gsa.gov' },
        ]
      };

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));


      beforeEach(inject(function(_$rootScope_, $controller, _$location_, _DataService_, _$httpBackend_, _$compile_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $location = _$location_;
        DataService = _DataService_;
        $httpBackend = _$httpBackend_;
        $compile = _$compile_;

        $httpBackend.when('GET', '/api/v1.0/user-profile').respond(data );


        userSearchController = $controller('UserSearchCtrl', {
          $scope: $scope,
          $location: $location,
          DataService: DataService,
          $modal: $modal
        });
        $httpBackend.flush();
        $scope.$digest();
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });

      it('should compile the directive', function() {
        element = angular.element('<ag-user-search></ag-user-search>');
        $compile(element)($scope);
        $scope.$digest();
        var result = element[0].querySelectorAll('.user-search-link');
        expect(angular.element(result)).toBeDefined();
      });

      it('should open the search modal', function() {
        $scope.showUserSearchModal();
        expect($modal).toHaveBeenCalledWith(jasmine.objectContaining({
          template: 'scripts/components/directives/user-search/user-search-modal.html',
          scope: $scope,
          backdrop: 'static',
          show: true
        }));
      });

      it('should get all the users on startup', function() {
        expect($scope.users.length).toBe(0);
      });

      it('should the search result', function() {
        $scope.searchResults('alpha');
        expect($scope.users.length).toBe(1);
        $scope.searchResults('');
        expect($scope.users.length).toBe(0);
      });

      it('should set page users', function() {
        var test = [
          { name: 'User 1' },
          { name: 'User 2' }
        ];

        $scope.setUsers(test);
        expect($scope.pageUsers).toBe(test);
      });
    });
  }
);
