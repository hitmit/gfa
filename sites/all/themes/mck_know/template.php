<?php

/**
 * Implements hook_theme().
 */
function mck_know_theme() {
  $items = array(
    'custom_main_menu' => array(
      'template' => 'templates/main_menu/custom-main-menu',
    ),
    'slide_menu' => array(
      'template' => 'templates/slide_menu/slide-menu',
    ),
    'views' => array(
      'template' => 'templates/views/views',
    ),
    'search' => array(
      'template' => 'templates/search/search',
    )
  );

  $menu_types = array(
    'industries',
    'business',
    'global',
    'locations',
    'careers',
    'about',
  );

  foreach ($menu_types as $menu_type) {
    $items['custom_main_menu_' . $menu_type] = array(
      'template' => 'templates/main_menu/custom-main-menu-' . $menu_type,
      'variables' => array('items' => array()),
    );
  }

  foreach ($menu_types as $menu_type) {
    $items['slide_menu_' . $menu_type] = array(
      'template' => 'templates/slide_menu/slide-menu-' . $menu_type,
      'variables' => array('item' => array()),
    );
  }

  return $items;
}

function mck_know_path() {
  global $base_path;

  return $base_path . drupal_get_path('theme', 'mck_know');
}

function mck_know_preprocess_page(array &$vars) {

}

function mck_know_preprocess_node(array &$vars) {
  switch ($vars['type']) {
    case 'page':
      $alias = drupal_get_path_alias();
      if (current_path() != $alias) {
        $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . str_replace('-', '_', $alias);
      }

      break;
  }
}

function mck_know_preprocess_field(array &$vars) {
  if ($vars['element']['#field_name'] == 'field_paragraph') {

  }
}

function mck_know_preprocess_custom_main_menu(array &$vars) {
  $vars['main_menu'] = menu_tree_all_data(variable_get('menu_main_links_source', 'main-menu'));
}

function mck_know_preprocess_slide_menu(array &$vars) {
  mck_know_preprocess_custom_main_menu($vars);
}

function mck_know_preprocess_slide_menu_industries(array &$vars) {
  $vars['items'] = $vars['item']['below'];
  $vars['role_id'] = drupal_clean_css_identifier($vars['item']['link']['title']);
}

function mck_know_preprocess_slide_menu_business(array &$vars) {
  mck_know_preprocess_slide_menu_industries($vars);
}

function mck_know_preprocess_slide_menu_global(array &$vars) {
  mck_know_preprocess_slide_menu_industries($vars);
}

function mck_know_preprocess_slide_menu_locations(array &$vars) {
  mck_know_preprocess_slide_menu_industries($vars);
}

function mck_know_preprocess_slide_menu_careers(array &$vars) {
  mck_know_preprocess_slide_menu_industries($vars);
}

function mck_know_preprocess_slide_menu_about(array &$vars) {
  mck_know_preprocess_slide_menu_industries($vars);
}

