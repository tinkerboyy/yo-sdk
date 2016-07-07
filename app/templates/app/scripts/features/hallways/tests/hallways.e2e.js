describe('Hallway View', function() {
  var page = {};
  var element = browser.element;
  page.featuredArticleList = $$('.featured-article-panel ul li');
  page.hallwaysList = $$('.hallways-nav h5');
  page.hallwaysLinks = element.all(by.repeater("hallway in hallways | orderBy:'label' track by $index"));
  page.hallwaysMenu = $('.left-rail-hallway-menu-label');
  page.rightColumn = $('.right-rail');
  page.communitiesWidget = $('.communities-widget');
  page.feedsWidget = $('.feeds-widget');
  page.allArticleView = $('.allArticleView');
  page.defaultArticleView = $('.defaultArticleView a');

  hallwaysList = [
    'Administrative Support',
    'Card Services',
    'Cleaning Supplies & Chemicals',
    'Employee Relocation',
    'Facilities Maintenance Services',
    'Freight',
    'Human Capital',
    'IT Hardware',
    'IT Security',
    'IT Services',
    'IT Software',
    'Motor Vehicles',
    'Professional Services',
    'Security & Protection',
    'Small Package Delivery',
    'Telecommunications',
    'Tools & Hardware',
    'Travel',
    'Workplace Environment'
  ];

  var hallwaysTax = [{
  'administrative-support': ['office supplies, paper products, and office devices.', 'Office Management', 'Office Management Products']
}, {
  'card-services': ['card and cardless solutions, payment products, and cardholder information.', 'Professional Services', 'Financial Services']
}, {
  'cleaning-supplies-chemicals': ['cleaning equipment, janitorial supplies, and specialty chemicals.', 'Facilities and Construction', 'Facility Related Materials']
}, {
  'employee-relocation': ['homesale assistance, household goods move, and additional relocation services.', 'Transportation and Logistics Services', 'Logistics Support Services']
}, {
  'facilities-maintenance-services': ['facilities maintenance & management, grounds maintenance & pest control, elevator & escalator maintenance, and energy management.', 'Facilities and Construction', '- Select -']
}, {
  'freight': ['freight-all-kind (FAK) shipments.', 'Transportation and Logistics Services', 'Transportation of Things']
}, {
  'human-capital': ['talent development & talent management, performance management, employee & labor relations, and compensation & benefits.', 'Human Capital', '- Select -']
}, {
  'it-hardware': ['computer components & peripherals, computer accessories, and handheld devices.', 'IT', 'IT Hardware']
}, {
  'it-security': ['cybersecurity, identity & access management, and information assurance.', 'IT', 'IT Security']
}, {
  'it-services': ['IT outsourcing, IT consulting services, and IT cloud - platforms & broker.', 'IT', 'IT Outsourcing']
}, {
  'it-software': ['business & productivity, multimedia & design, antivirus & security, and network.', 'IT', 'IT Software']
}, {
  'motor-vehicles': ['purchasing of vehicles, leasing of vehicles, and vehicle ancillary services.', 'Transportation and Logistics Services', 'Motor Vehicles (non-combat)']
}, {
  'professional-services': ['business consulting, logistics service, engineering services, and environmental services.', 'Professional Services', '- Select -']
}, {
  'security-protection': ['alarm & access control systems, surveillance & guard services, marine products & services, and protective equipment & clothing.', 'Security and Protection', '- Select -']
}, {
  'small-package-delivery': ['express delivery services and ground delivery services.', 'Transportation and Logistics Services', 'Package Delivery & Packaging']
}, {
  'telecommunications': ['infrastructure solutions, satellite services, wireless services, and telecom advisory services.', 'IT', 'Telecommunications']
}, {
  'tools-hardware': ['non-powered and powered tools, general hardware products, and paint and coatings.', 'Industrial Products', '- Select -']
}, {
  'travel': ['airline discount programs, lodging programs, and E-Gov Travel Service (ETS).', 'Travel and Lodging', '- Select -']
}, {
  'workplace-environment': ['furniture, document management, mail management, and audio / video.', 'Office Management', '- Select -']
}];


  var sfWidget = require('../../solutions-finder/tests/solutions-finder-widget.e2e.js');

  it('should show hallway name', function () {
    browser.get('/app/#/gateway/administrative-support');
    expect($('.left-rail-header .app-label').getText()).toEqual('HALLWAYS');
  });

  hallwaysTax.forEach(function (hallway, index) {
    var h = Object.keys(hallway);

    it('should load the right hallway', function() {
      if (index === 0) {
        page.hallwaysMenu.click();
        page.hallwaysLinks.last().$('a').click();
      }

      page.hallwaysMenu.click();

      page.hallwaysLinks.get(index).$('a').getText().then(function(title) {
        page.hallwaysLinks.get(index).$('a').click();
        expect(browser.getCurrentUrl()).toContain('/gateway/' + h);
        expect(page.hallwaysMenu.getText()).toEqual(title);
      });
    });

    it('should display hallway definition block in ' + h + ' hallway', function () {
      var defBlock = "Hallway (noun hall·way \\\'hȯl-ˌwā\\): category-specific information resource.\nThis hallway includes ";
      var def = $('#hallwayDefinition');
      var hallwayTaxonomies = def.$('span');

      expect(def.getText()).toEqual(defBlock + hallway[h][0]);
    });

    it('should display solution finder filters in ' + h + ' hallway', function () {

      var categoryGroup = sfWidget.getCategoryInputGroup();
      var subcategoryGroup = sfWidget.getSubcategoryInputGroup();
      expect(sfWidget.getDropdownButton(categoryGroup).getText()).toBe(hallway[h][1] + ' ');
      expect(sfWidget.getDropdownButton(subcategoryGroup).getText()).toBe(hallway[h][2] + ' ');
    });

  });

  it('should have all hallways in dropdown', function () {
    element(by.css('a.hallwayMenu')).click();
    var hallways = browser.element.all(by.repeater('hallway in hallways'));
    hallwaysList.forEach(function (item, i) {
      expect(hallways.get(i).$('.accordion-header h5 a').getText()).toEqual(item);
    });
    element(by.css('a.hallwayMenu')).click();

  });

  it('should have article index', function () {
    var label = element(by.css('.left-rail-header-label')).getText();
    expect(label).toEqual('ARTICLE INDEX');
  });

  it('should display default view', function () {
    expect(page.allArticleView.getText()).toEqual('View All');
    expect((page.allArticleView).isDisplayed()).toBe(true);
    expect((page.defaultArticleView).isDisplayed()).toBe(false);
    expect($('.hallway-solution-finder').isDisplayed()).toBe(true);
    expect($('#hallwayDefinition').isDisplayed()).toBe(true);
  });

  it('should display article view', function () {
    page.allArticleView.click();
    expect(page.defaultArticleView.getText()).toEqual('Back to hallway homepage');
    expect((page.allArticleView).isDisplayed()).toBe(false);
    expect((page.defaultArticleView).isDisplayed()).toBe(true);
    expect($('ag-solutions-finder').isDisplayed()).toBe(false);
    expect($('#hallwayDefinition').isDisplayed()).toBe(false);
  });

 it('should display default view again when back link is clicked', function () {
    page.defaultArticleView.click();
    expect((page.allArticleView).isDisplayed()).toBe(true);
    expect((page.defaultArticleView).isDisplayed()).toBe(false);
    expect($('ag-solutions-finder').isDisplayed()).toBe(true);
    expect($('#hallwayDefinition').isDisplayed()).toBe(true);
    expect($('.featuredArticles').isPresent()).toBe(true);
  });

  describe('Category Team', function() {
    page.categoryTeam = browser.element(by.id('category-team'));
    page.categoryTitle = page.categoryTeam.$('.title-banner');
    page.hallways = browser.element.all(by.repeater("hallway in hallways | orderBy:'label' track by $index"));

    it('should display the Category Team', function() {
      browser.get('/app/#/');
      page.hallways.get(0).$('a').click();
      expect(browser.getCurrentUrl()).toContain('/gateway/administrative-support');
      page.categoryTeam.isPresent().then(function(present) {
        if (present) {
          expect(page.categoryTeam.isDisplayed()).toBe(true);
          expect(page.categoryTitle.getText()).toEqual('MEET THE CATEGORY TEAM');
          expect(page.categoryTeam.$('.img-circle').isDisplayed()).toBe(true);
          expect(page.categoryTeam.$('.category-team-welcome').isDisplayed()).toBe(true);
        }
        else {
          expect(page.categoryTeam.isDisplayed()).toBe(false);
        }
       });
    });

    it('should look same as profile picture in Category Team user smaller profile picture ', function() {
        var imgElements = page.categoryTeam.$$('.img-circle');
        expect(imgElements.get(0).isPresent()).toBe(true);
        imgElements.get(0).getSize().then(function(eleSize){
          expect(eleSize.width).toBeGreaterThan(63);
          expect(eleSize.height).toEqual(64);
        });
    });

   if (!browser.params.publicUser) {
     it('should have a follow / unfollow', function() {
       page.categoryTeam.isPresent().then(function(present) {
         if (present) {
           expect(page.categoryTeam.$('span.follow-btn').isDisplayed()).toBe(true);
           var followUnfollow = page.categoryTeam.$('span.follow-btn').getText();
           page.categoryTeam.$('span.follow-btn').click();
           if (followUnfollow === 'Follow') {
             expect(page.categoryTeam.$('span.follow-btn').getText()).toBe('Unfollow');
           }
           else if (followUnfollow === 'Unfollow') {
             expect(page.categoryTeam.$('span.follow-btn').getText()).toBe('Follow');
           }
          }
        });
      });
    }
  });

  describe('Resource Section', function () {
    var resourceBtn = $$('hw-resources-block a');
    var indexValue = !browser.params.publicUser ? 2 : 1;

    it('should have the \'Buy Online\' button', function () {
      expect(resourceBtn.get(0).getText()).toContain('Buy Online');
    });

    it('should open the \'Buy Online\' modal', function() {
      resourceBtn.get(0).click();
      expect($('.cap-modal').isPresent()).toBe(true);
      expect($('.cap-modal').$('#b_head-box-content').element(by.tagName('h1')).getText()).toEqual('Transactional Platforms');
    });

    it('should close the \'Buy Online\' modal', function() {
      $('.cap-modal').$('div.close a').click();
      expect($('.cap-modal').isPresent()).toBe(false);
    });

    if (!browser.params.publicUser) {
      it('should have the \'View Prices Paid\' button', function () {
        expect(resourceBtn.get(1).getText()).toContain('View Prices Paid');
      });

      it('should open the \'View Prices Paid\' modal', function() {
        resourceBtn.get(1).click();
        expect($('.cap-modal').isPresent()).toBe(true);
        expect($('.cap-modal').$('#b_head-box-content').element(by.tagName('h1')).getText()).toEqual('Prices Paid');
      });

      it('should close the \'View Prices Paid\' modal', function() {
        $('.cap-modal').$('div.close a').click();
        expect($('.cap-modal').isPresent()).toBe(false);
      });
    }

    it('should have the \'Contribute & Share\' button', function () {
      expect(resourceBtn.get(indexValue).getText()).toContain('Contribute & Share');
    });

    it('should open the \'Contribute & Share\' modal', function() {
      resourceBtn.get(indexValue).click();
      expect($('.cap-modal').isPresent()).toBe(true);
      expect($('.cap-modal').$('#b_head-box-content').element(by.tagName('h1')).getText()).toEqual('Contribute & Share');
    });

    it('should close the \'Contribute & Share\' modal', function() {
      $('.cap-modal').$('div.close a').click();
      expect($('.cap-modal').isPresent()).toBe(false);
    });

    it('should include \'Statement of Work Library\' button on Professional Services hallway', function () {
      browser.get('/app/#/gateway/professional-services');
      expect($$('#resourceBtns a').get(indexValue).getText()).toContain('Statement of Work Library');
    });

    it('should go to the Statement of Work Library when the \'Statement of Work Library\' button is clicked', function() {
      resourceBtn.get(indexValue).click();
      expect(browser.getCurrentUrl()).toContain('/sowl');
      browser.get('/app/#/gateway/administrative-support');
    });
  });

  describe('Widgets', function () {

    if (!browser.params.publicUser) {
      it('should show Communities widget', function () {
        expect(page.communitiesWidget.isDisplayed()).toBe(true);
        expect(page.communitiesWidget.$('.title-banner').getText()).toEqual('COMMUNITY');
      });
    }

    it('should show  Events Feed', function () {
      expect(element(by.css('ag-feed .feed-title-banner')).getText()).toEqual('EVENTS');
    });

    it('should show News Feed', function () {
      expect(element(by.css('ag-news-feed .feed-title-banner')).getText()).toEqual('NEWS');
    });
  });

  describe('Solutions Finder Widget', function() {
    var sfWidget = require('../../solutions-finder/tests/solutions-finder-widget.e2e.js');

    it('should display Agency, Category and Subcategory dropdowns', function() {
      browser.get('/app/#/gateway/administrative-support');
      var agencyGroup = sfWidget.getMyAgencyInputGroup();
      expect(agencyGroup.$('label').getText()).toBe('My Agency');
      expect(agencyGroup.$('.ag-smart-select').isDisplayed()).toBe(true);

      var categoryGroup = sfWidget.getCategoryInputGroup();
      expect(categoryGroup.$('label').getText()).toBe('Category');
      expect(categoryGroup.$('.ag-smart-select').isDisplayed()).toBe(true);

      var subcategoryGroup = sfWidget.getSubcategoryInputGroup();
      expect(subcategoryGroup.$('label').getText()).toBe('Subcategory');
      expect(subcategoryGroup.$('.ag-smart-select').isDisplayed()).toBe(true);
    });

    it('should contain 24 Available To agencies', function() {
      $('#purchasingOrganization').click();
      var options =  element(by.css('[data-id="purchasingOrganization"]')).all(by.tagName('i'));
      options.count()
      expect(options.count()).toEqual(24);
      $('#purchasingOrganization').click();
    });


    it('should have the right Available To (My Agency) options in the right order', function() {
      var agencyGroup = sfWidget.getMyAgencyInputGroup();
      var button = sfWidget.getDropdownButton(agencyGroup);
      var options = sfWidget.getOptionsForDropdown(agencyGroup, true);
      button.click();
      options.map(function(option) {
        return option.getText();
      }).then(function(optionsList) {
        for (var i = 0; i < optionsList.length; i++) {
          optionsList[i] = optionsList[i].split('(')[0].trim();
        }
        expect(optionsList).toEqual([
          'Dept of Defense',
          'Air Force',
          'Army',
          'DHA',
          'Navy',
          'Other DoD Organization',
          'Federal Agencies',
          'DoC',
          'DoE',
          'DHS',
          'DoI',
          'DoJ',
          'DoL',
          'DoT',
          'Ed',
          'EPA',
          'GSA',
          'HHS',
          'HUD',
          'IRS',
          'NASA',
          'State',
          'Treasury',
          'USDA',
          'VA',
          'Other Federal Agency'
        ]);
      });
      button.click();
    });

    it('should filter by My Agency', function() {
      $('#purchasingOrganization').click();
      element(by.css('[data-id="purchasingOrganization"]')).all(by.tagName('i')).get(0).click();
      expect($('#purchasingOrganization').all(by.tagName('span')).get(0).getText()).toEqual('Air Force');
    });

    it('should filter by Category', function() {
      $('#ProductCategories').click();
     element(by.css('[data-id="ProductCategories"]')).all(by.tagName('i')).get(0).click();
      element(by.css('[data-id="ProductCategories"]')).all(by.tagName('i')).get(1).click();
      $('#ProductCategories').click();
      expect($('#ProductCategories').all(by.tagName('span')).get(0).getText()).toEqual('Facilities and Construction, Human Capital, Office Management');
    });

    it('should filter by Subcategory', function() {
      $('#productSubcategory').click();
      element(by.css('[data-id="productSubcategory"]')).all(by.tagName('i')).get(0).click();
      $('#productSubcategory').click();
      expect($('#productSubcategory').all(by.tagName('span')).get(0).getText()).toEqual('Construction Related Materials, Office Management Products');
    });
   });

  describe('Hallways Articles', function () {
    var featuredBlock = $('.featured-article-panel'),
    bkBtn = $('.back-to-hallway');
    articleTitle = $('#article-label');
    page.tileArticleList = $$('.article-tile');
    page.articles = element.all(by.repeater('article in articles track by article.id'));
    page.featuredArticles = element.all(by.repeater('article in articles | limitTo : 3 track by article.id'));
    page.tileArticles = element.all(by.repeater('article in articles | limitTo : articles.length : 3 track by article.id'));
    page.articleContainer = browser.element(by.css('.article-page'));
    page.articleAuthor = page.articleContainer.$('#article-info');
  //  page.commentsForm = page.articleContainer.$('.show-comments').$$('form');
    page.editForm = page.articleContainer.element(by.css('[name="commentEditForm"]'));
    page.addCommentsForm = page.articleContainer.$('.comment-form');
    page.commentsList = browser.element.all(by.repeater('comment in comments'));
    page.editComment = browser.element(by.model('commentCopy.body'));
    page.addComment = browser.element(by.model('newComment.body'));
    page.articleLinks = page.articleContainer.$('#article-links');
    page.nextArticle = page.articleLinks.$('.next-article-link');
    page.previousArticle = page.articleLinks.$('.previous-article-link');
    page.addCommentsEditor = page.articleContainer.$('.comment-form .rich-text-editor .editor');
    page.editCommentsEditor = page.editForm.element(by.css('.rich-text-editor .editor'));

    page.voting = page.articleContainer.$('.voting-article');

    it('should get all articles', function () {
      browser.get('/app/#/gateway/administrative-support');
      expect(page.articles.count()).toBeGreaterThan(0);
    });

    it('should have all featured articles tiles', function () {
      expect(page.featuredArticles.count()).toBeGreaterThan(0);
    });

    it('should have article tiles', function () {
      page.tileArticleList.count().then(function (count) {
        expect(count).toBeGreaterThan(0);
      });
    });

    it('shouldn\'t display dulpicate items in featured articles and articles', function() {
      var eleTitle;
      page.featuredArticles.count().then(function(countFA) {
        if(countFA > 0) {
          page.articles.count().then(function(count) {
            page.featuredArticles.each(function(ele, index) {
              if(countFA > 2 && index == 0) {
                eleTitle = ele.getText();
                expect(eleTitle).not.toEqual(page.articles.get(3).getText());
              }
              if(countFA > 3 && index == 1) {
                eleTitle = ele.getText();
                expect(eleTitle).not.toEqual(page.articles.get(4).getText());
              }
              if(countFA > 4 && index == 2) {
                eleTitle = ele.getText();
                expect(eleTitle).not.toEqual(page.articles.get(5).getText());
              }
            });
          });
        }
      });
    });

    it('should navigate to the first featured article', function () {
      page.featuredArticles.count().then(function(count) {
        if (count > 0) {
          var item = page.featuredArticles.get(0);
          item.$('.article-label').getText().then(function(title) {
            title = title.replace('...', '').trim();
            item.$('a').click();
            articleTitle.getText().then(function(text) {
              expect(text.toLowerCase()).toContain(title.toLowerCase());
            });

            bkBtn.click();
          });
        }
      });
    });

    it('should navigate to the 2nd featured article', function () {
     page.featuredArticles.count().then(function(count) {
        if (count > 1) {
          var item = page.featuredArticles.get(1);
          item.$('.article-label').getText().then(function(title) {
            title = title.replace('...', '').trim();
            item.$('a').click();
            articleTitle.getText().then(function(text) {
              expect(text.toLowerCase()).toContain(title.toLowerCase());
            });

            bkBtn.click();
          });
        }
      });
    });

    it('should navigate to the 3rd featured article', function () {
      page.featuredArticles.count().then(function(count) {
        if (count > 2) {
          var item = page.featuredArticles.get(2);
          item.$('.article-label').getText().then(function(title) {
            title = title.replace('...', '').trim();
            item.$('a').click();
            articleTitle.getText().then(function(text) {
              expect(text.toLowerCase()).toContain(title.toLowerCase());
            });

          });
        }
      });
    });


    it('should navigate back to hallway', function() {
      expect(page.articleContainer.$('a.back-to-hallway').getText()).toEqual('Back to hallway homepage');
      page.articleContainer.$('a.back-to-hallway').click();
      expect(browser.getLocationAbsUrl()).toContain('/gateway/administrative-support');
      page.featuredArticles.get(0).click();
    });

    it('should navigate to tile articles', function () {
      browser.get('/app/#/gateway/administrative-support');
      page.tileArticles.count().then(function(count) {
        if (count > 0) {
          page.tileArticles.get(0).$('.article-label').getText().then(function(title) {
            title = title.replace('...', '').trim();
            page.tileArticles.get(0).$('a').click();
            articleTitle.getText().then(function(text) {
                expect(text.toLowerCase()).toContain(title.toLowerCase());
            });
            bkBtn.click();

          });
        }
      });
    });
    it('should navigate to the Individual article', function() {
    //  browser.get('/app/#/gateway/administrative-support');
      page.featuredArticles.get(0).$('a').click();
      expect(page.articleContainer.$('#article-label').isDisplayed()).toBe(true);
    });

    it('should have the Next Article navigation link', function() {
      expect(page.nextArticle.getText()).toEqual('Next Article');
      expect(page.nextArticle.$('span').getAttribute('class')).toContain('fa-chevron-right');
    });

    it('should have the Previous Article navigation link', function() {
      page.nextArticle.click();
      expect(page.previousArticle.getText()).toEqual('Previous Article');
      expect(page.previousArticle.$('span').getAttribute('class')).toContain('fa-chevron-left');
      page.previousArticle.click();
    });

    it('should have the article description', function() {
      expect(page.articleContainer.$('#article-body').isDisplayed()).toBe(true);
      //expect(page.articleContainer.$('.author-article-description .img-thumbnail').isDisplayed()).toBe(true);
      //expect(page.articleContainer.$('.author-article-description .block-quote').isDisplayed()).toBe(true);
    });

    xit('should expand / collapse to show article details', function() {
      page.articleContainer.$('#articleBody a').click();
      expect(page.articleContainer.$('#articleBody a').getText()).toEqual('Less');
      page.articleContainer.$('#articleBody a').click();
      expect(page.articleContainer.$('#articleBody a').getText()).toEqual('More');
    });

    if (!browser.params.publicUser) {
      it('should have voting capability', function () {
      //  browser.get('/app/#/gateway/administrative-support');
        var vote = page.voting.$('.vote-up-down-widget');
        expect(vote.isPresent()).toBe(true);
        expect(vote.$('.vote-comment').getText()).toEqual('Found this helpful');
      });

      it('should vote the article up', function () {
        var vote = page.voting.$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-up');
        vote.$('div.vote-count').getText().then(function (count) {
          voteUp.click();
          expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');
          expect(vote.$('div.vote-count').getText()).toEqual(((count * 1) + 1).toString());
        });
      });

      it('should remember the up vote', function () {
        browser.refresh();
        var vote = page.voting.$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-up');
        expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');

      });

      it('should cancel the up vote on the article', function () {
        var vote = page.voting.$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
        });
      });

      it('should vote the article down', function () {
        var vote = page.voting.$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
        })
      });

      it('should remember the down vote', function () {
        browser.refresh();
        var vote = page.voting.$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-down');
        expect(voteUp.$('span.fa-thumbs-down').getAttribute('class')).toContain('active');
      });

      it('should cancel the down vote on the article', function () {
        var vote = page.voting.$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a[ng-click="vote(\'up\')"]').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) + 1).toString());
        });
      });

      it('should show the article author details', function() {
        expect(page.articleAuthor.isDisplayed()).toBe(true);
        expect(page.articleAuthor.$('.img-circle').isDisplayed()).toBe(true);
        expect(page.articleAuthor.$('.article-author-name').isDisplayed()).toBe(true);
        expect(page.articleAuthor.$('.article-author-jobTitle').isDisplayed()).toBe(true);
        expect(page.articleAuthor.$('#button-follow').isDisplayed()).toBe(true);
        expect(page.articleAuthor.$('#article-post-info').isDisplayed()).toBe(true);
      });

        it('should follow / unfollow the article author', function() {
          expect(page.articleAuthor.$('#button-follow span').getText()).toEqual('Follow');
          page.articleAuthor.$('#button-follow').click();
          expect(page.articleAuthor.$('#button-follow span').getText()).toEqual('Unfollow');
          page.articleAuthor.$('#button-follow').click();
        });

      it('should display comment form', function() {
        expect(page.articleContainer.$('.comment-form').isDisplayed()).toBe(true);
      });

      it('should add a comment', function() {
        page.commentsList.count().then(function(startCount) {
          page.addCommentsEditor.sendKeys('Adding Test New Comment');
          page.addCommentsForm.$('.submit-comment').click();
          page.commentsList.count().then(function(endCount) {
            expect(endCount).toBe(startCount+1);
          });
        });

      });

      it('should display comment author name', function(){
        expect(page.commentsList.last().$('.topic-author-name').isDisplayed()).toBe(true);
        expect(page.commentsList.last().$('.topic-author-name').getText()).toContain('e2eUser');
      });

      it('should display comment author picture', function(){
        expect(page.commentsList.last().$('.img-circle').isDisplayed()).toBe(true);
      });

      it('should follow / unfollow the comment author', function() {
        expect(page.commentsList.last().$('#button-follow span').getText()).toEqual('Follow');
        page.commentsList.last().$('#button-follow').click();
        expect(page.commentsList.last().$('#button-follow span').getText()).toEqual('Unfollow');
        page.commentsList.last().$('#button-follow').click();
      });

      it('should vote the comment down', function () {
        var vote = page.commentsList.last().$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
        })
      });

      it('should remember the comment down vote', function () {
        browser.refresh();
        var vote = page.commentsList.last().$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-down');
        expect(voteUp.$('span.fa-thumbs-down').getAttribute('class')).toContain('active');
      });

      it('should cancel the down vote on the comment', function () {
        var vote = page.commentsList.last().$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a[ng-click="vote(\'up\')"]').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) + 1).toString());
        });
      });

      it('should edit a comment', function() {
        page.commentsList.last().$('a.edit-comment').click();
        expect(page.editForm.isDisplayed()).toBe(true);
        page.editCommentsEditor.clear();
        page.editCommentsEditor.sendKeys('Test edited comment');
        page.editForm.$('.submit-comment').click();
        expect(page.editForm.isPresent()).toBe(false);
        var commentBody = page.commentsList.last().$('.comment-body').getText();
        expect(commentBody).toEqual('Test edited comment');
      });

      it('should delete a comment from the comments list', function() {
        page.commentsList.count().then(function(startCount) {
          page.commentsList.last().$('a.delete-comment').click();
          page.commentsList.count().then(function(endCount) {
            expect(endCount).toBe(startCount-1);
          });
        });
      });
    }

  });
  if (browser.params.publicUser) {

    describe('Public User Restrictions', function () {
      it('should not have the \'View Prices Paid\' button', function () {
        browser.get('/app/#/gateway/administrative-support');
        $$('hw-resources-block a').map(function (elm) {
          return elm.getText();
        }).then(function (result) {
          for (var i = 0; i < result.length; i++) {
            expect(result[i]).not.toContain('View Prices Paid');
          }
        });
      });
      it('should not display the Community widget', function () {
        expect(page.communitiesWidget.isPresent()).toBe(false);
      });

      it('should show  Events Feed', function () {
        expect(element(by.css('ag-feed .feed-title-banner')).getText()).toEqual('EVENTS');
      });

      it('should show NewsFeed', function () {
        expect(element(by.css('ag-news-feed .feed-title-banner')).getText()).toEqual('NEWS');
      });
    });
  }

  hallwaysTax.forEach(function (hallway, index) {
    var h = Object.keys(hallway);

    it('should load the Article page for ' + h , function() {
      if (index === 0) {
        page.hallwaysMenu.click();
        page.hallwaysLinks.last().$('a').click();
      }

      page.hallwaysMenu.click();

      page.hallwaysLinks.get(index).$('a').getText().then(function(title) {
        page.hallwaysLinks.get(index).$('a').click();
        expect(browser.getCurrentUrl()).toContain('/gateway/' + h);
        expect(page.hallwaysMenu.getText()).toEqual(title);

        page.tileArticles.count().then(function(count) {
        if (count > 0) {
          page.tileArticles.get(0).$('.article-label').getText().then(function(title) {
            title = title.replace('...', '').trim();
            page.tileArticles.get(0).$('a').click();
            articleTitle.getText().then(function(text) {
                expect(text.toLowerCase()).toContain(title.toLowerCase());
            });
         });
        }
       });
      });
    });
  });
});
