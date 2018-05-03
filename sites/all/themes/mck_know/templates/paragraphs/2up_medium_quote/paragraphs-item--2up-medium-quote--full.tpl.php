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

<section class="up two-up two-up-medium stack">
      <div class="block-list text-l">
        <div class="item blue promo-quote">
          <div class="text-wrapper text-l">
            <blockquote class="headline">
              <?php echo render($content['field_text_quote']); ?>
            </blockquote>
            <div>
              <h2 class="headline profile-name-title">
                <?php echo render($content['field_text_quote_byline']); ?>
              </h2>

            </div>
          </div>

        </div>
        <div style="background-image: url(<?php echo render($content['field_image']) ;?>)"class="item no-padding bio4">
          <div class="item-content-wrap">


          </div>

        </div>

      </div>
</section>
