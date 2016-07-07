<?php

/**
 * @file
 * Contains RestfulUsersResource.
 */

class RestfulDataIssueResource extends \AGRestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {
  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'id',
    );
    $public_fields['solutionId'] = array(
      'property' => 'fkSolutionId',
    );
    $public_fields['email'] = array(
      'property' => 'userEmail',
    );
    $public_fields['comments'] = array(
      'property' => 'comments',
    );

    return $public_fields;
  }

  /**
   * Create an item from the request object.
   *
   * @return array
   *   The structured array for the item ready to be rendered.
   */
  public function create() {
    $table = $this->getTableName();

    // set database to solution matrix
    db_set_active('solution_matrix');

    $request = $this->getRequest();
    static::cleanRequest($request);
    $data = $request;

    $id = db_insert($table)
        ->fields(array(
          'fkSolutionId' => $data['solutionId'],
          'userEmail' => $data['userEmail'],
          'comments' => $data['comments'],
        ))->execute();

    $data['id'] = $id;

    // get solution managers emails
    $query = 'SELECT solutionManager FROM {tbContractSolutions} AS cs WHERE cs.pkContractSolutionId = (:csid)';
    $result = db_query($query, array(':csid' => $data['solutionId']));
    $emails = $result->fetchCol();
    $emails = array_map('trim', explode(',', $emails[0]));

    $message = 'A user has submitted a data issue in the Solutions Finder. Please update the identified solution as soon as possible.';
    $message .= "\r\n";
    $message .= $data['comments'];

    // set database back to drupal default
    db_set_active();

    $this->mailOut($emails, $message);

    return array($data);
  }

  /**
   * Get a basic query object.
   *
   * @return SelectQuery
   *   A new SelectQuery object for this connection.
   */
  protected function getQuery() {
    $table = $this->getTableName();

    // set database to solution matrix
    db_set_active('solution_matrix');

    $query = db_select($table)->fields($table);

    // set database back to drupal default
    db_set_active();

    return $query;
  }

  protected function mailOut($emails, $messages) {

    // get user role id's
    $roles = array(
      array_search('Solutions Finder Admin', user_roles()),
      array_search('Site Manager', user_roles()),
    );

    // get a list of all users by role
    $query = 'SELECT DISTINCT(ur.uid) FROM {users_roles} AS ur WHERE ur.rid IN (:rids)';
    $result = db_query($query, array(':rids' => $roles));

    // get uids
    $uids = $result->fetchCol();

    // get email address' and save them to array using user_load_multiples
    // https://api.drupal.org/api/drupal/modules!user!user.module/function/user_load_multiple/7
    $users = user_load_multiple($uids);

    // get user emails
    foreach ($users as $user) {
      $user = get_object_vars($user);
      $emails[] = $user['mail'];
    }

    // remove duplicate emails
    $emails = array_unique($emails);

    // run drupal_mail_send
    foreach($emails as $email) {
      $module = 'gateway_restful_api';
      $key = 'data_issue';
      $language = language_default();
      $params = array();
      $from = 'hallways_site_manager@gsa.gov';
      $send = FALSE;
      $message = drupal_mail($module, $key, $email, $language, $params, $from, $send);
      $message['subject'] = 'Solutions Finder Data Issue';
      $message['body'] = array();
      $message['body'][] = $messages;
      $message['headers']['Return-Path'] = 'hallways_site_manager@gsa.gov';
      $message['headers']['Sender'] = 'hallways_site_manager@gsa.gov';

      // Retrieve the responsible implementation for this message.
      $system = drupal_mail_system($module, $key);

      // Format the message body.
      $message = $system->format($message);

      // Send e-mail.
      $message['result'] = $system->mail($message);
    }
  }
}
