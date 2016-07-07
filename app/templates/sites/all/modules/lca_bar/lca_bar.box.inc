<?php
/**
 * @file
 * lca_bar.box.inc
 */

/**
 * Implements hook_default_box().
 */
function lca_bar_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'lca_bar';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'LCA Bar';
  $box->options = array(
    'body' => array(
      'value' => '<div class="container-fluid" id="lca-block">
<div class="lca-bar">
<div class="lca-color-bar">
<div class="col-xs-4 col-sm-4">
<div class="progress">
<div class="progress-bar progress-bar-primary" style="width: 100%">&nbsp;</div>
</div>
<span class="lca-title">LEARN</span></div>

<div class="col-xs-4  col-sm-4">
<div class="progress">
<div class="progress-bar progress-bar-warning" style="width: 100%">&nbsp;</div>
</div>
<span class="lca-title">CONNECT</span></div>

<div class="col-xs-4 col-sm-4">
<div class="progress">
<div class="progress-bar progress-bar-success" style="width: 100%">&nbsp;</div>
</div>
<span class="lca-title">ACT</span></div>
</div>
</div>
</div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['lca_bar'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'lcabar_hallways';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'LCA BOX for Hallways';
  $box->options = array(
    'body' => array(
      'value' => '<div class="container-fluid" id="lca-block">
	<div class="lca-bar">
		<div class="lca-color-bar">
			<div class="col-xs-4 col-sm-4">
				<div class="progress">
					<div class="progress-bar progress-bar-primary" style="width: 100%"> </div>
				</div>
				<span class="lca-title">LEARN</span> </div>
			<div class="col-xs-4  col-sm-4">
				<div class="progress">
					<div class="progress-bar progress-bar-warning" style="width: 100%"> </div>
				</div>
				<span class="lca-title">CONNECT</span> </div>
			<div class="col-xs-4 col-sm-4">
				<div class="progress">
					<div class="progress-bar progress-bar-success" style="width: 100%"> </div>
				</div>
				<span class="lca-title">ACT</span> </div>
		</div>
	</div>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['lcabar_hallways'] = $box;

  return $export;
}
