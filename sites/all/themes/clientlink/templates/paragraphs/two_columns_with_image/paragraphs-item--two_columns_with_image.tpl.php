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
$heading              = isset($content['field_heading']) ? render($content['field_heading']) : '';
$title              = isset($content['field_title']) ? render($content['field_title']) : '';
$subtitle           = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$description           = isset($content['field_description']) ? render($content['field_description']) : '';
$short_description  = isset($content['field_short_description']) ? render($content['field_short_description']) : '';
$bguri              = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$bgurl              = isset($bguri) ? file_create_url($bguri) : NULL;

$arrow              = $content['field_display_arrow'][0]['#markup'];
$alignment_right    = $content['field_align_media_right'][0]['#markup'];
// Assign classes to arrow and media section based on the direction selected
$alignment_content  = $content['field_align_media_right'][0]['#markup'] ? "" : 'push-md-6';
$alignment_media    = $content['field_align_media_right'][0]['#markup'] ? "" : 'pull-md-6';

$arrow_enabled      = $content['field_display_arrow'][0]['#markup']? "arrow-enabled":"";

?>
<section class="row two-col two-col-with-image <?php echo $arrow_enabled ?>">
	<div class="col-12">
			<div class="row">
			   <div class="col-12 text-center mt-5">
			 		  	<?php if(isset($content['field_heading'])){?><h2 class="main-heading pb-3"><?php echo render($heading) ?> </h2><?php }?>
			 		  	<div class="mt-3 mb-5 main-description"><?php echo render($description) ?> </div>
			   </div>
			   </div>
			   <div class="row mb-5">
				<div class="col-md-6 col-sm-12 content <?php echo $alignment_content ?>">
					<?php if($arrow && $alignment_right) {?>
						<div class="arrow_right"></div>
					<?php } else if($arrow){?>
						<div class="arrow_left"></div>
					<?php } ?>
					<div class="content-wrapper section2">
						<div class="card" >
							<div class="card-block p-4 <?php echo render($arrow) ?>" >
								<p class="caption mb-0"><?php echo render($subtitle) ?></p>
								<h2 class="sub-heading"><?php echo render($title) ?> </h2>
								<div class="card-text"><?php  echo $short_description; ?></div>
							</div>
						</div>  
					</div>
				</div>
				<div class="col-md-6 col-sm-12 media-player <?php echo $alignment_media ?>">
					<div class="bg" style="background-image: url('<?php echo $bgurl ?>');"></div>
				</div>
	      </div>
	</div>
</section>

