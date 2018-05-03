<?php
function clientlink_preprocess_page(&$vars){
    $search_form = drupal_get_form('search_block_form');
    $vars['search'] = drupal_render($search_form);
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



