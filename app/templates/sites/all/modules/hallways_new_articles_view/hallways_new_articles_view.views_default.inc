<?php
/**
 * @file
 * hallways_new_articles_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hallways_new_articles_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'articles_block_for_hallways';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Articles block for Hallways';
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
  $handler->display->display_options['header']['area']['content'] = '		<!-- SECTION TITLE AREA -->
		<div class="title-banner-sm">What the experts are saying. </div>
		<!-- /END SECTION TITLE AREA -->
		
		<!-- ARTICLE VIEWER CONTROLS AREA -->
		<!-- CONTROL BUTTONS AREA -->
		<div class="view-controls-list pull-right" id="viewcontrols">
			<!--<div class="searchBar"> <a class="searchBut"><span class="fa fa-search fa-2x"></span></a>
				<input class="searchField" type="text" placeholder="Search" />
			</div>-->
			<div class="viewTools"> 
			<!--<a class="pull-right" data-toggle="collapse" data-parent="#viewcontrols" href="#sortBox" ><span class="fa fa-sort fa-2x"></span></a>--> 
			<a class=" pull-right listview "><span class="fa fa-list fa-2x"></span></a> 
			<a class=" pull-right gridview active"><span class="fa fa-th fa-2x"></span></a> 
			<div class="vt-label pull-right">view options</div>
			</div>
		</div>
		<!-- /END CONTROL BUTTONS AREA -->
		<!-- SORT OPTIONS PANEL -->
		<!--<div id="sortBox" class="panel-collapse collapse fade" >
			<div class="sortBow-inner"><a href="#" class="btn btn-link"><span class="fa fa-font fa-2x"></span> Alphabetical</a> <a href="#" class="btn btn-link"><span class="fa fa-calendar fa-2x"></span> Posted Date</a> <a href="#" class="btn btn-link"><span class="fa fa-calendar-o fa-2x"></span> Expiration Date</a> <span class="pull-right label-text">Sorting options</span> </div>
		</div>-->
		<!-- /END SORT OPTIONS PANEL -->
		<!-- /END ARTICLE VIEWER CONTROLS AREA -->';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: TalentDevelopmentBlogBlock */
  $handler = $view->new_display('block', 'TalentDevelopmentBlogBlock', 'block');
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    888 => '888',
    887 => '887',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: ProfessionalServicesBlogBlock */
  $handler = $view->new_display('block', 'ProfessionalServicesBlogBlock', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '889',
    1 => '891',
    2 => '892',
    3 => '890',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: SmallPackageDeliveryBlogBlock */
  $handler = $view->new_display('block', 'SmallPackageDeliveryBlogBlock', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_2';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '35',
    1 => '893',
    2 => '894',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: ToolsandHardwareBlogBlock */
  $handler = $view->new_display('block', 'ToolsandHardwareBlogBlock', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_2';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '900',
    1 => '902',
    2 => '906',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: CleaningSuppliesBlogBlock */
  $handler = $view->new_display('block', 'CleaningSuppliesBlogBlock', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '895',
    1 => '896',
    2 => '899',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: WorkplaceEnvironmentBlogBlock */
  $handler = $view->new_display('block', 'WorkplaceEnvironmentBlogBlock', 'block_5');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '898',
    1 => '907',
    2 => '903',
    3 => '905',
    4 => '908',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: TelecommunicationsBlogBlock */
  $handler = $view->new_display('block', 'TelecommunicationsBlogBlock', 'block_6');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '918',
    1 => '49',
    2 => '920',
    3 => '919',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: EmployeeRelocationBlogBlock */
  $handler = $view->new_display('block', 'EmployeeRelocationBlogBlock', 'block_7');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '922',
    1 => '921',
    2 => '923',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: FreightBlogBlock */
  $handler = $view->new_display('block', 'FreightBlogBlock', 'block_8');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '924',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: IT SecurityBlogBlock */
  $handler = $view->new_display('block', 'IT SecurityBlogBlock', 'block_9');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '925',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: ITServicesBlogBlock */
  $handler = $view->new_display('block', 'ITServicesBlogBlock', 'block_10');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '926',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: MotorVehiclesBlogBlock */
  $handler = $view->new_display('block', 'MotorVehiclesBlogBlock', 'block_11');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '928',
    1 => '927',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: TravelBlogBlock */
  $handler = $view->new_display('block', 'TravelBlogBlock', 'block_12');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '929',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: CardServicesBlogBlock */
  $handler = $view->new_display('block', 'CardServicesBlogBlock', 'block_13');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'path' => 'path',
    'body' => 'body',
    'field_expiration_date' => 'field_expiration_date',
    'nothing' => 'nothing',
  );
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
    'format_type' => 'unix_stamp',
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
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_UNIX';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="label label-danger flag ">New</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="sr-only">Old</div>';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sorting_for_blogblock_articles:block_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    0 => '930',
    1 => '931',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  $export['articles_block_for_hallways'] = $view;

  $view = new view();
  $view->name = 'sorting_for_blogblock_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sorting for BlogBlock Articles';
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
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: TalentDevelopmentBlogBlock */
  $handler = $view->new_display('block', 'TalentDevelopmentBlogBlock', 'block');
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
    888 => '888',
    887 => '887',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: ProfessionalServicesBlogBlock */
  $handler = $view->new_display('block', 'ProfessionalServicesBlogBlock', 'block_1');
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
    889 => '889',
    891 => '891',
    892 => '892',
    890 => '890',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: SmallPackageDeliveryBlogBlock */
  $handler = $view->new_display('block', 'SmallPackageDeliveryBlogBlock', 'block_2');
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
    35 => '35',
    893 => '893',
    894 => '894',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: ToolsandHardwareBlogBlock */
  $handler = $view->new_display('block', 'ToolsandHardwareBlogBlock', 'block_3');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    900 => '900',
    902 => '902',
    906 => '906',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: CleaningSuppliesBlogBlock */
  $handler = $view->new_display('block', 'CleaningSuppliesBlogBlock', 'block_4');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    895 => '895',
    896 => '896',
    899 => '899',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: WorkplaceEnvironmentBlogBlock */
  $handler = $view->new_display('block', 'WorkplaceEnvironmentBlogBlock', 'block_5');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    898 => '898',
    907 => '907',
    903 => '903',
    905 => '905',
    908 => '908',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: TelecommunicationsBlogBlock */
  $handler = $view->new_display('block', 'TelecommunicationsBlogBlock', 'block_6');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    918 => '918',
    49 => '49',
    920 => '920',
    919 => '919',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: EmployeeRelocationBlogBlock */
  $handler = $view->new_display('block', 'EmployeeRelocationBlogBlock', 'block_7');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    922 => '922',
    921 => '921',
    923 => '923',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: FreightBlogBlock */
  $handler = $view->new_display('block', 'FreightBlogBlock', 'block_8');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    924 => '924',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: IT SecurityBlogBlock */
  $handler = $view->new_display('block', 'IT SecurityBlogBlock', 'block_9');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    925 => '925',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: ITServicesBlogBlock */
  $handler = $view->new_display('block', 'ITServicesBlogBlock', 'block_10');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    926 => '926',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: MotorVehiclesBlogBlock */
  $handler = $view->new_display('block', 'MotorVehiclesBlogBlock', 'block_11');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    928 => '928',
    927 => '927',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;

  /* Display: TravelBlogBlock */
  $handler = $view->new_display('block', 'TravelBlogBlock', 'block_12');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    929 => '929',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: CardServicesBlogBlock */
  $handler = $view->new_display('block', 'CardServicesBlogBlock', 'block_13');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    930 => '930',
    931 => '931',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: FacilitiesMaintananceServicesBlogBlock */
  $handler = $view->new_display('block', 'FacilitiesMaintananceServicesBlogBlock', 'block_14');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    969 => '969',
    970 => '970',
    967 => '967',
    894 => '894',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';

  /* Display: SecurityProtectionBlogBlock */
  $handler = $view->new_display('block', 'SecurityProtectionBlogBlock', 'block_15');
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['id'] = 'field_portfolio_category_tid_1';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['table'] = 'field_data_field_portfolio_category';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['field'] = 'field_portfolio_category_tid';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['value'] = array(
    971 => '971',
    973 => '973',
    974 => '974',
    972 => '972',
  );
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['vocabulary'] = 'portfolio';
  $handler->display->display_options['filters']['field_portfolio_category_tid_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  $export['sorting_for_blogblock_articles'] = $view;

  return $export;
}
