<?php
require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

class AGRestfulEntityBaseTaxonomyTerm extends RestfulEntityBaseTaxonomyTerm {
  use AGPublicUserAccessCheck;
}
