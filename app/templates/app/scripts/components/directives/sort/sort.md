---
title: Sort
slug: sort-directive
---

Sort directive provides a unified sorting functionality that can be used across the application. The ag-sort component will insert a sort button that when clicked will show a dropdown of all sort options. The directive takes as parameters an array of sorting options, and an object that should hold the current sort parameters, and a collection of items that the directive will manage the sorting for.

### Usage
```html
<ag-sort
  data-collection="itemsToSort"
  data-sort-options="allSortOptions"
  data-current-sort="currentSortOption"
  ></ag-sort>
```

### OPTIONS
| Options                  | Type         	   | Default/Values      |   Description              |
| ------------------------ | ----------------- | ------------------- | -------------------------- |      
| collection               | Array             |                     | The collection of items the directive will sort                           |
| sortOptions              | Object            |                     | Array containing all of the available sorting options. Each item in the array should be an object with a "field" property which is the field to sort by, "label" property which is the label shown to the user, and "defaultOrder" which is a boolean which if true this option will sort the items in reverse order by default                           |
| currentSort              | Object            |                     | The object in the scope that will hold the current sorting option, will contain a "field" property, and a "reverseOrder" property                           |

### Demo
<ag-sort
  data-collection="itemsToSort"
  data-sort-options="allSortOptions"
  data-current-sort="currentSortOption"></ag-sort>
