<?php
/**
 * @file
 * button.vars.php
 */

/**
 * Implements hook_preprocess_button().
 */
function bootstrap_preprocess_button(&$vars) {
  if($vars['element']['#id'] != 'edit-submit-sow-search') {
    $vars['element']['#attributes']['class'][] = 'btn';
    if (isset($vars['element']['#value'])) {
      if ($class = _bootstrap_colorize_button($vars['element']['#value'])) {
        $vars['element']['#attributes']['class'][] = $class;
      }
    }
  }
}