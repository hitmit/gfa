<?php

class people_api  {

  function gfa_get_key(){

    $current_key = variable_get('nvc_key',0);
    $key_expires = variable_get('nvc_expires',0);

    if($key_expires < time()){

      $url = "http://apioauth.mckinsey.com/asg/oauth2/access_token";
      $headers = array('Content-Type' => 'application/x-www-form-urlencoded');
      $data = array("grant_type" => "client_credentials",
        "scope" => "public",
        "client_id" => "2040-bb6b86ac-efcf-4afe-b860-77f3c1bf7dba",
        "client_secret" => "8ce27d0e-10c1-4d65-8603-244ceb005959");

      $options = array(
        'method' => 'POST',
        'data' => drupal_http_build_query($data),
  
        'timeout' => 15,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      );
      $response = drupal_http_request($url,$options);
      $datar = json_decode($response->data);

      variable_set('nvc_key',$datar->access_token);
      variable_set('nvc_expires',$datar->expires_in + time());
      return $datar->access_token;
    }else{
      return $current_key;
    }
  }

  function gfa_person_suggest_query_name($name = '') {
    $api = 'http://api.mckinsey.com/v3/persons/autosuggest';
    $query = array(
      'access_token' => $this->gfa_get_key(),
      'q' => urlencode($name),
      'random' => time(),
    );
    $request = url($api, array('query' => $query));

    $options = array(
      'method' => 'GET',
      'timeout' => 15,
      'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
    );

    /*watchdog('nvc_person_suggest',$request);*/
    $response = drupal_http_request($request, $options);
    return json_decode($response->data);
  }

  function gfa_get_user_fmno($name = '', $officeCode = '', $email = '')  {
    $people = $this->gfa_person_suggest_query_name($name);
    $people = $people->response->persons;
    $datar = "No FMNO found";
    
    foreach($people as $person) {
      $apiOfficeCode = $person->core->gocOfficeCode;
      $apiFMNO = $person->core->fmno;
      $apiEmail = $person->contact->emails[0]->emailAddress;
      if((isset($apiOfficeCode) && !empty($apiOfficeCode)) && (isset($officeCode) && !empty($officeCode))) {
        if($apiOfficeCode == $officeCode) {
          if((isset($apiEmail) && !empty($apiEmail)) && (isset($email) && !empty($email))) {
            if($apiEmail == $email) {
              $datar = $apiFMNO;
              break;
            }
          } else  {
            $datar = $apiFMNO;
          }
        }
      }
    }

    return  $datar;
  }
}