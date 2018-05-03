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
//ddl($content);
$imageUri = (isset($content['field_image']['#items'][0]['uri']) && !empty($content['field_image']['#items'][0]['uri'])) ? $content['field_image']['#items'][0]['uri'] : NULL;
$imageUrl = (isset($imageUri) && !empty($imageUri)) ? file_create_url($imageUri) : NULL;
$title = $content['field_title']['#items'][0]['value'];
$description = (isset($content['field_description']['#items'][0]['value']) && !empty($content['field_description']['#items'][0]['value'])) ? $content['field_description']['#items'][0]['value'] : NULL;

?>

<div class="background-card background-image-main_0_universal_0_ctl00">
    <div class="visually-hidden preload-hero">
        <?php /*<picture>
            <source srcset="<?php echo $imageUrl; ?>" media="(max-width: 767px)">
            <source srcset="<?php echo $imageUrl; ?>" media="(min-width: 768px) and (max-width: 1180px)">
            <img src="<?php echo $imageUrl; ?>" alt="">
        </picture> */ ?>
    </div>

    <div class="background-card-bg background-image-main_0_universal_0_ctl00" style="background:url(<?php echo $imageUrl; ?>)"></div>
    <div class="background-card-overlay -color-cyan"></div>

    <div class="text-render">
        <div class="text-wrapper text-xl">
            <h3 id="main_0_universal_0_ctl00_sectionHeadline" class="headline"><?php echo $title; ?>
            	<div class="background-card-arrow mck-link-arrow-icon"></div>
            </h3>
        </div>
    </div>
</div>

<style>

.background-card.background-image-main_0_universal_0_ctl00 .background-card-overlay {
	opacity: 0;
}
.background-card.background-image-main_0_universal_0_ctl00:hover .background-card-overlay {
    opacity: 0.9;
}
.headline, .rail-article-title {
    font-family: "Chronicle Deck",Georgia,Times,"Times New Roman",serif;
    letter-spacing: -.02em;
    font-weight: 600;
    font-style: normal;
}
.mck-link-arrow-icon::before {
    content: "";
}
[class*=" mck-"]::before, [class^="mck-"]::before {
    font-family: mck-icons;
    speak: none;
    font-style: normal;
    font-weight: 400;
    font-variant: normal;
    text-transform: none;
    line-height: 1;
}
.grid-wall.-display-light .background-card .text-wrapper .headline {
 color:#fff
}
.grid-wall.-text-align-center .background-card .text-wrapper {
 text-align:center
}
.grid-wall.-text-align-right .background-card .text-wrapper {
 text-align:right
}
.grid-wall.-vertical-centered .background-card .text-wrapper .headline {
 top:50%;
 -ms-transform:translateY(-50%);
 transform:translateY(-50%)
}
.grid-wall.-vertical-low .background-card .text-wrapper .headline {
 bottom:0
}
.grid-wall.-theme-standard .animation-card.-in-view {
 z-index:10;
 box-shadow:0 10px 50px 2px rgba(0,41,96,.32);
 background-color:#00adef
}
.grid-wall.-theme-digital .animation-card .headline {
 color:#1f40e6
}
.grid-wall.-theme-digital .animation-card.-in-view .headline {
 color:#fff
}
.grid-wall.-theme-digital .animation-card.-in-view .animation-card-line {
 border-bottom:1px solid #00adef
}
@media screen and (min-width:89.9375empx) {
 .grid-wall.-type-background-image .grid-holder.span-full-width {
  max-width:initial;
  width:100%;
  margin-left:0
 }
}
.grid-wall .module-header .headline {
 display:inline-block
}
.grid-wall .module-header .headline.-color-standard,.grid-wall .module-header .headline.-gradient-standard {
 color:#00306e
}
.grid-wall .module-header .headline.-color-super-blue,.grid-wall .module-header .headline.-gradient-super-blue {
 color:#37dee7
}
.grid-wall .module-header .headline.-color-electric-blue,.grid-wall .module-header .headline.-gradient-electric-blue {
 color:#1f40e6
}
.grid-wall .module-header .headline.-color-warm,.grid-wall .module-header .headline.-gradient-warm {
 color:#ff8500;
 background:linear-gradient(left,#cd202c,#ff8500);
 background:-webkit-linear-gradient(left,#cd202c,#ff8500);
 -webkit-background-clip:text;
 background-clip:text;
 text-fill-color:transparent;
 -webkit-text-fill-color:transparent;
 padding-bottom:2px
}
.grid-wall .module-header .headline.-color-cool,.grid-wall .module-header .headline.-gradient-cool {
 color:#009aa6;
 background:linear-gradient(left,#009aa6,#63337d);
 background:-webkit-linear-gradient(left,#009aa6,#63337d);
 -webkit-background-clip:text;
 background-clip:text;
 text-fill-color:transparent;
 -webkit-text-fill-color:transparent;
 padding-bottom:2px
}
.grid-wall .module-header .headline.-color-electric,.grid-wall .module-header .headline.-color-electric-gradient,.grid-wall .module-header .headline.-gradient-electric,.grid-wall .module-header .headline.-gradient-electric-gradient {
 color:#1f40e6;
 background:linear-gradient(left,#1f40e6,#37dee7);
 background:-webkit-linear-gradient(left,#1f40e6,#37dee7);
 -webkit-background-clip:text;
 background-clip:text;
 text-fill-color:transparent;
 -webkit-text-fill-color:transparent;
 padding-bottom:2px
}
.grid-wall .card-link h1,.grid-wall .card-link h2,.grid-wall .card-link h3,.grid-wall .card-link li,.grid-wall .card-link p {
 transition:none
}
.grid-wall .cta .-arrow {
 transition:right .4s
}
.background-card {
 background:#000;
 height: 400px;
 overflow:hidden;
 position:relative
}
.background-card:hover .background-card-bg {
 -ms-transform:scale(1.05);
 transform:scale(1.05);
 opacity:.9
}
.background-card:hover .background-card-arrow {
 -ms-transform:translateX(0);
 transform:translateX(0);
 opacity:1
}
.background-card .background-card-bg {
 width:100%;
 height:100%;
 padding-bottom:100%;
 background-size:cover;
 background-position:center center;
 opacity:1;
 transform:translateZ(0) scale(1.01,1.01);
 transition:transform .4s ease-in-out,opacity .4s ease-in-out;
 backface-visibility:hidden
}
.background-card .background-card-overlay {
 background-color:#00adef;
 width:100%;
 height:100%;
 position:absolute;
 margin-top:-100%;
 opacity:0;
 transition:opacity .4s ease-in-out;
 backface-visibility:hidden
}
.background-card .background-card-overlay.-color-darkblue {
 background-color:#00306e
}
.background-card .background-card-overlay.-color-superblue {
 background-color:#37dee7
}
.background-card .background-card-overlay.-color-electricblue {
 background-color:#1f40e6
}
.background-card .background-card-overlay.-color-black {
 background-color:#000
}
.background-card .background-card-overlay.-color-white {
 background-color:#fff
}
.background-card .text-render {
 position:absolute;
 top:0;
 left:0;
 right:0;
 bottom:0;
 padding:12%
}
.background-card .text-wrapper {
 height:100%;
 position:relative
}
.background-card .text-wrapper .headline {
 display:inline-block;
 position:absolute;
 width:100%;
 left:0;
 backface-visibility:hidden;
 text-shadow:1px 1px 0 rgba(0,0,0,.2)
}
.background-card .background-card-arrow {
 margin-top:10px;
 transition:transform .4s ease-in-out,opacity .4s ease-in-out;
 -ms-transform:translateX(-60px);
 transform:translateX(-60px);
 opacity:0
}
@media screen and (min-width:560px) {
 .background-card {
  float:left;
  width:50%
 }
}
@media screen and (min-width:62.375em) {
 .background-card .text-wrapper .headline {
  font-size:2.25rem;
  line-height:1em
 }
}
</style>