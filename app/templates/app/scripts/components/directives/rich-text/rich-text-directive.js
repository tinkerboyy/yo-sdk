define(
  [
    'angular',
    'components/components-module'
],
  function(angular) {
    angular.module('gateways.components')
      .controller('RichTextController', function($scope, $element, $window) {
        //Set the HTML of the editor to the ngModel for edit mode
        $element.find('.editor').html($scope.data);

        $scope.format = function(type) {
          if (type === 'createLink') {

            var linkText;
            if (document.getSelection) {
              linkText = document.getSelection();
            } else {
              linkText = window.getSelection();
            }
            var regexp = /(ftp|http|https):\/\/(\w+:{0,1}\w*@)?(\S+)(:[0-9]+)?(\/|\/([\w#!:.?+=&%@!\-\/]))?/
              , def = regexp.test(linkText) ? linkText : ''
              , link = $window.prompt('Link Address: \nex: http://www.examplesite.com', def)
              , validate = regexp.exec(link);

            if (validate === null && link !== null) {
              while (!validate) {
                $window.alert('Invalid link: Please type full url address');
                link = $window.prompt('Link Address: \nex: http://www.examplesite.com', link);

                //exit loop if user clicks cancel
                if (link === null) {
                  break;
                }

                validate = regexp.exec(link);
              }
            }

            //assign empty string value if user clicks cancel
            if (link === null) link = '';

            document.execCommand(type, false, link);

            var linkElement = document.querySelectorAll('.rich-text-editor .editor a');
            for (var index = 0; index < linkElement.length; index++) {
              linkElement[index].setAttribute('target', '_blank');
            }

          } else {
            document.execCommand(type);
          }
          $scope.setData();
        };

        $scope.setData = function() {
          $scope.data = $element.find('.editor').html();
        };

        $scope.$on('clear-comment', function() {
          $element.find('.editor').html('');
        });
      })
      .directive('agRichText', function($timeout) {
        return {
          restrict: 'AE',
          replace: true,
          templateUrl: 'scripts/components/directives/rich-text/rich-text.html',
          controller: 'RichTextController',
          scope: {
            data: '=ngModel'
          },
          link: function(scope, elem) {
            var t;
            elem.on('blur keyup change', function() {
              if (t) {
                $timeout.cancel(t);
              }
              t = $timeout(scope.setData, 500);
            });
          }
        };
      });
  }
);
