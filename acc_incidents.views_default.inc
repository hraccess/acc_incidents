<?php
/**
 * @file
 * acc_incidents.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function acc_incidents_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'acc_incident_map';
  $view->description = '';
  $view->tag = 'Access';
  $view->base_table = 'node';
  $view->human_name = 'Access Incident Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Incident Map';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    200153887 => '200153887',
    52310416 => '52310416',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'acc_incidents_map';
  /* Relationship: Field: Location (field_locations) */
  $handler->display->display_options['relationships']['field_locations_tid']['id'] = 'field_locations_tid';
  $handler->display->display_options['relationships']['field_locations_tid']['table'] = 'field_data_field_locations';
  $handler->display->display_options['relationships']['field_locations_tid']['field'] = 'field_locations_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['relationship'] = 'field_locations_tid';
  $handler->display->display_options['fields']['field_location']['label'] = 'Point';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Clusters (field_clusters) */
  $handler->display->display_options['arguments']['field_clusters_tid']['id'] = 'field_clusters_tid';
  $handler->display->display_options['arguments']['field_clusters_tid']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['arguments']['field_clusters_tid']['field'] = 'field_clusters_tid';
  $handler->display->display_options['arguments']['field_clusters_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clusters_tid']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_clusters_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clusters_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clusters_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['arguments']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['arguments']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['arguments']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['arguments']['field_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_value']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_value']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Incident Map */
  $handler = $view->new_display('block', 'Incident Map', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['block_description'] = 'Incident Map';

  /* Display: Incidents Layer */
  $handler = $view->new_display('openlayers', 'Incidents Layer', 'openlayers_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_location',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
    'view_mode' => 'full',
    'style_field' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['acc_incident_map'] = array(
    t('Master'),
    t('Incident Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_locations'),
    t('Title'),
    t('Point'),
    t('All'),
    t('Incidents Layer'),
  );
  $export['acc_incident_map'] = $view;

  $view = new view();
  $view->name = 'acc_incidents';
  $view->description = '';
  $view->tag = 'Access';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Access Incidents';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    2 => '2',
    52310416 => '52310416',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_incident_type_acc_incident_target_id']['id'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['relationships']['field_incident_type_acc_incident_target_id']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['relationships']['field_incident_type_acc_incident_target_id']['field'] = 'field_incident_type_acc_incident_target_id';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint']['id'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['field'] = 'field_access_constraint';
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['label'] = 'Responsible Actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['delta_offset'] = '0';
  /* Field: Content: Name of Village (Destination) */
  $handler->display->display_options['fields']['field_below_admin_2_level']['id'] = 'field_below_admin_2_level';
  $handler->display->display_options['fields']['field_below_admin_2_level']['table'] = 'field_data_field_below_admin_2_level';
  $handler->display->display_options['fields']['field_below_admin_2_level']['field'] = 'field_below_admin_2_level';
  $handler->display->display_options['fields']['field_below_admin_2_level']['label'] = 'Below Admin 2 Level';
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters']['id'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['label'] = 'Sectors/Cluster Affected';
  $handler->display->display_options['fields']['field_clusters']['delta_offset'] = '0';
  /* Field: Content: Mark on map */
  $handler->display->display_options['fields']['field_point_location']['id'] = 'field_point_location';
  $handler->display->display_options['fields']['field_point_location']['table'] = 'field_data_field_point_location';
  $handler->display->display_options['fields']['field_point_location']['field'] = 'field_point_location';
  $handler->display->display_options['fields']['field_point_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_point_location']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Impact of access incident */
  $handler->display->display_options['fields']['field_acc_incident_impact_']['id'] = 'field_acc_incident_impact_';
  $handler->display->display_options['fields']['field_acc_incident_impact_']['table'] = 'field_data_field_acc_incident_impact_';
  $handler->display->display_options['fields']['field_acc_incident_impact_']['field'] = 'field_acc_incident_impact_';
  $handler->display->display_options['fields']['field_acc_incident_impact_']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_acc_incident_impact_']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Contextual filter: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['arguments']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['arguments']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['arguments']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['arguments']['field_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_value']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Incident Type (field_incident_type_acc_incident) */
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['id'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['field'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_incident_type_acc_incident_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Issuing actor / agency (field_responsible_actor) */
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_responsible_actor_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field: Access Constraint (field_access_constraint) */
  $handler->display->display_options['arguments']['field_access_constraint_tid']['id'] = 'field_access_constraint_tid';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['field'] = 'field_access_constraint_tid';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_access_constraint_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field: Clusters (field_clusters) */
  $handler->display->display_options['arguments']['field_clusters_tid']['id'] = 'field_clusters_tid';
  $handler->display->display_options['arguments']['field_clusters_tid']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['arguments']['field_clusters_tid']['field'] = 'field_clusters_tid';
  $handler->display->display_options['arguments']['field_clusters_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clusters_tid']['default_argument_type'] = 'global_filter_field';
  $handler->display->display_options['arguments']['field_clusters_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clusters_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clusters_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Access Incident */
  $handler = $view->new_display('page', 'Access Incident', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_admin1_2' => 'field_admin1_2',
    'field_date' => 'field_date',
    'field_responsible_actor' => 'field_responsible_actor',
    'field_targetted_actor' => 'field_targetted_actor',
    'field_access_constraint' => 'field_access_constraint',
    'field_incident_type_acc_incident' => 'field_incident_type_acc_incident',
    'field_sectors' => 'field_sectors',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_admin1_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_responsible_actor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_targetted_actor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_access_constraint' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_incident_type_acc_incident' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sectors' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint']['id'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['field'] = 'field_access_constraint';
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['label'] = 'Responsible Actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'access/incidents';
  $handler->display->display_options['menu']['title'] = 'Access Incidents';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_incident');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Export To Excel';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'access/incidents.xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_14' => 0,
    'block_13' => 0,
    'block_15' => 0,
    'block_16' => 0,
    'block_17' => 0,
    'block_18' => 0,
  );

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'access/incidents.csv';
  $handler->display->display_options['displays'] = array(
    'block_15' => 'block_15',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_14' => 0,
    'block_13' => 0,
  );

  /* Display: Chart Incidents By Access Constraints */
  $handler = $view->new_display('block', 'Chart Incidents By Access Constraints', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Access Constraints';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_access_constraint' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_access_constraint_1' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_access_constraint',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint']['id'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['field'] = 'field_access_constraint';
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint_1']['id'] = 'field_access_constraint_1';
  $handler->display->display_options['fields']['field_access_constraint_1']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint_1']['field'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_access_constraint_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_access_constraint_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Chart Access Incident By Incident Type */
  $handler = $view->new_display('block', 'Chart Access Incident By Incident Type', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incident By Incident Type';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_incident_type_acc_incident' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_incident_type_acc_incident_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_incident_type_acc_incident',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['id'] = 'field_incident_type_acc_incident_1';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Access Incident By Incident Type';

  /* Display: Chart Access Incident By Location */
  $handler = $view->new_display('block', 'Chart Access Incident By Location', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Locations';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_locations' => array(
      'enabled' => 0,
    ),
    'field_locations_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_locations',
    'invert' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations_1']['id'] = 'field_locations_1';
  $handler->display->display_options['fields']['field_locations_1']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations_1']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_locations_1']['label'] = 'number of incidents';
  $handler->display->display_options['fields']['field_locations_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Access Incidents by Location';

  /* Display: Chart Access Incident By Resposible Actors */
  $handler = $view->new_display('block', 'Chart Access Incident By Resposible Actors', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Responsible Actor';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_responsible_actor' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_responsible_actor_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_organization_type' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_organization_type',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor_1']['id'] = 'field_responsible_actor_1';
  $handler->display->display_options['fields']['field_responsible_actor_1']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_responsible_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_responsible_actor_1']['separator'] = ', ';
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = 'Org Type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Access Incidents by Responsible Actor';

  /* Display: Chart Access Incident By Sectors */
  $handler = $view->new_display('block', 'Chart Access Incident By Sectors', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Affected Sectors';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_clusters' => array(
      'enabled' => 0,
    ),
    'field_clusters_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_clusters',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters']['id'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['label'] = 'Sectors/Clusters Affected';
  $handler->display->display_options['fields']['field_clusters']['delta_offset'] = '0';
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters_1']['id'] = 'field_clusters_1';
  $handler->display->display_options['fields']['field_clusters_1']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters_1']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_clusters_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_clusters_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Chart Access Incident By Affected Organizations */
  $handler = $view->new_display('block', 'Chart Access Incident By Affected Organizations', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Affected Organizations';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_targetted_actor_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_organization_type' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_organization_type',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor_1']['id'] = 'field_targetted_actor_1';
  $handler->display->display_options['fields']['field_targetted_actor_1']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_targetted_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_targetted_actor_1']['separator'] = ', ';
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = 'Org Type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Access Incidents by Affected Organizations';

  /* Display: Access Incidents By Access Constraints */
  $handler = $view->new_display('block', 'Access Incidents By Access Constraints', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Access Constraints';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_field_access_constraint_ac' => 'field_field_access_constraint_ac',
    'field_field_access_constraint_ac_1' => 'field_field_access_constraint_ac_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_field_access_constraint_ac' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_field_access_constraint_ac_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint']['id'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['field'] = 'field_access_constraint';
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint_1']['id'] = 'field_access_constraint_1';
  $handler->display->display_options['fields']['field_access_constraint_1']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint_1']['field'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_access_constraint_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_access_constraint_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Access Incidents by Access Constraints';

  /* Display: Access Incident By Incident Type */
  $handler = $view->new_display('block', 'Access Incident By Incident Type', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incident By Incident Type';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_incident_type_acc_incident' => 'field_incident_type_acc_incident',
    'field_incident_type_acc_incident_1' => 'field_incident_type_acc_incident_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_incident_type_acc_incident' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_incident_type_acc_incident_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['id'] = 'field_incident_type_acc_incident_1';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Incident Type (field_incident_type_acc_incident) */
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['id'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['field'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Access Incident By Incident Type';

  /* Display: Access Incident By Location */
  $handler = $view->new_display('block', 'Access Incident By Location', 'block_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Locations';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_admin1_2' => 'field_admin1_2',
    'field_admin1_2_1' => 'field_admin1_2_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_admin1_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_admin1_2_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['delta_offset'] = '0';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations_1']['id'] = 'field_locations_1';
  $handler->display->display_options['fields']['field_locations_1']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations_1']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_locations_1']['label'] = 'Number of incident';
  $handler->display->display_options['fields']['field_locations_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Access Incidents by Location';

  /* Display: Access Incident By Resposible Actors */
  $handler = $view->new_display('block', 'Access Incident By Resposible Actors', 'block_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Responsible Actor';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_responsible_actor' => 'field_responsible_actor',
    'field_responsible_actor_1' => 'field_responsible_actor_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_responsible_actor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_responsible_actor_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_responsible_actor']['delta_offset'] = '0';
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor_1']['id'] = 'field_responsible_actor_1';
  $handler->display->display_options['fields']['field_responsible_actor_1']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_responsible_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_responsible_actor_1']['separator'] = ', ';
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = 'OrganizationType';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Issuing actor / agency (field_responsible_actor) */
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Access Incidents by Responsible Actor';

  /* Display: Access Incident By Sectors */
  $handler = $view->new_display('block', 'Access Incident By Sectors', 'block_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Sectors';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_sectors' => 'field_sectors',
    'field_sectors_1' => 'field_sectors_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_sectors' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sectors_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters']['id'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['label'] = 'Sectors/Clusters Affected';
  $handler->display->display_options['fields']['field_clusters']['delta_offset'] = '0';
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters_1']['id'] = 'field_clusters_1';
  $handler->display->display_options['fields']['field_clusters_1']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters_1']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_clusters_1']['label'] = 'Sectors/Clusters Affected';
  $handler->display->display_options['fields']['field_clusters_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Access Incidents by Sectors';

  /* Display: Access Incident By Affected Organizations */
  $handler = $view->new_display('block', 'Access Incident By Affected Organizations', 'block_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents by Affected Organization';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_targetted_actor' => 'field_targetted_actor',
    'field_targetted_actor_1' => 'field_targetted_actor_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_targetted_actor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_targetted_actor_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor_1']['id'] = 'field_targetted_actor_1';
  $handler->display->display_options['fields']['field_targetted_actor_1']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_targetted_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_targetted_actor_1']['separator'] = ', ';
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = 'Organization Type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Administrative request submitted by (field_targetted_actor) */
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Access Incidents by Affected Organizations';

  /* Display: XLS Access Incidents By Access Constraints */
  $handler = $view->new_display('views_data_export', 'XLS Access Incidents By Access Constraints', 'views_data_export_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Access Incidents by Access Constraints';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint']['id'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['field'] = 'field_access_constraint';
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint_1']['id'] = 'field_access_constraint_1';
  $handler->display->display_options['fields']['field_access_constraint_1']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint_1']['field'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_access_constraint_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_access_constraint_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_value']['expose']['operator_id'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['label'] = 'Incident Date (field_date)';
  $handler->display->display_options['filters']['field_date_value']['expose']['operator'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['identifier'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'access/by_access_constraints.xls';
  $handler->display->display_options['displays'] = array(
    'block_8' => 'block_8',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Access Incident By Incident Type */
  $handler = $view->new_display('views_data_export', 'XLS Access Incident By Incident Type', 'views_data_export_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Access Incidents by Incident Type';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['id'] = 'field_incident_type_acc_incident_1';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_incident_type_acc_incident_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Incident Type (field_incident_type_acc_incident) */
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['id'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['field'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_incident_type_acc_incident_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'access/by_incident_type.xls';
  $handler->display->display_options['displays'] = array(
    'block_7' => 'block_7',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Access Incident By Location */
  $handler = $view->new_display('views_data_export', 'XLS Access Incident By Location', 'views_data_export_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Access Incidents by Locations';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['delta_offset'] = '0';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations_1']['id'] = 'field_locations_1';
  $handler->display->display_options['fields']['field_locations_1']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations_1']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_locations_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_locations_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'access/by_location.xls';
  $handler->display->display_options['displays'] = array(
    'block_9' => 'block_9',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Access Incident By Resposible Actors */
  $handler = $view->new_display('views_data_export', 'XLS Access Incident By Resposible Actors', 'views_data_export_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Access Incidents by Responsible Actor';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['relationships']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor_1']['id'] = 'field_responsible_actor_1';
  $handler->display->display_options['fields']['field_responsible_actor_1']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_responsible_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_responsible_actor_1']['separator'] = ', ';
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = 'Organization Type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Issuing actor / agency (field_responsible_actor) */
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_responsible_actor_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'access/by_responscible_actor.xls';
  $handler->display->display_options['displays'] = array(
    'block_10' => 'block_10',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_11' => 0,
    'block_12' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Access Incident By Sectors */
  $handler = $view->new_display('views_data_export', 'XLS Access Incident By Sectors', 'views_data_export_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Access Incidents by Sectors';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters']['id'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['label'] = 'Sectors/Clusters';
  $handler->display->display_options['fields']['field_clusters']['delta_offset'] = '0';
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters_1']['id'] = 'field_clusters_1';
  $handler->display->display_options['fields']['field_clusters_1']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters_1']['field'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_clusters_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_clusters_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'access/by_sectors.xls';
  $handler->display->display_options['displays'] = array(
    'block_11' => 'block_11',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_12' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Access Incident By Affected Organizations */
  $handler = $view->new_display('views_data_export', 'XLS Access Incident By Affected Organizations', 'views_data_export_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Access Incidents by Affected Organization';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['relationships']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor_1']['id'] = 'field_targetted_actor_1';
  $handler->display->display_options['fields']['field_targetted_actor_1']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_targetted_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_targetted_actor_1']['separator'] = ', ';
  /* Field: Field: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['fields']['field_organization_type']['label'] = 'Organization Type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Administrative request submitted by (field_targetted_actor) */
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_targetted_actor_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'access/by_affected_org.xls';
  $handler->display->display_options['displays'] = array(
    'block_12' => 'block_12',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Recent Incidents */
  $handler = $view->new_display('block', 'Recent Incidents', 'block_14');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Incidents';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_admin1_2' => 'field_admin1_2',
    'field_date' => 'field_date',
    'field_access_constraint' => 'field_access_constraint',
    'field_incident_type_acc_incident' => 'field_incident_type_acc_incident',
    'field_responsible_actor' => 'field_responsible_actor',
    'field_targetted_actor' => 'field_targetted_actor',
    'field_sectors' => 'field_sectors',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_admin1_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_access_constraint' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_incident_type_acc_incident' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_responsible_actor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_targetted_actor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sectors' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Recent Incidents';

  /* Display: Chart Number of Incidents by date */
  $handler = $view->new_display('block', 'Chart Number of Incidents by date', 'block_13');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of Incidents by date';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_date' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_date_1' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_date',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date']['alter']['max_length'] = '2';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'access_short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Dates';
  $handler->display->display_options['fields']['field_date_1']['alter']['text'] = '%4';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Number of Incidents by date';

  /* Display: Access Incident Block */
  $handler = $view->new_display('block', 'Access Incident Block', 'block_15');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Access Incidents';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_admin1_2' => 'field_admin1_2',
    'field_date' => 'field_date',
    'field_access_constraint' => 'field_access_constraint',
    'field_incident_type_acc_incident' => 'field_incident_type_acc_incident',
    'field_responsible_actor' => 'field_responsible_actor',
    'field_targetted_actor' => 'field_targetted_actor',
    'field_sectors' => 'field_sectors',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_admin1_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_access_constraint' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_incident_type_acc_incident' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_responsible_actor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_targetted_actor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sectors' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'field_data_field_locations';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['delta_offset'] = '0';
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Access Constraint */
  $handler->display->display_options['fields']['field_access_constraint']['id'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['field'] = 'field_access_constraint';
  $handler->display->display_options['fields']['field_access_constraint']['relationship'] = 'field_incident_type_acc_incident_target_id';
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Issuing actor / agency */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['label'] = 'Responsible Actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Administrative request submitted by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Field: Clusters */
  $handler->display->display_options['fields']['field_clusters']['id'] = 'field_clusters';
  $handler->display->display_options['fields']['field_clusters']['table'] = 'field_data_field_clusters';
  $handler->display->display_options['fields']['field_clusters']['field'] = 'field_clusters';
  $handler->display->display_options['block_description'] = 'Access Incidents';

  /* Display: Chart Impact Trend */
  $handler = $view->new_display('block', 'Chart Impact Trend', 'block_16');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Impact Trend';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_date' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_value' => array(
      'enabled' => 1,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_date',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Impact of access incident (field_acc_incident_impact_) */
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['id'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['table'] = 'field_data_field_acc_incident_impact_';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['field'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'access_month_only_date_format',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Value */
  $handler->display->display_options['fields']['field_value']['id'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['table'] = 'field_data_field_value';
  $handler->display->display_options['fields']['field_value']['field'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['relationship'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['fields']['field_value']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_value']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Impact Trend';

  /* Display: Chart Impact */
  $handler = $view->new_display('block', 'Chart Impact', 'block_17');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Impact';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_value' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
    'field_acc_incident_impact_title' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Units',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_acc_incident_impact_title',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Impact of access incident (field_acc_incident_impact_) */
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['id'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['table'] = 'field_data_field_acc_incident_impact_';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['field'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Value */
  $handler->display->display_options['fields']['field_value']['id'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['table'] = 'field_data_field_value';
  $handler->display->display_options['fields']['field_value']['field'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['relationship'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['fields']['field_value']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_value']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Impact */
  $handler->display->display_options['fields']['field_acc_incident_impact_title']['id'] = 'field_acc_incident_impact_title';
  $handler->display->display_options['fields']['field_acc_incident_impact_title']['table'] = 'field_data_field_acc_incident_impact_title';
  $handler->display->display_options['fields']['field_acc_incident_impact_title']['field'] = 'field_acc_incident_impact_title';
  $handler->display->display_options['fields']['field_acc_incident_impact_title']['relationship'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['fields']['field_acc_incident_impact_title']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Chart Impact';

  /* Display: Impact Trend */
  $handler = $view->new_display('block', 'Impact Trend', 'block_18');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Impact Trend';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date' => 'field_date',
    'field_value' => 'field_value',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Impact of access incident (field_acc_incident_impact_) */
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['id'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['table'] = 'field_data_field_acc_incident_impact_';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['field'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'access_month_only_date_format',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Value */
  $handler->display->display_options['fields']['field_value']['id'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['table'] = 'field_data_field_value';
  $handler->display->display_options['fields']['field_value']['field'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['relationship'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['fields']['field_value']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_value']['label'] = 'Person Affected';
  $handler->display->display_options['fields']['field_value']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Impact Trend';

  /* Display: XLS Impact Trends */
  $handler = $view->new_display('views_data_export', 'XLS Impact Trends', 'views_data_export_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Impact Trends';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%display.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Impact of access incident (field_acc_incident_impact_) */
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['id'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['table'] = 'field_data_field_acc_incident_impact_';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['field'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['relationships']['field_acc_incident_impact__value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Value */
  $handler->display->display_options['fields']['field_value']['id'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['table'] = 'field_data_field_value';
  $handler->display->display_options['fields']['field_value']['field'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['relationship'] = 'field_acc_incident_impact__value';
  $handler->display->display_options['fields']['field_value']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_value']['label'] = 'Person Affected';
  $handler->display->display_options['fields']['field_value']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_value']['expose']['operator_id'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['label'] = 'Incident Date (field_date)';
  $handler->display->display_options['filters']['field_date_value']['expose']['operator'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['identifier'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'reports/impact_trends.xls';
  $handler->display->display_options['displays'] = array(
    'block_18' => 'block_18',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_14' => 0,
    'block_13' => 0,
    'block_15' => 0,
    'block_16' => 0,
    'block_17' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Number of Incidents by date */
  $handler = $view->new_display('block', 'Number of Incidents by date', 'block_19');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Number of Incidents by date';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date' => 'field_date',
    'field_date_1' => 'field_date_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date']['alter']['max_length'] = '2';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'access_short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['field_date_1']['alter']['text'] = '%4';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Number of Incidents by date';

  /* Display: XLS Number of incidents per day */
  $handler = $view->new_display('views_data_export', 'XLS Number of incidents per day', 'views_data_export_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Number of incidents per day';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Action Taken Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'access_short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['group_type'] = 'count';
  $handler->display->display_options['fields']['title_field']['label'] = 'Number of incidents';
  $handler->display->display_options['fields']['title_field']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Action Taken Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['path'] = 'access/num_rep_day.xls';
  $handler->display->display_options['displays'] = array(
    'block_19' => 'block_19',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_14' => 0,
    'block_13' => 0,
    'block_15' => 0,
    'block_16' => 0,
    'block_17' => 0,
    'block_18' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Action Taken Access Incident */
  $handler = $view->new_display('block', 'Action Taken Access Incident', 'block_20');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Action Taken Access Incident';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_date' => 'field_date',
    'field_access_constraint' => 'field_access_constraint',
    'field_incident_type_acc_incident' => 'field_incident_type_acc_incident',
    'field_responsible_actor' => 'field_responsible_actor',
    'field_targetted_actor' => 'field_targetted_actor',
    'field_locations' => 'field_locations',
    'field_below_admin_2_level' => 'field_below_admin_2_level',
    'field_clusters' => 'field_clusters',
    'field_point_location' => 'field_point_location',
    'field_acc_incident_impact_' => 'field_acc_incident_impact_',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_access_constraint' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_incident_type_acc_incident' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_responsible_actor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_targetted_actor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_locations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_below_admin_2_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clusters' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_point_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_acc_incident_impact_' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Action Taken Policy (field_acc_action_taken) */
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['id'] = 'field_acc_action_taken_value';
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['table'] = 'field_data_field_acc_action_taken';
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['field'] = 'field_acc_action_taken_value';
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Action taken date */
  $handler->display->display_options['fields']['field_action_taken_date']['id'] = 'field_action_taken_date';
  $handler->display->display_options['fields']['field_action_taken_date']['table'] = 'field_data_field_action_taken_date';
  $handler->display->display_options['fields']['field_action_taken_date']['field'] = 'field_action_taken_date';
  $handler->display->display_options['fields']['field_action_taken_date']['relationship'] = 'field_acc_action_taken_value';
  $handler->display->display_options['fields']['field_action_taken_date']['settings'] = array(
    'format_type' => 'access_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Action taken type */
  $handler->display->display_options['fields']['field_action_taken_type']['id'] = 'field_action_taken_type';
  $handler->display->display_options['fields']['field_action_taken_type']['table'] = 'field_data_field_action_taken_type';
  $handler->display->display_options['fields']['field_action_taken_type']['field'] = 'field_action_taken_type';
  $handler->display->display_options['fields']['field_action_taken_type']['relationship'] = 'field_acc_action_taken_value';
  /* Field: Field collection item: Action taken description */
  $handler->display->display_options['fields']['field_action_taken_description']['id'] = 'field_action_taken_description';
  $handler->display->display_options['fields']['field_action_taken_description']['table'] = 'field_data_field_action_taken_description';
  $handler->display->display_options['fields']['field_action_taken_description']['field'] = 'field_action_taken_description';
  $handler->display->display_options['fields']['field_action_taken_description']['relationship'] = 'field_acc_action_taken_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field collection item: Action taken type (field_action_taken_type) */
  $handler->display->display_options['filters']['field_action_taken_type_tid']['id'] = 'field_action_taken_type_tid';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['table'] = 'field_data_field_action_taken_type';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['field'] = 'field_action_taken_type_tid';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['relationship'] = 'field_acc_action_taken_value';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['value'] = '';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['vocabulary'] = 'acc_action_taken_type';
  $handler->display->display_options['block_description'] = 'Action Taken Access Incident';

  /* Display: XLS Action taken */
  $handler = $view->new_display('views_data_export', 'XLS Action taken', 'views_data_export_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'XLS Action taken';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Action Taken Policy (field_acc_action_taken) */
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['id'] = 'field_acc_action_taken_value';
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['table'] = 'field_data_field_acc_action_taken';
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['field'] = 'field_acc_action_taken_value';
  $handler->display->display_options['relationships']['field_acc_action_taken_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Incident Type */
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['id'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['table'] = 'field_data_field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['field'] = 'field_incident_type_acc_incident';
  $handler->display->display_options['fields']['field_incident_type_acc_incident']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Action taken date */
  $handler->display->display_options['fields']['field_action_taken_date']['id'] = 'field_action_taken_date';
  $handler->display->display_options['fields']['field_action_taken_date']['table'] = 'field_data_field_action_taken_date';
  $handler->display->display_options['fields']['field_action_taken_date']['field'] = 'field_action_taken_date';
  $handler->display->display_options['fields']['field_action_taken_date']['relationship'] = 'field_acc_action_taken_value';
  $handler->display->display_options['fields']['field_action_taken_date']['settings'] = array(
    'format_type' => 'access_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Action taken description */
  $handler->display->display_options['fields']['field_action_taken_description']['id'] = 'field_action_taken_description';
  $handler->display->display_options['fields']['field_action_taken_description']['table'] = 'field_data_field_action_taken_description';
  $handler->display->display_options['fields']['field_action_taken_description']['field'] = 'field_action_taken_description';
  $handler->display->display_options['fields']['field_action_taken_description']['relationship'] = 'field_acc_action_taken_value';
  /* Field: Field collection item: Action taken type */
  $handler->display->display_options['fields']['field_action_taken_type']['id'] = 'field_action_taken_type';
  $handler->display->display_options['fields']['field_action_taken_type']['table'] = 'field_data_field_action_taken_type';
  $handler->display->display_options['fields']['field_action_taken_type']['field'] = 'field_action_taken_type';
  $handler->display->display_options['fields']['field_action_taken_type']['relationship'] = 'field_acc_action_taken_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field collection item: Action taken type (field_action_taken_type) */
  $handler->display->display_options['filters']['field_action_taken_type_tid']['id'] = 'field_action_taken_type_tid';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['table'] = 'field_data_field_action_taken_type';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['field'] = 'field_action_taken_type_tid';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['relationship'] = 'field_acc_action_taken_value';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['vocabulary'] = 'acc_action_taken_type';
  $handler->display->display_options['filters']['field_action_taken_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'action_taken_acc_incidebt.xls';
  $handler->display->display_options['displays'] = array(
    'block_20' => 'block_20',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_8' => 0,
    'block_7' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_14' => 0,
    'block_13' => 0,
    'block_15' => 0,
    'block_16' => 0,
    'block_17' => 0,
    'block_18' => 0,
    'block_19' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['acc_incidents'] = array(
    t('Master'),
    t('Access Incidents'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Taxonomy term entity referenced from field_incident_type_acc_incident'),
    t('Title'),
    t('Action Taken Date'),
    t('Access Constraint'),
    t('Incident Type'),
    t('Responsible Actor'),
    t('Affected Organizations'),
    t('Location'),
    t('Below Admin 2 Level'),
    t('Sectors/Cluster Affected'),
    t('Mark on map'),
    t('Impact of access incident'),
    t('Description'),
    t('All'),
    t('Access Incident'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Data export'),
    t('CSV'),
    t('Chart Incidents By Access Constraints'),
    t('Access Incidents by Access Constraints'),
    t('Number of incidents'),
    t('Chart Access Incident By Incident Type'),
    t('Access Incident By Incident Type'),
    t('Number of Incidents'),
    t('Chart Access Incident By Location'),
    t('Access Incidents by Locations'),
    t('number of incidents'),
    t('Chart Access Incidents by Location'),
    t('Chart Access Incident By Resposible Actors'),
    t('Access Incidents by Responsible Actor'),
    t('Taxonomy term entity referenced from field_responsible_actor'),
    t('Org Type'),
    t('Chart Access Incidents by Responsible Actor'),
    t('Chart Access Incident By Sectors'),
    t('Access Incidents by Affected Sectors'),
    t('Sectors/Clusters Affected'),
    t('Chart Access Incident By Affected Organizations'),
    t('Access Incidents by Affected Organizations'),
    t('Taxonomy term entity referenced from field_targetted_actor'),
    t('Chart Access Incidents by Affected Organizations'),
    t('Access Incidents By Access Constraints'),
    t('Access Incident By Location'),
    t('Number of incident'),
    t('Access Incidents by Location'),
    t('Access Incident By Resposible Actors'),
    t('Issuing actor / agency'),
    t('OrganizationType'),
    t('Access Incident By Sectors'),
    t('Access Incidents by Sectors'),
    t('Access Incident By Affected Organizations'),
    t('Access Incidents by Affected Organization'),
    t('Organization Type'),
    t('XLS Access Incidents By Access Constraints'),
    t('XLS Access Incidents by Access Constraints'),
    t('Incident Date (field_date)'),
    t('XLS Access Incident By Incident Type'),
    t('XLS Access Incidents by Incident Type'),
    t('XLS Access Incident By Location'),
    t('XLS Access Incidents by Locations'),
    t('XLS Access Incident By Resposible Actors'),
    t('XLS Access Incidents by Responsible Actor'),
    t('XLS Access Incident By Sectors'),
    t('XLS Access Incidents by Sectors'),
    t('Sectors/Clusters'),
    t('XLS Access Incident By Affected Organizations'),
    t('XLS Access Incidents by Affected Organization'),
    t('Recent Incidents'),
    t('View all'),
    t('Chart Number of Incidents by date'),
    t('Number of Incidents by date'),
    t('Date'),
    t('Dates'),
    t('%4'),
    t('Access Incident Block'),
    t('Clusters'),
    t('Chart Impact Trend'),
    t('field collection item from field_acc_incident_impact_'),
    t('Value'),
    t('Chart Impact'),
    t('Impact'),
    t('Impact Trend'),
    t('Person Affected'),
    t('XLS Impact Trends'),
    t('XLS Number of incidents per day'),
    t('Action Taken Access Incident'),
    t('field collection item from field_acc_action_taken'),
    t('Action taken date'),
    t('Action taken type'),
    t('Action taken description'),
    t('XLS Action taken'),
  );
  $export['acc_incidents'] = $view;

  return $export;
}
