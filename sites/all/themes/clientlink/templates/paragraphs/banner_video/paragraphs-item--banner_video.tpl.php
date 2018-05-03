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

$videouri      = isset($content['field_video_file']['#items'][0]['uri']) ? $content['field_video_file']['#items'][0]['uri'] : '';
$videourl      = isset($videouri) ? file_create_url($videouri) : NULL;
$bguri         = isset($content['field_poster']['#items'][0]['uri']) ? $content['field_poster']['#items'][0]['uri'] : NULL;
$bgurl         = isset($bguri) ? file_create_url($bguri) : NULL;

$title         = isset($content['field_title']) ? render($content['field_title']) : '';
$description   = isset($content['field_short_description']) ? render($content['field_short_description']) : '';
$bg_video      = $content['field_background_video']['0']['#markup'] ? "background-video-wrapper" : 'media-player banner banner-video active';

//echo "<pre>"; var_dump($content); echo "</pre>";
?>

<div class="row m-0 ">
	<div class="col-lg-12 <?php echo $bg_video; ?>">
		<div class="media-video">
			<!-- <video class="video-js vjs-fluid vjs-default-skin vjs-16-9" controls  data-setup="{}" src="<?php echo $videourl ?>"></video> -->
			<?php if($content['field_background_video']['0']['#markup']) { ?>
				<video id="example_video_1" class="video-js vjs-default-skin background-video"
					preload="none"
					poster="<?php echo $bgurl ?>"
					data-setup='{"example_option":true}'
					loop autoplay>
					<source src="<?php echo $videourl ?>" type='video/mp4' />
				</video>
			<?php } else { ?>
				<video id="example_video_1" class="video-js vjs-default-skin vjs-16-9"
					controls preload="auto"
					poster="<?php echo $bgurl ?>"
					data-setup='{"example_option":true}' >
					<source src="<?php echo $videourl ?>" type='video/mp4' />
				</video>
			<?php } ?>
			<!-- <div class="bg" style="background-image: url('<?php echo $bgurl ?>');"></div> -->
		
			<div class="card">
				<div class="card-block">
				    <h5><?php  echo render($content['field_sub_title']); ?></h5>
					<h1><?php echo $title ?></h1>
					<div class="description"><?php echo $description ?></div>
				</div>
			</div>
		</div>
	</div>
</div>
