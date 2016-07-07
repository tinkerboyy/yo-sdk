describe('Solutions Finder', function() {
  var element = browser.element;
  var page = {};
  page.title = $('h1.DINCondensedBold');
  page.solutions = browser.element.all(by.repeater('solution in pageSolutions'));
  page.pinnedSolutions = browser.element.all(by.repeater('solution in allSolutions | filter: { pinned: true }'));
  page.resultsShown = $('#results-shown');
  page.totalResultsShown = $('#total-results');
  page.search = browser.element(by.model('moreSearch.search'));
  page.reset = $('#reset-solutions');
  page.viewAll = $('#view-all');
  page.overFilteredMessage = $('#overfiltered-message');

  describe('General Functionality', function() {
    it('should have a page title', function() {
      browser.get(browser.baseUrl + '/app/#/solutionsfinder');
      expect(page.title.getText()).toEqual('SOLUTIONS FINDER');
    });

    it('should show results count information', function() {
      expect($('span.show-results').isDisplayed()).toBe(true);
      expect($('#results-shown').getText()).toBeGreaterThan(0);
      expect(element(by.binding('allSolutions.length')).getText()).toBeGreaterThan(0);
    });
  });

  describe('Pagination', function() {
    page.pagination = browser.element(by.css('.pagination'));
    page.pageSizeContainer = browser.element(by.css('.page-size'));
    page.pageSizes = browser.element.all(by.repeater('size in pageSizes'));
    page.pages = browser.element.all(by.repeater('page in pages'));
    var solutionName = page.solutions.get(0).$('.solution-name');

    it('should have pagination', function () {
      //page.viewAll.click();
      expect(page.pagination.isDisplayed()).toBe(true);
    });

    it('should display 10 results', function () {
      page.pageSizes.get(0).$('a').click();
      expect(page.solutions.count()).not.toBeGreaterThan(10);
    });

    it('should display 25 results', function () {
      page.pageSizes.get(1).$('a').click();
      expect(page.solutions.count()).not.toBeGreaterThan(25);
    });

    it('should display 50 results', function () {
      page.pageSizes.get(2).$('a').click();
      expect(page.solutions.count()).not.toBeGreaterThan(50);
    });

    it('should display 100 results', function () {
      page.pageSizes.get(3).$('a').click();
      expect(page.solutions.count()).not.toBeGreaterThan(100);//todo
    });

    it('should toggle pages', function () {
      page.pageSizes.get(2).$('a').click();
      page.pageSizes.get(3).$('a').click();

      var size;

      page.pages.count().then(function(count) {
        for (var i = 0; i < count; i++) {
          size = page.pages.get(i);
          size.$('a').click();
          solutionName.getText().then(function(text) {
            expect(solutionName.getText()).toBe(text);
          });
        }
      });
    });
  });

  describe('Filters', function() {
    page.filters = element.all(by.css('div.accordion-select'));
    page.popover = browser.element(by.css('.popover'));

    it('should show all solutions when \'Reset\' button is clicked', function() {
      browser.get('/app/#/solutionsfinder');
      page.reset.click();
      page.resultsShown.getText(function(data) {
        expect(page.solutions.count().toString()).toEqual(data);
      });
    });

    it('should have the helper bubbles for all the filters', function() {
      page.filters.each(function(f, i) {
        var filter = page.filters.get(i);
        filter.$('span.accordion-select-help a').click();
        expect(page.popover.isDisplayed()).toBe(true);
        filter.$('span.accordion-select-help a').click();
      });
    });

    it('should perform a keyword search for known search terms', function() {
      page.search.clear();
      page.search.sendKeys('AbilityOne');
      expect(page.solutions.count()).not.toBe(0);
    });

    it('should perform a keyword search for an unknown search term and yield no results', function() {
      page.search.clear();
      page.search.sendKeys('unknownSearchTerm');
      expect(page.solutions.count()).toBe(0);
      page.reset.click();
    });

    it('should show typeahed options when searching and also checking of relative results', function() {
      page.search.clear();
      page.search.sendKeys('abili');
      var typeahead = $('.keyword-search-dotted ul.typeahead');
      expect(typeahead.isDisplayed()).toBe(true);
      expect(typeahead.$$('li').count()).toBeGreaterThan(0);
      expect(typeahead.$$('li').get(0).getText()).toContain('abili');
      typeahead.$$('li').get(0).$('a.ng-binding').click();
      var allresult = element.all(by.css('div.solution-results-item'));
      expect(allresult.get(0).$('div.solution-name').getText()).toContain('AbilityOne');
    });

    it('should reset all search terms and filters when \'Reset\' is clicked', function() {
      page.reset.click();
      expect(page.solutions.count()).toBe(25);
      //expect(page.search.evaluate()).toEqual(null);
    });

    it('should have all filters present', function() {
      expect(page.filters.count()).toEqual(5);
      expect(page.filters.get(0).$('.accordion-select-title').getText()).toEqual('My Agency');
      expect(page.filters.get(1).$('.accordion-select-title').getText()).toEqual('Program Type');
      expect(page.filters.get(2).$('.accordion-select-title').getText()).toEqual('Solution Type');
      expect(page.filters.get(3).$('.accordion-select-title').getText()).toEqual('Category');
      expect(page.filters.get(4).$('.accordion-select-title').getText()).toContain('Subcategory');
    });
    
    it('should have the \'Program Type\' filter expanded by default', function() {
      // reseting all filter to default 
      page.filters.map(function (ele){
        ele.$('a > i.fa-minus-circle').isPresent().then(function (opt){
          if(opt)
          ele.$('.accordion-select-title > a').click();
        });
      });

      page.filters.get(1).$('.accordion-select-title > a').click();
      expect(page.filters.get(1).$('i.fa-minus-circle').isPresent()).toBe(true);
      expect(page.filters.get(1).$('.accordion-select-options').isDisplayed()).toBe(true);
    });

    it('should expand and collapse all filters', function() {
      for (var i = 0; i < 4; i++) {
        //  Filter is already open for Program Type
        var displayState = i === 1 ? false : true;

        page.filters.get(i).$('.accordion-select-title > a').click();
        expect(page.filters.get(i).$('.accordion-select-options').isDisplayed()).toBe(displayState);

        page.filters.get(i).$('.accordion-select-title > a').click();
        expect(page.filters.get(i).$('.accordion-select-options').isDisplayed()).toBe(!displayState);
      }
    });

    it('should not collapse filter when selecting a value', function() {
      since('Accordion is not set to be expanded, accordion should be closed by default')
        .expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(false);
      page.filters.get(0).$('.accordion-select-title > a').click();
      since('We clicked the accordion header, the accordion should be open')
        .expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(0).$$('.accordion-select-options li a').then(function(elems) {
        since('There should be at least one accordion select option')
          .expect(elems.length > 0).toEqual(true);

        elems[0].click();

        since('The accordion should still be open after clicking an option')
          .expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(true);

        elems[0].click();
      });
      page.filters.get(0).$('.accordion-select-title > a').click();
    });

    // Screen settings saved to user preferences
    var aHeight;
    it('should resize the My Agency filter', function() {
      var dragHandle = page.filters.get(0).$('div.ui-resizable-s');
      page.filters.get(0).$('.accordion-select-title > a').click();
      page.filters.get(0).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseDown()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseMove(dragHandle, {
            x: 0,
            y: -100
          })
          .mouseUp()
          .perform();

        page.filters.get(0).$('div.ui-resizable').getCssValue('height').then(function(h) {
          aHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).toBeLessThan(height);
        });
      });
    });

    it('should remember resize of the My Agency filter', function() {
      browser.refresh();
      expect(page.filters.get(0).$('div.ui-resizable').getCssValue('height')).toEqual(aHeight);
    });

    it('should remember collapsed state of the My Agency filter', function() {
      page.filters.get(0).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the My Agency filter', function() {
      page.filters.get(0).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(0).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(0).$('.accordion-select-title > a').click();
    });

    var pHeight;
    it('should resize the Program Type filter', function() {
      var dragHandle = page.filters.get(1).$('div.ui-resizable-s');
      page.filters.get(1).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseDown()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseMove(dragHandle, {
            x: 0,
            y: -100
          })
          .mouseUp()
          .perform();

        page.filters.get(1).$('div.ui-resizable').getCssValue('height').then(function(h) {
          pHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).not.toBeGreaterThan(height);
        });
      });
    });

    it('should remember resize of the Program Type filter', function() {
      browser.refresh();
      expect(page.filters.get(1).$('div.ui-resizable').getCssValue('height')).toEqual(pHeight);
    });

    it('should remember collapsed state of the Program Type filter', function() {
      page.filters.get(1).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(1).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Program Type filter', function() {
      page.filters.get(1).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(1).$('.accordion-select-options').isDisplayed()).toBe(true);
    });

    var ccHeight;
    it('should resize the Contract Type filter', function() {
      page.filters.get(2).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(2).$('div.ui-resizable-s');
      page.filters.get(2).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseDown()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseMove(dragHandle, {
            x: 0,
            y: -100
          })
          .mouseUp()
          .perform();

        page.filters.get(2).$('div.ui-resizable').getCssValue('height').then(function(h) {
          ccHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).toBeLessThan(height);
        });
      });
    });

    it('should remember resize of the Contract Type filter', function() {
      browser.refresh();
      expect(page.filters.get(2).$('div.ui-resizable').getCssValue('height')).toEqual(ccHeight);
    });

    it('should remember collapsed state of the Contract Type filter', function() {
      page.filters.get(2).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(2).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Contract Type filter', function() {
      page.filters.get(2).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(2).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(2).$('.accordion-select-title > a').click();
    });

    var cHeight;
    it('should resize the Category filter', function() {
      page.filters.get(3).$('.accordion-select-title > a').click();
      var dragHandle = page.filters.get(3).$('div.ui-resizable-s');
      page.filters.get(3).$('div.ui-resizable').getCssValue('height').then(function(height) {
        height = parseInt(height.replace('px', ''), 10);
        browser.actions()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseDown()
          .mouseMove(dragHandle, {
            x: 0,
            y: 0
          })
          .mouseMove(dragHandle, {
            x: 0,
            y: -100
          })
          .mouseUp()
          .perform();

        page.filters.get(3).$('div.ui-resizable').getCssValue('height').then(function(h) {
          cHeight = h;
          h = parseInt(h.replace('px', ''), 10);
          expect(h).toBeLessThan(height);
        });
      });
    });

    it('should remember resize of the Category filter', function() {
      browser.refresh();
      expect(page.filters.get(3).$('div.ui-resizable').getCssValue('height')).toEqual(cHeight);
    });

    it('should remember collapsed state of the Category filter', function() {
      page.filters.get(3).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(3).$('.accordion-select-options').isDisplayed()).toBe(false);
    });

    it('should remember expanded state of the Category filter', function() {
      page.filters.get(3).$('.accordion-select-title > a').click();
      browser.refresh();
      expect(page.filters.get(3).$('.accordion-select-options').isDisplayed()).toBe(true);
      page.filters.get(3).$('.accordion-select-title > a').click();
    });

    it('should contain 26 Available To agencies', function() {
      page.filters.get(0).$('.accordion-select-title > a').click();
      var options = page.filters.get(0).all(by.repeater('item in collection'));
      expect(options.count()).toEqual(26);
    });

    it('should have the right Available To (My Agency) options in the right order', function() {
      var options = page.filters.get(0).$$('ul.accordion-select-options li');
      expect(options.get(0).getText()).toContain('Dept of Defense');
      expect(options.get(1).getText()).toContain('Air Force');
      expect(options.get(2).getText()).toContain('Army');
      expect(options.get(3).getText()).toContain('DHA');
      expect(options.get(4).getText()).toContain('Navy');
      expect(options.get(5).getText()).toContain('Other DoD Organization');
      expect(options.get(6).getText()).toContain('Federal Agencies');
      expect(options.get(7).getText()).toContain('DoC');
      expect(options.get(8).getText()).toContain('DoE');
      expect(options.get(9).getText()).toContain('DHS');
      expect(options.get(10).getText()).toContain('DoI');
      expect(options.get(11).getText()).toContain('DoJ');
      expect(options.get(12).getText()).toContain('DoL');
      expect(options.get(13).getText()).toContain('DoT');
      expect(options.get(14).getText()).toContain('Ed');
      expect(options.get(15).getText()).toContain('EPA');
      expect(options.get(16).getText()).toContain('GSA');
      expect(options.get(17).getText()).toContain('HHS');
      expect(options.get(18).getText()).toContain('HUD');
      expect(options.get(19).getText()).toContain('IRS');
      expect(options.get(20).getText()).toContain('NASA');
      expect(options.get(21).getText()).toContain('State');
      expect(options.get(22).getText()).toContain('Treasury');
      expect(options.get(23).getText()).toContain('USDA');
      expect(options.get(24).getText()).toContain('VA');
      expect(options.get(25).getText()).toContain('Other Federal Agency');
     });

    /**
     * Common logic to check a filter option and check that expected UI behavior happens
     *
     * @param  {ElementFinder} options           [description]
     * @param  {int} currentIndex      [description]
     * @param  {Function} checkResultsMatch [description]
     * @return {void}                   [description]
     */
    var checkFilterOption = function(filterIndex, options, currentIndex, params, checkResultsMatch) {
      if (typeof params === 'undefined') {
        params = {};
      }

      var option = options.get(currentIndex),
        filterCount,
        optionTitle;
      defer = protractor.promise.defer();

      option.$('.filter-count').getText().then(function(filterCountText) {
        filterCount = filterCountText.length > 2 ? filterCountText.substring(1, filterCountText.length - 1) : '';
      });

      browser.actions().mouseMove(option).click().perform();

      //Option should show selected state
      expect(option.element(by.xpath('..')).getAttribute('class')).toContain('selected');
      //Filter accordion select title should show highlighted to show that an option is selected
      expect(page.filters.get(filterIndex).$('.accordion-select-title').getAttribute('class')).toContain('has-selected-items');
      //Applied filters panel should be visible
      since('Applied filters panel should now be visible')
        .expect($('.ag-applied-filters > div').isDisplayed()).toBe(true);

      //Applied filters section should have the option name in it
      option.getText().then(function(title) {
        optionTitle = title;
        $$('.ag-applied-filters ul li').map(function(appliedFilter) {
          return appliedFilter.getText();
        }).then(function(appliedFilters) {
          expect(appliedFilters).toContain(title);
        })
      });

      //Result count should equal the filter count
      page.resultsShown.isPresent().then(function(isPresent) {
        if (filterCount === '0') {
          since('Filter matches no items so no results should be shown')
            .expect(isPresent).toBe(false);
          expect(page.totalResultsShown.isDisplayed()).toBe(true);
          expect(page.overFilteredMessage.isDisplayed()).toBe(true);
        } else {
          since('Filter matches items so results should be shown')
            .expect(isPresent).toBe(true);
          page.resultsShown.getText().then(function(resultsShownText) {
            expect(filterCount).toEqual(resultsShownText);

            if (checkResultsMatch) {
              checkResultsMatch({
                option: option,
                currentIndex: currentIndex
              });
            }
          });
        }
      });



      browser.actions().mouseMove(option).click().perform();
      //Option should not show active state anymore
      expect(option.element(by.xpath('..')).getAttribute('class')).not.toContain('selected');
      //Applied filters section should no longer be visible
      if (!params.appliedFiltersAlreadyOpen) {
        $('.ag-applied-filters > div').isDisplayed().then(function(isDisplayed) {
          since('Applied filters panel should not be visible')
            .expect(isDisplayed).toBe(false);
        });
      }

    };

    it('should filter by Agency', function() {
      var options = page.filters.get(0).$$('ul.accordion-select-options li a');

      //Check first two
      for (var i = 0; i < 2; i++) {
        checkFilterOption(0, options, i);
      }
      page.filters.get(0).$('.accordion-select-title > a').click();
    });

    it('should filter by Program Type', function() {
      var options = page.filters.get(1).$$('ul.accordion-select-options li a');

      //Check first two
      for (var i = 0; i < 1; i++) {
        checkFilterOption(1, options, i, {}, function(params) {
          var optionTitle;

          params.option.getText().then(function(title) {
            optionTitle = title;
          });

          //Check that results all have the program type that was selected
          page.solutions.count().then(function(count) {
            for (var i = 0; i < count; i++) {
              page.solutions.get(i).$$('.program-type').map(function(programType) {
                return programType.getText();
              }).then(function(programTypes) {
                expect(programTypes).toContain(optionTitle);
              });
            }
          });
        });
      }
    });

    it('should filter by Solutions Types', function() {
      var options = page.filters.get(2).$$('ul.accordion-select-options li a');
      page.filters.get(2).$('.accordion-select-title > a').click();

      //Check first two
      for (var i = 0; i < 2; i++) {
        checkFilterOption(2, options, i, {}, function(params) {
          var optionTitle;

          params.option.getText().then(function(title) {
            optionTitle = title;
          });

          //Check that results all have the contract type that was selected
          page.solutions.count().then(function(count) {
            for (var i = 0; i < count; i++) {
              page.solutions.get(i).$$('.contract-type').map(function(contractType) {
                return contractType.getText();
              }).then(function(contractTypes) {
                expect(contractTypes).toContain(optionTitle);
              });
            }
          });
        });
      }
      page.filters.get(2).$('.accordion-select-title > a').click();
    });

    it('should filter by Category', function() {
      var options = page.filters.get(3).$$('ul.accordion-select-options li a');
      page.filters.get(3).$('.accordion-select-title > a').click();

      //Check first two
      for (var i = 0; i < 2; i++) {
        checkFilterOption(3, options, i, {}, function(params) {
          var optionTitle;

          params.option.getText().then(function(title) {
            optionTitle = title;
          });

          //Check that results all have the category that was selected
          page.solutions.count().then(function(count) {
            for (var i = 0; i < count; i++) {
              page.solutions.get(i).$('.show-more').click();
              page.solutions.get(i).$$('.solution-category').map(function(category) {
                return category.getText();
              }).then(function(categories) {
                expect(categories).toContain(optionTitle);
              });
              page.solutions.get(i).$('.show-more').click();
            }
          });
        });
      }
      page.filters.get(3).$('.accordion-select-title > a').click();
    });
    it('should filter by Subcategory', function() {
        page.filters.get(3).$('.accordion-select-title > a').click();
        var categoryOptions = page.filters.get(3).$$('ul.accordion-select-options li a');

        for (var i = 0; i < 1; i++) {
          page.filters.get(3).$$('ul.accordion-select-options li a').get(i).click();

          //Open subcategory accordion first time
          if (i === 0) {
            page.filters.get(4).$('.accordion-select-title > a').click();
          }

          var options = page.filters.get(4).$$('ul.accordion-select-options li a');

          for (var j = 0; j < 1; j++) {
            checkFilterOption(4, options, j, {
              appliedFiltersAlreadyOpen: true
            }, function(params) {
              var optionTitle;

              params.option.getText().then(function(title) {
                optionTitle = title;
              });

              //Check that results all have the subcategory that was selected
              page.solutions.count().then(function(count) {
                for (var i = 0; i < count; i++) {
                  page.solutions.get(i).$('.show-more').click();
                  page.solutions.get(i).$$('.solution-subcategory').map(function(category) {
                    return category.getText();
                  }).then(function(categories) {
                    expect(categories).toContain(optionTitle);
                  });
                }
              });
            });
          }
          page.filters.get(3).$$('ul.accordion-select-options li a').get(i).click();
        }
        page.filters.get(3).$('.accordion-select-title > a').click();
    });    
  });

  describe('Individual Solution', function() {
    page.showMore = page.solutions.get(0).$('a.show-more');
    page.solutionDetails = page.solutions.get(0).$('.solution-details');
    it('should expand a solution to show details', function() {
      page.reset.click();
      //page.viewAll.click();
      page.showMore.click();
      expect(page.showMore.getText()).toEqual('Less');
      expect(page.solutionDetails.isDisplayed()).toBe(true);
    });

    it('should collapse a solution to hide details', function() {
      page.showMore.click();
      expect(page.showMore.getText()).toEqual('More');
      expect(page.solutionDetails.isDisplayed()).toBe(false);
    });

    it('should have a button link for Prices Paid', function() {
      var buttons = browser.element.all(by.css('a.prices-paid-button'));
      buttons.count().then(function(count) {
        for (var i = 0; i < count; i++) {
          expect(buttons.get(i).getText()).toEqual('Prices Paid');
        }
      });
    });

    if (!browser.params.publicUser) {
      describe('Voting', function() {
        it('should have voting capability', function() {
          page.reset.click();
          //page.viewAll.click();
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          expect(vote.isPresent()).toBe(true);
          expect(vote.$('.vote-comment').getText()).toEqual('Recommend');
        });

        it('should vote the solution up', function() {
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          var voteUp = vote.$('a.vote-up');
          vote.$('div.vote-count').getText().then(function(count) {
            voteUp.click();
            expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');
            expect(vote.$('div.vote-count').getText()).toEqual(((count * 1) + 1).toString());
          });
        });

        it('should remember the up vote', function() {
          browser.refresh();
          //page.viewAll.click();
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          var voteUp = vote.$('a.vote-up');
          expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');

        });

        it('should cancel the up vote on the solution', function() {
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          vote.$('div.vote-count').getText().then(function(votes) {
            vote.$('a.vote-down').click();
            expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
          });
        });

        it('should vote the solution down', function() {
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          vote.$('div.vote-count').getText().then(function(votes) {
            vote.$('a.vote-down').click();
            expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
          })
        });

        it('should remember the down vote', function() {
          browser.refresh();
          //page.viewAll.click();
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          var voteUp = vote.$('a.vote-down');
          expect(voteUp.$('span.fa-thumbs-down').getAttribute('class')).toContain('active');
        });

        it('should cancel the down vote on the solution', function() {
          var vote = page.solutions.get(0).$('.vote-up-down-widget');
          vote.$('div.vote-count').getText().then(function(votes) {
            vote.$('a[ng-click="vote(\'up\')"]').click();
            expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) + 1).toString());
          });
        });
      });
    }

    describe('Pinning', function() {
      it('should pin a solution', function() {
        var solution = page.solutions.get(0);
        var pinnedSolution = page.pinnedSolutions.get(0);
        solution.$('a.ag-pin:last-child').click();
        expect(pinnedSolution.getAttribute('class')).toContain('pinned');
        expect(pinnedSolution.$('a.ag-pin:last-child').getAttribute('class')).toContain('pinned');
      });

      it('should show pinned solutions even when no filter is selected', function() {
        page.reset.click();
        var pinnedSolution = page.pinnedSolutions.get(0);
        var allresult = element.all(by.css('div.solution-results-item'));
        expect(pinnedSolution.$('div.solution-name').getText()).toContain(allresult.get(0).$('div.solution-name').getText());
      });

      it('should show pinned solutions even when you have overfiltered', function() {
        page.search.sendKeys('unknownSearchTerm');
        expect(page.pinnedSolutions.count()).toBe(1);
      });

      it('should unpin a solution', function() {
        page.reset.click();
        //page.viewAll.click();
        var pinnedSolution = page.pinnedSolutions.get(0);
        pinnedSolution.$('a.ag-pin:last-child').click();
        expect(page.pinnedSolutions.count()).toBe(0);
      });
    });

    describe('Add to Project Center', function() {
      var openAdd = $$('div.solution-actions ul.dropdown-menu li a').first();
      var solutionName = '';
      it('should open the \'Add to Project\' Dialog', function() {
        page.solutions.get(0).$('a.solution-options').click();
        openAdd.click();
        expect($('div.add-to-project').isDisplayed()).toEqual(true);
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
        var projects = browser.element.all(by.repeater("project in projects | filter: { status: '1' }"));
        var name = element(by.binding('itemName'));

        page.solutions.get(0).$('div.solution-name').getText().then(function(text) {
          solutionName = text;
          expect(name.getText()).toEqual(text);
        });

        //Expect the submit button to be sdisabled
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual('true');

        projects.last().$('a').click();
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual(null);

        $('#add-to-project-submit').click();
      });

      it('should show the Solution in the Project Center', function() {
        browser.get('/app/#/');
        page.projects = browser.element.all(by.repeater("projectEntity in projects.data.collection | filter: { status: '1' } | orderBy: '-created'"));
        var project = page.projects.first();
        var items = project.all(by.repeater("projectContent in projectEntities.data.collection | myProjectContentFilter: { status: '1', pid: projectEntity.id } | orderBy: '-created'"));

        //Should show created project
        expect(project.$('h5').getText()).toEqual('E2E: Test Project');

        project.$('a.accordion-toggle').click();
        expect(items.first().$$('a').first().getText()).toEqual(solutionName);

        items.first().$$('a').first().click();
        expect(browser.getLocationAbsUrl()).toContain('/solutionsfinder/');
      });

      it('should clean up test project', function() {
        browser.get('/app/#/');
        page.projects.first().$('a.options').click();
        $('div.popover').$$('li.list-group-item a').get(1).click();
      });
    });

    describe('Report Data Issue', function() {
      var openReport = $$('div.solution-actions ul.dropdown-menu li a').last();
      page.submitDataIssue = $('#submit-data-issue');
      page.issueDetails = element(by.model('issue.comments'));

      it('should open the Report Data Issue form', function() {
        browser.get('/app/#/solutionsfinder');
        page.reset.click();
        //page.viewAll.click();
        page.solutions.get(0).$('a.solution-options').click();
        openReport.click();
        expect($('div.modal-dialog').isDisplayed()).toBe(true);
        expect($('h4.modal-title').getText()).toEqual('Report Data Issue');
        page.solutions.get(0).$('div.solution-name').getText().then(function(text) {
          expect(element(by.binding('issue.solutionName')).getText()).toEqual(text);
        });
      });
      
      it('should have different email address for public and non-public user', function(){        
        if(!browser.params.publicUser){
        expect(element(by.model('issue.userEmail')).getAttribute('value')).toContain('e2eUser@gsa.gov');
        }
        else{
          expect(element(by.model('issue.userEmail')).getAttribute('value')).toContain('@example.com');
        }      
      });

      it('should validate the form', function() {
        expect(page.submitDataIssue.getAttribute('disabled')).toBe('true');
        expect(page.issueDetails.getAttribute('class')).toContain('ng-invalid');
        page.issueDetails.sendKeys('E2E: Data issue details');
        expect(page.issueDetails.getAttribute('class')).toContain('ng-valid');
        expect(page.submitDataIssue.getAttribute('disabled')).toBe(null);
      });

      it('should close the form', function() {
        $('div.modal-header button.close').click();
        expect($('div.modal-dialog').isPresent()).toBe(false);
      });

      it('should submit the data issue', function() {
        page.solutions.get(0).$('a.solution-options').click();
        openReport.click();
        page.issueDetails.sendKeys('E2E: Data issue details');
        page.submitDataIssue.click();
      });
    });
  });

  describe('Add To Project Center', function() {
    page.share = $('.ag-share > a');
    var searchUrl;

    it('should have a share button', function() {
      browser.get('/app/#/solutionsfinder');
      page.reset.click();
      //page.viewAll.click();
      expect(page.share.isDisplayed()).toBe(true);
    });

    it('should open the share dialog', function() {
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
      expect($('div.add-to-project').isPresent()).toEqual(false);
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

  describe('Sorting', function() {
    page.sort = $('a.sort-toggle');
    page.sortMenu = $('ul.dropdown-menu');
    page.sortOptions = page.sortMenu.$$('li a');
    page.sortTestResult = [];

     //check's sorting for test 
     //ex: checkSort(page.solutions,'div.solution-name','ascending');
    function checkSort(collection, selector, direction, cb) {  
      var data = [];
      var sorted = [];
      var promises = [];
      var i = 0;
         collection.each(function(elem) {
            promises.push(i);          
            elem.$(selector).getText().then(function(sol){
                data.push(sol);
                promises.splice(promises.indexOf(i), 1);
                while(promises.length == 0) {
                  sorted = data.sort(); 
                    if (direction == 'descending'){
                      sorted = sorted.reverse();                                
                      }
                    cb(data, sorted);  
                    break; 
                  }
            });
               
        });         
    }

    it('should display the sorting directive', function() {
      browser.get('/app/#/solutionsfinder');
      //page.viewAll.click();
      expect(page.sort.isDisplayed()).toBe(true);
    });

    it('should show sorting options', function() {
      page.sort.click();
      expect(page.sortMenu.isDisplayed()).toBe(true);
      if(!browser.params.publicUser){
        expect(page.sortOptions.count()).toBe(4);
        expect(page.sortOptions.last().$('span.fa-arrow-up').isDisplayed()).toBe(true);
        expect(page.sortOptions.last().$('span.fa-check').isDisplayed()).toBe(true);
        expect(page.sortOptions.get(0).getText()).toEqual('Availability');
        expect(page.sortOptions.get(1).getText()).toEqual('Managed by agency');
        expect(page.sortOptions.get(2).getText()).toEqual('Recommend Count');
        expect(page.sortOptions.get(3).getText()).toEqual('Solution name');
      }else{
        expect(page.sortOptions.count()).toBe(3);
        expect(page.sortOptions.last().$('span.fa-arrow-up').isDisplayed()).toBe(true);
        expect(page.sortOptions.last().$('span.fa-check').isDisplayed()).toBe(true);
        expect(page.sortOptions.get(0).getText()).toEqual('Availability');
        expect(page.sortOptions.get(1).getText()).toEqual('Managed by agency');
        expect(page.sortOptions.get(2).getText()).toEqual('Solution name');      
      }
    });

    it('should sort by Solution Name descending', function() {
      page.sortOptions.last().click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
        checkSort(page.solutions,'div.solution-name','descending', function(data, test) {
          expect(data).toEqual(test);
        });
      });
      expect(page.sortOptions.last().$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.last().$('span.fa-check').isDisplayed()).toBe(true);
    });

    it('should sort by Solution Name ascending', function() {
      page.sortOptions.last().click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
        checkSort(page.solutions,'div.solution-name','ascending', function(data, test) {
          expect(data).toEqual(test);
        });
      });
      expect(page.sortOptions.last().$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.last().$('span.fa-check').isDisplayed()).toBe(true);
    });

    it('should sort by Availability ascending', function() {
      var availability = browser.element.all(by.binding('::solution.availableTo')).first();
      page.sortOptions.get(0).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
        checkSort(page.solutions,'div.solution-name','ascending', function(data, test) {
          expect(data).toEqual(test);
        });
      });
      expect(page.sortOptions.get(0).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(0).$('span.fa-check').isDisplayed()).toBe(true);
    });

    it('should sort by Availability descending', function() {
      var availability = browser.element.all(by.binding('::solution.availableTo')).first();
      page.sortOptions.get(0).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
        checkSort(page.solutions,'div.solution-name','descending', function(data, test) {
          expect(data).toEqual(test);
        });
      });
      expect(page.sortOptions.get(0).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(0).$('span.fa-check').isDisplayed()).toBe(true);
    });

    it('should sort by \'Managed by agency\' ascending', function() {
      var availability = browser.element.all(by.binding('::solution.managingAgencyShortName')).first();
      page.sortOptions.get(1).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
        checkSort(page.solutions,'div.solution-name','ascending', function(data, test) {
          expect(data).toEqual(test);
        });
      });
      expect(page.sortOptions.get(1).$('span.fa-arrow-up').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(1).$('span.fa-check').isDisplayed()).toBe(true);
    });

    it('should sort by \'Managed by agency\' descending', function() {
      var availability = browser.element.all(by.binding('::solution.managingAgencyShortName')).first();
      page.sortOptions.get(1).click();
      expect(page.sortMenu.isPresent()).toBe(false);
      page.sort.click();
      page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
        checkSort(page.solutions,'div.solution-name','descending', function(data, test) {
          expect(data).toEqual(test);
        });
      });
      expect(page.sortOptions.get(1).$('span.fa-arrow-down').isDisplayed()).toBe(true);
      expect(page.sortOptions.get(1).$('span.fa-check').isDisplayed()).toBe(true);
    });
     if (!browser.params.publicUser) { 
          it('should sort by \'Recommend Count\' descending', function() {
            var first = browser.element.all(by.css('div.vote-count')).first();
            var last = browser.element.all(by.css('div.vote-count')).last();
            page.sortOptions.get(2).click();
            first.getText().then(function(firstVote) {
              last.getText().then(function(lastVote) {
                expect(firstVote >= lastVote).toBe(true);
              });
            });
            expect(page.sortMenu.isPresent()).toBe(false);
            page.sort.click();
            page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
             checkSort(page.solutions,'div.solution-name','descending', function(data, test) {
               expect(data).toEqual(test);
              });
            });
            expect(page.sortOptions.get(2).$('span.fa-arrow-down').isDisplayed()).toBe(true);
            expect(page.sortOptions.get(2).$('span.fa-check').isDisplayed()).toBe(true);
          });

          it('should sort by \'Recommend Count\' ascending', function() {
            var first = browser.element.all(by.css('div.vote-count')).first();
            var last = browser.element.all(by.css('div.vote-count')).last();
            page.sortOptions.get(2).click();
            first.getText().then(function(firstVote) {
              last.getText().then(function(lastVote) {
                expect(firstVote <= lastVote).toBe(true);
              });
            });
            expect(page.sortMenu.isPresent()).toBe(false);
            page.sort.click();
            page.solutions.get(0).$('div.solution-name').getText().then(function(sol) {
             checkSort(page.solutions,'div.solution-name','ascending', function(data, test) {
               expect(data).toEqual(test);
              });
            });
            expect(page.sortOptions.get(2).$('span.fa-arrow-up').isDisplayed()).toBe(true);
            expect(page.sortOptions.get(2).$('span.fa-check').isDisplayed()).toBe(true);
          });
      }
  });

  describe('Price paid portal, Contract, Order, T&C buttons', function() {
    it('should have the Export button', function() {
       if(!browser.params.publicUser){
         expect($('#export-search-results').isPresent()).toBe(true);
       }else{
        expect($('#export-search-results').isPresent()).toBe(false);
       }
    });

    it('should have the Prices Paid Portal button', function() {
      if(!browser.params.publicUser){
        expect($('#prices-paid-portal').isPresent()).toBe(true);
      }else{
        expect($('#prices-paid-portal').isPresent()).toBe(false);
      }
    });

    it('should have a Prices Paid button on any Solution', function() {
        if(!browser.params.publicUser){
          expect($$('a.prices-paid-button').count()).toBeGreaterThan(0);
          expect($$('a.prices-paid-button').getCssValue('background-color')).toContain('rgba(70, 137, 155, 1)');
        }else{
          expect($('a.prices-paid-button').isPresent()).toBe(false);
          expect($('a.prices-paid-button').isPresent()).toBe(false);
        }
    });

    it('should have a Contract button on any Solution', function() {
       if(!browser.params.publicUser){
          expect($$('a.contract-button').count()).toBeGreaterThan(0);
          expect($$('a.contract-button').getCssValue('background-color')).toContain('rgba(70, 137, 155, 1)', 'rgba(70, 137, 155, 1)');
      } else{
          expect($('a.contract-button').isPresent()).toBe(false);
          expect($('a.contract-button').isPresent()).toBe(false);
      }
    });
  });

  if (browser.params.publicUser) {
    describe('Public User Restrictions', function() {
      it('should not show voting capability', function() {
        expect($('.vote-comment ng-binding').isPresent()).toBe(false);
      });

      it('should not have the Export button', function() {
        expect($('#export-search-results').isPresent()).toBe(false);
      });

      it('should not have the Prices Paid Portal button', function() {
        expect($('#prices-paid-portal').isPresent()).toBe(false);
      });

      it('should not have a Prices Paid button on any Solution', function() {
        expect($$('a.prices-paid-button').count()).toBe(0);
      });

      it('should not have a Contract button on any Solution', function() {
        expect($$('a.contract-button').count()).toBe(0);
      });
    });
  }

  describe('Solution Finder Page vs Solution finder Widget', function() {

    var count = '';

    it('select solution filter and get filtered solution result', function() {
      browser.get('/app/#/');
      browser.refresh();
      var button = element(by.id('purchasingOrganization'));
      button.click();
      button.element(by.xpath('following-sibling::ul/li[1]/a')).click();
      expect($('.solutions-counter').getText()).toBeGreaterThan(0);
      count = $('.solutions-counter').getText();

    });

    it('verify widget filtered solution result with results in solution page', function() {
      element(by.id('sfWidgetSubmitbtn')).click();
      expect(page.resultsShown.getText()).toEqual(count);
    });
  });

  describe('Page when browser resized to', function() {
    it(' 1057px and to check solution page is not overlapping', function() {
       browser.driver.manage().window().setSize(1057, 1000);
       element(by.css('div.solutions-results')).getCssValue('top').then(function(eleTop) {
        expect(eleTop).toBe('55px');
       });
    });
    it(' 750px and to check solution page is not overlapping', function() {
       browser.driver.manage().window().setSize(750, 1000);
       element(by.css('div.solutions-results')).getCssValue('top').then(function(eleTop) {
        expect(eleTop).toBe('80px');
       });
    });
    it(' 650px and to check solution page is not overlapping', function() {
       browser.driver.manage().window().setSize(650, 1000);
       element(by.css('div.solutions-results')).getCssValue('top').then(function(eleTop) {
        expect(eleTop).toBe('95px');
       });
    });
    it(' 600px and to check solution page is not overlapping', function() {
       browser.driver.manage().window().setSize(600, 1000);
       element(by.css('div.solutions-results')).getCssValue('top').then(function(eleTop) {
        expect(eleTop).toBe('120px');
       });
       browser.driver.manage().window().maximize();
    });
  });  
});
