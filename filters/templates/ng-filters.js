define(
  [
    'angular',
    'lodash',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('<%= appName %>.components')
      .filter('<%= filterName %>', function () {
        
      });
  }
);