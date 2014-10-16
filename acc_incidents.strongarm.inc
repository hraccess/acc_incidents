<?php
/**
 * @file
 * acc_incidents.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function acc_incidents_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_acc_incident';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_acc_incident';
  $strongarm->value = '[node:field_acc_date] [node:field_acc_type] [node:field_locations]';
  $export['auto_entitylabel_pattern_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_acc_incident';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__acc_incident';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '15',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_acc_incident';
  $strongarm->value = '0';
  $export['language_content_type_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_acc_incident';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_acc_incident';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_acc_incident';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_acc_incident';
  $strongarm->value = '1';
  $export['node_preview_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_acc_incident';
  $strongarm->value = 0;
  $export['node_submitted_acc_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_acc_incident_pattern';
  $strongarm->value = '[node:og-group-ref:0:url:path]/access-incident/[node:title]';
  $export['pathauto_node_acc_incident_pattern'] = $strongarm;

  return $export;
}
