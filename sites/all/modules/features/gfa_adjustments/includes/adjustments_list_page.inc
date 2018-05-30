<?php

/**
 * Return adjtype adjustment form select list.
 */
function adjtype_select_form($form, &$form_state, $arg1, $arg2, $arg3) {
    $form = array();

    $options = array(
        'input' => 'Input',
        'output' => 'Output'
    );
    $form['adjformat'] = array(
        '#attributes' => array('id' => array('arg1')),
        '#type' => 'select',
        '#title' => t('Adjustment format'),
        '#description' => t('Choose the export format.'),
        '#default_value' => $arg1,
        '#options' => $options
    );
    $adj = new adjustments();
    $options = $adj->getAdjTypeOptions();
    $form['adjtype'] = array(
        '#attributes' => array('id' => array('arg2')),
        '#type' => 'select',
        '#title' => t('Adjustment type'),
        '#description' => t('Choose the export form type.'),
        '#default_value' => $arg2,
        '#options' => $options
    );
    $options = array(
        'all' => 'All',
        'new' => 'New'
    );
    $form['adjrange'] = array(
        '#attributes' => array('id' => array('arg3')),
        '#type' => 'select',
        '#title' => t('Adjustment Range'),
        '#description' => t('Choose the data range.'),
        '#default_value' => $arg3,
        '#options' => $options
    );
    $form['submit']     = array(
        '#type' => 'submit',
        '#value' => t('Apply')
    );
    return $form;
}

/**
 * Adjtype select form submit function.
 */
function adjtype_select_form_submit($form, &$form_state) {
    $adjformat = $form_state['values']['adjformat'];
    $adjtype = $form_state['values']['adjtype'];
    $adjrange = $form_state['values']['adjrange'];
    $args = $form_state['build_info']['args'];
    drupal_goto('/adjustments/' . $adjformat . '/' . $adjtype . '/' . $adjrange);
}

function adjustments_list_page($arg1 = FALSE, $arg2 = FALSE, $arg3 = FALSE) {
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
    $paPeriodCodes = $adj->getPAPeriod($arg2);

    if(!empty($paPeriodCodes)) {

        $efq = $adj->queryAdjustments($arg2, $arg3, $paPeriodCodes);
        $entities = entity_load('field_collection_item', $efq);

        $arrayData = $adj->createAdjustmentOutput($entities, $arg1, $arg2);

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
                '#markup' => '<a href="' . base_path() . 'export-spreadsheet/' . $arg1 . '/' . $arg2 . '/' . $arg3 .'">Export</a>'
            );

            $page = array(
                'adjtype_select_form' => drupal_get_form('adjtype_select_form', $arg1, $arg2, $arg3),
                'table' => $table,
                'link' => $link
            );

            return $page;
        } else {
        	$messageText = '';
        	if ($arg3 == 'new') {
        	    $messageText = '<p>There are no new adjustments of type ' . $arg2 . ' since last download for the pay period.</p>';
        	} else  {
        		$messageText = '<p>There are no adjustments of type ' . $arg2 . ' for this pay period.</p>';
        	}
            $message = array(
                '#type' => 'markup',
                '#markup' => $messageText
            );

            $page = array(
                'adjtype_select_form' => drupal_get_form('adjtype_select_form', $arg1, $arg2, $arg3),
                'message' => $message
            );
        }
    } else  {
            $message = array(
                '#type' => 'markup',
                '#markup' => '<p>No pay period(s) found matching the requested dates. Please update the list of pay periods.</p>'
            );

            $page = array(
                'adjtype_select_form' => drupal_get_form('adjtype_select_form', $arg1, $arg2, $arg3),
                'message' => $message
            );
    }

        return $page;
}