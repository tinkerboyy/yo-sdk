define(
  [
    'angular',
    'angularStrap',
    'components/components-module',
    'components/directives/file-upload/file-upload-directive'
  ],
  function(angular) {
    angular.module('gateways.components')
      .controller('UserProfileController', function($scope, AGService, DataService, $modal, $agLoader, $http, $agFileUpload, $rootScope) {
        $scope.certifications = [];
        $scope.certification = {};
        $scope.user = {};
        $scope.profile = {};

        DataService.User.get({ id: AGService.data.user.id }, function(data) {
          $scope.user = data.data[0];
          $scope.user.id = AGService.data.user.id;
          $scope.user.imageUrl = $scope.user.picture.url;
        });

        //Get Help Articles
        DataService.Help.get({ featureName: 'user-profile' }, function(data) {
          $scope.help = data.data;
        });

        DataService.Certifications.query(function(data) {
          $scope.certifications = data.data;
        });

        $scope.addCertifications = function() {
          DataService.Certifications.save({ name: $scope.certification.name }, function(data) {
            $scope.profile.certifications.push(data.data[0]);
            $scope.certification.name = '';
          });
        };

        $scope.deleteCertification = function(index) {
          $scope.profile.certifications.splice(index, 1);
        };

        $scope.editProfile = function() {
          if ($scope.profileOpen) {
            return false;
          }

          $scope.profile = angular.copy($scope.user);

          $scope.profileError = false;
          $scope.profileModal = $modal({
            templateUrl: 'scripts/components/directives/user-profile/user-profile-form.html',
            scope: $scope,
            backdrop: 'static',
            show: true,
            container: 'body',
            placement: 'left'
          });

          $scope.profileOpen = true;
        };

        $scope.uploadPic = function(element, ngModel) {
          $scope.picError = false;
          if (ngModel.$valid) {
            $scope.imageLoader = $agLoader.getLoader(true);
            $scope.profile.imageUrl = '';

            $agFileUpload.uploadFile(
              'user-profile-picture',
              element
            ).then(function(data) {
              $scope.imageLoader.finish($scope.imageLoader.requests[0]);
              $scope.profile.imageUrl = data.data.data[0].url;
              $scope.profile.picture.url = data.data.data[0].url;
              $scope.profile.imageId = data.data.data[0].fid;
              var filename = data.data.data[0].url.split('/');
              $scope.file = { filename: filename[filename.length - 1] };
            }, function() {
              $scope.imageLoader.finish($scope.imageLoader.requests[0]);
              $scope.picError = true;
            });
          } else {
            $scope.picError = true;
          }
        };

        $scope.submitProfile = function(cb) {
          $scope.profileError = false;
          $scope.profileLoader = $agLoader.getLoader(true);
          var profileData = {
            id: $scope.profile.id,
            name: $scope.profile.name,
            jobTitle: $scope.profile.jobTitle,
            certifications: $scope.profile.certifications,
            picture: $scope.profile.imageId
          };

        //  $scope.user.id = $scope.profile.id;
          $scope.user.name = $scope.profile.name;
          $scope.user.jobTitle = $scope.profile.jobTitle;
          $scope.user.certifications = $scope.profile.certifications;
          $scope.user.picture.fid = $scope.profile.imageId;
          $scope.user.imageUrl = $scope.profile.imageUrl;

          DataService.User.update(profileData, function() {
           // angular.extend($scope.user, $scope.profile);
            $rootScope.$broadcast('update-profile', $scope.user);
            AGService.data.user.certifications = $scope.user.certifications;
            if (!AGService.data.user.user_info.field_job_title) {
              AGService.data.user.user_info.field_job_title = {};
            }
            if (!AGService.data.user.user_info.field_job_title.und) {
              AGService.data.user.user_info.field_job_title.und = [
                { value: null }
              ];
            }
            AGService.data.user.user_info.field_job_title.und[0].value = $scope.profile.jobTitle || null;
            AGService.data.user.user_info.realname = $scope.profile.name || null;
            //only if an image was uploaded by the user do we need to update the profile picture of the user.
            if (typeof $scope.profile.imageUrl !== 'undefined') {
              //if user hasn't setup a picture before, create an empty picture object
              if (!AGService.data.user.user_info.picture || typeof $scope.user.picture === 'undefined') {
                AGService.data.user.user_info.picture = {};
              }
              AGService.data.user.user_info.picture.url = $scope.profile.imageUrl;
              $scope.user.picture = AGService.data.user.user_info.picture;
            }
            $scope.profileLoader.finish($scope.profileLoader.requests[0]);
            cb();
            $scope.profileOpen = false;
          }, function() {
            $scope.profileLoader.finish($scope.profileLoader.requests[0]);
            $scope.profileError = true;
          });
        };

        $scope.closeProfile = function(cb) {
          $scope.$broadcast('clear');
          delete $scope.profileOpen;
          cb();
        };
      })
      .directive('agUserProfile', function() {
        return {
          restrict: 'AE',
          replace: true,
          templateUrl: 'scripts/components/directives/user-profile/user-profile.html',
          controller: 'UserProfileController',
          scope: {
            viewAll: '='
          }
        };
      });
  }
);
