<?php
/**
 * @file
 * hallways_article_sorting_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hallways_article_sorting_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sorting_of_adminsupportblogblock_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sorting of AdminSupportBlogBlock Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'path' => 'path',
    'title' => 'title',
    'field_image' => 'field_image',
    'field_expiration_date' => 'field_expiration_date',
    'field_short_description' => 'field_short_description',
    'field_interaction_mode' => 'field_interaction_mode',
    'field_new_tag_expiration_date_1' => 'field_new_tag_expiration_date_1',
    'views_conditional' => 'views_conditional',
    'nothing' => 'nothing',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_expiration_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_interaction_mode' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_new_tag_expiration_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_conditional' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="container">
		<!-- SECTION TITLE AREA -->
		<div class="title-banner-sm">Please Sort the Order</div>
		<!-- /END SECTION TITLE AREA -->
	</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['content'] = '<div style="font-size: 1.2em">The top three articles in the list of sorted articles will publish to the Featured Articles section on your hallway homepage.</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_expiration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
 <a href="[path]">
			<div class="cube cube-article">
				<div class="cube-title-bar"><p class="expDate">Exp. Date: [field_expiration_date]</p></div>
				<div class="cube-pad cube-title">
					<h2>[title]</h2>
					[body]
				</div>
			</div>
			</a> </div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    'article' => 'article',
    'hallways_document' => 'hallways_document',
    'video_article' => 'video_article',
  );

  /* Display: AdminSupportBlogBlock Articles */
  $handler = $view->new_display('block', 'AdminSupportBlogBlock Articles', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
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
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_expiration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'hallways_custom_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Short Description (Maximum 140 Characters) */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Field: Content: Interaction Mode */
  $handler->display->display_options['fields']['field_interaction_mode']['id'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['table'] = 'field_data_field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['field'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_mode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_interaction_mode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_mode']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_interaction_mode']['delta_offset'] = '0';
  /* Field: Content: new tag expiration date */
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['id'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['table'] = 'field_data_field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['field'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['settings'] = array(
    'format_type' => 'new_tag_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '4';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_STAMP';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">New</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '				<!-- ARTICLE --><li> 
					<!-- ARTICLE TILE -->
					
					<div class="article"><!-- ARTICLE wrapper --> 
						<a class="artGrid" href="[path]"><!-- article link -->
						<!-- ARTICLE TITLE AREA -->
						
							<div class="article-img-thumbnail"><!-- where the title back image is set -->
								
							<div class="titleBox"><!-- title area wrapper -->
								<!-- ARTICLE TITLE  --><div class="artTitle">[title]


</div><!-- /END ARTICLE TITLE  -->

							</div>
[field_image]
						</div>
						<!-- /END ARTICLE TITLE AREA --> 
						
						<!-- LCA bar -->
						<div id="lcaid" class="art-lca-image lca-img-lca">[field_interaction_mode]</div><!-- where the correct lca color combination is set --> 
						<!-- /END LCA bar --> 
						</a>
						<!-- ARTICLE DESCRIPTION AREA --> 
[views_conditional]
						<!-- ARTICLE DESCRIPTION  -->
						<div class="artDesc">[field_short_description]
</div>
						<!-- /END ARTICLE DESCRIPTION  --> 
						<!-- /END ARTICLE DESCRIPTION AREA --> 
						
					</div>
					<!-- /END ARTICLE wrapper --> 
					<!-- /END ARTICLE TILE --> 
				</li><!-- /END ARTICLE -->';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Update';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
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
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'hallways_document' => 'hallways_document',
    'video_article' => 'video_article',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Portfolio Category (field_portfolio_category) */
  $handler->display->display_options['filters']['field_portfolio_category_tid']['id'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['value'] = array(
    78 => '78',
    8 => '8',
    9 => '9',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['hierarchy'] = 1;
  $export['sorting_of_adminsupportblogblock_articles'] = $view;

  $view = new view();
  $view->name = 'sorting_of_ithardware_blogblock_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sorting of ITHardware BlogBlock Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'path' => 'path',
    'field_image' => 'field_image',
    'field_expiration_date' => 'field_expiration_date',
    'field_short_description' => 'field_short_description',
    'field_interaction_mode' => 'field_interaction_mode',
    'totalcount' => 'totalcount',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
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
    'field_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_expiration_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_interaction_mode' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'totalcount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="container">
		<!-- SECTION TITLE AREA -->
		<div class="title-banner-sm">Please Sort the Order</div>
		<!-- /END SECTION TITLE AREA -->
	</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['content'] = '<div style="font-size: 1.2em">The top three articles in the list of sorted articles will publish to the Featured Articles section on your hallway homepage.</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
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
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_expiration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'hallways_custom_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Short Description (Maximum 140 Characters) */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Field: Content: Interaction Mode */
  $handler->display->display_options['fields']['field_interaction_mode']['id'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['table'] = 'field_data_field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['field'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_mode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_interaction_mode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_mode']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_interaction_mode']['delta_offset'] = '0';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-xs-12 col-sm-6 col-md-6 col-lg-12"><!-- article size controller --> 
						<a href="[path]"><!-- article link -->
						<div class="thumbnail article">
						<div class="article-img-thumbnail">
[field_image]
Views: [totalcount]
</div>
							<!-- /END article image --> 
<div id="lcaid" class="lca-img-lca">[field_interaction_mode]</div>
							<div class="caption"> 
								<!-- Article title -->
								<p>[title]</p>
								<!-- Article expiration date -->
								<p class="desc">[field_short_description]</p>
							</div>
							<!-- /END Article title Area --> 
						</div>
						<!-- /END article wrapper --> 
						</a><!-- /END article link --> 
					</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'hallways_document' => 'hallways_document',
    'video_article' => 'video_article',
  );

  /* Display: ITHardwareBlogBlock */
  $handler = $view->new_display('block', 'ITHardwareBlogBlock', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_expiration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'hallways_custom_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Short Description (Maximum 140 Characters) */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Field: Content: Interaction Mode */
  $handler->display->display_options['fields']['field_interaction_mode']['id'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['table'] = 'field_data_field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['field'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_mode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_interaction_mode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_mode']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_interaction_mode']['delta_offset'] = '0';
  /* Field: Content: new tag expiration date */
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['id'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['table'] = 'field_data_field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['field'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '4';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_STAMP';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">New</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '				<!-- ARTICLE --><li> 
					<!-- ARTICLE TILE -->
					
					<div class="article"><!-- ARTICLE wrapper --> 
						<a class="artGrid" href="[path]"><!-- article link -->
						<!-- ARTICLE TITLE AREA -->
						
							<div class="article-img-thumbnail"><!-- where the title back image is set -->
								
							<div class="titleBox"><!-- title area wrapper -->
								<!-- ARTICLE TITLE  --><div class="artTitle">[title]</div><!-- /END ARTICLE TITLE  -->
							</div>
[field_image]
						</div>
						<!-- /END ARTICLE TITLE AREA --> 
						
						<!-- LCA bar -->
						<div id="lcaid" class="art-lca-image lca-img-lca">[field_interaction_mode]</div><!-- where the correct lca color combination is set --> 
						<!-- /END LCA bar --> 
						</a>
						<!-- ARTICLE DESCRIPTION AREA --> 
						<!-- NEW FLAG -->
			[views_conditional] 
						<!-- /END NEW FLAG --> 
						<!-- ARTICLE DESCRIPTION  -->
						<div class="artDesc">[field_short_description]</div>
						<!-- /END ARTICLE DESCRIPTION  --> 
						<!-- /END ARTICLE DESCRIPTION AREA --> 
						
					</div>
					<!-- /END ARTICLE wrapper --> 
					<!-- /END ARTICLE TILE --> 
				</li><!-- /END ARTICLE -->';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Update';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
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
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'hallways_document' => 'hallways_document',
    'video_article' => 'video_article',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Portfolio Category (field_portfolio_category) */
  $handler->display->display_options['filters']['field_portfolio_category_tid']['id'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['value'] = array(
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['hierarchy'] = 1;
  $export['sorting_of_ithardware_blogblock_articles'] = $view;

  $view = new view();
  $view->name = 'sorting_of_itsoftware_blogblock_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sorting of ITSoftware BlogBlock Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="container">
		<!-- SECTION TITLE AREA -->
		<div class="title-banner-sm">Please Sort the Order</div>
		<!-- /END SECTION TITLE AREA -->
	</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['content'] = '<div style="font-size: 1.2em">The top three articles in the list of sorted articles will publish to the Featured Articles section on your hallway homepage.</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
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
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_expiration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'hallways_custom_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Short Description (Maximum 140 Characters) */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Field: Content: Interaction Mode */
  $handler->display->display_options['fields']['field_interaction_mode']['id'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['table'] = 'field_data_field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['field'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_mode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_interaction_mode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_mode']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_interaction_mode']['delta_offset'] = '0';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-xs-12 col-sm-6 col-md-6 col-lg-12"><!-- article size controller --> 
						<a href="[path]"><!-- article link -->
						<div class="thumbnail article">
						<div class="article-img-thumbnail">
[field_image]
Views: [totalcount]
</div>
							<!-- /END article image --> 
<div id="lcaid" class="lca-img-lca">[field_interaction_mode]</div>
							<div class="caption"> 
								<!-- Article title -->
								<p>[title]</p>
								<!-- Article expiration date -->
								<p class="desc">[field_short_description]</p>
							</div>
							<!-- /END Article title Area --> 
						</div>
						<!-- /END article wrapper --> 
						</a><!-- /END article link --> 
					</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'hallways_document' => 'hallways_document',
    'video_article' => 'video_article',
  );

  /* Display: ITSoftwareBlogBlock */
  $handler = $view->new_display('block', 'ITSoftwareBlogBlock', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'path' => 'path',
    'field_image' => 'field_image',
    'field_expiration_date' => 'field_expiration_date',
    'field_short_description' => 'field_short_description',
    'field_interaction_mode' => 'field_interaction_mode',
    'totalcount' => 'totalcount',
    'field_new_tag_expiration_date_1' => 'field_new_tag_expiration_date_1',
    'views_conditional' => 'views_conditional',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
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
    'field_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_expiration_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_interaction_mode' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'totalcount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_new_tag_expiration_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_conditional' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Expiration Date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_expiration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'hallways_custom_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Short Description (Maximum 140 Characters) */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Field: Content: Interaction Mode */
  $handler->display->display_options['fields']['field_interaction_mode']['id'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['table'] = 'field_data_field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['field'] = 'field_interaction_mode';
  $handler->display->display_options['fields']['field_interaction_mode']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_mode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_interaction_mode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_mode']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_interaction_mode']['delta_offset'] = '0';
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  /* Field: Content: new tag expiration date */
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['id'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['table'] = 'field_data_field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['field'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_new_tag_expiration_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_new_tag_expiration_date_1';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '4';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_STAMP';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">New</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '				<!-- ARTICLE --><li> 
					<!-- ARTICLE TILE -->
					
					<div class="article"><!-- ARTICLE wrapper --> 
						<a class="artGrid" href="[path]"><!-- article link -->
						<!-- ARTICLE TITLE AREA -->
						
							<div class="article-img-thumbnail"><!-- where the title back image is set -->
								
							<div class="titleBox"><!-- title area wrapper -->
								<!-- ARTICLE TITLE  --><div class="artTitle">[title]</div><!-- /END ARTICLE TITLE  -->
							</div>
[field_image]
						</div>
						<!-- /END ARTICLE TITLE AREA --> 
						
						<!-- LCA bar -->
						<div id="lcaid" class="art-lca-image lca-img-lca">[field_interaction_mode]</div><!-- where the correct lca color combination is set --> 
						<!-- /END LCA bar --> 
						</a>
						<!-- ARTICLE DESCRIPTION AREA --> 
						<!-- NEW FLAG -->
						[views_conditional]
						<!-- /END NEW FLAG --> 
						<!-- ARTICLE DESCRIPTION  -->
						<div class="artDesc">[field_short_description]</div>
						<!-- /END ARTICLE DESCRIPTION  --> 
						<!-- /END ARTICLE DESCRIPTION AREA --> 
						
					</div>
					<!-- /END ARTICLE wrapper --> 
					<!-- /END ARTICLE TILE --> 
				</li><!-- /END ARTICLE -->';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Update';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'hallways_document' => 'hallways_document',
    'video_article' => 'video_article',
  );
  /* Filter criterion: Content: Portfolio Category (field_portfolio_category) */
  $handler->display->display_options['filters']['field_portfolio_category_tid']['id'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['value'] = array(
    0 => '28',
    1 => '29',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $export['sorting_of_itsoftware_blogblock_articles'] = $view;

  return $export;
}
