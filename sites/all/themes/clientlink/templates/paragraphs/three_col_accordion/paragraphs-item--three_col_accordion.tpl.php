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
$description   = isset($content['field_description']) ? render($content['field_description']) : '';

$paragraph         = isset($content['field_paragraph']) ? render($content['field_paragraph']) : '';

?>

<div class="row three-col-accordion">
	<div class="col-sm-12">
		<div class="row center-block ">
			<div class="col text-center pt-5 mt-4 mt-md-0"> 
				<h2><?php echo $title ?></h2>
				<h4><?php echo $description ?></h4><br/>
			</div>
		</div>
		<div class="row accordion-items">
		<ul>
			 <?php echo $paragraph ?>
		</ul>
        </div>  
        <div class="row">
        	<div class="col-12">
        			<div class="card-text current-description p-5"></div>
        	</div>
        </div>    
	</div> 
</div>  

