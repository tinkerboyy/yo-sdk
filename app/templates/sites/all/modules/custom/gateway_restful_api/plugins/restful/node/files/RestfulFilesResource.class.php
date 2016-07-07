<?php

/**
 * @file
 * Contains RestfulFootersResource.
 */

class RestfulFilesResource extends AGRestfulFilesUpload {

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields_extend = array(
      'url' => array(
        'property' => 'url'
      )
    );

    return array_merge($public_fields, $public_fields_extend);
  }

  /**
   * @Override
   * An adaptation of file_save_upload() that includes more verbose errors.
   *
   * @param string $source
   *   A string specifying the filepath or URI of the uploaded file to save.
   *
   * @return stdClass
   *   The saved file object.
   *
   * @throws \RestfulBadRequestException
   * @throws \RestfulServiceUnavailable
   *
   * @see file_save_upload()
   */
  protected function fileSaveUpload($source) {
    try {
      return parent::fileSaveUpload($source);
    }
    catch(Exception $e) {
      $exceptionMessage = $e->getMessage();
      $exception = new RestfulBadRequestException($exceptionMessage);

      if (strpos($exceptionMessage, "exceeding the maximum file size") !== FALSE) {
        $exception->addFieldError('file', 'size');
      } else if (strpos($exceptionMessage, "Only files with the following extensions are allowed") !== FALSE) {
        $exception->addFieldError('file', 'mime');
      } else {
        $exception = $e;
      }

      throw $exception;
    }
  }

  public function access() {
    $account = $this->getAccount();
    return $this->accessByAllowOrigin();
  }

}
