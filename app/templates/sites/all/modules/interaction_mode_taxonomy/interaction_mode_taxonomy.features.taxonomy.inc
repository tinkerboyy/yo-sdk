<?php
/**
 * @file
 * interaction_mode_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function interaction_mode_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'interaction_mode' => array(
      'name' => 'Interaction Mode',
      'machine_name' => 'interaction_mode',
      'description' => 'Interaction Mode',
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
