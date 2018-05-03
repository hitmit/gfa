<?php

/**
 * @file
 * Administrative page callbacks for the Flexi Access Options module.
 */

/**
 * Form builder to display a listing of content types and their ACL status.
 */
function views_ajax_ef_options_admin_content($form) {
  $boolean = array(
    'yes' => 'Yes',
    'no' => 'No'
  );

  $form['views_ajax_ef_options']['scroll_to_top'] = array(
    '#type' => 'select',
    '#title' => t('Scroll To Top:'),
    '#default_value' => variable_get('scroll_to_top'),
    '#options' => $boolean,
    '#description' => t('Scroll to top after changing exposed filter.'),
  );

  return system_settings_form($form);
}