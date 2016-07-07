<?php
/**
 * @file
 * email_notification_rule_and_web_service.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function email_notification_rule_and_web_service_default_rules_configuration() {
  $items = array();
  $items['email_notification_rule_and_web_service_articlecomment'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_articlecomment" : {
      "LABEL" : "ArticleCommentNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient", "comment" ],
      "ON" : {
        "comment_insert--comment_node_article" : { "bundle" : "comment_node_article" },
        "comment_insert--comment_node_hallways_document" : { "bundle" : "comment_node_hallways_document" },
        "comment_insert--comment_node_video_article" : { "bundle" : "comment_node_video_article" }
      },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[comment:node:workbench-access-sections]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n        if ($forum == \\u0027Human Capital\\u0027) $forum = \\u0027Talent Development\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E\\r\\n",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "New [comment:node:workbench-access-sections] hallway [comment:node:type] comment was published  ",
              "param_Date" : "[comment:node] created on [comment:created]   ",
              "param_mailContent" : "\\u003C?php\\r\\n      $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[comment:node]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $nodeContentType = token_replace(\\u0027[comment:node:content-type]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $nodeForum = token_replace(\\u0027[comment:node:workbench-access-sections]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment)); \\r\\n       $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n       $nodeID = token_replace(\\u0027[comment:node:nid]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n       $nodeTitle = token_replace(\\u0027[comment:node:title]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n\\r\\n        $forum = token_replace(\\u0027[comment:node:workbench-access-sections]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022\\u0026amp;\\u0022,\\u0022and\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        $nodeTitleUrl = str_replace(\\u0022\\u0026amp;\\u0022,\\u0022and\\u0022,$nodeTitle);\\r\\n        $nodeTitleUrl = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($nodeTitleUrl));\\r\\n       $nodeTitleUrl = preg_replace(\\u0022\\/\\u0026#?[a-z0-9]+;\\/i\\u0022,\\u0022\\u0022, $nodeTitleUrl);\\r\\n\\r\\n        echo $siteuser .\\u0027 comment on \\u0027 . $nodeContentType . \\u0027 \\u0022\\u0027 . htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 was published within the \\u0027 . htmlspecialchars_decode($nodeForum, ENT_QUOTES) . \\u0027 hallway at \\u0027 . $siteurl . \\u0027app\\/#\\/gateway\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID . \\u0027\\/\\u0027 . $nodeTitleUrl;\\r\\n ?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_articlecommentedit'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_articlecommentedit" : {
      "LABEL" : "EditedArticleCommentNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient", "comment" ],
      "ON" : {
        "comment_update--comment_node_article" : { "bundle" : "comment_node_article" },
        "comment_update--comment_node_hallways_document" : { "bundle" : "comment_node_hallways_document" },
        "comment_update--comment_node_video_article" : { "bundle" : "comment_node_video_article" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "site:current-user" ], "value" : [ "comment:author" ] } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "[comment:status]" },
            "PROVIDE" : { "variable_added" : { "variable_added" : "Added variable" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[comment:node:workbench-access-sections]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n       if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n       if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n        if ($forum == \\u0027Human Capital\\u0027) $forum = \\u0027Talent Development\\u0027;\\r\\n\\r\\n        $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n              $query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E\\r\\n",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_BCC" : [ "" ],
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Edited [comment:node:workbench-access-sections] hallway [comment:node:conent-type] comment was published",
              "param_Date" : "Comment edited  on [comment:changed]",
              "param_mailContent" : "\\u003C?php \\r\\n      $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[comment:node]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $nodeContentType = token_replace(\\u0027[comment:node:content-type]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $nodeForum = token_replace(\\u0027[comment:node:workbench-access-sections]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n       $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n       $nodeID = token_replace(\\u0027[comment:node:nid]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n       $nodeTitle = token_replace(\\u0027[comment:node:title]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n\\r\\n        $forum = token_replace(\\u0027[comment:node:workbench-access-sections]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022\\u0026amp;\\u0022,\\u0022and\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        $nodeTitleUrl = str_replace(\\u0022\\u0026amp;\\u0022,\\u0022and\\u0022,$nodeTitle);\\r\\n        $nodeTitleUrl = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($nodeTitleUrl));\\r\\n       $nodeTitleUrl = preg_replace(\\u0022\\/\\u0026#?[a-z0-9]+;\\/i\\u0022,\\u0022\\u0022, $nodeTitleUrl);\\r\\n\\r\\n        echo $siteuser .\\u0027 edited comment on \\u0027 . $nodeContentType . \\u0027 \\u0022\\u0027 . htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 was published within the \\u0027 . htmlspecialchars_decode($nodeForum, ENT_QUOTES) . \\u0027 hallway at \\u0027 . $siteurl . \\u0027app\\/#\\/gateway\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID . \\u0027\\/\\u0027 . $nodeTitleUrl;\\r\\n\\r\\n ?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_email" : "Created data" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-email" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_articlenotification'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_articlenotification" : {
      "LABEL" : "ArticleNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient" ],
      "ON" : {
        "node_insert--article" : { "bundle" : "article" },
        "node_insert--hallways_document" : { "bundle" : "hallways_document" },
        "node_insert--video_article" : { "bundle" : "video_article" }
      },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "New [node:workbench-access-sections] hallway [node:content-type] was published",
              "param_Date" : "[node:content-type] created on [node:created]",
              "param_mailContent" : "\\u003C?php\\r\\n      $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[node:title]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n      $nodeContentType = token_replace(\\u0027[node:content-type]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n      $nodeForum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n       $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n       $nodeID = token_replace(\\u0027[node:nid]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n       $nodeTitle = token_replace(\\u0027[node:title]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n\\r\\n        $forum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022\\u0026amp;\\u0022,\\u0022and\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        $nodeTitleUrl = str_replace(\\u0022\\u0026amp;\\u0022,\\u0022and\\u0022,$nodeTitle);\\r\\n        $nodeTitleUrl = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($nodeTitleUrl));\\r\\n       $nodeTitleUrl = preg_replace(\\u0022\\/\\u0026#?[a-z0-9]+;\\/i\\u0022,\\u0022\\u0022, $nodeTitleUrl);\\r\\n\\r\\n        echo $siteuser .\\u0027 \\u0027 . $nodeContentType . \\u0027 \\u0022\\u0027 . htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 was published within the \\u0027 . htmlspecialchars_decode($nodeForum, ENT_QUOTES) . \\u0027 hallway at \\u0027 . $siteurl . \\u0027app\\/#\\/gateway\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID . \\u0027\\/\\u0027 . $nodeTitleUrl;\\r\\n ?\\u003E\\r\\n"
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_editcommentnotification'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_editcommentnotification" : {
      "LABEL" : "EditedCommunityCommentNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient", "comment" ],
      "ON" : { "comment_update--comment_node_forum" : { "bundle" : "comment_node_forum" } },
      "IF" : [
        { "data_is" : { "data" : [ "site:current-user" ], "value" : [ "comment:author" ] } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "[comment:status]" },
            "PROVIDE" : { "variable_added" : { "variable_added" : "Added variable" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support Office Supplies\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n        if ($forum == \\u0027Human Capital\\u0027) $forum = \\u0027Talent Development\\u0027;\\r\\n        if ($forum == \\u0027Acquisition Gateway\\u0027) array_push($roles,\\u0027Gateway Moderator\\u0027);\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Moderator\\u0027;\\r\\n \\t array_push($roles,$forum );\\r\\n       \\r\\n\\t   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E\\r\\n",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_BCC" : [ "" ],
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Edited [comment:node:taxonomy-forums] community reply was published",
              "param_Date" : "Comment edited  on [comment:changed]",
              "param_mailContent" : "\\u003C?php\\r\\n      $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[comment:node]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $nodeForum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n       $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n       $nodeID = token_replace(\\u0027[comment:node:nid]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n\\r\\n        $forum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        echo $siteuser .\\u0027 edited reply on topic \\u0022\\u0027 . htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 was published within the \\u0027 . htmlspecialchars_decode($nodeForum, ENT_QUOTES) . \\u0027 community at \\u0027 . $siteurl . \\u0027app\\/#\\/communities\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID ;\\r\\n ?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_email" : "Created data" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-email" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_exp_emails'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_exp_emails" : {
      "LABEL" : "Article Expiration Notifications",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient" ],
      "USES VARIABLES" : {
        "node" : { "label" : "node", "type" : "node" },
        "days" : { "label" : "days", "type" : "integer" }
      },
      "ACTION SET" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n        if ($forum == \\u0027Human Capital\\u0027) $forum = \\u0027Talent Development\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E\\r\\n",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Attn: In [days:value] Day(s) [node:workbench-access-sections] hallway [node:content-type] \\u0022[node:title]\\u0022 is expiring\\r\\n",
              "param_mailContent" : "Please update the Expiration Date for [node:content-type] \\u0022[node:title]\\u0022. \\r\\n\\r\\nUrl : [node:url]"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created1" : "Created data" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_gatekeepernotification'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_gatekeepernotification" : {
      "LABEL" : "GatekeeperNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : {
                "article" : "article",
                "article_file_upload" : "article_file_upload",
                "forum" : "forum",
                "hallways_document" : "hallways_document",
                "hallways_historical_prices" : "hallways_historical_prices",
                "hallways_transactional_platforms" : "hallways_transactional_platforms",
                "video_article" : "video_article"
              }
            }
          }
        }
      ],
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array(\\u0022Public Access Gatekeeper\\u0022);\\r\\n        \\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "FOIA Review Required - Content Edited - [node:workbench-access-sections] hallway - [node:title]",
              "param_Date" : "[node:content-type] created on [node:created]",
              "param_mailContent" : "The following [node:content-type] in the [node:workbench-access-sections] hallway was edited: [node:title].  Therefore, the public check box was unchecked, so the content will not be displayed on the public view of the Gateway.  This piece of edited content now requires FOIA review.\\r\\n\\r\\nFor FOIA:  Please go to Gateway, navigate to where the [node:content-type] resides on the [node:workbench-access-sections] hallway, and view the edited content. If you encounter any trouble locating the content, send an email to the Gatekeeper, asking for a direct link to the material."
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_hwemailnotification'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_hwemailnotification" : {
      "LABEL" : "CommunityCommentNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient", "comment" ],
      "ON" : { "comment_insert--comment_node_forum" : { "bundle" : "comment_node_forum" } },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n        $emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n       $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support Office Supplies\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n        if ($forum == \\u0027Human Capital\\u0027) $forum = \\u0027Talent Development\\u0027;\\r\\n        if ($forum == \\u0027Acquisition Gateway\\u0027) array_push($roles,\\u0027Gateway Moderator\\u0027);\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Moderator\\u0027;\\r\\n \\t array_push($roles,$forum );\\r\\n               \\r\\n                $query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E\\r\\n",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "New [comment:node:taxonomy-forums] community reply was published",
              "param_Date" : "Comment created on [comment:created]",
              "param_mailContent" : "\\u003C?php\\r\\n      $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[comment:node]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $nodeForum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n      $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeID = token_replace(\\u0027[comment:node:nid]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n\\r\\n        $forum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        echo $siteuser .\\u0027 reply on topic \\u0022\\u0027 . htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 was published within the \\u0027 . htmlspecialchars_decode($nodeForum, ENT_QUOTES) . \\u0027 community at \\u0027 . $siteurl . \\u0027app\\/#\\/communities\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID ;\\r\\n ?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_sow_notification'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_sow_notification" : {
      "LABEL" : "SOWUploadNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient" ],
      "ON" : { "node_presave--sow" : { "bundle" : "sow" } },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array(\\u0027SOW Librarian\\u0027);\\r\\n         \\r\\n\\t   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t $emailList .= $mail;\\r\\n\\t\\t\\t $emailList .= \\u0027,\\u0027;\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\r\\n     \\/*  $emailList=\\u0022\\u0022;  *\\/\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "SOW content creation",
              "param_Date" : "Topic created on [node:created]",
              "param_mailContent" : "Please review [site:current-user] topic [node:title] to be published.\\r\\n"
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['email_notification_rule_and_web_service_topicreplynotification'] = entity_import('rules_config', '{ "email_notification_rule_and_web_service_topicreplynotification" : {
      "LABEL" : "TopicReplyNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient", "comment" ],
      "ON" : { "comment_insert--comment_node_forum" : { "bundle" : "comment_node_forum" } },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : [ "comment:node:author:mail" ],
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Acquisition Gateway Notification: New reply",
              "param_Date" : "Comment created on [comment:created]",
              "param_mailContent" : " \\u003C?php\\r\\n       $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[comment:node]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n       $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n       $nodeID = token_replace(\\u0027[comment:node:nid]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n\\r\\n        $forum = token_replace(\\u0027[comment:node:taxonomy-forums]\\u0027, array(\\u0027comment\\u0027 =\\u003E $comment));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        echo $siteuser .\\u0027 replied to your topic \\u0022\\u0027 .  htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 on the Acquisition Gateway at \\u0027 . $siteurl . \\u0027app\\/#\\/communities\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID ;\\r\\n ?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_contentexpireformoderators_1'] = entity_import('rules_config', '{ "rules_contentexpireformoderators_1" : {
      "LABEL" : "contentexpireformoderators_1",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "article" : "article",
                "hallways_document" : "hallways_document",
                "video_article" : "video_article"
              }
            }
          }
        },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : {
            "data" : [ "node:field-expiration-date" ],
            "op" : "\\u003E",
            "value" : "now"
          }
        },
        { "data_is" : {
            "data" : [ "node:field-expiration-date" ],
            "op" : "\\u003C",
            "value" : "+2 days"
          }
        }
      ],
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Attn: In 1 Day [node:content-type] \\u0022[node:title]\\u0022 is expiring",
              "param_mailContent" : "Please update the Expiration Date for [node:content-type] \\u0022[node:title]\\u0022. \\r\\n\\r\\nUrl : [node:url]"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created1" : "Created data1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_contentexpireformoderators_10'] = entity_import('rules_config', '{ "rules_contentexpireformoderators_10" : {
      "LABEL" : "contentexpireformoderators_10",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "article" : "article",
                "hallways_document" : "hallways_document",
                "video_article" : "video_article"
              }
            }
          }
        },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : {
            "data" : [ "node:field-expiration-date" ],
            "op" : "\\u003E",
            "value" : "+9 days"
          }
        },
        { "data_is" : {
            "data" : [ "node:field-expiration-date" ],
            "op" : "\\u003C",
            "value" : "+11 days"
          }
        }
      ],
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Attn: In 10 Days [node:content-type] \\u0022[node:title]\\u0022 is expiring",
              "param_mailContent" : "Please update the Expiration Date for [node:content-type] \\u0022[node:title]\\u0022. \\r\\n\\r\\nUrl : [node:url]"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created1" : "Created data1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_contentexpireformoderators_30'] = entity_import('rules_config', '{ "rules_contentexpireformoderators_30" : {
      "LABEL" : "contentexpireformoderators_30",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "article" : "article",
                "hallways_document" : "hallways_document",
                "video_article" : "video_article"
              }
            }
          }
        },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : {
            "data" : [ "node:field-expiration-date" ],
            "op" : "\\u003E",
            "value" : "+29 days"
          }
        },
        { "data_is" : {
            "data" : [ "node:field-expiration-date" ],
            "op" : "\\u003C",
            "value" : "+31 days"
          }
        }
      ],
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[node:workbench-access-sections]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n        if ($forum == \\u0027Administrative Support\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n        if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Publisher\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "Attn: In 30 Days [node:content-type] \\u0022[node:title]\\u0022 is expiring",
              "param_mailContent" : "Please update the Expiration Date for [node:content-type] \\u0022[node:title]\\u0022. \\r\\n\\r\\nUrl : [node:url]"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created1" : "Created data1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_email_notification_rule_and_web_service_sow_res_gatenotify'] = entity_import('rules_config', '{ "rules_email_notification_rule_and_web_service_sow_res_gatenotify" : {
      "LABEL" : "SOWResourceGatekeeperNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "resources_file" : "resources_file", "sow" : "sow" } }
          }
        }
      ],
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array(\\u0022Public Access Gatekeeper\\u0022);\\r\\n        \\r\\n   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t  if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_CC" : "travis.lewis@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "FOIA Review Required - Content Edited - [node:title]",
              "param_Date" : "[node:content-type] created on [node:created]",
              "param_mailContent" : "The following [node:content-type] was edited: [node:title].  Therefore, the public check box was unchecked, so the content will not be displayed on the public view of the Gateway.  This piece of edited content now requires FOIA review.  \\r\\n\\r\\nFor FOIA:  Please go to Gateway, navigate to where the [node:content-type] resides on the Gateway, and view the edited content. If you encounter any trouble locating the content, send an email to the Gatekeeper, asking for a direct link to the material."
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_emailnotification'] = entity_import('rules_config', '{ "rules_emailnotification" : {
      "LABEL" : "emailnotification",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : {
                "article" : "article",
                "hallways_document" : "hallways_document",
                "video_article" : "video_article"
              }
            }
          }
        }
      ],
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n        $emailList=\\u0022\\u0022;\\r\\n\\t\\t$path = current_path();\\r\\n\\t\\t$nids = explode(\\u0022comment\\/reply\\/\\u0022, $path);\\r\\n                $roles = array(\\u0027Gateway Moderator\\u0027);\\t\\r\\n\\t        $node = node_load($nids[1]);\\r\\n\\r\\n       if(isset($node-\\u003Eworkbench_access)){ \\r\\n\\t        $wbaccess= $node-\\u003Eworkbench_access;\\r\\n                if(isset($wbaccess)  and !empty ($wbaccess)){\\r\\n        \\t$tid=implode($wbaccess);\\r\\n\\t\\t$term = taxonomy_term_load($tid);\\r\\n\\t        $vacobulory =$term-\\u003Ename;\\r\\n                }\\r\\n                if(isset($vacobulory)  and !empty ($vacobulory)){\\r\\n\\t\\t$specific_role =\\u0027HW \\u0027.$vacobulory.\\u0027 Moderator\\u0027;\\r\\n                array_push(  $roles ,$specific_role );\\r\\n\\t       }\\r\\n       }else{\\r\\n               array_push($roles, \\u0027Site Manager\\u0027);\\r\\n        }\\r\\n         \\r\\n        $query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n\\t$query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\r\\n         if($result){\\r\\n\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n\\t\\t\\t $emailList .= $mail;\\r\\n\\t\\t\\t $emailList .= \\u0027,\\u0027;\\r\\n\\t\\t}\\r\\n\\t}\\r\\n\\r\\n        $email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n        return trim($email_user_list);\\r\\n?\\u003E",
              "param_From" : [ "site:current-user:mail" ],
              "param_Subject" : "[site:current-user] comments are ready for review",
              "param_Date" : "Comment Created on [comment:created]",
              "param_mailContent" : "Please review [site:current-user] comments published on [comment:node]"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created1" : "Created data1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_send_notification_to_solutions_finder_admin'] = entity_import('rules_config', '{ "rules_send_notification_to_solutions_finder_admin" : {
      "LABEL" : "Send notification to Solutions Finder Admin",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient" ],
      "USES VARIABLES" : { "text_string" : { "label" : "string", "type" : "text" } },
      "ACTION SET" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array(\\u0027Solutions Finder Admin\\u0027);\\r\\n        \\r\\n\\r\\n\\t   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n                $query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n                         if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }  \\r\\n\\t\\t}\\r\\n\\t} \\r\\n \\r\\n     \\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);   \\r\\n\\treturn trim($email_user_list);\\r\\n\\r\\n?\\u003E",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "New solutions published by [site:current-user]",
              "param_mailContent" : "[site:current-user] published a new solution.\\r\\n"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created1" : "Created data" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_topicnotification'] = entity_import('rules_config', '{ "rules_topicnotification" : {
      "LABEL" : "TopicNotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "wsclient" ],
      "ON" : { "node_insert--forum" : { "bundle" : "forum" } },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "\\u003C?php\\r\\n   \\t$emailList=\\u0022\\u0022;\\r\\n        $roles = array();\\r\\n        $forum = token_replace(\\u0027[node:taxonomy-forums]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n\\r\\n         if ($forum == \\u0027Administrative Support Office Supplies\\u0027) $forum = \\u0027Admin Support\\u0027;\\r\\n         if ($forum == \\u0027Cleaning Supplies Chemicals\\u0027) $forum = \\u0027Cleaning Supplies\\u0027;\\r\\n         if ($forum == \\u0027Acquisition Gateway\\u0027) array_push($roles,\\u0027Gateway Moderator\\u0027);\\r\\n         if ($forum == \\u0027Human Capital\\u0027) $forum = \\u0027Talent Development\\u0027;\\r\\n\\r\\n         $forum = \\u0027HW \\u0027 . $forum. \\u0027 Moderator\\u0027;\\r\\n \\t array_push($roles,$forum);\\r\\n\\r\\n\\t   \\t$query = db_select(\\u0027users_roles\\u0027, \\u0027ur\\u0027);\\r\\n                $query-\\u003Ejoin(\\u0027users\\u0027, \\u0027u\\u0027, \\u0027u.uid = ur.uid\\u0027);\\r\\n\\t\\t$query-\\u003Ejoin(\\u0027role\\u0027, \\u0027r\\u0027, \\u0027r.rid = ur.rid\\u0027);\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027uid\\u0027));\\r\\n\\t\\t$query-\\u003Efields(\\u0027u\\u0027,array(\\u0027mail\\u0027));\\r\\n\\t\\t$query-\\u003Econdition(\\u0027r.name\\u0027, $roles, \\u0027IN\\u0027);\\t\\r\\n\\t\\t$result = $query-\\u003Eexecute();\\r\\n\\t\\t\\r\\n\\t\\tif($result){\\r\\n\\t\\t\\tforeach($result as $row ) {\\r\\n\\t\\t\\t $uid = $row-\\u003Euid;\\r\\n\\t\\t\\t $mail= $row-\\u003Email;\\r\\n                         if ($mail ){\\r\\n\\t\\t\\t     $emailList .= $mail;\\r\\n\\t\\t\\t     $emailList .= \\u0027,\\u0027;\\r\\n                         }\\r\\n\\t\\t}\\r\\n\\t}\\r\\n     \\t$email_user_list =str_replace(\\u0022\\u0022, \\u0022\\u0022, $emailList);\\r\\n\\treturn trim($email_user_list);\\r\\n?\\u003E\\r\\n",
              "param_From" : "hallways_site_manager@gsa.gov",
              "param_Reply-To" : "hallways_site_manager@gsa.gov",
              "param_Subject" : "New [node:taxonomy-forums] community topic was published",
              "param_Date" : "Topic created on [node:created].",
              "param_mailContent" : "\\u003C?php\\r\\n      $siteuser = token_replace(\\u0027[site:current-user]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n      $nodeTitle = token_replace(\\u0027[node:title]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n      $nodeForum = token_replace(\\u0027[node:taxonomy-forums]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n       $siteurl = token_replace(\\u0027[site:url]\\u0027, array(\\u0027site\\u0027 =\\u003E $site));\\r\\n       $nodeID = token_replace(\\u0027[node:nid]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n\\r\\n        $forum = token_replace(\\u0027[node:taxonomy-forums]\\u0027, array(\\u0027node\\u0027 =\\u003E $node));\\r\\n        $forum = str_replace(\\u0022 \\u0026amp;\\u0022,\\u0022\\u0022,$forum);\\r\\n        $forum = str_replace(\\u0022 \\u0022, \\u0022-\\u0022, strtolower($forum));\\r\\n        echo $siteuser .\\u0027 topic \\u0022\\u0027 . htmlspecialchars_decode($nodeTitle, ENT_QUOTES) . \\u0027\\u0022 was published within the \\u0027 . htmlspecialchars_decode($nodeForum, ENT_QUOTES) . \\u0027 community at \\u0027 . $siteurl . \\u0027app\\/#\\/communities\\/\\u0027 . $forum . \\u0027\\/\\u0027 . $nodeID ;\\r\\n ?\\u003E\\r\\n"
            },
            "PROVIDE" : { "data_created" : { "data_created_topic" : "Created data topic" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-topic" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_topic1" : "Created data topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-topic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_userdeletenotification'] = entity_import('rules_config', '{ "rules_userdeletenotification" : {
      "LABEL" : "userdeletenotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "wsclient", "comment" ],
      "ON" : { "comment_delete" : [] },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "[comment:mail]",
              "param_From" : "moderator@gsa.gov",
              "param_Subject" : "Your comment was not published.",
              "param_mailContent" : "The moderator chose not to publish your comment. "
            },
            "PROVIDE" : { "data_created" : { "data_created_comment_delete" : "Created data for comment delete" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created-comment-delete" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_comment_delete1" : "Created data comment delete" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-comment-delete1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_useremailnotification'] = entity_import('rules_config', '{ "rules_useremailnotification" : {
      "LABEL" : "useremailnotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient", "comment" ],
      "ON" : { "comment_update" : [] },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "[comment:status]" },
            "PROVIDE" : { "variable_added" : { "variable_added" : "Added variable" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "[comment:mail]",
              "param_From" : "moderator@gsa.gov",
              "param_BCC" : [ "" ],
              "param_Subject" : "\\u003C?php\\r\\nif ($variable_added==\\u0022Published\\u0022)\\r\\n{print \\u0027Your comment was posted.  Thank you!\\u0027;}\\r\\nelse {print  \\u0027Your comment was not published.\\u0027;} \\r\\n?\\u003E",
              "param_mailContent" : "\\u003C?php\\r\\nif ($variable_added==\\u0022Published\\u0022)\\r\\n{print \\u0027Thanks for your comment, we welcome your feedback.\\u0027;}\\r\\nelse {print  \\u0027 The moderator chose not to publish your comment.\\u0027;} \\r\\n?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_created" : "Created data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_email" : "Created data" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-email" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_usertopicdeletenotification'] = entity_import('rules_config', '{ "rules_usertopicdeletenotification" : {
      "LABEL" : "usertopicdeletenotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "wsclient" ],
      "ON" : { "node_delete--forum" : { "bundle" : "forum" } },
      "DO" : [
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "[node:author:mail]",
              "param_From" : "moderator@gsa.gov",
              "param_Subject" : "Your topic was not published.",
              "param_mailContent" : "The moderator chose not to publish your topic. "
            },
            "PROVIDE" : { "data_created" : { "topic_delete_notification" : "Created data topic notification delete" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "topic-delete-notification" ]
            },
            "PROVIDE" : { "data_created" : { "topic_delete_notification1" : "Created data topic delete notification" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "topic-delete-notification1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  $items['rules_usertopicemailnotification'] = entity_import('rules_config', '{ "rules_usertopicemailnotification" : {
      "LABEL" : "usertopicemailnotification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "wsclient" ],
      "ON" : { "node_update--forum" : { "bundle" : "forum" } },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "[node:status]" },
            "PROVIDE" : { "variable_added" : { "topic_variable" : "Added topic variable" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_SimpleERequest",
              "param_To" : "[node:author:mail]",
              "param_From" : "moderator@gsa.gov",
              "param_Subject" : "\\u003C?php\\r\\nif ($topic_variable==\\u0022Published\\u0022)\\r\\n{print \\u0027Your Topic was posted.  Thank you!\\u0027;}\\r\\nelse {print  \\u0027Your topic was not published.\\u0027;} \\r\\n?\\u003E\\r\\n",
              "param_mailContent" : "\\u003C?php\\r\\nif ($topic_variable==\\u0022Published\\u0022)\\r\\n{print \\u0027Thanks for your topic, we welcome your feedback.\\u0027;}\\r\\nelse {print  \\u0027 The moderator chose not to publish your Topic.\\u0027;} \\r\\n?\\u003E"
            },
            "PROVIDE" : { "data_created" : { "data_usertopic_created" : "Created user topic data" } }
          }
        },
        { "data_create" : {
            "USING" : {
              "type" : "wsclient_emailservice_sendSimpleEmail",
              "param_in" : [ "data-usertopic-created" ]
            },
            "PROVIDE" : { "data_created" : { "data_created_usertopic1" : "Created data user topic1" } }
          }
        },
        { "wsclient_emailservice_sendSimpleEmail" : {
            "USING" : { "param_parameters" : [ "data-created-usertopic1" ] },
            "PROVIDE" : { "result" : { "result" : "sendSimpleEmailResponse" } }
          }
        }
      ]
    }
  }');
  return $items;
}
