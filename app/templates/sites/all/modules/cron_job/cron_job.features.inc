<?php
/**
 * @file
 * cron_job.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cron_job_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ultimate_cron" && $api == "ultimate_cron") {
    return array("version" => "3");
  }
}
