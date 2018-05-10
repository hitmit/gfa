<?php
$adjTypeForm = drupal_get_form('adj_select_form');
$feedForm = drupal_get_form('gfa_feed_document_add_form');

$formArray = array($adjTypeForm, $feedForm);
print drupal_render($formArray);
?>
