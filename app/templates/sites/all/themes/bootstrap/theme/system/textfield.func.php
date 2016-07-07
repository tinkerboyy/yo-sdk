<?php
/**
 * @file
 * textfield.func.php
 */

/**
 * Overrides theme_textfield().
 */
function bootstrap_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  $extra = '';
  $attributes = array();
  $output = null;

  if (!path_is_admin(current_path()) && !region_empty('sow_content_modal')) {
    element_set_attributes($element, array('id', 'name'));
    // _form_set_class($element, array('form-control'));

    if (isset($element['#name']) && $element['#name'] == 'title') {
      $element['#attributes']['placeholder'] = t('Enter SOW title here');
    } else if (isset($element['#name']) && $element['#name'] == 'field_agency[und][0][value]') {
      $element['#attributes']['placeholder'] = t('Your Agency');
    }
  } else {
    element_set_attributes($element, array(
      'id',
      'name',
      'value',
      'size',
      'maxlength',
    ));
    _form_set_class($element, array('form-text'));

    if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
      drupal_add_library('system', 'drupal.autocomplete');
      $element['#attributes']['class'][] = 'form-autocomplete';

      $attributes['type'] = 'hidden';
      $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
      $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
      $attributes['disabled'] = 'disabled';
      $attributes['class'][] = 'autocomplete';
      $output = '<div class="input-group">' . $output . '<span class="input-group-addon">' . _bootstrap_icon('refresh') . '</span></div>';
      $extra = '<input' . drupal_attributes($attributes) . ' />';
    }
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}
