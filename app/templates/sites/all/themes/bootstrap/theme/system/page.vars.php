<?php
/**
 * @file
 * page.vars.php
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function bootstrap_preprocess_page(&$variables) {

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-6"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-9"';
  }
  else {
    $variables['content_column_class'] = ' class="col-sm-12"';
  }

  // Primary nav.
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links.
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Build links.
    $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function.
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

  $variables['navbar_classes_array'] = array('navbar');

  if (theme_get_setting('bootstrap_navbar_position') !== '') {
    $variables['navbar_classes_array'][] = 'navbar-' . theme_get_setting('bootstrap_navbar_position');
  }
  else {
    $variables['navbar_classes_array'][] = 'container';
  }
  if (theme_get_setting('bootstrap_navbar_inverse')) {
    $variables['navbar_classes_array'][] = 'navbar-inverse';
  }
  else {
    $variables['navbar_classes_array'][] = 'navbar-default';
  }

  //JT 9/24/14 to enable page.tpl.php override for specific content type
  if (isset($variables['node']->type)) {
    // If the content type's machine name is "my_machine_name" the file
    // name will be "page--my-machine-name.tpl.php".
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

  // get list of views pages
  $views_page = views_get_page_view();
  $variables['label_root'] = null;
  $variables['label_sub'] = null;

  // if it's for sow search
  if (isset($views_page->name) && $views_page->name === "sow_search") {
    $variables['theme_hook_suggestions'][] = 'page__views__sow_search';

    $variables['pager']      = '';

    if ($views_page->display_handler->render_pager()) {
      $exposed_input = isset($views_page->exposed_raw_input) ? $views_page->exposed_raw_input : NULL;
      $variables['pager']      = $views_page->query->render_pager($exposed_input);
    }

    $query = drupal_get_query_parameters();

    $variables['node_details_view'] = FALSE;

    if (isset($query['sow_search'])) {
      $variables['sow_search_value'] = $query['sow_search'];
    }

  } else if (isset($variables['node']) && $variables['node']->type == 'sow') {
    $variables['theme_hook_suggestions'][] = 'page__views__sow_search';
    $variables['node_details_view'] = TRUE;
  } else if (isset($variables['node']) && $variables['node']->nid == 270) {
    $variables['theme_hook_suggestions'][] = 'page__views__sow_search';
  }
  if (isset($views_page->name)) {
    if ($views_page->name === "category_results_logistics" || $views_page->name === "sow_search") {
      if (is_numeric(arg(1))) {
        $tid = arg(1);
      } else if(drupal_get_query_parameters() > 0) {
        $querystring = drupal_get_query_parameters();
        if (array_key_exists('labels', $querystring)) {
          $terms = taxonomy_get_term_by_name($views_page->exposed_data['field_sow_category2_name'], 'category');

          if (!empty($terms)) {
            $first_term = array_shift($terms);
            $tid = $first_term->tid;
          }
        }
      }
    }

    if (isset($tid)) {
      $term = db_query("SELECT * FROM {taxonomy_term_data} WHERE tid = :tid", array(':tid' => $tid))->fetchAll();
      $parent_id = taxonomy_get_parents($tid);

      if (count($parent_id) > 0) {
        $variables['label_root'] = $parent_id[key($parent_id)]->name;
        $variables['label_sub'] = $term[0]->name;
      } else {
        $variables['label_root'] = $term[0]->name;
      }
    }

    $variables['node_details_view'] = FALSE;
    $variables['theme_hook_suggestions'][] = 'page__views__sow_search';
  }
}

/**
 * Implements hook_process_page().
 *
 * @see page.tpl.php
 */
function bootstrap_process_page(&$variables) {
  $variables['navbar_classes'] = implode(' ', $variables['navbar_classes_array']);
}
