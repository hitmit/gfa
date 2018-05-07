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


$column_items        = isset($content['field_paragraph']) ? $content['field_paragraph'] : '';

//ddl($content);
$count = count($content['field_paragraph']['#items']);

if($count == 2){
	$column_item_class = "col-md-6";
}else if($count == 3){
	$column_item_class = "col-md-6 col-lg-4";
}else if($count == 4){
	$column_item_class = "col-md-4 col-lg-3";
}else{
	$column_item_class = "col-md-12 text-center";
}


?>

<div class="row py-2 px-0 card-module mt-5">
	<div class="col-sm-12">
	<?php if(isset($content['field_title']) || isset($content['field_sub_title']) ){ ?>
		<div class="row center-block ">
			<div class="col text-center mt-4 mt-md-0"> 
				<h2 class="mb-5 pb-3">
					<?php echo $title ?>
					<small class="pt-3"><?php echo $subtitle ?></small>
				</h2>
			</div>
		</div>
		<?php } ?>
		<div class="row py-1">
		 						<?php foreach($column_items as $key => $item) {
										if(is_numeric($key)) {
											$paraItem = $item['entity']['paragraphs_item'];
											 ?>
											<div class="<?php echo $column_item_class; ?> col-sm-12 pb-3 content card-item"><?php echo render($paraItem); ?></div>	 
									    <?php } 
								    } ?>
        </div>   
            <div class="row center-block ">
            <?php if(isset($content['field_link'])){ ?>
			<div class="col text-center pt-5 mt-4 mt-md-0"> 
				<a class="blue-btn view-products" href="<?php  echo render($content['field_link']['#items'][0]['url']); ?>"><?php  echo render($content['field_link']['#items'][0]['title']); ?><span></span></a>	
			</div>
			<?php } ?>
	</div> 
  </div>  
</div>  
