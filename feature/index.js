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
    var folderName = _.kebabCase(this.name);
    var fileName = _.kebabCase(this.name);
    this.fs.copyTpl(
      this.templatePath('ng-features.js'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/features/' +  folderName + '/' + fileName + '-' +'module' + '.js'),
      {
        featureName: _.camelCase(this.name),
        appName: this.config.get('appName'),
        controller: _.upperFirst(_.camelCase(this.name)) + 'Controller',
        path: folderName,
        template: fileName,
        route: fileName
      }
    );

    this.fs.copyTpl(
      this.templatePath('_feature.html'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/features/' +  folderName + '/' + fileName + '.html'),
      {
        featureName: this.name
      }
    );

    this.fs.copyTpl(
      this.templatePath('_feature.txt'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/features/' +  folderName + '/' + fileName + '.less'),
      {
        featureName: _.kebabCase(this.name)
      }
    );

     this.fs.copyTpl(
      this.templatePath('tests/_feature_test.js'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/features/' + folderName + '/tests/' + fileName + '_test.js'),
      {
        featureName: _.kebabCase(this.name),
        appName: this.config.get('appName'),
        controller: _.upperFirst(_.camelCase(this.name)) + 'Controller',
        path: folderName,
        template: fileName,
        route: fileName
      }
    );

    this.fs.copyTpl(
      this.templatePath('tests/_feature.e2e.js'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/features/' + folderName + '/tests/' + fileName + '.e2e.js'),
      {
        featureName: _.camelCase(this.name),
        appName: this.config.get('appName'),
        controller: _.upperFirst(_.camelCase(this.name)) + 'Controller',
        path: folderName,
        template: fileName,
        route: fileName
      }
    );

    this.log(chalk.yellow("created feature: "));
    this.log(this.config.get('applicationName') + '/ag-app/app/scripts/features/' +  folderName + '/' + fileName + '-' +'module' + '.js');
    this.log(this.config.get('applicationName') + '/ag-app/app/scripts/features/' +  folderName + '/' + fileName + '.html');
    this.log(this.config.get('applicationName') + '/ag-app/app/scripts/features/' +  folderName + '/' + fileName + '.less');
  }
});
