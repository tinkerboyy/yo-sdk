define(
  [
    'angular',
    'angularCookies',
    'angularMocks',
    'components/components-module',
    'components/services/ag-service',
    'components/services/data-service',
    'components/services/notifications',
    'features/sowl/sowl-module'
  ],
  function() {
    describe('SOWL Controller', function() {
      var $scope
        , baseUrl = '/api/v1.0/'
        , $httpBackend
        , $rootScope
        , AGService
        , $filter
        , $cookies = {}
        , $routeParams = {}
        , $location
        , SOWLService
        , $modal
        , $agFileUpload
        , $q
        , $modal = jasmine.createSpy()
        , toasty
        , DataService;

      var testData = {
        data: [
          { id: 1, name: 'category 1' },
          { id: 2, name: 'Advertising & Marketing' },
          {
            id: 3,
            name: 'category 3',
            children: [
              { id: 4, name: 'category 4' }
            ]
          }
        ]
      },
      categoriesExpectedData = [
        { id: 2, name: 'Advertising & Marketing'},
        { id: 1, name: 'category 1'},
        {
          id: 3, name: 'category 3',
          children: [
            { id: 4, name: 'category 4', categoryId: 3}
          ],
        }
      ];

      beforeEach(module('gateways.components'));
      beforeEach(module('gateways.sowl'));

      beforeEach(inject(function(_$rootScope_, $controller, _$location_, _$httpBackend_, _AGService_, _DataService_, _$filter_, _SOWLService_, _$agFileUpload_, _$q_, _toasty_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        $httpBackend = _$httpBackend_;
        AGService = _AGService_;
        $location = _$location_;
        $filter = _$filter_;
        SOWLService = _SOWLService_;
        DataService = _DataService_;
        toasty = _toasty_;

        $modal = jasmine.createSpy('$modal');
        $agFileUpload = _$agFileUpload_;
        $q = _$q_;

        $scope.sowl = {};

        $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        $httpBackend.when('GET', baseUrl + 'sow-categories').respond(testData);
        $httpBackend.when('GET', baseUrl + 'sow-modal').respond(testData);
        $httpBackend.when('GET', baseUrl + 'search-suggestions').respond({});
        $httpBackend.when('GET', '/api-old/ContractSolutions/retrieve').respond([]);

        $controller('SowlController', {
          $scope: $scope,
          AGService: AGService,
          DataService: DataService,
          $location: $location,
          SOWLService: SOWLService,
          $cookies: $cookies,
          $modal: $modal,
          $routeParams: $routeParams,
          $agFileUpload: $agFileUpload,
          $q: $q
        });
      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingRequest();
        $httpBackend.verifyNoOutstandingExpectation();
      });

      it('should set AG Service properties', function() {
        $scope.init();
        expect(AGService.data.banner.env).toEqual(['learn', 'connect', 'act']);
        expect(AGService.data.banner.title).toEqual('');
      });

      it('should load SOW categories/subcategories and populate scope with categories', function() {
        var subcategoriesExpectedData = [
            { id: 4, name: 'category 4', categoryId: 3}
          ];
        $httpBackend.expect('GET', baseUrl + 'sow-categories').respond(testData);
        $httpBackend.flush();

        expect($scope.categories).toEqual(categoriesExpectedData);
        expect($scope.allSubcategories).toEqual(subcategoriesExpectedData);
      });

      it('should display the welcome message', function() {
        $cookies.welcome = false;
        $httpBackend.expect('GET', baseUrl + 'sow-modal').respond(testData);
        $cookies.welcome = false;
        $scope.init();
        $httpBackend.flush();
        expect($scope.welcome.visible).toBe(true);
      });

      it('should toggle on the display of the welcome message', function() {
        $scope.toggleWelcome(true);
        expect($cookies.welcome).toBe(undefined);
        expect($scope.welcome.visible).toBe(true);
      });

      it('should toggle off the display of the welcome message', function() {
        $scope.toggleWelcome(false);
        expect($cookies.welcome).not.toBe(undefined);
        expect($scope.welcome.visible).toBe(false);
      });

      it('should not display the welcome modal', function() {
        $cookies.welcome = true;
        $scope.init();
        expect($cookies.welcome).toBe(true);
        expect($modal).not.toHaveBeenCalled();
      });

      it('should get the Categories', function() {
        $httpBackend.expect('GET', baseUrl + 'sow-categories').respond(testData);
        $scope.init();
        $httpBackend.flush();

        expect($scope.categories).toEqual(categoriesExpectedData);
      });

      it('should generate number of rows for categories tiles', function() {
        var test = $scope.getRows(18);
        expect(test.length).toEqual(6);
      });

      it('should return nothing if an invalid number of categories is provided', function() {
        var test = $scope.getRows(undefined);
        expect(test).toBe(undefined);
      });

      it('should slice the array at the offset and by the size provided', function() {
        var data = [1, 2, 3, 4, 5, 6, 7, 8, 9];
        var test = $filter('slice')(data, 3, 3);
        expect(test).toEqual([4, 5, 6]);
      });

      it('should upload a new SOW', function() {
        var callbackSpy = jasmine.createSpy('callback');

        spyOn(DataService.SOWDocument, 'save').and.callFake(function(params, successCallback, errorCallback) {
          successCallback();
        });

        spyOn($agFileUpload, 'uploadFile').and.callFake(function() {
          return 'fakeFilePromise';
        });

        spyOn($q, 'all').and.callFake(function() {
          return {
            then: function(successCallback, errorCallback) {
              successCallback([
                {
                  config: {
                    data: {
                      word: true
                    }
                  },
                  data: {
                    data: [
                      {
                        fid: 'wordFid'
                      }
                    ]
                  }
                },
                {
                  config: {
                    data: {
                      pdf: true
                    }
                  },
                  data: {
                    data: [
                      {
                        fid: 'pdfFid'
                      }
                    ]
                  }
                }
              ]);
            }
          }
        });

        $scope.sow = {
          title: 'This is a test',
          agency: 'Army',
          word: [{
            value: 'test.docx'
          }],
          pdf: [{
            value: 'test.pdf'
          }]
        };

        $scope.doUpload(callbackSpy);
        $httpBackend.flush();
        expect($agFileUpload.uploadFile).toHaveBeenCalledWith(
          'sow-document',
          $scope.sow.word,
          {
            'word': true
          }
        );
        expect($agFileUpload.uploadFile).toHaveBeenCalledWith(
          'sow-document',
          $scope.sow.pdf,
          {
            'pdf': true
          }
        );
        expect($q.all).toHaveBeenCalledWith(['fakeFilePromise', 'fakeFilePromise']);
        expect(DataService.SOWDocument.save).toHaveBeenCalledWith(
          {
            label: 'This is a test',
            agency: 'Army',
            word: 'wordFid',
            pdf: 'pdfFid'
          },
          jasmine.any(Function),
          jasmine.any(Function)
        );
        expect(callbackSpy).toHaveBeenCalled();
        expect($scope.processing).toBe(false);
      })

      it('should NOT try to save SOW if file upload fails', function() {
        var callbackSpy = jasmine.createSpy('callback');
        spyOn(DataService.SOWDocument, 'save').and.callFake(function(params, successCallback, errorCallback) {
          successCallback();
        });

        spyOn($agFileUpload, 'uploadFile').and.callFake(function() {
          return 'fakeFilePromise';
        });

        spyOn($q, 'all').and.callFake(function() {
          return {
            then: function(successCallback, errorCallback) {
              errorCallback();
            }
          }
        });

        $scope.sow = {
          title: 'This is a test',
          agency: 'Army',
          word: [{
            value: 'test.docx'
          }],
          pdf: [{
            value: 'test.pdf'
          }]
        };

        $scope.doUpload(callbackSpy);
        $httpBackend.flush();

        expect(DataService.SOWDocument.save).not.toHaveBeenCalled();
        expect(callbackSpy).not.toHaveBeenCalled();
        expect($scope.processing).toBe(false);
        expect($scope.error).toBe(true);
      });

      it('should NOT upload a new SOW if API error occurs', function() {
        var callbackSpy = jasmine.createSpy('callback');
        spyOn(DataService.SOWDocument, 'save').and.callFake(function(params, successCallback, errorCallback) {
          errorCallback();
        });

        spyOn($agFileUpload, 'uploadFile').and.callFake(function() {
          return 'fakeFilePromise';
        });

        spyOn($q, 'all').and.callFake(function() {
          return {
            then: function(successCallback, errorCallback) {
              successCallback([
                {
                  config: {
                    data: {
                      word: true
                    }
                  },
                  data: {
                    data: [
                      {
                        fid: 'wordFid'
                      }
                    ]
                  }
                },
                {
                  config: {
                    data: {
                      pdf: true
                    }
                  },
                  data: {
                    data: [
                      {
                        fid: 'pdfFid'
                      }
                    ]
                  }
                }
              ]);
            }
          }
        });

        $scope.sow = {
          title: 'This is a test',
          agency: 'Army',
          word: [{
            value: 'test.docx'
          }],
          pdf: [{
            value: 'test.pdf'
          }]
        };

        $scope.doUpload(callbackSpy);
        $httpBackend.flush();

        expect(DataService.SOWDocument.save).toHaveBeenCalled();
        expect(callbackSpy).not.toHaveBeenCalled();
        expect($scope.processing).toBe(false);
        expect($scope.error).toBe(true);
      })

      it('should see a search term in the URL', function() {
        $location.path('/sowl/search');
        $routeParams.search = 'testSearch';
        $scope.init();
        $httpBackend.flush();

        expect($scope.sowl.currentPage).toEqual('search-results');
        expect($scope.moreSearch).toEqual({
          search: 'testSearch'
        });
        delete $routeParams.search;
      });

      it('should see a "View All" search term in the URL', function() {
        $location.path('/sowl/search');
        $routeParams.search = '*';
        $scope.init();
        $httpBackend.flush();

        expect($scope.sowl.currentPage).toEqual('search-results');
        expect($scope.moreSearch).toEqual({
          search: ''
        });
        delete $routeParams.search;
      });

      it('should see category filter parameter in url', function() {
        $location.path('/sowl/search');
        $routeParams.search = 'test';
        $location.search().categories = '123,456';
        $scope.init();
        $httpBackend.flush();

        expect($scope.sowl.currentPage).toEqual('search-results');
        expect($scope.moreSearch).toEqual({
          search: 'test',
          categories: ['123', '456']
        });

        delete $routeParams.search;
      });

      it('should see label search parameter in the URL', function() {
        $location.path('/sowl/search');
        $routeParams.label = '110';
        $scope.init();
        $httpBackend.flush();

        expect($scope.sowl.currentPage).toEqual('search-results');
        expect($scope.moreSearch).toEqual({
          categories: ['110']
        });

        delete $routeParams.label;
      });

      it('should perform search', function() {
        var broadcastSpy = spyOn($scope, '$broadcast');
        $scope.performSearch();
        expect($scope.sowl.currentPage).toBe('search-results');
        expect($scope.sowl.labelSearch).toBe(false);
        $rootScope.$broadcast('sowl.doSearch');
      });

      xit('should view all results', function() {
        $scope.viewAll();
        expect($scope.moreSearch).toBe({});
      });

      xit('should upload sow', function() {
        $scope.uploadSow();
        expect($scope.error).toBe(false);
        expect($scope.wordError).toBe(undefined);
        expect($scope.pdfError).toBe(undefined);
        expect($scope.sow).toBe({});
        expect($modal).toHaveBeenCalledWith(jasmine.objectContaining({
          templateUrl: 'scripts/features/sowl/upload-modal.html',
          scope: $scope,
          show: true
        }));
      });

      it('should SOWl Search', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('addProject.SOWLSearch');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Congratulations, your saved search was successfully added to your project!'});
      });

      it('should SOW  Document', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('addProject.SOWDocument');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Congratulations, your SOW was successfully added to your project!'});
      });

      it('should call toasty SOWL Comments submission', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('add-comments');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your comment was successfully submitted!', position: 'bottom-right' });
      });

      it('should call toasty SOWL Comments edit', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('update-comments');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your comment was successfully updated!', position: 'bottom-right' });
      });

      it('should call toasty SOWL Comments delete', function() {
        var successSpy = spyOn(toasty, 'success');
        $rootScope.$broadcast('delete-comments');
        expect(successSpy).toHaveBeenCalledWith({ msg: 'Your comment was successfully deleted.', position: 'bottom-right' });
      });

    });

  }
);
