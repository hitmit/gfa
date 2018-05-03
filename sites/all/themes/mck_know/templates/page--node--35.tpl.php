<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
<header class="global-header global-header-r3 navigation-r3" role="banner">
  <a aria-hidden="false" aria-label="Toggle Menu" class="skip-main" href="#0" tabindex="0">Skip to main content</a>
  <?php echo theme('slide_menu') ?>

  <section class="top-bar">
    <div class="top-bar-inner">

      <?php print theme('custom_main_menu'); ?>
      <?php print theme('search'); ?>

    </div>
  </section>
  <div class="logo-container">
    <a class="names mck-logo-icon alone" href="<?php echo url('<front>') ?>"><span class="visually-hidden">McKinsey &amp; Company Home</span></a>
  </div><!--END NAVIGATION MENU-->
  <div class="nav-right">
    <button class="search-nav-button r2-search" type="button"><span class="visually-hidden">Toggle search field</span></button> <button class="search-nav-button-close mobile r2-close" type="button"><span class="visually-hidden">Toggle search field</span></button>
  </div><!-- END NAVIGATION WHITE BAR -->
</header>


<div class="wrapper universal-page">
    

<div class="c-area">
	<div class="main">
		
		<article class="universal-main-content">
			<header id="main_0_universal_0_universal_area_a_0_titleAndDek" class="text-xl">
    <h1 id="main_0_universal_0_universal_area_a_0_titleContainer" class="title headline">
        Contact us
    </h1>
    
</header><div class="scfForm">
<div class="body text-longform">
<div id="main_0_universal_0_form_A787F001F1EE44969C0BEF329191D6C0_intro" class="scfIntroBorder">
	<p class="lead">Please fill out this form to ask any question re: TEDS 2018</p>                                     
                                  
<p>Required fields are marked with an asterisk (*).</p>


<p>For logistics questions, email <a href="mailto:Danielle_Isbell@mckinsey.com">Danielle_Isbell@mckinsey.com</a></p>

 <div class="body text-longform"> <?php print render($content['node-webform']) ?></div>
</div>
</div>

</div>
                        
                      
		</article>
	</div>
	<div class="rail">
		
<section class="up one-up-small-b
	 up-left
	 -imgs-hidden
	
	
	 -display-mode-standard">
    <h2 id="main_0_universal_0_universal_area_b_0_sectionHeader" class="section-header">
       TEDS Logistics questions
    </h2>
    
    <div id="main_0_universal_0_universal_area_b_0_divBlockList" class="block-list text-s">
        

<div class="item">
    
   
        
    
    
    <div class="text-wrapper">
         
        
            <div class="item profile-item">
        <!-- Dev note:
          if render mode = show images, include this div (.image)
          if render mode = hide images, remove this div (unless the page is in editing mode)
        -->
        <div class="image profile-image">
            <div class="circle-crop">
                <div class="image">
                    <a href="#">
                        <img src="https://apps.mckinsey.com/teds-stg/sites/all/themes/mck_know/images/danielle.jpg" alt="">
                    </a>
                </div>
            </div>
        </div>
        <div class="text-wrapper">
            <a href="mailto:Danielle_Isbell@mckinsey.com" class="item-title-link">
                <h4 class="-arrow headline">Danielle Isbell</h4>
            </a>
            <small class="description jobtitle">McKinsey & Company</small>  <!-- job title, region -->
            <div class="description">+1 650 842 5848</div>
	    <div class="description">
Danielle_Isbell@mckinsey.com</div><!-- description -->
        </div>
    </div>
        
    </div>
</div>


    </div>

    
</section>

	</div>
</div>
    
</div>


<div class="wrapper universal-page">
<?php echo render($page['content']) ?>
</div>

<?php print render($messages) ?>


<section class="promo text-l span-full-width -light lighter">
  <div class="wrapper">
    <div class="inner-wrapper">
      <div class="text-wrapper">

        <h3 class="headline">
          
Register ASAP for 2018 TEDS     </h3>

        <div class="promo-links">

          <a href="register" class="link-button mck-email-icon">
            
  Register          </a>
        </div>

      </div>
    </div>
  </div>
</section>

<footer class="global-footer">
  <section class="footer">
    <div class="footer-inner">
      <div class="footer-section">
        <div class="logo-container">
          <span class="names mck-logo-icon alone"><span class="visually-hidden">McKinsey &amp; Company Home</span></span>
        </div>
      
      </div>
    </div>
  </section>
</footer>

<div style="clear: both;"></div>
