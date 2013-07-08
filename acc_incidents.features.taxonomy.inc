<?php
/**
 * @file
 * acc_incidents.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function acc_incidents_taxonomy_default_vocabularies() {
  return array(
    'type_of_aid_workers' => array(
      'name' => 'Type of aid workers',
      'machine_name' => 'type_of_aid_workers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
