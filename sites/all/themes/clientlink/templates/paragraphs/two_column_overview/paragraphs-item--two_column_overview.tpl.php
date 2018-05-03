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
$caption           = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$short_description  = isset($content['field_short_description']) ? render($content['field_short_description']) : '';
$bguri              = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$bgurl              = isset($bguri) ? file_create_url($bguri) : NULL;
$icon               = isset($content['field_image_path']) ? render($content['field_image_path']) : '';

$alignment_right    = $content['field_align_media_right'][0]['#markup'];
// Assign classes to arrow and media section based on the direction selected
$alignment_content  = $content['field_align_media_right'][0]['#markup'] ? "" : 'push-md-6';
$alignment_media    = $content['field_align_media_right'][0]['#markup'] ? "" : 'pull-md-6';


?>

<section class="row two-col two-col-overview mt-5">
<div class="col-12 m-0 p-0">
<div class="row">
	<div class="col-md-6 col-sm-12 content <?php echo $alignment_content ?>">
		<div class="content-wrapper section2">
			<div class="card" >
				<div class="card-block p-4 " >
					<?php echo render($icon) ?>
					<p class="caption mb-0"><?php echo render($caption) ?> </p>
					<h2><?php echo render($title) ?></h2>
					<p class="card-text"><?php  echo $short_description; ?></p>

                       <?php if (isset($content['field_link_1'])){ ?>
                       					<?php  echo render($content['field_link_1']); ?>
                       	<?php }?>
                        <?php if (isset($content['field_link_2'])){ ?>
                       					<?php  echo render($content['field_link_2']); ?>
                       	<?php }?>
                       	<?php if (isset($content['field_link_3'])){ ?>
                       					<?php  echo render($content['field_link_3']); ?>
                       	<?php }?>
                       	<?php if (isset($content['field_link_4'])){ ?>
                       					<?php  echo render($content['field_link_4']); ?>
                       	<?php }?>

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

