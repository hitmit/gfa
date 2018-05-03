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




$field_team_member               = isset($content['field_team_member']) ? render($content['field_team_member']) : '';

?>

<div class="row four-col-card mt-5 pt-5 px-4 ">
		<div class="row pt-5">
			<div class="col-xl-3 col-lg-4 col-md-6 col-sm-12 pb-5 content"><?php echo $field_team_member; ?></div>
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
