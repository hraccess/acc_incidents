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
        'acc_incidents:map' => 'acc_incidents:map',
        'acc_incidents:master' => 'acc_incidents:master',
        'acc_incidents:table' => 'acc_incidents:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-5BBA78evOCBcvX5xyUAJKUpwSuJ4Xlhd' => array(
          'module' => 'facetapi',
          'delta' => '5BBA78evOCBcvX5xyUAJKUpwSuJ4Xlhd',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-LMp6pljOgavG86Bli1wANx1T9y6GZP3T' => array(
          'module' => 'facetapi',
          'delta' => 'LMp6pljOgavG86Bli1wANx1T9y6GZP3T',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-TgQvxHIbh2oxH10WqhJYHHFXebhsgebQ' => array(
          'module' => 'facetapi',
          'delta' => 'TgQvxHIbh2oxH10WqhJYHHFXebhsgebQ',
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
        'facetapi-l8bSwM5fB9aSAEx3EaM1Id7z7ZJAGm3m' => array(
          'module' => 'facetapi',
          'delta' => 'l8bSwM5fB9aSAEx3EaM1Id7z7ZJAGm3m',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-l99as1r0pDoRtecxy4EsaAVWZ2gaSkVc' => array(
          'module' => 'facetapi',
          'delta' => 'l99as1r0pDoRtecxy4EsaAVWZ2gaSkVc',
          'region' => 'sidebar_first',
          'weight' => '-2',
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
        'views-acc_incidents_graphs-block_1' => array(
          'module' => 'views',
          'delta' => 'acc_incidents_graphs-block_1',
          'region' => 'content',
          'weight' => '-67',
        ),
        'views-5f7317aeb0e74c85abcc1c76050d3095' => array(
          'module' => 'views',
          'delta' => '5f7317aeb0e74c85abcc1c76050d3095',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-db4a368da0f1f100e80ee4db9b9a82a5' => array(
          'module' => 'views',
          'delta' => 'db4a368da0f1f100e80ee4db9b9a82a5',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-5ca52657a0e73185e1b51a3dfd0dbbb0' => array(
          'module' => 'views',
          'delta' => '5ca52657a0e73185e1b51a3dfd0dbbb0',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-be5e6832b362e7e35c6f2efb71fcad72' => array(
          'module' => 'views',
          'delta' => 'be5e6832b362e7e35c6f2efb71fcad72',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-76bf0758a25b2bb9ae5f2142551f5f9e' => array(
          'module' => 'views',
          'delta' => '76bf0758a25b2bb9ae5f2142551f5f9e',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-a911264ed4ec29a2d397552630aecaa3' => array(
          'module' => 'views',
          'delta' => 'a911264ed4ec29a2d397552630aecaa3',
          'region' => 'content',
          'weight' => '-4',
        ),
        'views-43a77ae8e557abb5fd69dc0ea6cfc653' => array(
          'module' => 'views',
          'delta' => '43a77ae8e557abb5fd69dc0ea6cfc653',
          'region' => 'content',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_graphs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_list';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:list' => 'acc_incidents:list',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_map';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:map' => 'acc_incidents:map',
        'acc_incidents:master' => 'acc_incidents:master',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_incidents-map' => array(
          'module' => 'views',
          'delta' => '-exp-acc_incidents-map',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_map'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acc_incidents_table';
  $context->description = '';
  $context->tag = 'Access Incidents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'acc_incidents:table' => 'acc_incidents:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-acc_incidents-table' => array(
          'module' => 'views',
          'delta' => '-exp-acc_incidents-table',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Incidents');
  $export['acc_incidents_table'] = $context;

  return $export;
}
