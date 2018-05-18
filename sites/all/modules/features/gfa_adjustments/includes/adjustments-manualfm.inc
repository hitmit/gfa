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

        $tid = taxonomy_get_term_by_name($adjustmentType, $vocabulary = 'adjustment_form_types');
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
                $paPeriodCodes[] = $paPeriod->field_pa_period_code['und'][0]['value'];
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
            $efq->fieldCondition('field_downloaded', 'value', 0, '=');
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
        foreach($entities as $entity) {
            foreach($entity as $key => $field) {
                if(substr($key, 0, 5 ) === "field" && $key !== 'field_name' && $key !== 'field_fcuid' && $key !== 'field_downloaded') {
                    $field_instance = field_info_instance('field_collection_item', $key, 'field_cparn');
                    $elements[$key] = array(
                        'Label' => $field_instance['label'],
                        '#weight' => $field_instance['widget']['weight'],
                        'value' => $field['und'][0]['value']
                    );
                }
            }
        }
        uasort($elements, 'element_sort');

        switch ($adjustmentType) {

            case 'mnat':
                $arrayData = array();
                if($format == 'input') {
                    $arrayData[] = ['FMNO', 'Name', 'Debt', 'Emp GOC Off', 'Timesheet Period(s)', 'Project Code', 'Act Code', 'Project Name', 'Eng Off', 'Reg Hrs', 'O/T Hrs', 'Nts Awy', 'NTs9', 'Override PD', 'PD Cur', 'Tracking Number', 'Hours (to be reduced or added)', 'O/T Hours (to be reduced or added)', 'Charge Code (to be moved to)', 'New PD override', 'New PD Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $userName = isset($entity->field_user_name['und'][0]['value']) ? $entity->field_user_name['und'][0]['value'] : NULL;
                        $dept = isset($entity->field_dept['und'][0]['value']) ? $entity->field_dept['und'][0]['value'] : NULL;
                        $office = isset($entity->field_office['und'][0]['value']) ? $entity->field_office['und'][0]['value'] : NULL;
                        $projectCode = isset($entity->field_project_code['und'][0]['value']) ? $entity->field_project_code['und'][0]['value'] : NULL;
                        $actCode = isset($entity->field_act_code['und'][0]['value']) ? $entity->field_act_code['und'][0]['value'] : NULL;
                        $projectName = isset($entity->field_project_name['und'][0]['value']) ? $entity->field_project_name['und'][0]['value'] : NULL;
                        $engOff = isset($entity->field_eng_off['und'][0]['value']) ? $entity->field_eng_off['und'][0]['value'] : NULL;
                        $regularHours = isset($entity->field_regular_hours['und'][0]['value']) ? $entity->field_regular_hours['und'][0]['value'] : NULL;
                        $otHours = isset($entity->field_o_t_hours['und'][0]['value']) ? $entity->field_o_t_hours['und'][0]['value'] : NULL;
                        $ntsAwy = isset($entity->field_nts_awy['und'][0]['value']) ? $entity->field_nts_awy['und'][0]['value'] : NULL;
                        $nts9 = isset($entity->field_nts9['und'][0]['value']) ? $entity->field_nts9['und'][0]['value'] : NULL;
                        $override_pd = isset($entity->field_override_pd['und'][0]['value']) ? $entity->field_override_pd['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $trackingNum = isset($entity->field_tracking_number['und'][0]['value']) ? $entity->field_tracking_number['und'][0]['value'] : NULL;
                        $hoursReduceOrAdd = isset($entity->field_hours_reduce_or_add_['und'][0]['value']) ? $entity->field_hours_reduce_or_add_['und'][0]['value'] : NULL;
                        $otHoursReduceOrAdd = isset($entity->field_ot_hours_reduce_or_add_['und'][0]['value']) ? $entity->field_ot_hours_reduce_or_add_['und'][0]['value'] : NULL;
                        $ccToBeMoved = isset($entity->field_cc_to_be_moved['und'][0]['value']) ? $entity->field_cc_to_be_moved['und'][0]['value'] : NULL;
                        $newPDOverride = isset($entity->field_new_pd_override['und'][0]['value']) ? (float)$entity->field_new_pd_override['und'][0]['value'] : NULL;
                        $newPDCurrency = isset($entity->field_new_pd_currency['und'][0]['value']) ? $entity->field_new_pd_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$FMNO, $userName, $dept, $office, $paPeriodCode, $projectCode, $actCode, $projectName, $engOff, $regularHours, $otHours, $ntsAwy, $nts9, $override_pd, $currency, $trackingNum, $hoursReduceOrAdd, $otHoursReduceOrAdd, $ccToBeMoved, $newPDOverride, $newPDCurrency];
                    }
                } elseif($format == 'output') {
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
                }

                return $arrayData;

                break;

            case 'cparn':
                $elements = array();
                $arrayData = array();
                if($format == 'input') {
                    $arrayData[] = ['FMNO', 'First Name', 'Last Name', 'Position Code', 'PCAT', 'Labor Status', 'Employment Status', 'Complex', 'Sub Complex', 'User Location Code', 'User GOC Code', 'TS Start Date', 'Source Action', 'Charge Code', 'Charge Code GOC Office', 'Project Name', 'Activity Code', 'Billing Sub Type', 'Hours', 'Overtime', 'Per Diem Local Currency', 'Effective Perdiem', 'Perdiem USD', 'Currency Code', 'Source System', 'Created_by', 'Created_date', 'RADAR Reporting Period', 'ORS_Create_tstamp', 'Alternative Code', 'Hours to be moved', 'OT hours', 'POC (Local office)'];
                    foreach($entities as $key => $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $firstName = isset($entity->field_first_name['und'][0]['value']) ? $entity->field_first_name['und'][0]['value'] : NULL;
                        $lastName = isset($entity->field_last_name['und'][0]['value']) ? $entity->field_last_name['und'][0]['value'] : NULL;
                        $positionCode = isset($entity->field_position_code['und'][0]['value']) ? $entity->field_position_code['und'][0]['value'] : NULL;
                        $PCAT = isset($entity->field_pcat['und'][0]['value']) ? $entity->field_pcat['und'][0]['value'] : NULL;
                        $laborStatus = isset($entity->field_labor_status['und'][0]['value']) ? $entity->field_labor_status['und'][0]['value'] : NULL;
                        $employmentStatus = isset($entity->field_employment_status['und'][0]['value']) ? $entity->field_employment_status['und'][0]['value'] : NULL;
                        $complex = isset($entity->field_complex['und'][0]['value']) ? $entity->field_complex['und'][0]['value'] : NULL;
                        $subComplex = isset($entity->field_sub_complex['und'][0]['value']) ? $entity->field_sub_complex['und'][0]['value'] : NULL;
                        $userLocationCode = isset($entity->field_complex['und'][0]['value']) ? $entity->field_complex['und'][0]['value'] : NULL;
                        $subComplex = isset($entity->field_sub_complex['und'][0]['value']) ? $entity->field_sub_complex['und'][0]['value'] : NULL;
                        $userLocationCode = isset($entity->field_user_location_code['und'][0]['value']) ? $entity->field_user_location_code['und'][0]['value'] : NULL;
                        $userGOCCode = isset($entity->field_user_goc_code['und'][0]['value']) ? $entity->field_user_goc_code['und'][0]['value'] : NULL;
                        $sourceAction = isset($entity->field_source_action['und'][0]['value']) ? $entity->field_source_action['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $chargeGOC = isset($entity->field_charge_code_goc_office['und'][0]['value']) ? $entity->field_charge_code_goc_office['und'][0]['value'] : NULL;
                        $projectName = isset($entity->field_project_name['und'][0]['value']) ? $entity->field_project_name['und'][0]['value'] : NULL;
                        $activityCode = isset($entity->field_activity_code['und'][0]['value']) ? $entity->field_activity_code['und'][0]['value'] : NULL;
                        $billingSubType = isset($entity->field_billing_sub_type['und'][0]['value']) ? $entity->field_billing_sub_type['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiemLocalCurrency = isset($entity->field_per_diem_local_currency['und'][0]['value']) ? $entity->field_per_diem_local_currency['und'][0]['value'] : NULL;
                        $effectivePerdiem = $entity->field_effective_perdiem['und'][0]['value'] ? $entity->field_effective_perdiem['und'][0]['value'] : NULL;
                        $perdiemUSD = isset($entity->field_perdiem_usd['und'][0]['value']) ? $entity->field_perdiem_usd['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $sourceSystem = isset($entity->field_source_system['und'][0]['value']) ? $entity->field_source_system['und'][0]['value'] : NULL;
                        $createdBy = isset($entity->field_created_by['und'][0]['value']) ? $entity->field_created_by['und'][0]['value'] : NULL;
                        $createdDate = isset($entity->field_created_date['und'][0]['value']) ? $entity->field_created_date['und'][0]['value'] : NULL;
                        $radarReporting = isset($entity->field_radar_reporting_period['und'][0]['value']) ? $entity->field_radar_reporting_period['und'][0]['value'] : NULL;
                        $orsCreateTStamp = isset($entity->field_ors_create_tstamp['und'][0]['value']) ? $entity->field_ors_create_tstamp['und'][0]['value'] : NULL;
                        $alternativeCode = isset($entity->field_alternative_code['und'][0]['value']) ? $entity->field_alternative_code['und'][0]['value'] : NULL;
                        $hoursToBeMoved = isset($entity->field_hours_to_be_moved['und'][0]['value']) ? $entity->field_hours_to_be_moved['und'][0]['value'] : NULL;
                        $otHours = isset($entity->field_o_t_hours['und'][0]['value']) ? $entity->field_o_t_hours['und'][0]['value'] : NULL;
                        $poc = isset($entity->field_poc['und'][0]['value']) ? $entity->field_poc['und'][0]['value'] : NULL;
                        $arrayData[] = [$FMNO, $firstName, $lastName, $positionCode, $PCAT, $laborStatus, $employmentStatus, $complex, $subComplex, $userLocationCode, $userGOCCode, $paPeriodCode, $sourceAction, $charge, $chargeGOC, $projectName, $activityCode, $billingSubType, $hours, $overtime, $perdiemLocalCurrency, $effectivePerdiem, $perdiemUSD, $currency, $sourceSystem, $createdBy, $createdDate, $radarReporting, $orsCreateTStamp, $alternativeCode, $hoursToBeMoved, $otHours, $poc];
                    }
                } elseif($format == 'output') {
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
                }

                return $arrayData;

                break;

            case 'cparf':
                $arrayData = array();
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
                    $arrayData[] = [$paPeriodRange, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                }

                return $arrayData;

                break;

            case 'cpag':
                $arrayData = array();
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

                break;

            case 'ppa':
                $arrayData = array();
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

                break;

            case 'pppece':
                $arrayData = array();
                if($format == 'input') {
                    $arrayData[] = ['PA Period', 'FMNO', 'PE Charge Code', 'CE Charge Code', 'Hours', 'Overtime', 'Override Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $ceCharge = isset($entity->field_ce_charge_code['und'][0]['value']) ? $entity->field_ce_charge_code['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodCode, $FMNO, $charge, $ceCharge, $hours, $overtime, $perdiem, $currency];
                    }
                } elseif($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $ceCharge = isset($entity->field_ce_charge_code['und'][0]['value']) ? $entity->field_ce_charge_code['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? (float)$entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? (float)$entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $charge, isset($hours) ? $hours * -1 : NULL, isset($overtime) ? $overtime * -1 : NULL, $perdiem, $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, $ceCharge, $hours, $overtime, $perdiem, $currency];
                    }
                }

                return $arrayData;

                break;

            case 'shbp':
                $arrayData = array();
                if($format == 'input') {
                    $arrayData[] = ['Project Office Code', 'Project Number', 'FMNO', 'Name', 'FMNO GOC Office', 'FMNO Dept', 'FMNO Dept Name', 'PCAT Name', 'PCAT', 'Hours', 'Days', 'Transaction Amount LC', 'WIP Per Diem', 'Table B Per Diem', 'Nominal Per Diem', 'Staffing Office', 'Entry Office', 'Gl Date', 'Timesheet Period', 'Fees At Risk', 'Fees At Risk Recovery', 'NRR by Timesheet Period', 'Timesheet Month', 'Firm member Staffed to Project', 'Firm member on CER billing worksheet', 'Enter the New Per diem amount', 'Currency'];
                    foreach($entities as $key => $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $projectOfficeCode = isset($entity->field_project_office_code['und'][0]['value']) ? $entity->field_project_office_code['und'][0]['value'] : NULL;
                        $projectNumber = isset($entity->field_project_number['und'][0]['value']) ? $entity->field_project_number['und'][0]['value'] : NULL;
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $fmnoGOCOffice = isset($entity->field_fmno_goc_office['und'][0]['value']) ? $entity->field_fmno_goc_office['und'][0]['value'] : NULL;
                        $name = isset($entity->field_user_name['und'][0]['value']) ? $entity->field_user_name['und'][0]['value'] : NULL;
                        $fmnoDept = isset($entity->field_fmno_dept['und'][0]['value']) ? $entity->field_fmno_dept['und'][0]['value'] : NULL;
                        $fmnoDeptName = isset($entity->field_fmno_dept_name['und'][0]['value']) ? $entity->field_fmno_dept_name['und'][0]['value'] : NULL;
                        $pcatName = isset($entity->field_pcat_name['und'][0]['value']) ? $entity->field_pcat_name['und'][0]['value'] : NULL;
                        $pcat = isset($entity->field_pcat['und'][0]['value']) ? $entity->field_pcat['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $days = isset($entity->field_days['und'][0]['value']) ? $entity->field_days['und'][0]['value'] : NULL;
                        $transactionAmountLC = isset($entity->field_transaction_amount_lc['und'][0]['value']) ? $entity->field_transaction_amount_lc['und'][0]['value'] : NULL;
                        $wipPerDiem = isset($entity->field_wip_per_diem['und'][0]['value']) ? $entity->field_wip_per_diem['und'][0]['value'] : NULL;
                        $nominalPerDiem = isset($entity->field_nominal_per_diem['und'][0]['value']) ? $entity->field_nominal_per_diem['und'][0]['value'] : NULL;
                        $staffingOffice = isset($entity->field_staffing_office['und'][0]['value']) ? $entity->field_staffing_office['und'][0]['value'] : NULL;
                        $entryOffice = isset($entity->field_entry_office['und'][0]['value']) ? $entity->field_entry_office['und'][0]['value'] : NULL;
                        $glDate = isset($entity->field_gl_date['und'][0]['value']) ? $entity->field_gl_date['und'][0]['value'] : NULL;
                        $feesAtRisk = isset($entity->field_fees_at_risk['und'][0]['value']) ? $entity->field_fees_at_risk['und'][0]['value'] : NULL;
                        $feesAtRiskRecovery = isset($entity->field_fees_at_risk_recovery['und'][0]['value']) ? $entity->field_fees_at_risk_recovery['und'][0]['value'] : NULL;
                        $nrrByTimesheetPeriod = isset($entity->field_nrr_by_timesheet_period['und'][0]['value']) ? $entity->field_nrr_by_timesheet_period['und'][0]['value'] : NULL;
                        $timesheetMonth = isset($entity->field_timesheet_month['und'][0]['value']) ? $entity->field_timesheet_month['und'][0]['value'] : NULL;
                        $tableBPerDiem = isset($entity->field_table_b_per_diem['und'][0]['value']) ? $entity->field_table_b_per_diem['und'][0]['value'] : NULL;
                        $FMSTP = isset($entity->field_firm_member_staffed_to_pro['und'][0]['value']) ? $entity->field_firm_member_staffed_to_pro['und'][0]['value'] : NULL;
                        $FMOCBW = isset($entity->field_firm_member_on_cer_billing['und'][0]['value']) ? $entity->field_firm_member_on_cer_billing['und'][0]['value'] : NULL;
                        $NPDA = isset($entity->field_new_per_diem_amount['und'][0]['value']) ? $entity->field_new_per_diem_amount['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$projectOfficeCode, $projectNumber, $FMNO, $name, $fmnoGOCOffice, $fmnoDept, $fmnoDeptName, $pcatName, $pcat, $hours, $days, $transactionAmountLC, $wipPerDiem, $tableBPerDiem, $nominalPerDiem, $staffingOffice, $entryOffice, $glDate, $paPeriodCode, $feesAtRisk, $feesAtRiskRecovery, $nrrByTimesheetPeriod, $timesheetMonth, $FMSTP, $FMOCBW, $NPDA, $currency];
                    }
                } elseif($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $paPeriodCode = isset($entity->field_pa_period_code['und'][0]['value']) ? ($entity->field_pa_period_code['und'][0]['value']) : NULL;
                        $paPeriodRange = $this->getPAPeriodRange($adjustmentType, $paPeriodCode);
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $projectNumber = isset($entity->field_project_number['und'][0]['value']) ? $entity->field_project_number['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? (float)$entity->field_hours['und'][0]['value'] : NULL;
                        $wipPerDiem = isset($entity->field_wip_per_diem['und'][0]['value']) ? $entity->field_wip_per_diem['und'][0]['value'] : NULL;
                        $NPDA = isset($entity->field_new_per_diem_amount['und'][0]['value']) ? $entity->field_new_per_diem_amount['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $projectNumber, isset($hours) ? $hours * -1 : NULL, ' ', round($wipPerDiem), $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, $projectNumber, $hours, ' ', round($NPDA), $currency]; 
                    }
                }

                return $arrayData;

                break;
        }
    }
}