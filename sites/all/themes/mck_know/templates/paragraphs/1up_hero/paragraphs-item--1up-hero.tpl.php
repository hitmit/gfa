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

<?php if ($content['field_hero_type'][0]['#markup'] == 'Large'): ?>

  <section class="light-blue-container">

    <!-- Start Enhanced Hero Module -->


    <div class="hero enhanced-hero-intro tight">

      <style type="text/css">
        @media screen and (min-width: 767px ) {
          .enhanced-hero-intro .text-render {
            width: 100%;
          }
        }
      </style>

      <div class="hero-container nominees-banner" style="background-image: url(<?php echo render($content['field_image']);?>)">
        <div class="screen"></div>
        <div class="darken" style="background:rgba(0,0,0,0.4);"></div>
        <div class="text-wrapper alignment-center">
          <div class="hero-up">
            <div class="text-render -position-over-image -light -text-center">

              <div class="text-xl">
                <h1 class="headline enhanced-headline -text-center -gradient-">
                  <?php echo render($content['field_title']) ?>
                </h1>
                <div class="description"><?php echo render($content['field_date']) ?></div>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="intro-container">
        <div class="article-wrapper">
          <article class="up body">
            <header>
              <div class="text-render -dark -position-over-image">

                <div class="text-xxl">

                  <h1 class="headline -text-center -gradient-">
                    <?php echo render($content['field_title']) ?>
                  </h1>

                </div>
              </div>

              <div class="text-l intro-text">

                <h3 class="headline -gradient-" >
                  <?php echo render($content['field_hero_headline']) ?>
                </h3>

                <div class="description ">

                  <?php echo render($content['field_text_paragraph']) ?>

                </div>

              </div>

            </header>

          </article>
        </div>
      </div></div>

  </section>

<?php elseif ($content['field_text_overlays_image'][0]['#markup'] == 'no'): ?>

  <div class="wrapper">
    <section class="up">
      <article class="item text-xl">
        <div class="image">
          <img src="<?php echo render($content['field_image']) ?>">
        </div>
        <div class="text-wrapper tight">
          <h3 class="headline"><center><?php echo render($content['field_title']) ?></center></h3>
          <div class="-light description"><?php echo render($content['field_text_paragraph']) ?></div>
        </div>
      </article>
    </section>
  </div>

<?php else: ?>

  <div class="wrapper">
    <section class="up medium-hero careers">
      <div class="image hero-container homepage-medium-hero" style="background-image: url(<?php echo render($content['field_image']); ?>)"></div>
      <article class="up body">
        <header class="text-xl">
          <h3 class="headline">
            <?php echo render($content['field_hero_headline']) ?>
          </h3>
          <div class="description">
            <?php echo render($content['field_text_paragraph']) ?>
          </div>
        </header>
      </article>
    </section>
  </div>


<?php endif; ?>
