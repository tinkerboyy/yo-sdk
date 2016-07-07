<?php

/**
 * @file
 * Contains RestfulEntityUser__1_0.
 */

class RestfulUserProfilesResource extends \AGRestfulEntityBaseUser {
  protected $range = 10000;

    /**
  * Overrides RestfulHelpResource::publicFieldsInfo().
  * 
  *
  * @SWG\Definition(
  *   definition="user-profile",
  *   @SWG\Property(
  *     property="id",
  *     type="string",
  *     description="ID of user"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Display name of user"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="Display url of user's user profile"
  *   ),
  *   @SWG\Property(
  *     property="name",
  *     type="string",
  *     description="Displays Username"
  *   ), 
  *   @SWG\Property(
  *     property="email",
  *     type="string",
  *     description="Displays email of user"
  *   ),
  *   @SWG\Property(
  *     property="picture",
  *     type="string",
  *     description="Displays url of user's picture"
  *   ),
  *   @SWG\Property(
  *     property="jobTitle",
  *     type="string",
  *     description="Display jobtitle of user"
  *   ),
  *   @SWG\Property(
  *     property="agency",
  *     type="string",
  *     description="Display agency user belongs to"
  *   ), 
  * )
  *
  */

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['name'] = array(
      'property' => 'field_user_alternative_name',
    );

    $public_fields['id'] = array(
      'property' => 'uid',
    );

    $public_fields['email'] = array(
      'property' => 'mail',
    );

    $public_fields['picture'] = array(
        'property' => 'uid',
        'process_callbacks' => array(array($this, 'userPicture'))
      );

    $public_fields['jobTitle'] = array(
      'property' => 'field_job_title',
    );

    $public_fields['agency'] = array(
      'property' => 'uid',
      'process_callbacks' => array(array($this, 'userAgency'))
    );

    $public_fields['certifications'] = array(
      'property' => 'uid',
      'process_callbacks' => array(array($this, 'userCertifications'))
    );

    return $public_fields;
  }

  public function userAgency($uid) {
    $user = user_load($uid);
    $agency = $user->field_user_cas_agency['und'][0]['value'];
    return $agency;
  }
  
  /**
   * [userCertifications returns lisat of user Certifications.]
   * @param  [int] $uid [user id]
   * @return [object] $certifications [List of users certifications]
   */
  public function userCertifications($uid) {
    $user = user_load($uid);
    $query = db_select('ag_user_certifications', 'auc');
    $query->join('ag_certifications', 'ac', 'auc.cid = ac.id');
    $query
      ->condition('auc.uid',$user->uid)
      ->fields('ac', array('id','name'));
    $result = $query->execute();
   
    //Initialize empty array for certifications
    $certifications = array();

    foreach($result as $row) {
      $certifications[] = $row;
    }
    
    return $certifications;
  }

  public function userPicture($uid) {
    // get logged in user uid

    $user = user_load($uid);
    if (!$user->picture) {
      $user->picture = array("url"=>NULL);
    }
    else {
      $user->picture->url = file_create_url($user->picture->uri);
    }

    return $user->picture;
  }

 /**
   * Get a list of entities.
   *
   * @SWG\Path(
   *   path="/user-profile",
   *   @SWG\Get(
   *     tags={"User Profile"},
   *     summary="Returns all available Users profile",
   *     @SWG\Response(
   *       response=200,
   *       description="List of Users profile",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/user-profile")
   *         )
   *       )
   *     )
   *   ),
   *     @SWG\Response(
   *       response=200,
   *       description="List of user profile",
   *       @SWG\schema(
   *         type="object",
   *         @SWG\Property(
   *           property="data",
   *           type="array",
   *           @SWG\Items(ref="#/definitions/user-profile")
   *         )
   *       )
   *     )
   * )
   */
  
/**
   * Overrides \RestfulEntityBase::putEntity().
   */
  public function putEntity($entity_id) {
    global $user;
    $request = $this->getRequest();
    $picture = (int)$request['picture'];


    //Save entity and ignore certifications field
    $this->updateEntity($entity_id, FALSE, array('certifications', 'picture'));

    //Update User Certifications
    db_delete('ag_user_certifications')
      ->condition('uid', $user->uid)
      ->execute();

    foreach ($request['certifications'] as $certification) {
      if(empty($certification)) continue;
      db_insert('ag_user_certifications')
        ->fields(
          array(
            'uid' => $user->uid,
            'cid' => $certification['id']
          )
        )
        ->execute();
    }

    if ($picture) {
      db_update('users')
        ->condition('uid', (int)$entity_id)
        ->fields(array('picture' => $picture))
        ->execute();
    }

    $context = $this->getEntityCacheTags($entity_id);
    $this->clearRenderedCache($context);

    return array($this->viewEntity($entity_id));
  }

  /**
    * Overrides \RestfulEntityBaseUser::getList()
    */
  public function getList() {
    if (isset($_SESSION['phpCAS']['attributes']['samlAuthenticationStatementAuthMethod'])) {
      $aumethod=$_SESSION['phpCAS']['attributes']['samlAuthenticationStatementAuthMethod'];

      $cas_cap_grouplist = $_SESSION['phpCAS']['attributes']['GroupList'];

      $whitelistgroup   = 'CAP-ACQUISITION-GATEWAY';

      $casgroupverification = strpos($cas_cap_grouplist, $whitelistgroup);

      if ($_SESSION['phpCAS']['attributes']['User-Classification'] == 'CONTRACTOR' && $casgroupverification === false) {
        throw new \RestfulForbiddenException('You do not have access to this resource.');
      }
    }

    $results = db_query(
      "SELECT u.uid as id, u.mail as email, u.picture as imageId, p.uri as imageUrl, a.field_user_cas_agency_value as agency, j.field_job_title_value as jobTitle, un.field_user_alternative_name_value as name 
      FROM users u 
      LEFT JOIN users_roles ur ON u.uid=ur.uid 
      LEFT JOIN field_data_field_user_cas_agency a ON u.uid=a.entity_id 
      LEFT JOIN field_data_field_job_title j ON u.uid=j.entity_id 
      LEFT JOIN field_data_field_user_alternative_name un ON u.uid=un.entity_id 
      LEFT JOIN file_managed as p ON u.picture=p.fid 
      WHERE NOT (SELECT COUNT(*) FROM users_roles WHERE users_roles.uid=u.uid AND users_roles.rid=(SELECT rid FROM role WHERE name='Public User')) > 0 AND u.status=1 
      GROUP BY u.uid"
    )
    ->fetchAll();

    foreach ($results as &$result) {
      $result->picture = $result->imageUrl ? array('url' => file_create_url($result->imageUrl)) : array('url' => null);
      unset($result->imageUrl);
      unset($result->imageId);
    }

    return $results;
  }
}
