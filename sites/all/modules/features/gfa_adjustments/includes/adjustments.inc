<?php

class Adjustments {

    /**
     * Query database for current or previous pay period.
     */
    function getPAPeriod($adjustmentType) {
        $priorPeriods = array('ppa', 'pppece');
        $now = new DateTime();

        $date = $now->format('Y-m-d H:i:s');
        $date2 = $now->modify('-1 month');
        $date2 = $now->format('Y-m-d H:i:s');

        $tid = taxonomy_get_term_by_name($adjustmentType, $vocabulary = 'adjustment_form_types');
        $tid = reset($tid)->tid;

        $pp = new EntityFieldQuery();

        $pp->entityCondition('entity_type', 'field_collection_item')
            // No bundle value, use field name.
            ->propertyCondition('field_name', 'field_pa_periods')
            // We don't want revisions!
            ->propertyCondition('archived', 0)
            ->fieldCondition('field_adjustment_form_type', 'tid', $tid)
            ->fieldCondition('field_pa_date_range', 'value', $date, '<=', 0)
            ->fieldCondition('field_pa_date_range', 'value2', $date2, '>=', 0)
            ->fieldOrderBy('field_pa_date_range', 'value', 'DESC');

        $results = $pp->execute();

        if(isset($results['field_collection_item'])) {
            $entities = array_keys($results['field_collection_item']);
            if(in_array($adjustmentType, $priorPeriods)) {
                $entities = array($entities[1]);
            } else {
                $entities = array($entities[0]);
            }
            $paPeriods = entity_load('field_collection_item', $entities);
            foreach($paPeriods as $paPeriod) {
                $date = isset($paPeriod->field_pa_date_range['und'][0]['value']) ? $paPeriod->field_pa_date_range['und'][0]['value'] : NULL;
                $paStart = DateTime::createFromFormat('Y-m-d H:i:s', $date);
                $paStartFmt = date_format($paStart, 'M d, Y');
                $date = isset($paPeriod->field_pa_date_range['und'][0]['value2']) ? $paPeriod->field_pa_date_range['und'][0]['value2'] : NULL;
                $paEnd = DateTime::createFromFormat('Y-m-d H:i:s', $date);
                $paEndFmt = date_format($paEnd, 'M d, Y');
                $paPeriodCode = $paPeriod->field_pa_period_code['und'][0]['value'];
                $paRange = $paStartFmt . ' - ' . $paEndFmt;
                $paPeriod = array($paPeriodCode, $paRange);
                return $paPeriod;
            }
        }
    }

    /**
     * Query database for adjustments.
     */
    function queryAdjustments($fieldName, $range, $paPeriodCode) {
        $efq = new EntityFieldQuery();

        $efq->entityCondition('entity_type', 'field_collection_item')
            // No bundle value, use field name.
            ->propertyCondition('field_name', 'field_' . $fieldName)
            // We don't want revisions!
            ->propertyCondition('archived', 0)
            ->fieldCondition('field_pa_period_code', 'value', $paPeriodCode, '=');

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
     * Create Adjustment Template from field_collection_item entity.
     */
    function createAdjustmentOutput($entities, $format, $adjustmentType, $paPeriod) {
        switch ($adjustmentType) {
            case 'ppa':
                $arrayData = array();
                $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;
                $paPeriodRange = isset($paPeriod) ? end($paPeriod) : NULL;
                $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                foreach($entities as $entity) {
                    $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                    $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                    $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                    $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                    $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                    $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                    $arrayData[] = [$format == 'input' ? $paPeriodCode : $paPeriodRange, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                }

                return $arrayData;

                break;

            case 'cparn':
                $arrayData = array();
                $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;
                $paPeriodRange = isset($paPeriod) ? end($paPeriod) : NULL;
                if($format == 'input') {
                    $arrayData[] = ['FMNO', 'First Name', 'Last Name', 'Position Code', 'PCAT', 'Labor Status', 'Employment Status', 'Complex', 'Sub Complex', 'User Location Code', 'User GOC Code', 'TS Start Date', 'Source Action', 'Charge Code', 'Charge Code GOC Office', 'Project Name', 'Activity Code', 'Billing Sub Type', 'Hours', 'Overtime', 'Perdiem Local Currency', 'Effective Perdiem', 'Perdiem USD', 'Currency Code', 'Source System', 'Created By', 'Created Date', 'RADAR Reporting Period', 'ORS Create tstamp', 'Alternative Code', 'Hours to be moved', 'OT hours', 'POC (Local office)'];
                    foreach($entities as $key => $entity) {
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
                        $tsStartDate = isset($entity->field_ts_start_date['und'][0]['value']) ? $entity->field_ts_start_date['und'][0]['value'] : NULL;
                        $sourceAction = isset($entity->field_source_action['und'][0]['value']) ? $entity->field_source_action['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $chargeGOC = isset($entity->field_charge_code_goc_office['und'][0]['value']) ? $entity->field_charge_code_goc_office['und'][0]['value'] : NULL;
                        $projectName = isset($entity->field_project_name['und'][0]['value']) ? $entity->field_project_name['und'][0]['value'] : NULL;
                        $activityCode = isset($entity->field_activity_code['und'][0]['value']) ? $entity->field_activity_code['und'][0]['value'] : NULL;
                        $billingSubType = isset($entity->field_billing_sub_type['und'][0]['value']) ? $entity->field_billing_sub_type['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiemLocalCurrency = isset($entity->field_perdiem_local_currency['und'][0]['value']) ? $entity->field_perdiem_local_currency['und'][0]['value'] : NULL;
                        $effectivePerdiem = $entity->field_effective_perdiem['und'][0]['value'] ? $entity->field_effective_perdiem['und'][0]['value'] : NULL;
                        $perdiemUSD = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $sourceSystem = isset($entity->field_source_system['und'][0]['value']) ? $entity->field_source_system['und'][0]['value'] : NULL;
                        $createdBy = isset($entity->field_created_by['und'][0]['value']) ? $entity->field_created_by['und'][0]['value'] : NULL;
                        $createdDate = isset($entity->field_created_date['und'][0]['value']) ? $entity->field_created_date['und'][0]['value'] : NULL;
                        $orsCreateTStamp = isset($entity->field_ors_create_tstamp['und'][0]['value']) ? $entity->field_ors_create_tstamp['und'][0]['value'] : NULL;
                        $alternativeCode = isset($entity->field_alternative_code['und'][0]['value']) ? $entity->field_alternative_code['und'][0]['value'] : NULL;
                        $hoursToBeMoved = isset($entity->field_hours_to_be_moved['und'][0]['value']) ? $entity->field_hours_to_be_moved['und'][0]['value'] : NULL;
                        $otHours = isset($entity->field_o_t_hours['und'][0]['value']) ? $entity->field_o_t_hours['und'][0]['value'] : NULL;
                        $poc = isset($entity->field_poc['und'][0]['value']) ? $entity->field_poc['und'][0]['value'] : NULL;
                        $arrayData[] = [$FMNO, $firstName, $lastName, $positionCode, $PCAT, $laborStatus, $employmentStatus, $complex, $subComplex, $userLocationCode, $userGOCCode, $tsStartDate, $sourceAction, $charge, $chargeGOC, $projectName, $activityCode, $billingSubType, $hours, $overtime, $perdiemLocalCurrency, $effectivePerdiem, $perdiemUSD, $currency, $sourceSystem, $createdBy, $createdDate, $paPeriodCode, $orsCreateTStamp, $alternativeCode, $hoursToBeMoved, $otHours, $poc];
                    }
                } elseif($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours'];
                    foreach($entities as $entity) {
                        $paEnd = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hoursToBeMoved = isset($entity->field_hours_to_be_moved['und'][0]['value']) ? $entity->field_hours_to_be_moved['und'][0]['value'] : NULL;
                        $alternativeCode = isset($entity->field_alternative_code['und'][0]['value']) ? $entity->field_alternative_code['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $charge, isset($hoursToBeMoved) ? $hoursToBeMoved * -1 : NULL];
                        $arrayData[] = [$paPeriodRange, $FMNO, $alternativeCode, $hoursToBeMoved];
                    }
                }

                return $arrayData;

                break;

            case 'cparf':
                $arrayData = array();
                $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;
                $paPeriodRange = isset($paPeriod) ? end($paPeriod) : NULL;
                $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                foreach($entities as $entity) {
                    $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                    $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                    $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                    $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                    $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                    $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                    $arrayData[] = [$paPeriodRange, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                }

                return $arrayData;

                break;

            case 'cpag':
                $arrayData = array();
                $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;
                $paPeriodRange = isset($paPeriod) ? end($paPeriod) : NULL;
                $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                foreach($entities as $entity) {
                    $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                    $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                    $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                    $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                    $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                    $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                    $arrayData[] = [$format == 'input' ? $paPeriodCode : $paPeriodRange, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                }

                return $arrayData;

                break;

            case 'pppece':
                $arrayData = array();
                $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;
                $paPeriodRange = isset($paPeriod) ? end($paPeriod) : NULL;
                if($format == 'input') {
                    $arrayData[] = ['PA Period', 'FMNO', 'PE Charge Code', 'CE Charge Code', 'Hours', 'Overtime', 'Override Perdiem', 'Currency'];
                    foreach($entities as $entity) {
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
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $ceCharge = isset($entity->field_ce_charge_code['und'][0]['value']) ? $entity->field_ce_charge_code['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $charge, isset($hours) ? $hours * -1 : NULL, isset($overtime) ? $overtime * -1 : NULL, $perdiem, $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, $ceCharge, $hours, $overtime, $perdiem, $currency];
                    }
                }

                return $arrayData;

                break;

            case 'mnat':
                $arrayData = array();
                $paPeriodCode = isset($paPeriod) ? reset($paPeriod) : NULL;
                $paPeriodRange = isset($paPeriod) ? end($paPeriod) : NULL;
                if($format == 'input') {
                    $arrayData[] = ['FMNO', 'User Name', 'Debt', 'Office', 'Timesheet Period', 'Project Code', 'Act Code', 'Project Name', 'Eng Off', 'Regular Hours', 'O/T Hours', 'Nts Awy', 'NTs9', 'Override PD', 'Currency', 'Tracking Number', 'Hours (Reduce or add)', 'O/T Hours (Reduce or add)', 'CC to be moved', 'New PD Override', 'New PD Currency'];
                    foreach($entities as $entity) {
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
                        $newPDOverride = isset($entity->field_new_pd_override['und'][0]['value']) ? $entity->field_new_pd_override['und'][0]['value'] : NULL;
                        $newPDCurrency = isset($entity->field_new_pd_currency['und'][0]['value']) ? $entity->field_new_pd_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$FMNO, $userName, $dept, $office, $paPeriodCode, $projectCode, $actCode, $projectName, $engOff, $regularHours, $otHours, $ntsAwy, $nts9, $override_pd, $currency, $trackingNum, $hoursReduceOrAdd, $otHoursReduceOrAdd, $ccToBeMoved, $newPDOverride, $newPDCurrency];
                    }
                } elseif($format == 'output') {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $projectCode = isset($entity->field_project_code['und'][0]['value']) ? $entity->field_project_code['und'][0]['value'] : NULL;
                        $hoursReduceOrAdd = isset($entity->field_hours_reduce_or_add_['und'][0]['value']) ? $entity->field_hours_reduce_or_add_['und'][0]['value'] : NULL;
                        $otHoursReduceOrAdd = isset($entity->field_ot_hours_reduce_or_add_['und'][0]['value']) ? $entity->field_ot_hours_reduce_or_add_['und'][0]['value'] : NULL;
                        $override_pd = isset($entity->field_override_pd['und'][0]['value']) ? $entity->field_override_pd['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $ccToBeMoved = isset($entity->field_cc_to_be_moved['und'][0]['value']) ? $entity->field_cc_to_be_moved['und'][0]['value'] : NULL;
                        $newPDOverride = isset($entity->field_new_pd_override['und'][0]['value']) ? $entity->field_new_pd_override['und'][0]['value'] : NULL;
                        $newPDCurrency = isset($entity->field_new_pd_currency['und'][0]['value']) ? $entity->field_new_pd_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodRange, $FMNO, $projectCode, isset($hoursReduceOrAdd) ? $hoursReduceOrAdd * -1 : NULL, $otHoursReduceOrAdd, $override_pd, $currency];
                        $arrayData[] = [$paPeriodRange, $FMNO, isset($ccToBeMoved) ? $ccToBeMoved : $projectCode, isset($hoursReduceOrAdd) ? $hoursReduceOrAdd : NULL, $otHoursReduceOrAdd, $newPDOverride, $newPDCurrency];
                    }
                }

                return $arrayData;

                break;
        }
    }
}