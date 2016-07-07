fdescribe('Communities', function () {
  if (!browser.params.publicUser) {

    var page = {};
    var element = browser.element;
    page.menu = browser.element.all(by.css('nav.communities-list ul li'));
    page.title = $('h1.DINCondensedBold');
    page.topics = browser.element.all(by.repeater('topic in pageTopics'));
    page.addTopic = $('#comunity-add-topic-link');
    page.viewAll = $('.profile-view-all a');
    page.accordions = element.all(by.css('div.accordion-light'));

    beforeAll(function() {
      browser.get('/app/#/communities');
    });

    it('should have a title', function () {
      browser.get(browser.baseUrl + '/app/#/communities');
      expect(page.title.getText()).toEqual('MY COMMUNITY');
    });

    fdescribe('Pagination', function() {
      page.pagination = browser.element(by.css('.pagination'));
      page.pageSizeContainer = browser.element(by.css('.page-size'));
      page.pageSizes = browser.element.all(by.repeater('size in pageSizes'));
      page.pages = browser.element.all(by.repeater('page in pages'));
      page.paginations = $$('.pagination');
      page.topPagination = $('#topics-top-pagination');
      page.bottomPagination = $('.bottom-pagination');
      page.tPages = page.topPagination.$$('li.page-item');
      page.bPages = page.bottomPagination.$$('li.page-item');

      it('should update the pagination at both places', function() {
        page.tPages.get(1).$('a').click();
        expect(page.tPages.get(1).getAttribute('class')).toContain('active');
        expect(page.bPages.get(1).getAttribute('class')).toContain('active');
      });

      it('should have the same page count on both places', function() {
        page.pageSizes.get(2).$('a').click();
        page.tPages.count().then(function(count) {
          expect(page.bPages.count()).toEqual(count);
        });
      });

      it('should have pagination', function() {
        expect(page.pagination.isDisplayed()).toBe(true);
      });

      it('should display 10 results', function() {
        page.pageSizes.get(0).$('a').click();
        expect(page.topics.count()).toEqual(10);
      });

      it('should display 25 results', function() {
        page.pageSizes.get(1).$('a').click();
        expect(page.topics.count()).toEqual(25);
      });

      it('should display 50 results', function() {
        page.pageSizes.get(2).$('a').click();
        expect(page.topics.count()).not.toBeGreaterThan(50);
      });

      it('should display 100 results', function() {
        page.pageSizes.get(3).$('a').click();
        expect(page.topics.count()).not.toBeGreaterThan(100);
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
    });

    describe('Profile Management', function () {
      page.screenName = $('#my-screen-name');
      page.jobTitle = $('div.job-title');
      page.agency = $('div.agency');
      page.editProfile = $('.edit-profile');
      page.certificationList = browser.element.all(by.repeater('profileCertificate in profile.certifications track by $index'));

      it('should show the current user profile in the left column', function () {
        expect($('#ag-user-profile').isDisplayed()).toBe(true);
      });

      it('should display the \'My Info\' modal', function () {
        page.editProfile.click();
        expect($('div.user-profile-form').isDisplayed()).toBe(true);
        expect($('div.user-profile-form h2').getText()).toEqual('My Info');
      });

      it('should close the \'My Info\' modal when cancel is clicked', function () {
        $('#cancel-user-profile-form').click();
        expect($('div.user-profile-form').isPresent()).toBe(false);
      });

      it('should validate profile form', function () {
        page.editProfile.click();
        $('#FullName').clear();
        expect($('#submit-user-profile-form').getAttribute('disabled')).toBe('true');
      });

      it('should set the user screen name', function () {
        $('#FullName').sendKeys('e2eUser');
        expect($('#submit-user-profile-form').getAttribute('disabled')).toBe(null);
        $('#submit-user-profile-form').click();
        expect(page.screenName.getText()).toEqual('e2eUser');
      });

      it('should show the user screen name in the navbar', function () {
        expect($('#navbar-screen-name').getText()).toEqual('Hi, e2eUser');
      });

      it('should update the user screen name', function () {
        page.editProfile.click();
        $('#FullName').clear();
        $('#FullName').sendKeys('e2eUser');
        $('#submit-user-profile-form').click();
        expect(page.screenName.getText()).toEqual('e2eUser');
        expect($('#navbar-screen-name').getText()).toEqual('Hi, e2eUser');
      });

      it('should set the user JobTitle', function () {
        page.editProfile.click();
        $('#JobTitle').clear();
        $('#JobTitle').sendKeys('Developer');
        $('#submit-user-profile-form').click();
        expect($('div.job-title').getText()).toEqual('Developer');
      });

      it('should update the user Job Title', function () {
        page.editProfile.click();
        $('#JobTitle').clear();
        $('#JobTitle').sendKeys('E2E Developer');
        $('#submit-user-profile-form').click();
        expect($('div.job-title').getText()).toEqual('E2E Developer');
      });

      it('should have the user Organization Name disabled', function () {
        page.editProfile.click();
        expect($('#OrgName').getAttribute('disabled')).toBe('true');
        $('#cancel-user-profile-form').click();
      });

      it('should have the user email disabled', function () {
        page.editProfile.click();
        expect($('#email-address').getAttribute('disabled')).toBe('true');
        $('#cancel-user-profile-form').click();
      });

      it('should add user certifications', function() {
        page.editProfile.click();
        $('#certifications').sendKeys('Angular');
        $('.btn-certification').click();
        expect(page.certificationList.count()).toBeGreaterThan(0);
        $('#submit-user-profile-form').click();
      });

      it('should show typeahead options for certifications', function() {
        page.editProfile.click();
        var certifications = $('div.user-profile-certifications ul.typeahead');
        $('#certifications').sendKeys('Ang');
        expect(certifications.isDisplayed()).toBe(true);
        certifications.$$('li a').each(function(certification) {
          expect(certification.getText()).toContain('Ang');
        });
      });

      it('should delete the user certifications from the list', function() {
        page.certificationList.get(0).click();
        expect(page.certificationList.count()).toBe(0);
        $('#submit-user-profile-form').click();
      });
    });

    describe('Groups Navigation', function () {
      it('should have a menu', function () {
        expect(page.menu.count()).not.toEqual(0);
      });

      it('should navigate to each group', function () {
        page.menu.count().then(function (count) {
          for (var i = 0; i < count; i++) {
            var item = page.menu.get(i);
            item.$('a').click();
            item.getText(i).then(function (text) {
              expect($('h2.community-heading').getText()).toEqual(text);
            });
          }
        });
      });

      it('should view all topics', function () {
        var cActivity = $('#communities-header-row h2');
        var viewAll = $('.profile-view-all a');
        page.menu.get(0).$('a').click();
        viewAll.click();
        expect(cActivity.getText()).toEqual('Community Activity');

        page.menu.get(0).$('a').click();
        page.menu.get(1).$('a').click();
        page.menu.get(2).$('a').click();
        viewAll.click();
        expect(cActivity.getText()).toEqual('Community Activity');
      });

      it('should keep the Group name in sync with the current Group when creating a new topic and switching groups using the Groups Menu', function () {
        page.viewAll.click();
        page.addTopic.click();
        var groupName = browser.element(by.model('newTopic.community'));
        expect(groupName.getText()).toEqual('Select Community... ');

        page.menu.get(0).$('a').click();
        page.menu.get(0).getText().then(function (name) {
          expect(groupName.getText()).toEqual(name + ' ');
        });

        page.menu.get(1).$('a').click();
        page.menu.get(1).getText().then(function (name) {
          expect(groupName.getText()).toEqual(name + ' ');
        });

        page.menu.get(2).$('a').click();
        page.menu.get(2).getText().then(function (name) {
          expect(groupName.getText()).toEqual(name + ' ');
        });
      });

      it('should keep the Group name in sync with the current group when creating a topic and the group is changed from My Groups', function () {
        var groupName = browser.element(by.model('newTopic.community'));
        page.menu.get(0).$('a').click();
        $('button.follow-group').click();
        page.menu.get(1).$('a').click();
        page.accordions.get(1).$('header').click();
        page.addTopic.click();
        $('#my-groups li:first-child a').click();
        $('#my-groups li:first-child a').getText().then(function (name) {
          expect(groupName.getText()).toEqual(name + ' ');
        });
        ;
        $('button.follow-group').click();
      });

      it('should navigate to the topic Group when the Group name is clicked', function () {
        page.viewAll.click();
        var groupLink = page.topics.get(0).$('a.topic-group-link');
        groupLink.getText(function (name) {
          groupLink.click();
          expect($('h2.community-heading').getText()).toEqual(name);
        });
      });

      it('should navigate to the Group when group name is clicked while viewing single topic', function () {
        browser.get('/app/#');
        //Navigate to first topic
        $$('.communities-widget ul li h4 a').first().click();
        //Now click 1st group name
        page.menu.get(0).$('a').click();

        //Verify that the page is showing group topics
        $('h2.community-heading').getText().then(function (headerText) {
          expect(page.menu.get(0).$('a').getText()).toEqual(headerText);
        });
      });

      it('should look same as profile picture in user topics, comments, connection finder user smaller picture ', function() {
        var imgElements = $$('.picture img');
        expect(imgElements.get(0).isPresent()).toBe(true);
        imgElements.get(0).getSize().then(function(eleSize){
          expect(eleSize.width).toBeGreaterThan(63);
          expect(eleSize.height).toEqual(64);
        });
        //checking of profile picture in connection finder 
        page.addPeople.$('.user-search-modal').click();
        expect($('.modal-content').isDisplayed()).toBe(true);
        $('#searchConnections').sendKeys('a');
        expect($('.modal-content').$$('.picture img').count()).toBeGreaterThan(0);
        $('.modal-content').$$('.picture img').get(0).getSize().then(function(eleSize){
          expect(eleSize.width).toBeGreaterThan(63);
          expect(eleSize.height).toEqual(64);
        });
        $('div.modal-title button.close').click();
        expect($('.modal-content').isPresent()).toBe(false);
      });  
    });

    describe('Creating Topics', function () {
      page.topicForm = $('#communities-new-topic');
      page.topicTitle = element(by.model('newTopic.label'));
      page.topicGroup = $('#newTopicCommunity');;
      page.topicBody = element(by.model('newTopic.body'));
      page.cancelTopic = $('#cancel-new-topic');
      page.submitTopic = $('#submit-new-topic');
      page.groupOptions = $$('form ul.dropdown-menu li a');
      var editor = $('#newTopicContent.rich-text-editor .editor');
      var bold = $('#newTopicContent.rich-text-editor .bold-control');
      var underline = $('#newTopicContent.rich-text-editor .underline-control');
      var italic = $('#newTopicContent.rich-text-editor .italics-control');
      var ol = $('#newTopicContent.rich-text-editor .ordered-list-control');
      var ul = $('#newTopicContent.rich-text-editor .unordered-list-control');
      var hyperlink = $('#newTopicContent.rich-text-editor .hyperlink-control');
      var wysiwyg = $('#newTopicContent.rich-text-editor');
      var time = Date.now();

      it('should open the new topic form', function () {
        browser.get('/app/#/communities');
        page.viewAll.click();
        $('#comunity-add-topic-link').click();
        expect(page.topicForm.isDisplayed()).toBe(true);
        expect(page.topicTitle.isDisplayed()).toBe(true);
        expect(wysiwyg.isDisplayed()).toBe(true);
        expect(page.submitTopic.isDisplayed()).toBe(true);
        expect(page.cancelTopic.isDisplayed()).toBe(true);
        expect(page.topicForm.$('h4').getText()).toEqual('New Group Topic');
      });

      it('should require a topic Group', function () {
        expect(page.submitTopic.getAttribute('disabled')).toEqual('true');
        expect(page.topicGroup.getAttribute('class')).toContain('ng-invalid');
        page.topicGroup.click();
        page.groupOptions.last().click();
        expect(page.topicGroup.getAttribute('class')).toContain('ng-valid');
      });

      it('should require a topic title', function () {
        expect(page.submitTopic.getAttribute('disabled')).toEqual('true');
        expect(page.topicTitle.getAttribute('class')).toContain('ng-invalid');
        page.topicTitle.sendKeys('E2E: Test Topic Title');
        expect(page.topicTitle.getAttribute('class')).toContain('ng-valid');
      });

      it('should require a topic body', function () {
        expect(page.submitTopic.getAttribute('disabled')).toEqual('true');
        expect(page.topicBody.getAttribute('class')).toContain('ng-invalid');
        editor.sendKeys('E2E: Test Topic body text');
        expect(page.topicBody.getAttribute('class')).toContain('ng-valid');
        expect(page.submitTopic.getAttribute('disabled')).toEqual(null);
      });

      it('should cancel topic creation', function () {
        page.cancelTopic.click();
        expect(page.topicForm.isDisplayed()).toBe(false);
        $('#comunity-add-topic-link').click();
        expect(page.submitTopic.getAttribute('disabled')).toBe('true');
      });

      it('should make text bold', function() {
        editor.clear();
        bold.click();
        editor.sendKeys('Bold Text');
        expect(editor.getInnerHtml()).toContain('<b>Bold Text</b>');
      });

      it('should make text italics', function() {
        editor.clear();
        italic.click();
        editor.sendKeys('Italics Text');
        expect(editor.getInnerHtml()).toContain('<i>Italics Text</i>');
      });

      it('should make text underline', function() {
        editor.clear();
        underline.click();
        editor.sendKeys('Underline Text');
        expect(editor.getInnerHtml()).toContain('<u>Underline Text</u>');
      });

      it('should make text Ordered List', function() {
        editor.clear();
        ol.click();
        editor.sendKeys('List Item 1');
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys('List Item 2');
        editor.sendKeys(protractor.Key.ENTER);
        expect(editor.getInnerHtml()).toContain('<ol>');
        expect(editor.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(editor.getInnerHtml()).toContain('<li>List Item 2</li>');
      });

      it('should make text Unordered List', function() {
        editor.clear();
        ul.click();
        editor.sendKeys('List Item 1');
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys('List Item 2');
        editor.sendKeys(protractor.Key.ENTER);
        expect(editor.getInnerHtml()).toContain('<ul>');
        expect(editor.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(editor.getInnerHtml()).toContain('<li>List Item 2</li>');
      });

      xit('should create a hyperlink', function() {
        editor.clear();
        editor.sendKeys('Hyperlink Text');
        editor.sendKeys(protractor.Key.chord(protractor.Key.CONTROL, 'a'));
        hyperlink.click();
        var a = browser.switchTo().alert();
        a.sendKeys(browser.baseUrl);
        a.accept();
        browser.pause();
        expect(editor.getInnerHtml()).toContain('<a href="' + browser.baseUrl + '">' + browser.baseUrl + '</a>');
      });

      it('should submit new topic', function () {
        editor.clear();
        page.topicGroup.click();
        $$('ul.dropdown-menu li a').last().click();
        page.topicTitle.sendKeys('E2E: Test Topic Title ' + time);
        editor.click();
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ARROW_UP);
        editor.sendKeys(protractor.Key.ARROW_UP);
        editor.sendKeys(protractor.Key.ARROW_UP);
        editor.sendKeys(protractor.Key.ARROW_UP);
        editor.sendKeys(protractor.Key.ARROW_UP);
        bold.click();
        editor.sendKeys('Bold Text');
        editor.sendKeys(protractor.Key.ARROW_RIGHT);
        editor.sendKeys(protractor.Key.ENTER);
        italic.click();
        editor.sendKeys('Italics Text');
        editor.sendKeys(protractor.Key.ARROW_RIGHT);
        editor.sendKeys(protractor.Key.ENTER);
        //page.italic.click();
        underline.click();
        editor.sendKeys('Underline Text');
        editor.sendKeys(protractor.Key.ARROW_RIGHT);
        editor.sendKeys(protractor.Key.ENTER);
        //page.underline.click();
        ol.click();
        editor.sendKeys('List Item 1');
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys('List Item 2');
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ENTER);
        ul.click();
        editor.sendKeys('List Item 1');
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys('List Item 2');
        editor.sendKeys(protractor.Key.ENTER);
        editor.sendKeys(protractor.Key.ENTER);
        page.submitTopic.click();

        expect(page.topicForm.isDisplayed()).toBe(false);
      });

      it('should show new topic immediately at the top of the topics feed', function () {
        var bodyText = page.topics.get(0).$('div.body-text');
        expect(page.topics.get(0).$('h4.topic-title a').getText()).toEqual('E2E: Test Topic Title ' + time);
        expect(bodyText.getInnerHtml()).toContain('<b>Bold Text</b>');
        expect(bodyText.getInnerHtml()).toContain('<i>Italics Text</i>');
        expect(bodyText.getInnerHtml()).toContain('<u>Underline Text</u>');
        expect(bodyText.getInnerHtml()).toContain('<ol>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 2</li>');
        expect(bodyText.getInnerHtml()).toContain('<ul>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 2</li>');
      });
    });

    describe('Reply to Topic', function () {
      var replyCount = page.topics.get(0).element(by.binding('topic.comment_count'));
      page.replyTopic = page.topics.get(0).$('a.communities-reply-link');
      page.replyForm = page.topics.get(0).$('.comment-form');
      page.replyBody = element(by.model('newComment.body'));
      page.clearReply = page.replyForm.$('button.cancel-comment');
      page.submitReply = page.replyForm.$('button.submit-comment');
      page.editor = page.replyBody.$('.rich-text-editor .editor');
      page.bold = page.replyBody.$('.rich-text-editor .bold-control');
      page.underline = page.replyBody.$('.rich-text-editor .underline-control');
      page.italic = page.replyBody.$('.rich-text-editor .italics-control');
      page.ol = page.replyBody.$('.rich-text-editor .ordered-list-control');
      page.ul = page.replyBody.$('.rich-text-editor .unordered-list-control');
      page.hyperlink = page.replyBody.$('.rich-text-editor .hyperlink-control');
      page.commentsList = page.topics.get(0).all(by.repeater('comment in comments'));
      page.editForm = element(by.css('[name="commentEditForm"]'));
      page.editCommentsEditor = page.editForm.element(by.css('.rich-text-editor .editor'));

      it('should open the reply form', function () {
        page.replyTopic.click();
        expect(page.replyForm.isDisplayed()).toBe(true);
        expect(page.submitReply.isDisplayed()).toBe(true);
        expect(page.clearReply.isDisplayed()).toBe(true);
      });

      it('should require a reply body', function () {
        expect(page.replyBody.getAttribute('class')).toContain('ng-invalid');
        expect(page.submitReply.getAttribute('disabled')).toEqual('true');

        page.editor.sendKeys('E2E: Test Topic body text');

        expect(page.replyBody.getAttribute('class')).toContain('ng-valid');
        expect(page.submitReply.getAttribute('disabled')).toEqual(null);
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

      it('should clear the reply form', function () {
        page.clearReply.click();
        expect(page.editor.getInnerHtml()).toEqual('');
      });

      it('should submit a topic reply', function () {
        page.replyTopic.click();
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

        //expect(page.replyForm.isPresent()).toBe(false);

         page.commentsList.count().then(function(startCount) {
          page.submitReply.click();
          page.commentsList.count().then(function(endCount) {
            expect(endCount).toBe(startCount+1);
          });
        });
      });

      it('should immediately show the reply in the replies list', function () {
        var reply = page.topics.get(0).all(by.repeater('comment in comments')).last();
        var bodyText = reply.$('.comment-body');
        expect(bodyText.getInnerHtml()).toContain('<b>Bold Text</b>');
        expect(bodyText.getInnerHtml()).toContain('<i>Italics Text</i>');
        expect(bodyText.getInnerHtml()).toContain('<u>Underline Text</u>');
        expect(bodyText.getInnerHtml()).toContain('<ol>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 2</li>');
        expect(bodyText.getInnerHtml()).toContain('<ul>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 1</li>');
        expect(bodyText.getInnerHtml()).toContain('<li>List Item 2</li>');
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
        page.replyTopic.click();
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

      it('should reply second existing topic and after reply topic it shouldn\'t get to top of list', function() {
        var secondTopicReplyCount = page.topics.get(1).element(by.binding('topic.comment_count'));
        var firstTopicTitle = page.topics.get(0).$('.topic-title').getText()
        page.replySecondTopic = page.topics.get(1).$('a.communities-reply-link');
        page.replySecondForm = page.topics.get(1).$('.comment-form');
        page.replySecondBody = element(by.model('newComment.body'));
        page.clearSecondReply = page.replySecondForm.$('button.cancel-comment');
        page.submitSecondReply = page.replySecondForm.$('button.submit-comment');
        page.SecondTopiceditor = page.replySecondBody.$('.rich-text-editor .editor');
        page.SecondTopicCommentsList = page.topics.get(1).all(by.repeater('comment in comments'));

        page.replySecondTopic.click();
        page.SecondTopiceditor.clear();
        page.SecondTopiceditor.sendKeys('Test reply comment');
        page.SecondTopiceditor.sendKeys(protractor.Key.ENTER);

        //expect(page.replyForm.isPresent()).toBe(false);

        page.SecondTopicCommentsList.count().then(function(startCount) {
          page.submitSecondReply.click();
          page.SecondTopicCommentsList.count().then(function(endCount) {
            expect(endCount).toBe(startCount+1);
          });         
        });
        browser.navigate().refresh();
        expect(page.topics.get(0).$('.topic-title').getText()).toBe(firstTopicTitle);
      });

    });

    describe('Individual Topic', function () {
      var expander = page.topics.get(0).$('div.communities-expander a');
      it('should have a \'More\' link', function () {
        browser.refresh();
        page.viewAll.click();
        expect(expander.isDisplayed()).toBe(true);
        expect(expander.getText()).toEqual('More');
      });

      it('should expand to show details including replies', function () {
        expander.click();
        expect(expander.getText()).toEqual('Less');
        expect(page.topics.get(0).$('div.comments').isPresent()).toBe(true);
      });

      it('should collapse to hide details including replies', function () {
        expander.click();
        expect(expander.getText()).toEqual('More');
        expect(page.topics.get(0).$('div.comments').isPresent()).toBe(false);
      });
    });

    describe('Community Accordions', function () {

      it('should have two accordions', function() {
        browser.get('/app/#/communities');
        expect(page.accordions.count()).toEqual(2);
      });

      it('should have My connections', function () {
        expect(page.accordions.get(0).$('h4').getText()).toEqual('My Connections');
        expect(page.accordions.get(0).$('i.fa-minus-circle').isPresent()).toBe(true);
      });

      it('should have My Groups', function () {
        expect(page.accordions.get(1).$('h4').getText()).toEqual('My Groups');
        expect(page.accordions.get(1).$('i.fa-plus-circle').isPresent()).toBe(true);
      });

      it('should expand and collapse all accordions', function () {

        page.accordions.get(0).$('header').click();
        expect(page.accordions.get(0).$('.accordion-content').isPresent()).toBe(false);
        expect(page.accordions.get(0).$('i.fa-plus-circle').isPresent()).toBe(true);

        page.accordions.get(0).$('header').click();
        expect(page.accordions.get(0).$('.accordion-content').isDisplayed()).toBe(true);
        expect(page.accordions.get(0).$('i.fa-minus-circle').isPresent()).toBe(true);

        page.accordions.get(1).$('header').click();
        expect(page.accordions.get(1).$('.accordion-content').isDisplayed()).toBe(true);
        expect(page.accordions.get(1).$('i.fa-minus-circle').isPresent()).toBe(true);

        page.accordions.get(1).$('header').click();
        expect(page.accordions.get(1).$('.accordion-content').isPresent()).toBe(false);
        expect(page.accordions.get(1).$('i.fa-plus-circle').isPresent()).toBe(true);
      });
    });

    describe('My Connections and User Activity', function () {
      page.connections = browser.element.all(by.repeater('user in connections'));
      page.noConnections = $('div.no-connections-message');
      page.replies = $$('li.reply');
      page.comments = $$('li.comment');
      page.addPeople = page.accordions.get(0).$('.user-search-link');

      it('should show a no-connections message', function () {
        browser.get('/app/#/communities');
        expect(page.noConnections.isPresent()).toBe(true);
      });

      it('should display Add people button', function() {
        expect(page.addPeople.isDisplayed()).toBe(true);
        expect(page.addPeople.$('.user-search-modal').getText()).toEqual('Add People');
        expect(page.addPeople.$('.user-search-modal i').getAttribute('class')).toContain('fa-users');
      });

      it('should follow a user', function () {
        page.menu.get(1).$('a').click();
        var user = page.topics.get(0);
        user.$('button.follow-user').click();
        user.$('.topic-author-name').getText().then(function (name) {
          expect(page.noConnections.isPresent()).toBe(false);
          expect($('ul.my-connections-list').isDisplayed()).toBe(true);
          expect(page.connections.count()).toBe(1);
          expect(page.connections.get(0).$('a.user-link').getText()).toEqual(name);
        });
        expect(user.$('button.follow-user').getText()).toEqual('Unfollow');
      });

      it('should show "Unfollow" in the follow buttons under My Connections', function () {
        page.connections.count().then(function (count) {
          for (var i = 0; i < count; i++) {
            expect(page.connections.get(i).$('button.follow-user').getText()).toEqual('Unfollow');
          }
        });
      });

      it('should unfollow the first user', function () {
        page.connections.get(0).$('button.follow-user').click();
        expect(page.connections.count()).toBe(0);
      });

      it('should change the text in the follow button in the topics list to "Follow" when unfollowed', function () {
        var user = page.topics.get(0);
        expect(user.$('button.follow-user').getText()).toEqual('Follow');
      });

      it('should go to the "My Profile" page when name is clicked in User Profile', function () {
        var username = $('#my-screen-name');
        username.click();
        username.getText().then(function (name) {
          expect(browser.getLocationAbsUrl()).toContain('/communities/user/');
          expect($('h2.user-profile-name').getText()).toEqual(name);
        });

        var agency = $('#ag-user-profile .agency');
        agency.getText().then(function (ag) {
          expect($('#user-activity-agency').getText()).toEqual(ag);
        });

        var jobTitle = $('#ag-user-profile .job-title');
        jobTitle.getText().then(function (jt) {
          expect($('#user-activity-job-title').getText()).toEqual(jt);
        });
      });

      it('User smaller profile picture should look same as Profile picture in "My Profile" page ', function() {
        var groupList = $$('li.list-group-item');
        expect(groupList.count()).toBeGreaterThan(0);
        groupList.get(0).$('div.img-circle').getSize().then(function(eleSize){
          expect(eleSize.width).toBeGreaterThan(63);
          expect(eleSize.height).toEqual(64);
        });
      });  

      it('should load up my user profile when I navigate to /communities/user', function () {
        browser.get('/app/#/communities/user');
        expect(browser.getLocationAbsUrl()).toContain('/communities/user/');
      });

      it('should not be able to follow myself on my profile page', function () {
        expect($('.follow-user-button').isPresent()).toBe(false);
      });

      it('should show a mixture of topics, replies and comments in the feed', function () {
        var feedTopics = element.all(by.css('li.topic'));
        expect(feedTopics.count()).toBeGreaterThan(0);
        page.comments.count().then(function(count) {
          if (count > 0) {
            expect(page.comments.count()).toBeGreaterThan(0);
            expect(page.comments.get(0).$('.feed-item-type').getText()).toEqual('Comment');
          }
        });
        expect(page.replies.count()).toBeGreaterThan(0);
        expect(page.replies.get(0).$('.feed-item-type').getText()).toEqual('Reply');
      });

      it('should not show voting on comments', function () {
        page.comments.count().then(function(count) {
          if (count > 0) {
            expect(page.comments.get(0).$('.vote-up-down-widget').isPresent()).toBe(false);
          }
        });
      });

      it('should not show voting on Replies', function () {
        expect(page.replies.get(0).$('.vote-up-down-widget').isPresent()).toBe(false);
      });

      it('should not show Reply ability on comments', function () {
        page.comments.count().then(function(count) {
          if (count > 0) {
            expect(page.comments.get(0).$('.communities-reply-block').isPresent()).toBe(false);
          }
        });
      });

      it('should not show Reply ability on Replies', function () {
        expect(page.replies.get(0).$('.communities-reply-block').isPresent()).toBe(false);
      });

      it('should navigate to a specific Group from my profile page', function () {
        var comm = page.menu.get(1);
        comm.$('a').click();
        expect(browser.getLocationAbsUrl()).not.toContain('/communities/user/');
        expect(comm.$('a').getAttribute('class')).toContain('active');

        //Check that the details of the community are correct
        page.menu.get(1).getText().then(function (community) {
          expect($('h2.community-heading').getText()).toEqual(community);
        });
      });

      it('should go to a User\'s profile other than mine', function () {
        var user = page.topics.get(0).$('.topic-author-name a');

        user.getText().then(function (name) {
          user.click();
          expect(browser.getLocationAbsUrl()).toContain('/communities/user/');
          expect($('h2.user-profile-name').getText()).toEqual(name);
        });
      });

      it('should only load topics, comments and replies for the user profile being viewed', function () {
        var user = page.topics.get(0).$('.topic-author-name a');
        user.getText().then(function (name) {
          page.topics.count().then(function (count) {
            for (var i = 0; i < count; i++) {
              expect(page.topics.get(i).$('.topic-author-name a').getText()).toEqual(name);
            }
          });
        });
      });

      it('should differentiate replies to topics from comments', function() {
        var reply = page.replies.get(0);
        expect(reply.$('.feed-item-type').getText()).toEqual('Reply');
        expect(reply.$('h4.topic-title').getText()).toContain('RE:');
      });

      it('should change the text to  "Unfollow" on all Follow buttons on the page when the user is followed', function () {
        var buttons = browser.element.all(by.css('button.follow-user'));
        $('.follow-user-button').click();
        buttons.count().then(function (count) {
          for (var i = 0; i < count; i++) {
            expect(buttons.get(i).getText()).toEqual('Unfollow');
          }
        });
      });

      it('should change the text to  "Follow" on all Follow buttons on the page when the user is followed', function () {
        var buttons = browser.element.all(by.css('button.follow-user'));
        $('button.follow-user-button').click();
        buttons.count().then(function (count) {
          for (var i = 0; i < count; i++) {
            expect(buttons.get(i).getText()).toEqual('Follow');
          }
        });
      });

      it('should open to the actual topic when the title link is clicked on a reply', function() {
        var reply = page.replies.get(0);
        reply.$('h4.topic-title a').getText().then(function(title) {
          title = title.replace('RE:', '').trim();
          reply.$('h4.topic-title a').click();
          expect(browser.getLocationAbsUrl()).toContain('/communities/topic');
          expect($('li.topic h4.topic-title a').getText()).toEqual(title);
          browser.navigate().back();
        });
      });

      xit('should open to the actual Hallway Article when the title link is clicked on a comment', function() {
        //TODO: Addd comment to article and check it links back
      });

      xit('should open to the actual Statement of Work Document when the title link is clicked on a comment', function() {
        //TODO: Add comment to SOW Document and confirm it links back
      });
    });

    describe('User Search ', function () {
      page.userSearch = browser.element(by.css('.user-search-link button'));
      page.label = browser.element(by.css('.form-label strong'));
      page.userList = $('#user-list ul');
      page.input = browser.element(by.css('.user-search-input'));
      page.searchTerm = browser.element(by.model('searchText'));
      page.alertInfo = browser.element(by.css('.user-search-message'));

      page.users = browser.element.all(by.repeater('user in pageUsers'));
      var modal = browser.element(by.css('div.modal'));

      it('should have find connection link', function () {
        browser.get('/app/#/communities');
        expect(page.userSearch.isPresent()).toBe(true);
      });

      it('should open the user search modal', function () {
        page.userSearch.click();
        expect(modal.isDisplayed()).toBe(true);
        expect(page.alertInfo.isDisplayed()).toBe(true);
        expect(page.alertInfo.$('h3').isDisplayed()).toBe(true);
        expect(page.alertInfo.$('h3').getText()).toEqual('Welcome!');
      });

      it('should have the Modal Title and Label for the User Search', function () {
        page.modalTitle = browser.element(by.css('.modal-title h2'));
        expect(page.modalTitle.getText()).toEqual('Connections Finder');
        expect(page.label.getText()).toEqual('Search for connections');
      });

      it('should close the User Search Modal', function () {
        $('div.modal-title button.close').click();
        expect(modal.isPresent()).toBe(false);
      });

      it('should search for unknown search term', function () {
        var pagination = browser.element(by.css('.modal-footer ul.pagination'));
        page.userSearch.click();
        expect(page.alertInfo.isDisplayed()).toBe(true);
        page.searchTerm.sendKeys('unknownsearchtermsxyz');
        expect(page.alertInfo.isDisplayed()).toBe(true);
        expect(page.userList.isPresent()).toBe(false);
        expect(page.users.count()).toBe(0);
        expect(pagination.isPresent()).toBe(false);
      });

      it('should display no more than 15 items per page', function () {
        page.searchTerm.clear();
        page.searchTerm.sendKeys('a');
        expect(page.alertInfo.isPresent()).toBe(false);
        expect(page.users.count()).not.toBeGreaterThan(15);
      });

      it('should search by name', function () {
        page.searchTerm.clear();
        page.searchTerm.sendKeys('katie');
        expect(page.users.count()).toBeGreaterThan(0);
      });

      it('should follow a user in the results', function () {
        page.users.first().$('button.follow-user').click();
        expect(page.connections.count()).toBe(1);
      });

      it('should unfollow a user in the results', function () {
        page.users.first().$('button.follow-user').click();
        expect(page.noConnections.isDisplayed()).toBe(true);
      });

      it('should click on a user name in the results and see the user profile', function () {
        page.searchTerm.clear();
        page.searchTerm.sendKeys('katie');
        var user = page.users.first().$('a.user-search-screen-name');
        user.getText().then(function (name) {
          user.click();
          expect(browser.getLocationAbsUrl()).toContain('/communities/user/');
          expect($('h2.user-profile-name').getText()).toEqual(name);
          expect(modal.isPresent()).toBe(false);
        });
      });

      it('should  search by email', function () {
        page.userSearch.click();
        page.searchTerm.clear();
        page.searchTerm.sendKeys('e2euser');
        expect(page.users.count()).toBeGreaterThan(0);
      });

      it('should search by agency', function () {
        page.searchTerm.clear();
        page.searchTerm.sendKeys('general');
        expect(page.users.count()).toBeGreaterThan(0);
        $('.close').click();
      });
    });

    describe('Voting', function () {
      it('should have voting capability', function () {
        page.viewAll.click();
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        expect(vote.isPresent()).toBe(true);
        expect(vote.$('.vote-comment').getText()).toEqual('Found this helpful');
      });

      it('should vote the topic up', function () {
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-up');
        vote.$('div.vote-count').getText().then(function (count) {
          voteUp.click();
          expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');
          expect(vote.$('div.vote-count').getText()).toEqual(((count * 1) + 1).toString());
        });
      });

      it('should remember the up vote', function () {
        browser.refresh();
        page.viewAll.click();
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-up');
        expect(voteUp.$('span.fa-thumbs-up').getAttribute('class')).toContain('active');

      });

      it('should cancel the up vote on the topic', function () {
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
        });
      });

      it('should vote the topic down', function () {
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a.vote-down').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) - 1).toString());
        })
      });

      it('should remember the down vote', function () {
        browser.refresh();
        page.viewAll.click();
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        var voteUp = vote.$('a.vote-down');
        expect(voteUp.$('span.fa-thumbs-down').getAttribute('class')).toContain('active');
      });

      it('should cancel the down vote on the topic', function () {
        var vote = page.topics.get(0).$('.vote-up-down-widget');
        vote.$('div.vote-count').getText().then(function (votes) {
          vote.$('a[ng-click="vote(\'up\')"]').click();
          expect(vote.$('div.vote-count').getText()).toEqual(((votes * 1) + 1).toString());
        });
      });
    });
  }
  if (browser.params.publicUser) {
    describe('Public User Restrictions', function() {
      it('should not exist for public users', function() {
        browser.get('/app/#/communities');
        expect(browser.getLocationAbsUrl()).not.toContain('/app/#/communities');
      });
    });
  }
});
