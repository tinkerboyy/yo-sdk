define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('getBlurb', function() {
        return function(str, length) {
          //Strip html tags from string
          var tmp = document.createElement('DIV');
          tmp.innerHTML = str;
          str =  tmp.textContent || tmp.innerText || '';

          //if returning full length string, don't strip markup
          if (str.length <= length) {
            return str;
          } else {
            if (str.length > length) {
              str = str.substring(0, length);
              str = str.substring(0, str.lastIndexOf(' '));
              str += ' ...';
            }

            return str;
          }
        };
      });
  }
);
