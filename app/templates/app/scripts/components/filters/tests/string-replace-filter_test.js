define([ 
    'angular',
    'angularMocks',
    'components/components-module' ,
    'components/filters/string-replace-filter'
  ], function (angular) {
  describe('stringReplace filter', function() {
    beforeEach(module('gateways.solutionFinder'));

    beforeEach(inject(function(_$filter_){
      $filter= _$filter_;
    }));

    it('returns null when a non-string type value is given as the object on which to operate', function() {
      expect($filter('stringReplace')(null)).toEqual(null);
    });

    it('returns a string with the first instance of the old substring is replaced with the new substring', function() {
      expect($filter('stringReplace')('aaa', 'a', 'b')).toEqual('bbb');
    });
  });
});
