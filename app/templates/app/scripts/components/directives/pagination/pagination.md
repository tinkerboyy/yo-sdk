---
title: Pagination
slug: pagination
---

Pagination directive provides a  pagination functionality for large collection.

### Usage
```html
<ag-pagination
        data-items="topics"
        data-callback="setTopics"
        data-current-page="currentPageNumber.value">
</ag-pagination>
```

### Demo
<ag-pagination
        data-items="topics"
        data-callback="setTopics"
        data-current-page="currentPageNumber.value">
</ag-pagination>

### OPTIONS
| Options                  | Type         	   | Default/Values      |   Description                               |
| ------------------------ | ----------------- | ------------------- | --------------------------------------------|      
| items                    | Array             |                     | the collection to be paginated              |
| target                   | Object            |                     |                                             |
| currentPage              | Object            |    1                | To set the current page number, default is 1|
| order                    | Object            |                     | property name to order the collection by    |
| pageSizes                | Array             |[10, 25, 50, 100]    | pageSizes is array of page size options to display |

