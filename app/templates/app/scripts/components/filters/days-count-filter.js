define(
  [
    'angular',
    'components/components-module'
  ],
  function(angular) {
    angular.module('gateways.components')
      .filter('agDaysCount', function () {
        var secondsPerDay = 24 * 60 * 60;
        // from and to are seconds
        return function(date, from, to) {
          if (from === 'now') {
            from = Math.ceil(new Date().getTime() / 1000);
          }

          if (to === 'now') {
            to = Math.ceil(new Date().getTime() / 1000);
          }

          return Math.ceil((to - from) / secondsPerDay);
        };
      });
});
