define(
  [
    'angular',
    'filesize',
    'angularUpload',
    'components/components-module'
  ],
  function(angular, filesize) {
    angular.module('gateways.components')
      .factory('$agFileUpload', function(upload, $window, $q) {
        function uploadFile(type, fileInput, additionalData) {

          var data = {
            files: fileInput,
            upload_type: type,
            iframe: $window.FormData ? false : true
          };

          if (additionalData) {
            data = angular.extend(data, additionalData);
          }
          var uploadDeferred = $q.defer();

          upload({
            url: '/api/v1.0/file',
            method: 'POST',
            data: data
          }).then(function(response) {
            if (typeof response.data === 'string') {
              response.data = angular.fromJson(response.data);
            }

            uploadDeferred.resolve(response);
          }, function(errorResponse) {
            uploadDeferred.reject(errorResponse);
          });

          return uploadDeferred.promise;
        }

        return {
          uploadFile: uploadFile
        };
      })
      .controller('AgFileUploadController', function($scope) {
        $scope.fileInputModel = {};

        $scope.formatBytes = function(bytesStr) {
          var bytes = parseInt(bytesStr, 10);
          if (isNaN(bytes)) {
            bytes = 0;
          }
          return filesize(bytes);
        };

        $scope.$on('clear', function() {
          if ($scope.file && $scope.file.filename) {
            delete $scope.file.filename;
          }
        });
      })
      .directive('agFileAllowedExtensions', function() {
        return {
          require: 'ngModel',
          link: function(scope, el, attrs, ctrl) {
            var allowedExtensions = attrs.agFileAllowedExtensions ? attrs.agFileAllowedExtensions.split(',') : [];

            ctrl.$validators.agFileAllowedExtensions = function (modelValue, viewValue) {
              if (allowedExtensions.length > 0 && modelValue) {
                var fileExt = viewValue.fileName.split('.').pop();
                if (allowedExtensions.indexOf(fileExt) === -1) {
                  return false;
                }
              }
              return true;
            };
          }
        };
      })
      .directive('agFileMaxSize', function() {
        return {
          require: 'ngModel',
          link: function(scope, el, attrs, ctrl) {
            var maxSize = parseInt(attrs.agFileMaxSize, 0);
            if (isNaN(maxSize)) {
              maxSize = 0;
            }

            ctrl.$validators.agFileMaxSize = function (modelValue, viewValue) {
              if (maxSize > 0 && viewValue && viewValue.files && viewValue.files[0].size > maxSize) {
                return false;
              }
              return true;
            };
          }
        };
      })
      .directive('agValidateFile', function() {
        return {
          require: 'ngModel',
          link: function(scope, el, attrs, ngModel) {
            scope.fileInputModel.model = ngModel;

            el.bind('change', function() {
              scope.target = el;

              scope.$apply(function() {
                var viewValue = {
                  fileName: el[0].value,
                  files: el[0].files
                };
                ngModel.$setViewValue(viewValue);
                ngModel.$render();

                if (scope.changeCallback) {
                  scope.changeCallback(el, ngModel);
                }
              });
            });
          }
        };
      })
      .directive('agFileUpload', function() {
        return {
          restrict: 'AE',
          controller: 'AgFileUploadController',
          templateUrl: 'scripts/components/directives/file-upload/file-upload.html',
          scope: {
            inputId: '@',
            inputName: '@',
            validationRules: '=?',
            maxFileSize: '@',
            allowedFileExtensions: '@',
            target: '=?',
            changeCallback: '=?',
            showValidationMessages: '@',
            imageUrl: '=?',
            profileInfo: '=?',
            file: '=?'
          },
          link: function($scope, ele) {
            $scope.changeFile = function() {
              var fileinput = ele[0].querySelector('.form-file');
              fileinput.click();
              if ($scope.file && $scope.file.filename) {
                delete $scope.file.filename;
              }
            };

            $scope.$watch('profileInfo', function() {
              $scope.userDetails = $scope.profileInfo;
            });
          }
        };
      });
  }
);
