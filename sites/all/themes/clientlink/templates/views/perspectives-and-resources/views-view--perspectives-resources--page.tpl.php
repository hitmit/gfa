<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="prespectives-resources">

<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>


<div class="row m-0 ">
    <div class="col-lg-12 banner img media-player banner-img ">

    <div class="bg" style="background-image: url('sites/all/themes/clientlink/images/hero_perspectives.jpg');"></div>
    <div class="darken" style="background:rgba(0,0,0,0.1);"></div>
  
      <div class="card">
          <div class="card-block">
              <h5>McKinsey Cancer Center Intranet</h5>
            <h1> Perspectives &amp; Resources <small></small>
            </h1>
          </div>
      </div>
    </div>  
          <div class="overlay-content col-lg-10"></div>
    </div>


<section class="row two-col ">
  <div class="col-12">
      <div class="row">
         <div class="col-12 text-center mt-5">
                            <div class="mt-3 mb-5 main-description"> </div>
         </div>
         </div>
         <div class="row mb-5">
        <div class="col-md-6 col-sm-12 content ">
                    <div class="content-wrapper section2">
            <div class="card">
            
                <p class="caption mb-0 pl-4">Featured Article</p>
              <div class="card-block p-4 0">   <a target="_blank" href="https://www.mckinsey.com/~/media/McKinsey/Industries/Healthcare%20Systems%20and%20Services/Our%20Insights/The%20next%20wave%20of%20innovation%20in%20oncology/The-next-wave-of-innovation-in-oncology.ashx"> <h2 class="sub-heading pb-3">Next wave of innovation in oncology </h2></a>
                <div class="card-text">
  <p>A new wave of therapeutic and diagnostic technologies in oncology is becoming available. While many of these have the potential to transform oncology treatment in the future, manufacturers, regulators and care providers must address a number of topics—including clinical, regulatory and market access hurdles—to deliver on their promise.</p>
 <p>
<a class="blue-btn -arrow" target="_blank" href="https://www.mckinsey.com/~/media/McKinsey/Industries/Healthcare%20Systems%20and%20Services/Our%20Insights/The%20next%20wave%20of%20innovation%20in%20oncology/The-next-wave-of-innovation-in-oncology.ashx"> Read article</a></p>
</div>
              </div>
            </div>  
          </div>
        </div>
        <div class="col-md-6 col-sm-12 media-player ">
          <div class="bg" style="background-image: url('http://dev-drupaldev-lx07.amdc.mckinsey.com/media-services/mckinsey-cancer-center/sites/all/themes/clientlink/images/img_article_1.png');"></div>
        </div>
        </div>
  </div>
</section>

<div class="row publication-filters pt-5">
  <?php if ($header): ?>
    <div class="view-header col-lg-9 col-sm-7">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters col-lg-3 col-sm-5">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

</div>
  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>



</div><?php /* class view */ ?>


</div> 