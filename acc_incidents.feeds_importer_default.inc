<?php
/**
 * @file
 * acc_incidents.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function acc_incidents_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_incident_csv_impoter';
  $feeds_importer->config = array(
    'name' => 'Access Incident CSV Impoter',
    'description' => 'Import Access Incidents from CVS file for Access Humanitarian project',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Incident Date Start',
            'target' => 'field_date:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Incident Date End',
            'target' => 'field_date:end',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Access Constraint',
            'target' => 'field_access_constraint',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Incident Type',
            'target' => 'field_incident_type_acc_incident:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Incident Type GUID',
            'target' => 'field_incident_type_acc_incident',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Resposible Actor',
            'target' => 'field_responsible_actor:label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Resposible Actor GUID',
            'target' => 'field_responsible_actor',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Targetted Organization',
            'target' => 'field_targetted_actor:label',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Targetted Organization GUID',
            'target' => 'field_targetted_actor',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Location',
            'target' => 'field_locations',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Below Admin 2 Level',
            'target' => 'field_below_admin_2_level',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Sector(s)/Cluster(s)',
            'target' => 'field_clusters',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Impact Text',
            'target' => 'field_acc_incident_impact_:field_acc_incident_impact_title:label',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Impact Text GUID',
            'target' => 'field_acc_incident_impact_:field_acc_incident_impact_title',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Value',
            'target' => 'field_acc_incident_impact_:field_value',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Description',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'access_incident',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['acc_incident_csv_impoter'] = $feeds_importer;

  return $export;
}
