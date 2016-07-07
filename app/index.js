'use strict';

var generators = require('yeoman-generator');
var _ = require('lodash');
var yosay = require('yosay');
var chalk = require('chalk');
var util = require('util');
var mkdirp = require('mkdirp');
var inquirer = require('inquirer');
var spawnCommand = require('spawn-command');
var path = require('path');
var mv = require('mv');
var spawn = require('child_process').spawn;
var shell = require('shelljs');


var  appRoot = {
      agApp: 'ag-app',
      app: {
        scripts: "",
        assets: ""
      }
    };

module.exports = generators.Base.extend({

  constructor: function() {
    generators.Base.apply(this, arguments);
  },

  initializing: function() {
    this.log(yosay());
  },

  prompting: function() {

  //  this.log(yosay('Welcome to :)' + chalk.yellow(' Madhukar !!! ')));

    var done = this.async();

    inquirer.prompt([{
      type: 'input',
      name: 'applicationName',
      message: 'What\'s your Application Name',
      default: 'acquisition-gateway'
    }, {
      type: 'input',
      name: 'applicationDesc',
      message: 'What\'s your Application Description',
      default: 'acquisition-gateway sample project'
    }, {
      type: 'input',
      name: 'appName',
      message: 'What\'s your ng-app Name',
      default: 'App'
    }], function (answers) {
      this.log('\n');
      this.log('Project Name: ' + chalk.blue.underline.bold(answers.applicationName));
      this.log('Project Description: ' + chalk.blue.underline.bold(answers.applicationDesc));
      this.log('Angular App Name: ' + chalk.blue.underline.bold(answers.appName));
      this.log('\n');

      this.config.set('applicationName', answers.applicationName);
      this.config.set('applicationDesc', answers.applicationDesc);
      this.config.set('appName', answers.appName);
      this.config.save();

      done();
    }.bind(this));
  },

  configuring: function() {},

  default: function() {},

  writing:  {

    scaffoldFolders: function() {
      this.log(chalk.yellow('scafolding ' + this.config.get('applicationName')));
      this.log('\n');

      mkdirp(this.config.get('applicationName'));
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/assets');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/assets/css');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/assets/images');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/assets/less');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/vendor');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts/components');
      mkdirp(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts/features');
      mkdirp(this.config.get('applicationName') + '/assets');
      mkdirp(this.config.get('applicationName') + '/assets/js');
    },
    // write the package.json files
    nodeModules: function() {
      this.fs.copyTpl(
        this.templatePath('_package.json'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'package.json'),
        {
          name: this.config.get('appName'),
          title: 'This is ' + this.config.get('appName') + ' node packages',
          desc: this.config.get(this.config.get('applicationDesc'))
        }
      );
    },
    // write the bower.json and the dependencies
    bower: function () {
      this.fs.copyTpl(
        this.templatePath('_bower.json'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'bower.json'),
        {
          name: this.config.get('applicationName'),
          title: 'This is ' + this.config.get('appName') + ' node packages',
          desc: this.config.get(this.config.get('applicationDesc'))
        }
      );
    },
    // copy gulpfile
    gulp: function() {
      this.fs.copyTpl(
        this.templatePath('_gulpfile.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'gulpfile.js'),
        {
          title: 'This is ' + this.config.get('applicationName') + ' gulpfile'
        }
      );
    },
     // copy jshintrc
    jshint: function() {
      this.fs.copy(
        this.templatePath('_jshintrc'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'.jshintrc')
      );
    },
    // copy jscsrc
    jscs: function() {
      this.fs.copy(
        this.templatePath('_jscsrc'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'.jscsrc')
      );
    },
    // karma configuration
    karma: function() {
      this.fs.copy(
        this.templatePath('_karma.conf.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'karma.conf.js')
      );
    },
    // protractor configuration
    protractor: function() {
      this.fs.copy(
        this.templatePath('_protractor.conf.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'protractor.conf.js')
      );
    },
    // requirejs test main
    testMain: function() {
      this.fs.copy(
        this.templatePath('_test-main.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'test-main.js')
      );
    },

    app: function() {
      this.directory('app/assets', this.config.get('applicationName') + '/' + appRoot.agApp + '/app/assets');
      this.directory('app/scripts/components', this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts/components');
      this.directory('app/scripts/features', this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts/features');
     // this.directory('app/vendor', this.config.get('applicationName') + '/' + appRoot.agApp + '/app/vendor');

      this.fs.copyTpl(
        this.templatePath('app/scripts/_app.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts' + '/' + 'app.js'),
        {
          ngApp: this.config.get('appName')
        }
      );

      this.fs.copyTpl(
        this.templatePath('app/scripts/_public.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts' + '/' + 'public.js'),
        {
          ngApp: this.config.get('appName')
        }
      );

      this.fs.copyTpl(
        this.templatePath('app/scripts/_main.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts' + '/' + 'main.js'),
        {
          ngApp: this.config.get('appName')
        }
      );

      this.fs.copyTpl(
        this.templatePath('app/scripts/_public-main.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/scripts' + '/' + 'public-main.js'),
        {
          ngApp: this.config.get('appName')
        }
      );

      this.fs.copyTpl(
        this.templatePath('app/index.php'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/app/index.php'),
        {
          ngApp: this.config.get('appName')
        }
      );
    },

    appStaticFiles: function() {
      // copy bowerrc
      this.fs.copy(
        this.templatePath('_bowerrc'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'.bowerrc')
      );
      // copy gitignore
      this.fs.copy(
        this.templatePath('_gitignore'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'.gitignore')
      );
      // copy editorconfig
      this.fs.copy(
        this.templatePath('_editorconfig'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'.editorconfig')
      );
      // copy csv-reporter
      this.fs.copy(
        this.templatePath('_csv-reporter.js'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'csv-reporter.js')
      );

      this.fs.copy(
        this.templatePath('README.md'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'README.md')
      );
      // setting up dev environment markdown
      this.fs.copy(
        this.templatePath('setting-up-dev-environment.md'),
        this.destinationPath(this.config.get('applicationName') + '/' + appRoot.agApp + '/' +'setting-up-dev-environment.md')
      );

    },

    assets: function() {
      this.directory('assets/art', this.config.get('applicationName') + '/assets/art');
      this.directory('assets/css', this.config.get('applicationName') + '/assets/css');
      this.directory('assets/fonts', this.config.get('applicationName') + '/assets/fonts');
      this.directory('assets/art', this.config.get('applicationName')+ '/assets/art');
      this.directory('assets/js/swagger-ui/lang', this.config.get('applicationName') + '/assets/js/swagger-ui/lang');
      this.directory('assets/js/swagger-ui/css', this.config.get('applicationName') + '/assets/js/swagger-ui/css');
      this.directory('assets/js/swagger-ui/fonts', this.config.get('applicationName') + '/assets/js/swagger-ui/fonts');
      this.directory('assets/js/swagger-ui/images', this.config.get('applicationName') + '/assets/js/swagger-ui/images');

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/index.html'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/index.html')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/o2c.html'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/o2c.html')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/swagger-ui.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/swagger-ui.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/swagger-ui.min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/swagger-ui.min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/underscore-min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/underscore-min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/backbone-min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/backbone-min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/handlebars-2.0.0.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/handlebars-2.0.0.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/highlight.7.3.pack.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/highlight.7.3.pack.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/jquery-1.8.0.min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/jquery-1.8.0.min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/jquery.ba-bbq.min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/jquery.ba-bbq.min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/jquery.slideto.min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/jquery.slideto.min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/jquery.wiggle.min.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/jquery.wiggle.min.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/marked.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/marked.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/swagger-oauth.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/swagger-oauth.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/swagger-ui/lib/underscore-min.map'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/swagger-ui/lib/underscore-min.map')
      );

      this.fs.copy(
        this.templatePath('assets/js/cap-os-v1-custom.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/cap-os-v1-custom.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/cap-os-v1-custom.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/cap-os-v1-custom.js')
      );

       this.fs.copy(
        this.templatePath('assets/js/cap-os-v1-foot.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/cap-os-v1-foot.js')
      );

      this.fs.copy(
        this.templatePath('assets/js/cap-os-v1-head.js'),
        this.destinationPath(this.config.get('applicationName') + '/assets/js/cap-os-v1-head.js')
      );
    },

    global: function() {
      // copy gitignore
      this.fs.copy(
        this.templatePath('_gitignore'),
        this.destinationPath(this.config.get('applicationName') + '/.gitignore')
      );

       this.fs.copy(
        this.templatePath('_gitignore'),
        this.destinationPath('.gitignore')
      );

      this.fs.copy(
        this.templatePath('_htaccess'),
        this.destinationPath(this.config.get('applicationName') + '/.htaccess')
      );
    },

    staticModules: function() {
      this.directory('homepage', this.config.get('applicationName') + '/homepage');
      this.directory('includes', this.config.get('applicationName') + '/includes');
      this.directory('misc', this.config.get('applicationName') + '/misc');
      this.directory('modules', this.config.get('applicationName') + '/modules');
      this.directory('profiles', this.config.get('applicationName') + '/profiles');
      this.directory('scripts', this.config.get('applicationName') + '/scripts');
      this.directory('sites', this.config.get('applicationName') + '/sites');
      this.directory('solutionsfinder', this.config.get('applicationName') + '/solutionsfinder');
      this.directory('themes', this.config.get('applicationName') + '/themes');

      this.fs.copy(
        this.templatePath('content.menu.inc'),
        this.destinationPath(this.config.get('applicationName') + '/sites/all/modules/ctools/includes/content.menu.inc')
      );
    },

    staticPhp: function() {
      this.fs.copy(
        this.templatePath('xmlrpc.php'),
        this.destinationPath(this.config.get('applicationName') + '/xmlrpc.php')
      );

       this.fs.copy(
        this.templatePath('web.config'),
        this.destinationPath(this.config.get('applicationName') + '/web.config')
      );

      this.fs.copy(
        this.templatePath('update.php'),
        this.destinationPath(this.config.get('applicationName') + '/update.php')
      );

      this.fs.copy(
        this.templatePath('title'),
        this.destinationPath(this.config.get('applicationName') + '/title')
      );

      this.fs.copy(
        this.templatePath('solution_matrix.php'),
        this.destinationPath(this.config.get('applicationName') + '/solution_matrix.php')
      );

      this.fs.copy(
        this.templatePath('search_queries.csv'),
        this.destinationPath(this.config.get('applicationName') + '/search_queries.csv')
      );

      this.fs.copy(
        this.templatePath('scrTest.php'),
        this.destinationPath(this.config.get('applicationName') + '/scrTest.php')
      );

      this.fs.copy(
        this.templatePath('robots.txt'),
        this.destinationPath(this.config.get('applicationName') + '/robots.txt')
      );

      this.fs.copy(
        this.templatePath('public-gateway.php'),
        this.destinationPath(this.config.get('applicationName') + '/public-gateway.php')
      );

      this.fs.copy(
        this.templatePath('policy.php'),
        this.destinationPath(this.config.get('applicationName') + '/policy.php')
      );

      this.fs.copy(
        this.templatePath('install.php'),
        this.destinationPath(this.config.get('applicationName') + '/install.php')
      );

      this.fs.copy(
        this.templatePath('faq.php'),
        this.destinationPath(this.config.get('applicationName') + '/faq.php')
      );

      this.fs.copy(
        this.templatePath('cron.php'),
        this.destinationPath(this.config.get('applicationName') + '/cron.php')
      );

      this.fs.copy(
        this.templatePath('contract_solutions.sql'),
        this.destinationPath(this.config.get('applicationName') + '/contracts_solutions.sql')
      );

      this.fs.copy(
        this.templatePath('contract_solutions.csv'),
        this.destinationPath(this.config.get('applicationName') + '/contracts_solutions.csv')
      );

      this.fs.copy(
        this.templatePath('authorize.php'),
        this.destinationPath(this.config.get('applicationName') + '/authorize.php')
      );
    },

    html: function() {
      this.fs.copyTpl(
        this.templatePath('_index.php'),
        this.destinationPath(this.config.get('applicationName') + '/index.php'),
        {
          name: ''
        }
      );
    },
    // dummy drush scripts
    data: function() {
      this.directory('data', this.config.get('applicationName') + '/data');
    },

    scripts: function() {}

  },

  conflicts: function() {},

  install: function() {
    this.log(chalk.yellow('Welcome to ' + this.config.get('applicationName')));
   //this.installDependencies();
  },

  end: function() {
    var elementDir = process.cwd();
  }

});
