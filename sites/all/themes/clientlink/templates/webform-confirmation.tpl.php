<?php 

$referer = $_SERVER['HTTP_REFERER'];

?>

<div class="row">
	<div class="col-10 p-5 m-5 mx-auto">
         <h2 class="mb-5">Thank you, your submission has been received.</h2>
         <p class="text-center"><a href="<?php echo $referer; ?>" class="mck-button">Go back to the form</a></p>
     </div>
</div>