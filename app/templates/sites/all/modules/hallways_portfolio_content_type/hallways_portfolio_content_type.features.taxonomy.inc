<?php
/**
 * @file
 * hallways_portfolio_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hallways_portfolio_content_type_taxonomy_default_vocabularies() {
  return array(
    'categoryclassification' => array(
      'name' => 'CategoryClassification',
      'machine_name' => 'categoryclassification',
      'description' => 'Taxonomy to classify a Category as a Hallway or Gateway',
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
