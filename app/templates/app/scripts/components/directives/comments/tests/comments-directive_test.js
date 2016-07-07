/**
 * Created by Madhukar on 12/23/15.
 */
define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/comments/comments-directive',
  'components/directives/comments/comments.html'
],
  function(angular) {
    describe('Comments Directive', function() {
      var $scope
      , $compile
      , element
      , $httpBackend
      , commentsController;

      var testComments = [
        { id: 1, body: 'Comment 1' },
        { id: 2, body: 'Comment 2' },
        { id: 3, body: 'Comment 3' },
      ];

      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));

      beforeEach(angular.mock.inject(function($controller, $rootScope, _$compile_, _AGService_, _$httpBackend_, AGNotifications) {
        $scope = $rootScope.$new();
        $compile = _$compile_;
        $httpBackend = _$httpBackend_;

        $httpBackend.when('GET', '/api/v1.0/comments?filter%5Bnid%5D=1234&range=all').respond({ data: testComments });
        $httpBackend.when('GET', '/api/v1.0/preferences').respond({});
        $scope.item = { id: 1234, name: 'Test Item' };


        $controller('AgCommentsController', {
          $scope: $scope,
          AGService: _AGService_,
          AGNotifications: AGNotifications
        });

      }));

      afterEach(function() {
        $httpBackend.verifyNoOutstandingExpectation();
        $httpBackend.verifyNoOutstandingRequest();
      });


      it('should fetch comments for specified item', function() {
        $httpBackend.flush();
        expect($scope.comments).toEqual(testComments);
      });


      it('should not show a notification if no callback is supplied', function() {
        $scope.newComment.body = 'Test Comment',
        $scope.newComment.nid = 1234;
        var test = $scope.newComment;
        spyOn($scope, 'clearComment');
        var response = angular.copy(test);

        $httpBackend.expect('POST', '/api/v1.0/comments').respond({ data: [response] });
        $scope.postComment(test);

        $httpBackend.flush();
      });

      it('should submit a comment successfully', function() {
        $scope.newComment.body = 'Test Comment',
        $scope.newComment.nid = 1234;
        var test = $scope.newComment;
        spyOn($scope, 'clearComment');
        var response = angular.copy(test);

        $scope.notifyTopic = jasmine.createSpy();;

        $httpBackend.expect('POST', '/api/v1.0/comments').respond({ data: [response] });
        $scope.postComment(test);

        expect(test.processing).toBe(true);
        expect(test.success).toBe(undefined);

        $httpBackend.flush();

        expect(test.success).toBe(true);
        expect(test.processing).toBe(undefined);
        expect($scope.notifyTopic).toHaveBeenCalled();
        expect($scope.item.comments[3]).toEqual(response);
        expect($scope.clearComment).toHaveBeenCalled();
      });

      it('should handle comment creation API failure gracefully', function() {
        $scope.newComment.body = 'Test Comment',
        $scope.newComment.nid = 1234;
        var test = $scope.newComment;

        $httpBackend.expect('POST', '/api/v1.0/comments').respond(500);

        $scope.postComment(test);
        $httpBackend.flush();

        expect(test.processing).toBe(undefined);
        expect(test.error).toBe(true);
      });

      it('should cancel posting a comment', function() {
        $scope.newComment.body = 'Test Comment',
        $scope.clearComment();
        $httpBackend.flush();
        expect($scope.newComment.body).toBe(undefined);
      });

    });
});
