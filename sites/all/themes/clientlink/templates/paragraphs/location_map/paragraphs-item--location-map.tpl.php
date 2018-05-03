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
?>
<div class="row location-map-wrapper mt-5 py-5">  
    <div class="col-12 location-map"> 
        <?php if(isset($content['field_heading'])){ ?>
           <div class="mb-3">
               <div class="col-12 p-0">
                   <h4 class="main-heading"><?php echo trim(render($content['field_heading'])) ?></h4>
               </div>     
           </div>    
        <?php } ?>
    <div class="row" style="margin:0">
        <div class="col-lg-4 col-md-4 col-sm-12 location-details p-5" data-zoom="15">
            <h3 class="headline"><?php echo trim(render($content['field_title'])) ?></h3>
            <p class="location-address address"><?php echo nl2br(trim(strip_tags(render($content['field_address'])))) ?></p>
            <p class="location-address phone mt-5">
            <?php if( isset($content['field_office']) ) { ?>
                Voice: <a href="tel:<?php echo trim(render($content['field_office'])) ?>"><?php echo trim(render($content['field_office'])) ?></a>
            <?php } ?>
            <br/>
            <?php if(isset($content['field_sub_title'])) { ?>
            Fax: <a target="_blank" href="<?php echo trim(render($content['field_sub_title'])) ?>"><?php echo trim(render($content['field_sub_title'])) ?></a>
            <?php }?>
            </p>
        </div>
        <section class="col-lg-8 col-md-8 col-sm-12 p-0">
                <?php echo render($content['field_map_embed']) ?>
        </section>
    </div>  
</div>
</div>