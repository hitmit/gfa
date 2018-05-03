<?php

class Adjustments {

    /**
     * Query database for current or previous pay period.
     */
    function getPAPeriod($adjustmentType) {
        $priorPeriods = array('ppa');
        $now = new DateTime();

        if(in_array($adjustmentType, $priorPeriods)) {
            $date = $now->modify('-2 weeks');
            $date = $date->format('Y-m-d H:i:s');
//            ddl($date);
        } else {
            $date = $now->format('Y-m-d H:i:s');
        }

        $pp = new EntityFieldQuery();

        $pp->entityCondition('entity_type', 'field_collection_item')
            // No bundle value, use field name.
            ->propertyCondition('field_name', 'field_pa_periods')
            // We don't want revisions!
            ->propertyCondition('archived', 0)
            ->fieldCondition('field_pa_date_range', 'value', $date, '<=', 0)
            ->fieldCondition('field_pa_date_range', 'value2', $date, '>=', 0);

        $results = $pp->execute();

        if($results['field_collection_item']) {
            $entities = array_keys($results['field_collection_item']);
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
    function createAdjustmentOutput(array $entities, $format, $adjustmentType, array $paPeriod) {
        switch ($adjustmentType) {
            case 'ppa':
                $arrayData = array();
                $paPeriodCode = reset($paPeriod);
                $paPeriodRange = end($paPeriod);
                if($format == "input" ) {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodCode, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                    }
                } elseif($format == 'output') {
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
                }

                return $arrayData;

                break;

            case 'cparn':
                $arrayData = array();
                $paPeriodCode = reset($paPeriod);
                $paPeriodRange = end($paPeriod);
                if($format == "input" ) {
                    $arrayData[] = ['PA Period', 'FMNO', 'Charge Code', 'Hours', 'Overtime', 'Perdiem', 'Currency'];
                    foreach($entities as $entity) {
                        $FMNO = isset($entity->field_fmno['und'][0]['value']) ? $entity->field_fmno['und'][0]['value'] : NULL;
                        $charge = isset($entity->field_charge['und'][0]['value']) ? $entity->field_charge['und'][0]['value'] : NULL;
                        $hours = isset($entity->field_hours['und'][0]['value']) ? $entity->field_hours['und'][0]['value'] : NULL;
                        $overtime = isset($entity->field_overtime['und'][0]['value']) ? $entity->field_overtime['und'][0]['value'] : NULL;
                        $perdiem = isset($entity->field_perdiem['und'][0]['value']) ? $entity->field_perdiem['und'][0]['value'] : NULL;
                        $currency = isset($entity->field_currency['und'][0]['value']) ? $entity->field_currency['und'][0]['value'] : NULL;
                        $arrayData[] = [$paPeriodCode, $FMNO, $charge, $hours, $overtime, $perdiem, $currency];
                    }
                } elseif($format == 'output') {
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
                }

                return $arrayData;

                break;
        }
    }
}