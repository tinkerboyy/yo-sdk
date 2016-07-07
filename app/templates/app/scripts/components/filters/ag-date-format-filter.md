---
title: Date Format Filter
slug: ag-date-format-filter
---

This filter formats dates in the right way

## Requirements
Requires the $filter service to be injected

## Usage
This filter can be used directly from within JavaScript code (a controller, service or even another filter) as 
```JS
var d = $filter('ag-date-format')(timestamp);
```

To use this filter in your HTML markup, simply apply it to the data

```HTML
<div>Formatted date: {{ data.timestamp | ag-date-format: 'short' }}</div>
<div>Formatted date: {{ data.timestamp | ag-date-format: 'medium' }}</div>
<div>Formatted date: {{ data.timestamp | ag-date-format: 'long' }}</div>
```

<div>Formatted date: {{ data.timestamp | ag-date-format: 'short' }}</div>
<div>Formatted date: {{ data.timestamp | ag-date-format: 'medium' }}</div>
<div>Formatted date: {{ data.timestamp | ag-date-format: 'long' }}</div>

