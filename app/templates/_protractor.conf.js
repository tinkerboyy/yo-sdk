
exports.config = {

  chromeDriver: null,

  chromeOnly: false,

  seleniumArgs: [],

  allScriptsTimeout: 120000,

  specs: [
    './app/scripts/features/**/tests/*.e2e.js',
  ],

  exclude: [],

  capabilities: {
    'browserName': 'firefox'
  },

  rootElement: 'body',

  onPrepare: function() {
    browser.params.publicUser = browser.params.publicUser && browser.params.publicUser !== 'undefined' ? true : false;
    var SpecReporter = require('jasmine-csv-reporter');
    require('jasmine2-custom-message');
    require('jasmine-expect');
    // add jasmine spec reporter
    jasmine.getEnv().addReporter(new SpecReporter({displayStacktrace: true}));

    browser.driver.manage().window().maximize();

    if (browser.params.publicUser) {
      browser.driver.get(browser.baseUrl + '/public-gateway.php');
      //browser.driver.findElement(by.css('a.login-information-button')).click();
    } else {
      browser.driver.get(browser.baseUrl + '/user');
      browser.driver.get(browser.baseUrl + '/user');
      browser.driver.findElement(by.css('#edit-name')).sendKeys(browser.params.username);
      browser.driver.findElement(by.css('#edit-pass')).sendKeys(browser.params.password);
      browser.driver.findElement(by.css('#edit-submit')).click();
      browser.driver.wait(function() {
        return browser.driver.isElementPresent(by.css('#heroContent')).then(function() {
          return true;
        });
      });

      browser.driver.get(browser.baseUrl + '/app/#/');
    }


    browser.driver.wait(function() {
      return browser.driver.getCurrentUrl().then(function(url) {
        return /\/app\/#\//.test(url);
      });
    });
  },

  framework: 'jasmine2',

  jasmineOpts: {
    ui: 'bdd',
    reporter: 'csv-reporter'
  },

  onCleanUp: function() {},

  jasmineNodeOpts: {
    silent: false,
    defaultTimeoutInterval: 120000,
    showColors: true,
    print: function() {}
  }
};
