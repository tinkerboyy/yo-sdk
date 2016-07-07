<?php

trait AGPublicUserAccessCheck {
  public function access() {


    if($this->isPublicUser() && $this->plugin['allow_public_acess'] !== true) {
      return false;
    }
    return parent::access();
  }

  public function isPublicUser() {
    $account = $this->getAccount();

    $roles = array_map(function($role) { return strtolower($role); }, $account->roles);

    return in_array('public user', $roles);
  }
}
