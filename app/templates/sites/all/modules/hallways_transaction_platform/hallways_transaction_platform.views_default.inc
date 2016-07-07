<?php
/**
 * @file
 * hallways_transaction_platform.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hallways_transaction_platform_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hallways_transactional_platforms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hallways Transactional Platforms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Transactional Url */
  $handler->display->display_options['fields']['field_transactional_url']['id'] = 'field_transactional_url';
  $handler->display->display_options['fields']['field_transactional_url']['table'] = 'field_data_field_transactional_url';
  $handler->display->display_options['fields']['field_transactional_url']['field'] = 'field_transactional_url';
  $handler->display->display_options['fields']['field_transactional_url']['label'] = '';
  $handler->display->display_options['fields']['field_transactional_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transactional_url']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_transactional_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transactional_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_transactional_url']['type'] = 'link_absolute';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row">
<div class="col-sm-3"><a href="[field_transactional_url]" target="_blank">[title]</a></div>

<div class="col-sm-9">[body]</div>
</div>
<hr>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    84 => '84',
    872 => '872',
    85 => '85',
    86 => '86',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Administrative Transactional Platform */
  $handler = $view->new_display('block', 'Administrative Transactional Platform', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    84 => '84',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: IT Hardware Transactional Platform */
  $handler = $view->new_display('block', 'IT Hardware Transactional Platform', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    85 => '85',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: IT Software Transactional Platform */
  $handler = $view->new_display('block', 'IT Software Transactional Platform', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    86 => '86',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Small Package Delivery Transactional Platform */
  $handler = $view->new_display('block', 'Small Package Delivery Transactional Platform', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    874 => '874',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Talent Development */
  $handler = $view->new_display('block', 'Talent Development', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    885 => '885',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Professional Services */
  $handler = $view->new_display('block', 'Professional Services', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    884 => '884',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Tools and Hardware */
  $handler = $view->new_display('block', 'Tools and Hardware', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    904 => '904',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Cleaning Supplies */
  $handler = $view->new_display('block', 'Cleaning Supplies', 'block_7');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    897 => '897',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Workplace Environment */
  $handler = $view->new_display('block', 'Workplace Environment', 'block_8');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    901 => '901',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Telecommunications */
  $handler = $view->new_display('block', 'Telecommunications', 'block_9');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    909 => '909',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Employee Relocation */
  $handler = $view->new_display('block', 'Employee Relocation', 'block_10');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    913 => '913',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Freight */
  $handler = $view->new_display('block', 'Freight', 'block_11');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    911 => '911',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: IT Security */
  $handler = $view->new_display('block', 'IT Security', 'block_12');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    912 => '912',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: IT Services */
  $handler = $view->new_display('block', 'IT Services', 'block_13');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    914 => '914',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Motor Vehicles */
  $handler = $view->new_display('block', 'Motor Vehicles', 'block_14');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    915 => '915',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Travel */
  $handler = $view->new_display('block', 'Travel', 'block_15');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    916 => '916',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';

  /* Display: Card Services */
  $handler = $view->new_display('block', 'Card Services', 'block_16');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hallways_transactional_platforms' => 'hallways_transactional_platforms',
  );
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['access_id'] = array(
    917 => '917',
  );
  $handler->display->display_options['filters']['access_id']['size'] = '5';
  $export['hallways_transactional_platforms'] = $view;

  return $export;
}
