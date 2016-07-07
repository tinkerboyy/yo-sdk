<?php
/**
 * @file
 * cms_hallways_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cms_hallways_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cas_login_context';
  $context->description = 'CAS Login Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'login-info-non-piv' => 'login-info-non-piv',
        'caphallwaysrules' => 'caphallwaysrules',
        'federal-contractor' => 'federal-contractor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cas-login' => array(
          'module' => 'cas',
          'delta' => 'login',
          'region' => 'content',
          'weight' => '15',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CAS Login Context');
  $export['cas_login_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_hero_content';
  $context->description = 'Group Hero Content';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'groups' => 'groups',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-group_hero_content' => array(
          'module' => 'boxes',
          'delta' => 'group_hero_content',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Group Hero Content');
  $export['group_hero_content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hallways_misc_context';
  $context->description = 'Blocks for All pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-header_modal_links' => array(
          'module' => 'boxes',
          'delta' => 'header_modal_links',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'workbench-block' => array(
          'module' => 'workbench',
          'delta' => 'block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'boxes-connect_contribute_footer' => array(
          'module' => 'boxes',
          'delta' => 'connect_contribute_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'views-41cd4cb2780b37273d50fedadfa3826a' => array(
          'module' => 'views',
          'delta' => '41cd4cb2780b37273d50fedadfa3826a',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'views-cms_footer-cms_footer_block' => array(
          'module' => 'views',
          'delta' => 'cms_footer-cms_footer_block',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'boxes-dap_tracking_code' => array(
          'module' => 'boxes',
          'delta' => 'dap_tracking_code',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for All pages');
  $export['hallways_misc_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hallways_quicknavigation';
  $context->description = 'Halways Quick Navigation Dropdown';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~caphallwaysrules' => '~caphallwaysrules',
        '~login-information' => '~login-information',
        '~login-info-non-piv' => '~login-info-non-piv',
        '~user' => '~user',
        '~federal-contractor' => '~federal-contractor',
        '~unauth-contact' => '~unauth-contact',
        '~content/contact-us' => '~content/contact-us',
        '~users/*' => '~users/*',
        '~admin/sorting*' => '~admin/sorting*',
        '~forums*' => '~forums*',
        '~forum*' => '~forum*',
        '~group*' => '~group*',
        '~groups' => '~groups',
        '~group' => '~group',
        '~node/add*' => '~node/add*',
        '~footer-about-us' => '~footer-about-us',
        '~footer-explore' => '~footer-explore',
        '~footer-shared-services' => '~footer-shared-services',
        '~content/techfar-hub-0' => '~content/techfar-hub-0',
        'AdministrativeSupport' => 'AdministrativeSupport',
        'EducationandTraining' => 'EducationandTraining',
        'ITHardware' => 'ITHardware',
        'ITSoftware' => 'ITSoftware',
        'ProfessionalServices' => 'ProfessionalServices',
        'SmallPackageDelivery' => 'SmallPackageDelivery',
        'CleaningSuppliesandChemicals' => 'CleaningSuppliesandChemicals',
        'WorkplaceEnvironment' => 'WorkplaceEnvironment',
        'ToolsandHardware' => 'ToolsandHardware',
        'Telecommunications' => 'Telecommunications',
        'EmployeeRelocation' => 'EmployeeRelocation',
        'Freight' => 'Freight',
        'ITSecurity' => 'ITSecurity',
        'ITServices' => 'ITServices',
        'MotorVehicles' => 'MotorVehicles',
        'Travel' => 'Travel',
        'CardServices' => 'CardServices',
        'TalentDevelopment' => 'TalentDevelopment',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-quick_navigation' => array(
          'module' => 'boxes',
          'delta' => 'quick_navigation',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Halways Quick Navigation Dropdown');
  $export['hallways_quicknavigation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'header_for_misc_pages';
  $context->description = 'Header for Misc Pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'footer-about-us' => 'footer-about-us',
        'footer-explore' => 'footer-explore',
        'footer-shared-services' => 'footer-shared-services',
        'content/techfar-hub-0' => 'content/techfar-hub-0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-header_for_unauth' => array(
          'module' => 'boxes',
          'delta' => 'header_for_unauth',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header for Misc Pages');
  $export['header_for_misc_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage_blocks';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home' => 'home',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-homepage_hero_content' => array(
          'module' => 'boxes',
          'delta' => 'homepage_hero_content',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'boxes-resources_ithardware_content' => array(
          'module' => 'boxes',
          'delta' => 'resources_ithardware_content',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-2e4f4722fb7d45fb059391bc8edd4ec0' => array(
          'module' => 'views',
          'delta' => '2e4f4722fb7d45fb059391bc8edd4ec0',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-homepage_hallways_block-block' => array(
          'module' => 'views',
          'delta' => 'homepage_hallways_block-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'solution_finder-solution_finder' => array(
          'module' => 'solution_finder',
          'delta' => 'solution_finder',
          'region' => 'content_bottom_leftside',
          'weight' => '-9',
        ),
        'boxes-homepage_resources' => array(
          'module' => 'boxes',
          'delta' => 'homepage_resources',
          'region' => 'content_bottom_rightside',
          'weight' => '-10',
        ),
        'views-164aaadaadc30167502ab90bfda81843' => array(
          'module' => 'views',
          'delta' => '164aaadaadc30167502ab90bfda81843',
          'region' => 'content_bottom_right',
          'weight' => '-5',
        ),
        'boxes-homepage_lca_content' => array(
          'module' => 'boxes',
          'delta' => 'homepage_lca_content',
          'region' => 'top_footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['homepage_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lcabarblock_context';
  $context->description = 'LCA Bar Block for Different Pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~login-information' => '~login-information',
        '~caphallwaysrules' => '~caphallwaysrules',
        '~<front>' => '~<front>',
        '~AdministrativeSupport' => '~AdministrativeSupport',
        '~EducationandTraining' => '~EducationandTraining',
        '~ITHardware' => '~ITHardware',
        '~ITSoftware' => '~ITSoftware',
        '~ProfessionalServices' => '~ProfessionalServices',
        '~SmallPackageDelivery' => '~SmallPackageDelivery',
        '~content/contact-us' => '~content/contact-us',
        '~admin/sorting*' => '~admin/sorting*',
        '~ToolsandHardware' => '~ToolsandHardware',
        '~WorkplaceEnvironment' => '~WorkplaceEnvironment',
        '~CleaningSuppliesandChemicals' => '~CleaningSuppliesandChemicals',
        '~Telecommunications' => '~Telecommunications',
        '~EmployeeRelocation' => '~EmployeeRelocation',
        '~Freight' => '~Freight',
        '~ITSecurity' => '~ITSecurity',
        '~ITServices' => '~ITServices',
        '~MotorVehicles' => '~MotorVehicles',
        '~Travel' => '~Travel',
        '~CardServices' => '~CardServices',
        '~forums*' => '~forums*',
        '~forum*' => '~forum*',
        '~group*' => '~group*',
        '~groups' => '~groups',
        '~user*' => '~user*',
        '~users*' => '~users*',
        '~node/add*' => '~node/add*',
        '~unauth-contact' => '~unauth-contact',
        '~login-info-non-piv' => '~login-info-non-piv',
        '~federal-contractor' => '~federal-contractor',
        '~TalentDevelopment' => '~TalentDevelopment',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-header_for_unauth' => array(
          'module' => 'boxes',
          'delta' => 'header_for_unauth',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('LCA Bar Block for Different Pages');
  $export['lcabarblock_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lcabox_hallways_context';
  $context->description = 'LCA BOX for Hallways Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'AdministrativeSupport' => 'AdministrativeSupport',
        'EducationandTraining' => 'EducationandTraining',
        'ITHardware' => 'ITHardware',
        'ITSoftware' => 'ITSoftware',
        'ProfessionalServices' => 'ProfessionalServices',
        'SmallPackageDelivery' => 'SmallPackageDelivery',
        'CleaningSuppliesandChemicals' => 'CleaningSuppliesandChemicals',
        'WorkplaceEnvironment' => 'WorkplaceEnvironment',
        'ToolsandHardware' => 'ToolsandHardware',
        'Telecommunications' => 'Telecommunications',
        'EmployeeRelocation' => 'EmployeeRelocation',
        'Freight' => 'Freight',
        'ITSecurity' => 'ITSecurity',
        'ITServices' => 'ITServices',
        'MotorVehicles' => 'MotorVehicles',
        'Travel' => 'Travel',
        'CardServices' => 'CardServices',
        'groups' => 'groups',
        'TalentDevelopment' => 'TalentDevelopment',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-lcabar_hallways' => array(
          'module' => 'boxes',
          'delta' => 'lcabar_hallways',
          'region' => 'bottom_featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('LCA BOX for Hallways Context');
  $export['lcabox_hallways_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'masquerade';
  $context->description = 'Masquerade';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
    'user' => array(
      'values' => array(
        'Gateway Author' => 'Gateway Author',
        'Gateway Moderator' => 'Gateway Moderator',
        'Gateway Publisher' => 'Gateway Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Masquerade');
  $export['masquerade'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pivcardcheck_block_context';
  $context->description = 'PivCardCheck Block Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~login-information' => '~login-information',
        '~login-info-non-piv' => '~login-info-non-piv',
        '~stantest' => '~stantest',
        '~federal-contractor' => '~federal-contractor',
      ),
    ),
    'user' => array(
      'values' => array(
        'Gateway Author' => 'Gateway Author',
        'Gateway Moderator' => 'Gateway Moderator',
        'Gateway Publisher' => 'Gateway Publisher',
        'HW Admin Support Author' => 'HW Admin Support Author',
        'HW Admin Support Moderator' => 'HW Admin Support Moderator',
        'HW Admin Support Publisher' => 'HW Admin Support Publisher',
        'HW Card Services Author' => 'HW Card Services Author',
        'HW Card Services Moderator' => 'HW Card Services Moderator',
        'HW Card Services Publisher' => 'HW Card Services Publisher',
        'HW Cleaning Supplies Author' => 'HW Cleaning Supplies Author',
        'HW Cleaning Supplies Moderator' => 'HW Cleaning Supplies Moderator',
        'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
        'HW Education and Training Author' => 'HW Education and Training Author',
        'HW Education and Training Moderator' => 'HW Education and Training Moderator',
        'HW Education and Training Publisher' => 'HW Education and Training Publisher',
        'HW Employee Relocation Author' => 'HW Employee Relocation Author',
        'HW Employee Relocation Moderator' => 'HW Employee Relocation Moderator',
        'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
        'HW Freight Author' => 'HW Freight Author',
        'HW Freight Moderator' => 'HW Freight Moderator',
        'HW Freight Publisher' => 'HW Freight Publisher',
        'HW IT Hardware Author' => 'HW IT Hardware Author',
        'HW IT Hardware Moderator' => 'HW IT Hardware Moderator',
        'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
        'HW IT Security Author' => 'HW IT Security Author',
        'HW IT Security Moderator' => 'HW IT Security Moderator',
        'HW IT Security Publisher' => 'HW IT Security Publisher',
        'HW IT Services Author' => 'HW IT Services Author',
        'HW IT Services Moderator' => 'HW IT Services Moderator',
        'HW IT Services Publisher' => 'HW IT Services Publisher',
        'HW IT Software Author' => 'HW IT Software Author',
        'HW IT Software Moderator' => 'HW IT Software Moderator',
        'HW IT Software Publisher' => 'HW IT Software Publisher',
        'HW Motor Vehicles Author' => 'HW Motor Vehicles Author',
        'HW Motor Vehicles Moderator' => 'HW Motor Vehicles Moderator',
        'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
        'HW Professional Services Author' => 'HW Professional Services Author',
        'HW Professional Services Moderator' => 'HW Professional Services Moderator',
        'HW Professional Services Publisher' => 'HW Professional Services Publisher',
        'HW Small Package Delivery Author' => 'HW Small Package Delivery Author',
        'HW Small Package Delivery Moderator' => 'HW Small Package Delivery Moderator',
        'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
        'HW Talent Development Author' => 'HW Talent Development Author',
        'HW Talent Development Moderator' => 'HW Talent Development Moderator',
        'HW Talent Development Publisher' => 'HW Talent Development Publisher',
        'HW Telecommunications Author' => 'HW Telecommunications Author',
        'HW Telecommunications Moderator' => 'HW Telecommunications Moderator',
        'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
        'HW Tools Hardware Author' => 'HW Tools Hardware Author',
        'HW Tools Hardware Moderator' => 'HW Tools Hardware Moderator',
        'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
        'HW Travel Author' => 'HW Travel Author',
        'HW Travel Moderator' => 'HW Travel Moderator',
        'HW Travel Publisher' => 'HW Travel Publisher',
        'HW Workplace Environment Author' => 'HW Workplace Environment Author',
        'HW Workplace Environment Moderator' => 'HW Workplace Environment Moderator',
        'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
        'SOW Librarian' => 'SOW Librarian',
        'Site Manager' => 'Site Manager',
        'Solution Manager' => 'Solution Manager',
        'Solutions Finder Admin' => 'Solutions Finder Admin',
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('PivCardCheck Block Context');
  $export['pivcardcheck_block_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-administrative-support-context';
  $context->description = 'Admin Support Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-administrative-support' => 'admin/sorting-administrative-support',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Admin Support Publisher' => 'HW Admin Support Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-d5661c6d85890a1dc9a769c7076129f3' => array(
          'module' => 'views',
          'delta' => 'd5661c6d85890a1dc9a769c7076129f3',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Support Context Sorting');
  $export['sorting-administrative-support-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-cardservices-context';
  $context->description = 'CardServices Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-cardservices' => 'admin/sorting-cardservices',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Card Services Publisher' => 'HW Card Services Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-97d190cd77fa9ff93d3c9a9dc5c9445d' => array(
          'module' => 'views',
          'delta' => '97d190cd77fa9ff93d3c9a9dc5c9445d',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CardServices Context Sorting');
  $export['sorting-cardservices-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-cleaning-supplies-context';
  $context->description = 'Sorting for CleaningSuppliesandChemicals';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-cleaningsuppliesandchemicals' => 'admin/sorting-cleaningsuppliesandchemicals',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Cleaning Supplies Publisher' => 'HW Cleaning Supplies Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-4c0c21266b3511ba2f2b6c06f3773000' => array(
          'module' => 'views',
          'delta' => '4c0c21266b3511ba2f2b6c06f3773000',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sorting for CleaningSuppliesandChemicals');
  $export['sorting-cleaning-supplies-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-educationandtraining-context';
  $context->description = 'Education and Training Sorting Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-educationandtraining' => 'admin/sorting-educationandtraining',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Education and Training Publisher' => 'HW Education and Training Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-9b73ad06b58b67fe246023b05b6aa3d4' => array(
          'module' => 'views',
          'delta' => '9b73ad06b58b67fe246023b05b6aa3d4',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Education and Training Sorting Context');
  $export['sorting-educationandtraining-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-employeerelocation-context';
  $context->description = 'EmployeeRelocation Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-employeerelocation' => 'admin/sorting-employeerelocation',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Employee Relocation Publisher' => 'HW Employee Relocation Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-8fd424c8e6646c01a1feb09af57ab3dd' => array(
          'module' => 'views',
          'delta' => '8fd424c8e6646c01a1feb09af57ab3dd',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('EmployeeRelocation Context Sorting');
  $export['sorting-employeerelocation-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-facilities-maintenance-services';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-facilities-maintenance-services' => 'admin/sorting-facilities-maintenance-services',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Facilities Maintenance Services Publisher' => 'HW Facilities Maintenance Services Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-5871dc456c1845faf83af720c67f40e0' => array(
          'module' => 'views',
          'delta' => '5871dc456c1845faf83af720c67f40e0',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['sorting-facilities-maintenance-services'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-freight-context';
  $context->description = 'Freight Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-freight' => 'admin/sorting-freight',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Freight Publisher' => 'HW Freight Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ef4fc2c020ca99f10535c1fa46d31dbf' => array(
          'module' => 'views',
          'delta' => 'ef4fc2c020ca99f10535c1fa46d31dbf',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Freight Context Sorting');
  $export['sorting-freight-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-it-hardware';
  $context->description = 'IT Hardware Sorting Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-it-hardware' => 'admin/sorting-it-hardware',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW IT Hardware Publisher' => 'HW IT Hardware Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7370b344d1494e2ee277189bb1de8246' => array(
          'module' => 'views',
          'delta' => '7370b344d1494e2ee277189bb1de8246',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('IT Hardware Sorting Context');
  $export['sorting-it-hardware'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-it-software-context';
  $context->description = 'IT Software Sorting Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-it-software' => 'admin/sorting-it-software',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW IT Software Publisher' => 'HW IT Software Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-246fb6d1ef57fba541875e03b253d0fb' => array(
          'module' => 'views',
          'delta' => '246fb6d1ef57fba541875e03b253d0fb',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('IT Software Sorting Context');
  $export['sorting-it-software-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-itsecurity-context';
  $context->description = 'itsecurity Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-itsecurity' => 'admin/sorting-itsecurity',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW IT Security Publisher' => 'HW IT Security Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-e55fb6b873ff63e3e654f9059b39de57' => array(
          'module' => 'views',
          'delta' => 'e55fb6b873ff63e3e654f9059b39de57',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('itsecurity Context Sorting');
  $export['sorting-itsecurity-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-itservices-context';
  $context->description = 'ITServices Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-itservices' => 'admin/sorting-itservices',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW IT Services Publisher' => 'HW IT Services Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-b0ed8e3575dbc20975ea7850cf45649d' => array(
          'module' => 'views',
          'delta' => 'b0ed8e3575dbc20975ea7850cf45649d',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ITServices Context Sorting');
  $export['sorting-itservices-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-motorvehicles-context';
  $context->description = 'MotorVehicles Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-motorvehicles' => 'admin/sorting-motorvehicles',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Motor Vehicles Publisher' => 'HW Motor Vehicles Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-68ec04b4b5d47bbf528892caca323196' => array(
          'module' => 'views',
          'delta' => '68ec04b4b5d47bbf528892caca323196',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('MotorVehicles Context Sorting');
  $export['sorting-motorvehicles-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-professionalservices-context';
  $context->description = 'Professional Services Sorting Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-professionalservices' => 'admin/sorting-professionalservices',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Professional Services Publisher' => 'HW Professional Services Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-d85fe015bf86a5dd2c5421fe98c9919f' => array(
          'module' => 'views',
          'delta' => 'd85fe015bf86a5dd2c5421fe98c9919f',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Professional Services Sorting Context');
  $export['sorting-professionalservices-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-security-protection';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-security-protection' => 'admin/sorting-security-protection',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Security Protection Publisher' => 'HW Security Protection Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-42eaa3984e21df5ea51c4a144463455f' => array(
          'module' => 'views',
          'delta' => '42eaa3984e21df5ea51c4a144463455f',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['sorting-security-protection'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-smallpackagedelivery-context';
  $context->description = 'Small Package Delivery Sorting Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-smallpackagedelivery' => 'admin/sorting-smallpackagedelivery',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Small Package Delivery Publisher' => 'HW Small Package Delivery Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-49cb241e160319eeef25c890001684ef' => array(
          'module' => 'views',
          'delta' => '49cb241e160319eeef25c890001684ef',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Small Package Delivery Sorting Context');
  $export['sorting-smallpackagedelivery-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-telecommunications-context';
  $context->description = 'Telecommunications Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-telecommunications' => 'admin/sorting-telecommunications',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Telecommunications Publisher' => 'HW Telecommunications Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-8b2d196cea7a3d829e2f5833f259db66' => array(
          'module' => 'views',
          'delta' => '8b2d196cea7a3d829e2f5833f259db66',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Telecommunications Context Sorting');
  $export['sorting-telecommunications-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-tools-hardware-context';
  $context->description = 'Sorting for Tools and Hardware';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-toolsandhardware' => 'admin/sorting-toolsandhardware',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Tools Hardware Publisher' => 'HW Tools Hardware Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f9de55f673f35777b6d524fde004eb8b' => array(
          'module' => 'views',
          'delta' => 'f9de55f673f35777b6d524fde004eb8b',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sorting for Tools and Hardware');
  $export['sorting-tools-hardware-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-travel-context';
  $context->description = 'Travel Context Sorting';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-travel' => 'admin/sorting-travel',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Travel Publisher' => 'HW Travel Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ab534ccf1fa35e94c3bad72f6ea0e404' => array(
          'module' => 'views',
          'delta' => 'ab534ccf1fa35e94c3bad72f6ea0e404',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Travel Context Sorting');
  $export['sorting-travel-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sorting-workplaceenvironment-context';
  $context->description = 'Sorting for Workplace Environment';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sorting-workplaceenvironment' => 'admin/sorting-workplaceenvironment',
      ),
    ),
    'user' => array(
      'values' => array(
        'HW Workplace Environment Publisher' => 'HW Workplace Environment Publisher',
        'Site Manager' => 'Site Manager',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-0b70f99bbb75ef60965c631e5355baf0' => array(
          'module' => 'views',
          'delta' => '0b70f99bbb75ef60965c631e5355baf0',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sorting for Workplace Environment');
  $export['sorting-workplaceenvironment-context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'unauth_header_context';
  $context->description = 'UNAuth Header Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'unauth-contact' => 'unauth-contact',
        'login-information' => 'login-information',
        'content/contact-us' => 'content/contact-us',
        'federal-contractor' => 'federal-contractor',
        'login-info-non-piv' => 'login-info-non-piv',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-header_for_unauth' => array(
          'module' => 'boxes',
          'delta' => 'header_for_unauth',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('UNAuth Header Context');
  $export['unauth_header_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile_context';
  $context->description = 'User Profile Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user*' => 'user*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-user_hero_content' => array(
          'module' => 'boxes',
          'delta' => 'user_hero_content',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'boxes-lcabar_hallways' => array(
          'module' => 'boxes',
          'delta' => 'lcabar_hallways',
          'region' => 'bottom_featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User Profile Context');
  $export['user_profile_context'] = $context;

  return $export;
}
