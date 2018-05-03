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

/*echo "<pre>";
print_r($content);
echo "</pre>";*/

$bguri         = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$bgurl         = isset($bguri) ? file_create_url($bguri) : NULL;
$name          = isset($content['field_title']) ? render($content['field_title']) : '';
$designation   = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$office   = isset($content['field_office']) ? render($content['field_office']) : '';
$description   = isset($content['field_short_description']) ? render($content['field_short_description']) : '';
$mailto        = isset($content['field_learn_more_link']) ? render($content['field_learn_more_link']['#items'][0]['value']) : '';

$name_class =  str_replace(" ", "-", strtolower(trim($content['field_title']['#items'][0]['value'])));
//$first_alert  = $content['field_first_alert'][0]['#markup'] ? "first-alert" : '';

?>
<a href="mailto:<?php echo $mailto; ?>" class="team-member">
<div class="card  p-3 <?php echo $name_class ?>">
  <div class="card-block p-0">
	  <?php if(isset($content['field_image'])){?>
	  	<p class="thumbnail mb-3" style="background-image: url('<?php echo $bgurl ?>');"></p>
	  <?php } ?>
      <h5><?php echo $name; ?></h5>
      <h6><?php echo $designation; ?></h6>
      <h6><?php echo $office; ?></h6>
    <div class="card-text pt-3"><?php echo $description; ?></div>
    <?php if(isset($content['field_learn_more_link'])){?>
    <a href="mailto:<?php echo $mailto; ?>" class="mail-to"><span  class="mck-icon mck-icon__email"></span><span>Email</span> </a>
   <?php }?>
    </div>
   </div>
 </a>
