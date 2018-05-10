<?php
/**
 * @file
 * gfa_feeds_importer_.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gfa_feeds_importer__ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
