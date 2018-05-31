<?php
function clientlink_preprocess_page(&$vars){
    $search_form = drupal_get_form('search_block_form');
    $vars['search'] = drupal_render($search_form);
}


function clientlink_preprocess_node(array &$vars) {
  switch ($vars['type']) {
    case 'page':
      $alias = drupal_get_path_alias();
      if (current_path() != $alias) {
        $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . str_replace('-', '_', $alias);
      }

      break;
  }
}


function clientlink_links__system_main_menu() {return null;}

/* main ul */
function clientlink_menu_tree__main_menu($variables) {
  return '<ul class="navbar-nav">' . $variables['tree'] . '</ul>';
}

/* inner ui */
function clientlink_menu_tree__main_menu_inner($variables) {
    return '<ul class="dropdown">' . $variables['tree'] . '</ul>';
}

/* inner li */
function clientlink_menu_link__main_menu_inner($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li class="submenu-item">' . $output . $sub_menu . "</li>\n";
}

/* main li */
function clientlink_menu_link__main_menu(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    foreach ($element['#below'] as $key => $val) {
      if (is_numeric($key)) {             
        $element['#below'][$key]['#theme'] = 'menu_link__main_menu_inner'; // 2 lavel 
      }
    }
    $element['#below']['#theme_wrappers'][0] = 'menu_tree__main_menu_inner';  // 2 lavel 
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li class="nav-item">' . $output . $sub_menu . "</li>\n";
}

function clientlink_form_alter(&$form, &$form_state, $form_id) {
  if (!empty($form['actions']) && $form['actions']['submit']) {
    $form['actions']['submit']['#attributes'] = array('class' => array('mck-button', 'mck-th-cyan', 'mck-button--big'));
  }
  
}

function clientlink_preprocess_select(&$vars) {
  $vars['element']['#attributes']['class'][] = "form-control";
}

function clientlink_preprocess_button(&$vars)  {
  $vars['element']['#attributes']['class'][] = "btn";
}

function clientlink_form_element($variables) {
  $element =& $variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array(
    'form-group',
  );
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
      ' ' => '-',
      '_' => '-',
      '[' => '-',
      ']' => '',
    ));
  }

  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';
  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;
    case 'none':
    case 'attribute':

      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }
  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }
  $output .= "</div>\n";
  return $output;
}