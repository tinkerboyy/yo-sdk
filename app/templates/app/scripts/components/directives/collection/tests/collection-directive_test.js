define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/services/collection-factory',
    'components/directives/collection/collection-directive'
  ],
  function(angular) {
    describe('Collection Directive', function() {
      var $scope          
        , $parse 
        , $attrs = {
            agCollection: [ { resourceName: 'Projects' }, 
                            { resourceName: 'ProjectEntities' } 
                          ]
          }
        , $collection; 


      beforeEach(module('gateways.components'));
      beforeEach(module('templates'));


      beforeEach(inject(function(_$rootScope_,  _$parse_, _$collection_, $controller) {
        $rootScope = _$rootScope_;
        $scope = $rootScope.$new();       
        $parse = _$parse_;
        $collection = _$collection_;
        
        $controller('AgCollectionController', {
          $scope:$scope,
          $attrs: $attrs,
          $parse: $parse,
          $collection: $collection
        })
        
      }));      

      it('should expose angular.copy as getEditCopy', function() {
        expect($scope.getEditCopy).toEqual(angular.copy);
      });
      
    });
  }
);
