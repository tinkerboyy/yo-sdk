define(
  [
    'components/components-module'
  ],
  function() {
    angular.module('gateways.components')
      .controller('AgPaginationCtrl', function($scope, $filter) {
        $scope.pageSizes = $scope.pageSizes || [10, 25, 50, 100];
      //  $scope.pageSize = $scope.pageSizes.length === 1 ? $scope.pageSizes[0] : 25;
        $scope.pageSize = $scope.pageSize || 25;
        $scope.offeringSize = 10; //maximum number of offerings per column
        $scope.currentPage = $scope.currentPage || 1;

        //Calculate pageCount based on page size
        var getPageCount = function(items, pageSize) {
          return items ? Math.ceil(items.length / pageSize) : 0;
        };

       //Calculate offeringlength based on offering size
        /*getOfferingLength = function(items, offeringSize) {
          var offeringLength = Math.ceil(items.length / offeringSize);
          return offeringLength;
        };
*/
        //Create a pages array
        $scope.setPages = function(pageCount) {
          var pages = [];
          for (var i = 1; i <= pageCount; i++) {
            pages.push(i);
          }

          $scope.pages = pages;
        };

        $scope.paginate = function(page) {
          if (page > $scope.pages.length || page < 1) {
            return;
          }

          var data = $scope.items;
          if ($scope.order) {
            data = $filter('orderBy')($scope.items, $scope.order);
          }

          $scope.currentPage = page;
          $scope.start = $scope.pageSize * (page - 1);
          $scope.end = ($scope.pageSize * page);
          var out = data.slice($scope.start, $scope.end);

          if ($scope.callback) {
            $scope.callback(out);
          }

          if ($scope.target) {
            $scope.target = out;
          }
          $scope.start++;
        };

        $scope.changeSize = function(size) {
          if ($scope.items) {
            $scope.count = $scope.items.length;
            $scope.pageSize = size;
            var pages = getPageCount($scope.items, size);
            $scope.setPages(pages);
            if (pages < $scope.currentPage && pages > 0) {
              $scope.currentPage = pages;
            }
            $scope.paginate($scope.currentPage);
          }
        };

        $scope.$watchGroup(['pageSize', 'currentPage'], function() {
          if ($scope.items) {
            $scope.setPages(getPageCount($scope.items, $scope.pageSize));
            $scope.paginate($scope.currentPage);
          }
        }, true);
      })
      .directive('agPagination', function() {
        return {
          restrict: 'AE',
          templateUrl: 'scripts/components/directives/pagination/pagination.html',
          controller: 'AgPaginationCtrl',
          replace: true,
          scope: {
            items: '=',
            target: '=',
            callback: '=',
            order: '@',
            pageSizes: '=?',
            pageSize: '=?',
            currentPage: '=?'
          },
          link: function(scope) {
            scope.$watch('items', function() {
              scope.changeSize(scope.pageSize);
            });
          }
        };

      });
  }

);
