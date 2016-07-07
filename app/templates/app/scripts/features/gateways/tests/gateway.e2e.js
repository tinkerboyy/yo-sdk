describe('Acquisition Gateway', function() {
  var element = browser.element;
  var page = {},
    hallwaysList  = [
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
    ].sort(),
    originalTimeout;

  page.hallwaysWidget = $('.hallways-nav');
  page.hallways = browser.element.all(by.repeater('hallway in hallways'));
  page.projects = browser.element.all(by.repeater('projectEntity in projects.data.collection'));
  page.eventsFeed = browser.element(by.id('events'));
  page.newsFeed = browser.element(by.id('news'));
  page.communitiesWidget = $('.communities-widget');
  page.feedsWidget = $('#events');
  page.resourceWidget = $('.resources');
  page.resources = element.all(by.repeater('resource in resources track by $index'));
  page.title = $('[title="Home"]');
  var topmenu = $$('#navbar .menu li a');
  var aboutmodal = $('#about-us');
  var exploremodal = $('#explore');
  var abtmodalclose = $('#about-us .close a');
  var expmodalclose = $('#explore .close a');
  var regularNavUsername = $('.navbar-nav a[ng-if="!publicUser"]');
  var publicUNavUsername = $('.navbar-nav span[ng-if="publicUser"]');
  //var hmpuserlink = $('#navbar .navbar-right a');
  var hmphelp = $('.navbar-nav a[template="scripts/components/directives/nav/help.dropdown.html"]');
  var hmpsignout = $('.navbar-nav a[ng-click="logout()"]');
  var signinModal = browser.element(by.css('.signin'));
  var publicSignin = $('.navbar-nav a[ng-click="promptLogin()"]');
  var faqNav = $('.navbar-nav a[href="/faq.php"]');
   page.signinActions = $$('.signin-actions button');
  //var hmpsignoutpage = $('#video .centerAbsolute h1');
  var path = require('path');
  var sfIndex = !browser.params.publicUser ? 1 : 0;
  var sowlIndex = !browser.params.publicUser ? 2 : 1;
  var tfhIndex = !browser.params.publicUser ? 1 : 0;
  var swlIndex = !browser.params.publicUser ? 4 : 1;

  var navigateBack = function() {
  browser.waitForAngular();
  browser.navigate().back();
  }

  beforeAll(function() {
    browser.get('/app/#/');
    $('body').allowAnimations(false);
  });

  describe('Project Center', function() {
    page.projectCenter = $('.project-center');
    page.tabs = page.projectCenter.$$('ul.nav-tabs li');
    page.addProject = $('button.btn-new-entity');
    page.cancelProjectForm = $$('form.project-entry div.actions a').get(0);
    page.submitProjectForm = $$('form.project-entry div.actions a').get(1);
    page.projectForm = $('form.project-entry');
    page.projectNameField = page.projectForm.element(by.model('entityCopy.name'));
    page.projectDateField = page.projectForm.element(by.model('entityCopy.due'));
    page.projectDescriptionField = page.projectForm.element(by.model('entityCopy.description'));
    page.projectNotesField = element(by.model('entityCopy.notes'));
    page.projects = element.all(by.repeater("projectEntity in projects.data.collection | filter: { status: '1' } | orderBy: '-created'"));
    page.addTask = $('.add-task');
    page.addTaskForm = $('form.task-entry');
    page.taskNameField = page.addTaskForm.element(by.model('entityCopy.name'));
    page.taskDueField = page.addTaskForm.element(by.model('entityCopy.due'));
    page.cancelTaskForm = $$('form.task-entry div.actions a').get(1);
    page.submitTaskForm = $$('form.task-entry div.actions a').get(2);
    page.tasks = element.all(by.repeater("entity in tasks.data.collection | filter: filter | orderBy: 'due'"));
    page.addEvent = $('.add-event');
    page.addEventForm = $('form.event-entry');
    page.cancelEventForm = $$('form.event-entry div.actions a').get(1);
    page.submitEventForm = $$('form.event-entry div.actions a').get(2);
    page.eventNameField = page.addEventForm.element(by.model('entityCopy.name'));
    page.eventStartDue = page.addEventForm.element(by.model('entityCopy.startDate'));
    page.eventEndDue = page.addEventForm.element(by.model('entityCopy.endDate'));
    page.eventStartTime = page.addEventForm.element(by.model('entityCopy.startTime'));
    page.eventEndTime = page.addEventForm.element(by.model('entityCopy.endTime'));
    page.formLocation = page.addEventForm.element(by.model('entityCopy.location'));
    page.formDescription = page.addEventForm.element(by.model('entityCopy.description'));
    page.formProjectID = page.addEventForm.element(by.model('entityCopy.projectId'));
    page.events = element.all(by.repeater("eventEntity in privateEvents.data.collection | filter: filter | orderBy: 'start_date'"));
    page.displayOptions = page.tasks.get(0).$('a.my-task-options');
    page.displayOptionsList = $$('div.popover ul.list-group li');
    page.displayEventEditOptions = page.events.get(0).$('a.options');
    page.displayEventEditOptionsList = $$('div.popover ul.list-group li');
    page.selectProject = element(by.model('entityCopy.projectId'));
    page.projectActions = page.projects.get(0).$('.accordion-header');
    page.projectOptions = page.projectActions.$('a.options');
    page.projectToggle = page.projectActions.$('a.accordion-toggle');
    page.projectOptionsList = $$('div.popover-content ul.list-group li a');
    page.addContent = $('.content-container');
    page.addContentOptions = page.addContent.$$('center a');
    page.projectFileNameField = element(by.model('fileEntity.label'));
    page.projectFileField = element(by.model('fileEntity.file'));
    page.submitFileUpload = $('#submit-file-upload');
    page.cancelFileUpload = $('#cancel-file-upload');
    page.projectFiles = element.all(by.repeater("projectContent in projectEntities.data.collection"));
    page.welcomeMessage =  $('.pcWelcome');
    page.welcomeMessageBtn = page.welcomeMessage.$('button.btn-new-entity');
    page.resourcesBlock = $('.resources');
    page.resourcesLink = page.resourcesBlock.$$('ag-accordion');
    page.projectExpandButton = page.projects.get(0).element(by.css('a[title="expand"]'));
    page.projectCollapseButton = page.projects.get(0).element(by.css('a[title="collapse"]'));
    page.eventExpandButton = page.events.get(0).element(by.css('a[title="expand"]'));
    page.eventCollapseButton = page.events.get(0).element(by.css('a[title="collapse"]'));
    page.solutions = element.all(by.repeater('solution in pageSolutions'));
    page.search = browser.element(by.model('moreSearch.search'));
    page.share = $('.ag-share > a');
    page.createProjFromEvent = $$('form.event-entry div.actions a').get(0);
    page.createProjectFromTask = $$('form.task-entry div.actions a').get(0);


    it('should have the Project Center widget', function() {
      expect(page.projectCenter.isDisplayed()).toBe(true);
    });

    it('should have the title', function() {
      expect(page.projectCenter.$('.title-banner').getText()).toBe('PROJECT CENTER');
      expect(page.projectCenter.$('p small').getText()).toBe('Build Your Acquisition');
    });

    it('should have the \'My Projects\', \'Tasks\' and \'Events\' tabs', function() {
      expect(page.tabs.count()).toBe(3);
      expect(page.tabs.get(0).getText()).toEqual('My Projects');
      expect(page.tabs.get(1).getText()).toEqual('My Tasks');
      expect(page.tabs.get(2).getText()).toEqual('My Events');
    });

    it('should have \'Projects\' as the default active tab', function() {
        expect(page.tabs.get(0).getAttribute('class')).toContain('active');
        expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
        expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');
    });

    describe('My Projects', function() {
      
      it('should show welcome message when the projects are empty', function() {
        expect(page.welcomeMessage.isDisplayed()).toBe(true);
        if (!browser.params.publicUser) {
          expect(page.welcomeMessage.getAttribute('class')).toContain('nonpublicWelcome');
        }
        if (browser.params.publicUser) {
          expect(page.welcomeMessage.getAttribute('class')).toContain('publicWelcome');
        }      
      });

      it('should open \'New Project\'', function() {
        page.addProject.click();
        expect(page.projectForm.isDisplayed()).toBe(true);
      });

      it('should validate the form', function() {
        expect(page.projectNameField.getAttribute('class')).toContain('ng-invalid');
        expect($('span.text-danger').isDisplayed()).toBe(true);
        expect($('span.text-danger').getText()).toEqual('Project name is required.');
        page.projectNameField.sendKeys('E2E: Test Project');
        expect(page.projectNameField.getAttribute('class')).toContain('ng-valid');
        expect($('span.text-danger').getText()).toBe('');
      });

      it('should close the form', function() {
        page.cancelProjectForm.click();
        expect(page.projectForm.isPresent()).toBe(false);
        expect(page.welcomeMessage.isDisplayed()).toBe(true);
      });

      it('should create \'New Project\'', function() {
        page.addProject.click();
        page.projectNameField.sendKeys('E2E: Test Project');
        page.projectDateField.click();
        $$('tbody tr td button').last().click();

        page.projectDescriptionField.sendKeys('E2E: Test Project description');
        page.projectNotesField.sendKeys('E2E: Test Project notes');

        //check that the modal closes on succesful submit
        page.submitProjectForm.click();
        expect(page.projectForm.isPresent()).toBe(false);

        //check that the new project shows in the listing
        expect(page.projects.count()).toBeGreaterThan(0);
        expect(page.welcomeMessage.isPresent()).toBe(false);
      });

      it('should expand project content', function(){
        expect((page.projectExpandButton).isPresent()).toBe(true);
        expect((page.projectExpandButton.$('.fa-expand')).isPresent()).toBe(true);
        expect((page.projects.get(0).$('.my-project-body')).isDisplayed()).toBe(false);
        page.projectExpandButton.click();
        expect((page.projects.get(0).$('.my-project-body')).isDisplayed()).toBe(true);
      });

      it('should collapse project content', function(){
        expect(page.projectCollapseButton.isPresent()).toBe(true);
        expect((page.projectCollapseButton.$('.fa-compress')).isPresent()).toBe(true);
        page.projectCollapseButton.click();
        expect((page.projects.get(0).$('.my-project-body')).isDisplayed()).toBe(false);
      });

      it('should edit project', function() {
        page.projectOptions.click();
        expect(page.projectOptionsList.get(0).getText()).toBe('Edit Project');
        expect(page.projectOptionsList.get(1).getText()).toBe('Remove Project');
        expect(page.projectOptionsList.get(2).getText()).toBe('Add Content');

        page.projectOptionsList.get(0).click();

        page.projectNameField.clear();
        page.projectNameField.sendKeys('E2E: Edit Test Project');
        page.projectDateField.click();

        page.projectDescriptionField.clear();
        page.projectDescriptionField.sendKeys('E2E: Test Project description');
        page.projectNotesField.clear();
        page.projectNotesField.sendKeys('E2E: Test Project notes');

        //check that the modal closes on succesful submit
        page.submitProjectForm.click();

        expect(page.projectForm.isPresent()).toBe(false);
        expect(page.projects.get(0).$('.accordion-header h5 a').getText()).toBe('E2E: Edit Test Project');
      });
  

      it('should display the \'Add Content\' menu', function() {
        page.projectOptions.click();
        page.projectOptionsList.get(2).click();

        expect($('.project-center .widget-header .content-menu').isDisplayed()).toBe(true);
        expect($('.project-center .widget-header .content-menu').getText()).toEqual('What type of content would you like to add to your project?');

        if (!browser.params.publicUser) {
          expect(page.addContentOptions.get(0).$('i.fa').getAttribute('class')).toContain('fa-upload');
          expect(page.addContentOptions.get(0).$('div.upload').getText()).toBe('File Upload');
        }

        if (browser.params.publicUser) {
          expect(page.addContentOptions.get(0).$('i.fa').getAttribute('class')).not.toContain('fa-upload');
        }

        expect(page.addContentOptions.get(sfIndex).$('i.fa').getAttribute('class')).toContain('fa-th-large');
        expect(page.addContentOptions.get(sfIndex).$('div.solutions-finder').getText()).toBe('Solutions Finder');

        expect(page.addContentOptions.get(sowlIndex).$('i.fa').getAttribute('class')).toContain('fa-bank');
        expect(page.addContentOptions.get(sowlIndex).$('div.statement').getText()).toBe('Statement of');
        expect(page.addContentOptions.get(sowlIndex).$('div.library').getText()).toBe('Work Library');
      });
     
      it('should close the \'Add Content\' menu', function() {
        element(by.css('[ng-click="popPage()"]')).click();
        expect($('.project-center .widget-header .content-menu').isPresent()).toBe(false);
      });

      if (!browser.params.publicUser) {
        it('should open the  add File content Form', function() {
          page.projectOptions.click();
          page.projectOptionsList.get(2).click();
          page.addContentOptions.get(0).click();
          expect($('div.modal form').isDisplayed()).toBe(true);
        });

        it('should validate the Add File Content form', function() {
          expect(page.projectFileNameField.getAttribute('class')).toContain('ng-invalid');
          expect(page.projectFileField.getAttribute('class')).toContain('ng-invalid');

          page.projectFileNameField.sendKeys('E2E: Test file name');
          expect(page.projectFileNameField.getAttribute('class')).toContain('ng-valid');

          var fileLocation = '../../../../pdf-test.pdf';
          var filePath = path.resolve(__dirname, fileLocation);

          page.projectFileField.sendKeys(filePath);
          expect(page.projectFileField.getAttribute('class')).toContain('ng-valid');
        });

        it('should cancel project file upload', function() {
          page.cancelFileUpload.click();
          expect($('div.modal-content').isPresent()).toBe(false);
          $('.fa-times').click();
        });

        xit('should upload a project file', function() {
          page.addContentOptions.get(0).click();
          page.projectFileNameField.sendKeys('E2E: Test file name');

          var fileLocation = '../../../../pdf-test.pdf';
          var filePath = path.resolve(__dirname, fileLocation);
          page.projectFileField.sendKeys(filePath);

          page.submitFileUpload.click();
          expect($('div.modal-content').isPresent()).toBe(false);
          $('.fa-times').click();
          expect(page.projectFiles.count()).toBeGreaterThan(0);
          expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual('E2E: Test file name');
        });
      }
      var solutionName = '';
      it('should open Solutions Finder to add content', function() {
        page.projectOptions.click();
        page.projectOptionsList.get(2).click();
        page.addContentOptions.get(sfIndex).click();
        expect(browser.getCurrentUrl()).toContain('/solutionsfinder');
      });

      it('should open the Solution \'Add to Project\' Dialog', function() {
        var openAdd = $$('div.solution-actions ul.dropdown-menu li a').first();
        page.solutions.get(0).$('a.solution-options').click();
        openAdd.click();
        expect($('div.add-to-project').isDisplayed()).toEqual(true);
      });

      it('should validate \'Add to project\' fields and submit Solution to project', function() {
        var projects = element.all(by.repeater("project in projects | filter: { status: '1' }"));
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
        var project = page.projects.first();
        page.projectExpandButton.click();
        expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual(solutionName);
        expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: Solution');

      });

      it('should open Statement of Work Library to add content', function() {
        page.projectOptions.click();
        page.projectOptionsList.get(2).click();        
        page.addContentOptions.get(sowlIndex).click();
        expect(browser.getCurrentUrl()).toContain('/sowl');
      });

      var searchUrl;
      it('should open the \'Add to Project\' Dialog for SOWL Search', function() {
        page.share.click();
        searchUrl = browser.getLocationAbsUrl();
        $('#share-add-to-project').click();
        expect($('div.add-to-project').isDisplayed()).toEqual(true);
        expect($('#share-popover').isPresent()).toBe(false);
      });

      it('should validate \'Add to project\' fields and submit SOWL search to project', function() {
        var name = browser.element(by.model('item.name'));
        var projects = browser.element.all(by.repeater("project in projects | filter: { status: '1' }"));
        expect(name.isPresent()).toBe(true);

        //Expect the submit button to be sdisabled
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual('true');

        name.sendKeys('E2E: Test SOW Search');
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual('true');

        projects.last().$('a').click();
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual(null);

        $('#add-to-project-submit').click();
      });

      it('should show the new SOWL search in the Project Center', function() {
        browser.get('/app/#');
        var project = page.projects.first();

        page.projectExpandButton.click();
        expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual('E2E: Test SOW Search');
        expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: SOWL Search');

      });

      it('should open Solutions Finder to add search content', function() {
          page.projectOptions.click();
          page.projectOptionsList.get(2).click();
          page.addContentOptions.get(sfIndex).click();

          expect(browser.getCurrentUrl()).toContain('/solutionsfinder');
      });

      it('should open the search \'Add to Project\' Dialog', function() {
        page.share.click();
        searchUrl = browser.getLocationAbsUrl();
        $('#share-add-to-project').click();
        expect($('div.add-to-project').isDisplayed()).toEqual(true);
        expect($('#share-popover').isPresent()).toBe(false);
      });
     
      it('should validate \'Add to project\' fields and submit Solution search to project', function() {
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
      });

      it('should show the new Solution search in the Project Center', function() {
        browser.get('/app/#');
        var project = page.projects.first();

        page.projectExpandButton.click();
        expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual('E2E: Test Solution Search');
        expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: Solutions Finder Search');

      });

      it('should open Statement of Work Library to add content', function() {
        page.projectOptions.click();
        page.projectOptionsList.get(2).click();        
        page.addContentOptions.get(sowlIndex).click();
        expect(browser.getCurrentUrl()).toContain('/sowl');
      });
        
      var sowlName = '';

      it('should open the SOWL \'Add to Project\' Dialog', function() {
        $('#sowl-clear-welcome').click();
        var sowl = element.all(by.repeater('result in pagedResults'));
        var sowlTitle = sowl.get(0).$('.sowTitle');
        sowlTitle.getText().then(function(text) {
          sowlName = text;
        });
        sowlTitle.click();
        element(by.css('a[ng-click="addToProject(document)"]')).click();
        expect($('div.add-to-project').isDisplayed()).toEqual(true);
      });

      it('should validate \'Add to project\' fields and submit SOWL document to project', function() {
        var projects = element.all(by.repeater("project in projects | filter: { status: '1' }"));
        var name = element(by.binding('itemName'));
        
        expect(name.getText()).toEqual(sowlName);

        //Expect the submit button to be sdisabled
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual('true');

        projects.last().$('a').click();
        expect($('#add-to-project-submit').getAttribute('disabled')).toEqual(null);

        $('#add-to-project-submit').click();
      });

      it('should show the SOWL document in the Project Center', function() {
        browser.get('/app/#/');
        var project = page.projects.first();
        page.projectExpandButton.click();
        expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual(sowlName);
        expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: SOW Document');
      });

      it('should delete a Solutions Finder content', function() {
        page.projectFiles.get(0).$('a.project-content-options').click();
        page.projectFiles.count().then(function(startCount) {
          $('div.popover ul li a').click();
           page.projectFiles.count().then(function(endCount) {
              expect(endCount).toBe(startCount-1);
           });
        });
      });

      it('should delete a Statement of Work Library Search', function() {
        page.projectFiles.get(0).$('a.project-content-options').click();
        page.projectFiles.count().then(function(startCount) {
          $('div.popover ul li a').click();
           page.projectFiles.count().then(function(endCount) {
              expect(endCount).toBe(startCount-1);
           });
        });
      });

      it('should delete a Solution Search', function() {
        page.projectFiles.get(0).$('a.project-content-options').click();
        page.projectFiles.count().then(function(startCount) {
          $('div.popover ul li a').click();
           page.projectFiles.count().then(function(endCount) {
              expect(endCount).toBe(startCount-1);
           });
        });
      });

      it('should delete a SOWL Document', function() {
        page.projectFiles.get(0).$('a.project-content-options').click();
        page.projectFiles.count().then(function(startCount) {
          $('div.popover ul li a').click();
           page.projectFiles.count().then(function(endCount) {
              expect(endCount).toBe(startCount-1);
           });
        });
      });
      
      if (!browser.params.publicUser) {
        xit('should delete a File content', function() {
          page.projectFiles.get(0).$('a.project-content-options').click();
          page.projectFiles.count().then(function(startCount) {
            $('div.popover ul li a').click();
             page.projectFiles.count().then(function(endCount) {
                expect(endCount).toBe(startCount-1);
             });
          });
        });
      }
    });
  
    describe('My Tasks', function() {
      it('should \'Add New Tasks\'', function() {
        page.tabs.get(1).$('a').click();
        expect(page.tabs.get(0).getAttribute('class')).not.toContain('active');
        expect(page.tabs.get(1).getAttribute('class')).toContain('active');
        expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');
      });

      it('should open \'New Task\' ', function() {
        page.addTask.click();
        expect(page.addTaskForm.isDisplayed()).toBe(true);
      });

      it('should validate form', function() {
        var dangerField = $('.popover').$$('span.text-danger');

        expect(page.taskNameField.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(0).isDisplayed()).toBe(true);
        expect(dangerField.get(0).getText()).toEqual('Task name is required.');
        page.taskNameField.sendKeys('E2E: Test Task');
        expect(page.taskNameField.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(0).getText()).toBe('');

        expect(page.taskDueField.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(1).isDisplayed()).toBe(true);
        expect(dangerField.get(1).getText()).toEqual('Task due date is required.');
        page.taskDueField.click();
        $$('tbody tr td button').last().click();
        expect(page.taskDueField.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(1).getText()).toBe('');
      });

      it('should close the form', function() {
        page.cancelTaskForm.click();
        expect(page.addTaskForm.isPresent()).toBe(false);

        page.addTask.click();
        expect(page.taskNameField.getAttribute('class')).toContain('ng-invalid');
        expect(page.taskDueField.getAttribute('class')).toContain('ng-invalid');
      });

      it('should create \'New Task\'', function() {
        var ele = browser.element(by.css('.toast.toasty-type-success'));
        var EC = protractor.ExpectedConditions;
        page.taskNameField.sendKeys('E2E: Test Task');
        page.taskDueField.click();
        $$('tbody tr td button').last().click();
        page.submitTaskForm.click();
        //browser.wait(EC.visibilityOf(ele), 20000);
        expect(page.tasks.count()).toBeGreaterThan(0);
      });

      it('should edit a Task', function() {
        page.displayOptions.click();
      
        expect(page.displayOptionsList.get(0).$('a').getText()).toBe('Edit Task');
        expect(page.displayOptionsList.get(1).$('a').getText()).toBe('Remove Task');
      
        page.displayOptionsList.get(0).$('a').click();
        expect(page.addTaskForm.isDisplayed()).toBe(true);
      
        page.taskNameField.clear();
        page.taskNameField.sendKeys('E2E: Edit Test Task');
        page.taskDueField.click();
        $$('tbody tr td button').last().click();
      
        page.submitTaskForm.click();

      //  var task = page.tasks.get(0);
       expect(page.tasks.get(0).$('.task-name').getText()).toBe('E2E: Edit Test Task');
      });

      it('should assign an existing project to the Task', function() {
        page.displayOptions.click();
        page.displayOptionsList.get(0).$('a').click();

        page.selectProject.click().then(function(){
          $$('select option').get(1).click().then(function(){
            browser.actions().sendKeys( protractor.Key.ENTER ).perform();  //Firefox hack needed to wait for model to update
            page.submitTaskForm.click();
          });
        });        
        expect(page.tasks.get(0).element(by.binding('entity.projectName')).getText()).toEqual('E2E: Edit Test Project');

      });

      it('should assign project through Create a New Project to the Task', function() {
        page.displayOptions.click();
        page.displayOptionsList.get(0).$('a').click();
      
        expect(page.projectForm.isPresent()).toBe(false);

        page.createProjectFromTask.click();
        expect(page.projectForm.isDisplayed()).toBe(true);
        expect(page.projectNameField.getAttribute('class')).toContain('ng-invalid');

        page.projectNameField.sendKeys('E2E: Test Project from Task');
        page.projectDateField.click();
        $$('tbody tr td button').last().click();

        page.projectDescriptionField.sendKeys('E2E: Test Project description');
        page.projectNotesField.sendKeys('E2E: Test Project notes');

        //check that the modal closes on succesful submit
        page.submitProjectForm.click();
        expect(page.projectForm.isPresent()).toBe(false);
        page.selectProject.click().then(function(){
          $$('select option').get(1).click().then(function(){
            browser.actions().sendKeys( protractor.Key.ENTER ).perform();  //Firefox hack needed to wait for model to update
            page.submitTaskForm.click();
          });
        });    
        expect(page.tasks.get(0).element(by.binding('entity.projectName')).getText()).toEqual('E2E: Test Project from Task');
    
      });

      it('should link to expanded project', function() {

        page.tasks.get(0).element(by.binding('entity.projectName')).click();
        expect(page.tabs.get(0).getAttribute('class')).toContain('active');
        expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
        expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');

        expect(page.projects.count()).toBe(2);

        expect(page.projectCollapseButton.isPresent()).toBe(true);
        expect((page.projectCollapseButton.$('.fa-compress')).isPresent()).toBe(true);
        expect((page.projects.get(0).$('.my-project-body')).isDisplayed()).toBe(true);

        page.projects.get(0).$('.accordion-header a.options').click();
        page.projectOptionsList.get(1).click();
      
        page.tabs.get(1).$('a').click();

      });

      it('should delete Task', function() {
        page.tasks.each(function(task, i){
          page.tasks.get(i).$('a.my-task-options').click();
          page.displayOptionsList.get(1).$('a').click();
        });
        expect(page.tasks.count()).toBe(0);
      });
    });

    describe('My Events', function() {
      it('should display \'New Events\' tab', function() {
        page.tabs.get(2).$('a').click();
        expect(page.tabs.get(0).getAttribute('class')).not.toContain('active');
        expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
        expect(page.tabs.get(2).getAttribute('class')).toContain('active');
      });

      it('should open \'New Events\'', function() {
        page.addEvent.click();
        expect(page.addEventForm.isDisplayed()).toBe(true);
      });

     it('should validate the New Event form', function() {
        var dangerField = $('.popover').$$('span.text-danger');

        expect(page.eventNameField.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(0).isDisplayed()).toBe(true);
        expect(dangerField.get(0).getText()).toEqual('Event name is required.');
        page.eventNameField.sendKeys('E2E: Test Event');
        expect(page.eventNameField.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(0).getText()).toBe('');

        expect(page.eventStartDue.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(1).isDisplayed()).toBe(true);
        expect(dangerField.get(1).getText()).toEqual('Event start date is required.');
        page.eventStartDue.click();
        $$('tbody tr td button').last().click();
        expect(page.eventStartDue.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(1).getText()).toBe('');

        expect(page.eventEndDue.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(2).isDisplayed()).toBe(true);
        expect(dangerField.get(2).getText()).toEqual('Event end date is required.');
        page.eventEndDue.click();
        $$('tbody tr td button').last().click();
        expect(page.eventEndDue.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(2).getText()).toBe('');

        expect(page.eventStartTime.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(3).isDisplayed()).toBe(true);
        expect(dangerField.get(3).getText()).toEqual('Event start time is required.');
        page.eventStartTime.click();
        $('tbody tr:nth-of-type(3) td:first-of-type button').click();
        expect(page.eventStartTime.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(3).getText()).toBe('');

        expect(page.eventEndTime.getAttribute('class')).toContain('ng-invalid');
        expect(dangerField.get(4).isDisplayed()).toBe(true);
        expect(dangerField.get(4).getText()).toEqual('Event end time is required.');
        page.eventEndTime.click();
        $('tbody tr:nth-of-type(3) td:first-of-type button').click();
        expect(page.eventEndTime.getAttribute('class')).toContain('ng-valid');
        expect(dangerField.get(4).getText()).toBe('');
        
      });

      it('should close the form', function() {
        browser.waitForAngular();
        page.cancelEventForm.click();
        expect(page.addEventForm.isPresent()).toBe(false);
      });

      it('should create \'New Event\'', function() {
        page.addEvent.click();

        page.eventNameField.sendKeys('E2E: Test Event');

        page.eventStartDue.click();
        $$('tbody tr td button').last().click();

        page.eventEndDue.click();
        $$('tbody tr td button').last().click();

        page.eventStartTime.click();
        $('tbody tr:nth-of-type(3) td:first-of-type button').click();

        page.eventEndTime.click();
        $('tbody tr:nth-of-type(3) td:first-of-type button').click();

        page.formLocation.sendKeys('E2E: Test Location');

        page.formDescription.sendKeys('E2E: Test Description');
        
        page.submitEventForm.click();

        expect(page.events.count()).toBeGreaterThan(0);
      });

      var EC = protractor.ExpectedConditions;

      it('should expand event content', function(){
        expect(page.eventExpandButton.isPresent()).toBe(true);
        expect((page.eventExpandButton.$('.fa-expand')).isPresent()).toBe(true);
        expect((page.events.get(0).element(by.binding('eventEntity.location'))).isDisplayed()).toBe(false);
        page.eventExpandButton.click();
        expect((page.events.get(0).element(by.binding('eventEntity.location'))).isDisplayed()).toBe(true);
      });

     it('should collapse event content', function(){
        expect(page.eventCollapseButton.isPresent()).toBe(true);
        expect((page.eventCollapseButton.$('.fa-compress')).isPresent()).toBe(true);
        page.eventCollapseButton.click();
        expect((page.events.get(0).element(by.binding('eventEntity.location'))).isDisplayed()).toBe(false);
      });

      it('should edit an Event', function() {
        page.displayEventEditOptions.click();
        expect(page.displayEventEditOptionsList.get(0).$('a').getText()).toBe('Edit Event');
        expect(page.displayEventEditOptionsList.get(1).$('a').getText()).toBe('Remove Event');
        expect(page.displayEventEditOptionsList.get(2).$('a').getText()).toBe('Share Event');

        page.displayEventEditOptionsList.get(0).$('a').click();
        expect(page.addEventForm.isDisplayed()).toBe(true);

        page.eventNameField.clear();
        page.eventNameField.sendKeys('E2E: Edit Test Event');
        page.eventStartDue.click();
        $$('tbody tr td button').last().click();

        page.eventEndDue.click();
        $$('tbody tr td button').last().click();

        page.eventStartTime.click();
        $('tbody tr:nth-of-type(3) td:first-of-type button').click();

        page.eventEndTime.click();
        $('tbody tr:nth-of-type(3) td:first-of-type button').click();

        page.formLocation.clear();
        page.formLocation.sendKeys('E2E: Edit Test Location');

        page.formDescription.clear();
        page.formDescription.sendKeys('E2E: Edit Test Description');

        page.submitEventForm.click();

        expect(page.events.count()).toBeGreaterThan(0);
        expect(page.events.get(0).$('.accordion-header h5').getText()).toBe('E2E: Edit Test Event');

      });
      
      it('should assign an existing project to the Event', function() {
        page.displayEventEditOptions.click();
        page.displayEventEditOptionsList.get(0).$('a').click();
        
        page.selectProject.click().then(function(){
          $$('select option').get(1).click().then(function(){
            browser.actions().sendKeys( protractor.Key.ENTER ).perform();  //Firefox hack needed to wait for model to update
            page.submitEventForm.click();
          });
        });  
  
        page.eventExpandButton.click();

        expect(page.events.get(0).element(by.binding('eventEntity.projectName')).getText()).toEqual('E2E: Edit Test Project');
      });

      it('should assign project through Create a New Project to the Event', function() {

        page.displayEventEditOptions.click();
        page.displayEventEditOptionsList.get(0).$('a').click();
        expect(page.projectForm.isPresent()).toBe(false);

        page.createProjFromEvent.click();
        expect(page.projectForm.isDisplayed()).toBe(true);
        expect(page.projectNameField.getAttribute('class')).toContain('ng-invalid');

        page.projectNameField.sendKeys('E2E: Test Project from Event');
        page.projectDateField.click();
        $$('tbody tr td button').last().click();

        page.projectDescriptionField.sendKeys('E2E: Test Project description');
        page.projectNotesField.sendKeys('E2E: Test Project notes');

        //check that the modal closes on succesful submit
        page.submitProjectForm.click();
        expect(page.projectForm.isPresent()).toBe(false);
        
        page.selectProject.click().then(function(){
          $$('select option').get(1).click().then(function(){
            browser.actions().sendKeys( protractor.Key.ENTER ).perform();  //Firefox hack needed to wait for model to update
            page.submitEventForm.click();
          });
        });  

        page.eventExpandButton.click();

        expect(page.events.get(0).element(by.binding('eventEntity.projectName')).getText()).toEqual('E2E: Test Project from Event');
      });
  
      it('should link to expanded project', function() {

        page.events.get(0).element(by.binding('eventEntity.projectName')).click();

        expect(page.tabs.get(0).getAttribute('class')).toContain('active');
        expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
        expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');

        expect(page.projects.count()).toBe(2);

        expect(page.projectCollapseButton.isPresent()).toBe(true);
        expect((page.projectCollapseButton.$('.fa-compress')).isPresent()).toBe(true);
        expect((page.projects.get(0).$('.my-project-body')).isDisplayed()).toBe(true);

        page.projects.get(0).$('.accordion-header a.options').click();
        page.projectOptionsList.get(1).click();

        page.tabs.get(2).$('a').click();

      });

      it('should delete Event', function() {
        page.events.each(function(myevent, i){
           page.events.get(i).$('.accordion-header a.options').click();
          page.displayEventEditOptionsList.get(1).$('a').click();
        });      
        expect(page.events.count()).toBe(0);
      });
    });
    
    describe('Project Center Clean Up', function() {
      it('should delete project', function() {
        page.tabs.get(0).$('a').click();
        page.projects.each(function(project, i){
           page.projects.get(i).$('.accordion-header a.options').click();
           page.projectOptionsList.get(1).click();
        });
        expect(page.projects.count()).toBe(0);
        expect(page.welcomeMessage.isDisplayed()).toBe(true);
      });
    });
  
  });
  
  describe('Home Page', function() {
    page.banner = browser.element(by.binding('banner.title'));

    it('should have the Home page banner', function() {
      expect(page.banner.getText()).toBe('ACQUISITION GATEWAY');
    });

    it('should have project center', function(){
      expect($('.project-center .title-banner').getText()).toBe('PROJECT CENTER');
      expect($('.project-center header p small').getText()).toBe('Build Your Acquisition');
    });

    it('should have the Hallways widget', function() {
      expect(page.hallwaysWidget.isPresent()).toBe(true);
      expect(page.hallwaysWidget.$('.title-banner').getText()).toEqual('HALLWAYS');
      expect(page.hallwaysWidget.$('.title-banner').getCssValue('text-transform')).toEqual('uppercase');
    });

    it('should have Solutions Finder widget', function() {
      var solFinder = {};
      solFinder.form = $('form.solutions-finder');
      solFinder.titleBanner = solFinder.form.$('h5.title-banner');
      solFinder.inputGroups = solFinder.form.$$('.form-group');

      expect(solFinder.titleBanner.isDisplayed()).toBe(true);
      expect(solFinder.titleBanner.getText()).toEqual('SOLUTIONS FINDER');
    });

    it('should have Resources widget', function() {
      expect(page.resourceWidget.isDisplayed()).toBe(true);
      expect(page.resourceWidget.$('h5.title-banner').getText()).toEqual('RESOURCES');
    });

    it('should have Events widget', function() {
      expect($('#events').isDisplayed()).toBe(true);
      expect(page.eventsFeed.$('.feed-title-banner').getText()).toEqual('EVENTS');

      element.all(by.repeater('feed in feeds | orderBy: \'event.value\' | upcoming')).count().then(function(count){
        var noEventText = $('#events.feeds-widget').element(by.css('[ng-if="feeds === null || ( feeds | upcoming ) === null "]'));
        if (count == 0) {
          expect(noEventText.isDisplayed()).toBe(true);
          expect(noEventText.getText()).toContain('Info! Sorry, there are currently no upcoming events scheduled');
        } else {
          expect(noEventText.isPresent()).toBe(false);
          expect(element.all(by.repeater('feed in feeds | orderBy: \'event.value\' | upcoming')).count()).toBeGreaterThan(0);
        }
      });
      
    });

    it('should have News widget', function() {
      expect($('#news').isDisplayed()).toBe(true);
      expect(page.newsFeed.$('.feed-title-banner').getText()).toEqual('NEWS');
      element.all(by.repeater('node in nodeArray | orderBy: \'-created\' track by $index')).count().then(function(count){
        var noNewsText = $('#news.feeds-widget').element(by.css('[ng-if="nodes === null"]'));
        if (count == 0) {
          expect(noNewsText.isDisplayed()).toBe(true);
          expect(noNewsText.getText()).toContain('Sorry, there are currently no news items');
        } else {
          expect(noNewsText.isPresent()).toBe(false);
          expect(element.all(by.repeater('node in nodeArray | orderBy: \'-created\' track by $index')).count()).toBeGreaterThan(0);
        }
      });
    });

    it('should link to News content', function() {
      var newsItem = element.all(by.repeater('node in nodeArray | orderBy: \'-created\' track by $index')),
          test = false;
      
      newsItem.get(0).$('.node-title').getText().then(function(label) {
        newsItem.get(0).$('.node-title a').click();
        browser.getCurrentUrl().then(function(url) {
          if (url.indexOf('/app/#/gateway') != -1 || url.indexOf('/app/#/news') != -1) test = true;
          expect(test).toEqual(true);

          if (url.indexOf('/app/#/gateway') != -1) {
           expect($('#article-label').getText()).toContain(label.toUpperCase());
          } 

          if (url.indexOf('/app/#/news') != -1) {
            expect(element(by.binding('news.label')).getText()).toContain(label);
          }
        });
      });

      browser.get('/app/#/');

    });

  });

  if (!browser.params.publicUser) {
    describe('Community', function () {
      it('should have the Community widget', function () {
        expect(page.communitiesWidget.isDisplayed()).toBe(true);
        expect(page.communitiesWidget.$('.title-banner').getText()).toEqual('COMMUNITY');
      });
      it('should link to community page', function () {
        page.communitiesWidget.$('.widget-header a').click()
        expect(browser.getCurrentUrl()).toContain('/communities');
        browser.get('/app/#/');
      });
      it('should display the list of topics', function () {
        page.topics = browser.element.all(by.repeater('topic in topics'));
        expect(page.topics.count()).toBeGreaterThan(0);
      });
    });
  }
  describe('Resources Widget', function () {
    if (!browser.params.publicUser) {

      it('should have correct resources in Resources widget', function() {
        expect(page.resources.get(0).$('h5 a').getText()).toEqual('Shared Services');
        expect(page.resources.get(1).$('h5 a').getText()).toEqual('TechFAR Hub');
        expect(page.resources.get(2).$('h5 a').getText()).toEqual('eBuy Open');
        expect(page.resources.get(3).$('h5 a').getText()).toEqual('Prices Paid Portal');
        expect(page.resources.get(4).$('h5 a').getText()).toEqual('Statement of Work Library');
      });
      it('should display correct icon for \'Shared Services\' content', function() {
        expect(page.resources.get(0).element(by.css("img[src*='../sites/all/themes/bootstrap/art/shared-services.png']")).isPresent()).toBe(true);
      });
      it('should display correct icon for \'eBuy Open\' content', function() {
        expect(page.resources.get(2).$('.fa-cubes').isPresent()).toBe(true);
      });
      it('should display correct icon for \'Prices Paid Portal\' content', function() {
        expect(page.resources.get(3).$('.fa-bar-chart').isPresent()).toBe(true);
      });
      it('should display correct description for \'Shared Services\' content', function() {
        var description = 'Learn more about available shared services that help federal departments and agencies leverage existing solutions rather build new ones.'
        expect(page.resources.get(0).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
        page.resources.get(0).$('.accordion-toggle').click();
        expect(page.resources.get(0).$('.accordion-toggle').$('.fa-minus-circle').isPresent()).toBe(true);
        expect(page.resources.get(0).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(true);
        expect(page.resources.get(0).element(by.binding('resource.description')).$('p').getText()).toContain(description);
        page.resources.get(0).$('.accordion-toggle').click();
        expect(page.resources.get(0).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
        expect(page.resources.get(0).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(false);
      });
      it('should display correct description for \'eBuy Open\' content', function() {
        var description = 'eBuy Open is an interactive web application that displays eBuy RFQ information to users and provides several filtering and search options, which enables users to quickly drill down to desired information.'
        expect(page.resources.get(2).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
        page.resources.get(2).$('.accordion-toggle').click();
        expect(page.resources.get(2).$('.accordion-toggle').$('.fa-minus-circle').isPresent()).toBe(true);
        expect(page.resources.get(2).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(true);
        expect(page.resources.get(2).element(by.binding('resource.description')).$('p').getText()).toContain(description);
        page.resources.get(2).$('.accordion-toggle').click();
        expect(page.resources.get(2).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
        expect(page.resources.get(2).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(false);
      });
      it('should display correct description for \'Prices Paid Portal\' content', function() {
        var description = 'Prices Paid Portal (P3) is an interactive web application that provides users access to selected data sets which can be searched, filtered, and exported.'
        expect(page.resources.get(3).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
        page.resources.get(3).$('.accordion-toggle').click();
        expect(page.resources.get(3).$('.accordion-toggle').$('.fa-minus-circle').isPresent()).toBe(true);
        expect(page.resources.get(3).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(true);
        expect(page.resources.get(3).element(by.binding('resource.description')).$('p').getText()).toContain(description);
        page.resources.get(3).$('.accordion-toggle').click();
        expect(page.resources.get(3).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
        expect(page.resources.get(3).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(false);
      });
      it('should link to Prices Paid Portal', function() {
        page.resources.get(3).$('h5 a').click();
        browser.getAllWindowHandles().then(function (handles) {
          newWindowHandle = handles[1];
          browser.switchTo().window(newWindowHandle).then(function () {
            expect(browser.driver.getCurrentUrl()).toContain("https://p3");
            browser.driver.close().then(function () {
              browser.switchTo().window(handles[0]);
            });
          });
        });
      });
      it('should link to eBuy Open content', function() {
        page.resources.get(2).$('h5 a').click();
        browser.getAllWindowHandles().then(function (handles) {
          newWindowHandle = handles[1];
          browser.switchTo().window(newWindowHandle).then(function () {
            expect(browser.driver.getCurrentUrl()).toContain("https://www.ebuy.gsa.gov/");
            browser.driver.close().then(function () {
              browser.switchTo().window(handles[0]);
            });
          });
        });
      });
      it('should link to Shared Services', function() {
        page.resources.get(0).$('h5 a').click();
        browser.getAllWindowHandles().then(function (handles) {
          newWindowHandle = handles[1];
          browser.switchTo().window(newWindowHandle).then(function () {
            expect(browser.driver.getCurrentUrl()).toContain("/content/footer/shared-services/");
            browser.driver.close().then(function () {
              browser.switchTo().window(handles[0]);
            });
         });
        });
      });
    }
   
    it('should display correct icon for \'TechFAR Hub\' content', function() {
      expect(page.resources.get(tfhIndex).$('.fa-street-view').isPresent()).toBe(true);
    });
    it('should display correct icon for \'Statement of Work Library\' content', function() {
      expect(page.resources.get(swlIndex).$('.fa-university').isPresent()).toBe(true);
    });
    it('should contain correct description for \'TechFAR Hub\' content', function() {
      var description = 'The TechFAR Hub is a community of practice open to all Federal government employees with an interest in successful acquisitions. The TechFAR Hub and the Gateway share the common goals of saving taxpayer dollars, making acquisition more efficient, and improving service to customers inside government and out'
      expect(page.resources.get(tfhIndex).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
      page.resources.get(tfhIndex).$('.accordion-toggle').click();
      expect(page.resources.get(tfhIndex).$('.accordion-toggle').$('.fa-minus-circle').isPresent()).toBe(true);
      expect(page.resources.get(tfhIndex).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(true);
      expect(page.resources.get(tfhIndex).element(by.binding('resource.description')).$('p').getText()).toContain(description);
      page.resources.get(tfhIndex).$('.accordion-toggle').click();
      expect(page.resources.get(tfhIndex).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
      expect(page.resources.get(tfhIndex).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(false);
    });
    it('should contain correct description for \'Statement of Work Library\' content', function() {
      var description = 'The Statement of Work Library is a repository of samples and templates for SOWs, PWSs and SOOs.'
      expect(page.resources.get(swlIndex).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
      page.resources.get(swlIndex).$('.accordion-toggle').click();
      expect(page.resources.get(swlIndex).$('.accordion-toggle').$('.fa-minus-circle').isPresent()).toBe(true);
      expect(page.resources.get(swlIndex).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(true);
      expect(page.resources.get(swlIndex).element(by.binding('resource.description')).$('p').getText()).toContain(description);
      page.resources.get(swlIndex).$('.accordion-toggle').click();
      expect(page.resources.get(swlIndex).$('.accordion-toggle').$('.fa-plus-circle').isPresent()).toBe(true);
      expect(page.resources.get(swlIndex).element(by.binding('resource.description')).$('p').isDisplayed()).toBe(false);
    });
    it('should link to TechFAR Hub', function() {
      page.resources.get(tfhIndex).$('h5 a').click();
      browser.getAllWindowHandles().then(function (handles) {
        newWindowHandle = handles[1];
        browser.switchTo().window(newWindowHandle).then(function () {
          expect(browser.driver.getCurrentUrl()).toContain("/content/the-techfar-hub");
          browser.driver.close().then(function () {
            browser.switchTo().window(handles[0]);
          });
        });
      });
    });
    it('should link to Statement of Work Library', function() {
      page.resources.get(swlIndex).$('h5 a').click();
      expect(browser.driver.getCurrentUrl()).toContain('/sowl');
    });
  });

  describe('Hallways Navigation', function() {
    it('should toggle hallway expand', function() {
      browser.get('/app/#');
      page.hallways.each(function(hallway, index) {
         expect(page.hallways.get(index).$('.accordion-body').isDisplayed()).toBe(false);
        page.hallways.get(index).element(by.css('[bs-collapse-toggle]')).click();
        expect(page.hallways.get(index).$('.accordion-body').isDisplayed()).toBe(true);
        page.hallways.get(index).element(by.css('[bs-collapse-toggle]')).click();
        expect(page.hallways.get(index).$('.accordion-body').isDisplayed()).toBe(false);
      });
    });

    it('should have all hallways', function() {
      hallwaysList.forEach(function(item, i) {
        expect(page.hallways.get(i).$('.accordion-header h5 a').getText()).toEqual(item);
      });
    });
   
   hallwaysList.forEach(function (h, i) {
      it('should open ' + hallwaysList[i] + ' hallway', function() {
        var hallway = page.hallways.get(i);   
        hallway.getText().then(function(linkName) {
          hallway.$('.accordion-header h5 a').click();
          browser.element(by.binding('hallway.label')).getText().then(function(hallwayName) {
            expect(linkName).toEqual(hallwayName);
          });
          browser.navigate().back();
        });
      });
    });
  });

  describe('Solutions Finder Widget', function() {
    var sfWidget = require('../../solutions-finder/tests/solutions-finder-widget.e2e.js');

    it('should display Agency, Category and Subcategory dropdowns', function() {
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

 // $('.solutions-finder').element(by.css('ag-smart-select[data-id="purchasingOrganization"] ul')).all(by.css('li i')).get(0).click();
 //      expect($('#purchasingOrganization').all(by.tagName('span')).get(0).getText()).toEqual('Air Force');
   
    });

    it('should filter by Category', function() {
      $('#ProductCategories').click();
      element(by.css('[data-id="ProductCategories"]')).all(by.tagName('i')).get(0).click();
      element(by.css('[data-id="ProductCategories"]')).all(by.tagName('i')).get(1).click();
      $('#ProductCategories').click();
      expect($('#ProductCategories').all(by.tagName('span')).get(0).getText()).toEqual('Facilities and Construction, Human Capital');
    });

    it('should filter by Subcategory', function() {
      $('#productSubcategory').click();
      element(by.css('[data-id="productSubcategory"]')).all(by.tagName('i')).get(0).click();
      $('#productSubcategory').click();
      expect($('#productSubcategory').all(by.tagName('span')).get(0).getText()).toEqual('Construction Related Materials');
    });
  });


  describe('Navigation', function() {

    it('should have a gateway title', function() {
      expect(page.title.getText()).toBe('Acquisition Gateway');
    });

    it('should have a about us title', function() {
      expect(topmenu.get(0).getText()).toBe('About Us');
      topmenu.get(0).click();
      expect(aboutmodal.isDisplayed()).toBe(true);
      abtmodalclose.click();
      expect(aboutmodal.isPresent()).toBe(false);
    });

    it('should have a explore title', function() {
      expect(topmenu.get(1).getText()).toBe('Explore');
      topmenu.get(1).click();
      expect(exploremodal.isDisplayed()).toBe(true);
      expmodalclose.click();
      expect(exploremodal.isPresent()).toBe(false);
    });
    
    it('should have a help title', function() {
      expect(hmphelp.getText()).toBe('Help');
    });

    it('should have a faq title', function() {
      expect(faqNav.getText()).toBe('FAQs');
    });

    it('should link to faq', function() {
      faqNav.click();
      expect(browser.driver.getCurrentUrl()).toContain('/faq.php');
      browser.get('/app/#/');
    });

    if (!browser.params.publicUser) {
      it('should have a username title', function() {
        expect(regularNavUsername.getText()).toContain('Hi, e2eUser');
      });

      it('should have a signout title', function() {
        expect(hmpsignout.getText()).toBe('Sign Out');
      });
    }

  });

  if (browser.params.publicUser) {
    describe('Public User Restrictions', function () {
      it('should show welcome message when the projects are empty', function() {
        expect(page.welcomeMessage.isDisplayed()).toBe(true);
        expect(page.welcomeMessage.getAttribute('class')).toContain('publicWelcome');
      });

      it('should open \'New Project\'', function() {
        page.welcomeMessageBtn.click();
        expect(page.projectForm.isDisplayed()).toBe(true);
        page.cancelProjectForm.click();
        expect(page.projectForm.isPresent()).toBe(false);
      });

      it('should have a username title', function() {
        expect(publicUNavUsername.getText()).toContain('Hi, Guest');
      });

      it('should have a sign in link in navigation', function() {
        expect(publicSignin.getText()).toBe('Sign In');
      });

      it('should display the sign in modal', function() {
        publicSignin.click();
        expect(signinModal.isDisplayed()).toBe(true);
        expect(signinModal.$('.modal-text').getText()).toEqual('If you are a Federal Employee, would you like to sign in for full access to the Acquisition Gateway?');
        expect(page.signinActions.get(0).getText()).toEqual('Yes, sign me in');
        expect(page.signinActions.get(1).getText()).toEqual('Continue as guest');
      });

      it('should close the sign in modal when \'Continue as Guest\' is clicked', function() {
        $('.guest').click();
        expect(browser.getLocationAbsUrl()).toContain('/');
        expect(signinModal.isPresent()).toBe(false);
      })

      xit('should go to the Sign In page when \'Yes, sign me in\' is clicked', function() { 
        $('.signin-link').click();
        $('.signme').click();
        expect(browser.driver.getCurrentUrl()).toContain('/login-information');
        expect(signinModal.isPresent()).toBe(false);
      });

      it('should not display the Community widget', function () {
        expect(page.communitiesWidget.isPresent()).toBe(false);
      });

      it('should only display \'TechFAR Hub\' and \'Statement of Work Library\' links in the Resource section', function () {
        expect(page.resourcesLink.get(0).$('.resourceLabel').getText()).toEqual('TechFAR Hub');
        expect(page.resourcesLink.get(1).$('.resourceLabel').getText()).toEqual('Statement of Work Library');
      });

      it('should not display \'Prices Paid Portal\', \'Shared Services\', or \'eBuy Open\' links in Resources section', function () {
       page.resources.map(function (elm) {
          return elm.getText();
        }).then(function (result) {
          for (var i = 0; i < result.length; i++) {
            expect(result[i]).not.toContain('Prices Paid Portal') ;
            expect(result[i]).not.toContain('Shared Services');
            expect(result[i]).not.toContain('eBuy Open');
          }
        });
      });
    });
  }
});