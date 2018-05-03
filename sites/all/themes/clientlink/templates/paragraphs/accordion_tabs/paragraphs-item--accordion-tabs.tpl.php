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

$heading  = isset($content['field_title']) ? render($content['field_title']) : '';
$paragraph  = isset($content['field_paragraph']) ? render($content['field_paragraph']) : '';
?>
<div class="accordion-tabs row">
  <div class="col-12 text-center my-5">
    <?php if(isset($content['field_title'])){ ?>
      <h2><?php echo $heading;?></h2>
    <?php }?>
  </div>
  <div class="col-12 mb-5">
    <div id="accordion" role="tablist" aria-multiselectable="true">
        <ul><?php echo render($paragraph); ?></ul>
    </div>
  </div>
</div>
