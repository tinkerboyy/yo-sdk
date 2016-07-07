/**
 * Created by Madhukar on 10/15/15.
 */
define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .directive('agPdf', function() {
        return {
          restrict: 'AE',
          link: function(scope, element, attrs) {
            var url = attrs.data;
            url = url.search('{{') >= 0 ? scope.$eval(attrs.data) : url;
            element.replaceWith('<object ng-if="!addToProjectModal || (addToProjectModal && !isMSIE) " data="' + url + '" type="application/pdf" width="100%" height="600px" wmode="opaque"><p>It appears you do not have a PDF plugin for this browser. No biggie... you can <a href="' + url + '" target="_blank">click here to download the PDF file.</a></p></object>');
          }
        };

      });
  }
);
