---
title: Accordion Select
slug: accordion-select
---

This directive can be used to replace a dropdown select and offeres single or multiple select options

### Demo	

<button
        data-placement="bottom"
        data-animation="am-flip-x"
        id="purchasingOrganization"
        ng-if="categories.length > 0 && allSubcategories.length > 0 && contractTypes.length > 0 && programTypes.length > 0 && availableTo.length > 0 && allSolutions.length > 0"
        model="accordianSelects.agency"
        data-collection="availableTo"
        display-text-field="name"
        value-field=""
        data-target="moreSearch"
        data-target-field="availableTo"
        data-change="changeFilter"
        data-dont-expand-initially="true"
        placeholder="My Agency"
        is-parent-on-empty="fkOptionParentId"
        help="agency"
        help-data="help"
        data-filter-counts="filterCountUpdater.filterCounts.availableTo"
        ag-accordion-select
      ></button>


### HTML

```HTML
 <button
        data-placement="bottom"
        data-animation="am-flip-x"
        id="purchasingOrganization"
        ng-if="categories.length > 0 && allSubcategories.length > 0 && contractTypes.length > 0 && programTypes.length > 0 && availableTo.length > 0 && allSolutions.length > 0"
        model="accordianSelects.agency"
        data-collection="availableTo"
        display-text-field="name"
        value-field=""
        data-target="moreSearch"
        data-target-field="availableTo"
        data-change="changeFilter"
        data-dont-expand-initially="true"
        placeholder="My Agency"
        is-parent-on-empty="fkOptionParentId"
        help="agency"
        help-data="help"
        data-filter-counts="filterCountUpdater.filterCounts.availableTo"
        ag-accordion-select
      ></button>
 ```

### OPTIONS

| Options                  | Type         	   | Default/Values      |   Description              |
| ------------------------ | ----------------- | ------------------- | -------------------------- |      
| target                   | scope property |required, can't be null | scope property to assign the selected value(s) to |
| targetField              | string | null | If target is an object, this indicates what field in the target to use as the selected value. If null and target is an object, the entire object is used as the value |
| multiple                 | boolean  | false | Indicates whether or not this accordion select allows multiple value selections |
| placeholder              | the placeholder text |                     |                            |
| displayTextField         |                   |                     |                            |
| valueField               |                   |                     |                            |
| collection               |                   |                     |                            |
| change                   |                   |                     |                            |
| isParentOnEmpty          |                   |                     |                            |
| help                     |                   |                     |                            |
| helpData                 |                   |                     |                            |
| orderBy                  |                   |                     |                            |
| filterCounts             |                   |                     |                            |
| filterCountKey           |                   |                     |                            |
| model                    |                   |                     |                            |
| expanded                 |                   |                     |                            |
| dontExpandInitially      |                   |                     |                            | 
