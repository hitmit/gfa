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
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  

  <div class="row m-0 ">
    <div class="col-lg-12 banner img media-player banner-img ">

    <div class="bg" style="background-image: url('sites/all/themes/clientlink/images/hero_experts.jpg');"></div>
    <div class="darken" style="background:rgba(0,0,0,0.1);"></div>
  
      <div class="card">
          <div class="card-block">
              <h5>McKinsey Cancer Center Intranet</h5>
            <h1>Our Experts</h1>
            <p>Our leadership team covers the Americas, Europe and Asia 
with over 150 years of experience.</p>
          </div>
      </div>
    </div>  
          <div class="overlay-content col-lg-10"></div>
    </div>
      <div class="row my-5 experts-filters">
        <div class="col-12">
          <?php print render($title_suffix); ?>
            <?php if ($header): ?>
              <div class="view-header">
                <?php print $header; ?>
              </div>
            <?php endif; ?>

            <?php if ($exposed): ?>
              <div class="view-filters float-right">
                <?php print $exposed; ?>
              </div>
            <?php endif; ?>
    </div>
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