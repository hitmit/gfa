<?php

function adjustments_list_page($arg1, $arg2, $arg3) {
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

    if(!empty($arrayData[1])) {
        $tableHeader = $arrayData[0];
        $tableRows = array();
        foreach($arrayData as $key => $value) {
            if($key !== 0) {
                $tableRows[] = $value;
            };
        };

        $table = array(
            '#theme' => 'table',
            '#header' => $tableHeader,
            '#rows' => $tableRows,
            '#caption' => $arg1 . ' ' . $arg2 . ' ' . $arg3
        );

        $link = array(
            '#type' => 'markup',
            '#markup' => '<a href="' . base_path() . 'export-spreadsheet/' . $arg1 . '/' . $arg2 . '">Export</a>'
        );

        $page = array(
          'table' => $table,
          'link' => $link
        );

        return $page;
    } else {
       drupal_set_message('There are no new adjustments of type ' . $arg2 . ' since last download for the pay period.', 'status', FALSE);
       return '<p>There are no new adjustments of type ' . $arg2 . ' since last download for the pay period.</p>';
    }
}