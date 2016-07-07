<div id="article-wrap">
	<div class="article-nav blog">
	  <?php if ( other_node_pagination($node, 'p') != NULL ) : ?>
		  <a href="<?php print url('node/' . other_node_pagination($node, 'p'), array('absolute' => TRUE)); ?>" class="post-nav"><i class="icon-angle-left"></i></a>
		<?php endif; ?>
		<a href="#" class="close"><i class="icon-angle-right"></i><i class="icon-angle-left"></i></a>
		<?php if ( other_node_pagination($node, 'n') != NULL ) : ?>
		  <a href="<?php print url('node/' . other_node_pagination($node, 'n'), array('absolute' => TRUE)); ?>" class="post-nav"><i class="icon-angle-right"></i></a>
		<?php endif; ?>
	</div>
	
	<div class="video-title blog">
		<h2><?php if ( theme_get_setting('meta_date') == '1' ) : ?><small><?php print format_date($node->created, 'custom', 'M d, Y'); ?></small><?php endif; ?><?php if ( theme_get_setting('meta_title') == '1' ) { echo $title; } ?><?php if ( (render($content['field_tags'])) AND (theme_get_setting('meta_tags')) == '1' ): ?><small>Posted In: <?php print render($content['field_tags']); ?></small><?php endif; ?></h2>
		<h6 class="remove-bottom"><?php print render($content['field_article_tagline']); ?></h6>
	</div>
	
	<?php if (render($content['field_image'])) {print render($content['field_image']); } ?>
	
	<?php if (render($content['field_article_embed'])) {print render($content['field_article_embed']); } ?>
	<div class="clear break small"></div>
	
	<article>
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
	<?php if (render($content['comments'])): ?>
	 <h5 id="comment-title"><?php print $comment_count; ?> <?php print t('Comments'); ?></h5>
	 <hr>
	  <?php print render($content['comments']); ?>
	<?php endif; ?>  
	</article>
</div>