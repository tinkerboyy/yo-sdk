define(
  [
    'angular',
    'angularRoute',
    'angularStrap',
    'angularStrapTpl',
    'components/components-module',
    'components/directives/pdf/pdf-directive',
    'features/sowl/sowl-module'
  ],
  function (angular) {
    function mapCategoriesToParent(categories) {
      var childNames = {};

      angular.forEach(categories, function(parent) {
        angular.forEach(parent.children, function(child) {
          childNames[child.name] = parent.name;
        });
      });

      return childNames;
    }

    angular.module('gateways.sowl')
      .controller('DocumentCtrl', function ($scope, $q, AGService, DataService, SOWLService, $window, $agLoader) {
        $scope.publicUser = AGService.data.publicUser;
        $window.scrollTo(0,0);

        $scope.init = function() {
          // Check for IE 9 true or not
          var ua = $window.navigator.userAgent;
          if (navigator.appVersion.indexOf('MSIE') !== -1 || ua.indexOf('Trident') >= 0 ) {
            $scope.isMSIE = true;
          }

          $scope.icons = SOWLService.data.icons;

          if ($scope.currentDocument && $scope.currentDocument.id) {
              $scope.documentLoader = $agLoader.getLoader();

              if (!$scope.publicUser) {
              //Load votes for SOWL
              var votesLoader = $scope.documentLoader.add();
                DataService.Votes.getForItem({
                  'type': 'sow',
                  'itemId': $scope.currentDocument.id
                }, function(response) {
                  $scope.votes = {};
                  $scope.votes[$scope.currentDocument.id] = response.data[0];
                  $scope.documentLoader.finish(votesLoader);
                }, function() {
                  $scope.documentLoader.finish(votesLoader);
                });
              }

              //Load document data
              var docDataLoader = $scope.documentLoader.add();
              DataService.SOWDocument.get({ id: $scope.currentDocument.id }, function(data) {
                $scope.document = data.data[0];

                DataService.SOWCategories.get(function(data) {
                  var childParentMap = mapCategoriesToParent(data.data);

                  angular.forEach($scope.document.categories, function(category, i) {
                    if (typeof childParentMap[category.name] === 'undefined') {
                      $scope.document.categories[i].topLevelCategory = category.name;
                    } else {
                      $scope.document.categories[i].topLevelCategory = childParentMap[category.name];
                    }
                  });

                  $scope.documentLoader.finish(docDataLoader);
                }, function() {
                  $scope.documentLoader.finish(docDataLoader);
                });

                //Set GTM Data
                DataService.setDataLayer({
                  agEvent: {
                    type: 'view',
                    itemType: 'SOW Document',
                    item: {
                      id: $scope.document.id,
                      name: $scope.document.label || null
                    }
                  }
                });
                DataService.setDataLayer({ 'event': 'view' });
              }, function() {
                $scope.documentLoader.finish(docDataLoader);
              });
          }

        };
        //$location.path('/sowl/search');
        $scope.init();

        $scope.$on('sowl.viewDocument', function() {
          $scope.init();
        });
    });
  }
);
