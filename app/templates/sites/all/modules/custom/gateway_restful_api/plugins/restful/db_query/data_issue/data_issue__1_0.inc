<?php
$plugin = array(
  'label' => t('Data Issue'),
  'resource' => 'data-issue',
  'name' => 'data_issue__1_0',
  'data_provider_options' => array(
    'table_name' => 'tbDataIssues',
    'id_column' => 'id',
  ),
  'description' => t('Expose data issues GET and POST to the REST API.'),
  'class' => 'RestfulDataIssueResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
