describe('Statement of Work Library', function() {
  var element = browser.element;
  var page = {};
  page.viewAll = $('#sowl-view-all');
  page.reset = browser.element(by.id('reset-sowl'));
  page.results = element.all(by.repeater('result in pagedResults track by $index'));
  page.searchResults = page.results;
  page.labels = element.all(by.repeater('label in result.category_tags'));

  describe('Landing Page', function() {
    it('should display SOW results with all expected information', function() {
      browser.get('/app/#/sowl');
      expect(browser.getLocationAbsUrl()).toBe('/sowl/search');
      expect(page.searchResults.count()).toBeGreaterThan(0);
    });
  });

  describe('General Functionality', function() {
    it('should show the SOWL application header', function() {
      expect($('h1.ag-app-header').getText()).toEqual('STATEMENT OF WORK');
    });

  });

  describe('SOW details on Search Results Page', function(){
    it('should display Date Uploaded', function() {
    expect(page.results.count()).toBeGreaterThan(0);
    expect(page.results.get(0).$('span.date-uploaded').getText()).toEqual('Date Uploaded: 11/19/2014');
    });
  });

  describe('Pagination', function() {
    page.pagination = $$('.pagination').first();
    page.pageSizeContainer = browser.element(by.css('.page-size'));
    page.pageSizes = browser.element.all(by.repeater('size in pageSizes'));
    page.pages = browser.element.all(by.repeater('page in pages'));
    page.pageList = browser.element.all(by.css('li.views-row'));

    it('should have pagination', function() {
      expect(page.pagination.isDisplayed()).toBe(true);
    });

    it('should display 10 results', function() {
      page.pageSizes.get(0).$('a').click();
      expect(page.results.count()).toEqual(10);
    });

    it('should display 25 results', function() {
      page.pageSizes.get(1).$('a').click();
      expect(page.results.count()).not.toBeGreaterThan(25);
    });

    it('should display 50 results', function() {
      page.pageSizes.get(2).$('a').click();
      expect(page.results.count()).not.toBeGreaterThan(50);
    });

    it('should display 100 results', function() {
      page.pageSizes.get(3).$('a').click();
      //expect(page.results.count()).toBeGreaterThan(50);
      expect(page.results.count()).not.toBeGreaterThan(100);
    });

    it('should toggle pages', function() {
      page.pages.count().then(function(count) {
      var pageNum;
        for (var i = 0; i < count; i++) {
          pageNum = page.pages.get(i);
          pageNum.$('a').click();
          pageNum.$('a').getText().then(function(text) {
          //  expect(text).toEqual(text);
          });
        }
      });
    });


    // it('should toggle page size', function() {
    //   expect(page.pageSizes.count()).toBeGreaterThan(0);
    //   var size;
    //   page.pageSizes.count().then(function(count) {
    //     for (var i = 0; i < count; i++) {
    //       size = page.pageSizes.get(i);
    //       size.$('a').click();
    //       size.$('a').getText().then(function(text) {
    //         expect(page.resuts.count()).toEqual(parseInt(text));
    //       });
    //     }
    //   });
    // });
   });

  describe('Welcome Message', function() {
    it('should display a welcome message', function() {
      expect($('#sowl-welcome').isDisplayed()).toBe(true);
    });

    it('should close the welcome message', function() {
      $('#sowl-clear-welcome').click();
      expect($('#sowl-welcome').isPresent()).toBe(false);
      expect($('#sowl-show-welcome').isPresent()).toBe(true);
    });

    it('should remember to not show the message if messgae is closed', function() {
      browser.get('/app/#/sowl');
      expect($('#sowl-welcome').isPresent()).toBe(false);
    });

    it('should reshow the welcome message', function() {
      $('#sowl-show-welcome').click();
      expect($('#sowl-welcome').isDisplayed()).toBe(true);
    });

    it('should remember to always show the message if message is left visible', function() {
      browser.get('/app/#/sowl/search');
      expect($('#sowl-welcome').isDisplayed()).toBe(true);
    });
  });

  describe('Filters', function() {
    page.accFilters = element.all(by.css('div.accordion-select'));
    page.filters = browser.element(by.css('.sowl-filters'));
    page.mainTitle = browser.element(by.css('.sowl-filters h4'));
    page.filterTitle = browser.element.all(by.css('.accordion-select-title a'));
    page.filterOptions = browser.element.all(by.css('ul.accordion-select-options li'));
    page.search = browser.element(by.model('moreSearch.search'));
    page.filters = browser.element.all(by.css('div.accordion-select'));

    it('should have all filters present', function() {
      expect(page.filters.count()).toEqual(6);
      expect(page.filters.get(0).$('.accordion-select-title').getText()).toEqual('Category');
      expect(page.filters.get(1).$('.accordion-select-title').getText()).toContain('Subcategory');
      expect(page.filters.get(2).$('.accordion-select-title').getText()).toEqual('Work Statement Type');
      expect(page.filters.get(3).$('.accordion-select-title').getText()).toEqual('Related Solutions');
      expect(page.filters.get(4).$('.accordion-select-title').getText()).toEqual('Contract Format');
      expect(page.filters.get(5).$('.accordion-select-title').getText()).toContain('Additional Options');
    });

    it('should expand and collapse all filters', function() {
      for(var i = 0; i < 5; i++) {
        //Filters are all closed
        var displayState = true;

        //Skip over subcategory bc it's disabled by default
        if (i !== 1) {
          page.filters.get(i).$('.accordion-select-title > a').click();
          expect(page.filters.get(i).$('.accordion-select-options').isDisplayed()).toBe(displayState);

          page.filters.get(i).$('.accordion-select-title > a').click();
          expect(page.filters.get(i).$('.accordion-select-options').isDisplayed()).toBe(!displayState);
        }
      }
    });

    var cHeight;
    it('should resize the Category filter', function() {
      page.filters.get(0).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(0).$('div.ui-resizable-s');
      page.filters.get(0).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseDown()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseMove(dragHandle, { x: 0, y: -100 })
          .mouseUp()
          .perform();

        page.filters.get(0).$('div.ui-resizable').getCssValue('height').then(function(h) {
          cHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).not.toBeGreaterThan(height);
        });
      });
    });

    it('should remember resize of the Category filter', function() {
      browser.refresh();
      expect(page.filters.get(0).$('div.ui-resizable').getCssValue('height')).toEqual(cHeight);
    });

    it('should remember collapsed state of the Category filter', function() {
      page.filters.get(0).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Category filter', function() {
      page.filters.get(0).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(0).$('.accordion-select-title > a').click();
    });

    var wHeight;
    it('should resize the Work Statement Type filter', function() {
      page.filters.get(2).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(2).$('div.ui-resizable-s');
      page.filters.get(2).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseDown()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseMove(dragHandle, { x: 0, y: -100 })
          .mouseUp()
          .perform();

        page.filters.get(2).$('div.ui-resizable').getCssValue('height').then(function(h) {
          wHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).not.toBeGreaterThan(height);
        });
      });
    });

    it('should remember resize of the Work Statement Type filter', function() {
      browser.refresh();
      expect(page.filters.get(2).$('div.ui-resizable').getCssValue('height')).toEqual(wHeight);
    });

    it('should remember collapsed state of the Work Statement Type filter', function() {
      page.filters.get(2).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(2).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Work Statement Type filter', function() {
      page.filters.get(2).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(2).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(2).$('.accordion-select-title > a').click();
    });

    var rHeight;
    it('should resize the Related Solutions filter', function() {
      page.filters.get(3).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(3).$('div.ui-resizable-s');
      page.filters.get(3).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseDown()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseMove(dragHandle, { x: 0, y: -100 })
          .mouseUp()
          .perform();

        page.filters.get(3).$('div.ui-resizable').getCssValue('height').then(function(h) {
          rHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).not.toBeGreaterThan(height);
        });
      });
    });

    it('should remember resize of the Related Solutions filter', function() {
      browser.refresh();
      expect(page.filters.get(3).$('div.ui-resizable').getCssValue('height')).toEqual(rHeight);
    });

    it('should remember collapsed state of the Related Solutions filter', function() {
      page.filters.get(3).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(3).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Related Solutions filter', function() {
      page.filters.get(3).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(3).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(3).$('.accordion-select-title > a').click();
    });

    var cfHeight;
    it('should resize the Contract Format filter', function() {
      page.filters.get(4).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(4).$('div.ui-resizable-s');
      page.filters.get(4).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseDown()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseMove(dragHandle, { x: 0, y: -100 })
          .mouseUp()
          .perform();

        page.filters.get(4).$('div.ui-resizable').getCssValue('height').then(function(h) {
          cfHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).not.toBeGreaterThan(height);
        });
      });
    });

    it('should remember resize of the Contract Format filter', function() {
      browser.refresh();
      expect(page.filters.get(4).$('div.ui-resizable').getCssValue('height')).toEqual(cfHeight);
    });

    it('should remember collapsed state of the Contract Format filter', function() {
      page.filters.get(4).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(4).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Contract Format filter', function() {
      page.filters.get(4).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(4).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(4).$('.accordion-select-title > a').click();
    });

    var aHeight;
    it('should resize the Additional Options filter', function() {
      page.filters.get(5).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(5).$('div.ui-resizable-s');
      page.filters.get(5).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseDown()
          .mouseMove(dragHandle, { x: 0, y: 0 })
          .mouseMove(dragHandle, { x: 0, y: -100 })
          .mouseUp()
          .perform();

        page.filters.get(5).$('div.ui-resizable').getCssValue('height').then(function(h) {
          aHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).not.toBeGreaterThan(height);
        });
      });
    });

    it('should remember resize of the Additional Options filter', function() {
      browser.refresh();
      expect(page.filters.get(5).$('div.ui-resizable').getCssValue('height')).toEqual(aHeight);
    });

    it('should remember collapsed state of the Additional Options filter', function() {
      page.filters.get(5).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(5).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Additional Options filter', function() {
      page.filters.get(5).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(5).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(5).$('.accordion-select-title > a').click();
    });

    it('should search by Category', function() {

      expect(page.mainTitle.getText()).toEqual('Filter By');
      expect(page.accFilters.get(0).$('.accordion-select-title a').getText()).toEqual('Category');
      expect(browser.getLocationAbsUrl()).toEqual('/sowl/search');

      page.accFilters.get(0).$('.accordion-select-title a').click();
      expect($('.accordion-select-options').isPresent()).toBe(true);

      for(var i=0; i < page.filterOptions; i++) {
        var link = get(i);
        if (link === 0) {
          link.click();
          expect(browser.getLocationAbsUrl()).toEqual('/sowl/search?categories=91');
        }
        link.click();getAttr
      }
      page.accFilters.get(0).$('.accordion-select-title a').click();
    });

    it('should search by work statement type', function() {
      expect(page.accFilters.get(2).$('.accordion-select-title a').getText()).toEqual('Work Statement Type');
      expect(browser.getLocationAbsUrl()).toEqual('/sowl/search');

      page.accFilters.get(2).$('.accordion-select-title a').click();
      expect($('.accordion-select-options').isPresent()).toBe(true);
      for(var i=0; i < page.filterOptions; i++) {
        var link = get(i);
        var attr = link.getAttribute('dataItemId');
        if (link === 0) {
          link.click();
          expect(browser.getLocationAbsUrl()).toEqual('/sowl/search?workStatementType=PWS');
          link.click();
        }
      }
      page.accFilters.get(2).$('.accordion-select-title a').click();
    });

    it('should search by Related Solutions', function() {
      expect(page.accFilters.get(3).$('.accordion-select-title a').getText()).toEqual('Related Solutions');
      expect(browser.getLocationAbsUrl()).toEqual('/sowl/search');

      page.accFilters.get(3).$('.accordion-select-title a').click();
      expect($('.accordion-select-options').isPresent()).toBe(true);
      for(var i=0; i < page.filterOptions; i++) {
        var link = get(i);
        var attr = link.getAttribute('dataItemId');
        if (link === 0) {
          link.click();
          expect(browser.getLocationAbsUrl()).toEqual('/sowl/search?relatedSolutions=164');
          link.click();
        }
      }
      page.accFilters.get(3).$('.accordion-select-title a').click();
    });

    it('should search by Contract Format', function() {
      expect(page.accFilters.get(4).$('.accordion-select-title a').getText()).toEqual('Contract Format');
      expect(browser.getLocationAbsUrl()).toEqual('/sowl/search');

      page.accFilters.get(4).$('.accordion-select-title a').click();
      expect($('.accordion-select-options').isPresent()).toBe(true);
      for(var i=0; i < page.filterOptions; i++) {
        var link = get(i);
        var attr = link.getAttribute('dataItemId');
        if (link === 0) {
          link.click();
          expect(browser.getLocationAbsUrl()).toEqual('/sowl/search?contractFormats=GWAC');
          link.click();
        }
      }
      page.accFilters.get(4).$('.accordion-select-title a').click();

    });

    it('should search by Additional Options', function() {
      expect(page.accFilters.get(5).$('.accordion-select-title a').getText()).toEqual('Additional Options');
      expect(browser.getLocationAbsUrl()).toEqual('/sowl/search');

      page.accFilters.get(5).$('.accordion-select-title a').click();
      expect($('.accordion-select-options').isPresent()).toBe(true);
      for(var i=0; i < page.filterOptions; i++) {
        var link = get(i);
        var attr = link.getAttribute('dataItemId');
        if (link === 0) {
          link.click();
          expect(browser.getLocationAbsUrl()).toEqual('/sowl/search?additionalOptions=SAMPLE');
          link.click();
        }
      }
      page.accFilters.get(5).$('.accordion-select-title a').click();
    });

    it('should have the input search present', function() {
      expect(page.search.isPresent()).toBe(true);
    });

    it('should return the typeahead results in the dropdown when I type', function() {
      page.search.sendKeys('tech');
      expect($('ul.typeahead').isPresent()).toBe(true);

      var typeaheadItems = $$('ul.typeahead li');
      typeaheadItems.count().then(function(count) {
        expect(count > 0).toBe(true);
        for (var i = 0; i < count; i++) {
          expect(typeaheadItems.get(i).getText()).toContain('tech');
        }
      });
    });

    it('should not have duplicate labels in the SOW results', function() {
     // page.search.sendKeys('agile');

        function isUnique(arr) {
           var map = {}, i;
           arr.each(function(arrlabel, index) {
            arrlabel.$('.catBut-title').getText().then(function(label) {
              if (map[label]) {
                return false;
              }
              map[label] = true;
            });
          });

            return true;
          }

        // if count is greated than 10 results 
        page.results.count().then(function(count) {
          if (count > 10) {
            for(var i = 0; i < 10; i++) {
              expect(isUnique(page.results.get(i).all(by.repeater('label in result.category.und')))).toBe(true);
            }
          }
        });
        
    });

    it('should not show typeahead results if I type something that does not have results', function() {
      page.search.sendKeys('somethingWithoutTypeaheadResults');

      var typeaheadItems = $$('ul.typeahead li');
      typeaheadItems.count().then(function(count) {
        expect(count).toBe(0);
      });
    });

    it('should show all search results when I click Reset', function() {
      browser.get('/app/#/sowl/search?categories=91');
      page.reset.click();
      expect(browser.getLocationAbsUrl()).toEqual('/sowl/search');

      //Verify that the result count is present and greater than 0
      $('.result-count span.label').getText().then(function(resultCountText) {
        var resultCount = parseInt(resultCountText, 10);
        if (isNaN(resultCount)) {
          resultCount = 0;
        }

        since('Result count should be greater than 0')
          .expect(resultCount).toBeGreaterThan(0);
      });

      //Verify that the header is present
      expect($('.search-results-container h2').getText()).toBe('Search Results');

      //Verify that we have results on the page
      expect(page.searchResults.count()).toBeGreaterThan(0);
    });

    it('it should show Tutorial block', function() {
      var tutorialPanel = $('#sowl-left-rail .sow-tutorial-panel');
      expect(tutorialPanel.isDisplayed()).toBe(true);
      expect(tutorialPanel.$('h3').isDisplayed()).toBe(true);
      expect(tutorialPanel.$('h3').getText()).toBe('Want to understand how the SOW Library works and what you will find here?');
      expect(tutorialPanel.$('p').isDisplayed()).toBe(true);
      expect(tutorialPanel.$('p').getText()).toBe('Click below for an overview.');
      expect(tutorialPanel.$('a.sow-contrib-button').isDisplayed()).toBe(true);
      expect(tutorialPanel.$('a.sow-contrib-button').getText()).toBe('Take me to the tutorial');
    });

    if (!browser.params.publicUser) {
      it('it should show Submit Your SOW block', function() {
        var submitPanel = $('#sowl-left-rail .sow-submit-panel');
        expect(submitPanel.isDisplayed()).toBe(true);
        expect(submitPanel.$('h3').isDisplayed()).toBe(true);
        expect(submitPanel.$('h3').getText()).toBe('Have a Statement of Work that you would like to add to the archive and share?');
        expect(submitPanel.$('p').isDisplayed()).toBe(true);
        expect(submitPanel.$('p').getText()).toBe('Click below to upload your SOW.');
        expect(submitPanel.$('a.sow-contrib-button').isDisplayed()).toBe(true);
        expect(submitPanel.$('a.sow-contrib-button').getText()).toBe('Submit your SOWs here');
      });
    }

    it('it should show Contact Us blocks', function() {
      var contactPanel = $('#sowl-left-rail .sow-contact-panel');
      expect(contactPanel.isDisplayed()).toBe(true);
      expect(contactPanel.$('h3').isDisplayed()).toBe(true);
      expect(contactPanel.$('h3').getText()).toBe('Have some ideas for improvements?');
      expect(contactPanel.$('p').isDisplayed()).toBe(true);
      expect(contactPanel.$('p').getText()).toBe('Click below to send us an email letting us know what you think or ways we can improve.');
      expect(contactPanel.$('a.sow-contrib-button').isDisplayed()).toBe(true);
      expect(contactPanel.$('a.sow-contrib-button').getText()).toBe('Contact Us');
    });
  });

  describe('Sorting', function() {
    page.sort = $('a.sort-toggle');
    page.sortMenu = $('ul.sowl-search-sort-options');
    page.sortOptions = page.sortMenu.$$('li a');

    page.getItemTitle = function(item) {
      return item.$('div.sowTitle').getText();
    };

    page.getItemViewCount = function(item) {
      return item.element(by.binding('result.views')).getText();
    };

    page.getCountNumber = function(countText) {
      var count = countText.split(':').pop().trim();
      count = parseInt(count, 10);
      return isNaN(count) ? 0 : count;
    };

    page.getItemDownloadCount = function(item) {
      return item.element(by.binding('result.downloads')).getText();
    };

    page.getItemVoteCount = function(item) {
      return item.$('.vote-up-down-widget').element(by.binding('item.votes || 0 | number')).getText();
    };

    it('should display the sorting directive', function() {
      browser.get('/app/#/sowl/search');
      expect(page.sort.isDisplayed()).toBe(true);
    });

    it('should show sorting options', function() {
      page.sort.click();
      expect(page.sortMenu.isDisplayed()).toBe(true);
      if (browser.params.publicUser) {
        expect(page.sortOptions.count()).toBe(6);
      } else {
        expect(page.sortOptions.count()).toBe(7);
      }
      expect(page.sortOptions.get(0).$('span.fa-check').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(0).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(0).getText()).toEqual('Relevance');
      expect(page.sortOptions.get(1).getText()).toEqual('Alphabetically');
      expect(page.sortOptions.get(2).getText()).toEqual('Date Uploaded');
      expect(page.sortOptions.get(3).getText()).toEqual('View Count');
      expect(page.sortOptions.get(4).getText()).toEqual('Download Count');
      expect(page.sortOptions.get(5).getText()).toEqual('Downloads to View Ratio');
      if (!browser.params.publicUser) {
        expect(page.sortOptions.get(6).getText()).toEqual('Vote Count');
      }
      page.sort.click();
    });

    it('should sort by Alphabetically ascending', function() {
      page.sort.click();
      page.sortOptions.get(1).click();
      page.sort.click();
      expect(page.sortOptions.get(1).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(1).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            if (!firstItem) {
              since('"' + itemTitle + '"  should not appear after "' + prevTitle + '"')
                .expect(itemTitle.toLowerCase() >= prevTitle.toLowerCase()).toBe(true);
            }

            prevTitle = itemTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Alphabetically descending', function() {
      page.sort.click();
      page.sortOptions.get(1).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      expect(page.sortOptions.get(1).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(1).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            if (!firstItem) {
              since('"' + itemTitle + '"  should not appear after "' + prevTitle + '"')
                .expect(itemTitle.toLowerCase() <= prevTitle.toLowerCase()).toBe(true);
            }

            prevTitle = itemTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Date Uploaded descending', function() {
      page.sort.click();
      page.sortOptions.get(2).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      expect(page.sortOptions.get(2).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(2).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevViewCount = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          page.getItemViewCount(item).then(function(viewCountText) {
            var viewCount = page.getCountNumber(viewCountText);

            if (!firstItem) {
              since('"' + currentTitle + '" with view count (' + viewCount + ') should not appear after "' + prevTitle + '" with view count (' + prevViewCount + ')')
                .expect(viewCount <= prevViewCount).toBe(true);
            }

            prevViewCount = viewCount;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Date Uploaded ascending', function() {
      page.sort.click();
      page.sortOptions.get(2).click();
      page.sort.click();
      expect(page.sortOptions.get(2).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(2).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevViewCount = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          page.getItemViewCount(item).then(function(viewCountText) {
            var viewCount = page.getCountNumber(viewCountText);

            if (!firstItem) {
              since('"' + currentTitle + '" with view count (' + viewCount + ') should not appear after "' + prevTitle + '" with view count (' + prevViewCount + ')')
                .expect(viewCount >= prevViewCount).toBe(true);
            }

            prevViewCount = viewCount;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by View Count descending', function() {
      page.sort.click();
      page.sortOptions.get(3).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      expect(page.sortOptions.get(3).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(3).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevViewCount = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          page.getItemViewCount(item).then(function(viewCountText) {
            var viewCount = page.getCountNumber(viewCountText);

            if (!firstItem) {
              since('"' + currentTitle + '" with view count (' + viewCount + ') should not appear after "' + prevTitle + '" with view count (' + prevViewCount + ')')
                .expect(viewCount <= prevViewCount).toBe(true);
            }

            prevViewCount = viewCount;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by View Count ascending', function() {
      page.sort.click();
      page.sortOptions.get(3).click();
      page.sort.click();
      expect(page.sortOptions.get(3).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(3).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevViewCount = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          page.getItemViewCount(item).then(function(viewCountText) {
            var viewCount = page.getCountNumber(viewCountText);

            if (!firstItem) {
              since('"' + currentTitle + '" with view count (' + viewCount + ') should not appear after "' + prevTitle + '" with view count (' + prevViewCount + ')')
                .expect(viewCount >= prevViewCount).toBe(true);
            }

            prevViewCount = viewCount;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Download Count descending', function() {
      page.sort.click();
      page.sortOptions.get(4).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      expect(page.sortOptions.get(4).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(4).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevDownloadCount = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          page.getItemDownloadCount(item).then(function(downloadCountText) {
            var downloadCount = page.getCountNumber(downloadCountText);

            if (!firstItem) {
              since('"' + currentTitle + '" with download count (' + downloadCount + ') should not appear after "' + prevTitle + '" with download count (' + prevDownloadCount + ')')
                .expect(downloadCount <= prevDownloadCount).toBe(true);
            }

            prevDownloadCount = downloadCount;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Download Count ascending', function() {
      page.sort.click();
      page.sortOptions.get(4).click();
      page.sort.click();
      expect(page.sortOptions.get(4).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(4).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevDownloadCount = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          page.getItemDownloadCount(item).then(function(downloadCountText) {
            var downloadCount = page.getCountNumber(downloadCountText);

            if (!firstItem) {
              since('"' + currentTitle + '" with download count (' + downloadCount + ') should not appear after "' + prevTitle + '" with download count of (' + prevDownloadCount + ')')
                .expect(downloadCount >= prevDownloadCount).toBe(true);
            }

            prevDownloadCount = downloadCount;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Download to View Ratio descending', function() {
      page.sort.click();
      page.sortOptions.get(5).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      expect(page.sortOptions.get(5).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(5).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevDownloadViewRatio = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          protractor.promise.all([
            page.getItemDownloadCount(item),
            page.getItemViewCount(item)
          ]).then(function(counts) {
            var downloadCount = page.getCountNumber(counts[0]),
              viewCount = page.getCountNumber(counts[1]),
              downloadViewRatio = viewCount === 0 ? 0 : downloadCount / viewCount;

            if (!firstItem) {
              since('"' + currentTitle + '" with download/view ratio of (' + downloadViewRatio + ') should appear after "' + prevTitle + '" with download count of (' + prevDownloadViewRatio + ')')
                .expect(downloadViewRatio <= prevDownloadViewRatio).toBe(true);
            }

            prevDownloadViewRatio = downloadViewRatio;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    it('should sort by Download to View Ratio ascending', function() {
      page.sort.click();
      page.sortOptions.get(5).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      expect(page.sortOptions.get(5).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(5).$('span.fa-check').isDisplayed()).toBe(true);
      page.sort.click();

      page.results.count().then(function(count) {
        var prevDownloadViewRatio = null,
          prevTitle,
          currentTitle,
          firstItem = true;

        for (var i = 0; i < count; i++) {
          var item = page.results.get(i);

          page.getItemTitle(item).then(function(itemTitle) {
            currentTitle = itemTitle;
          });

          protractor.promise.all([
            page.getItemDownloadCount(item),
            page.getItemViewCount(item)
          ]).then(function(counts) {
            var downloadCount = page.getCountNumber(counts[0]),
              viewCount = page.getCountNumber(counts[1]),
              downloadViewRatio = viewCount === 0 ? 0 : downloadCount / viewCount;

            if (!firstItem) {
              since('"' + currentTitle + '" with download/view ratio of (' + downloadViewRatio + ') should appear before "' + prevTitle + '" with download count of (' + prevDownloadViewRatio + ')')
                .expect(downloadViewRatio >= prevDownloadViewRatio).toBe(true);
            }

            prevDownloadViewRatio = downloadViewRatio;
            prevTitle = currentTitle;
            firstItem = false;
          });
        }
      });
    });

    if (!browser.params.publicUser) {
      it('should sort by Vote Count descending', function() {
        page.sort.click();
        page.sortOptions.get(6).click();
        expect(page.sortMenu.isPresent()).toBe(false);
        page.sort.click();
        expect(page.sortOptions.get(6).$('span.fa-arrow-down').isDisplayed()).toBe(true);
        expect(page.sortOptions.get(6).$('span.fa-check').isDisplayed()).toBe(true);
        page.sort.click();

        page.results.count().then(function(count) {
          var prevVoteCount = null,
            prevTitle,
            currentTitle,
            firstItem = true;

          for (var i = 0; i < count; i++) {
            var item = page.results.get(i);

            page.getItemTitle(item).then(function(itemTitle) {
              currentTitle = itemTitle;
            });

            page.getItemVoteCount(item).then(function(voteCountText) {
              var voteCount = page.getCountNumber(voteCountText);

              if (!firstItem) {
                since('"' + currentTitle + '" with vote count (' + prevVoteCount + ') should not appear after "' + prevTitle + '" with vote count (' + prevVoteCount + ')')
                  .expect(voteCount <= prevVoteCount).toBe(true);
              }

              prevVoteCount = voteCount;
              prevTitle = currentTitle;
              firstItem = false;
            });
          }
        });
      });

      it('should sort by Vote Count ascending', function() {
        page.sort.click();
        page.sortOptions.get(6).click();
        page.sort.click();
        expect(page.sortOptions.get(6).$('span.fa-arrow-up').isDisplayed()).toBe(true);
        expect(page.sortOptions.get(6).$('span.fa-check').isDisplayed()).toBe(true);
        page.sort.click();

        page.results.count().then(function(count) {
          var prevVoteCount = null,
            prevTitle,
            currentTitle,
            firstItem = true;

          for (var i = 0; i < count; i++) {
            var item = page.results.get(i);

            page.getItemTitle(item).then(function(itemTitle) {
              currentTitle = itemTitle;
            });

            page.getItemVoteCount(item).then(function(voteCountText) {
              var voteCount = page.getCountNumber(voteCountText);

              if (!firstItem) {
                since('"' + currentTitle + '" with download count (' + voteCount + ') should not appear after "' + prevTitle + '" with download count of (' + prevVoteCount + ')')
                  .expect(voteCount >= prevVoteCount).toBe(true);
              }

              prevVoteCount = voteCount;
              prevTitle = currentTitle;
              firstItem = false;
            });
          }
        });
      });
    }
  });

  describe('Sharing', function() {
    page.share = $('.ag-share > a');
    var searchUrl;

    it('should open the share dialog', function() {
      browser.get('/app/#/sowl');
      page.share.click();
      expect($('#share-popover').isPresent()).toBe(true);
      expect($('#share-popover').isDisplayed()).toBe(true);
    });

    it('should close the share dialog', function() {
      $('#share-popover button.close').click();
      expect($('#share-popover').isPresent()).toBe(false);
      expect($('#share-popover').isPresent()).toBe(false);
    });

    it('should open the \'Add to Project\' Dialog', function() {
      page.share.click();
      page.search.sendKeys('test');
      searchUrl = browser.getLocationAbsUrl();
      $('#share-add-to-project').click();
      expect($('div.add-to-project').isDisplayed()).toEqual(true);
      expect($('#share-popover').isPresent()).toBe(false);
    });

    it('should create a new project', function() {
      var projects = browser.element.all(by.repeater('project in projects | filter: { status: \'1\' }'));
      projects.count().then(function(count) {
        $('.btn-new-entity').click();
        expect($('div.my-projects div.popover').isDisplayed()).toBe(true);

        element(by.model('project.name')).sendKeys('E2E: Test Project');
        $('div.my-projects div.popover button[type="submit"]').click();

        expect($('div.my-projects div.popover').isPresent()).toBe(false);
        expect(projects.count()).toEqual(count + 1);
      });
    });

    it('should validate \'Add to project\' fields and submit search to project', function() {
      var name = browser.element(by.model('item.name'));
      var projects = browser.element.all(by.repeater("project in projects | filter: { status: '1' }"));
      expect(name.isPresent()).toBe(true);

      //Expect the submit button to be sdisabled
      expect($('#add-to-project-submit').getAttribute('disabled')).toEqual('true');

      name.sendKeys('E2E: Test Solution Search');
      expect($('#add-to-project-submit').getAttribute('disabled')).toEqual('true');

      projects.last().$('a').click();
      expect($('#add-to-project-submit').getAttribute('disabled')).toEqual(null);

      $('#add-to-project-submit').click();
      //expect($('div.add-success').isDisplayed()).toEqual(true);
      //expect($('div.add-success').getText()).toEqual('Your Solutions Finder Search was successfully added' );
      //expect($('div.add-success i.fa-check-circle').isDisplayed()).toBe(true);
    });

    it('should show the new search in the Project Center', function() {
      browser.get('/app/#/');
      page.projects = browser.element.all(by.repeater("projectEntity in projects.data.collection | filter: { status: '1' } | orderBy: '-created'"));
      var project = page.projects.first();
      var items = project.all(by.repeater("projectContent in projectEntities.data.collection | myProjectContentFilter: { status: '1', pid: projectEntity.id } | orderBy: '-created'"));

      //Should show created project
      expect(project.$('h5').getText()).toEqual('E2E: Test Project');

      project.$('a.accordion-toggle').click();
      expect(items.first().$$('a').first().getText()).toEqual('E2E: Test Solution Search');

      items.first().$$('a').first().click();
      expect(browser.getLocationAbsUrl()).toEqual(searchUrl);
    });

    it('should clean up test project', function() {
      browser.get('/app/#/');
      page.projects.first().$('a.options').click();
      $('div.popover').$$('li.list-group-item a').get(1).click();
    });
  });

  if (!browser.params.publicUser) {
    describe('Comments', function() {
      page.createComment = $('.comment-form');
      page.submitComment = $('button.submit-comment');
      page.comments = element.all(by.repeater('comment in comments'));
      page.commentBody = element(by.model('newComment.body'));
      page.editor = $('.rich-text-editor .editor');
      page.bold = $('.rich-text-editor .bold-control');
      page.underline = $('.rich-text-editor .underline-control');
      page.italic = $('.rich-text-editor .italics-control');
      page.ol = $('.rich-text-editor .ordered-list-control');
      page.ul = $('.rich-text-editor .unordered-list-control');
      page.hyperlink = $('.rich-text-editor .hyperlink-control');
      page.editForm = element(by.css('[name="commentEditForm"]'));
      page.editCommentsEditor = page.editForm.element(by.css('.rich-text-editor .editor'));

      it('should have a comments area', function() {
        browser.get('/app/#/sowl/search');
        page.reset.click();
        page.results.get(1).$('div.sowTitleBox a').click();
        expect(page.createComment.isDisplayed()).toBe(true);
      });

      it('should require a comment body', function () {
        expect(page.commentBody.getAttribute('class')).toContain('ng-invalid');
        expect(page.submitComment.getAttribute('disabled')).toEqual('true');

        page.editor.sendKeys('E2E: Test Topic body text');

        expect(page.commentBody.getAttribute('class')).toContain('ng-valid');
        expect(page.submitComment.getAttribute('disabled')).toEqual(null);
      });

      it('should make text bold', function() {
        page.editor.clear();
        page.bold.click();
        page.editor.sendKeys('Bold Text');
        expect(page.editor.getInnerHtml()).toContain('<b>Bold Text</b>');
      });

      it('should make text italics', function() {
        page.editor.clear();
        page.italic.click();
        page.editor.sendKeys('Italics Text');
        expect(page.editor.getInnerHtml()).toContain('<i>Italics Text</i>');
      });

      it('should make text underline', function() {
        page.editor.clear();
        page.underline.click();
        page.editor.sendKeys('Underline Text');
        expect(page.editor.getInnerHtml()).toContain('<u>Underline Text</u>');
      });

      it('should make text Ordered List', function() {
        page.editor.clear();
        page.ol.click();
        page.editor.sendKeys('List Item 1');
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys('List Item 2');
        page.editor.sendKeys(protractor.Key.ENTER);
        expect(page.editor.getInnerHtml()).toContain('<ol>');
        expect(page.editor.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(page.editor.getInnerHtml()).toContain('<li>List Item 2</li>');
      });

      it('should make text Unordered List', function() {
        page.editor.clear();
        page.ul.click();
        page.editor.sendKeys('List Item 1');
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys('List Item 2');
        page.editor.sendKeys(protractor.Key.ENTER);
        expect(page.editor.getInnerHtml()).toContain('<ul>');
        expect(page.editor.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(page.editor.getInnerHtml()).toContain('<li>List Item 2</li>');
      });

      xit('should create a hyperlink', function() {
        page.editor.clear();
        page.editor.sendKeys('Hyperlink Text');
        page.editor.sendKeys(protractor.Key.chord(protractor.Key.CONTROL, 'a'));
        page.hyperlink.click();
        var a = browser.switchTo().alert();
        a.sendKeys(browser.baseUrl);
        a.accept();
        browser.pause();
        expect(page.editor.getInnerHtml()).toContain('<a href="' + browser.baseUrl + '">' + browser.baseUrl + '</a>');
      });

      it('should submit a topic comment', function () {
        //page.commentTopic.click();
        page.editor.clear();
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ARROW_UP);
        page.editor.sendKeys(protractor.Key.ARROW_UP);
        page.editor.sendKeys(protractor.Key.ARROW_UP);
        page.editor.sendKeys(protractor.Key.ARROW_UP);
        page.editor.sendKeys(protractor.Key.ARROW_UP);
        page.bold.click();
        page.editor.sendKeys('Bold Text');
        page.editor.sendKeys(protractor.Key.ARROW_RIGHT);
        page.editor.sendKeys(protractor.Key.ENTER);
        page.italic.click();
        page.editor.sendKeys('Italics Text');
        page.editor.sendKeys(protractor.Key.ARROW_RIGHT);
        page.editor.sendKeys(protractor.Key.ENTER);
        //page.italic.click();
        page.underline.click();
        page.editor.sendKeys('Underline Text');
        page.editor.sendKeys(protractor.Key.ARROW_RIGHT);
        page.editor.sendKeys(protractor.Key.ENTER);
        //page.underline.click();
        page.ol.click();
        page.editor.sendKeys('List Item 1');
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys('List Item 2');
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ENTER);
        page.ul.click();
        page.editor.sendKeys('List Item 1');
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys('List Item 2');
        page.editor.sendKeys(protractor.Key.ENTER);
        page.editor.sendKeys(protractor.Key.ENTER);

        //expect(page.commentForm.isPresent()).toBe(false);
        page.submitComment.click();
      });

      it('should edit a comment', function() {
        page.comments.last().$('a.edit-comment').click();
        expect(page.editForm.isDisplayed()).toBe(true);
        page.editCommentsEditor.clear();
        page.editCommentsEditor.sendKeys('Test edited comment');
        page.editForm.$('.submit-comment').click();
        expect(page.editForm.isPresent()).toBe(false);
        var commentBody = page.comments.last().$('.comment-body').getText();
        expect(commentBody).toEqual('Test edited comment');
      });

      it('should display comment author name', function(){
          expect(page.comments.last().$('.topic-author-name').isDisplayed()).toBe(true);
          expect(page.comments.last().$('.topic-author-name').getText()).toContain('e2eUser');
      });

      it('should display comment author picture', function(){
        expect(page.comments.last().$('.img-circle').isDisplayed()).toBe(true);
      });

      it('should follow / unfollow the comment author', function() {
        expect(page.comments.last().$('#button-follow span').getText()).toEqual('Follow');
        page.comments.last().$('#button-follow').click();
        expect(page.comments.last().$('#button-follow span').getText()).toEqual('Unfollow');
        page.comments.last().$('#button-follow').click();
      });

      it('should delete a comment from the comments list', function() {
        page.comments.count().then(function(startCount) {
          page.comments.last().$('a.delete-comment').click();
          page.comments.count().then(function(endCount) {
            expect(endCount).toBe(startCount-1);
          });
        });
      });
    });
  }

  if (!browser.params.publicUser) {
    describe('Voting', function() {
      it('should have voting capability', function() {
        browser.get('/app/#/sowl');
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        expect(vote.isPresent()).toBe(true);
        expect(vote.$('.vote-comment').getText()).toEqual('Found this helpful');
      });

      it('should vote the Document up', function() {
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-up');
        vote.$('div.vote-count').getText().then(function(count) {
          voteUp.click();
          expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');
          expect(vote.$('div.vote-count').getText()).toEqual(((count*1) + 1).toString());
        });
      });

      it('should remember the up vote', function() {
        browser.refresh();
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-up');
        expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');

      });

      it('should cancel the up vote on the Document', function() {
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function(votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes*1) - 1).toString());
        });
      });

      it('should vote the Document down', function() {
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function(votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes*1) - 1).toString());
        })
      });

      it('should remember the down vote', function() {
        browser.refresh();
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-down');
        expect(voteUp.$('span.fa-thumbs-down').getAttribute('class')).toContain('active');
      });

      it('should cancel the down vote on the Document', function() {
        var vote = page.searchResults.get(0).$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function(votes) {
          vote.$('a[ng-click="vote(\'up\')"]').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes*1) + 1).toString());
        });
      });
    });
  }

   if (browser.params.publicUser) {
      describe('Voting for Public users', function() {
        it('should not show voting capability', function() {
          expect($('.vote-comment ng-binding').isPresent()).toBe(false);
        });
      });
    }
 });
