<?php

/**
 * @file
 * Administrative page callbacks for the RSVP Notifications module.
 */

/**
 * Form builder to display module settings.
 */
function gfa_adjustments_admin_content($form) {
    $options = array(
        'phpexcel' => 'PHPExcel (PHP 5.2+)',
        'phpspreadsheet' => 'PHPSpreadsheet (PHP 5.6+)'
    );

    $form['gfa_adjustments']['spread_library'] = array(
        '#type' => 'select',
        '#title' => t('Spreadsheet Library:'),
        '#default_value' => variable_get('spread_library', 'phpexcel'),
        '#options' => $options,
        '#description' => t('Select which PHP spreadsheet library to use for export.'),
    );

    $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    return system_settings_form($form);
}