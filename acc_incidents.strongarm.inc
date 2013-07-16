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
  $strongarm->name = 'auto_entitylabel_node_access_incident';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_access_incident';
  $strongarm->value = '[node:field_incident_type_acc_incident] [node:field_locations] [node:field_date]';
  $export['auto_entitylabel_pattern_node_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_access_incident';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_access_incident';
  $strongarm->value = '1';
  $export['comment_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_access_incident';
  $strongarm->value = 0;
  $export['comment_anonymous_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_access_incident';
  $strongarm->value = 0;
  $export['comment_default_mode_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_access_incident';
  $strongarm->value = '50';
  $export['comment_default_per_page_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_access_incident';
  $strongarm->value = 1;
  $export['comment_form_location_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_access_incident';
  $strongarm->value = '0';
  $export['comment_preview_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_access_incident';
  $strongarm->value = 1;
  $export['comment_subject_field_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__access_incident';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'entityreference_view_widget' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '13',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'global_filters';
  $strongarm->value = array(
    1 => array(
      'name' => 'field_access_constraint',
      'block' => 'global_filter_1',
      'uses_view' => '0',
      'field' => 'field_access_constraint',
      'view' => '',
      'widget' => 'select',
      'convert_to_range' => 0,
      'label' => '',
      'option_all_text' => '',
      'confirm_question' => '',
      'set_on_select' => 0,
      'global_field_or_view_default' => '',
      'global_php_default' => '',
    ),
    2 => array(
      'name' => 'field_locations',
      'block' => 'global_filter_2',
      'uses_view' => '0',
      'field' => 'field_locations',
      'view' => '',
      'widget' => 'select',
      'convert_to_range' => 0,
      'label' => '',
      'option_all_text' => '',
      'confirm_question' => '',
      'set_on_select' => 0,
      'global_field_or_view_default' => '',
      'global_php_default' => '',
    ),
    3 => array(
      'name' => 'field_date',
      'block' => 'global_filter_3',
      'uses_view' => '0',
      'field' => 'field_date',
      'view' => '',
      'widget' => 'default_date_popup',
      'convert_to_range' => 0,
      'label' => '',
      'option_all_text' => '',
      'confirm_question' => '',
      'set_on_select' => 0,
      'global_field_or_view_default' => '',
      'global_php_default' => '<?php return \'2013-01-01--2013-12-31\'; ?>',
    ),
    4 => array(
      'name' => 'field_clusters',
      'block' => 'global_filter_4',
      'uses_view' => '0',
      'field' => 'field_clusters',
      'view' => '',
      'widget' => 'select',
      'convert_to_range' => 0,
      'label' => '',
      'option_all_text' => '',
      'confirm_question' => '',
      'set_on_select' => 0,
      'global_field_or_view_default' => '',
      'global_php_default' => '',
    ),
    5 => array(
      'name' => 'field_incident_type_restriction',
      'block' => 'global_filter_5',
      'uses_view' => '0',
      'field' => 'field_incident_type_restriction',
      'view' => '',
      'widget' => 'default',
      'convert_to_range' => 0,
      'label' => '',
      'option_all_text' => '',
      'confirm_question' => '',
      'set_on_select' => 0,
      'global_field_or_view_default' => '',
      'global_php_default' => '',
    ),
    6 => array(
      'name' => '',
      'block' => NULL,
      'uses_view' => NULL,
      'field' => NULL,
      'view' => NULL,
      'widget' => NULL,
      'convert_to_range' => NULL,
      'label' => NULL,
      'option_all_text' => NULL,
      'confirm_question' => NULL,
      'set_on_select' => NULL,
      'global_field_or_view_default' => NULL,
      'global_php_default' => NULL,
    ),
  );
  $export['global_filters'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_access_incident';
  $strongarm->value = '0';
  $export['language_content_type_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_access_incident';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_access_incident';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_access_incident';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_access_incident';
  $strongarm->value = '0';
  $export['node_preview_access_incident'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_access_incident';
  $strongarm->value = 1;
  $export['node_submitted_access_incident'] = $strongarm;

  return $export;
}
