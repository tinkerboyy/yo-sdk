'use-strict';

var generators = require('yeoman-generator');
var _ = require('lodash');

module.exports = generators.NamedBase.extend({
  
  constructor: function() {
    generators.NamedBase.apply(this, arguments);
  },
  
  writing: function() {
    var folderName = _.kebabCase(this.name);
    var fileName = _.kebabCase(this.name);
    var directiveName = 'ag-' + this.name;
    
    this.fs.copyTpl(
      this.templatePath('ng-directive.js'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/components/directives/' + folderName + '/' + fileName + '-' + 'directive.js'),
      {
        directiveName: _.camelCase(directiveName),
        controller: _.upperFirst(_.camelCase(this.name)) + 'Controller',
        path: folderName,
        template: fileName
      }
    );
    
    this.fs.copyTpl(
      this.templatePath('_directive.html'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/components/directives/' + folderName + '/' + fileName + '.html'),
      {
        directiveName: this.name
      }
    );
    
    this.fs.copyTpl(
      this.templatePath('_directive.txt'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/components/directives/' + folderName + '/' + fileName + '.less'),
      {
        directiveName: 'ag-' + _.kebabCase(this.name)
      }
    );
    
    this.fs.copyTpl(
      this.templatePath('tests/_directive_test.js'),
      this.destinationPath(this.config.get('applicationName') + '/ag-app/app/scripts/components/directives/' + folderName + '/tests/' + fileName + '_test.js'),
      {
        directiveName: fileName,
        name: _.upperFirst(_.camelCase(this.name)),
        path: folderName,
        template: fileName
      }
    );
  }
  
});