define(
  [
    'angular',
    'angularMocks',
    'components/directives/nav/nav-controller'
  ],
  function(angular) {
    describe('Nav Controller', function() {
      var $scope
        , $rootScope
        , modalSpy;

      beforeEach(module('gateways.components'));

      beforeEach(inject(function(_$rootScope_, $controller, _$modal_) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();
        modalSpy = jasmine.createSpy('$modal', _$modal_);

        $controller('NavController', {
          $scope: $scope,
          $modal: modalSpy
        });
      }));

      it('should open a new modal of given type and return a reference to the modal', function() {
        var type = 'type',
          modal = $scope.openModal(type),
          expectedOpts = {
            templateUrl: 'scripts/components/directives/nav/modals/' + type + '.modal.html',
            show: true
          };

        expect(modalSpy).toHaveBeenCalledWith(expectedOpts);
      });
    });
  }
);