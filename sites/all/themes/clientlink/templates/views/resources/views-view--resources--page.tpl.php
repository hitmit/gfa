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
<div class="<?php print $classes; ?> resources">

<div class="resources-banner">
	<div class="row">
		<div class="col-12 mx-auto">
			<div class="darken" style="background:rgba(0,0,0,0.2);"></div>
			<h1>Resources<br/><small>Looking for help? Search below for video tutorials and quick guides on a range of topics.</small></h1>
		
                 <?php if ($exposed): ?>
					<div class="view-filters mx-auto">
						<?php print $widgets['field-field_tid_1']; ?>
					</div>
				 <?php endif; ?>
		</div>
	</div>
</div>


<div class=" resources-container">
	<div class="">
		<div class="row resources-filter">
			<div class="col-sm-12  col-md-4">
				<?php if ($header): ?>
				<div class="view-header row pt-4 pb-5 mx-auto">
					<div class="results-count">
						<?php print $header; ?>
					</div>
				</div>
				<?php  endif; ?>

			<?php if (!($rows)): ?>		  
			     <div class="view-header row pt-4 pb-5 mx-auto">
						<div class="results-count">
							<?php echo "0 RESULTS"; ?>
						</div>
					</div>
	        <?php  endif; ?>
          </div>
			<div class="col-sm-12 text-right">
				<?php if ($exposed): ?>
					<div class="view-filters mx-auto">
						<?php print $exposed; ?>
					</div>
				<?php endif; ?>
			</div>
		</div>

		<?php if ($rows): ?>
			<div class="view-content row resources-list m-0 mx-auto">
			<?php print $rows; ?>
			</div>
		<?php elseif ($empty): ?>
			<div class="view-empty row resources-list m-0 mx-auto">
			   <div class="col-sm-12  col-md-6">
			      <?php print $empty; ?>
			  </div>
			</div>
		<?php endif; ?>

		<div class="row pagination">
			<div class="col-12 mx-auto mt-4">
			<?php if ($pager): ?>
				<?php print $pager; ?>
			<?php endif; ?>
		    </div>
		</div>

		</div>
    </div>

</div>
</div>
<?php /* class view */ ?>