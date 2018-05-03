<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="row">
	<div class="col-12">
	<?php foreach ($rows as $id => $row): ?>
	<div class="row search-results-row ">
	  <div <?php if ($classes_array[$id]) { print ' class="col-12 my-3 pt-3 ' . $classes_array[$id] .'"';  } ?>>
	    <?php print $row; ?>
	  </div>
	 </div>
	<?php endforeach; ?>
	</div>
</div>
