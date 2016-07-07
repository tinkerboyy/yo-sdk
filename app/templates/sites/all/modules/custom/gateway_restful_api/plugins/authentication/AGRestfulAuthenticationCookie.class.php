<?php
/**
 * @file
 * Contains RestfulAuthenticationCookie.
 */
class AGRestfulAuthenticationCookie extends RestfulAuthenticationCookie {

  /**
   * Implements RestfulAuthenticationInterface::authenticate().
   */
  public function authenticate(array $request = array(), $method = \RestfulInterface::GET) {

  	if (isset($_SESSION['phpCAS']['attributes']['samlAuthenticationStatementAuthMethod'])) {
      // echo "defined";
      $aumethod=$_SESSION['phpCAS']['attributes']['samlAuthenticationStatementAuthMethod'];

      $cas_cap_grouplist = $_SESSION['phpCAS']['attributes']['GroupList'];
      $whitelistgroup   = 'CAP-ACQUISITION-GATEWAY';
      $casgroupverification = strpos($cas_cap_grouplist, $whitelistgroup);

      if ($_SESSION['phpCAS']['attributes']['User-Classification'] == 'CONTRACTOR' && $casgroupverification === false) {
        //user_logout();
        throw new \RestfulForbiddenException('You do not have access to this resource.');
        //  module_load_include('pages.inc', 'user');
        //  drupal_goto("federal-contractor");
      } elseif (strpos($aumethod, "pivcard") !== false) {
           //echo "you are piv Card!!!!!";
      } elseif (strpos($aumethod, "secureplus:federated-saml2:assurancelevel3") !== false) {
          //echo "you are SSO!!!!!";
      } elseif (strpos($aumethod, "secureplus:MobileTwoFactorUnregistered:assurancelevel3") !== false) {
           //echo "you are SecurePlus!!!!!";
      } else {
        //user_logout();
        throw new \RestfulForbiddenException('You do not have access to this resource.');
           //echo "you are bad!!!!!";
          //module_load_include('pages.inc', 'user');
          //$_GET['destination'] = 'login-info-non-piv';
      }
    } else {
      if ((!user_is_logged_in() || user_is_anonymous()) && !drupal_is_cli()) {
        throw new \RestfulForbiddenException('You do not have access to this resource.');
      }
        //echo "not defined";
    }
    return parent::authenticate($request, $method);
  }

}
