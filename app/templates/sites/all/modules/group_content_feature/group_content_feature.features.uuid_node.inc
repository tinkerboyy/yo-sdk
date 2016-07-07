<?php
/**
 * @file
 * group_content_feature.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function group_content_feature_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 867,
  'title' => 'Acquisition Gateway Group',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '389e4db5-ee5f-453a-893b-91bb054732c9',
  'type' => 'group',
  'language' => 'und',
  'created' => 1425011943,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f5528bf9-2d92-4943-89d8-1b5a0880cb58',
  'revision_uid' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The primary group for the Acquisition Gateway portal.</p>
',
        'summary' => '',
        'format' => 'filtered_html',
      ),
    ),
  ),
  'group_group' => array(
    'und' => array(
      0 => array(
        'value' => 1,
      ),
    ),
  ),
  'field_public_private' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => 0,
  'last_comment_name' => '',
  'last_comment_uid' => 57,
  'comment_count' => 0,
  'name' => 'sands.hakimi',
  'picture' => 0,
  'data' => 'a:8:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"contact";i:1;s:5:"block";a:1:{s:5:"views";a:1:{s:24:"portfolio_vertical-block";i:1;}}s:7:"overlay";i:1;}',
  'date' => '2015-02-26 23:39:03 -0500',
);
  return $nodes;
}
