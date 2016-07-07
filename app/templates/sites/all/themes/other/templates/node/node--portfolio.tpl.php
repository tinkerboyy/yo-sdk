<?php
/**
 * Slideshow variables.
 */
$image_slide = ''; 
if ($items = field_get_items('node', $node, 'field_portfolio_slideshow')) {
  if (count($items) == 1) {
    $image_slide = 'false';
  }
  elseif (count($items) > 1) {
    $image_slide = 'true';
  }
}

$img_count = 0;
$counter = count($items);
?>

<div class="article-nav">
  <?php if ( other_node_pagination($node, 'p') != NULL ) : ?>
	  <a href="<?php print url('node/' . other_node_pagination($node, 'p'), array('absolute' => TRUE)); ?>" class="post-nav"><i class="icon-angle-left"></i></a>
	<?php endif; ?>
	<a href="#" class="close"><i class="icon-angle-right"></i><i class="icon-angle-left"></i></a>
	<?php if ( other_node_pagination($node, 'n') != NULL ) : ?>
	  <a href="<?php print url('node/' . other_node_pagination($node, 'n'), array('absolute' => TRUE)); ?>" class="post-nav"><i class="icon-angle-right"></i></a>
	<?php endif; ?>
</div>

<?php if (render($content['field_portfolio_video'])): ?>
<div class="video-container">
	<?php print render($content['field_portfolio_video']); ?>
</div>
<?php endif; ?>

<?php if (!render($content['field_portfolio_video']) && ($image_slide == 'true')): ?>
  <ul class="rslides">
  <?php print render($content['field_portfolio_slideshow']); ?>	
  </ul>  
  <div class="clear break small"></div>
<?php endif; ?>

<?php if (!render($content['field_portfolio_video']) && ($image_slide == 'false')): ?>
  <div class="single-portfolio-img">
    <?php print render($content['field_portfolio_image']); ?>
  </div>
  <div class="clear break small"></div>
<?php endif; ?>

<article>
  <div class="video-title">
	  <h2><?php print $title; ?></h2>
		<h6 class="remove-bottom"><?php print render($content['field_portfolio_tagline']); ?></h6>
	</div>
	
	<?php if (render($content['body'])): ?>
	<div class="three_fourths">
		<?php print render($content['body']); ?>
		
		<?php
		  // Remove the "Add new comment" link on the teaser page or if the comment
		  // form is being displayed on the same page.
		  if ($teaser || !empty($content['comments']['comment_form'])) {
		    unset($content['links']['comment']['#links']['comment-add']);
		  }
		  // Only display the wrapper div if there are links.
		  $links = render($content['links']);
		  if ($links):
	  ?>
	  <div class="link-wrapper">
	    <?php print $links; ?>
	  </div>
	  <?php endif; ?>
	
	</div>
	<?php endif; ?>
	
	<div class="one_fourth last">
		<h6><?php echo t('Project Details'); ?></h6>
		<?php if (render($content['field_portfolio_client'])): ?>
		  <p><strong><?php echo t('CLIENT'); ?> :</strong> <?php print render($content['field_portfolio_client']); ?></p>
		<?php endif; ?>  
		<?php if ($display_submitted): ?>
		  <p><strong><?php echo t('DATE'); ?>:</strong> <?php print format_date($node->created, 'custom', 'M d, Y'); ?></p>
		<?php endif; ?>  
		<?php if (render($content['field_portfolio_category'])): ?>
		  <p><strong><?php echo t('TAGS'); ?> :</strong> <?php print render($content['field_portfolio_category']); ?></p>
		<?php endif; ?>  
		<?php if (render($content['field_portfolio_website'])): ?>
		  <p><strong><?php echo t('WEBSITE'); ?> :</strong> <a href="<?php print render($content['field_portfolio_website']); ?>" target="_blank"><?php print render($content['field_portfolio_website']); ?></a></p>
		<?php endif; ?>  
	</div>
	
		
	<div class="clear"></div><!--CLEAR FLOATS-->
		
</article>