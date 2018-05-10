<?php
/**
 * @file
 * gfa_feeds_importer_.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function gfa_feeds_importer__feeds_importer_default() {
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
      'plugin_key' => 'FeedsExcelParser',
      'config' => array(
        'all_worksheets' => 0,
        'max_rows' => '100',
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

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cpag';
  $feeds_importer->config = array(
    'name' => 'CPAG',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
        'field_name' => 'field_cpag',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_uid',
        'identifier_field_name' => 'field_fcuid',
        'mappings' => array(
          0 => array(
            'source' => 'PA Period',
            'target' => 'field_pa_period_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Charge Code',
            'target' => 'field_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Hours',
            'target' => 'field_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Overtime',
            'target' => 'field_overtime',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Perdiem',
            'target' => 'field_perdiem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Currency',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'UID',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_cpag',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['cpag'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cparf';
  $feeds_importer->config = array(
    'name' => 'CPARF',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
        'field_name' => 'field_cparf',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_uid',
        'identifier_field_name' => 'field_fcuid',
        'mappings' => array(
          0 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'PA Period',
            'target' => 'field_pa_period_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Charge Code',
            'target' => 'field_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Hours',
            'target' => 'field_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Overtime',
            'target' => 'field_overtime',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Perdiem',
            'target' => 'field_perdiem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Currency',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'UID',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_cparf',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['cparf'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cparn';
  $feeds_importer->config = array(
    'name' => 'cparn',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
        'field_name' => 'field_cparn',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_uid',
        'identifier_field_name' => 'field_fcuid',
        'mappings' => array(
          0 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'First name',
            'target' => 'field_first_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Last Name',
            'target' => 'field_last_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Position Code',
            'target' => 'field_position_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'PCAT',
            'target' => 'field_pcat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Labor Status',
            'target' => 'field_labor_status',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Employment Status',
            'target' => 'field_employment_status',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Complex',
            'target' => 'field_complex',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Sub Complex',
            'target' => 'field_sub_complex',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'User Location Code',
            'target' => 'field_user_location_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'User GOC Code',
            'target' => 'field_user_goc_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'TS Start Date',
            'target' => 'field_ts_start_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Source Action',
            'target' => 'field_source_action',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Charge Code',
            'target' => 'field_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Charge Code GOC Office',
            'target' => 'field_charge_code_goc_office',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Project Name',
            'target' => 'field_project_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Activity Code',
            'target' => 'field_activity_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Billing Sub Type',
            'target' => 'field_billing_sub_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Hours',
            'target' => 'field_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Overtime',
            'target' => 'field_overtime',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Perdiem Local Currency',
            'target' => 'field_perdiem_local_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Effective Perdiem',
            'target' => 'field_effective_perdiem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Perdiem USD',
            'target' => 'field_perdiem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Currency Code',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Source System',
            'target' => 'field_source_system',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'Created By',
            'target' => 'field_created_by',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Created Date',
            'target' => 'field_created_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Creator Location',
            'target' => 'field_creator_location',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'RADAR Reporting Period',
            'target' => 'field_pa_period_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'ORS Create Tstamp',
            'target' => 'field_ors_create_tstamp:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Alternative Code',
            'target' => 'field_alternative_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          31 => array(
            'source' => 'Hours to be Moved',
            'target' => 'field_hours_to_be_moved',
            'unique' => FALSE,
            'language' => 'und',
          ),
          32 => array(
            'source' => 'OT Hours',
            'target' => 'field_ot_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          33 => array(
            'source' => 'POC(Local Office)',
            'target' => 'field_poc',
            'unique' => FALSE,
            'language' => 'und',
          ),
          34 => array(
            'source' => 'Downloaded',
            'target' => 'field_downloaded',
            'unique' => FALSE,
            'language' => 'und',
          ),
          35 => array(
            'source' => 'uid',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_cparn',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['cparn'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ppa';
  $feeds_importer->config = array(
    'name' => 'PPA',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
        'field_name' => 'field_ppa',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_uid',
        'identifier_field_name' => 'field_fcuid',
        'mappings' => array(
          0 => array(
            'source' => 'PA Period',
            'target' => 'field_pa_period_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Charge Code',
            'target' => 'field_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Hours',
            'target' => 'field_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Overtime',
            'target' => 'field_overtime',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Perdiem',
            'target' => 'field_perdiem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Currency',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'UID',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_ppa',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['ppa'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pppece';
  $feeds_importer->config = array(
    'name' => 'PPPECE',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
        'field_name' => 'field_pppece',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_uid',
        'identifier_field_name' => 'field_fcuid',
        'mappings' => array(
          0 => array(
            'source' => 'PA Period',
            'target' => 'field_pa_period_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Charge Code',
            'target' => 'field_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'PE Charge Code',
            'target' => 'field_charge',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Hours',
            'target' => 'field_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Overtime',
            'target' => 'field_overtime',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Perdiem',
            'target' => 'field_perdiem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Currency',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'UID',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_pppece',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['pppece'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'shbp';
  $feeds_importer->config = array(
    'name' => 'SHBP',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
        'field_name' => 'field_shbp',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => 'field_uid',
        'identifier_field_name' => '',
        'mappings' => array(
          0 => array(
            'source' => 'PA Period',
            'target' => 'field_project_office_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'FMNO',
            'target' => 'field_fmno',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Project Number',
            'target' => 'field_project_number',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'First Name',
            'target' => 'field_first_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Last Name',
            'target' => 'field_last_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'FMNO GOC',
            'target' => 'field_fmno_goc_office',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'FMNO Dept',
            'target' => 'field_fmno_dept',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'FMNO Dept Name',
            'target' => 'field_fmno_dept_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'PCAT Name',
            'target' => 'field_pcat_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'PCAT',
            'target' => 'field_pcat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Hours',
            'target' => 'field_hours',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Days',
            'target' => 'field_days',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Transaction Amount LC',
            'target' => 'field_transaction_amount_lc',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'WIP Per Diem',
            'target' => 'field_wip_per_diem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Table Per Diem',
            'target' => 'field_table_b_per_diem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Nominal Per Diem',
            'target' => 'field_nominal_per_diem',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Staffing Office',
            'target' => 'field_staffing_office',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Entry Office',
            'target' => 'field_entry_office',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'GL Date',
            'target' => 'field_gl_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Timesheet Period',
            'target' => 'field_pa_period_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Fees at Risk',
            'target' => 'field_fees_at_risk',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Fees at Risk Recovery',
            'target' => 'field_fees_at_risk_recovery',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'NRR by Timesheet Period',
            'target' => 'field_nrr_by_timesheet_period',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Timesheet Month',
            'target' => 'field_timesheet_month',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Firm Member Staffed Project',
            'target' => 'field_firm_member_staffed_to_pro',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'Firm Member CER Billing',
            'target' => 'field_firm_member_on_cer_billing',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'New Per Diem',
            'target' => 'field_new_per_diem_amount',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Currency',
            'target' => 'field_currency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'uid',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_shbp',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['shbp'] = $feeds_importer;

  return $export;
}
