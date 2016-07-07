define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/services/filter-count-tracker'
  ],
  function() {
    describe('Filter Count Tracker', function() {
      var FilterCountTracker;

      beforeEach(module('gateways.components'));

      beforeEach(inject(function(_FilterCountTracker_) {
        FilterCountTracker = _FilterCountTracker_;
        FilterCountTracker.enabled = true;
      }));

      it('should show initial filter count', function() {
        FilterCountTracker.addFilterGroup('catType', true, 'OR');
        FilterCountTracker.addFilterGroup('fur', true, 'OR');

        FilterCountTracker.addFilterOption('catType', 'domestic');
        FilterCountTracker.addFilterOption('catType', 'exotic');

        FilterCountTracker.addFilterOption('fur', 'none');
        FilterCountTracker.addFilterOption('fur', 'shortfur');
        FilterCountTracker.addFilterOption('fur', 'longfur');

        FilterCountTracker.addItem('tabby', {catType: ['domestic'], fur: ['shortfur']});
        FilterCountTracker.addItem('calico', {catType: ['domestic'], fur: ['shortfur']});
        FilterCountTracker.addItem('siamese', {catType: ['domestic'], fur: ['shortfur']});
        FilterCountTracker.addItem('persian', {catType: ['domestic'], fur: ['longfur']});
        FilterCountTracker.addItem('sphinx', {catType: ['domestic', 'exotic'], fur: ['none']});

        FilterCountTracker.addItem('lion', {catType: ['exotic'], fur: ['shortfur']});
        FilterCountTracker.addItem('tiger', {catType: ['exotic'], fur: ['shortfur']});

        var expectedResults = {
          catType: {
            domestic: 5,
            exotic: 3
          },
          fur: {
            none: 1,
            shortfur: 5,
            longfur: 1
          }
        };
        FilterCountTracker.update({});

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults);
      });

      it('should update filter counts as you select filters', function() {
        FilterCountTracker.addFilterGroup('catType', true, 'OR');
        FilterCountTracker.addFilterGroup('fur', true, 'OR');

        FilterCountTracker.addFilterOption('catType', 'domestic');
        FilterCountTracker.addFilterOption('catType', 'exotic');

        FilterCountTracker.addFilterOption('fur', 'none');
        FilterCountTracker.addFilterOption('fur', 'shortfur');
        FilterCountTracker.addFilterOption('fur', 'longfur');

        FilterCountTracker.addItem('tabby', {catType: ['domestic'], fur: ['shortfur']});
        FilterCountTracker.addItem('calico', {catType: ['domestic'], fur: ['shortfur']});
        FilterCountTracker.addItem('siamese', {catType: ['domestic'], fur: ['shortfur']});
        FilterCountTracker.addItem('persian', {catType: ['domestic'], fur: ['longfur']});
        FilterCountTracker.addItem('sphinx', {catType: ['domestic', 'exotic'], fur: ['none']})

        FilterCountTracker.addItem('lion', {catType: ['exotic'], fur: ['shortfur']});
        FilterCountTracker.addItem('tiger', {catType: ['exotic'], fur: ['shortfur']});

        var expectedResults = {
          catType: {
            domestic: 5,
            exotic: 3
          },
          fur: {
            none: 1,
            shortfur: 5,
            longfur: 1
          }
        };

        FilterCountTracker.update({});

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults);

        FilterCountTracker.update({
          catType: ['domestic']
        });

        var expectedResults2 = {
          catType: {
            domestic: 5,
            exotic: 7
          },
          fur: {
            none: 1,
            shortfur: 3,
            longfur: 1
          }
        };

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults2);

        var expectedResults3 = {
          catType: {
            domestic: 3,
            exotic: 5
          },
          fur: {
            none: 4,
            shortfur: 3,
            longfur: 4
          }
        };

        FilterCountTracker.update({
          catType: ['domestic'],
          fur: ['shortfur']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults3);

        var expectedResults3 = {
          catType: {
            domestic: 5,
            exotic: 5
          },
          fur: {
            none: 6,
            shortfur: 5,
            longfur: 6
          }
        };

        FilterCountTracker.update({
          catType: ['domestic', 'exotic'],
          fur: ['shortfur']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults3);
      });

      it('should update filter counts as you select filters for AND groups', function() {
        FilterCountTracker.addFilterGroup('degreesOffered', true, 'AND');

        FilterCountTracker.addFilterOption('degreesOffered', '2-year');
        FilterCountTracker.addFilterOption('degreesOffered', '4-year');
        FilterCountTracker.addFilterOption('degreesOffered', 'masters');
        FilterCountTracker.addFilterOption('degreesOffered', 'doctorate');

        FilterCountTracker.addItem('PG Community College', {degreesOffered: ['2-year']});
        FilterCountTracker.addItem('UMD', {degreesOffered: ['4-year', 'masters', 'doctorate']});
        FilterCountTracker.addItem('Some Other College', {degreesOffered: ['4-year']});
        FilterCountTracker.addItem('Third College', {degreesOffered: ['4-year', 'masters']});
        FilterCountTracker.addItem('Graduate Student Only College', {degreesOffered: ['masters', 'doctorate']});

        var expectedResults = {
          degreesOffered: {
            '2-year': 1,
            '4-year': 3,
            'masters': 3,
            'doctorate': 2
          }
        };

        FilterCountTracker.update({});

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults);

        var expectedResults2 = {
          degreesOffered: {
            '2-year': 0,
            '4-year': 3,
            'masters': 2,
            'doctorate': 1
          }
        };

        FilterCountTracker.update({
          'degreesOffered': ['4-year']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults2);
      });

      it('should include results that are always shown regardless of filter selected in counts', function() {
        FilterCountTracker.addFilterGroup('degreesOffered', true, 'AND');

        FilterCountTracker.addFilterOption('degreesOffered', '2-year');
        FilterCountTracker.addFilterOption('degreesOffered', '4-year');
        FilterCountTracker.addFilterOption('degreesOffered', 'masters');
        FilterCountTracker.addFilterOption('degreesOffered', 'doctorate');

        FilterCountTracker.addItem('PG Community College', {degreesOffered: ['2-year']});
        FilterCountTracker.addItem('UMD', {degreesOffered: ['4-year', 'masters', 'doctorate']}, true);
        FilterCountTracker.addItem('Some Other College', {degreesOffered: ['4-year']});
        FilterCountTracker.addItem('Third College', {degreesOffered: ['2-year', '4-year', 'masters']});
        FilterCountTracker.addItem('Graduate Student Only College', {degreesOffered: ['masters', 'doctorate']});

        var expectedResults = {
          degreesOffered: {
            '2-year': 3,
            '4-year': 2,
            'masters': 2,
            'doctorate': 1
          }
        };

        FilterCountTracker.update({
          'degreesOffered': ['2-year']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults);
      });

      it('should use override functions to calculate group and item sets', function() {
        var overrides = {
          getFilterOptionKey: function() {},
          getItemsForSelectedFiltersInGroup: function() {},
          getItemsForFilter: function() {}
        },
        fakeGetFilterOptionKey = function(option) {
          var map = {
            'option1': 'key1',
            'option2': 'key2'
          };
          return map[option];
        },
        fakeGetItemsForSelectedFiltersInGroup = function() {
          return [1,3,4,5];
        },
        fakeGetItemsForFilter = function(group, groupDef, filterOption, selectedFilters) {
          if (filterOption === 'option1') {
            return [1,5];
          }
          return [3];
        };

        spyOn(overrides, 'getFilterOptionKey').and.callFake(fakeGetFilterOptionKey);
        spyOn(overrides, 'getItemsForSelectedFiltersInGroup').and.callFake(fakeGetItemsForSelectedFiltersInGroup);
        spyOn(overrides, 'getItemsForFilter').and.callFake(fakeGetItemsForFilter);

        FilterCountTracker.addFilterGroup('groupWithOverrides', false, 'AND', overrides);
        FilterCountTracker.addFilterOption('groupWithOverrides', 'option1');
        FilterCountTracker.addFilterOption('groupWithOverrides', 'option2');
        FilterCountTracker.addFilterGroup('otherGroup', true, 'OR');
        FilterCountTracker.addFilterOption('otherGroup', 'other1');
        FilterCountTracker.addFilterOption('otherGroup', 'other2');
        FilterCountTracker.addItem(1, {'groupWithOverrides': ['option1']});
        FilterCountTracker.addItem(2, {'otherGroup': ['other1']});
        FilterCountTracker.addItem(3, {'groupWithOverrides': ['option2']});
        FilterCountTracker.addItem(4, {'otherGroup': ['other2']});
        FilterCountTracker.addItem(5, {'groupWithOverrides': ['option1']});
        FilterCountTracker.addItem(6, {'otherGroup': ['other1']});

        var selectedFilters = {
          groupWithOverrides: ['option1']
        };
        FilterCountTracker.update(selectedFilters);

        expect(overrides.getItemsForSelectedFiltersInGroup).toHaveBeenCalledWith(
          'groupWithOverrides', jasmine.any(Object), selectedFilters
        );

        expect(overrides.getFilterOptionKey).toHaveBeenCalledWith('option1');
        expect(overrides.getFilterOptionKey).toHaveBeenCalledWith('option2');

        expect(overrides.getItemsForFilter).toHaveBeenCalledWith(
          'groupWithOverrides', jasmine.any(Object), 'option1', selectedFilters
        );
        expect(overrides.getItemsForFilter).toHaveBeenCalledWith(
          'groupWithOverrides', jasmine.any(Object), 'option2', selectedFilters
        );

        expect(FilterCountTracker.filterCounts.groupWithOverrides.key1).toEqual(2);
        expect(FilterCountTracker.filterCounts.groupWithOverrides.key2).toEqual(1);
      });

      it('should use override function get the key in selectedFilters to use for the group', function() {
        var overrides = {
          selectedFilterKey: 'otherFilterKey'
        };

        FilterCountTracker.addFilterGroup('groupWithOverrides', true, 'OR', overrides);
        FilterCountTracker.addFilterGroup('groupWithOverrides', true, 'OR', overrides);
        FilterCountTracker.addFilterOption('groupWithOverrides', 'option1');
        FilterCountTracker.addFilterOption('groupWithOverrides', 'option2');
        FilterCountTracker.addFilterGroup('otherGroup', true, 'OR');
        FilterCountTracker.addFilterOption('otherGroup', 'other1');
        FilterCountTracker.addFilterOption('otherGroup', 'other2');
        FilterCountTracker.addItem(1, {'groupWithOverrides': ['option1']});
        FilterCountTracker.addItem(2, {'otherGroup': ['other1']});
        FilterCountTracker.addItem(3, {'groupWithOverrides': ['option2']});
        FilterCountTracker.addItem(4, {'otherGroup': ['other2']});
        FilterCountTracker.addItem(5, {'groupWithOverrides': ['option1']});
        FilterCountTracker.addItem(6, {'otherGroup': ['other1']});

        FilterCountTracker.update({});
        expect(FilterCountTracker.filterCounts).toEqual({
          'groupWithOverrides': {
            'option1': 2,
            'option2': 1
          },
          'otherGroup': {
            'other1': 2,
            'other2': 1
          }
        });

        var selectedFilters = {
          'otherFilterKey': ['option1']
        };
        FilterCountTracker.update(selectedFilters);
        expect(FilterCountTracker.filterCounts).toEqual({
          'groupWithOverrides': {
            'option1': 2,
            'option2': 3
          },
          'otherGroup': {
            'other1': 0,
            'other2': 0
          }
        });
      });

      it('should allow you to add/remove always shown items', function() {
        FilterCountTracker.addFilterGroup('degreesOffered', true, 'AND');

        FilterCountTracker.addFilterOption('degreesOffered', '2-year');
        FilterCountTracker.addFilterOption('degreesOffered', '4-year');
        FilterCountTracker.addFilterOption('degreesOffered', 'masters');
        FilterCountTracker.addFilterOption('degreesOffered', 'doctorate');

        FilterCountTracker.addItem('PG Community College', {degreesOffered: ['2-year']});
        FilterCountTracker.addItem('UMD', {degreesOffered: ['4-year', 'masters', 'doctorate']}, true);
        FilterCountTracker.addItem('Some Other College', {degreesOffered: ['4-year']});
        FilterCountTracker.addItem('Third College', {degreesOffered: ['2-year', '4-year', 'masters']});
        FilterCountTracker.addItem('Graduate Student Only College', {degreesOffered: ['masters', 'doctorate']});

        var expectedResults = {
          degreesOffered: {
            '2-year': 3,
            '4-year': 2,
            'masters': 2,
            'doctorate': 1
          }
        },
        expectedResultsWithAddedAlwaysShown = {
          degreesOffered: {
            '2-year': 4,
            '4-year': 3,
            'masters': 3,
            'doctorate': 2
          }
        };

        FilterCountTracker.update({
          'degreesOffered': ['2-year']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults);

        FilterCountTracker.addAlwaysShownItem('Graduate Student Only College');
        FilterCountTracker.update({
          'degreesOffered': ['2-year']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResultsWithAddedAlwaysShown);

        FilterCountTracker.removeAlwaysShownItem('Graduate Student Only College');
        FilterCountTracker.update({
          'degreesOffered': ['2-year']
        });

        expect(FilterCountTracker.filterCounts).toEqual(expectedResults);
      });
    });
  }
);
