<?php
/**
 * @file
 * acc_incidents.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function acc_incidents_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function acc_incidents_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function acc_incidents_node_info() {
  $items = array(
    'access_incident' => array(
      'name' => t('Access Incident'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Access Incident Title'),
      'help' => '',
    ),
  );
  return $items;
}
