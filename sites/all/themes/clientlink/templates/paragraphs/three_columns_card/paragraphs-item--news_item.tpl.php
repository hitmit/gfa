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
$author             = isset($content['field_author']) ? render($content['field_author']) : '';
$location             = isset($content['field_office']) ? render($content['field_office']) : '';
$date               = isset($content['field_date']) ? render($content['field_date']) : '';
$description        = isset($content['field_description']) ? render($content['field_description']) : '';
$link               = isset($content['field_learn_more_link']) ? render($content['field_learn_more_link']) : '';
?>

<div class="card">
    <?php if (isset($content['field_image'])){ ?>
	<div class="bg" style="background-image: url('<?php echo $bgurl ?>');"></div>
	<?php }?>
	<div class="card-block p-5">
		       <h4><?php  echo $title; ?></h4>

		<div class="card-text">
			<p class="pb-1"><span class="name pr-2"><?php  echo $author; ?><br/><?php  echo $location; ?></span><span class="date"><?php  echo $date; ?></span></p>
			<?php  echo $description; ?>
		</div>
		 <?php if (isset($content['field_learn_more_link'])){ ?>
		<a href="<?php  echo $link; ?>" class="mt-5">Learn More</a>
		<?php }?>
	 </div>
</div>
  

