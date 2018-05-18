<?php
/**
 * @file
 * gfa_feeds_importer_.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function gfa_feeds_importer__feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'cpa_mnat-fcuid-unique';
  $feeds_tamper->importer = 'cpa_mnat';
  $feeds_tamper->source = 'fcuid';
  $feeds_tamper->plugin_id = 'unique';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Unique';
  $export['cpa_mnat-fcuid-unique'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'cpa_mnat-fmno-cast_to_int';
  $feeds_tamper->importer = 'cpa_mnat';
  $feeds_tamper->source = 'FMNO';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Cast to integer';
  $export['cpa_mnat-fmno-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'cpa_mnat-fmno-copy';
  $feeds_tamper->importer = 'cpa_mnat';
  $feeds_tamper->source = 'FMNO';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'to',
    'source' => 'Tracking Number',
  );
  $feeds_tamper->weight = 7;
  $feeds_tamper->description = 'Copy source value';
  $export['cpa_mnat-fmno-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'cpa_mnat-fmno-trim';
  $feeds_tamper->importer = 'cpa_mnat';
  $feeds_tamper->source = 'FMNO';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Trim';
  $export['cpa_mnat-fmno-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'cpa_mnat-regular_hours-rewrite';
  $feeds_tamper->importer = 'cpa_mnat';
  $feeds_tamper->source = 'Regular Hours';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '11',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['cpa_mnat-regular_hours-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'cparn-uid-efq_finder';
  $feeds_tamper->importer = 'cparn';
  $feeds_tamper->source = 'uid';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'node',
    'bundle' => 'cparn',
    'field' => 'field_uid',
    'column' => 'value',
    'property' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['cparn-uid-efq_finder'] = $feeds_tamper;

  return $export;
}
