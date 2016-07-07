<?php
/**
 * @file
 * forum_content_feature.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function forum_content_feature_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 842,
  'title' => 'Structured methods of collaboration ',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '27ae5f0b-22b6-4a08-95aa-897db3025885',
  'ds_switch' => '',
  'type' => 'forum',
  'language' => 'und',
  'created' => 1425267275,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '84d7ddff-3d9a-4980-81b1-6b2411498f6a',
  'revision_uid' => 842,
  'taxonomy_forums' => array(
    'und' => array(
      0 => array(
        'tid' => 932,
        'uuid' => '616ba00c-dd09-49b7-933b-41c785eb032e',
      ),
    ),
  ),
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Structured methods of collaboration encourage <a href="https://en.wikipedia.org/wiki/Introspection" title="Introspection">introspection</a> of behavior and communication.<sup><a href="https://en.wikipedia.org/wiki/Collaboration#cite_note-spencelecture-6">[6]</a></sup> These methods <em>specifically</em> aim to increase the success of teams as they engage in collaborative <a href="https://en.wikipedia.org/wiki/Problem_solving" title="Problem solving">problem solving</a>. Forms, rubrics, charts and graphs are useful in these situations to <a class="mw-redirect" href="https://en.wikipedia.org/wiki/Objectivity_(journalism)" title="Objectivity (journalism)">objectively</a> document <a href="https://en.wikipedia.org/wiki/Personality_psychology" title="Personality psychology">personal traits</a> with the goal of improving performance in current and future projects.</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Structured methods of collaboration encourage introspection of behavior and communication.<sup>[6]</sup> These methods <em>specifically</em> aim to increase the success of teams as they engage in collaborative problem solving. Forms, rubrics, charts and graphs are useful in these situations to objectively document personal traits with the goal of improving performance in current and future projects.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Post',
      1 => 'sioct:BoardPost',
    ),
    'taxonomy_forums' => array(
      'predicates' => array(
        0 => 'sioc:has_container',
      ),
      'type' => 'rel',
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
  'last_comment_name' => NULL,
  'last_comment_uid' => 842,
  'comment_count' => 0,
  'name' => 'Gateway Site Manager',
  'picture' => 0,
  'data' => 'a:6:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"contact";i:1;}',
  'forum_tid' => 932,
  'date' => '2015-03-01 19:34:35 -0800',
);
  return $nodes;
}
