  define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('agDateFormat', function ($filter) {
        var formats = {
          'long': 'EEEE, MMMM dd, yyyy - HH:mm',
          'short': 'yyyy-MM-dd HH:mm',
          'medium': 'EEE, yyyy-MM-dd HH:mm'
        };
        return function(date, format) {
          return date ? $filter('date')(parseInt(date, 10) * 1000, formats[format] || format) : null;
        };
      });
});
