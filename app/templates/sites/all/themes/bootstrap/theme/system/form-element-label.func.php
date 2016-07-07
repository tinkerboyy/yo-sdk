<?php
/**
 * @file
 * form-element-label.func.php
 */

/**
 * Overrides theme_form_element_label().
 */
function bootstrap_form_element_label(&$variables) {
  $element = $variables['element'];

  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // Determine if certain things should skip for checkbox or radio elements.
  $skip = (isset($element['#type']) && ('checkbox' === $element['#type'] || 'radio' === $element['#type']));

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '' && !$skip) && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();

  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after' && !$skip) {
    $attributes['class'][] = $element['#type'];
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'][] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // Insert radio and checkboxes inside label elements.
  $output = '';
  if (isset($variables['#children'])) {
    $output .= $variables['#children'];
  }

  // if (!path_is_admin(current_path()) && !region_empty('sow_content_modal')) {
  if (!path_is_admin(current_path()) && !region_empty('sow_content_modal')) {
    if (isset($element['#name']) && $element['#name'] == 'title') {
      // The leading whitespace helps visually separate fields from inline labels.
      return ' <label' . drupal_attributes($attributes) . '><h3><span class="label label-warning">1</span> Please create a title for your SOW.</h3>' . "</label>\n";
    } else if (isset($element['#name']) && $element['#name'] == 'field_agency[und][0][value]') {
      return ' <label' . drupal_attributes($attributes) . '><h3><span class="label label-warning">2</span> Please provide your Agency.</h3>' . "</label>\n";
    } else if (isset($element['#name']) && $element['#name'] == 'field_upload[und][0]') {
      return ' <label' . drupal_attributes($attributes) . '><h4>To upload your SOW in <span class="fa fa-file-pdf-o" style="color:red;"></span> PDF format:</h4>' . "</label>\n";
    } else if (isset($element['#name']) && $element['#name'] == 'field_word_document_upload[und][0]') {
      $header = '<div><label for="titleLabel">
                  <h3><span class="label label-warning">3</span> Choose your file format. <small>The preferred format is <span class="fa fa-file-word-o"></span> MS Word (.doc, or .docx). For convenience, you may also include <span class="fa fa-file-pdf-o"></span> PDF format.</small></h3>
                </label></div>';
      return $header . ' <label' . drupal_attributes($attributes) . '><h4>To upload your SOW in <span class="fa fa-file-word-o" style="color:blue;"></span> MS Word format:</h4>' . "</label>\n";
    }
  } else {
    // The leading whitespace helps visually separate fields from inline labels.
    return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
  }
  // Append label.
  // $output .= $t('!title !required', array('!title' => $title, '!required' => $required));

  // // The leading whitespace helps visually separate fields from inline labels.
  // return ' <label' . drupal_attributes($attributes) . '>' . $output . "</label>\n";
}
