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
$title        = isset($content['field_title']) ? render($content['field_title']) : '';
?>

<div class="row promo-bar m-0 ">
  <div class="col-12 ">
    <div class="row m-0">
      <div class="col-8 p-4">
         <h3><?php echo $title ?></h3>
      </div>
      <div class="col-4 text-right p-4">
      <?php if(isset($content['field_link'])){?>
         <a href="#contact-popup" target="<?php echo render($content['field_link']['#items'][0]['attributes']['target']);  ?>" class="btn btn-primary open-popup-link">
                <span class="mck-icon mck-icon__email pr-2"></span>
                <?php echo render($content['field_link']['#items'][0]['title']); ?>
              </a>
        <?php }?>
      </div>
    </div>
  </div>  
</div>
<div id="contact-popup" class="white-popup mfp-hide">
  <?php
    $block = block_load('webform', 'client-block-50');
    $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
    $output = drupal_render($render_array);
    print $output;
  ?>
</div>