define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/accordion-select/accordion-select-directive'
    ],
    function(angular) {
      describe('Applied Filters Provider', function() {
        var uploadFunc,
          $agFileUpload,
          $window,
          $q;

        beforeEach(module('gateways.components'));
        beforeEach(module(function ($provide) {
          uploadFunc = jasmine.createSpy('upload').and.callFake(function() {
            return {
              then: function(successCallback, errorCallback) {
                successCallback({
                  data: [{
                    fid: 123
                  }]
                });
              }
            }
          });

          $provide.value('upload', uploadFunc);
        }));

        beforeEach(inject(function(_$agFileUpload_, _$window_, _$q_) {
          $window = _$window_;
          $q = _$q_;
          $agFileUpload = _$agFileUpload_;
        }));

        it('should upload file', function() {
          var fileInput = {
            value: 'test.png'
          };

          $agFileUpload.uploadFile('user-profile-picture', fileInput, {
            otherProperty: 'someValue'
          });

          expect(uploadFunc).toHaveBeenCalledWith({
            url: '/api/v1.0/file',
            method: 'POST',
            data: {
              files: fileInput,
              upload_type: 'user-profile-picture',
              otherProperty: 'someValue',
              iframe: false
            }
          });
        });

        it('should upload file using iframes if FormData not existing', function() {
          var fileInput = {
            value: 'test.png'
          };

          $window.FormData = undefined;

          $agFileUpload.uploadFile('user-profile-picture', fileInput, {
            otherProperty: 'someValue'
          });

          expect(uploadFunc).toHaveBeenCalledWith({
            url: '/api/v1.0/file',
            method: 'POST',
            data: {
              files: fileInput,
              upload_type: 'user-profile-picture',
              otherProperty: 'someValue',
              iframe: true
            }
          });
        });
      });
    }
);
