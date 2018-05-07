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
$column_items        = isset($content['field_paragraph']) ? $content['field_paragraph'] : '';



?>

<div class="row p-0 card-module news-feed mt-5">
	<div class="col-sm-12 m-0 p-0">
	<?php if(isset($content['field_title']) || isset($content['field_sub_title']) ){ ?>
		<div class="row center-block m-0">
			<div class="col text-center mt-4 mt-md-0 p-0"> 
				<h2 class="mb-4 pb-3">
					<?php echo $title ?>
				</h2>
			</div>
		</div>
		<?php } ?>
		<div class="row py-1 px-3 m-0">
		 						<?php foreach($column_items as $key => $item) {
										if(is_numeric($key)) {
											$paraItem = $item['entity']['paragraphs_item'];
											 ?>
											<div class=" col-sm-12 pb-3 content card-item m-0"><?php echo render($paraItem); ?></div>	 
									    <?php } 
								    } ?>
        </div>   
            <div class="row center-block m-0">
            <?php if(isset($content['field_link'])){ ?>
			<div class="col text-center pt-5 mt-4 mt-md-0"> 
				<a class="blue-btn view-products" href="<?php  echo render($content['field_link']['#items'][0]['url']); ?>"><?php  echo render($content['field_link']['#items'][0]['title']); ?><span></span></a>	
			</div>
			<?php } ?>
	</div> 
  </div>  
</div>  
