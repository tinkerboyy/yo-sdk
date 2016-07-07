<?php
/**
 * @file
 * techfarhub_podcast.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function techfarhub_podcast_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|podcast_article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'podcast_article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
      ),
      'right' => array(
        1 => 'field_podcast_description',
        2 => 'field_podcast_group',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_podcast_description' => 'right',
      'field_podcast_group' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|podcast_article|default'] = $ds_layout;

  return $export;
}
