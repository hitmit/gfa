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

?>
<div class="item">
  <div class="image">
    <a href="<?php echo render($content['field_column_link'][0]['#element']['url']) ?>" tabindex="-1" aria-hidden="true">
      <?php echo render($content['field_image']) ?>
    </a>
  </div>

  <div class="text-wrapper">
    <a href="<?php echo render($content['field_column_link'][0]['#element']['url']) ?>" class="item-title-link">
      <h3 class="-arrow headline">
        <?php echo render($content['field_column_title']) ?>
      </h3>
    </a>
  </div>
</div>
