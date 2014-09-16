<?php
/**
 * @file
 * acc_incident.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function acc_incident_context_default_contexts() {
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
        'acc_incidents:map' => 'acc_incidents:map',
        'acc_incidents:master' => 'acc_incidents:master',
        'acc_incidents:table' => 'acc_incidents:table',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-J2JMN70I18WlrnhGNCnWM4QtA4wG6U4Y' => array(
          'module' => 'facetapi',
          'delta' => 'J2JMN70I18WlrnhGNCnWM4QtA4wG6U4Y',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-9ue2gd0P70KkewXSxkuQUU1Pv0oRRaYn' => array(
          'module' => 'facetapi',
          'delta' => '9ue2gd0P70KkewXSxkuQUU1Pv0oRRaYn',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-Mr0B15bSiepOvJtZbHylJlwcGWzmSeSv' => array(
          'module' => 'facetapi',
          'delta' => 'Mr0B15bSiepOvJtZbHylJlwcGWzmSeSv',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-F1CiCc1Ry0NeapgWln06pCPPML2WugMh' => array(
          'module' => 'facetapi',
          'delta' => 'F1CiCc1Ry0NeapgWln06pCPPML2WugMh',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-650OMpFHUPiv0OafiKob7TJUhRqTs1py' => array(
          'module' => 'facetapi',
          'delta' => '650OMpFHUPiv0OafiKob7TJUhRqTs1py',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-UW8RIqVz39aDhL0I88nzx0C1tAptyJEV' => array(
          'module' => 'facetapi',
          'delta' => 'UW8RIqVz39aDhL0I88nzx0C1tAptyJEV',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-U44yw0wbcDoEFHhcEhyCiC6axMYd1pBd' => array(
          'module' => 'facetapi',
          'delta' => 'U44yw0wbcDoEFHhcEhyCiC6axMYd1pBd',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-GUF0nsCIijJFh5JZadxAw5CLTCEDebu2' => array(
          'module' => 'facetapi',
          'delta' => 'GUF0nsCIijJFh5JZadxAw5CLTCEDebu2',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-xvQwI7NV9AlX2s4vcZC9WU1wi6pK6ofZ' => array(
          'module' => 'facetapi',
          'delta' => 'xvQwI7NV9AlX2s4vcZC9WU1wi6pK6ofZ',
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
        'views-acc_incident_graphs-block_2' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_2',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-acc_incident_graphs-block_1' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_1',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-acc_incident_graphs-block_3' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_3',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-acc_incident_graphs-block_4' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_4',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-acc_incident_graphs-block_5' => array(
          'module' => 'views',
          'delta' => 'acc_incident_graphs-block_5',
          'region' => 'content',
          'weight' => '6',
        ),
        'views-d9cede631cd7c771b18188cc5ee4a307' => array(
          'module' => 'views',
          'delta' => 'd9cede631cd7c771b18188cc5ee4a307',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-698c8d70463be9d041890d880332ecb4' => array(
          'module' => 'views',
          'delta' => '698c8d70463be9d041890d880332ecb4',
          'region' => 'content',
          'weight' => '2',
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
