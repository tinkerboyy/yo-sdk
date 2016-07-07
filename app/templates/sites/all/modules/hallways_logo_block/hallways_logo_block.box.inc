<?php
/**
 * @file
 * hallways_logo_block.box.inc
 */

/**
 * Implements hook_default_box().
 */
function hallways_logo_block_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'header_logo';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Homepage Logo';
  $box->options = array(
    'body' => array(
      'value' => '<div class="container">
<div style="padding-top:50px">
<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6">
<p><img alt="Acquisition Gateway" class="img-responsive" src="/sites/default/files/logo.png" style="margin-bottom:5px; margin-top:10px; max-height:90px" />(Beta Release—08/18/2014)</p>
</div>
</div>
</div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['header_logo'] = $box;

  return $export;
}
