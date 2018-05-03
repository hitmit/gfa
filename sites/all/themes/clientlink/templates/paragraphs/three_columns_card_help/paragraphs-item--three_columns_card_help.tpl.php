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

$title         = isset($content['field_title']) ? render($content['field_title']) : '';
$description   = isset($content['field_short_description']) ? render($content['field_short_description']) : '';

$item1         = isset($content['field_help_item_1']) ? render($content['field_help_item_1']) : '';
$item2         = isset($content['field_help_item_2']) ? render($content['field_help_item_2']) : '';
$item3         = isset($content['field_help_item_3']) ? render($content['field_help_item_3']) : '';

?>

<div class="row three-col-card">
	<div class="col-sm-12">
		<div class="row center-block ">
			<div class="col text-center"> 
				<h2><?php echo $title ?></h2>
				<p><?php echo $description ?></p>
			</div>
		</div>
		<div class="row">
			<div class="col-xl-4 col-lg-4 col-md-4 col-sm-12 mt-3 content"><?php echo $item1; ?></div>
			<div class="col-xl-4 col-lg-4 col-md-4 col-sm-12 mt-3 content"><?php echo $item2; ?></div>
			<div class="col-xl-4 col-lg-4 col-md-4 col-sm-12 mt-3 content"><?php echo $item3; ?></div>	 
        </div>       
	</div> 
</div>  

