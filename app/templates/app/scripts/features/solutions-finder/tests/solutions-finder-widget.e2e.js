var SolutionsFinderWidget = (function () {

    var sfWidget = {};

    sfWidget.form = $('form.solutions-finder');
    sfWidget.titleBanner = sfWidget.form.$('h5.title-banner');
    sfWidget.inputGroups = sfWidget.form.$$('.form-group');

    sfWidget.getMyAgencyInputGroup = function() {
      return sfWidget.inputGroups.get(0);
    };

    sfWidget.getCategoryInputGroup = function() {
      return sfWidget.inputGroups.get(1);
    };

    sfWidget.getSubcategoryInputGroup = function() {
      return sfWidget.inputGroups.get(2);
    };

    sfWidget.getDropdownButton = function(inputGroup) {
      return inputGroup.$('.ag-smart-select button');
    };

    sfWidget.getDropdown = function(inputGroup) {
      return inputGroup.$('.ag-smart-select ul');
    };

    sfWidget.getOptionsForDropdown = function(inputGroup, includeParentItems) {
      var listItemSelector = includeParentItems ? 'li' : '[role=menuitem]',
        selector = '.ag-smart-select ul ' + listItemSelector;
      return inputGroup.$$(selector);
    };

    sfWidget.getSolutionCounter = function() {
      return this.form.$('.solutions-counter');
    };

    sfWidget.getResetButton = function() {
      return this.form.$('.counter button');
    };

    /**
     * Common logic to check a filter option and check that expected UI behavior happens
     *
     * @param  {ElementFinder} options           [description]
     * @param  {int} currentIndex      [description]
     * @param  {Function} checkResultsMatch [description]
     * @return {void}                   [description]
     */
    sfWidget.testFilterOption = function(inputGroup, options, currentIndex, params) {
      var self = this;
      if (typeof params === 'undefined') {
        params = {};
      }

      var option = options.get(currentIndex),
        filterCount,
        optionTitle,
        button = this.getDropdownButton(inputGroup);

      //Open dropdown to start test of option
      if (params.preTestActions) {
        params.preTestActions();
      }
      button.click();

      option.$('.filter-count').getText().then(function(filterCountText) {
        filterCount = filterCountText.length > 2 ? filterCountText.substring(1, filterCountText.length - 1) : '';
      });

      //Select should have the selected option displayed
      option.getText().then(function(title) {
        optionTitle = title;
      });

      option.click();

      //Option should show selected state
      if (params.singleSelect) {
        //We need to open dropdown again since it closed to check
        button.click();
      }
      expect(option.element(by.xpath('..')).getAttribute('class')).toContain('active');

      this.getDropdownButton(inputGroup).getText().then(function(selectedText) {
        expect(optionTitle).toContain(selectedText);
      });

      //Result count should equal the filter count
      sfWidget.getSolutionCounter().getText().then(function(solutionCountText) {
        expect(filterCount).toBe(solutionCountText);
      });

      //De-select option
      // option.click();
      sfWidget.getResetButton().click();

      //Re-open dropdown to check status of option item
      if (params.preTestActions) {
        params.preTestActions();
      }
      button.click();

      expect(option.element(by.xpath('..')).getAttribute('class')).not.toContain('active');

      //Close the dropdown to end test of option
      button.click();
      //Reset selected options again
      sfWidget.getResetButton().click();
    };

    return sfWidget;

})();

module.exports = SolutionsFinderWidget;
