<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php 
    global $parent_root;
      if (!$picture) {
        echo '<img src="'.$parent_root.'/img/anon.png" alt="image" class="avatar">'; 
      }
      else { 
        print $picture;   
      }
    ?>

  <?php if ($new): ?>
    <span class="new"><?php print $new ?></span>
  <?php endif; ?>
  
  
  <div class="comment-content"> 
	  <?php print render($title_prefix); ?>
	  <h6 class="margin-bottom-10" <?php print $title_attributes; ?>><?php print $author; ?> <span class="meta"> •  <?php echo t('Posted');?> <?php print format_date($comment->created, 'custom', 'M d, Y'); ?></span> <span class="comment-permalink"><?php print $permalink; ?></span></h6> 
	  <?php print render($title_suffix); ?>
	
	  
	
	  <div class="content"<?php print $content_attributes; ?>>
	    
	    <?php
	      // We hide the comments and links now so that we can render them later.
	      hide($content['links']);
	      print render($content);
	    ?>
	    <?php if ($signature): ?>
	    <div class="user-signature clearfix">
	      <?php print $signature ?>
	    </div>
	    <?php endif; ?>
	  </div>
	
	  <?php print render($content['links']) ?> 
	  <hr>
  </div>
</div>
