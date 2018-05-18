<?php
/**
 * @file
 * gfa_adjustments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gfa_adjustments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function gfa_adjustments_node_info() {
  $items = array(
    'cparn' => array(
      'name' => t('CPARN'),
      'base' => 'node_content',
      'description' => t('Use <i>CPARN</i> to add CPA RADAR Net Accruals to the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mnat' => array(
      'name' => t('MNAT'),
      'base' => 'node_content',
      'description' => t('Use CPARN to add CPA RADAR Net Accruals to the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pay_periods' => array(
      'name' => t('Pay Periods'),
      'base' => 'node_content',
      'description' => t('Use pay periods to add pay periods to the adjustments.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ppa' => array(
      'name' => t('PPA'),
      'base' => 'node_content',
      'description' => t('Use <i>PPA</i> to add Prior Period Adjustments to the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pppece' => array(
      'name' => t('PPPECE'),
      'base' => 'node_content',
      'description' => t('Use PPECE to add Prior Period PE to CE adjustments to the website.
'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
