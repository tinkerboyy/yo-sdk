<?php
/**
 * @file
 * cms_video_content_type.default_video_embed_styles.inc
 */

/**
 * Implements hook_default_video_embed_styles().
 */
function cms_video_content_type_default_video_embed_styles() {
  $export = array();

  $video_embed_style = new stdClass();
  $video_embed_style->disabled = FALSE; /* Edit this to true to make a default video_embed_style disabled initially */
  $video_embed_style->api_version = 1;
  $video_embed_style->name = 'custom';
  $video_embed_style->title = 'Custom';
  $video_embed_style->data = array(
    'brightcove' => array(
      'width' => '640',
      'height' => '360',
    ),
    'facebook' => array(
      'height' => '360',
      'width' => '640',
    ),
    'youtube' => array(
      'width' => '1200',
      'height' => '600',
      'theme' => 'dark',
      'autoplay' => 0,
      'vq' => 'large',
      'rel' => 0,
      'showinfo' => 1,
      'modestbranding' => 0,
      'iv_load_policy' => '1',
      'controls' => '1',
      'autohide' => '2',
    ),
    'vimeo' => array(
      'width' => '640',
      'height' => '360',
      'color' => '00adef',
      'portrait' => 1,
      'title' => 1,
      'byline' => 1,
      'autoplay' => 0,
      'loop' => 0,
      'froogaloop' => 0,
    ),
    'data__active_tab' => 'edit-data-youtube',
  );
  $export['custom'] = $video_embed_style;

  return $export;
}
