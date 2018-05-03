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

$title               = isset($content['field_title']) ? render($content['field_title']) : '';
$subtitle            = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$products_link       = isset($content['field_products_link']) ? render($content['field_products_link']) : '#';
$products_link_label = isset($content['field_products_link_label']) ? render($content['field_products_link_label']) : 'Link To Products';


$item1               = isset($content['field_tools_item_1']) ? render($content['field_tools_item_1']) : '';
$item2               = isset($content['field_tools_item_2']) ? render($content['field_tools_item_2']) : '';
$item3               = isset($content['field_tools_item_3']) ? render($content['field_tools_item_3']) : '';
$item4               = isset($content['field_tools_item_4']) ? render($content['field_tools_item_4']) : '';

?>

<div class="row four-col-card mt-5 pt-5 px-4 ">
	<div class="col-sm-12">
		<div class="row center-block ">
			<div class="col text-center mt-4 mt-md-0"> 
				<h2 class="mb-0">
					<?php echo $title ?>
					<small class="pt-3"><?php echo $subtitle ?></small>
				</h2>
			</div>
		</div>
		<div class="row pt-5">
			<div class="col-xl-3 col-lg-4 col-md-6 col-sm-12 pb-5 content"><?php echo $item1; ?></div>
			<div class="col-xl-3 col-lg-4 col-md-6 col-sm-12 pb-5 content"><?php echo $item2; ?></div>
			<div class="col-xl-3 col-lg-4 col-md-6 col-sm-12 pb-5 content"><?php echo $item3; ?></div>
			<div class="col-xl-3 col-lg-4 col-md-6 col-sm-12 pb-5 content"><?php echo $item4; ?></div>	 
        </div>  
        <?php if(isset($content['field_link_1'])){?> 
            <!--<div class="row center-block ">
				<div class="col text-center pt-5 mt-4 mt-md-0"> 
					<a class="mck-button view-products" href="<?php  echo render($content['field_link_1']['#items'][0]['url']); ?>"><?php  echo render($content['field_link_1']['#items'][0]['title']); ?><span></span></a>	
				</div>
	      </div> -->
	<?php } ?>
  </div>  
</div>  
