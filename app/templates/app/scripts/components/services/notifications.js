/**
 * Created by Madhukar on 12/10/15.
 */

define(
  [
    'angular',
    'lodash',
    'components/components-module',
    'angularToasty'
  ], function(angular, _, componentsModule) {
    componentsModule.factory('AGNotifications', function(toasty) {
      var agNotifications = this
        , apiObj = {}
        , responseApi = {}
        , messages = {}
        , apiBuilder = {
          'pin': {
            successMessage: 'Your solution has been pinned to the top of the results!',
            deleteMessage: 'You are no longer following'
          },
          'follow':  {
            successMessage: 'Congratulations, you are now following',
            deleteMessage: 'You are no longer following'
          },
          '/api/v1.0/topics': {
            successMessage: 'Your topic was submitted!',
            errorMessage: 'Unsuccessful Post'
          },
          '/api/v1.0/comments': {
            successMessage: 'Your reply was submitted!',
            deleteMessage: 'You are no longer following',
            errorMessage: ''
          },
          '/api/v1.0/projects': {
            successMessage: 'Congratulations, your task was successfully created.'
          },
          '/api/v1.0/tasks': {
            successMessage: 'Congratulations, your task was successfully created.',
            successMessage1: 'Congratulations, your task was successfully created.',
            successMessage2: 'Congratulations, your task was successfully added to your project.',
            deleteMessage: 'you have deleted the task.',
            updateMessage: 'Congratulations, your task was successfully updated.',
            errorMessage: ''
          },
          '/api/v1.0/private-events': {
            successMessage: 'Congratulations, your event was successfully created.',
            successMessage1: 'Congratulations, your event was successfully created.',
            successMessage2: 'Congratulations, your event was successfully added to your project.',
            deleteMessage: 'You have deleted an event.',
            updateMessage: 'Congratulations, your task was successfully event.',
            errorMessage: ''
          },
          '/api/v1.0/projects-entity': {
            successMessage: 'Congratulations, your solution was successfully added to your project!',
            errorMessage: ''
          },
          '/api/v1.0/data-issue': {
            successMessage: 'Thank you for your submission, we appreciate you helping us keep the app current!'
          },
          '/api/v1.0/project-files': {
            successMessage: 'Succesfully Uploaded'
          }
        }
        , responses = {
          get: 'GET',
          post: 'POST',
          put: 'PUT',
          deleteIt: 'DELETE'
        };

      agNotifications.setNotification = function(response) {

        function setConditions(response) {
          var url = {}
            , defaultObj = {}
            , method = response.config.method
            , responseUrl = response.config.url
            , splitUrl = responseUrl.split('/')
            , wantedList = [
              '/api/v1.0/projects-entity',
              '/api/v1.0/project-files',
              '/api/v1.0/data-issue',
              '/api/v1.0/projects-entity',
              '/api/v1.0/private-events',
              '/api/v1.0/tasks',
              '/api/v1.0/projects',
              '/api/v1.0/comments',
              '/api/v1.0/topics',
              '/api/v1.0/preferences'
            ];

          responseUrl = (splitUrl.length === 5) ? (splitUrl.pop() ? splitUrl.join('/') : '') : splitUrl.join('/');

          var found = false;
          found = _.contains(wantedList, responseUrl);

          if (found) {
            responseApi =  responseUrl;
            switch (method) {
              case responses.post:
                if (response.config.data && response.config.data.action !== 'screen') {
                  url = responseApi.indexOf('/preferences') > -1 ? response.config.data.action : response.config.url;
                } else {
                  return false;
                }
                break;
              case responses.deleteIt:
                url = responseApi.indexOf('/preferences') > -1 ? response.config.params['filter[action]'] : responseUrl;
                break;
              case responses.get:
                url = responseApi.indexOf('/tasks') > -1 ? responseUrl: responseApi;
                break;
              case responses.put:
                if (response.config.data.action !== 'screen') {
                  url = responseApi;
                } else {
                  return false;
                }
                break;
              default:
                break;
            }

            if (url) {
              apiObj = apiBuilder[url];
              angular.extend(apiObj, response.config);

              if (method === responses.post) {
                if ((url.indexOf('tasks') === -1 && url.indexOf('projects-entity') === -1) && (apiObj.data || apiObj.data.action || apiObj.data.type || apiObj.data.solutionName)) {
                  messages.msg = apiObj.successMessage;
                }
              } else if (method === responses.deleteIt) {
                if (apiObj.params) {
                  messages.msg = apiObj.params['filter[action]'] !== 'pin' ? apiObj.deleteMessage : {};
                } else {
                  return;
                }
              } else if (method === responses.get && url.indexOf('tasks') > -1) {
                messages.msg = apiObj.successMessage;
                if (apiObj.data && apiObj.data.projectId && apiObj.data.projectId !== null) {
                  messages.msg = apiObj.successMessage2;
                } else if (apiObj.data && apiObj.data.projectId && apiObj.data.projectId === null) {
                  messages.msg = apiObj.successMessage1;
                }
              } else if (method === responses.get && url.indexOf('private-events') > -1) {
                messages.msg = apiObj.successMessage;
                if (apiObj.data && apiObj.data.projectId && apiObj.data.projectId !== null) {
                  messages.msg = apiObj.successMessage2;
                } else if (apiObj.data && apiObj.data.projectId && apiObj.data.projectId === null) {
                  messages.msg = apiObj.successMessage1;
                }
              }
            } else {
              apiObj = defaultObj;
            }
          }
        }

        if (response.config.method !== 'GET') {
          setConditions(response);
        }

        if (response.config.method === 'GET' && ((response.config.url.indexOf('/tasks') > -1) || (response.config.url.indexOf('/private-events') > -1))  && response.config.url.indexOf('/project-center') === -1) {
          setConditions(response);
        }
      };

      agNotifications.getNotification = function() {
        // toasty.clear();
        toasty.success(messages);
        return;
      };

      return agNotifications;

    });
  });
