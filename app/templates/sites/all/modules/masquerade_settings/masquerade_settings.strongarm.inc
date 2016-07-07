<?php
/**
 * @file
 * masquerade_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function masquerade_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'masquerade_admin_roles';
  $strongarm->value = array(
    3 => '3',
    4 => '4',
    57 => '57',
    59 => '59',
    58 => '58',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
    10 => '10',
    11 => '11',
    12 => '12',
    13 => '13',
    60 => '60',
    14 => '14',
    62 => '62',
    15 => '15',
    61 => '61',
    16 => '16',
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
    21 => '21',
    22 => '22',
    27 => '27',
    29 => '29',
    28 => '28',
    24 => '24',
    26 => '26',
    25 => '25',
    30 => '30',
    32 => '32',
    31 => '31',
    33 => '33',
    35 => '35',
    34 => '34',
    36 => '36',
    38 => '38',
    37 => '37',
    39 => '39',
    41 => '41',
    40 => '40',
    42 => '42',
    44 => '44',
    43 => '43',
    45 => '45',
    47 => '47',
    46 => '46',
    48 => '48',
    50 => '50',
    49 => '49',
    51 => '51',
    53 => '53',
    52 => '52',
    54 => '54',
    56 => '56',
    55 => '55',
    1 => 0,
    64 => 0,
    63 => 0,
    2 => 0,
    23 => 0,
  );
  $export['masquerade_admin_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'masquerade_quick_switches';
  $strongarm->value = array(
    0 => '1523',
  );
  $export['masquerade_quick_switches'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'masquerade_test_user';
  $strongarm->value = 'Demonstration';
  $export['masquerade_test_user'] = $strongarm;

  return $export;
}
