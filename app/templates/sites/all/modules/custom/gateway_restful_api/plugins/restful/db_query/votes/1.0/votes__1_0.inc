<?php

$plugin = array(
  'label' => t('Votes'),
  'resource' => 'votes',
  'name' => 'votes__1_0',
  'data_provider_options' => array(
    'table_name' => 'ag_votes',
    'id_column' => 'id',
  ),
  'description' => t('Tracks user votes on items in the Acquisition Gateway'),
  'class' => 'RestfulVotesResource',
  'authentication_types' => array('ag_cookie'),
  'authentication_optional' => FALSE,
  'allow_origin' => $GLOBALS['base_url']
);
