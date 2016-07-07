<?php
/**
 * @file
 * email_notification_rule_and_web_service.features.inc
 */

/**
 * Implements hook_default_wsclient_service().
 */
function email_notification_rule_and_web_service_default_wsclient_service() {
  $items = array();
  $items['emailservice'] = entity_import('wsclient_service', '{
    "settings" : [],
    "operations" : {
      "sendSimpleEmail" : {
        "label" : "sendSimpleEmail",
        "result" : {
          "type" : "sendSimpleEmailResponse",
          "label" : "sendSimpleEmailResponse"
        },
        "parameter" : { "parameters" : { "type" : "sendSimpleEmail" } }
      },
      "sendEmail" : {
        "label" : "sendEmail",
        "result" : { "type" : "sendEmailResponse", "label" : "sendEmailResponse" },
        "parameter" : { "parameters" : { "type" : "sendEmail" } }
      }
    },
    "datatypes" : {
      "ERequest" : {
        "label" : "ERequest",
        "property info" : {
          "To" : { "type" : "text" },
          "From" : { "type" : "text" },
          "CC" : { "type" : "text" },
          "BCC" : { "type" : "text" },
          "Reply-To" : { "type" : "text" },
          "Subject" : { "type" : "text" },
          "Encoding" : { "type" : "text" },
          "Date" : { "type" : "text" },
          "mailContent" : { "type" : "text" },
          "headerList" : { "type" : "Header" },
          "mailAttachments" : { "type" : "MailAttachment" },
          "fileReferences" : { "type" : "text" }
        }
      },
      "SimpleEResponse" : {
        "label" : "SimpleEResponse",
        "property info" : {
          "statusMessage" : { "type" : "text" },
          "statusCode" : { "type" : "integer" }
        }
      },
      "EResponse" : {
        "label" : "EResponse",
        "property info" : {
          "statusMessage" : { "type" : "text" },
          "statusCode" : { "type" : "integer" }
        }
      },
      "sendEmail" : {
        "label" : "sendEmail",
        "property info" : { "in" : { "type" : "ERequest" } }
      },
      "sendEmailResponse" : {
        "label" : "sendEmailResponse",
        "property info" : { "out" : { "type" : "EResponse" } }
      },
      "sendSimpleEmail" : {
        "label" : "sendSimpleEmail",
        "property info" : { "in" : { "type" : "SimpleERequest" } }
      },
      "sendSimpleEmailResponse" : {
        "label" : "sendSimpleEmailResponse",
        "property info" : { "out" : { "type" : "SimpleEResponse" } }
      },
      "MailAttachment" : {
        "label" : "MailAttachment",
        "property info" : {
          "attachmentName" : { "type" : "text" },
          "appBOData" : { "type" : "base64Binary" }
        }
      },
      "Header" : {
        "label" : "Header",
        "property info" : {
          "headerName" : { "type" : "text" },
          "headerValue" : { "type" : "text" }
        }
      },
      "SimpleERequest" : {
        "label" : "SimpleERequest",
        "property info" : {
          "To" : { "type" : "text" },
          "From" : { "type" : "text" },
          "CC" : { "type" : "text" },
          "BCC" : { "type" : "text" },
          "Reply-To" : { "type" : "text" },
          "Subject" : { "type" : "text" },
          "Encoding" : { "type" : "text" },
          "Date" : { "type" : "text" },
          "mailContent" : { "type" : "text" }
        }
      }
    },
    "global_parameters" : [],
    "name" : "emailservice",
    "label" : "EmailService",
    "url" : "https:\\/\\/soa-ext.fas.gsa.gov\\/nde\\/esoa\\/EmailService?wsdl",
    "type" : "soap",
    "authentication" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
