define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/services/notifications',
    'components/directives/user-profile/user-profile.html',
    'components/directives/user-profile/user-profile-directive'
    ],
    function(angular) {
      describe('User Profile Directive', function() {
        var $scope = {},
          $attrs = {},
          $modal = jasmine.createSpy(),
          $agLoader,
          AGNotifications,
          $httpBackend,
          AGService,
          $compile,
          $agFileUpload;

        var testProfile = {
          name: 'John Smith',
          jobTitle: 'Aquisition Specialist',
          agency: 'General Services Administration',
          picture: {
            url: 'http://gsa.gov/profiles/john_smith.jpg'
          },
          certifications: [],
          id: 1234,
          imageUrl: 'http://gsa.gov/profiles/john_smith.jpg'
        };

        var testCertifications = [
          { id: 1, name: 'Certification 1' },
          { id: 2, name: 'Certification 2' },
          { id: 3, name: 'Certification 3' }
        ];

        beforeEach(module('gateways.components'));

        beforeEach(inject(function($rootScope, $controller, _AGService_, _$agLoader_, _$httpBackend_, $http, _$agFileUpload_, _$compile_) {
          $scope = $rootScope.$new();
          AGService = _AGService_;
          $agLoader = _$agLoader_;
          $httpBackend = _$httpBackend_;
          $agFileUpload = _$agFileUpload_;
          $compile = _$compile_

          AGService.data.user = {
            id: 1234,
            user_info: {
              realname: 'John Smith',
              field_job_title: {
                und: [
                  { value: 'Aquisition Specialist' }
                ]
              },
              field_user_cas_agency: {
                und: [
                  { value: 'General Services Administration' }
                ]
              },
              picture: {
                url: 'http://gsa.gov/profiles/john_smith.jpg'
              }
            },
            preferences: { follow: {} }
          };

          $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
          $httpBackend.expectGET('/api/v1.0/help/user-profile').respond({});
          $httpBackend.when('GET', '/api/v1.0/user-profile/1234').respond({ data: [ testProfile ] });
          $httpBackend.when('GET', '/api/v1.0/certifications').respond({ data: testCertifications });
          $httpBackend.when('PUT', '/api/v1.0/user-profile/6789').respond(200);

          $controller('UserProfileController', {
            $scope: $scope,
            $attrs: $attrs,
            AGService: _AGService_,
            $modal: $modal,
            $agLoader: _$agLoader_,
            $http: $http,
            $agFileUpload: $agFileUpload
          });

          $httpBackend.flush();
        }));

        afterEach(function() {
          $httpBackend.verifyNoOutstandingRequest();
          $httpBackend.verifyNoOutstandingExpectation();
        });

        it('should compile the directive', function() {
          var element = angular.element('<ag-user-profile></ag-user-profile>');
          $scope.viewAll = jasmine.createSpy();
          $compile(element)($scope);
          $scope.$digest();
          $httpBackend.flush();
          expect(element.html()).toContain('<h4 class="user-name">');
        });

        it('should populate scope with profile info', function() {
          expect($scope.user).toEqual(testProfile);
        });

        it('should open edit profile modal', function() {
          $scope.editProfile();

          expect($scope.profile).toEqual($scope.user);

          expect($scope.profileError).toEqual(false);
          expect($modal).toHaveBeenCalledWith(jasmine.objectContaining({
            templateUrl: 'scripts/components/directives/user-profile/user-profile-form.html',
            scope: $scope,
            show: true,
            container: 'body',
            placement: 'left',
          }));
        });

        it('should not open the edit profile modal if it\'s already open', function() {
          $scope.profileOpen = true;
          var test = $scope.editProfile();
          expect(test).toBe(false);
        });

        it('should close the profile editor', function() {
          var cb = jasmine.createSpy();
          $scope.profileOpen = true;
          $scope.closeProfile(cb);
          expect($scope.profileOpen).toBe(undefined);
          expect(cb).toHaveBeenCalled();
        });

        it('should upload picture', function() {
          $scope.profile = { picture: {}};
          var imageLoader = {
              requests: ['123'],
              finish: function() { }
            },
            elementController = {
              $valid: true
            },
            element = [{
              value: 'image.jpg',
              files: [
                {
                  name:'/some/path/to/image.jpg',
                  type: 'image/jpeg',
                  size: 200000
                }
              ]
            }],
            fileResponse = {
              data: [
                {
                  url: 'http://hallways-unittest.cap.gsa.gov/profiles-pics/image.jpg',
                  fid: '234567'
                }
              ]
            };
          spyOn($agLoader, 'getLoader').and.returnValue(imageLoader);
          spyOn(imageLoader, 'finish');
          spyOn($agFileUpload, 'uploadFile').and.returnValue({
            then: function(success, error) {
              success({
                data: fileResponse
              });
            }
          });

          $scope.uploadPic(element, elementController);

          expect($agFileUpload.uploadFile).toHaveBeenCalledWith(
            'user-profile-picture',
            element
          );

          expect($agLoader.getLoader).toHaveBeenCalledWith(true);
          expect($scope.profile.imageUrl).toEqual('http://hallways-unittest.cap.gsa.gov/profiles-pics/image.jpg');
          expect($scope.profile.imageId).toEqual('234567');
          expect(imageLoader.finish).toHaveBeenCalledWith('123');
          expect($scope.picError).toEqual(false);
        });

        it('should not allow upload of invalid file type', function() {
          $scope.profile = {};
          var imageLoader = {
              requests: ['123'],
              finish: function() { }
            },
            elementController = {
              $valid: false
            },
            element = [{
              value: 'image.jpg',
              files: [
                {
                  name:'/some/path/to/image.jpg',
                  type: 'image/jpeg',
                  size: 200000
                }
              ]
            }];

          spyOn($agLoader, 'getLoader').and.returnValue(imageLoader);
          spyOn(imageLoader, 'finish');
          spyOn($agFileUpload, 'uploadFile');

          $scope.uploadPic(element, elementController);

          expect($agLoader.getLoader).not.toHaveBeenCalled();
          expect($agFileUpload.uploadFile).not.toHaveBeenCalled();
          expect($scope.picError).toEqual(true);
          expect(imageLoader.finish).not.toHaveBeenCalled();
        });

        it('should handle error when uploading pic', function() {
          $scope.profile = {};
          var imageLoader = {
              requests: ['123'],
              finish: function() { }
            },
            elementController = {
              $valid: true
            },
            element = [{
              value: 'image.jpg',
              files: [
                {
                  name:'/some/path/to/image.jpg',
                  type: 'image/jpeg',
                  size: 200000
                }
              ]
            }],
            fileResponse = {
              data: [
                {
                  url: 'http://hallways-unittest.cap.gsa.gov/profiles-pics/image.jpg',
                  fid: '234567'
                }
              ]
            };
          spyOn($agLoader, 'getLoader').and.returnValue(imageLoader);
          spyOn(imageLoader, 'finish');
          spyOn($agFileUpload, 'uploadFile').and.returnValue({
            then: function(success, error) {
              error();
            }
          });

          $scope.uploadPic(element, elementController);

          expect($agLoader.getLoader).toHaveBeenCalledWith(true);
          expect($agFileUpload.uploadFile).toHaveBeenCalledWith(
            'user-profile-picture',
            element
          );
          expect(imageLoader.finish).toHaveBeenCalledWith('123');
          expect($scope.profile.imageUrl).toEqual('');
          expect($scope.profile.imageId).toEqual(undefined);
          expect($scope.picError).toEqual(true);
        });

        it('should update profile', function() {
          spyOn($agLoader, 'getLoader').and.callThrough();
          var callback = jasmine.createSpy();
          var profileResponse = {
              agency: null,
              name: 'Suzy Queue1',
              jobTitle: 'Manager1',
              id: '6789',
              email: null,
              label:'Suzy Queue',
              picture: {fid: 12345},
              certifications:[]
            };

          $scope.profile = {
            name: 'Suzy Queue',
            jobTitle: 'Manager',
            imageId: 12345,
            id: 6789,
            certifications:[],
            picture: {url: null}
          };

          $httpBackend.expectPUT('/api/v1.0/user-profile/6789', {
            name: 'Suzy Queue',
            jobTitle: 'Manager',
            picture: 12345,
            certifications:[]
          }).respond(200, profileResponse);

          $scope.submitProfile(callback);
          spyOn($scope.profileLoader, 'finish');
          $httpBackend.flush();

          expect($agLoader.getLoader).toHaveBeenCalledWith(true);
          expect(AGService.data.user.user_info.field_job_title.und[0].value).toEqual('Manager');
          expect(AGService.data.user.user_info.realname).toEqual('Suzy Queue');
          expect($scope.profileLoader.finish).toHaveBeenCalled();
          expect($scope.profileError).toEqual(false);
          expect(callback).toHaveBeenCalled();

          // it should handle unset profile properties gracefully when updating a profile
          delete AGService.data.user.user_info.field_job_title;
          delete AGService.data.user.user_info.picture;
          delete $scope.user.picture.fid;
          delete $scope.profile.name;
          delete $scope.profile.jobTitle;
          $scope.profile.imageUrl = 'test url';

          $httpBackend.when('PUT', '/api/v1.0/user-profile').respond(profileResponse);

          $scope.submitProfile(callback);
          $httpBackend.flush();

          expect(AGService.data.user.user_info.field_job_title).toEqual({ und: [{ value: null }] });
          expect(AGService.data.user.user_info.realname).toEqual(null);
          expect(AGService.data.user.user_info.picture.url).toEqual('test url');

          $scope.user.picture = true;
          $scope.submitProfile(callback);
          $httpBackend.flush();
        });

        it('should handle error when updating profile', function() {
          var profileLoader = {
              requests: ['098'],
              finish: function() { }
            },
            callback = jasmine.createSpy();
          spyOn($agLoader, 'getLoader').and.returnValue(profileLoader);
          spyOn(profileLoader, 'finish');

          $scope.profile = {
            name: 'Suzy Queue',
            jobTitle: 'Manager',
            imageId: 12345,
            id: 6789,
            certifications:[],
            picture: {url: null}
          };

          $httpBackend.expectPUT('/api/v1.0/user-profile/6789', {
            name: 'Suzy Queue',
            jobTitle: 'Manager',
            picture: 12345,
            certifications: []
          }).respond(500, {});

          $scope.submitProfile(callback);
          $httpBackend.flush();

          expect($agLoader.getLoader).toHaveBeenCalledWith(true);
          expect(profileLoader.finish).toHaveBeenCalledWith('098');
          expect($scope.profileError).toEqual(true);
          expect(callback).not.toHaveBeenCalled();
        });

        it('should add certifications', function() {
          $scope.profile.certifications = [];
          $scope.certification = { name: 'Certification 1' };
          $httpBackend.expect('POST', '/api/v1.0/certifications').respond({ data: [ { name: 'Certification 1', id: 1234 }] });
          $scope.addCertifications();
          $httpBackend.flush();

          expect($scope.profile.certifications[0]).toEqual({ name: 'Certification 1', id: 1234 });

        });

        it('should delete specific certification from profile list', function() {
          $scope.profile.certifications = [ 1, 2, 3, 4];
          $scope.deleteCertification(1);
          expect($scope.profile.certifications).toEqual([1, 3, 4]);
        });

      });
    }
);
