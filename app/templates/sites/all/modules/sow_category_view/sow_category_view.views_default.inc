<?php
/**
 * @file
 * sow_category_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sow_category_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'category_test';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sow category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'SOWL Categories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_public_private' => 'field_public_private',
    'status' => 'status',
    'field_sow_category2' => 'field_sow_category2',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_public_private' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sow_category2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'SOWL Documents along with Category and SubCategory list <br/>
Displaying @start - @end of @total';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<style> 
.views-exposed-widget .form-checkboxes { 
display: none;
}
</style>';
  $handler->display->display_options['footer']['area']['format'] = 'list_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Public / Private */
  $handler->display->display_options['fields']['field_public_private']['id'] = 'field_public_private';
  $handler->display->display_options['fields']['field_public_private']['table'] = 'field_data_field_public_private';
  $handler->display->display_options['fields']['field_public_private']['field'] = 'field_public_private';
  $handler->display->display_options['fields']['field_public_private']['label'] = 'Public';
  $handler->display->display_options['fields']['field_public_private']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_public_private']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_public_private']['empty'] = 'No';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_sow_category2']['id'] = 'field_sow_category2';
  $handler->display->display_options['fields']['field_sow_category2']['table'] = 'field_data_field_sow_category2';
  $handler->display->display_options['fields']['field_sow_category2']['field'] = 'field_sow_category2';
  $handler->display->display_options['fields']['field_sow_category2']['type'] = 'hs_taxonomy_term_reference_hierarchical_links';
  $handler->display->display_options['fields']['field_sow_category2']['settings'] = array(
    'linked' => 0,
  );
  $handler->display->display_options['fields']['field_sow_category2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sow_category2']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_sow_category2']['separator'] = '\\n';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64 => 0,
    63 => 0,
    3 => 0,
    4 => 0,
    57 => 0,
    59 => 0,
    58 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    23 => 0,
    9 => 0,
    10 => 0,
    60 => 0,
    14 => 0,
    62 => 0,
    15 => 0,
    61 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    27 => 0,
    29 => 0,
    28 => 0,
    24 => 0,
    26 => 0,
    25 => 0,
    30 => 0,
    32 => 0,
    31 => 0,
    33 => 0,
    35 => 0,
    34 => 0,
    36 => 0,
    38 => 0,
    37 => 0,
    39 => 0,
    41 => 0,
    40 => 0,
    42 => 0,
    44 => 0,
    43 => 0,
    45 => 0,
    47 => 0,
    46 => 0,
    48 => 0,
    50 => 0,
    49 => 0,
    51 => 0,
    53 => 0,
    52 => 0,
    54 => 0,
    56 => 0,
    55 => 0,
    65 => 0,
    67 => 0,
    66 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    68 => 0,
    70 => 0,
    69 => 0,
    71 => 0,
    72 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sow' => 'sow',
  );
  /* Filter criterion: Content: Label (field_sow_category2) */
  $handler->display->display_options['filters']['field_sow_category2_tid']['id'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['table'] = 'field_data_field_sow_category2';
  $handler->display->display_options['filters']['field_sow_category2_tid']['field'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['value'] = 'All';
  $handler->display->display_options['filters']['field_sow_category2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['operator_id'] = 'field_sow_category2_tid_op';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['label'] = 'Label (field_sow_category2)';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['operator'] = 'field_sow_category2_tid_op';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['identifier'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    222 => 0,
    221 => 0,
    3 => 0,
    4 => 0,
    57 => 0,
    59 => 0,
    58 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    23 => 0,
    9 => 0,
    10 => 0,
    60 => 0,
    14 => 0,
    62 => 0,
    15 => 0,
    61 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    27 => 0,
    29 => 0,
    28 => 0,
    24 => 0,
    26 => 0,
    25 => 0,
    30 => 0,
    32 => 0,
    31 => 0,
    33 => 0,
    35 => 0,
    34 => 0,
    36 => 0,
    38 => 0,
    37 => 0,
    39 => 0,
    41 => 0,
    40 => 0,
    42 => 0,
    44 => 0,
    43 => 0,
    45 => 0,
    47 => 0,
    46 => 0,
    48 => 0,
    50 => 0,
    49 => 0,
    51 => 0,
    53 => 0,
    52 => 0,
    54 => 0,
    56 => 0,
    55 => 0,
    223 => 0,
    224 => 0,
    225 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    226 => 0,
    227 => 0,
    228 => 0,
    229 => 0,
    230 => 0,
  );
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['label'] = 'Label (field_sow_category2)';
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['identifier'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_sow_category2_tid']['vocabulary'] = 'category';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_public_private' => 'field_public_private',
    'status' => 'status',
    'field_sow_category2' => 'field_sow_category2',
    'changed' => 'changed',
    'path' => 'path',
    'edit_node' => 'edit_node',
    'last_editor' => 'last_editor',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_public_private' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sow_category2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_editor' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64 => 0,
    63 => 0,
    3 => 0,
    4 => 0,
    57 => 0,
    59 => 0,
    58 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    23 => 0,
    9 => 0,
    10 => 0,
    60 => 0,
    14 => 0,
    62 => 0,
    15 => 0,
    61 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    27 => 0,
    29 => 0,
    28 => 0,
    24 => 0,
    26 => 0,
    25 => 0,
    30 => 0,
    32 => 0,
    31 => 0,
    33 => 0,
    35 => 0,
    34 => 0,
    36 => 0,
    38 => 0,
    37 => 0,
    39 => 0,
    41 => 0,
    40 => 0,
    42 => 0,
    44 => 0,
    43 => 0,
    45 => 0,
    47 => 0,
    46 => 0,
    48 => 0,
    50 => 0,
    49 => 0,
    51 => 0,
    53 => 0,
    52 => 0,
    54 => 0,
    56 => 0,
    55 => 0,
    65 => 0,
    67 => 0,
    66 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    68 => 0,
    70 => 0,
    69 => 0,
    71 => 0,
    72 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sow' => 'sow',
  );
  /* Filter criterion: Content: Label (field_sow_category2) */
  $handler->display->display_options['filters']['field_sow_category2_tid']['id'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['table'] = 'field_data_field_sow_category2';
  $handler->display->display_options['filters']['field_sow_category2_tid']['field'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['value'] = 'All';
  $handler->display->display_options['filters']['field_sow_category2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['operator_id'] = 'field_sow_category2_tid_op';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['label'] = 'Label (field_sow_category2)';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['operator'] = 'field_sow_category2_tid_op';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['identifier'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    222 => 0,
    221 => 0,
    3 => 0,
    4 => 0,
    57 => 0,
    59 => 0,
    58 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    23 => 0,
    9 => 0,
    10 => 0,
    60 => 0,
    14 => 0,
    62 => 0,
    15 => 0,
    61 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    27 => 0,
    29 => 0,
    28 => 0,
    24 => 0,
    26 => 0,
    25 => 0,
    30 => 0,
    32 => 0,
    31 => 0,
    33 => 0,
    35 => 0,
    34 => 0,
    36 => 0,
    38 => 0,
    37 => 0,
    39 => 0,
    41 => 0,
    40 => 0,
    42 => 0,
    44 => 0,
    43 => 0,
    45 => 0,
    47 => 0,
    46 => 0,
    48 => 0,
    50 => 0,
    49 => 0,
    51 => 0,
    53 => 0,
    52 => 0,
    54 => 0,
    56 => 0,
    55 => 0,
    223 => 0,
    224 => 0,
    225 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    226 => 0,
    227 => 0,
    228 => 0,
    229 => 0,
    230 => 0,
  );
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['label'] = 'Label (field_sow_category2)';
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['identifier'] = 'field_sow_category2_tid';
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_sow_category2_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_sow_category2_tid']['vocabulary'] = 'category';
  $handler->display->display_options['path'] = 'admin/sow-category-view';
  $export['category_test'] = $view;

  return $export;
}
