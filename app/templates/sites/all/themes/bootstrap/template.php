<?php
/**
 * @file
 * template.php
 *
 * This file should only contain light helper functions and stubs pointing to
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `theme` folder named after the
 * function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template implementations also
 * live in the 'theme' folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 * @see _bootstrap_theme()
 * @see theme/registry.inc
 *
 * Due to a bug in Drush, these includes must live inside the 'theme' folder
 * instead of something like 'includes'. If a module or theme has an 'includes'
 * folder, Drush will think it is trying to bootstrap core when it is invoked
 * from inside the particular extension's directory.
 * @see https://drupal.org/node/2102287
 */

/**
 * Include common functions used through out theme.
 */
include_once dirname(__FILE__) . '/theme/common.inc';

/**
 * Implements hook_theme().
 *
 * Register theme hook implementations.
 *
 * The implementations declared by this hook have two purposes: either they
 * specify how a particular render array is to be rendered as HTML (this is
 * usually the case if the theme function is assigned to the render array's
 * #theme property), or they return the HTML that should be returned by an
 * invocation of theme().
 *
 * @see _bootstrap_theme()
 */
function bootstrap_theme(&$existing, $type, $theme, $path) {
  bootstrap_include($theme, 'theme/registry.inc');
  return _bootstrap_theme($existing, $type, $theme, $path);
}

/**
 * Declare various hook_*_alter() hooks.
 *
 * hook_*_alter() implementations must live (via include) inside this file so
 * they are properly detected when drupal_alter() is invoked.
 */
bootstrap_include('bootstrap', 'theme/alter.inc');

function bootstrap_preprocess_image(&$vars) {
	if (isset($vars['style_name'])) {
	  if($vars['style_name'] == 'homepage_feature_thumbnail') {
		$vars['attributes']['class'][] = "img-circle";
	  }
	}
	$vars['attributes']['class'][] = "img-responsive";
}

/**
 * Returns HTML for a form.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #action, #method, #attributes, #children
 *
 * @ingroup themeable
 */
function bootstrap_form($variables) {
  $element = $variables['element'];

  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }

  if(isset($element['sow_search'])) {
    // Anonymous DIV to satisfy XHTML compliance.
    return '<form' . drupal_attributes($element['#attributes']) . '><div class="hidden-xs" id="filterBox">' . $element['#children'] . '</div></form>';
  } else {
    // Anonymous DIV to satisfy XHTML compliance.
    return '<form' . drupal_attributes($element['#attributes']) . '><div>' . $element['#children'] . '</div></form>';
  }
}


/**
 * Returns HTML for a set of checkbox form elements.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #children, #attributes.
 *
 * @ingroup themeable
 */
function bootstrap_checkboxes($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }

  if($element['#id'] == 'edit-labels') {
    return (!empty($element['#children']) ? $element['#children'] : '') . '</ul>';
  } else {
    return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
  }
}

/**
 * Returns HTML for a checkbox form element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #name, #attributes, #checked, #return_value.
 *
 * @ingroup themeable
 */


function _get_file_count($file) {
  $query = "SELECT t.pid FROM {track_da_files_paths} t " .
         "WHERE t.fid = :fid AND t.path = :uri ";

  $result = db_query($query, array(':fid' => $file['fid'], ':uri' => $file['uri']))->fetch();
  if (!empty($result)) {
    $pid = $result->pid;

    $query2 = "SELECT COUNT(t.recid) counter FROM {track_da_files} t " .
              "WHERE t.pid = :pid GROUP BY t.pid ";
    $result2 = db_query($query2, array(':pid' => $pid))->fetch();

    if (!empty($result2)) {
      return $result2->counter;
    } else {
      return 0;
    }
  }
}

function _get_base_url() {
  $protocol = (isset($_SERVER['HTTPS']) && ($_SERVER['HTTPS'] != "off")) ? "https" : "http";
  return $protocol . "://" . $_SERVER['HTTP_HOST'];
}

function region_empty($test_region) {
  /* Check to see if a region is occupied
   * returns 1 if it's empty
   */
  global $theme;

  $test_empty = 1;

  $result = db_query_range('SELECT n.pages, n.visibility FROM {block} n WHERE n.region=:region AND n.theme=:template', 0, 10, array(':region' => $test_region, ':template' => $theme));
  foreach($result as $node) {
    if ($node->visibility < 2) {
      $path = drupal_get_path_alias($_GET['q']);

      // Compare with the internal and path alias (if any).
      $page_match = drupal_match_path($path, $node->pages);
      if ($path != $_GET['q']) {
        $page_match = $page_match || drupal_match_path($_GET['q'], $node->pages);
      }
      // When $block->visibility has a value of 0, the block is displayed on
      // all pages except those listed in $block->pages. When set to 1, it
      // is displayed only on those pages listed in $block->pages.
      $page_match = !($node->visibility xor $page_match);
    } else {
      $page_match = drupal_eval($block->pages);
    }

    if ($page_match)
      $test_empty = 0;
  }
  return $test_empty;
}
