<?php
/**
 * @file
 * paragraphs_updates.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function paragraphs_updates_paragraphs_info() {
  $items = array(
    'banner' => array(
      'name' => 'Banner',
      'bundle' => 'banner',
      'locked' => '1',
    ),
    'banner_image' => array(
      'name' => 'Banner Image',
      'bundle' => 'banner_image',
      'locked' => '1',
    ),
    'banner_video' => array(
      'name' => 'Banner Video',
      'bundle' => 'banner_video',
      'locked' => '1',
    ),
    'help_item' => array(
      'name' => 'Help Item',
      'bundle' => 'help_item',
      'locked' => '1',
    ),
    'image' => array(
      'name' => 'Image',
      'bundle' => 'image',
      'locked' => '1',
    ),
    'news_item' => array(
      'name' => 'News Item',
      'bundle' => 'news_item',
      'locked' => '1',
    ),
    'three_columns_card' => array(
      'name' => 'Three Columns Card',
      'bundle' => 'three_columns_card',
      'locked' => '1',
    ),
    'three_columns_card_help' => array(
      'name' => 'Three Columns Card Help',
      'bundle' => 'three_columns_card_help',
      'locked' => '1',
    ),
    'three_columns_card_news' => array(
      'name' => 'Three Columns Card News',
      'bundle' => 'three_columns_card_news',
      'locked' => '1',
    ),
    'two_column' => array(
      'name' => 'Two Columns',
      'bundle' => 'two_column',
      'locked' => '1',
    ),
    'two_columns_with_image' => array(
      'name' => 'Two Columns with Image',
      'bundle' => 'two_columns_with_image',
      'locked' => '1',
    ),
    'two_columns_with_video' => array(
      'name' => 'Two Columns with Video',
      'bundle' => 'two_columns_with_video',
      'locked' => '1',
    ),
    'video' => array(
      'name' => 'Video',
      'bundle' => 'video',
      'locked' => '1',
    ),
  );
  return $items;
}
