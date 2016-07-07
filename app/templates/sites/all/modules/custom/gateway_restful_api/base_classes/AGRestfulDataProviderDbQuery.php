<?php

require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

abstract class AGRestfulDataProviderDbQuery extends RestfulDataProviderDbQuery {
  use AGPublicUserAccessCheck;
}
