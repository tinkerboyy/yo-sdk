define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    /**
      * This filters out html tags
      * @param text {string}, data that contains html tags
      * @return out filtered string without html tags
      */
    angular.module('gateways.components')
      .filter('stripHTML', function() {
        return function(text) {
          if (text) {
            var regex = /(<([^>]+)>)/ig;
            return text.replace(regex, '');
        }
       };
    });
});
