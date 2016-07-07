describe('Project Center', function () {
  var page = {};
  var element = browser.element;
  var path = require('path');

  page.title = $('h1.DINCondensedBold');
  page.create = $('button.btn-new-entity-primary');
 // page.createTask = $('button.btn-new-entity');
  page.createEvent = $('button.btn-new-entity');
  page.pageTitle = $('div.fullview h1');
  page.pageTaskTitle = $('div.fullView h1');
  page.pageEventTitle = $('div.my-events h1')
  page.menu = $$('div.project-center-full-menu ul.nav li a');
  page.projectForm = $('form.project-entry');
  page.projectNameField = page.projectForm.element(by.model('entityCopy.name'));
  page.projectDueField = page.projectForm.element(by.model('entityCopy.due'))
  page.projectDescriptionField = page.projectForm.element(by.model('entityCopy.description'))
  page.projectNotesField = element(by.model('entityCopy.notes'))
  page.cancelProject = $$('form.project-center-entry div.actions a').get(0);
  page.submitProject = $$('form.project-center-entry div.actions a').get(1);
  page.projects = element.all(by.repeater("projectEntity in projects.data.collection | filter: { status: '1' } | orderBy: '-created' track by projectEntity.id"));
  page.tabs = page.projects.get(0).$$('ul.nav-tabs li');
  page.addProjectContent = page.projects.get(0).$('div.my-project-content a.add-project-content');
  page.addContentOptions = $$('div.popover ul.list-group li a');
  page.projectFileNameField = element(by.model('fileEntity.label'));
  page.projectFileField = element(by.model('fileEntity.file'));
  page.submitFileUpload = $('#submit-file-upload');
  page.cancelFileUpload = $('#cancel-file-upload');
  page.projectFiles = element.all(by.repeater("projectContent in projectEntities.data.collection | myProjectContentFilter: filter | orderBy: '-created'"));
  page.solutions = element.all(by.repeater('solution in pageSolutions'));
  page.viewAll = $('#view-all');
  page.share = $('.ag-share > a');
  page.search = browser.element(by.model('moreSearch.search'));
  page.taskForm = $('form.task-entry');
  page.taskNameField = element(by.model('entityCopy.name'));
  page.taskDueField = element(by.model('entityCopy.due'));
  page.addEvent = $('a.add-event');
  page.addTask = $('button.add-task');
  page.addEvent = $('a.add-event');
  page.eventForm = $('form.event-entry');
  page.eventNameField = browser.element(by.model('entityCopy.name'));
  page.eventStartDue = browser.element(by.model('entityCopy.startDate'));
  page.eventEndDue = browser.element(by.model('entityCopy.endDate'));
  page.eventStartTime = browser.element(by.model('entityCopy.startTime'));
  page.eventEndTime = browser.element(by.model('entityCopy.endTime'));
  page.eventLocation = browser.element(by.model('entityCopy.location'));
  page.eventDescription = browser.element(by.model('entityCopy.description'));
  page.tasks = element.all(by.repeater("entity in tasks.data.collection | filter: filter | orderBy: 'due'"));
  page.createProjectFromTask = $$('form.task-entry div.actions a').get(0);
//  page.cancelNewTask = $$('form.project-center-entry div.actions a').get(1);
//  page.submitNewTask = $$('form.project-center-entry div.actions a').get(2);
  page.cancelNewTask = $('form.project-center-entry div.actions a.cancel-task');
  page.submitNewTask = $('form.project-center-entry div.actions a.save-task');
  page.createProjFromEvent = $$('form.event-entry div.actions a').get(0);
  page.cancelNewEvent = $$('form.project-center-entry div.actions a').get(1);
  page.submitNewEvent = $$('form.project-center-entry div.actions a').get(2);
  page.events = browser.element.all(by.repeater("eventEntity in privateEvents.data.collection | filter: filter | orderBy: 'start_date'"));
  page.selectProject = element(by.model('entityCopy.projectId'));
  page.formProjectID = browser.element(by.model('entityCopy.projectId'));

  var sfIndex = !browser.params.publicUser ? 1 : 0,
      sowlIndex = !browser.params.publicUser ? 2 : 1;
      hallwayIndex  = !browser.params.publicUser ? 3 : 2;

  describe('My Projects', function () {

    beforeAll(function () {
      browser.get('/app/#/project-center/projects');
    });

    it('Should have page title', function () {
      expect(page.title.getText()).toEqual('PROJECT CENTER');
    });

    it('should have \'My Projects\' highlighted in the left rail', function() {
      expect(page.menu.get(0).getAttribute('class')).not.toContain('heavy-mute');
    });

    it('should have \'My Projects\' title in the center column', function() {
      expect(page.pageTitle.getText()).toEqual('My Projects');
    });

    it('should have the right icon for the page', function() {

    });

    it('should open the New Project form', function () {
      page.create.click();
      expect(page.projectForm.isDisplayed()).toBe(true);
    });

    it('should validate the New Project form', function() {
      expect(page.projectNameField.getAttribute('class')).toContain('ng-invalid');
      expect($('span.text-danger').isDisplayed()).toBe(true);
      expect($('span.text-danger').getText()).toEqual('Project name is required.');
      page.projectNameField.sendKeys('E2E: Test Project');
      expect(page.projectNameField.getAttribute('class')).toContain('ng-valid');
      expect($('span.text-danger').getText()).toBe('');
    });

    it('should cancel the New Project Form', function() {
      page.cancelProject.click();
      expect(page.projectForm.isPresent()).toBe(false);

      page.create.click();
      expect(page.projectNameField.getAttribute('class')).toContain('ng-invalid');
    });

    it('should create a new project', function() {
      //fill out the form and submit
      page.projectNameField.sendKeys('E2E: Test Project');
      page.projectDueField.click();

      page.projectDescriptionField.sendKeys('E2E: Test Project description');
      page.projectNotesField.sendKeys('E2E: Test Project notes');

      //check that the modal closes on succesful submit
      page.submitProject.click();
      expect(page.projectForm.isPresent()).toBe(false);

      //check that the new project shows in the listing
      expect(page.projects.count()).toBeGreaterThan(0);
    });

    it('should expand and collapse Project content', function () {
      var project = page.projects.get(0),
      expandButton =  project.$('button[ng-click="toggle(projectEntity.id)"]'),
      expandLink = project.$('a[ng-click="toggle(projectEntity.id)"]'),
      projectDetails = project.$('.project-details');

      expect(expandButton.getAttribute('title')).toEqual('expand');

      expandButton.click();
      expect(expandButton.getAttribute('title')).toEqual('collapse');
      expect(projectDetails.isDisplayed()).toBe(true);

      expandButton.click();
      expect(projectDetails.isDisplayed()).toBe(false);
      expect(expandButton.getAttribute('title')).toEqual('expand');

      expandLink.click();
      expect(projectDetails.isDisplayed()).toBe(true);
      expect(expandButton.getAttribute('title')).toEqual('collapse');

      expandLink.click();
      expect(projectDetails.isDisplayed()).toBe(false);
      expect(expandButton.getAttribute('title')).toEqual('expand');
    });

    it('should edit project', function () {
      var project = page.projects.get(0);
      project.$('button.edit-project').click();
      expect(page.projectForm.isDisplayed()).toBe(true);
      page.projectNameField.clear();
      page.projectNameField.sendKeys('E2E: Test Project updated');
      page.projectDescriptionField.clear();
      page.projectDescriptionField.sendKeys('E2E: Test Project description updated');
      page.projectNotesField.sendKeys('E2E: Test Project notes updated');
      page.submitProject.click();

      expect(project.$('a[ng-click="toggle(projectEntity.id)"]').getText()).toEqual('E2E: Test Project updated');
      expect(project.element(by.binding('projectEntity.description')).getText()).toEqual('E2E: Test Project description updated');
    });

    it('should have the \'Content\', \'Tasks\' and \'Events\' tabs', function() {
      var project = page.projects.get(0);
      project.$('a[ng-click="toggle(projectEntity.id)"]').click();
      expect(page.tabs.count()).toBe(3);
      expect(page.tabs.get(0).getText()).toEqual('Content');
      expect(page.tabs.get(1).getText()).toEqual('Tasks');
      expect(page.tabs.get(2).getText()).toEqual('Events');
    });

    it('should display the \'Add Content\' menu', function() {
      page.addProjectContent.click();
      
      if (browser.params.publicUser) expect(page.addContentOptions.count()).toBe(3);

      if (!browser.params.publicUser) {
        expect(page.addContentOptions.count()).toBe(4);
        expect(page.addContentOptions.get(0).getText()).toBe('File Upload');
        expect(page.addContentOptions.get(0).$('i.fa').getAttribute('class')).toContain('fa-upload');
      }

      expect(page.addContentOptions.get(sfIndex).getText()).toBe('Solutions Finder');
      expect(page.addContentOptions.get(sfIndex).$('i.fa').getAttribute('class')).toContain('fa-th-large');
      expect(page.addContentOptions.get(sowlIndex).getText()).toBe('SOW Library');
      expect(page.addContentOptions.get(sowlIndex).$('i.fa').getAttribute('class')).toContain('fa-bank');
      expect(page.addContentOptions.get(hallwayIndex).getText()).toBe('Hallways');
      expect(page.addContentOptions.get(hallwayIndex).getAttribute('class')).toContain('text-muted');
      expect(page.addContentOptions.get(hallwayIndex).$('i.fa').getAttribute('class')).toContain('fa-asterisk');

      page.addProjectContent.click();
    });

    if (browser.params.publicUser) {
      it('should not display the \'Add File\' in content menu', function() {
        page.addProjectContent.click();
        page.addContentOptions.each(function(content, i) {
          expect(content.getText()).not.toContain('File Upload');
        });
        page.addProjectContent.click();
      });
    }

    if (!browser.params.publicUser) {
      it('should open the  add File content Form', function() {
        page.addProjectContent.click();
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
        expect($('div.modal form').isPresent()).toBe(false);
      });

      xit('should upload a project file', function() {
        page.addProjectContent.click();
        page.addContentOptions.get(0).click();
        page.projectFileNameField.sendKeys('E2E: Test file name');

        var fileLocation = '../../../../pdf-test.pdf';
        var filePath = path.resolve(__dirname, fileLocation);
        page.projectFileField.sendKeys(filePath);

        page.submitFileUpload.click();
        expect($('div.modal form').isPresent()).toBe(false);

        expect(page.projectFiles.count()).toBeGreaterThan(0);
        expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual('E2E: Test file name');
        expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Uploaded Document');

      });
    }
    var solutionName = '';
    it('should open Solutions Finder to add content', function() {
      page.addProjectContent.click();
      page.addContentOptions.get(sfIndex).click();
      expect(browser.getCurrentUrl()).toContain('/solutionsfinder');
    });

    it('should open the solution \'Add to Project\' Dialog', function() {
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
      browser.get('/app/#/project-center/projects');
      var project = page.projects.first();
      project.$('a[ng-click="toggle(projectEntity.id)"]').click();
      expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual(solutionName);
      expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: Solution');

    });

    it('should delete a Solutions Finder content', function() {
      page.projectFiles.get(0).$('a.project-content-options').click();
      $('div.popover ul li a').click();
      expect(page.projectFiles.count()).toBe(0);
    });

    it('should open Statement of Work Library to add content', function() {
      page.addProjectContent.click();
      page.addContentOptions.get(sowlIndex).click();
      expect(browser.getCurrentUrl()).toContain('/sowl');
    });

    var searchUrl;
    it('should open the SOWL search \'Add to Project\' Dialog', function() {
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
      browser.get('/app/#/project-center/projects');
      var project = page.projects.first();

      project.$('a[ng-click="toggle(projectEntity.id)"]').click();
      expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual('E2E: Test SOW Search');
      expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: SOWL Search');
    });

    it('should delete a SOWL Search', function() {
      page.projectFiles.get(0).$('a.project-content-options').click();
      $('div.popover ul li a').click();
      expect(page.projectFiles.count()).toBe(0);
    });

    it('should open Solutions Finder to add search content', function() {
      page.addProjectContent.click();
      page.addContentOptions.get(sfIndex).click();
      expect(browser.getCurrentUrl()).toContain('/solutionsfinder');
    });

    it('should open the Solution search \'Add to Project\' Dialog', function() {
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
      browser.get('/app/#/project-center/projects');
      var project = page.projects.first();

      project.$('a[ng-click="toggle(projectEntity.id)"]').click();
      expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual('E2E: Test Solution Search');
      expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: Solutions Finder Search');
    });

    it('should delete a Solution Search', function() {
      page.projectFiles.get(0).$('a.project-content-options').click();
      $('div.popover ul li a').click();
      expect(page.projectFiles.count()).toBe(0);
    });

    it('should open Statement of Work Library to add content', function() {
      page.addProjectContent.click();
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
      browser.get('/app/#/project-center/projects');
      var project = page.projects.first();
      project.$('a[ng-click="toggle(projectEntity.id)"]').click();
      expect(page.projectFiles.get(0).element(by.binding('projectContent.name')).getText()).toEqual(sowlName);
      expect(page.projectFiles.get(0).element(by.binding('projectContent.type')).getText()).toEqual('Type: SOW Document');
    });

    it('should delete SOWL Document', function() {
      page.projectFiles.get(0).$('a.project-content-options').click();
      $('div.popover ul li a').click();
      expect(page.projectFiles.count()).toBe(0);
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
    
    it('should switch to the \'Tasks\' tab', function() {
      page.tabs.get(1).$('a').click();
      expect(page.tabs.get(1).getAttribute('class')).toContain('active');
      expect(page.tabs.get(0).getAttribute('class')).not.toContain('active');
      expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');
      expect(page.addTask.getText()).toEqual('New Task');
    });

    it('should open New Task form', function() {
      page.addTask.click();
      expect($('form.task-entry').isDisplayed()).toBe(true);
    });

    it('should validate task form', function() {
      expect(page.taskNameField.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(0).getText()).toEqual('Task name is required.');

      page.taskNameField.sendKeys('E2E: Test Task');
      expect(page.taskNameField.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(0).getText()).toEqual('');

      expect(page.taskDueField.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(1).getText()).toEqual('Task due date is required.');

      page.taskDueField.click();
      $$('tbody tr td button').last().click();
      expect(page.taskDueField.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(1).getText()).toEqual('');
    });

    it('should cancel task form', function() {
      $('form.task-entry').$('a.cancel-task').click();
      expect($('form.task-entry').isPresent()).toBe(false);
    });

    it('should create a new Task', function() {
      page.toasty = $('#toasty');
      page.toastySuccess = element.all(by.repeater('toast in toasty'));

      page.addTask.click();
      page.taskNameField.sendKeys('E2E: Test Task');
      page.taskDueField.click();
      $$('tbody tr td button').last().click();

      $('a.save-task').click();
      expect($('form.task-entry').isPresent()).toBe(false);
      expect(page.tasks.count()).toBe(1);
    });

    it('should delete the created task', function() {
      page.tasks.get(0).$('a.my-task-options').click();
      $$('div.popover ul.list-group > li > a').get(1).click();
      expect(page.tasks.count()).toBe(0);
    });

    it('should switch to the \'Events\' tab', function() {
      page.tabs.get(2).$('a').click();
      expect(page.tabs.get(2).getAttribute('class')).toContain('active');
      expect(page.tabs.get(0).getAttribute('class')).not.toContain('active');
      expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
      expect(page.addEvent.getText()).toEqual('New Event');
    });

    it('should create a new Event', function() {
      page.addEvent.click();

      expect(page.tabs.get(2).getAttribute('class')).toContain('active');
      expect($('form.event-entry').isDisplayed()).toBe(true);

      expect(page.eventNameField.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(0).getText()).toEqual('Event name is required.');
      page.eventNameField.sendKeys('E2E: Test Event');
      expect(page.eventNameField.getAttribute('class')).toContain('ng-valid');

      expect(page.eventStartDue.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(1).getText()).toEqual('Event start date is required.');
      page.eventStartDue.click();
      $$('tbody tr td button').last().click();
      expect(page.eventStartDue.getAttribute('class')).toContain('ng-valid');

      expect(page.eventEndDue.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(2).getText()).toEqual('Event end date is required.');
      page.eventEndDue.click();
      $$('tbody tr td button').last().click();
      expect(page.eventEndDue.getAttribute('class')).toContain('ng-valid');

      expect(page.eventStartTime.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(3).getText()).toEqual('Event start time is required.');
      page.eventStartTime.click();
      $('tbody tr:nth-of-type(3) td:first-of-type button').click();
      expect(page.eventStartTime.getAttribute('class')).toContain('ng-valid');

      expect(page.eventEndTime.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(4).getText()).toEqual('Event end time is required.');
      page.eventEndTime.click();
      $('tbody tr:nth-of-type(4) td:first-of-type button').click();
      expect(page.eventEndTime.getAttribute('class')).toContain('ng-valid');

      $('form.event-entry').$('div.actions a.saveBtn').click();

    });

    xit('should display events ordered by date', function() {
      expect(true).toBe(false);
    });

    it('should delete created events', function() {
      page.events.get(0).$('a.options').click();
      $$('div.popover ul.list-group > li > a').get(1).click();
      expect(page.events.count()).toBe(0);

    });
  });

  describe('My Tasks', function() {
    beforeAll(function () {
      browser.get('/app/#/project-center/projects');
    });

    it('should have \'My Tasks\' highlighted in the left rail', function() {
      page.menu.get(1).click();
      expect(page.menu.get(1).getAttribute('class')).not.toContain('heavy-mute');
    });

    it('should have \'My Tasks\' title in the center column', function() {
      expect(page.pageTaskTitle.getText()).toEqual('My Tasks');
    });

    it('should have the right icon for the page', function() {
      expect(page.pageTaskTitle.$('i').getAttribute('class')).toContain('fa-th-list');
    });

    it('should open the New Task form', function () {
      page.create.click();
      expect(page.taskForm.isDisplayed()).toBe(true);
    });

    it('should validate the New Task form', function() {
      expect(page.taskNameField.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(0).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(0).getText()).toEqual('Task name is required.');
      page.taskNameField.sendKeys('E2E: Test Project');
      expect(page.taskNameField.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(0).getText()).toBe('');

      expect(page.taskDueField.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(1).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(1).getText()).toEqual('Task due date is required.');
      page.taskDueField.sendKeys('E2E: Test Project');

      page.taskDueField.click();
      $$('tbody tr td button').last().click();
      expect(page.taskDueField.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(1).getText()).toBe('');
    });

    it('should cancel the New Task Form', function() {
      page.cancelNewTask.click();
      expect(page.taskForm.isPresent()).toBe(false);

      page.create.click();
      expect(page.taskNameField.getAttribute('class')).toContain('ng-invalid');
    });

    it('should create a new Task', function() {
      //fill out the form and submit
      page.taskNameField.sendKeys('E2E: Test Task');
      page.taskDueField.click();
      $$('tbody tr td button').last().click();

      //check that the modal closes on succesful submit
   //   page.submitNewTask.click();
      var save = $('a[ng-click="taskEntry.$valid && tasks.saveAsAssociate(entityCopy, $hide)"]');
      save.click();
      expect(page.taskForm.isPresent()).toBe(false);

      expect(page.tasks.get(0).element(by.binding('entity.name')).getText()).toBe('E2E: Test Task');

      expect(page.tasks.count()).toEqual(1);
    });

    it('should edit a Task', function() {

      page.tasks.get(0).$('a.edit-task').click();

      page.taskNameField.clear();
      page.taskNameField.sendKeys('E2E: Edit Test Task');
      page.taskDueField.click();
      $$('tbody tr td button').last().click();
      page.submitNewTask.click();

      expect(page.tasks.get(0).element(by.binding('entity.name')).getText()).toBe('E2E: Edit Test Task');

      expect(page.tasks.count()).toEqual(1);
    });

    it('should assign an existing project to the Task', function() {
      page.tasks.get(0).$('a.edit-task').click();

      page.formProjectID.click().then(function(){
         $$('select option').get(1).click().then(function(){
          browser.actions().sendKeys( protractor.Key.ENTER ).perform(); //Firefox hack needed to wait for model to update
          page.submitNewTask.click();
         });
      });
     
      expect(page.tasks.get(0).element(by.binding('entity.projectName')).getText()).toEqual('E2E: Test Project updated');

    });

    it('should assign project through Create a New Project to the Task', function() {
      var projectForm = $('form.project-entry');
      projectNameField = projectForm.element(by.model('entityCopy.name'));

      page.tasks.get(0).$('a.edit-task').click();
      expect(projectForm.isPresent()).toBe(false);

      page.createProjectFromTask.click();
      expect(projectForm.isDisplayed()).toBe(true);
      expect(projectNameField.getAttribute('class')).toContain('ng-invalid');

      projectNameField.sendKeys('E2E: Test Project from Task');
      page.projectDueField.click();

      page.projectDescriptionField.sendKeys('E2E: Test Project description');
      page.projectNotesField.sendKeys('E2E: Test Project notes');

      projectForm.$('a.save').click();
      expect(projectForm.isPresent()).toBe(false);

      page.formProjectID.click().then(function(){
        $$('select option').get(1).click().then(function(){
          browser.actions().sendKeys( protractor.Key.ENTER ).perform();  //Firefox hack needed to wait for model to update
          page.submitNewTask.click();
        });
      });

      expect(page.tasks.get(0).element(by.binding('entity.projectName')).getText()).toEqual('E2E: Test Project from Task');
    
    });

    it('should link to project', function() {

      page.tasks.get(0).element(by.binding('entity.projectName')).click();
      expect(page.tabs.get(0).getAttribute('class')).toContain('active');
      expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
      expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');

      expect(page.projects.count()).toBe(2);

      var project = page.projects.get(0),
      expandButton =  project.$('button[ng-click="toggle(projectEntity.id)"]'),
      projectDetails = project.$('.project-details');

      expect(expandButton.getAttribute('title')).toEqual('collapse');
      expect(projectDetails.isDisplayed()).toBe(true);
      
      page.projects.get(0).$('button.delete-project').click();

      page.menu.get(1).click();

    });

    it('should delete a Task', function() {
      page.tasks.get(0).$('a.delete-task').click();
      expect(page.tasks.count()).toBe(0);
    });
  });

  describe('My Events', function() {
    var myEvents = page.events.get(0),
        eventExpandButton =  myEvents.$('button[ng-click="expanded = !expanded"]'),
        eventExpandLink = myEvents.$('a[ng-click="expanded = !expanded"]'),
        eventDetails = myEvents.$('.event-details');

    beforeAll(function () {
      browser.get('/app/#/project-center/projects');
    });

    it('should have \'My Events\' highlighted in the left rail', function() {
      page.menu.get(2).click();
      expect(page.menu.get(2).getAttribute('class')).not.toContain('heavy-mute');
    });

    it('should have \'My Events\' title in the center column', function() {
      expect(page.pageEventTitle.getText()).toEqual('My Events');
    });

    it('should have the right icon for the page', function() {
      expect(page.pageEventTitle.$('i').getAttribute('class')).toContain('fa-calendar');
    });

    it('should open the New Event form', function () {
      page.createEvent.click();
      expect(page.eventForm.isDisplayed()).toBe(true);
    });

    it('should validate the New Event form', function() {
      expect(page.eventNameField.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(0).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(0).getText()).toEqual('Event name is required.');
      page.eventNameField.sendKeys('E2E: Test Event');
      expect(page.eventNameField.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(0).getText()).toBe('');

      expect(page.eventStartDue.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(1).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(1).getText()).toEqual('Event start date is required.');
      page.eventStartDue.click();
      page.eventForm.$$('tbody tr td button').last().click();
      expect(page.eventStartDue.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(1).getText()).toBe('');

      expect(page.eventEndDue.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(2).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(2).getText()).toEqual('Event end date is required.');
      page.eventEndDue.click();
      page.eventForm.$$('tbody tr td button').last().click();
      expect(page.eventEndDue.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(2).getText()).toBe('');

      expect(page.eventStartTime.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(3).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(3).getText()).toEqual('Event start time is required.');
      page.eventStartTime.click();
      $('tbody tr:nth-of-type(3) td:first-of-type button').click();
      expect(page.eventStartTime.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(3).getText()).toBe('');

      expect(page.eventEndTime.getAttribute('class')).toContain('ng-invalid');
      expect($$('span.text-danger').get(4).isDisplayed()).toBe(true);
      expect($$('span.text-danger').get(4).getText()).toEqual('Event end time is required.');
      page.eventEndTime.click();
      $('tbody tr:nth-of-type(3) td:first-of-type button').click();
      expect(page.eventEndTime.getAttribute('class')).toContain('ng-valid');
      expect($$('span.text-danger').get(4).getText()).toBe('');
    });

    it('should cancel the New Event Form', function() {
      page.cancelNewEvent.click();
      expect(page.eventForm.isPresent()).toBe(false);
    });

    it('should create a New Event', function() {
      page.createEvent.click();
      expect(page.eventNameField.getAttribute('class')).toContain('ng-invalid');
      page.eventNameField.sendKeys('E2E: Test Event');
      page.eventStartDue.click();
      page.eventForm.$$('tbody tr td button').last().click();
      page.eventEndDue.click();
      page.eventForm.$$('tbody tr td button').last().click();
      page.eventStartTime.click();
      $('tbody tr:nth-of-type(5) td:first-of-type button').click();
      page.eventEndTime.click();
      $('tbody tr:nth-of-type(5) td:first-of-type button').click();
      page.eventLocation.sendKeys('E2E: Test Location');
      page.eventDescription.sendKeys('E2E: Test Description');

      page.submitNewEvent.click();
      expect(page.events.count()).toBeGreaterThan(0);
      expect(myEvents.element(by.binding('eventEntity.name')).getText()).toBe('E2E: Test Event');

    });

    it('should edit an Event', function() {
      myEvents.$('button.edit-event').click();

      expect(page.eventForm.isDisplayed()).toBe(true);
      page.eventNameField.clear();
      page.eventNameField.sendKeys('E2E: Test Event Updated');
      page.submitNewEvent.click();

      expect(page.eventForm.isPresent()).toBe(false);
      expect(page.events.count()).toEqual(1);
      
      expect(myEvents.element(by.binding('eventEntity.name')).getText()).toBe('E2E: Test Event Updated');

    });

    it('should assign an existing project to the Event', function() {
      myEvents.$('button.edit-event').click();

      page.formProjectID.click().then(function(){
         $$('select option').get(1).click().then(function(){
          browser.actions().sendKeys( protractor.Key.ENTER ).perform(); //Firefox hack needed to wait for model to update
          page.submitNewEvent.click();
         });
      });
     
      eventExpandButton.click();

      expect(myEvents.element(by.binding('eventEntity.projectName')).getText()).toEqual('E2E: Test Project updated');

    });

    it('should assign project through Create a New Project to the Event', function() {
      var projectForm = $('form.project-entry');
      projectNameField = projectForm.element(by.model('entityCopy.name'));

      myEvents.$('button.edit-event').click();
      expect(projectForm.isPresent()).toBe(false);

      page.createProjFromEvent.click();
      expect(projectForm.isDisplayed()).toBe(true);
      expect(projectNameField.getAttribute('class')).toContain('ng-invalid');

      projectNameField.sendKeys('E2E: Test Project from Event');
      page.projectDueField.click();

      page.projectDescriptionField.sendKeys('E2E: Test Project description');
      page.projectNotesField.sendKeys('E2E: Test Project notes');

      projectForm.$('a.save').click();
      expect(projectForm.isPresent()).toBe(false);

      page.formProjectID.click().then(function(){
        $$('select option').get(1).click().then(function(){
          browser.actions().sendKeys( protractor.Key.ENTER ).perform();  //Firefox hack needed to wait for model to update
          page.submitNewEvent.click();
        });
      });

      eventExpandButton.click();

      expect(myEvents.element(by.binding('eventEntity.projectName')).getText()).toEqual('E2E: Test Project from Event');
    });
  
    it('should link to project', function() {

      myEvents.element(by.binding('eventEntity.projectName')).click();

      expect(page.tabs.get(0).getAttribute('class')).toContain('active');
      expect(page.tabs.get(1).getAttribute('class')).not.toContain('active');
      expect(page.tabs.get(2).getAttribute('class')).not.toContain('active');

      expect(page.projects.count()).toBe(2);

      var project = page.projects.get(0),
      expandButton =  project.$('button[ng-click="toggle(projectEntity.id)"]'),
      projectDetails = project.$('.project-details');

      expect(expandButton.getAttribute('title')).toEqual('collapse');
      expect(projectDetails.isDisplayed()).toBe(true);
      
      page.projects.get(0).$('button.delete-project').click();

      page.menu.get(2).click();

    });

    xit('should expand and collapse Event content', function () {
      expect(eventExpandButton.getAttribute('title')).toEqual('expand');

      eventExpandButton.click();
      expect(eventExpandButton.getAttribute('title')).toEqual('collapse');
      expect(eventDetails.isDisplayed()).toBe(true);

      eventExpandButton.click();
      expect(eventDetails.isDisplayed()).toBe(false);
      expect(eventExpandButton.getAttribute('title')).toEqual('expand');

      expandLink.click();
      expect(eventDetails.isDisplayed()).toBe(true);
      expect(eventExpandButton.getAttribute('title')).toEqual('collapse');

      eventExpandLink.click();
      expect(eventDetails.isDisplayed()).toBe(false);
      expect(eventExpandButton.getAttribute('title')).toEqual('expand');
    });

    it('should delete an Event', function() {
      page.events.get(0).$('button.delete-event').click();
      expect(page.events.count()).toBe(0);
    });

  });
  
  describe('My Projects Cleanup', function() {
    it('should delete project', function () {
      browser.get('/app/#/project-center/projects');
      page.projects.each(function(project) {;
        project.$('button.delete-project').click();
      });
      expect(page.projects.count()).toBe(0);
    });
  });
});