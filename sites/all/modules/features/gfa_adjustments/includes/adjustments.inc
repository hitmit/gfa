<?php

class Adjustments {
    /**
     * Global adjustment type options list.
     */
    function getAdjTypeOptions() {
        $options = array(
            'mnat' => 'CPA - MB2 TV',
            'cparn' => 'CPA - RADAR Net Accrual TV',
            'cparf' => 'CPA - RADAR Format GFA',
            'cpag' => 'Current Period Accruals - GFA',
            'ppa' => 'Prior Period Adjustments',
            'pppece' => 'Prior Period PE to CE',
            'shbp' => 'SHB Perdiem'
        );

        return $options;
    }

    /**
     * Query database for current or previous pay periods.
     * Return a list of pay period codes.
     */
    function getPAPeriod($adjustmentType) {
        $priorPeriods = array('ppa', 'pppece');
        
        $now = new DateTime();

        $date = $now->format('Y-m-d H:i:s');

        if($adjustmentType == 'cparf') {
            $tid = taxonomy_get_term_by_name('ppa', $vocabulary = 'adjustment_form_types');
        } else  {
            $tid = taxonomy_get_term_by_name($adjustmentType, $vocabulary = 'adjustment_form_types');
        }
        $tid = reset($tid)->tid;

        $pp = new EntityFieldQuery();

        $pp->entityCondition('entity_type', 'field_collection_item')
            // No bundle value, use field name.
            ->propertyCondition('field_name', 'field_pa_periods')
            // We don't want revisions!
            ->propertyCondition('archived', 0)
            ->fieldCondition('field_adjustment_form_type', 'tid', $tid)
            ->fieldOrderBy('field_pa_date_range', 'value', 'DESC');

        if(in_array($adjustmentType, $priorPeriods)) {
            $pp->fieldCondition('field_pa_date_range', 'value2', $date, '<', 0);
        } else  {
            $pp->fieldCondition('field_pa_date_range', 'value', $date, '<=', 0)
            ->fieldCondition('field_pa_date_range', 'value2', $date, '>=', 0);
        }

        $results = $pp->execute();

        if(isset($results['field_collection_item'])) {
            $entities = array_keys($results['field_collection_item']);
            $paPeriods = entity_load('field_collection_item', $entities);
            $paPeriodCodes = array();
            foreach($paPeriods as $paPeriod) {
                if($adjustmentType == 'cparf') {
                    $date = isset($paPeriod->field_pa_date_range['und'][0]['value']) ? $paPeriod->field_pa_date_range['und'][0]['value'] : NULL;
                    $paStart = DateTime::createFromFormat('Y-m-d H:i:s', $date);
                    $paStartFmt = date_format($paStart, 'M d, Y');
                    $date = isset($paPeriod->field_pa_date_range['und'][0]['value2']) ? $paPeriod->field_pa_date_range['und'][0]['value2'] : NULL;
                    $paEnd = DateTime::createFromFormat('Y-m-d H:i:s', $date);
                    $paEndFmt = date_format($paEnd, 'M d, Y');
                    $paPeriodRange = $paStartFmt . ' - ' . $paEndFmt;
                    $paPeriodCodes[] = $paPeriodRange;
                } else {
                    $paPeriodCodes[] = $paPeriod->field_pa_period_code['und'][0]['value'];
                }
            }
            return  $paPeriodCodes;
        }
    }

    /**
     * Query database for pay period matching the provided pay period code.
     * Return matching date range.
     */
    function getPAPeriodRange($adjustmentType, $paPeriodCode) {
        $tid = taxonomy_get_term_by_name($adjustmentType, $vocabulary = 'adjustment_form_types');
        $tid = reset($tid)->tid;

        $pp = new EntityFieldQuery();

        $pp->entityCondition('entity_type', 'field_collection_item')
            // No bundle value, use field name.
            ->propertyCondition('field_name', 'field_pa_periods')
            // We don't want revisions!
            ->propertyCondition('archived', 0)
            ->fieldCondition('field_adjustment_form_type', 'tid', $tid)
            ->fieldCondition('field_pa_period_code', 'value', $paPeriodCode, '=')
            ->fieldOrderBy('field_pa_date_range', 'value', 'DESC');

        $results = $pp->execute();

        if(isset($results['field_collection_item'])) {
            $entities = array_keys($results['field_collection_item']);
            $paPeriods = entity_load('field_collection_item', $entities);
            foreach($paPeriods as $paPeriod) {
                $date = isset($paPeriod->field_pa_date_range['und'][0]['value']) ? $paPeriod->field_pa_date_range['und'][0]['value'] : NULL;
                $paStart = DateTime::createFromFormat('Y-m-d H:i:s', $date);
                $paStartFmt = date_format($paStart, 'M d, Y');
                $date = isset($paPeriod->field_pa_date_range['und'][0]['value2']) ? $paPeriod->field_pa_date_range['und'][0]['value2'] : NULL;
                $paEnd = DateTime::createFromFormat('Y-m-d H:i:s', $date);
                $paEndFmt = date_format($paEnd, 'M d, Y');
                $paPeriodRange = $paStartFmt . ' - ' . $paEndFmt;
                return $paPeriodRange;
            }
        }
    }

    /**
     * Query database for adjustments.
     */
    function queryAdjustments($fieldName, $range, $paPeriodCodes) {
        $efq = new EntityFieldQuery();

        $efq->entityCondition('entity_type', 'field_collection_item')
            // No bundle value, use field name.
            ->propertyCondition('field_name', 'field_' . $fieldName)
            // We don't want revisions!
            ->propertyCondition('archived', 0)
            ->fieldCondition('field_pa_period_code', 'value', $paPeriodCodes, 'IN')
            ->fieldOrderBy('field_pa_period_code', 'value', 'ASC');

        if($range == 'new') {
            $efq->fieldCondition('field_downloaded', 'value', '0', '=');
        }

        $results = $efq->execute();

        $entityIDs = array();

        if(isset($results['field_collection_item'])) {
            $entityIDs = array_keys($results['field_collection_item']);
        }

        return $entityIDs;
    }

    /**
     * Create Adjustment Template from field_collection_item entities.
     */
    function createAdjustmentOutput($entities, $format, $adjustmentType) {
        $arrayData = array();
        if($format == 'input') {
            $tableHeaders = array();
            $tableRows = array();
            $first = true;
            foreach($entities as $key1 => $entity) {
                foreach($entity as $key2 => $field) {
                    if(substr($key2, 0, 5 ) === "field" && $key2 !== 'field_name' && $key2 !== 'field_fcuid' && $key2 !== 'field_downloaded') {
                        $field_instance = field_info_instance('field_collection_item', $key2, 'field_' . $adjustmentType);
                        $elements[$key1][$key2] = array(
                            'label' => $field_instance['label'],
                            'value' => isset($field['und'][0]['value']) ? $field['und'][0]['value'] : '',
                            '#weight' => $field_instance['widget']['weight']
                        );
                    }
                }
                uasort($elements[$key1], 'element_sort');
            }
            foreach($elements as $element) {
                foreach($element as $key => $field) {
                    if($first == true) {
                        $tableHeaders[] = $field['label'];
                    }
                    $tableRows[] = $field['value'];
                }
                if($first == true) {
                    $arrayData[] = $tableHeaders;
                }
                $arrayData[] = $tableRows;
                //Empty $tableRows for the start of the next element
                $tableRows = array();
                $first = false;
            }

            return $arrayData;
        }

        switch ($adjustmentType) {

            case 'mnat':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $projectCode = isset($entity->field_project_code['und'][0]['value']) ? $entity->field_project_code['und'][0]['value'] : NULL;
                        $hoursReduceOrAdd = isset($entity->field_hours_reduce_or_add_['und'][0]['value']) ? (float)$entity->field_hours_reduce_or_add_['und'][0]['value'] : NULL;
                        $otHoursReduceOrAdd = isset($entity->field_ot_hours_reduce_or_add_['und'][0]['value']) ? (float)$entity->field_ot_hours_reduce_or_add_['und'][0]['value'] : NULL;
                        $overridePD = isset($entity->field_override_pd['und'][0]['value']) ? (float)$entity->field_override_pd['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $ccToBeMoved = isset($entity->field_cc_to_be_moved['und'][0]['value']) ? $entity->field_cc_to_be_moved['und'][0]['value'] : NULL;
                        $newPDOverride = isset($entity->field_new_pd_override['und'][0]['value']) ? $entity->field_new_pd_override['und'][0]['value'] : NULL;
                        $newPDCurrency = isset($entity->field_new_pd_currency['und'][0]['value']) ? $entity->field_new_pd_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $projectCode, isset($hoursReduceOrAdd) ? $hoursReduceOrAdd * -1 : NULL, isset($otHoursReduceOrAdd) ? $otHoursReduceOrAdd * -1 : NULL, $overridePD, $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, isset($ccToBeMoved) ? $ccToBeMoved : $projectCode, isset($hoursReduceOrAdd) ? $hoursReduceOrAdd : NULL, $otHoursReduceOrAdd, $newPDOverride, $newPDCurrency];
                    }

                    return $arrayData;
                }

                break;

            case 'cparn':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $paEnd = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hoursToBeMoved = isset($entity->field_hours_to_be_moved['und'][0]['value']) ? (float)$entity->field_hours_to_be_moved['und'][0]['value'] : NULL;
                        $alternativeCode = isset($entity->field_alternative_code['und'][0]['value']) ? $entity->field_alternative_code['und'][0]['value'] : NULL;
                        $otHours = isset($entity->field_o_t_hours['und'][0]['value']) ? (float)$entity->field_o_t_hours['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $charge, isset($hoursToBeMoved) ? $hoursToBeMoved * -1 : NULL, isset($otHours) ? $otHours * -1 : NULL];
                        $arrayData[] = [$paPeriodRange, $FMNO, $alternativeCode, isset($hoursToBeMoved) ? $hoursToBeMoved : NULL, isset($otHours) ? $otHours : NULL];
                    }

                    return $arrayData;
                }

                break;

            case 'cparf':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? (float)$entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? (float)$entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodCode, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                    }

                    return $arrayData;
                }

                break;

            case 'cpag':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? (float)$entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? (float)$entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$format == 'input' ? $paPeriodCode : $paPeriodRange, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                    }

                    return $arrayData;
                }

                break;

            case 'ppa':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? (float)$entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? (float)$entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$format == 'input' ? $paPeriodCode : $paPeriodRange, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                    }

                    return $arrayData;
                }

                break;

            case 'pppece':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $ceCharge = isset($entity->field_ce_charge_code['und'][0]['value']) ? $entity->field_ce_charge_code['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? (float)$entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_override_pd['und'][0]['value']) ? (float)$entity->field_override_pd['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $charge, isset($hours) ? $hours * -1 : NULL, isset($overtime) ? $overtime * -1 : NULL, $perdiem, $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, $ceCharge, $hours, $overtime, $perdiem, $currency];
                    }

                    return $arrayData;
                }

                break;

            case 'shbp':
                if($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $projectNumber = isset($entity->field_project_number['und'][0]['value']) ? $entity->field_project_number['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $wipPerDiem = isset($entity->field_wip_per_diem['und'][0]['value']) ? number_format(round(floatval(str_replace(",","",$entity->field_wip_per_diem['und'][0]['value'])))) : NULL;
                        $NPDA = isset($entity->field_enter_the_new_per_diem_amo['und'][0]['value']) ? number_format(round(floatval(str_replace(",","",$entity->field_enter_the_new_per_diem_amo['und'][0]['value'])))) : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $projectNumber, isset($hours) ? $hours * -1 : NULL, $wipPerDiem, $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, $projectNumber, $hours, $NPDA, $currency]; 
                    }

                    return $arrayData;
                }

                break;
        }
    }
}