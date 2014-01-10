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
  $context->name = 'acc_incidents';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:list' => 'acc_incidents:list',
        'acc_incidents:master' => 'acc_incidents:master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_incidents-list' => array(
          'module' => 'views',
          'delta' => '-exp-acc_incidents-list',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-5BBA78evOCBcvX5xyUAJKUpwSuJ4Xlhd' => array(
          'module' => 'facetapi',
          'delta' => '5BBA78evOCBcvX5xyUAJKUpwSuJ4Xlhd',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-LMp6pljOgavG86Bli1wANx1T9y6GZP3T' => array(
          'module' => 'facetapi',
          'delta' => 'LMp6pljOgavG86Bli1wANx1T9y6GZP3T',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-UB180i8VlpBIoeKhyiFoRbvumb1zWxeX' => array(
          'module' => 'facetapi',
          'delta' => 'UB180i8VlpBIoeKhyiFoRbvumb1zWxeX',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-60a95va1KLIPSiw8z1w6OvH0ovd1NulW' => array(
          'module' => 'facetapi',
          'delta' => '60a95va1KLIPSiw8z1w6OvH0ovd1NulW',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-UA7MhPZ0nb2NI8kgFzmaHnI4Y9iTOUM0' => array(
          'module' => 'facetapi',
          'delta' => 'UA7MhPZ0nb2NI8kgFzmaHnI4Y9iTOUM0',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-IJmnbuu4mkmMNS4bDN3oexHiPBqOG2qJ' => array(
          'module' => 'facetapi',
          'delta' => 'IJmnbuu4mkmMNS4bDN3oexHiPBqOG2qJ',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_graphs';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:graphs' => 'acc_incidents:graphs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-acc_incidents_graphs-graph_by_type' => array(
          'module' => 'views',
          'delta' => 'acc_incidents_graphs-graph_by_type',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-acc_incidents_graphs-graph_by_sector' => array(
          'module' => 'views',
          'delta' => 'acc_incidents_graphs-graph_by_sector',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-acc_incidents_graphs-graph_by_date' => array(
          'module' => 'views',
          'delta' => 'acc_incidents_graphs-graph_by_date',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-acc_incidents_graphs-graph_by_location' => array(
          'module' => 'views',
          'delta' => 'acc_incidents_graphs-graph_by_location',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-acc_incidents_graphs-block_1' => array(
          'module' => 'views',
          'delta' => 'acc_incidents_graphs-block_1',
          'region' => 'content',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_graphs'] = $context;

  return $export;
}
