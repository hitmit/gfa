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

$media  = isset($content['field_banner_media']) ? render($content['field_banner_media']) : '';
$title  = isset($content['field_title']) ? render($content['field_title']) : '';
$description  = isset($content['field_short_description']) ? render($content['field_short_description']) : '';

?>

<div class="row">
		<div class="col-lg-12 banner media-player">
		<?php echo $media?>
			<div class="card">
					<div class="card-block">
						<h1><?php echo $title ?>
						<small><?php echo $description ?></small>
						</h1>
					</div>
			</div>
		</div>
</div>
