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

$item1         = isset($content['field_news_item_1']) ? render($content['field_news_item_1']) : '';
$item2         = isset($content['field_news_item_2']) ? render($content['field_news_item_2']) : '';
$item3         = isset($content['field_news_item_3']) ? render($content['field_news_item_3']) : '';

$link         = isset($content['field_link']) ? $content['field_link']['#items'][0] : '';

?>

<div class="row three-col-card three-col-team">
	<div class="col-sm-12 three-col-wrapper">
		<div class="row center-block ">
			<div class="col text-center pt-5 mt-4 mt-md-0"> 
				<h3><?php echo $title ?></h3>
				<p><?php echo $description ?></p>
			</div>
		</div>
		<div class="row">
			<div class="col-xl-4 col-lg-4 col-md-6 col-sm-12 pb-5  mt-3 content p-1"><?php echo $item1; ?></div>
			<div class="col-xl-4 col-lg-4 col-md-6 col-sm-12 pb-5  mt-3 content p-1 "><?php echo $item2; ?></div>
			<div class="col-xl-4 col-lg-4 col-md-6 col-sm-12 pb-5  mt-3 content p-1 "><?php echo $item3; ?></div>	 
        </div>  
        <?php if(isset($content['field_link'])){ ?>
	        <div class="row pb-5">
		        <div class="col-12 text-center">
		 			<a href="<?php echo $link['url'] ?>" class="btn border-radius-0 -arrow"><?php echo $link['title'] ?></a>  
		        </div>
	        </div>       
        <?php } ?>   
	</div> 
</div>  

