<?php

function check_mnat_file_valdation($body) {
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

  if ($body['J'] &&  is_numeric($body['J']) && intval($body['J']) == floatval($body['J'])) {
    $error['error'] = true;
    $error['message'] = "Column J of " . $key . " should have float value.";
    return $error;
  }

  if ($body['K'] &&  is_numeric($body['K']) && intval($body['K']) == floatval($body['K'])) {
    $error['error'] = true;
    $error['message'] = "Column K of " . $key . " should have float value.";
    return $error;
  }

  if (!$body['N']  && !$body['O']) {
    $error['error'] = true;
    $error['message'] = "Both Column N and O of Row " . $key . " can't be null.";
    return $error;
  }

  if (!$body['Q']  && !$body['R']) {
    $error['error'] = true;
    $error['message'] = "Both Column Q and R of Row " . $key . " can't be null.";
    return $error;
  }

  if ($body['Q'] && is_numeric($body['Q']) && intval($body['Q']) == floatval($body['Q'])) {
    $error['error'] = true;
    $error['message'] = "Column Q of " . $key . " should have float value.";
    return $error;
  }

  if ($body['R'] && is_numeric($body['R']) && intval($body['R']) == floatval($body['R'])) {
    $error['error'] = true;
    $error['message'] = "Column R of " . $key . " should have float value.";
    return $error;
  }

  if (!$body['S']) {
    $error['error'] = true;
    $error['message'] = 'Column S of Row ' . $key . ' is required';
    return $error;
  }

  if (!$body['T']  && !$body['U']) {
    $error['error'] = true;
    $error['message'] = "Both Column T and U of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

function check_cparn_file_valdation($body) {
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

  if ($body['S'] &&  is_numeric($body['S']) && intval($body['S']) == floatval($body['S'])) {
    $error['error'] = true;
    $error['message'] = "Column S of " . $key . " should have float value.";
    return $error;
  }

  if ($body['T'] &&  is_numeric($body['T']) && intval($body['T']) == floatval($body['T'])) {
    $error['error'] = true;
    $error['message'] = "Column R of " . $key . " should have float value.";
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

  if ($body['AF'] && is_numeric($body['AF']) && intval($body['AF']) == floatval($body['AF'])) {
    $error['error'] = true;
    $error['message'] = "Column AF of " . $key . " should have float value.";
    return $error;
  }

  if ($body['AG'] && is_numeric($body['AG']) && intval($body['AG']) == floatval($body['AG'])) {
    $error['error'] = true;
    $error['message'] = "Column AG of " . $key . " should have float value.";
    return $error;
  }
  return $error;
}

function check_cparf_file_valdation($body) {
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

  if ($body['D'] && is_numeric($body['D']) && intval($body['D']) == floatval($body['D'])) {
    $error['error'] = true;
    $error['message'] = "Column D of " . $key . " should have float value.";
    return $error;
  }

  if ($body['E'] && is_numeric($body['E']) && intval($body['E']) == floatval($body['E'])) {
    $error['error'] = true;
    $error['message'] = "Column E of " . $key . " should have float value.";
    return $error;
  }

  if (!$body['F']  && !$body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column F and G of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

function check_cpag_file_valdation($body) {
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

  if ($body['D'] &&  is_numeric($body['D']) && intval($body['D']) == floatval($body['D'])) {
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

  if (!$body['F']  && !$body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column F and G of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

function check_ppa_file_valdation($body) {
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

  if ($body['D'] &&  is_numeric($body['D']) && intval($body['D']) == floatval($body['D'])) {
    $error['error'] = true;
    $error['message'] = "Column D of " . $key . " should have float value.";
    return $error;
  }

  if ($body['E'] &&  is_numeric($body['E']) && intval($body['E']) == floatval($body['E'])) {
    $error['error'] = true;
    $error['message'] = "Column E of " . $key . " should have float value.";
    return $error;
  }

  if (!$body['F']  && !$body['G']) {
    $error['error'] = true;
    $error['message'] = "Both Column F and G of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

function check_pppece_file_valdation($body) {
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

  if ($body['E'] &&  is_numeric($body['E']) && intval($body['E']) == floatval($body['E'])) {
    $error['error'] = true;
    $error['message'] = "Column E of " . $key . " should have float value.";
    return $error;
  }

  if ($body['F'] &&  is_numeric($body['F']) && intval($body['F']) == floatval($body['F'])) {
    $error['error'] = true;
    $error['message'] = "Column F of " . $key . " should have float value.";
    return $error;
  }

  if (!$body['G']  && !$body['H']) {
    $error['error'] = true;
    $error['message'] = "Both Column F and G of Row " . $key . " can't be null.";
    return $error;
  }
  return $error;
}

function check_shbp_file_valdation($body) {
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

  if ($body['J'] && is_numeric($body['J']) && intval($body['J']) == floatval($body['J'])) {
    $error['error'] = true;
    $error['message'] = 'Column J of Row ' . $key . ' should have float value.';
    return $error;
  }

  if (!$body['M']) {
    $error['error'] = true;
    $error['message'] = 'Column M of Row ' . $key . ' is required';
    return $error;
  }

  if ($body['M'] && is_numeric($body['M']) && intval($body['M']) == floatval($body['M'])) {
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

  if ($body['Z'] &&  is_numeric($body['Z']) && intval($body['Z']) == floatval($body['Z'])) {
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
