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

$image = isset($content['field_image'][0]) ? render($content['field_image'][0]) : '';

?>
<section class="up one-up up-left">
  <article class="text-xl block-list -no-dek">
    <div class="item">
      <?php if ($content['field_image_direction'][0]['#markup'] == 'Left'): ?>
        <div class="image">
          <video class="video-js vjs-fluid" controls poster="<?php echo $image ?>" data-setup="{}" src="<?php echo render($content['field_file']) ?>"></video>
        </div>
      <?php endif ?>
        <div class="text-wrapper">
          <h3 class="headline"><?php echo render($content['field_title']) ?></h3>
          <div class="description"><?php echo render($content['field_description']) ?></div>
        </div>
      <?php if ($content['field_image_direction'][0]['#markup'] == 'Right'): ?>
        <div class="image">
          <video class="video-js vjs-fluid" controls poster="<?php echo $image ?>" data-setup="{}" src="<?php echo render($content['field_file']) ?>"></video>
        </div>
      <?php endif ?>
    </div>
  </article>
</section>
