<?php
/**
 * @file
 * cms_footer.box.inc
 */

/**
 * Implements hook_default_box().
 */
function cms_footer_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'connect_contribute_footer';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Connect and Contribute Footer';
  $box->options = array(
    'body' => array(
      'value' => '<div id="r_modal-container">
	<div id="footer-connect-contribute" class="modal cap-modal fade" tabindex="-1" role="dialog">
			<div class="modal-dialog ">
				<div class="modal-content">
					<div class="modal-body ">
						<!-- MODAL CLOSE BUTTON-->
						<div class="close"><a href="#" data-dismiss="modal">X</a></div>
						<div class=" mheadBox app-head-box-image">
							<div class="container"> 
								<!-- BLOCK - Headbox Content 
		   ################################################-->
								
								<div id="b_head-box-content"> 
									
									<!-- NODE - App Name
				++++++++++++++++++++++++++++++++++++++++++++-->
									<h1 id="app-name">Contribute &amp; Share</h1>
									
								</div>
								
								<!--  /END BLOCK - Headbox Content 
		   ###############################################--> 
							</div>
						</div>
						<!-- #LEARN-CONNECT-ACT BLOCK -->
						<div class="container-fluid" id="r_lca"> 
							
							<!-- BLOCK - LCA Bar
		   ################################################-->
							
							<div id="b_lca-bar"> 
								
								<!-- NODE - LCA State
				++++++++++++++++++++++++++++++++++++++++++++-->
								<div id="lca-state"> 
									<!-- default state shown in example -->
									<div class="col-xs-12 col-sm-12">
										<div class="progress">
											<div class="progress-bar progress-bar-warning" style="width: 100%"></div>
										</div>
										<span class="lca-title">CONNECT</span> </div>
								</div>
							</div>
							
							<!--  /END BLOCK - LCA Bar
		   ###############################################--> 
							
						</div>
						<!-- /END #LEARN-CONNECT-ACT BLOCK -->
											<!-- CONTENT -->
						<div id="r_content-main">
							<div class="container">	
							<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12" id="right-content">
								<div class="title-banner">Contribute</div>
								<div class="subHead">Share your expertise.</div>
								<p>Share your guides, templates, and tools with your community as an Acquisition Gateway "contributing member". Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.

	Thank you for your support. Let\'s start Acting as One!</p>
							
							<hr>
							
								
				<div class="title-banner">Share</div>
								<div class="subHead">Tell others about the Acquisition Gateway.</div>
				<p></p>
				<hr>
				<div class="hi-icon-wrap hi-icon-effect-1 hi-icon-effect-1b">
				<a href="http://facebook.com/sharer.php?u=https://hallways.cap.gsa.gov/homepage/welcome.php&amp;t=Acquisition%20Gateway" class="hi-icon hi-icon-facebook" title="Facebook">Facebook</a>&nbsp;<a href="http://twitter.com/intent/tweet?url=https://hallways.cap.gsa.gov/homepage/welcome.php&amp;text=Acquisition%20Gateway" class="hi-icon hi-icon-twitter" title="Twitter">Twitter</a>&nbsp;<a href="https://plus.google.com/share?url=https://hallways.cap.gsa.gov/homepage/welcome.php" class="hi-icon hi-icon-google" title="Google Plus">Google Plus</a>
				</div>
			
							
							</div>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['connect_contribute_footer'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'header_modal_links';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Header Modal Links';
  $box->options = array(
    'body' => array(
      'value' => '<ul class="nav navbar-nav navbar-left">
	<li><a data-toggle="modal" href="#footer-about-us">About Us</a></li>
	<li><a data-toggle="modal" href="#footer-explore">Explore</a></li>
</ul>

<ul class="nav navbar-nav navbar-right">
<?php
global $user;
if ( 
$user->uid ) {
$profile = \'<li><a data-toggle="modal" href="/user">My Profile</a></li>\';
print $profile;
}
else {
  // Not logged in
}
?>
	<li><a data-toggle="modal" href="/faq.php" target="_blank">FAQs</a></li>
	<li class="dropdown hidden-xs"><a class="dropdown-toggle" data-toggle="dropdown"> <span class="nav-link-text">Help</span></a>
	<ul class="dropdown-menu" role="menu" style="min-width:450px; opacity:1; margin-right:10px;">
		<li>
		<div class="panel-body">
		<h3 class="DINCondensedBold">How Can We Help?</h3>

		<p>Are you having trouble? We want to help you succeed. Whether it is a sign in issue, problems finding what you need, or a concern about the accuracy or usefulness of an item, please let us know. If it affects you, we care.</p>

		<p>Email us at:</p>

		<p><a class="btn btn-block btn-warning" href="mailto:hallways_site_manager@gsa.gov">hallways_site_manager@gsa.gov</a></p>

		<p>Thank you for your support. We aim to respond to every message within one working day.</p>
		</div>
		</li>
	</ul>
	</li>
	<li class="hidden-sm hidden-md hidden-lg">
	<div class="nav-link-icon">&nbsp;</div>

	<div class="nav-link-text"><a href="mailto:hallways_site_manager@gsa.gov">Help</a></div>
	</li>
</ul>
',
      'format' => 'php_code',
    ),
    'additional_classes' => '',
  );
  $export['header_modal_links'] = $box;

  return $export;
}
