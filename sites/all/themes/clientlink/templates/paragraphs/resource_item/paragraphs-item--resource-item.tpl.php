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


$title        = isset($content['field_title']) ? render($content['field_title']['#items'][0]['value']) : '';
$description  = isset($content['field_short_description']) ? $content['field_short_description']['#items'][0]['value'] : '';
$category     = isset($content['field_resource_category']) ? render($content['field_resource_category']) : '';

$category_id     = isset($content['field_resource_category']) ? $content['field_resource_category']['#items'][0]['tid'] : '';

$docuri       = isset($content['field_doc']) ? render($content['field_doc']['#items'][0]['filename']) : NULL;
$docurl       = isset($bguri) ? file_create_url($docuri) : NULL;
$email_doc_link = $GLOBALS['base_url'] . "/sites/default/files/resources/" . $content['field_doc']['#items'][0]['filename'];
$email_body   = "Take a look at the resource file: %0D%0A".$email_doc_link. "%0D%0A ".$description;


$videouri           = isset($content['field_video_upload']['#items'][0]['uri']) ? $content['field_video_upload']['#items'][0]['uri'] : '';
$videourl           = isset($videouri) ? file_create_url($videouri) : NULL;
$video_bguri        = isset($content['field_image']['#items'][0]['uri']) ? $content['field_image']['#items'][0]['uri'] : NULL;
$video_bgurl        = isset($video_bguri) ? file_create_url($video_bguri) : NULL;

/* extract resource categry name from tid */
//echo $category_id;
$category_name = "";
$category_class = "";

if($category_id==5){

	$category_name = "Case Studies";
	$category_class = "case-study";

}elseif($category_id==6){

	$category_name = "Quick Guides";
	$category_class = "quick-guides";

}elseif($category_id==7){

	$category_name = "Videos";
	$category_class = "videos";

}
elseif($category_id==11){

	$category_name = "Newsletter";
	$category_class = "newsletter";

}
?>
<?php if( isset($content['field_video_upload']) ){?>
<div class="card p-3 media-player <?php echo $category_class; ?> ">
    <div class="card-block">
    	
        <p class="caption m-0 pb-1"><?php echo $category_name; ?></p>
		<h5 class="mt-1"><?php echo $title; ?></h5>
		<?php if(isset($content['field_short_description'])){ ?>
		<div class="card-text pt-3 pb-5 "><?php echo $description; ?></div>
		<?php }?>
		<div class="media-video player mfp-hide"  id="video-popup">
			<video  id="resources_video" class="video-js vjs-default-skin vjs-16-9"
	           controls preload="auto" width="640" height="264"
	           poster="<?php echo $video_bgurl ?>"
	           data-setup='{"example_option":true}'>
	       <source src="<?php echo $videourl ?>" type='video/mp4' />

  	     </video>

       </div>
        <div class="bg" style="background-image: url('<?php echo $video_bgurl ?>');">
               <a href="#video-popup"  class="btn play-btn open-popup-link" ></a> 
        </div>

		<p class="links"><a href="<?php echo $videourl ?>" download class="mck-icon mck-icon__download pr-3 mr-3"> </a>
		<a href="mailto:?subject=<?php echo $title; ?>&body=<?php echo $email_body; ?>" class="mck-icon mck-icon__email"></a>

	</p>
    </div>
</div>
<?php }else {?>
<div class="card p-3 <?php echo $category_class; ?> ">
    <div class="card-block">
        <p class="caption m-0 pb-1"><?php print $category_name; ?></p>
		<h5 class="mt-1"><?php echo $title; ?></h5>
		<div class="card-text pt-3 pb-5"><?php echo $description; ?></div>
		<p class="links"><a href="sites/default/files/resources/<?php echo $docuri ; ?>" class="mck-icon mck-icon__download pr-3 mr-3"> </a>
		<a href="mailto:?subject=<?php echo $title; ?>&body=<?php echo $email_body; ?>" class="mck-icon mck-icon__email"></a>
	</p>
    </div>
</div>
<?php } ?>
  
