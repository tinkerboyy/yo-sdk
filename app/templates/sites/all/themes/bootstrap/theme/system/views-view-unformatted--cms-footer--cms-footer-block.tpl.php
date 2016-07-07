<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="container"> 
	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<h2 class="DINCondensedBold">ACQUISITION GATEWAY</h2>
	</div>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div>