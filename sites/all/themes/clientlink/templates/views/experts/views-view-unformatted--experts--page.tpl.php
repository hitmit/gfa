
<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */



   $main_category = array();
   $row_results = array();


	foreach ($view->result as $catrow) {
	   $team_category = (isset($catrow->field_field_team_category)) ? $catrow->field_field_team_category[0]['rendered']['#title'] : '';

	   if (!(in_array($team_category, $main_category))) {
   			  $main_category[] = $team_category;
		}
	  
	}

?>


<div class="row experts-results mx-3">

<?php 

$cat_results = array();
 foreach ($view->result as $key=>$resultrow) {

 	 $team_category = (isset($resultrow->field_field_team_category)) ? $resultrow->field_field_team_category[0]['rendered']['#title'] : '';
 	 
		foreach ($main_category as $cat) {
     
		     if($cat === $team_category){
					$cat = str_replace("","_",$cat);
					$cat = strtolower($cat);			
					$row_results[$cat][$key] = $resultrow;
					ddl($row_results);
			  }
     	}
}


 foreach($row_results as $key=>$rowresult){ 
	$key = str_replace("_","",$key);
	$key = ucwords($key);


?>

<div class="col-12 ">
	<div class="row">
		<div class="col-12">
			<h4 class="mb-5 pb-3"><?php echo $key; ?></h4>
		</div>
	</div>
<div class="row">
<?php
ddl($rowresult);

   foreach($rowresult as $row){


	$mainImage = (isset($row->field_field_image[0])) ? $row->field_field_image[0]['rendered']['#item']['uri'] : NULL;
	$mainImageUrl = (isset($mainImage) && !empty($mainImage)) ? file_create_url($mainImage) : '';

	$title = (isset($row->field_field_title[0])) ? $row->field_field_title[0]['raw']['value'] : '';
	$sub_title = (isset($row->field_field_sub_title[0])) ? $row->field_field_sub_title[0]['raw']['value'] : '';
	$description = (isset($row->field_field_description[0])) ? $row->field_field_description[0]['rendered']['#markup'] : '';
    $location = (isset($row->field_field_location[0])) ? $row->field_field_location[0]['rendered']['#title'] : '';
    $main_category = (isset($row->field_field_team_category)) ? $row->field_field_team_category[0]['rendered']['#title'] : '';
    $link = (isset($row->field_field_know_link[0])) ? $row->field_field_know_link[0]['raw']['url'] : NULL;
    
?>

   

<div class="col-lg-4 col-md-6 col-sm-12 ">
	<div class="row  m-0">
		<?php if (isset($link) && !empty($link)) { ?>
			<a target="blank" href="<?php echo $link; ?>" class="bg col-md-5 col-sm-12 rounded-circle" style="background-image: url('<?php echo $mainImageUrl ?>');"></a>
			<div class="card-content col-md-7  col-sm-12 pb-5 pl-3 pr-0 pt-4" >
				<a target="_blank" href="<?php echo $link; ?>"><h5 class="-arrow"><?php  echo $title; ?></h5></a>
				<p class="mb-0"><?php  echo $sub_title; ?>, <?php echo $location; ?></p>
				<div class="card-text p-0 pt-2 pb-2">
			        <?php  echo $description; ?>
				</div>				
		    </div>
		<?php } else { ?>
			<div class="bg col-md-5 col-sm-12 rounded-circle" style="background-image: url('<?php echo $mainImageUrl ?>');"></div>
			<div class="card-content col-md-7  col-sm-12 pb-5 pl-3 pr-0 pt-4" >
				<h5><?php  echo $title; ?></h5>
				<p class="mb-0"><?php  echo $sub_title; ?>, <?php echo $location; ?></p>
				<div class="card-text p-0 pt-2 pb-2">
			        <?php  echo $description; ?>
				</div>				
		    </div>
		<?php } ?>
    </div>
</div>
<?php }?>
</div>


</div>

<?php  }  ?>
