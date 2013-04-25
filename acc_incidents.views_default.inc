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
  $view->name = 'incident_map';
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
  $handler->display->display_options['style_options']['map'] = 'default';
  /* Relationship: Content: Geographical Location (Origin) (field_admin1_2) */
  $handler->display->display_options['relationships']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['relationships']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['relationships']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
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
  $handler->display->display_options['fields']['field_location']['relationship'] = 'field_admin1_2_tid';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Relationship: Content: Geographical Location (Origin) (field_admin1_2) */
  $handler->display->display_options['relationships']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['relationships']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['relationships']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  $handler->display->display_options['block_description'] = 'Incident Map';

  /* Display: Incidents Layer */
  $handler = $view->new_display('openlayers', 'Incidents Layer', 'openlayers_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'field_location',
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
  $translatables['incident_map'] = array(
    t('Master'),
    t('Incident Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_admin1_2'),
    t('Title'),
    t('Location'),
    t('Incidents Layer'),
  );
  $export['incident_map'] = $view;

  $view = new view();
  $view->name = 'incidents';
  $view->description = '';
  $view->tag = 'Access';
  $view->base_table = 'node';
  $view->human_name = 'Access Incidents';
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
  /* Relationship: Content: Geographical Location (Origin) (field_admin1_2) */
  $handler->display->display_options['relationships']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['relationships']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['relationships']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['delta_offset'] = '0';
  /* Field: Content: Date */
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
  /* Field: Taxonomy term: Access Constraint */
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
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Filter criterion: Content: Administrative request submited by (field_targetted_actor) */
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['operator_id'] = 'field_targetted_actor_target_id_op';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['label'] = 'Affected Organization';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['operator'] = 'field_targetted_actor_target_id_op';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['identifier'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Resposible Actor (field_responsible_actor) */
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['operator_id'] = 'field_responsible_actor_target_id_op';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['label'] = 'Responsible Actor';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['operator'] = 'field_responsible_actor_target_id_op';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['identifier'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Sector(s) affected (field_sectors) */
  $handler->display->display_options['filters']['field_sectors_tid']['id'] = 'field_sectors_tid';
  $handler->display->display_options['filters']['field_sectors_tid']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['filters']['field_sectors_tid']['field'] = 'field_sectors_tid';
  $handler->display->display_options['filters']['field_sectors_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_sectors_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['operator_id'] = 'field_sectors_tid_op';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['label'] = 'Sector / Cluster';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['operator'] = 'field_sectors_tid_op';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['identifier'] = 'field_sectors_tid';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_sectors_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sectors_tid']['vocabulary'] = 'clusters';
  $handler->display->display_options['filters']['field_sectors_tid']['hierarchy'] = 1;
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Geographical Location (Origin) (field_admin1_2) */
  $handler->display->display_options['filters']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['filters']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['value'] = '';
  $handler->display->display_options['filters']['field_admin1_2_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_admin1_2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['operator_id'] = 'field_admin1_2_tid_op';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['operator'] = 'field_admin1_2_tid_op';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['identifier'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_admin1_2_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_admin1_2_tid']['vocabulary'] = 'locations';
  $handler->display->display_options['filters']['field_admin1_2_tid']['hierarchy'] = 1;
  /* Filter criterion: Taxonomy term: Access Constraint (field_access_constraint) */
  $handler->display->display_options['filters']['field_access_constraint_tid']['id'] = 'field_access_constraint_tid';
  $handler->display->display_options['filters']['field_access_constraint_tid']['table'] = 'field_data_field_access_constraint';
  $handler->display->display_options['filters']['field_access_constraint_tid']['field'] = 'field_access_constraint_tid';
  $handler->display->display_options['filters']['field_access_constraint_tid']['relationship'] = 'field_incident_type_acc_incident_target_id';
  $handler->display->display_options['filters']['field_access_constraint_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_access_constraint_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_access_constraint_tid']['expose']['operator_id'] = 'field_access_constraint_tid_op';
  $handler->display->display_options['filters']['field_access_constraint_tid']['expose']['label'] = 'Access Constraint';
  $handler->display->display_options['filters']['field_access_constraint_tid']['expose']['operator'] = 'field_access_constraint_tid_op';
  $handler->display->display_options['filters']['field_access_constraint_tid']['expose']['identifier'] = 'field_access_constraint_tid';
  $handler->display->display_options['filters']['field_access_constraint_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_access_constraint_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_access_constraint_tid']['vocabulary'] = 'access_constraints';

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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['delta_offset'] = '0';
  /* Field: Content: Date */
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
  /* Field: Taxonomy term: Access Constraint */
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
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'access/incidents';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Access Incidents';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

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
  );

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'access/incidents.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Chart Incidents By Access Constraints */
  $handler = $view->new_display('block', 'Chart Incidents By Access Constraints', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Access Incidents by Access Constraints';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'pie';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_field_access_constraint_ac' => array(
      'enabled' => 0,
      'sort' => '0',
    ),
    'field_field_access_constraint_ac_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_field_access_constraint_ac',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Access Constraints */
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['id'] = 'field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['field'] = 'field_field_access_constraint_ac';
  /* Field: Content: Access Constraints */
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['id'] = 'field_field_access_constraint_ac_1';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['field'] = 'field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['label'] = 'Number of Reports';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Access Constraints (field_field_access_constraint_ac) */
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['id'] = 'field_field_access_constraint_ac_tid';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['field'] = 'field_field_access_constraint_ac_tid';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['order'] = 'DESC';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';

  /* Display: Chart Access Incident By Incident Type */
  $handler = $view->new_display('block', 'Chart Access Incident By Incident Type', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Access Incident By Incident Type';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['block_description'] = 'Chart Access Incident By Incident Type';

  /* Display: Chart Access Incident By Location */
  $handler = $view->new_display('block', 'Chart Access Incident By Location', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Access Incidents by Locations';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_admin1_2' => array(
      'enabled' => 0,
    ),
    'field_admin1_2_1' => array(
      'enabled' => 1,
      'sort' => 'ASC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => '',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_admin1_2',
    'invert' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['delta_offset'] = '0';
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2_1']['id'] = 'field_admin1_2_1';
  $handler->display->display_options['fields']['field_admin1_2_1']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2_1']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_admin1_2_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_admin1_2_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_admin1_2_1']['separator'] = ', ';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['block_description'] = 'Chart Access Incidents by Location';

  /* Display: Chart Access Incident By Resposible Actors */
  $handler = $view->new_display('block', 'Chart Access Incident By Resposible Actors', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Access Incidents by Responsible Actor';
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
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_responsible_actor',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_responsible_actor']['delta_offset'] = '0';
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor_1']['id'] = 'field_responsible_actor_1';
  $handler->display->display_options['fields']['field_responsible_actor_1']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_responsible_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_responsible_actor_1']['separator'] = ', ';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['block_description'] = 'Chart Access Incidents by Responsible Actor';

  /* Display: Chart Access Incident By Sectors */
  $handler = $view->new_display('block', 'Chart Access Incident By Sectors', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Access Incidents by Sectors';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_sectors' => array(
      'enabled' => 0,
    ),
    'field_sectors_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of Incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_sectors',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['label'] = 'Sector/Cluster';
  $handler->display->display_options['fields']['field_sectors']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sectors']['multi_type'] = 'ul';
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors_1']['id'] = 'field_sectors_1';
  $handler->display->display_options['fields']['field_sectors_1']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors_1']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_sectors_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_sectors_1']['separator'] = ', ';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';

  /* Display: Chart Access Incident By Affected Organizations */
  $handler = $view->new_display('block', 'Chart Access Incident By Affected Organizations', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Chart Access Incidents by Affected Organizations';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'visualization';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['fields'] = array(
    'field_targetted_actor' => array(
      'enabled' => 0,
    ),
    'field_targetted_actor_1' => array(
      'enabled' => 1,
      'sort' => 'DESC',
    ),
  );
  $handler->display->display_options['style_options']['yAxis'] = array(
    'title' => 'Number of incidents',
  );
  $handler->display->display_options['style_options']['xAxis'] = array(
    'labelField' => 'field_targetted_actor',
    'invert' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor_1']['id'] = 'field_targetted_actor_1';
  $handler->display->display_options['fields']['field_targetted_actor_1']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_targetted_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_targetted_actor_1']['separator'] = ', ';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  /* Field: Content: Access Constraints */
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['id'] = 'field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['field'] = 'field_field_access_constraint_ac';
  /* Field: Content: Access Constraints */
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['id'] = 'field_field_access_constraint_ac_1';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['field'] = 'field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['label'] = 'Number of Reports';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Access Constraints (field_field_access_constraint_ac) */
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['id'] = 'field_field_access_constraint_ac_tid';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['field'] = 'field_field_access_constraint_ac_tid';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['order'] = 'DESC';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['delta_offset'] = '0';
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2_1']['id'] = 'field_admin1_2_1';
  $handler->display->display_options['fields']['field_admin1_2_1']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2_1']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_admin1_2_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_admin1_2_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_admin1_2_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Geographical Location (Origin) (field_admin1_2) */
  $handler->display->display_options['sorts']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['order'] = 'DESC';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_responsible_actor']['delta_offset'] = '0';
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor_1']['id'] = 'field_responsible_actor_1';
  $handler->display->display_options['fields']['field_responsible_actor_1']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_responsible_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_responsible_actor_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Resposible Actor (field_responsible_actor) */
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['label'] = 'Sector/Cluster';
  $handler->display->display_options['fields']['field_sectors']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sectors']['multi_type'] = 'ul';
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors_1']['id'] = 'field_sectors_1';
  $handler->display->display_options['fields']['field_sectors_1']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors_1']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_sectors_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_sectors_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sector(s) affected (field_sectors) */
  $handler->display->display_options['sorts']['field_sectors_tid']['id'] = 'field_sectors_tid';
  $handler->display->display_options['sorts']['field_sectors_tid']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['sorts']['field_sectors_tid']['field'] = 'field_sectors_tid';
  $handler->display->display_options['sorts']['field_sectors_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_sectors_tid']['order'] = 'DESC';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor_1']['id'] = 'field_targetted_actor_1';
  $handler->display->display_options['fields']['field_targetted_actor_1']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_targetted_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_targetted_actor_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Administrative request submited by (field_targetted_actor) */
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
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
  /* Field: Content: Access Constraints */
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['id'] = 'field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac']['field'] = 'field_field_access_constraint_ac';
  /* Field: Content: Access Constraints */
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['id'] = 'field_field_access_constraint_ac_1';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['field'] = 'field_field_access_constraint_ac';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_field_access_constraint_ac_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Access Constraints (field_field_access_constraint_ac) */
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['id'] = 'field_field_access_constraint_ac_tid';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['table'] = 'field_data_field_field_access_constraint_ac';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['field'] = 'field_field_access_constraint_ac_tid';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_field_access_constraint_ac_tid']['order'] = 'DESC';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'access/reports/by_access_constraints.xls';
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
  $handler->display->display_options['path'] = 'access/reports/by_incident_type.xls';
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
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['delta_offset'] = '0';
  /* Field: Content: Geographical Location (Origin) */
  $handler->display->display_options['fields']['field_admin1_2_1']['id'] = 'field_admin1_2_1';
  $handler->display->display_options['fields']['field_admin1_2_1']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2_1']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_admin1_2_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_admin1_2_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Geographical Location (Origin) (field_admin1_2) */
  $handler->display->display_options['sorts']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_admin1_2_tid']['order'] = 'DESC';
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
  $handler->display->display_options['path'] = 'access/reports/by_location.xls';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Resposible Actor */
  $handler->display->display_options['fields']['field_responsible_actor_1']['id'] = 'field_responsible_actor_1';
  $handler->display->display_options['fields']['field_responsible_actor_1']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_responsible_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_responsible_actor_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Resposible Actor (field_responsible_actor) */
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
  $handler->display->display_options['path'] = 'access/reports/by_responscible_actor.xls';
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
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  /* Field: Content: Sector(s) affected */
  $handler->display->display_options['fields']['field_sectors_1']['id'] = 'field_sectors_1';
  $handler->display->display_options['fields']['field_sectors_1']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors_1']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_sectors_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_sectors_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sector(s) affected (field_sectors) */
  $handler->display->display_options['sorts']['field_sectors_tid']['id'] = 'field_sectors_tid';
  $handler->display->display_options['sorts']['field_sectors_tid']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['sorts']['field_sectors_tid']['field'] = 'field_sectors_tid';
  $handler->display->display_options['sorts']['field_sectors_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_sectors_tid']['order'] = 'DESC';
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
  $handler->display->display_options['path'] = 'access/reports/by_sectors.xls';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Affected Organizations';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Content: Administrative request submited by */
  $handler->display->display_options['fields']['field_targetted_actor_1']['id'] = 'field_targetted_actor_1';
  $handler->display->display_options['fields']['field_targetted_actor_1']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_targetted_actor_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_targetted_actor_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Administrative request submited by (field_targetted_actor) */
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
  $handler->display->display_options['path'] = 'access/reports/by_affected_org.xls';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
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
      'sort' => 'ASC',
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
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Number of Incidents';
  $handler->display->display_options['fields']['field_date_1']['separator'] = ', ';
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
  /* Filter criterion: Content: Date (field_date) */
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
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['block_description'] = 'Chart Number of Incidents by date';
  $translatables['incidents'] = array(
    t('Master'),
    t('Access Incidents'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Taxonomy term entity referenced from field_incident_type_acc_incident'),
    t('term from field_admin1_2'),
    t('Title'),
    t('Geographical Location (Origin)'),
    t('Date'),
    t('Access Constraint'),
    t('Incident Type'),
    t('Resposible Actor'),
    t('Affected Organizations'),
    t('Sector(s) affected'),
    t('Affected Organization'),
    t('Responsible Actor'),
    t('Sector / Cluster'),
    t('Incident Date (field_date)'),
    t('Location'),
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
    t('Chart Access Incidents by Access Constraints'),
    t('Access Constraints'),
    t('Number of Reports'),
    t('Chart Access Incident By Incident Type'),
    t('Number of Incidents'),
    t('Chart Access Incident By Location'),
    t('Chart Access Incidents by Locations'),
    t('Chart Access Incidents by Location'),
    t('Chart Access Incident By Resposible Actors'),
    t('Chart Access Incidents by Responsible Actor'),
    t('Chart Access Incident By Sectors'),
    t('Chart Access Incidents by Sectors'),
    t('Sector/Cluster'),
    t('Chart Access Incident By Affected Organizations'),
    t('Chart Access Incidents by Affected Organizations'),
    t('Access Incidents By Access Constraints'),
    t('Access Incidents by Access Constraints'),
    t('Access Incident By Incident Type'),
    t('Access Incident By Location'),
    t('Access Incidents by Locations'),
    t('Access Incidents by Location'),
    t('Access Incident By Resposible Actors'),
    t('Access Incidents by Responsible Actor'),
    t('Access Incident By Sectors'),
    t('Access Incidents by Sectors'),
    t('Access Incident By Affected Organizations'),
    t('Access Incidents by Affected Organization'),
    t('Access Incidents by Affected Organizations'),
    t('XLS Access Incidents By Access Constraints'),
    t('XLS Access Incidents by Access Constraints'),
    t('XLS Access Incident By Incident Type'),
    t('XLS Access Incidents by Incident Type'),
    t('XLS Access Incident By Location'),
    t('XLS Access Incidents by Locations'),
    t('XLS Access Incident By Resposible Actors'),
    t('XLS Access Incidents by Responsible Actor'),
    t('XLS Access Incident By Sectors'),
    t('XLS Access Incidents by Sectors'),
    t('XLS Access Incident By Affected Organizations'),
    t('XLS Access Incidents by Affected Organization'),
    t('Recent Incidents'),
    t('View all'),
    t('Chart Number of Incidents by date'),
    t('Number of Incidents by date'),
  );
  $export['incidents'] = $view;

  return $export;
}
