---
title: pinning
slug: pin
---

Pinning functionality provides the pinning the items similar to marking them as favorites.

### Demo

<ag-pin
    data-type="solution"
    data-item="solution"
    data-notify="notifyPinned"
    callback="togglePinned"
    ></ag-pin>


### HTML

```HTML
<ag-pin
    data-type="solution"
    data-item="solution"
    data-notify="notifyPinned"
    callback="togglePinned"
    ></ag-pin>
```

### OPTIONS

| Options                  | Type         	   | Default/Values        |   Description                  |
| ------------------------ | ----------------- | --------------------- | ------------------------------ |
| type                     | string            |required, can't be null| Type of pin feature applied to |
| item                     | string            | null                  |                                |
| notify                   | boolean           | false                 | Indicates whether or not the pinning applied |
| callback                 |                   |                       |                                |
