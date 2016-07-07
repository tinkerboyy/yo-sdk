<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulHallwaysResource extends AGRestfulEntityBaseNode {

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
  *
  * @SWG\Definition(
  *   definition="HallwayPortfolio",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="Id of user"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Display name of the hallway portfolio"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="permalink to the hallway-historical with a specific id"
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="object",
  *     description="Body text of hallway portfolio"
  *   ),
  *   @SWG\Property(
  *     property="status",
  *     type="string",
  *     description="Id of user"
  *   ),
  *   @SWG\Property(
  *     property="portfolioimage",
  *     type="array",
  *     description="Portfolioimage",
  *     ref = "#/definitions/portfolioimage"
  *   ),
  *   @SWG\Property(
  *     property="portfoliotagline",
  *     type="object",
  *     description="Display portfolio tagline"
  *   ),
  *   @SWG\Property(
  *     property="portfolioheadertextareanew",
  *     type="object",
  *     description="Portfolio header test area new"
  *   ),
  *   @SWG\Property(
  *     property="portfolioarticleembed",
  *     type="string",
  *     description="PortfolioArticleEmbed"
  *   ),
  *   @SWG\Property(
  *     property="portfolioaction",
  *     type="string",
  *     description="Display portfolio action"
  *   ),
  *   @SWG\Property(
  *     property="portfoliocategory",
  *     type="array",
  *     description="Display portfolio category",
  *     ref = "#/definitions/portfoliocategory"
  *   ),
  *   @SWG\Property(
  *     property="portfolioclassification",
  *     type="object",
  *     description="PortfolioClassification",
  *     ref = "#/definitions/portfolioclassification"
  *   ),
  *   
  *   @SWG\Property(
  *     property="publisher",
  *     type="object",
  *     description="publisher",
  *     ref = "#/definitions/publisher"
  *   ),
  *   @SWG\Property(
  *     property="moderator",
  *     type="object",
  *     description="moderator",
  *     ref = "#/definitions/moderator"
  *   ),
  *   @SWG\Property(
  *     property="categoryTeamWelcome",
  *     type="string",
  *     description="categoryTeamWelcome"
  *   ),
  *   @SWG\Property(
  *     property="communityhallway",
  *     type="object",
  *     description="CommunityHallway"
  *   ),
  *   @SWG\Property(
  *     property="solutionFindercat",
  *     type="string",
  *     description="SolutionFinderCat"
  *   ),
  *   @SWG\Property(
  *     property="solutionfindersubcat",
  *     type="string",
  *     description="SolutionFinderSubcat"
  *   ),
  *   @SWG\Property(
  *     property="slug",
  *     type="string",
  *     description="Slug"
  *   ),
  *  )
  *
  */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
 
    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );

    $public_fields['status'] = array(
      'property' => 'status',
      'full_view' => TRUE,
    );

    $public_fields['publisher'] = array(
      'callback' => array($this, 'getPublisher'),
    );

    $public_fields['moderator'] = array(
      'callback' => array($this, 'getModerator'),
    );

    $public_fields['moderator'] = array(
      'callback' => array($this, 'getModerator'),
    );

    $public_fields['categoryTeamWelcome'] = array(
      'property' => 'field_team_welcome_message',
    );

    $public_fields['portfoliotagline'] = array(
      'property' => 'field_portfolio_tagline',
      'full_view' => TRUE,
    );

    $public_fields['portfolioheadertextareanew'] = array(
      'property' => 'field_headertextareanew',
      'full_view' => TRUE,
    );

    $public_fields['portfolioarticleembed'] = array(
      'property' => 'field_article_embed',
      'full_view' => TRUE,
    );

    $public_fields['portfolioaction'] = array(
      'property' => 'field_action',
      'full_view' => TRUE,
    );

    $public_fields['portfoliocategory'] = array(
      'property' => 'field_portfolio_category',
      'full_view' => TRUE,
    );

    $public_fields['portfolioclassification'] = array(
      'property' => 'field_category_classification',
      'full_view' => TRUE,
    );

    $public_fields['communityhallway'] = array(
      'property' => 'field_community_hallway',
      'full_view' => TRUE,
    );

     $public_fields['solutionfindercat'] = array(
      'property' => 'field_solution_finder_categories',
      'full_view' => TRUE,
    );

    $public_fields['solutionfindersubcat'] = array(
        'callback' => array($this, 'subcatFilter'),
    );

    $public_fields['slug'] = array(
        'property' => 'nid',
        'process_callbacks' => array(array($this, 'getSlug'))
    );
    
    return $public_fields;
  }

  /**
    * Get the Hallway URL slug
    * @return [string] - slug version of the hallway label
    */
    protected function getSlug($nid) {
      $url = explode('/', drupal_get_path_alias('node/' . $nid));
      return $url[count($url) - 1];
    }

  /**
   * [getUserByrole : Retrives user Object filtered by roles]
   * @param  [entity object] $wrapper [EntityMetadataWrapper]
   * @return [object] [User object filtered by roles]
   */

    private function userByrole($wrapper, $role) {
    $label = $wrapper->label();    
    switch ($label) {
    case 'Administrative Support':
        $label = 'Admin Support';
        break;
    case 'Cleaning Supplies & Chemicals':
        $label = 'Cleaning Supplies';
        break;
    case 'Security & Protection':
        $label = 'Security Protection';
        break;
    case 'Tools & Hardware':
        $label = 'Tools Hardware';
        break;    
    case 'Human Capital':
        $label = 'Talent Development';
        break;          
     }

    $name  = "HW {$label} ". $role;
    $role = user_role_load_by_name($name);
    //If $role returns TRUE; 
    if($role){
      $uid = db_select('users_roles', 'ur')
        ->fields('ur', array('uid'))
        ->condition('ur.rid', $role->rid, '=')
        ->execute()
        ->fetchCol();
    
    $user = user_load(end($uid));
   
    // //Check if uid value is not null. 
    if (is_null($user->uid) || $user->uid == "0") { return null; }

    //Get full URL for user picture
    if ($user->picture && $user->picture->uri) {
      $user->picture->url = file_create_url($user->picture->uri);
    }

    return array( 
      'uid' => $user->uid,
      'name' => $user->name,
      'picture' => $user->picture
    ); 

    } else {
      return null;
    }
  }


  /**
   * [getPublisher: Retrives Publisher Array]
   * @param  [entity object] $wrapper [EntityMetadataWrapper]
   * @return [object] [User object filtered by roles]
   */
  protected function getPublisher($wrapper) {
    return $this->userByrole(
      $wrapper, 
      $role = 'Publisher'
    );
  }

  /**
   * [getModerator: Retrives Moderator Array]
   * @param  [entity object] $wrapper [EntityMetadataWrapper]
   * @return [object] [User object filtered by roles]
   */
  protected function getModerator($wrapper) {
    return $this->userByrole(
      $wrapper, 
      $role = 'Moderator'
    );
  }

  protected function subcatFilter($wrapper) {
     $info = array(
        'property' => 'field_solution_finder_categories',
        'wrapper_method' => 'value'
      );
     $sf_category = $this->getValueFromProperty($wrapper, $wrapper->field_solution_finder_categories, $info, null);


    $info = array(
      'property' => 'field_sf_it_subcat',
      'wrapper_method' => 'value'
    );
    $office_management_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_it_subcat, $info, null);
    if($office_management_subcat) {
      if ($sf_category == "1")  $subcatfield = $office_management_subcat;
    }

    $info = array(
      'property' => 'field_sf_professional_services_s',
      'wrapper_method' => 'value'
    );
    $professional_services_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_professional_services_s, $info, null);
    if($professional_services_subcat) {
      if ($sf_category == "2")  $subcatfield = $professional_services_subcat;
    }


    $info = array(
      'property' => 'field_sf_security_and_protection',
      'wrapper_method' => 'value'
    );
    $security_and_protection_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_security_and_protection, $info, null);
    if($security_and_protection_subcat) {
      if ($sf_category == "3" )  $subcatfield = $security_and_protection_subcat;
      }


    $info = array(
      'property' => 'field_sf_construction_materials_',
      'wrapper_method' => 'value'
    );
    $construction_materials_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_construction_materials_, $info, null);
    if($construction_materials_subcat) {
       if ($sf_category == "4")  $subcatfield = $construction_materials_subcat;
    }


    $info = array(
      'property' => 'field_sf_industrial_products_sub',
      'wrapper_method' => 'value'
    );
    $industrial_products_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_industrial_products_sub, $info, null);
    if($industrial_products_subcat) {
      if ($sf_category == "5")   $subcatfield = $industrial_products_subcat;
    }


    $info = array(
        'property' => 'field_sf_office_management_subca',
        'wrapper_method' => 'value'
      );
      $office_management_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_office_management_subca, $info, null);
      if($office_management_subcat) {
        if ($sf_category == "6") $subcatfield = $office_management_subcat;
    }

    $info = array(
      'property' => 'field_sf_transportation_and_logi',
      'wrapper_method' => 'value'
    );
    $transportation_and_logi_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_transportation_and_logi, $info, null);
    if($transportation_and_logi_subcat) {
      if ($sf_category == "7")  $subcatfield = $transportation_and_logi_subcat;
    }


    $info = array(
      'property' => 'field_sf_travel_and_lodging_subc',
      'wrapper_method' => 'value'
    );
    $travel_and_lodging_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_travel_and_lodging_subc, $info, null);
    if($travel_and_lodging_subcat) {
      if ($sf_category == "8")  $subcatfield = $travel_and_lodging_subcat;
    }


    $info = array(
      'property' => 'field_sf_human_capital_subcat',
      'wrapper_method' => 'value'
    );
    $human_capital_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_human_capital_subcat, $info, null);
    if($human_capital_subcat) {
      if ($sf_category == "9")  $subcatfield = $human_capital_subcat;
    }


    $info = array(
      'property' => 'field_sf_medical_subcat',
      'wrapper_method' => 'value'
    );
    $medical_subcat = $this->getValueFromProperty($wrapper, $wrapper->field_sf_medical_subcat, $info, null);
    if($medical_subcat) {
      if ($sf_category == "10")  $subcatfield = $medical_subcat;
    }

   /**
    *    @SWG\Path(
    *    path="/hallway-portfolio",
    *    @SWG\Get(
    *      tags={"Hallway-portfolio"},
    *      summary="Provides sesion information for the currently logged in user session",
    *      @SWG\Response(
    *        response=200,
    *        description="Current session information",
    *        @SWG\Schema(
    *          type="object",
    *          @SWG\Property(
    *            property="data",
    *            type="array"
    *          )
    *        )
    *      )
    *    )
    *  )
    */

    return $subcatfield;

  }
}
