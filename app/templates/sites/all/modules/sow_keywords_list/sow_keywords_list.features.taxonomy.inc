<?php
/**
 * @file
 * sow_keywords_list.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
 
 /**
 *
 * @SWG\Definition(
 *   definition="sow_keyword",
 *   @SWG\Property(
 *     property="id",
 *     type="integer",
 *     description="Id of SOW Keyword"
 *   ),
 *   @SWG\Property(
 *     property="label",
 *     type="string",
 *     description="Name of searched SOW Keyword"
 *   ),
 *   @SWG\Property(
 *     property="self",
 *     type="string",
 *     description="Perma link for sow keyword"
 *   )
 * )
 */

 /**
 * Get a list of entities.
 *
 * @return array
 *   Array of entities, as passed to RestfulEntityBase::viewEntity().
 *
 * @throws RestfulBadRequestException
 *
 * @SWG\Path(
 *   path="/sowkeyword",
 *   @SWG\Get(
 *     tags={"sowkeyword"},
 *     summary="Retrieve all SOW Keywords",
 *     @SWG\Response(
 *       response=200,
 *       description="List of SOW Keywords",
 *       @SWG\Schema(
 *         type="array",
 *           @SWG\Items(ref="#/definitions/sow_keyword")
 *       )
 *     )
 *   )
 * )
 *
 */


function sow_keywords_list_taxonomy_default_vocabularies() {
  return array(
    'sow_keywords_list' => array(
      'name' => 'SOW Keywords List',
      'machine_name' => 'sow_keywords_list',
      'description' => 'SOW Keywords List',
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
