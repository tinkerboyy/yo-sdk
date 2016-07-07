<div id="comments" class="comments scroll-animate <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($content['comments'] && $node->type != 'forum'): ?>
    <?php print render($title_prefix); ?>
   
    <?php print render($title_suffix); ?>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
    <p><?php print t('What are your thoughts? Please leave a comment.'); ?></p>
    <?php print render($content['comment_form']); ?>
  <?php endif; ?>
</div>
