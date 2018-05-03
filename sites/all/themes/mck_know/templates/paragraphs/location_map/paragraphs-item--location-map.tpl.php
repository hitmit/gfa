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

<section class="up location-map-section r3-offices">
  <div class="span-full-width">
    <div class="gmap-holder">

      <div class="gmap">
        <iframe frameborder="0" style="border:0" src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3168.1351184500336!2d-122.44356998460226!3d37.43391267982299!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x808f0b6387226d6b%3A0x26fdf75aa4885b1e!2sThe+Ritz-Carlton%2C+Half+Moon+Bay!5e0!3m2!1sen!2sus!4v1496344622736"></iframe>
      </div>

      <div class="text-holder text-m item city-0 active" data-zoom="15">
        <h3 class="headline"><?php echo trim(render($content['field_title'])) ?></h3>

        <p class="location-address address"><?php echo nl2br(trim(strip_tags(render($content['field_address'])))) ?></p>

        <p class="location-address phone">
            Voice: <a href="tel:<?php echo trim(render($content['field_phone'])) ?>"><?php echo trim(render($content['field_phone'])) ?></a>
            <br>
            Web: <a target="_blank" href="<?php echo trim(render($content['field_link'])) ?>"><?php echo trim(render($content['field_link'])) ?></a>
        </p>
      </div>
    </div>
  </div>
</section>
