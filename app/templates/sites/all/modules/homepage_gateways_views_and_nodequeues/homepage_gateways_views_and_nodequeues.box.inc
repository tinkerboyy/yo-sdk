<?php
/**
 * @file
 * homepage_gateways_views_and_nodequeues.box.inc
 */

/**
 * Implements hook_default_box().
 */
function homepage_gateways_views_and_nodequeues_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'homepage_lca_content';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Homepage LCA Box';
  $box->options = array(
    'body' => array(
      'value' => '<div id="hallway-landing-pg-bottom">
<div class="container">
<!--<h2 class="title-banner">The Philosophy - defined.</h2>-->
<div class="col-xs-12 col-sm-4">
  <div class="panel-body">
    <h4 class="title-banner">LEARN.</h4>
    <div><img src="sites/all/themes/bootstrap/art/article-tiles/lrn.png" alt="Learn" class="img-responsive"></div></div>
</div>
<div class="col-xs-12 col-sm-4">
  <div class="panel-body">
    <h4 class="title-banner">CONNECT.</h4>
    <div><img src="sites/all/themes/bootstrap/art/article-tiles/connect.png" alt="Connect" class="img-responsive"></div></div>
</div>
<div class="col-xs-12 col-sm-4">
  <div class="panel-body">
    <h4 class="title-banner">ACT.</h4>
    <div><img src="sites/all/themes/bootstrap/art/article-tiles/act.png" alt="Act" class="img-responsive"></div></div>
</div>
<div class="col-xs-12 col-sm-12">
<div class="panel-body">
<p>The Acquisition Gateway, built by GSA, is a workspace designed to let Federal acquisition professionals learn what they need to know, connect with others to collaborate and communicate, and act to accomplish their tasks effectively. Organized to match the government’s category management structure, the content in the Gateway was developed for you and by you—the acquisition professional.  We are building the Gateway with an Agile approach that incorporates user-centered design and iterative development. We conduct continuous user-testing and encourage feedback from users, so that the Acquisition Gateway can grow and change to best serve your needs.
</p>
<p>
We encourage you to explore the solution comparisons, tools, templates, success stories, prices paid data, and more to achieve successful outcomes at each step of the acquisition lifecycle.  Thank you for helping us as we build your place to learn, connect, and act with others in the acquisition community. </p>
</div>
</div>
</div>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['homepage_lca_content'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'user_hero_content';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'User Hero Content';
  $box->options = array(
    'body' => array(
      'value' => '<div class="col-xs-12 col-sm-12 col-md-8 col-lg-8" id="heroContent">
<div class="panel panel-body">
<h2>My Connect Profile</h2>
</div>
</div>',
      'format' => 'full_html',
    ),
  );
  $export['user_hero_content'] = $box;

  return $export;
}
