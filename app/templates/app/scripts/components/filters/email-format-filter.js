define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    /**
      * Searches for emails within a string and replaces with mailto tag wrapped around emails
      * @param $sce, a service that allows safe rendering of html within a string
      * @param info {string} of point of contact for a specific solution
      * @return out filtered string which includes emails wrapped in an mailto link tag
      */
    angular.module('gateways.components')
      .filter('emailFormat', function($sce) {
        return function(info) {
          var regex = /[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}/g
            , pocText = info.replace(regex, function(x) {
                var newEmail = '<a href="mailto:' + x + '">' + x + '</a>';
                return newEmail;
              });
          return $sce.trustAsHtml(pocText);
        };
    });
});
