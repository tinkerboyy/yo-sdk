/**
 * Created by Madhukar on 12/24/15.
 */
define([
  'angular',
  'angularMocks',
  'components/components-module',
  'components/directives/confirmation/confirmation-directive'
], function(angular) {
    describe('Confirmation Directive', function() {
      var scope
        , $compile
        , element;

      var dom = [
        '<div class="add-to-project">',
          '<div class="add-success ">',
            '<center>',
            '<div>',
              '<i class="fa fa-5x fa-check-circle text-success"></i>',
            '</div>',
            '<p class="lead">Your file was successfully added</p>',
            '</center>',
          '</div>',
          '</div>'
          ].join('');

      beforeEach(angular.mock.module('gateways.components'));
      beforeEach(angular.mock.module('templates'));

      beforeEach(angular.mock.inject(function($templateCache, _$compile_, $rootScope) {
        scope = $rootScope.$new();
        $compile = _$compile_;

        $templateCache.put('scripts/components/directives/confirmation/confirmation.html', dom);


        element = angular.element('<ag-confirmation></ag-confirmation>');
        $compile(element)(scope);
        scope.$digest();
      }));

      it('should have the template compiled', function() {
        var result = element[0];
        var success = element[0].querySelectorAll('.add-success');
        expect(result.children.length > 0).toBeTruthy();
        expect(angular.element(success).hasClass('add-success')).toBeDefined();
      });
    });
  }
);
