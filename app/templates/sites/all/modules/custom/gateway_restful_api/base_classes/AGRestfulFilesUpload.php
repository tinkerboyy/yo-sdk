<?php
require_once dirname(__FILE__) . '/AGPublicUserAccessCheck.php';

class AGRestfulFilesUpload extends RestfulFilesUpload {
  use AGPublicUserAccessCheck;
}
