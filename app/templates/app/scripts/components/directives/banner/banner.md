---
title: Banner 
slug: banner
---

This directive places a full page banner across the top of the application. The settings for the banner are passed through the Acquisition Gateway Service (AGService) as properties of the banner.

Configure the banner at the top of your controller by injecting the AGService and setting properties. 

### USAGE
```JS
angular.module('myModule')
  .controller(function($scope, AGService) {
    AGService.data.banner.title = 'My App Title';
    AGService.data.banner.subtitle = 'Application or section subtitle';
    AGService.data.banner.env = ['learn';
  });
```
