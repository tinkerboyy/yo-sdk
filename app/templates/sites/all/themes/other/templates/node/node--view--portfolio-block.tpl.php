<li class="<?php print str_replace(',-', ' ', str_replace(' ', '-',strip_tags(render($content['field_portfolio_category'])))); ?>">
	<?php print render($content['field_portfolio_image']); ?>
	<div>
		<a href="<?php print $node_url; ?>">
		  <span class="center">
			  <h4 class="heavy remove-bottom"><?php print $title; ?></h4>
			  <p><?php print strtolower(render($content['field_portfolio_category'])); ?></p>
		  </span>
		</a>
	</div>
</li>