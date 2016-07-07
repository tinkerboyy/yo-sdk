fdescribe('<%= featureName %>', function () {
  
  var page = {}
  , element = browser.element;
  
  beforeAll(function() {
     browser.get('/app/#/');
   });
   
   it('should have the feature title', function() {
      var ele = browser.element(by.css('.feature-name'));
      expect(ele.isDisplayed()).toBe(true);
   });

});