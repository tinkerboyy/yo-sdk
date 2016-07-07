(function ($) {
  Drupal.behaviors.pahtAutoSowUserSubmit = {
    attach: function (context, settings) {
      $('input#edit-path-pathauto', context).once('pathAutoChecked', function () {
        $(this).prop('checked', true);
      });
    }
  };
}(jQuery));
