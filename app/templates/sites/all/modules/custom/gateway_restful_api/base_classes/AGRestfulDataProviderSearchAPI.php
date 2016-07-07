<?php

require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

abstract class AGRestfulDataProviderSearchAPI extends RestfulDataProviderSearchAPI {
  use AGPublicUserAccessCheck;
}
