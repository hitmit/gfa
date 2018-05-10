<?php

// Include PHPSpreadsheet with composer autoloader.
require drupal_get_path('module', 'gfa_adjustments') . '/vendor/autoload.php';
use PhpOffice\PhpSpreadsheet\Spreadsheet;
use PhpOffice\PhpSpreadsheet\Writer\Xlsx;

/**
 * Update boolean field_downloaded from 0 to 1.
 */
function updateDownloaded($entities) {
    foreach($entities as $entity) {
        $fci_wrapper = entity_metadata_wrapper('field_collection_item', $entity);
        $fci_wrapper->field_downloaded->set(1);
        $fci_wrapper->save();
    }
}

/**
 * Export query results to spreadsheet.
 * $arg1 = 'input' or 'output'
 * $arg2 = Adjustment type e.g. 'ppa'
 * $arg3 = 'all' or 'new'
 */
function export_spreadsheet($arg1, $arg2, $arg3) {
    if(!isset($arg1) || empty($arg1)) {
        $arg1 = 'output';
    }
    if(!isset($arg2) || empty($arg2)) {
        $arg2 = 'mnat';
    }
    if(!isset($arg3) || empty($arg3)) {
        $arg3 = 'new';
    }

    $adj = new adjustments();
    $paPeriod = $adj->getPAPeriod($arg2);
    $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;

    $efq = $adj->queryAdjustments($arg2, $arg3, $paPeriodCode);
    $entities = entity_load('field_collection_item', $efq);

    $arrayData = $adj->createAdjustmentOutput($entities, $arg1, $arg2, $paPeriod);

    if(!empty($arrayData[1])) {
        $library = variable_get('spread_library', 'phpexcel');
        $filename = $arg1 . '-' . $arg2 . '_' . date('m-d-Y_hia') . '.xlsx"';

        if($library == 'phpexcel') {
            $spreadsheet = new PHPExcel();
            $writer = new PHPExcel_Writer_Excel2007($spreadsheet);
        } elseif($library == 'phpspreadsheet') {
            $spreadsheet = new Spreadsheet();
            $writer = new Xlsx($spreadsheet);
        }

        $sheet = $spreadsheet->getActiveSheet();
        $spreadsheet->getActiveSheet()
            ->fromArray(
                $arrayData,  // The data to set
                NULL,        // Array values with this value will not be set
                'A1'         // Top left coordinate of the worksheet range where
            );

        header('Content-Type: application/vnd.ms-excel');
        header('Content-Disposition: attachment; filename="' . $filename);
        $writer->save("php://output");
        if($arg1 == 'output' && $arg3 == 'new') {
            updateDownloaded($entities);
        }
    } else {
        drupal_set_message('There are no new adjustments of type ' . $arg2 . ' since last download for the pay period.', 'status', FALSE);
        drupal_goto('/prior-period-adjustments');
    }
}