define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/accordion-select/accordion-select-directive'
    ],
    function(angular) {
      describe('Accordion Select Directive', function() {
        var target = {};
        var $scope = {};
        var $attrs = {};
        var changeSpy = jasmine.createSpy('changeSpy');

        beforeEach(module('gateways.components'));

        beforeEach(inject(function($rootScope, $controller, AGService) {
          $scope = $rootScope.$new();
          $scope = {
            collection: [
              { name: 'item 1', id: 1 },
              { name: 'item 2', id: 2 },
              { name: 'item 3', id: 3 },
              { name: 'item 4', id: 4 },
            ],
            targetField: 'test',
            valueField: 'id',
            target: target,
            displayTextField: 'name',
            change: changeSpy,
            orderBy: 'name'
          };

          $controller('AccordionSelectCtrl', {
            $scope: $scope,
            $attrs: $attrs
          });
        }));

        it('should select a single item in the list', function() {
          $scope.multiple = false;
          $scope.doSelect($scope.collection[0], 'id');
          expect($scope.selectedItems.length).toEqual(1);
          expect($scope.selectedItems[0]).toEqual($scope.collection[0]);
        });

        it('should unselect a selected item', function() {
          $scope.multiple = false;
          $scope.selectedItems = [$scope.collection[0]];
          $scope.doSelect($scope.collection[0], 'id');
          expect($scope.selectedItems.length).toEqual(0);
        });

        it('should select a different item in the list and unselect the currently selected item', function() {
          $scope.multiple = false;
          $scope.selectedItems = [$scope.collection[0]];
          $scope.doSelect($scope.collection[1], 'id');
          expect($scope.selectedItems.length).toEqual(1);
          expect($scope.selectedItems[0]).toEqual($scope.collection[1]);
        });

        it('should select multiple items in the list', function() {
          $attrs.multiple = true;
          $scope.selectedItems = [$scope.collection[0]];
          $scope.doSelect($scope.collection[1], 'id');
          expect($scope.selectedItems.length).toEqual(2);
        });

        it('should uncheck a checked item in multiple select mode', function() {
          $attrs.multiple = true;
          $scope.selectedItems = [$scope.collection[0], $scope.collection[1]];
          $scope.doSelect($scope.collection[1], 'id');
          expect($scope.selectedItems.length).toEqual(1);
        });

        it('should check the selected item in model is selected in target array', function() {
          
            $scope.targetField = 'test';
            $scope.target = {
              test: [$scope.collection[0], $scope.collection[1]]
            };

            $scope.checkSelected($scope.collection[0]);
            expect($scope.selectedItems.length).toEqual(1);
        });
      });
    }
)
