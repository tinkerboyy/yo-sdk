<?php

/**
 * @file
 * Contains RestfulSowResource.
 */

class RestfulFileResource extends \AGRestfulEntityBase {
  private static $uploadTypes = array(
    'sow-document' => array(
      'validators' => array(
        'file_validate_extensions' => array('pdf doc docx'),
        'file_validate_size' => array(102400000),
      ),
    ),
    'user-profile-picture' => array(
      'validators' => array(
        'file_validate_extensions' => array('jpg png gif jpeg'),
        'file_validate_size' => array(1024000),
      )
    )
  );

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['file'] = array(
      'property' => 'file',
      );

    return $public_fields;
  }


  /**
   * {@inheritdoc}
   */

  /**
   * {@inheritdoc}
   */
  public function createEntity() {
    GLOBAL $user;
    $out = array();

    if ($_POST['upload_type']) {
      if (isset(self::$uploadTypes[$_POST['upload_type']])) {
        $typeOptions = self::$uploadTypes[$_POST['upload_type']];
      } else {
        throw new \RestfulBadRequestException("Specified Upload Type is not valid");
      }
    } else {
      throw new \RestfulBadRequestException("Upload Type is required");
    }

    if(count($_FILES) > 0){
      foreach ($_FILES as $key => $files) {
        //Custom code to upload image file in drupal
        if(is_uploaded_file($files['tmp_name']) && $files['error'] == UPLOAD_ERR_OK) {


          $file = new stdClass();
          $file->uid      = $user->uid;
          $file->status   = 0;
          $file->filename = trim(drupal_basename($files['name']), '.');
          $file->uri      = $files['tmp_name'];
          $file->filemime = file_get_mimetype($file->filename);
          $file->filesize = $files['size'];
          //List of profile picture file types. 
          //$fileExtensions = array('image/png','image/jpeg','image/jpg');
          // Change the destination URI based on filemime type 
          //$destination = in_array($file->filemime, $fileExtensions) ? 'public://pictures/' : 'private://';
          $destination ='private://';
          $destination_scheme = file_uri_scheme($destination);
          if (!$destination_scheme || !file_stream_wrapper_valid_scheme($destination_scheme)) {
            return FALSE;
          }
          $file->destination = file_destination($destination . $file->filename, FILE_EXISTS_RENAME);
          if (substr($destination, -1) != '/') {
            $destination .= '/';
          }
          $file->uri = $file->destination;

          //Perform validation
          $this->validateFile($file, $typeOptions['validators']);

          if (!drupal_move_uploaded_file($files['tmp_name'], $file->uri)) {
            throw new RestfulServerConfigurationException('Could not upload file');
          }
           // Change status to permanent.
          $file->status = FILE_STATUS_PERMANENT;
          $file = file_save($file);
          $out[] = $file;
          $file->url = file_create_url($file->uri);
        }
      }
    }

    if ($_POST['iframe']) {
      header('Content-Type: text/plain');
      echo json_encode(array(
        'data' => $out
      ));
      exit;
    }

    return $out;

  }

  private function validateFile($file, $validators) {
    // Call the validation functions specified by this function's caller.
    $errors = file_validate($file, $validators);

    // Check for errors.
    if (!empty($errors)) {
      $message = format_string('The specified file %name could not be uploaded.', array('%name' => $file->filename));
      if (count($errors) > 1) {
        $message .= theme('item_list', array('items' => $errors));
      }
      else {
        $message .= ' ' . array_pop($errors);
      }

      throw new \RestfulBadRequestException($message);
    }
  }

}
