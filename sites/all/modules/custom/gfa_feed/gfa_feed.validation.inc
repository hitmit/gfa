<?php

/**
 * Validation function for mnat form.
 */
function check_mnat_file_valdation($key, $body) {
  $error['error'] = false;
  if (!$body['A']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['A'] && !is_numeric($body['A'])) {
    $error['error'] = true;
    $error['message'] = 'Column A should of ' . $key . ' should be numeric value';
    return $error;
  }
  
  if (!$body['E']) {
    $error['error'] = true;
    $error['message'] = 'Column E of Row ' . $key . ' is required';
    return $error;
  }
 
  if (!$body['F']) {
    $error['error'] = true;
    $error['message'] = 'Column F of Row ' . $key . ' is required';
    return $error;
  }

  if ((!$body['J']  && !$body['K'])) {
    $error['error'] = true;
    $error['message'] = "Both Column J and K of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['J'] &&  !is_decimal($body['J'])) {
    $error['error'] = true;
    $error['message'] = "Column J of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['K'] &&  !is_decimal($body['K'])) {
    $error['error'] = true;
    $error['message'] = "Column K of " . $key . " should have float value.";
    return $error;
  }

  if ($body['N'] && !$body['O']) {
    $error['error'] = true;
    $error['message'] = "Both Column O of Row " . $key . " can't be null.";
    return $error;
  }


  if (!$body['N'] && $body['O']) {
    $error['error'] = true;
    $error['message'] = "Both Column N of Row " . $key . " can't be null.";
    return $error;
  }

  if (!$body['Q']  && !$body['R']) {
    $error['error'] = true;
    $error['message'] = "Both Column Q and R of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['Q'] && !is_decimal($body['Q'])) {
    $error['error'] = true;
    $error['message'] = "Column Q of " . $key . " should have float value.";
    return $error;
  }

  if ($body['R'] && !is_decimal($body['R'])) {
    $error['error'] = true;
    $error['message'] = "Column R of Row " . $key . " should have float value.";
    return $error;
  }

  if (!$body['S']) {
    $error['error'] = true;
    $error['message'] = 'Column S of Row ' . $key . ' is required';
    return $error;
  }

  
  if ($body['T'] && !$body['U']) {
    $error['error'] = true;
    $error['message'] = "Both Column U of Row " . $key . " can't be null.";
    return $error;
  }


  if (!$body['T'] && $body['U']) {
    $error['error'] = true;
    $error['message'] = "Both Column T of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

/**
 * Validation function for cparn form.
 */
function check_cparn_file_valdation($key, $body) {
  $error['error'] = false;    
  if (!$body['A']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['A'] && !is_numeric($body['A'])) {
    $error['error'] = true;
    $error['message'] = "Column A of " . $key . " should have numeric value.";
    return $error;
  }

  if (!$body['L']) {
    $error['error'] = true;
    $error['message'] = 'Column L of Row ' . $key . ' is required';
    return $error;
  }
  if (!$body['N']) {
    $error['error'] = true;
    $error['message'] = 'Column N of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['S']  && !$body['T']) {
    $error['error'] = true;
    $error['message'] = "Both Column S and T of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['S'] &&  !is_decimal($body['S'])) {
    $error['error'] = true;
    $error['message'] = "Column S of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['T'] &&  !is_decimal($body['T'])) {
    $error['error'] = true;
    $error['message'] = "Column R of Row " . $key . " should have float value.";
    return $error;
  }

  if (!$body['AE']) {
    $error['error'] = true;
    $error['message'] = 'Column N of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['AF']  && !$body['AG']) {
    $error['error'] = true;
    $error['message'] = "Both Column F and G of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['AF'] && !is_decimal($body['AF'])) {
    $error['error'] = true;
    $error['message'] = "Column AF of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['AG'] && !is_decimal($body['AG'])) {
    $error['error'] = true;
    $error['message'] = "Column AG of Row " . $key . " should have float value.";
    return $error;
  }
  return $error;
}

/**
 * Validation function for cparf form.
 */
function check_cparf_file_valdation($key, $body) {
  $error['error'] = false; 
  if (!$body['A']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }
  
  if (!$body['B']) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['B'] && !is_numeric($body['B'])) {
    $error['error'] = true;
    $error['message'] = "Column B of " . $key . " should have numeric value.";
    return $error;
  }
  
  if (!$body['C']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['D']  && !$body['E']) {
    $error['error'] = true;
    $error['message'] = "Both Column D and E of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['D'] && !is_decimal($body['D'])) {
    $error['error'] = true;
    $error['message'] = "Column D of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['E'] && !is_decimal($body['E'])) {
    $error['error'] = true;
    $error['message'] = "Column E of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['F'] && !$body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column G of Row " . $key . " can't be null.";
    return $error;
  }

  if (!$body['F'] && $body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column F of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

/**
 * Validation function for cpag form.
 */
function check_cpag_file_valdation($key, $body) {
  $error['error'] = false;
  if (!$body['A']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['A'] && !is_numeric($body['A'])) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['B']) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['B'] && !is_numeric($body['B'])) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['C']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['D']) {
    $error['error'] = true;
    $error['message'] = 'Column D of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['D'] &&  !is_decimal($body['D'])) {
    $error['error'] = true;
    $error['message'] = "Column D  of Row " . $key . " should have float value.";
    return $error;
  }

  if (is_numeric(intval($body['D'])) && is_numeric(intval($body['D'])) < 0) {
    $error['error'] = true;
    $error['message'] = "Column D  of Row " . $key . " can't be less than 0.";
    return $error;
  }

  if (!$body['E']) {
    $error['error'] = true;
    $error['message'] = 'Column E of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['F'] && !$body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column G of Row " . $key . " can't be null.";
    return $error;
  }


  if (!$body['F'] && $body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column F of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

/**
 * Validation function for ppa form.
 */
function check_ppa_file_valdation($key, $body) {
  $error['error'] = false;
  if (!$body['A']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['A'] && !is_numeric($body['A'])) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['B']) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['B'] && !is_numeric($body['B'])) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['C']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['D']  && !$body['E']) {
    $error['error'] = true;
    $error['message'] = "Both Column D and E of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['D'] &&  !is_decimal($body['D'])) {
    $error['error'] = true;
    $error['message'] = "Column D of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['E'] &&  !is_decimal($body['E'])) {
    $error['error'] = true;
    $error['message'] = "Column E of  Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['F'] && !$body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column G of Row " . $key . " can't be null.";
    return $error;
  }

  if (!$body['F'] && $body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column F of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

/**
 * Validation function for pppece form.
 */
function check_pppece_file_valdation($key, $body) {
  $error['error'] = false;
  if (!$body['A']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['A'] && !is_numeric($body['A'])) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['B']) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['B'] && !is_numeric($body['B'])) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['C']) {
    $error['error'] = true;
    $error['message'] = 'Column A of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['D']) {
    $error['error'] = true;
    $error['message'] = 'Column D of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['E']  && !$body['F']) {
    $error['error'] = true;
    $error['message'] = "Both Column E and F of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['E'] &&  !is_decimal($body['E'])) {
    $error['error'] = true;
    $error['message'] = "Column E of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['F'] &&  !is_decimal($body['F'])) {
    $error['error'] = true;
    $error['message'] = "Column F of Row " . $key . " should have float value.";
    return $error;
  }

  if ($body['G'] && !$body['H']) {
    $error['error'] = true;
    $error['message'] = "Both Column H of Row " . $key . " can't be null.";
    return $error;
  }


  if (!$body['G'] && $body['H']) {
    $error['error'] = true;
    $error['message'] = "Both Column G of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

/**
 * Validation function for shbp form.
 */
function check_shbp_file_valdation($key, $body) {
  $error['error'] = false;
  if (!$body['B']) {
    $error['error'] = true;
    $error['message'] = 'Column B of Row ' . $key . ' is required';
    return $error;
  }
  
  if (!$body['C']) {
    $error['error'] = true;
    $error['message'] = 'Column C of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['C'] && !is_numeric($body['C'])) {
    $error['error'] = true;
    $error['message'] = 'Column C of Row ' . $key . ' should have numeric value.';
    return $error;
  }
  
  if (!$body['J']) {
    $error['error'] = true;
    $error['message'] = 'Column J of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['J'] && !is_decimal($body['J'])) {
    $error['error'] = true;
    $error['message'] = 'Column J of Row ' . $key . ' should have float value.';
    return $error;
  }

  if (!$body['M']) {
    $error['error'] = true;
    $error['message'] = 'Column M of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['M'] && !is_decimal($body['M'])) {
    $error['error'] = true;
    $error['message'] = 'Column M of Row ' . $key . ' should have float value.';
    return $error;
  }

  if (!$body['S']) {
    $error['error'] = true;
    $error['message'] = 'Column S of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['S'] && !is_numeric($body['S'])) {
    $error['error'] = true;
    $error['message'] = 'Column S of Row ' . $key . ' should have numeric value.';
    return $error;
  }

  if (!$body['Z']) {
    $error['error'] = true;
    $error['message'] = 'Column Z of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['Z'] &&  !dcimal($body['Z'])) {
    $error['error'] = true;
    $error['message'] = 'Column Z of Row ' . $key . ' should have float value.';
    return $error;
  }

  if (!$body['AA']) {
    $error['error'] = true;
    $error['message'] = 'Column AA of Row ' . $key . ' is required';
    return $error;
  }
  return $error;
}
