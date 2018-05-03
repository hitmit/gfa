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
$short_description  = isset($content['field_short_description']) ? render($content['field_short_description']) : '';
$media              = isset($content['field_image']) ? render($content['field_image']) : '';
$link_label         = isset($content['field_link_1_label']) ? render($content['field_link_1_label']) : 'Get Started';


?>

<section class="row one-column-jumbotron">
	<div class="col-sm-12 col-md-6 col-lg-5 p-3 px-md-5 mx-auto content px-2">
		<div class="jumbotron">
			<?php echo render($media) ?>
			<?php if(isset($content['field_title'])){ ?>
			<h2  class="pb-4"><?php echo render($title) ?></h2>
			<?php } ?>
		  <div><?php echo render($short_description) ?></div>
		  <div class="pt-4">
		    <a class="mck-button mck-th-blue-mckinsey mck-button--big" href="resources" role="button"><?php echo render($link_label) ?><span></span></a>
		  </div>
		</div>
	</div>
</section>
