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
  $feeds_importer->id = 'acc_incident_types';
  $feeds_importer->config = array(
    'name' => 'CSV Access Incident Types',
    'description' => 'Import access incident types from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'acc_incident_types',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['acc_incident_types'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_incidents';
  $feeds_importer->config = array(
    'name' => 'CSV Access Incidents',
    'description' => 'Import Access Incidents from a CSV file',
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
        'bundle' => 'acc_incident',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title_field:et:und',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Start Date',
            'target' => 'field_acc_incident_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'End Date',
            'target' => 'field_acc_incident_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Type',
            'target' => 'field_acc_incident_type',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Responsible Actors',
            'target' => 'field_responsible_actors:label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Affected Organizations',
            'target' => 'field_affected_organizations:label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Location',
            'target' => 'field_locations',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Sectors',
            'target' => 'field_clusters',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Description',
            'target' => 'body:et:und',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Description',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['acc_incidents'] = $feeds_importer;

  return $export;
}
