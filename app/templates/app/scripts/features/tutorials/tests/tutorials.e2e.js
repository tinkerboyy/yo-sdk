xdescribe('Gateway Tutorials', function() {
  it('should load up the landing page', function() {
    browser.get('/app/#/tutorials');
    expect($('#tutorials h1').getText()).toEqual('GATEWAY TUTORIALS');

  it('should have tutorial options in the menu', function() {

  });
  });
});
