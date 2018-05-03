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


$videouri      = isset($content['field_video']['#items'][0]['uri']) ? $content['field_video']['#items'][0]['uri'] : '';
$videourl      = isset($videouri) ? file_create_url($videouri) : NULL;
$bguri         = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$bgurl         = isset($bguri) ? file_create_url($bguri) : NULL;

?>
<div class="one-col-video row">
	<div class="col-12 mt-5">
			<div class="card" >
			<div class="card-block p-4 " >
				<h2 class="mb-5"><?php echo render($title) ?> </h2>
				<div class="media">
					<video class="video-js vjs-fluid" controls  data-setup="{}" src="<?php echo $videouri ?>" poster="<?php echo $bgurl ?>"></video>
					<a href="javascript: void(0);"  class="btn play-btn"></a>
				</div>
				<div class="card-text mt-5"><?php  echo $description; ?></div>
			</div>
			</div>  
	</div>
</div>

