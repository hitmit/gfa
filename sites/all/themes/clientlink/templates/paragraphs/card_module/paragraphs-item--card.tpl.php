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


//$activeBg              = isset($content['field_poster']['#items'][0]['uri']) ? $content['field_poster']['#items'][0]['uri'] : NULL;
//$activebgurl           = isset($activeBg) ? file_create_url($activeBg) : NULL;

$title              = isset($content['field_title']) ? render($content['field_title']) : '';
$sub_title          = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$date          = isset($content['field_date']) ? render($content['field_date']) : '';
$description        = isset($content['field_description']) ? render($content['field_description']) : '';
//$number        = isset($content['field_heading']) ? render($content['field_heading']) : '';

$link_items         = isset($content['field_links']) ? $content['field_links'] : '';


$bgimage = $content['field_align_media_right'][0]['#markup'];

$iconAsTitle= $content['field_background_video'][0]['#markup'];

$textAlign = $content['field_align_text'][0]['#markup']? "text-left" : "";

$titleIcon = $content['field_background_video'][0]['#markup']? "title-icon" : "";


?>

<div class="card <?php echo $textAlign; ?> <?php echo $titleIcon; ?>">
        <div class="row">
        	<div class="col-12">
			    <?php if((isset($content['field_image']) & (!($bgimage)) & (!($iconAsTitle)) )){ ?>
					<div class="thumbnail-bg mb-3" style="background-image: url('<?php echo $bgurl ?>');"></div>
			    <?php } ?>	
	   		 </div>
	    </div>


       <div class="row">
       		<div class="col-12">
						 	<div class="col-12 p-0">
					                             <?php if((isset($content['field_image']) & ($bgimage) & (!($iconAsTitle)))){ ?>
									<div class="card-block py-2 p-0 card-bg" style="background-image: url('<?php echo $bgurl ?>');">
						    <?php } else{?>
									<div class="card-block py-2 p-0 ">
							<?php } ?>

							<?php if(isset($content['field_sub_title'])){ ?>
										<p class="caption"><span class="caption-text"><?php  echo $sub_title; ?></span><span class="date"><?php  echo $date; ?></span></p>
							<?php } ?>

							<?php if(isset($content['field_title']) && $iconAsTitle ){ ?>
								<a href="javascript: void(0);" class="title-text-icon">
									<h3>
											<span class="title-bg" style="background-image: url('<?php echo $bgurl ?>');"></span>
											<span class="title-bg-active" style="background-image: url('<?php echo $activebgurl ?>');"></span>
											<span><?php  echo $title; ?></span>
									</h3>
								</a>
							<?php }else if(isset($content['field_title'])){?>
				                    <h4><?php  echo $title; ?></h4>

								<?php } ?>

								<?php if(isset($content['field_heading'])){ ?>
									<p class="number mb-3"><?php  echo $number; ?></p>
								<?php } ?>

								
								<?php if(isset($content['field_description'])){ ?>
									<div class="card-text pt-0">
									<p><?php  echo $description; ?></p>
									</div>
								<?php } ?>


								<?php if(isset($content['field_links'])){ ?>
									<div class="pb-1 links pt-3">
										<?php foreach($link_items as $key => $item) {
										if(is_numeric($key)) {
											$paraItem = $item['#element'];
										 ?>
											 <a href="<?php echo $paraItem['url']; ?>" class="blue-btn -arrow ">
											 	<?php echo $paraItem['title']; ?>
											 </a>
										<?php } 
										} ?>
									</div>
								<?php } ?>

						</div><!-- end of card -->
       		</div><!--end of col for card content -->
        </div>
		

		
		</div>
</div>

  
