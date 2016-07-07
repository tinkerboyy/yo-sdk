<?php
/**
 * @file
 * environment_indicator_feature.default_environment_indicator_environments.inc
 */

/**
 * Implements hook_default_environment_indicator_environment().
 */
function environment_indicator_feature_default_environment_indicator_environment() {
  $export = array();

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'development_environment';
  $environment->name = 'Development Environment';
  $environment->regexurl = 'hallways-dev.fas.gsa.gov';
  $environment->settings = array(
    'color' => '#0784ac',
    'text_color' => '#ffffff',
    'weight' => '0',
    'position' => 'bottom',
    'fixed' => 1,
  );
  $export['development_environment'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'prod_passive';
  $environment->name = 'Prod Passive';
  $environment->regexurl = 'passivehallways.cap.gsa.gov';
  $environment->settings = array(
    'color' => '#fda140',
    'text_color' => '#000000',
    'weight' => '2',
    'position' => 'bottom',
    'fixed' => 1,
  );
  $export['prod_passive'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'test_environment';
  $environment->name = 'Test Environment';
  $environment->regexurl = 'hallways-test.cap.gsa.gov';
  $environment->settings = array(
    'color' => '#22a400',
    'text_color' => '#ffffff',
    'weight' => '1',
    'position' => 'bottom',
    'fixed' => 1,
  );
  $export['test_environment'] = $environment;

  return $export;
}
