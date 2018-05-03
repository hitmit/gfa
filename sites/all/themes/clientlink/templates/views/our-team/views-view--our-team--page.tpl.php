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
	<div class="<?php print $classes; ?> our-team">
		<div class="">
			<div class="banner img media-player banner-img">
				<div class="bg"></div>
				<div class="card">
					<div class="card-block">
						
						<h1>Working With Us<!-- <small>Some quick example text</small> --></h1>
					<!-- </br><div class="col-md-12"><h4>How to Get Started</br>
<small>Ready to use ClientLink? <a href="#get-started">Let’s go</a></small></h4></div></br>
					<div class="col-md-12"><h4>Meet the Team</br>
<small>Ready to use ClientLink? <a href="#minds-behind">Get to know the minds behind ClientLink.</a></small></h4></div> -->

						<?php if ($exposed): ?>
							<div class="view-filters mx-auto">
								<?php print $exposed; ?>
							</div>
						<?php endif; ?>
					</div>
				</div>
			</div>
		</div>


<!-- <div class="row"  id="get-started">
			<div class="col-lg-12">
				<div class="bg"></div>
				<div class="card">
					<div class="card-block">
						
						<h4>How to Get Started</h4>
					<ul>
						<li>Steps on how to get started with product</li>
						<li>Any download resources about the product(s) users can read pdf/ppt
</li>
						<li>Video(s) about product(s) with option to download or share with colleagues
</li>
						<li>Any product team member info/contact leads. Who the main team members are for reach product
</li>
						<li>A form for submitting questions for usage to product team
</li>
						<li>Frequently asked questions/answers 
</li>
						<li>Link to product download or signup
</li>

					</ul>

						
					</div>
				</div>
			
		</div>
	</div> -->


	<?php if ($header): ?>
		<div class="view-header row m-0 mx-auto" id="minds-behind">
			<div class="col-12 results-count pt-5 pb-3 m-0 ">
				<?php print $header; ?>
			</div>
		</div>
	<?php endif; ?>
	
	
	<?php if ($rows): ?>
		<div class="view-content row our-team-list m-0 mx-auto">
		<?php print $rows; ?>
		</div>
	<?php elseif ($empty): ?>
		<div class="view-empty">
		<?php print $empty; ?>
		</div>
	<?php endif; ?>

	<div class=" pagination">
			<div class="mx-auto mt-4">
			<?php if ($pager): ?>
				<?php print $pager; ?>
			<?php endif; ?>
		    </div>
		</div>

</div><?php /* class view */ ?>