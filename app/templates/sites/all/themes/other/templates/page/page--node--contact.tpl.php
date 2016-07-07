<?php if (isset($node) && field_get_items('node', $node, 'field_background_image') != FALSE): ?>
  <a href="#" class="view-background"><i class="icon-eye-close icon-2x"></i></a>
<?php endif; ?>  

<div id="mobile-nav">
	<i class="icon-reorder"></i>
	<?php if (theme_get_setting('mobile_logo_path') != ""): ?>
		<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="mobile-logo">
	    <img src="<?php print file_create_url(theme_get_setting('mobile_logo_path')); ?>" alt="<?php print t('Home'); ?>" />
	  </a>
	<?php endif; ?>
</div>

<header>
  <?php if ($logo): ?>
		<div id="logo">
			<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
	      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
	    </a>
		</div>
	<?php endif; ?>
	
	<?php if ($site_name || $site_slogan): ?>
    <div id="name-and-slogan"<?php if ($disable_site_name && $disable_site_slogan) { print ' class="hidden"'; } ?>>

      <?php if ($site_name): ?>
        <?php if ($title): ?>
          <div id="site-name"<?php if ($disable_site_name) { print ' class="hidden"'; } ?>>
            <strong>
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </strong>
          </div>
        <?php else: /* Use h1 when the content title is empty */ ?>
          <h1 id="site-name"<?php if ($disable_site_name) { print ' class="hidden"'; } ?>>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <div id="site-slogan"<?php if ($disable_site_slogan) { print ' class="hidden"'; } ?>>
          <?php print $site_slogan; ?>
        </div>
      <?php endif; ?>

    </div> <!-- /#name-and-slogan -->
  <?php endif; ?>  
	
	<?php if ($page['site_nav']): ?>
	  <nav>
      <?php print render($page['site_nav']); ?>
	  </nav>
	<?php endif; ?>
	
	<?php if ($page['sidebar_primary']): ?>
    <?php print render($page['sidebar_primary']); ?>
	<?php endif; ?>
	
	<?php if ($page['sidebar_secondary']): ?>
    <?php print render($page['sidebar_secondary']); ?>
	<?php endif; ?>
</header>

<div id="basic-page" class="content-wrapper">
	<div id="loader"></div>
	<?php if ($messages): ?>
	  <div id="messages">
	   <?php print $messages; ?>
	  </div>
	<?php endif; ?>
	<?php if ($tabs): ?>
    <div class="tabs">
      <?php print render($tabs); ?>
    </div>
  <?php endif; ?>
  <?php print render($page['help']); ?>
  <?php if ($action_links): ?>
    <ul class="action-links">
      <?php print render($action_links); ?>
    </ul>
  <?php endif; ?>
  <?php print render($page['before_content']); ?>
	<?php print render($page['content']); ?>
</div>

<?php if (isset($node) && field_get_items('node', $node, 'field_background_image') != FALSE): ?>
	<script type="text/javascript">
	jQuery(document).ready(function($){
	  $('body').addClass("cover");
	  $('body').css("background-image", "url(<?php echo file_create_url($node->field_background_image['und'][0]['uri']); ?>)");  
	});
	</script>
<?php endif; ?>