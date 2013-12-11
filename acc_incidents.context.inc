<?php
/**
 * @file
 * acc_incidents.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function acc_incidents_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_access_incidents';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'access/dashboard/factsheet-access-incidents' => 'access/dashboard/factsheet-access-incidents',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-acc_incidents-block_1' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-acc_incidents-block_8' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_8',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-acc_incidents-block_2' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_2',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-acc_incidents-block_7' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_7',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-acc_incidents-block_3' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_3',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-acc_incidents-block_9' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_9',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-acc_incidents-block_4' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_4',
          'region' => 'content',
          'weight' => '-4',
        ),
        'views-acc_incidents-block_10' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_10',
          'region' => 'content',
          'weight' => '-3',
        ),
        'views-acc_incidents-block_5' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_5',
          'region' => 'content',
          'weight' => '-2',
        ),
        'views-acc_incidents-block_11' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_11',
          'region' => 'content',
          'weight' => '-1',
        ),
        'views-acc_incidents-block_6' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_6',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_incidents-block_12' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_12',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-acc_incidents-block_17' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_17',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_incidents-block_13' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_13',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_incidents-block_20' => array(
          'module' => 'views',
          'delta' => 'acc_incidents-block_20',
          'region' => 'content',
          'weight' => '7',
        ),
        'boxes-acc_access_links' => array(
          'module' => 'boxes',
          'delta' => 'acc_access_links',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'global_filter-global_filter_3' => array(
          'module' => 'global_filter',
          'delta' => 'global_filter_3',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-filter-reset---incident-date' => array(
          'module' => 'bean',
          'delta' => 'filter-reset---incident-date',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'global_filter-global_filter_1' => array(
          'module' => 'global_filter',
          'delta' => 'global_filter_1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean-filter-reset---access-constraint' => array(
          'module' => 'bean',
          'delta' => 'filter-reset---access-constraint',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'global_filter-global_filter_2' => array(
          'module' => 'global_filter',
          'delta' => 'global_filter_2',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'bean-filter-reset---location' => array(
          'module' => 'bean',
          'delta' => 'filter-reset---location',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'global_filter-global_filter_4' => array(
          'module' => 'global_filter',
          'delta' => 'global_filter_4',
          'region' => 'sidebar_second',
          'weight' => '-3',
        ),
        'bean-filter-reset---clusters' => array(
          'module' => 'bean',
          'delta' => 'filter-reset---clusters',
          'region' => 'sidebar_second',
          'weight' => '-2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['acc_access_incidents'] = $context;

  return $export;
}
