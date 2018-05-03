<?php
/**
 * @file
 * gfa_adjustments.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function gfa_adjustments_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cpa_mnat';
  $feeds_importer->config = array(
    'name' => 'CPA MNAT',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_mnat',
        'host_entity_type' => 'node',
        'guid_field_name' => 'field_uid',
        'is_field' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Name',
            'target' => 'field_user_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Dept',
            'target' => 'field_dept',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Office',
            'target' => 'field_office',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Timesheet',
            'target' => 'field_timesheet_period:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Project Code',
            'target' => 'field_project_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Act Code',
            'target' => 'field_act_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Project Name',
            'target' => 'field_project_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Eng Off',
            'target' => 'field_eng_off',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Regular Hours',
            'target' => 'field_regular_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'OT Hours',
            'target' => 'field_o_t_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Nts Awy',
            'target' => 'field_nts_awy',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'NTs9',
            'target' => 'field_nts9',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Override PD',
            'target' => 'field_override_pd',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'PD Cur',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Tracking Number',
            'target' => 'field_tracking_number',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Hours Reduced/Add',
            'target' => 'field_hours_reduce_or_add_',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'OT Hours Reduced/Add',
            'target' => 'field_ot_hours_reduce_or_add_',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'CC Moved',
            'target' => 'field_cc_to_be_moved',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'New PD Override',
            'target' => 'field_new_pd_override',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'New PD Currency',
            'target' => 'field_new_pd_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'uid',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'fcuid',
            'target' => 'field_fcuid',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_mnat',
        'language' => 'und',
        'identifier_field_name' => 'field_fcuid',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['cpa_mnat'] = $feeds_importer;

  return $export;
}
