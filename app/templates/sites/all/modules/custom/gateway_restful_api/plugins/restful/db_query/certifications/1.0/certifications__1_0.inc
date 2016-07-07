<?php

$plugin = array(
  'label' => t('Certifications'),
  'resource' => 'certifications',
  'name' => 'certifications__1_0',
  'data_provider_options' => array(
    'table_name' => 'ag_certifications',
    'id_column' => 'id',
  ),
  'description' => t('Expose Certifications data to the REST API.'),
  'class' => 'RestfulCertificationsResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_public_acess' => TRUE,
  'allow_origin' => $GLOBALS['base_url']
);
