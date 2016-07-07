<?php

/**
 * @file
 * Contains RestfulEntityUser__1_0.
 */

class RestfulEntityAuth__1_0 extends \RestfulEntityBaseUser {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
    @SWG\Definition(
      definition="UserInfo",
      @SWG\Property(
        property="name",
        type="string",
        description="username"
      ),
      @SWG\Property(
        property="theme",
        type="string",
        description="User's preferred theme"
      ),
      @SWG\Property(
        property="signature_format",
        type="string",
        description="Format of user signature"
      ),
      @SWG\Property(
        property="created",
        type="string",
        description="Timestamp of when the user was created"
      ),
      @SWG\Property(
        property="access",
        type="string",
        description="Timestamp of when the user last accessed the application"
      ),
      @SWG\Property(
        property="login",
        type="string",
        description="Timestamp of when the user last signed in"
      ),
      @SWG\Property(
        property="status",
        type="string",
        description="User account status"
      ),
      @SWG\Property(
        property="timezone",
        type="string",
        description="User timezone"
      ),
      @SWG\Property(
        property="language",
        type="string",
        description="User's preferred language"
      ),
      @SWG\Property(
        property="picture",
        type="object",
        description="User's display picture"
      ),
      @SWG\Property(
        property="init",
        type="string",
      ),
      @SWG\Property(
        property="roles",
        type="array",
        description="User system roles",
        @SWG\Items(
          type="string"
        )
      ),
      @SWG\Property(
        property="field_job_title",
        type="object",
        description="User's job title"
      ),
      @SWG\Property(
        property="field_user_cas_agency",
        type="object",
        description="User's CAS Agency"
      ),
      @SWG\Property(
        property="cas_names",
        type="array",
        @SWG\Items(
          type="string"
        )
      ),
      @SWG\Property(
        property="cas_name",
        type="string",
      ),
      @SWG\Property(
        property="realname",
        type="string",
        description="User's display name "
      ),
      @SWG\Property(
        property="cas",
        type="object",
        description=""
      ),
    )

    @SWG\Definition(
      definition="Auth",
      @SWG\Property(
        property="id",
        type="integer",
        description="ID of currently logged in user"
      ),
      @SWG\Property(
        property="label",
        type="string",
        description="Display name of currently logged in user"
      ),
      @SWG\Property(
        property="self",
        type="string",
        description="permalink to the currently logged in user's unique resource"
      ),
      @SWG\Property(
        property="user_info",
        type="object",
        description="User details for currently logged in user",
        ref="#/definitions/UserInfo"
      ),
      @SWG\Property(
        property="session",
        type="object",
        description="Current session details",
      ),
    )
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    $public_fields['id'] = array(
      'property' => 'uid',
    );

    $public_fields['mail'] = array(
      'property' => 'mail',
    );

    $public_fields['user_info'] = array(
        'callback' => array($this, 'userInfo')
      );

    $public_fields['session'] = array(
      'callback' => array($this, 'getSessionInfo')
    );

    $public_fields['container_id'] = array(
      'callback' => array($this, 'getContainerId')
    );

    return $public_fields;
  }

  public function getSessionInfo() {
    //Clear referrer url cookie
    unset($_COOKIES['referrerUrl']);
    setCookie('referrerUrl', null, -1, '/');
    setCookie('referrerUrl', null, -1, '/app/');
    setCookie('referrerUrl', null, -1, '/app');

    return array(
      'timeLeft' => $_SESSION['timeLeft'],
      'refreshLength' => $_SESSION['refreshLength']
    );
  }

  public function getContainerId() {
    require(DRUPAL_ROOT . '/sites/default/settings.php');
    return $container_id; 
  }

  public function userInfo() {
    // get logged in user uid
    $uid = $GLOBALS['user']->uid;

    $user = user_load($uid);

    //Add CAS information
    $user->cas = $_SESSION['phpCAS']['attributes'];

    // remove sensitive and irrelevant information
    unset($user->uid);
    unset($user->mail);
    unset($user->pass);
    unset($user->uuid);
    unset($user->workbench_access);
    unset($user->data);
    unset($user->og_user_node);
    unset($user->field_user_alternative_name);
    unset($user->rdf_mapping);


    //Get picture URL if picture exists
    if($user->picture) {
      $user->picture->url = file_create_url($user->picture->uri);
    }

    return $user;
  }

  /**
   * Overrides \RestfulEntityBase::getQueryForList().
   */
  public function getQueryForList() {
    // get logged in user uid
    $uid = $GLOBALS['user']->uid;

    // remove sensitive information
    // // get parent class
    $query = parent::getQueryForList();

    $query->propertyCondition('uid', $uid);

    return $query;
  }

  /**
    * Overrides \RestfulEntityBaseUser::getList()

      @SWG\Path(
        path="/auth",
        @SWG\Get(
          tags={"Users"},
          summary="Provides sesion information for the currently logged in user session",
          @SWG\Response(
            response=200,
            description="Current session information",
            @SWG\Schema(
              type="object",
              @SWG\Property(
                property="data",
                type="array",
                @SWG\Items(ref="#/definitions/Auth")
              )
            )
          )
        ),
        @SWG\Delete(
          tags={"Users"},
          summary="Terminates the current user session",
          @SWG\Response(
            response=200,
            description="confirms session was terminated successfully"
          )
        )

      )
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
    return parent::getList();

  }

  public function delete() {
    session_destroy();
    //throw new \RestfulForbiddenException('You have been signed out');
  }
}
