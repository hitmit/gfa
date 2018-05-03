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
$name              = isset($content['field_title']) ? render($content['field_title']) : '';
$designation          = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$team_category        = isset($content['field_team_category']) ? render($content['field_team_category']) : '';
$field_location        = isset($content['field_location']) ? render($content['field_location']) : '';




?>

 <div class="card">
	<div class="bg" style="background-image: url('<?php echo $bgurl ?>');"></div>
	<a href="<?php  echo render($content['field_know_link'][0]['url']); ?>"><div class="card-block pb-5 px-4 pt-4">
		<p class="caption mb-0"><?php  echo $sub_title; ?></p>
		<h3><?php  echo $title; ?></h3>
		<h4 class="-arrow headline"></h4>
		<div class="card-text pt-3 pb-5">
			<?php  echo $description; ?>
		</div>
		<?php print $team_category; ?><br/>
		<?php print $field_location; ?>
	 </div></a>
     <a href="<?php  echo render($content['field_know_link'][0]['url']); ?>">VIEW MORE</a>
</div>
  

