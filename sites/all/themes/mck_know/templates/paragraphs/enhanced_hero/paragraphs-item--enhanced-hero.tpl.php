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
<div class="hero-featured hotel" data-module="ParallaxFactory">
  <div class="parallax-container hotel-hero" style="transform: translate3d(0px, 670px, 0px); background-image: url(<?php echo $content['field_image'][0]['#item']['uri'] ? file_create_url($content['field_image'][0]['#item']['uri']) : '' ?>"></div>
  <div class="screen"></div>
  <div class="darken" style="background:rgba(0,0,0,0.4);"></div>
  <div class="wrapper">
    <div class="universal-hero -text-center -light content">
      <div class="text-wrapper">
          <h4 class="description"><?php echo render($content['field_title']) ?></h4>
          <hr class="yellowline">
          <div class="text-xxl">

          <h2 class="headline"><?php echo render($content['field_hero_headline']) ?></h2>
        </div>
         <div class="text-hero-sm">
          <h4 class="description"><?php echo render($content['field_hero_description']) ?></h4></div>
         <a class="featured-cta" href="<?php echo $content['field_link'][0]['#element']['url'] ?>"><?php echo $content['field_link'][0]['#element']['title'] ?></a>
      </div>
    </div>
  </div>
</div>
