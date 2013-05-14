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
  $context->name = 'access_incidents';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard/factsheet-access-incidents' => 'dashboard/factsheet-access-incidents',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-incidents-block_1' => array(
          'module' => 'views',
          'delta' => 'incidents-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-incidents-block_8' => array(
          'module' => 'views',
          'delta' => 'incidents-block_8',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-incidents-block_2' => array(
          'module' => 'views',
          'delta' => 'incidents-block_2',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-incidents-block_7' => array(
          'module' => 'views',
          'delta' => 'incidents-block_7',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-incidents-block_3' => array(
          'module' => 'views',
          'delta' => 'incidents-block_3',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-incidents-block_9' => array(
          'module' => 'views',
          'delta' => 'incidents-block_9',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-incidents-block_4' => array(
          'module' => 'views',
          'delta' => 'incidents-block_4',
          'region' => 'content',
          'weight' => '-4',
        ),
        'views-incidents-block_10' => array(
          'module' => 'views',
          'delta' => 'incidents-block_10',
          'region' => 'content',
          'weight' => '-3',
        ),
        'views-incidents-block_5' => array(
          'module' => 'views',
          'delta' => 'incidents-block_5',
          'region' => 'content',
          'weight' => '-2',
        ),
        'views-incidents-block_11' => array(
          'module' => 'views',
          'delta' => 'incidents-block_11',
          'region' => 'content',
          'weight' => '-1',
        ),
        'views-incidents-block_6' => array(
          'module' => 'views',
          'delta' => 'incidents-block_6',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-incidents-block_12' => array(
          'module' => 'views',
          'delta' => 'incidents-block_12',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-incidents-block_13' => array(
          'module' => 'views',
          'delta' => 'incidents-block_13',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-incidents-block_16' => array(
          'module' => 'views',
          'delta' => 'incidents-block_16',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-incidents-block_18' => array(
          'module' => 'views',
          'delta' => 'incidents-block_18',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-incidents-block_17' => array(
          'module' => 'views',
          'delta' => 'incidents-block_17',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-incidents-block_19' => array(
          'module' => 'views',
          'delta' => 'incidents-block_19',
          'region' => 'content',
          'weight' => '6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['access_incidents'] = $context;

  return $export;
}
