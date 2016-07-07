/* configuration for setting up filters */

'use-strict';

var generators = require('yeoman-generator');
var _ = require('lodash');
var chalk = require('chalk')

module.exports = generators.NamedBase.extend({

  constructor: function() {

    generators.NamedBase.apply(this, arguments);

   // this.name = _.kebabCase(this.name);
  },

  writing: function() {
    var fileName = _.kebabCase(this.name);
    this.fs.copyTpl(
      this.templatePath('ng-filters.js'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/components/filters/' + fileName + '-' +'filter' + '.js'),
      {
        appName: this.config.get('appName'),
        filterName: _.camelCase(this.name)
      }
    );
    
    this.fs.copyTpl(
    this.templatePath('tests/_feature_test.js'),
    this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/components/filters/tests/' + fileName + '_test.js'),
    {
       appName: this.config.get('appName'),
       filterName: _.camelCase(this.name),
      }
    );

    this.log(chalk.yellow("created files: "));
    this.log(this.config.get('applicationName') + '/ag-app/app/scripts/filters/' + fileName + '-' +'filter' + '.js');
    this.log(this.config.get('applicationName') + '/ag-app/app/scripts/filters/tests/' + fileName + '_test.js');
  }
});

