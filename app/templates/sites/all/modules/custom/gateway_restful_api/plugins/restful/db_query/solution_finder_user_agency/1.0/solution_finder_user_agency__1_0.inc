<?php
$plugin = array(
  'label' => t('Solution Finder User Agency'),
  'resource' => 'solutions-finder-user-agency',
  'name' => 'solution_finder_user_agency__1_0',
  'data_provider_options' => array(
    'table_name' => 'tbUserAgencyPreferences',
    'id_column' => 'user_agency',
  ),
  'description' => t('Expose User Agency preferences GET and POST to the REST API.'),
  'class' => 'RestfulUserAgencyResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
