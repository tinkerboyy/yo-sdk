define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/applied-filters/applied-filters.html',
    'components/directives/accordion-select/accordion-select-directive'
    ],
    function(angular) {
      describe('Applied Filters Provider', function() {
        var $appliedFilters;

        beforeEach(module('gateways.components'));
        beforeEach(inject(function(_$appliedFilters_) {
          $appliedFilters = _$appliedFilters_;
        }));

        it('should allow you to specify new filter groups', function() {
          $appliedFilters.addFilterGroup('testGroup1', { multiple: false });
          $appliedFilters.addFilterGroup('testGroup2', { multiple: true });

          expect($appliedFilters.filterGroups).toEqual([
            {
              groupName: 'testGroup1',
              options: {
                multiple: false
              }
            },
            {
              groupName: 'testGroup2',
              options: {
                multiple: true
              }
            }
          ])
        });

        it('should allow you to add display names for filter options', function() {
            $appliedFilters.addFilterDisplayName('testGroup1', 'option1', 'Option #1');
            $appliedFilters.addFilterDisplayName('testGroup1', 'option2', 'Option #2');
            $appliedFilters.addFilterDisplayName('testGroup2', 'group2_option1', 'Group 2 - Option #1');

            expect($appliedFilters.filterDisplayNames).toEqual({
              'testGroup1': {
                'option1': 'Option #1',
                'option2': 'Option #2'
              },
              'testGroup2': {
                'group2_option1': 'Group 2 - Option #1'
              }
            });
        });
      });

      describe('Applied Filters', function() {
        var $scope = {},
          $httpBackend,
          $compile,
          $appliedFilters = {
            filterDisplayNames: {
              'group1': {
                'option1': 'Option 1'
              }
            },
            filterGroups: [
              {
                groupName: 'group1',
                options: {
                  multiple: true
                }
              }
            ]
          };

        beforeEach(module('gateways.components'));
        beforeEach(module('templates'));

        beforeEach(inject(function($rootScope, $controller, AGService, _$httpBackend_, _$compile_) {
          $httpBackend = _$httpBackend_;
          $scope = $rootScope.$new();
          $scope.appliedFilters = {};
          $compile = _$compile_;
          
          $httpBackend.when('GET', '/api/v1.0/preferences').respond({});

          $controller('AppliedFiltersController', {
            $scope: $scope,
            $appliedFilters: $appliedFilters
          });
        }));

        it('should compile the directive', function() {
          var element = angular.element('<div ag-applied-filters></div>');
          $compile(element)($scope);
          $scope.$digest();
          expect(element.attr('class')).toContain('ag-applied-filters');
        });

        it('should pass data from $appliedFilters to $scope', function() {
          expect($scope.filterDisplayNames).toEqual($appliedFilters.filterDisplayNames);
          expect($scope.filterGroups).toEqual($appliedFilters.filterGroups);
        });

        it('should remove filter option from applied filters for single select filter group', function() {
          $scope.appliedFilters = {
            dogBreed: 21,
            weightRange: ['40-60', '0-20']
          };

          $appliedFilters = {
            filterDisplayNames: {
              dogBreed: {
                21: 'Pit Bull'
              }
            },
            filterGroups: [
              {
                groupName: 'dogBreed',
                options: {
                  multiple: false
                }
              },
              {
                groupName: 'weightRange',
                options: {
                  multiple: true
                }
              }
            ]
          };

          var test = {
            dogBreed: null,
            weightRange: ['40-60', '0-20']
          };

          $scope.removeAppliedFilter($appliedFilters.filterGroups[0], 21);

          expect($scope.appliedFilters).toEqual(test);

        })

        it('should remove applied filter for multi-select filter group', function() {
          $scope.appliedFilters = {
            dogBreed: 21,
            weightRange: ['40-60', '0-20']
          };

          $appliedFilters = {
            filterDisplayNames: {
              dogBreed: {
                21: 'Pit Bull'
              }
            },
            filterGroups: [
              {
                groupName: 'dogBreed',
                options: {
                  multiple: false
                }
              },
              {
                groupName: 'weightRange',
                options: {
                  multiple: true
                }
              }
            ]
          };

          $scope.removeAppliedFilter($appliedFilters.filterGroups[1], '40-60');

          expect($scope.appliedFilters).toEqual({
            dogBreed: 21,
            weightRange: ['0-20']
          });

          $scope.removeAppliedFilter($appliedFilters.filterGroups[1], 'unknown');
        });

        it('should remove applied filter for group where filter values are objects', function() {
          $scope.appliedFilters = {
            planeType: [{
              id: 123,
              name: "It's My Aeroplane"
            }]
          };

          $appliedFilters = {
            filterDisplayNames: {
              planeType: {
                123: 'Aeroplane'
              }
            },
            filterGroups: [
              {
                groupName: 'planeType',
                options: {
                  multiple: true,
                  value_is_object: true
                }
              }
            ]
          };

          $scope.removeAppliedFilter($appliedFilters.filterGroups[0], { id: 123 });

          expect($scope.appliedFilters).toEqual({
            planeType: []
          });

          $scope.removeAppliedFilter($appliedFilters.filterGroups[0], { id: 'unknown' });
          expect($scope.appliedFilters).toEqual({
            planeType: []
          });
        });

        it('should call callback function provided', function() {
          $scope.removeFilterCallback = jasmine.createSpy();
          var test = { options: {} };
          $scope.removeAppliedFilter(test, 'b');
          expect($scope.removeFilterCallback).toHaveBeenCalledWith(test, 'b');

        });

        it('should see if update has applied filters', function() {
          $scope.updateHasAppliedFilters();
          expect($scope.hasAppliedFilters).toBe(false);

          $scope.appliedFilters = {
            planeType: null
          }
          $scope.updateHasAppliedFilters();
          expect($scope.hasAppliedFilters).toBe(false);

          $scope.appliedFilters = {
            planeType: {}
          }
          $scope.updateHasAppliedFilters();
          expect($scope.hasAppliedFilters).toBe(true);

          $scope.appliedFilters = {
            planeType: []
          }
          $scope.updateHasAppliedFilters();
          expect($scope.hasAppliedFilters).toBe(false);

          $scope.appliedFilters = {
            planeType: [1, 2, 3]
          }
          $scope.updateHasAppliedFilters();
          expect($scope.hasAppliedFilters).toBe(true);
        });

        it('should watch for changes to applied filters', function() {
          var watchSpy = spyOn($scope, 'updateHasAppliedFilters');
          $scope.appliedFilters = {
            planeType: [1, 2, 3]
          }
          $scope.$digest();
          
          expect(watchSpy).toHaveBeenCalled();
        });
      });
    }
)
