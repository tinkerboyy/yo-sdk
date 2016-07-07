<?php
/**
 * @file
 * cms_hallways_context.box.inc
 */

/**
 * Implements hook_default_box().
 */
function cms_hallways_context_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'homepage_comming_soon';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Homepage Comming Soon';
  $box->options = array(
    'body' => array(
      'value' => '<div class="col-xs-12 col-sm-12 clearfix" id="solution-finder">
			<div class="title-banner">What are we building next?</div>
			<div class="sf-panel">
			<h3>Are you trying to choose an acquisition solution?</h3>
			<p>You’ve found the future home of the Solution Finder—a brand new decision support tool that will help you navigate the acquisition solution landscape.</p>
      <p>When it is available, the Solutions Finder will feature 80+ acquisition solutions across 10 categories -- all available for filtering and comparison.</p>
			</div>
			</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['homepage_comming_soon'] = $box;

  return $export;
}
