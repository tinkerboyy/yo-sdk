<?php
/**
 * @file
 * cron_job.ultimate_cron.inc
 */

/**
 * Implements hook_default_ultimate_cron_job().
 */
function cron_job_default_ultimate_cron_job() {
  $export = array();

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'article_expiration_notifications_cron';
  $job->title = 'Default cron handler';
  $job->settings = array(
    'scheduler' => array(
      'name' => '',
      'simple' => array(
        'rules' => array(
          0 => '0+@ 0 * * *',
        ),
      ),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
    'settings' => array(
      'general' => array(),
      'poorman' => array(),
      'queue' => array(),
    ),
  );
  $export['article_expiration_notifications_cron'] = $job;

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'browscap_cron';
  $job->title = 'Default cron handler';
  $job->settings = array(
    'scheduler' => array(
      'name' => '',
      'simple' => array(
        'rules' => array(
          0 => '0+@ */3 * * *',
        ),
      ),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
    'settings' => array(
      'general' => array(),
      'poorman' => array(),
      'queue' => array(),
    ),
  );
  $export['browscap_cron'] = $job;

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'custom_expire_rules_cron';
  $job->title = 'Default cron handler';
  $job->settings = array(
    'scheduler' => array(
      'name' => '',
      'simple' => array(
        'rules' => array(
          0 => '0+@ */12 * * *',
        ),
      ),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
    'settings' => array(
      'general' => array(),
      'poorman' => array(),
      'queue' => array(),
    ),
  );
  $export['custom_expire_rules_cron'] = $job;

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'dblog_cron';
  $job->title = 'Remove expired log messages and flood control events';
  $job->settings = array(
    'scheduler' => array(
      'name' => '',
      'simple' => array(
        'rules' => array(
          0 => '0+@ */3 * * *',
        ),
      ),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
    'settings' => array(
      'general' => array(),
      'poorman' => array(),
      'queue' => array(),
    ),
  );
  $export['dblog_cron'] = $job;

  return $export;
}
