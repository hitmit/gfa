<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

$title              = isset($content['field_title']) ? render($content['field_title']) : '';
$description           = isset($content['field_description']) ? render($content['field_description']) : '';

?>
 	<div class="col-sm-12 col-md-6">
			<div class="card" >
			<div class="card-block p-4 mt-4" >
				<a href="<?php  echo render($content['field_link']['#items'][0]['url']); ?>">
<h2 class="mb-4"><?php echo render($title) ?> </h2></a>
				<p class="card-text"><?php  echo $description; ?></p>
			</div>
			</div>  
	</div>

