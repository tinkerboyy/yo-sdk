<?php
/**
 * @file
 * cms_hallway_resources_ct.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cms_hallway_resources_ct_taxonomy_default_vocabularies() {
  return array(
    'workbenchhallwaygroups' => array(
      'name' => 'WorkBenchHallwayGroups',
      'machine_name' => 'workbenchhallwaygroups',
      'description' => 'used for work bench moderation',
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
