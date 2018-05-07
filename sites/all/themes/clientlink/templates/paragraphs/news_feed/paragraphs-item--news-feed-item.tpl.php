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


$bguri              = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$bgurl              = isset($bguri) ? file_create_url($bguri) : NULL;

$title              = isset($content['field_title']) ? render($content['field_title']) : '';
$sub_title          = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$date          = isset($content['field_date']) ? render($content['field_date']) : '';
$description        = isset($content['field_description']) ? render($content['field_description']) : '';



?>

<div class="card ">
        <div class="row">
        	<div class="col-5">
			    <?php if((isset($content['field_image']))){ ?>
					<div class="thumbnail-bg mb-3" style="background-image: url('<?php echo $bgurl ?>');"></div>
			    <?php } ?>	
	   		 </div>

       		<div class="col-7">
									<div class="card-block py-2 p-0 ">
							<?php if(isset($content['field_sub_title'])){ ?>
										<p class="caption">
											<span class="caption-text"><?php  echo $sub_title; ?></span>
											<span class="date"><?php  echo $date; ?></span></p>
							<?php } ?>

							<?php if(isset($content['field_title'])){?>
				                    <h4><?php  echo $title; ?></h4>

								<?php } ?>
								
							<?php if(isset($content['field_description'])){ ?>
								<div class="card-text pt-0 pr-2">
								<p><?php  echo $description; ?></p>
								</div>
							<?php } ?>

						<!-- end of card -->
       		</div><!--end of col for card content -->
        </div>
		

		
		</div>
</div>

  
