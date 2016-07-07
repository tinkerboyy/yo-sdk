<?php if (render($content['field_contact_map'])): ?>
<div class="video-container">
  <?php print render($content['field_contact_map']); ?>  
</div>
<?php endif; ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<div class="video-title">
		<h2><?php print $title; ?></h2>
		<?php if (render($content['field_contact_tagline'])): ?>
		  <h6 class="remove-bottom"><?php print render($content['field_contact_tagline']); ?> </h6>
	  <?php endif; ?>
	</div>
	
	<?php if (render($content['field_contact_info'])): ?>
	<div class="one_third">
	  <?php print render($content['field_contact_info']); ?>
	</div>
	<?php endif; ?>
	
	<?php if (module_exists('contact')): ?>
	<div class="two_thirds last">
	  <?php 
	    require_once drupal_get_path('module', 'contact') .'/contact.pages.inc'; 
      $contact_form = drupal_get_form('contact_site_form');
      print drupal_render($contact_form); 
    ?>  
	</div>
	<?php endif; ?>

<div class="clear break small"></div>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_before_content']);
      print render($content);
    ?>
  </div>

</article>