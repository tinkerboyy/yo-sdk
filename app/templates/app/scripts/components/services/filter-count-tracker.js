define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular, _, componentsModule) {
    /**
     * Keeps track of the number of results selecting a filter will show
     *
     * Uses set math. Keeps track of the items that are shown by each group of filter options
     * and the items shown by each individual filter and uses combination of set union/intersection
     * depending on whether its an AND/OR search and calculates the number of items to be
     * shown if a particular filter is selected.
     *
     * Each group can be set to search type of AND or OR. AND means the filtering
     * algorithm (defined by component that uses filter count tracker) will only
     * return items that match all filter options selected and OR means it will
     * match any items that have at least one filter option selected.
     *
     */
    var FilterCountUpdater = function() {
      this.reset();
		};

		FilterCountUpdater.SEARCH_TYPE_OR = 'OR';
		FilterCountUpdater.SEARCH_TYPE_AND = 'AND';

    FilterCountUpdater.prototype.reset = function() {
      this.filterGroups = {};
			this.itemSets = {
				alwaysShows: [],
				all: []
			};
			this.groupSets = {};
			this.filterOptions = {};
			this.filterCounts = {};
      this.enabled = true;
    };

		/**
		 * Initializes a filter group
		 *
		 * @param {string} groupId    Identifier for filter group
		 * @param {string} searchType AND/OR search
		 * @param {boolean} multiSelect Whether the filter is single or multi-select
		 * @param {function} customFilterSetFunc Function if set will override default functionality that creates set of documents that match selected filters
		 */
		FilterCountUpdater.prototype.addFilterGroup = function(groupId, multiSelect, searchType, overrides) {
			this.filterGroups[groupId] = {
				type: searchType,
				multiSelect: multiSelect,
				overrides: overrides
			};
      this.itemSets[groupId] = {};
		};

		FilterCountUpdater.prototype.addFilterOption = function(groupId, optionId) {
			if (_.isUndefined(this.filterOptions[groupId])) {
				this.filterOptions[groupId] = [];
			}
			this.filterOptions[groupId].push(optionId);
		};

    FilterCountUpdater.prototype.addAlwaysShownItem = function(itemId) {
      this.itemSets.alwaysShows.push(itemId);
    };

    FilterCountUpdater.prototype.removeAlwaysShownItem = function(itemId) {
      var itemIndex = this.itemSets.alwaysShows.indexOf(itemId);
      if (itemIndex > -1) {
        this.itemSets.alwaysShows.splice(itemIndex, 1);
      }
    };

		/**
		 * Add an item to be tracked by filter count update. Will associate the item with one or more filters.
		 *
		 * @param {string|int} itemId          Unique identifier for item
		 * @param {array} matchingFilters Array of filter IDs that this item is matched to
		 * @param {boolean} alwaysShows     If true then this item always showed regardless of what filters are currently selected
		 */
		FilterCountUpdater.prototype.addItem = function(itemId, matchingFilters, alwaysShows) {
			var self = this;

			if (alwaysShows) {
				this.itemSets.alwaysShows.push(itemId);
			}

			this.itemSets.all.push(itemId);

			//Go through matching filters and add this item ID to document set for each filter
			var filter,
        filters;
      for (var groupKey in matchingFilters) {
        filters = matchingFilters[groupKey];

        // _.forEach(matchingFilters, function(filters, groupKey) {
				if (_.isUndefined(self.itemSets[groupKey])) {
					self.itemSets[groupKey] = {};
				}

				for (var i = 0; i < filters.length; i++) {
					filter = filters[i];

					if (_.isUndefined(self.itemSets[groupKey][filter])) {
						self.itemSets[groupKey][filter] = [];
					}

					self.itemSets[groupKey][filter].push(itemId);
				}
			}
		};

		/**
		 * Updates the filter counts given the currently selected filters
		 *
		 * @param {object} selectedFilters Currently selected filters
		 */
		FilterCountUpdater.prototype.update = function(selectedFilters) {
      if (!this.enabled) return false;

			//First generate document sets for each filter group
			var self = this,
        filterGroup,
        groupKey;

			//Build document sets for each group
      for (groupKey in self.filterGroups) {
        if (!self.filterGroups.hasOwnProperty(groupKey)) continue;

        filterGroup = self.filterGroups[groupKey];
				if (!_.isUndefined(filterGroup.overrides) && !_.isUndefined(filterGroup.overrides.getItemsForSelectedFiltersInGroup)) {
					self.groupSets[groupKey] = filterGroup.overrides.getItemsForSelectedFiltersInGroup.apply(self, [groupKey, filterGroup, selectedFilters]);
				} else if (!filterGroup.multiSelect) {
					self.groupSets[groupKey] = self._buildGroupSetSingle(groupKey, filterGroup, selectedFilters);
				} else if (filterGroup.type === FilterCountUpdater.SEARCH_TYPE_OR) {
					self.groupSets[groupKey] = self._buildGroupSetForOr(groupKey, filterGroup, selectedFilters);
				} else if (filterGroup.type === FilterCountUpdater.SEARCH_TYPE_AND) {
					self.groupSets[groupKey] = self._buildGroupSetForAnd(groupKey, filterGroup, selectedFilters);
				}
			}

			//Now calculate the filter counts for each individual filter option within each group
			for (groupKey in self.filterGroups) {
        if (!self.filterGroups.hasOwnProperty(groupKey)) continue;

        filterGroup = self.filterGroups[groupKey];
				var intersectSets = self._getOtherGroupSets(groupKey),
						intersectCopy,
						i,
						filterOption,
						groupSet,
						selectedFilterKey = self._getSelectedFilterKey(groupKey);

				if (_.isUndefined(self.filterCounts[groupKey])) {
					self.filterCounts[groupKey] = {};
				}

				if (_.isArray(self.filterOptions[groupKey])) {
					for (i = 0; i < self.filterOptions[groupKey].length; i++) {
						filterOption = self.filterOptions[groupKey][i];
						intersectCopy = _.clone(intersectSets);

						if (!_.isUndefined(filterGroup.overrides) && !_.isUndefined(filterGroup.overrides.getItemsForFilter)) {
							intersectCopy.push(filterGroup.overrides.getItemsForFilter.apply(self, [groupKey, filterGroup, filterOption, selectedFilters]));
						} else if (!filterGroup.multiSelect) {
							intersectCopy.push(self.itemSets[groupKey][filterOption]);
						} else if (filterGroup.type === FilterCountUpdater.SEARCH_TYPE_OR) {
							groupSet = self.groupSets[groupKey];
							if (!_.isArray(selectedFilters[selectedFilterKey]) || selectedFilters[selectedFilterKey].length === 0) {
								groupSet = [];
							}

              intersectCopy.push(_.union(
								self.itemSets[groupKey][filterOption],
								groupSet
							));
						} else if (filterGroup.type === FilterCountUpdater.SEARCH_TYPE_AND) {
							groupSet = self.groupSets[groupKey];
							intersectCopy.push(self.itemSets[groupKey][filterOption]);
							intersectCopy.push(groupSet);
						}

						var filterOptionKey = self._getFilterOptionKey(groupKey, filterOption),
							matchingItems = _.intersection.apply(_, intersectCopy);
						if (_.isArray(self.itemSets.alwaysShows) && self.itemSets.alwaysShows.length > 0) {
							matchingItems = _.union(matchingItems, self.itemSets.alwaysShows);
						}
						self.filterCounts[groupKey][filterOptionKey] = matchingItems.length;
					}
				}
			}
		};

		/**
		 * Builds document set representing the current selected filter for a group that is set to single select
		 *
		 * @param  {string} groupKey        Identifier for group
		 * @param  {object} filterGroup     Filter group settings
		 * @param  {object} selectedFilters All selected filters
		 * @return {array}                 Set of all document ids matched selecting filters within group
		 */
		FilterCountUpdater.prototype._buildGroupSetSingle = function(groupKey, filterGroup, selectedFilters) {
			var selectedFilterKey = this._getSelectedFilterKey(groupKey);
			return this.itemSets[groupKey][selectedFilters[selectedFilterKey]];
		};

		/**
		 * Builds document set representing all currently selected filters within a particular group
		 * This is for a group that is defined as an OR search where it matches any document that has any one of the selected filters.
		 * If there are no filters selected that means we aren't filtering on anything in this group so return all documents
		 *
		 * @param  {string} groupKey        Identifier for group
		 * @param  {object} filterGroup     Filter group settings
		 * @param  {object} selectedFilters All selected filters
		 * @return {array}                 Set of all document ids matched selecting filters within group
		 */
		FilterCountUpdater.prototype._buildGroupSetForOr = function(groupKey, filterGroup, selectedFilters) {
			var selectedFilterKey = this._getSelectedFilterKey(groupKey);

			if (_.isArray(selectedFilters[selectedFilterKey]) && selectedFilters[selectedFilterKey].length > 0) {
				var setsToUnion = [];
				for (var i = 0; i < selectedFilters[selectedFilterKey].length; i++) {
					setsToUnion.push(this.itemSets[groupKey][selectedFilters[selectedFilterKey][i]]);
				}

				return _.union.apply(_, setsToUnion);
			}
			return this.itemSets.all;
		};

		FilterCountUpdater.prototype._buildGroupSetForAnd = function(groupKey, filterGroup, selectedFilters) {
			var selectedFilterKey = this._getSelectedFilterKey(groupKey);

			if (_.isArray(selectedFilters[selectedFilterKey]) && selectedFilters[selectedFilterKey].length > 0) {
				var setsToIntersect = [];
				for (var i = 0; i < selectedFilters[selectedFilterKey].length; i++) {
					setsToIntersect.push(this.itemSets[groupKey][selectedFilters[selectedFilterKey][i]]);
				}

				return _.intersection.apply(_, setsToIntersect);
			}
			return this.itemSets.all;
		};

		FilterCountUpdater.prototype._getOtherGroupSets = function(thisGroupKey) {
			var otherGroupSets = [],
				self = this,
        group, key;
      for (key in self.filterGroups) {
        if (!self.filterGroups.hasOwnProperty(key)) continue;

        group = self.filterGroups[key];
				if (key !== thisGroupKey) {
					otherGroupSets.push(self.groupSets[key]);
				}
			}
			return otherGroupSets;
		};

		FilterCountUpdater.prototype._getFilterOptionKey = function(groupKey, item) {
			if (!_.isUndefined(this.filterGroups[groupKey].overrides) && !_.isUndefined(this.filterGroups[groupKey].overrides.getFilterOptionKey)) {
				return this.filterGroups[groupKey].overrides.getFilterOptionKey(item);
			}
			return item;
		};

		FilterCountUpdater.prototype._getSelectedFilterKey = function(groupKey) {
			if (!_.isUndefined(this.filterGroups[groupKey].overrides) && !_.isUndefined(this.filterGroups[groupKey].overrides.selectedFilterKey)) {
				return this.filterGroups[groupKey].overrides.selectedFilterKey;
			}
			return groupKey;
		};

    componentsModule.factory('FilterCountTracker', function() {
        return new FilterCountUpdater();
      });
  }
);
