<?php
/**
 * @file
 * acc_incident.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function acc_incident_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function acc_incident_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function acc_incident_node_info() {
  $items = array(
    'acc_incident' => array(
      'name' => t('Access Incident'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function acc_incident_default_search_api_index() {
  $items = array();
  $items['access_incident'] = entity_import('search_api_index', '{
    "name" : "Access Incident",
    "machine_name" : "access_incident",
    "description" : null,
    "server" : "hr_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "published_safe" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "created" : { "type" : "date" },
        "field_acc_date" : { "type" : "list\\u003Cdate\\u003E" },
        "field_acc_impacts:field_acc_impact_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_acc_impacts:field_acc_impact_value" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_acc_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_acc_type:parent" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_affected_organization_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_affected_organizations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_locations:field_geofield:bottom" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:geo_type" : { "type" : "list\\u003Cstring\\u003E" },
        "field_locations:field_geofield:geom" : { "type" : "list\\u003Ctext\\u003E" },
        "field_locations:field_geofield:lat" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:latlon" : { "type" : "list\\u003Cstring\\u003E" },
        "field_locations:field_geofield:left" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:lon" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:right" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:field_geofield:schemaorg_shape" : { "type" : "list\\u003Cstring\\u003E" },
        "field_locations:field_geofield:srid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_locations:field_geofield:top" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_locations:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_responsible_actors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_responsible_organization_t" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_type_of_affectee" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "acc_incident" : "acc_incident" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_locations:field_geofield:geom" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_locations:field_geofield:geom" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_locations:field_geofield:geom" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_locations:field_geofield:geom" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
