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

/*
echo "<pre>";
echo print_r($content);
echo "</pre>";*/
 
$icon         = isset($content['field_image']) ? render($content['field_image']) : NULL;
$bguri              = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$bgurl              = isset($bguri) ? file_create_url($bguri) : NULL;
$number              = isset($content['field_sub_title']) ? render($content['field_sub_title']) : '';
$title        = isset($content['field_title']) ? render($content['field_title']) : '';
$description  = isset($content['field_description']) ? render($content['field_description']) : '';
$link         = isset($content['field_learn_more']) ? render($content['field_learn_more']['#items']['0']['url']) : '';
$link_title   = isset($content['field_learn_more']) ? render($content['field_learn_more']['#items']['0']['title']) : 'Learn More';


?>

<div class="card help-item">
	<div class="card-block p-4">
	    <?php if (isset($content['field_image'])){ ?>
				<?php if($icon){ ?>
				<div class="img "  style="background-image: url('<?php echo $bgurl ?>');"></div>
				<?php } else {?>
				<span class="mck-icon"></span>
				<?php }?>
		 <?php } ?>
		 <?php if (isset($content['field_sub_title'])){ ?>
               <h2 class="number"><?php  echo $number; ?></h2>
	    <?php } ?>
	     <?php if (isset($content['field_title'])){ ?>
               <h4 class="mt-4"><?php echo $title; ?></h4>
	    <?php } ?>
		
		<div class="card-text pt-3"><?php echo $description; ?></a>
		</div>
		<?php if(isset($content['field_learn_more'])){?>
		<a btn border-radius-0 -arrow href="<?php echo $link ; ?>" class="mt-5"><?php echo $link_title; ?></a>
		<?php } ?>
	 </div>
</div>
  

