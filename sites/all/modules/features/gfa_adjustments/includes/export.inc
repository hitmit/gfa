<?php

// Include PHPSpreadsheet with composer autoloader.
require drupal_get_path('module', 'gfa_adjustments') . '/vendor/autoload.php';
use PhpOffice\PhpSpreadsheet\Spreadsheet;
use PhpOffice\PhpSpreadsheet\Writer\Xlsx;

/**
 * Update boolean field_downloaded from 0 to 1.
 */
function updateDownloaded(array $entities) {
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
 */
function export_spreadsheet($arg1, $arg2, $arg3) {
    if(!isset($arg1) || empty($arg1)) {
        $arg1 = 'output';
    }
    if(!isset($arg2) || empty($arg2)) {
        $arg2 = 'ppa';
    }
    if(!isset($arg3) || empty($arg3)) {
        $arg = 'all';
    }

    $adj = new adjustments();
    $paPeriod = $adj->getPAPeriod($arg2);
    $paPeriodCode = reset($paPeriod);

    $efq = $adj->queryAdjustments($arg2, $arg3, $paPeriodCode);
    $entities = entity_load('field_collection_item', $efq);

    $arrayData = $adj->createAdjustmentOutput($entities, $arg1, $arg2, $paPeriod);

    $spreadsheet = new Spreadsheet();
    $sheet = $spreadsheet->getActiveSheet();
    if(!empty($arrayData[1])) {
        $spreadsheet->getActiveSheet()
            ->fromArray(
                $arrayData,  // The data to set
                NULL,        // Array values with this value will not be set
                'A1'         // Top left coordinate of the worksheet range where
        );

        $writer = new Xlsx($spreadsheet);
        header('Content-Type: application/vnd.ms-excel');
        $filename = $arg1 . '-' . $arg2;
        header('Content-Disposition: attachment; filename="' . $filename . '.xlsx"');
        $writer->save("php://output");

        updateDownloaded($entities);
    } else {
        drupal_set_message('There are no new adjustments of type ' . $arg2 . ' since last download for the pay period.', 'status', FALSE);
        drupal_goto('/prior-period-adjustments');
    }
}