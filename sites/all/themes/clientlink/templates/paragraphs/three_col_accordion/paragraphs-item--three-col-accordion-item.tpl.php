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

$activeBg              = isset($content['field_poster']['#items'][0]['uri']) ? $content['field_poster']['#items'][0]['uri'] : NULL;
$activebgurl           = isset($activeBg) ? file_create_url($activeBg) : NULL;


$title              = isset($content['field_title']) ? render($content['field_title']) : '';
$title              = isset($content['field_title']) ? render($content['field_title']) : '';
$description       = isset($content['field_description']) ? render($content['field_description']) : '';
$description_title        = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
?>

<li class="col-4 three-col-accordion-item">
	<div class="card">	    
		<div class="card-block p-3 py-5" >
			             
			             <h4 >
			             <div class="valign-wrapper">

			             <?php if ( isset($content['field_image']) & isset($content['field_poster']) ){ ?>
			             <div>
								<span class="bg" style="background-image: url('<?php echo $bgurl ?>');"></span>	
								<span class="activebg" style="background-image: url('<?php echo $activebgurl ?>');"></span>		
						</div>							
							<?php }else if(isset($content['field_image'])){?>
							<div>
								<span class="bg" style="background-image: url('<?php echo $bgurl ?>');"></span>		
							</div>						
							<?php }?>
							<div>
							<span class="accordion-title"><?php  echo $title; ?></span>
							</div>
							</div>
						</h4>
						<div class="card-text">								
							<h5>
							<?php if(isset($content['field_image'])){?>
								<span class="bg" style="background-image: url('<?php echo $bgurl ?>');"></span>								
							<?php }?>
							<span class="title"><?php  echo $description_title; ?></span>
							</h5>				
							<div><?php  echo $description; ?></div>
					</div>
		 </div>


			
	</div>
</li> 

