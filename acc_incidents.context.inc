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
        'views--exp-acc-incidents-list' => array(
          'module' => 'views',
          'delta' => '-exp-acc-incidents-list',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-Doo4L0wF0S0VqmLw9L0qLGpqmhYJZbeQ' => array(
          'module' => 'facetapi',
          'delta' => 'Doo4L0wF0S0VqmLw9L0qLGpqmhYJZbeQ',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-V6K0Fi0GFxe5oJI0fGNRT1jmdztjdbb6' => array(
          'module' => 'facetapi',
          'delta' => 'V6K0Fi0GFxe5oJI0fGNRT1jmdztjdbb6',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ne3uJ06pueCixGIbyQS51nZWZ22PlVMM' => array(
          'module' => 'facetapi',
          'delta' => 'ne3uJ06pueCixGIbyQS51nZWZ22PlVMM',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-seY79gLu807VUsyd02zo74uVMyFNDLgi' => array(
          'module' => 'facetapi',
          'delta' => 'seY79gLu807VUsyd02zo74uVMyFNDLgi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-SFtnqYWx1xaDwlCDijMzVIxVVXwkkWk8' => array(
          'module' => 'facetapi',
          'delta' => 'SFtnqYWx1xaDwlCDijMzVIxVVXwkkWk8',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-ZN5ve81z9Z14q79eta6NyubbmmBNM3k3' => array(
          'module' => 'facetapi',
          'delta' => 'ZN5ve81z9Z14q79eta6NyubbmmBNM3k3',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Incidents');
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
  t('Incidents');
  $export['incidents_graphs'] = $context;

  return $export;
}
