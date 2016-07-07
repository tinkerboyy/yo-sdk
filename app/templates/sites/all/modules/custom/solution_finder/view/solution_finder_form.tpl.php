<!-- Render form in template.  -->
<form id="solutionFinderWidget" class="form-horizontal" ng-controller="SolutionFinderController">
<div class="title-banner">Find a solution.</div>
<div ng-if="categories.length === 0 || allSubcategories.length === 0 || availableTo.length === 0 || allSolutions.length === 0">
        <center><i class="fa fa-spinner fa-spin fa-4x"></i><p>Loading...</p></center>
</div> 
<div class="sf-panel" ng-if="categories.length > 0 && allSubcategories.length > 0 && allSolutions.length > 0" ng-init="toggleSearch(true)" ng-cloak>
	<div class="clearfix">&nbsp;</div>
     <div class="col-xs-12 col-sm-4">
     	<label
        for="purchasingOrganization"
        class="control-label">
        My Agency
      </label>
      </div>
      <div class="col-xs-12 col-sm-8 agency">
        <div bs-tooltip="'Acquiring agency or agency for whom the acquisition is being conducted'">
          <button 
            bs-select
            template= "/sites/all/modules/custom/solution_finder/view/smart-select.html"
            title="'Acquiring agency or agency for whom the acquisition is being conducted'"
            data-placement="bottom"
            id="purchasingOrganization"
            class="form-control"
            placeholder="- Select -"
            bs-options="availableToOption  as availableToOption.name for availableToOption in availableTo"
            ng-model="moreSearch.availableTo"
            ng-change="changeFilter(moreSearch, 'availableTo')"
          ></button>
          </div>
      </div>
    <div class="clearfix">&nbsp;</div>
    <div class="container-fluid">
    <div class="col-xs-12 col-sm-4" >
      <label
        for="ProductCategories"
        class="control-label">
        Category
      </label>
      </div>
      <div class="col-xs-12 col-sm-8">
         <button
         ng-init="setSubcategories(); autoSelect()"
         bs-tooltip="'Select a product or service category'"
         data-placement="bottom"
         data-multiple="1"
         class="form-control btn btn-default"
         id="ProductCategories"
         bs-options="category.id as category.name for category in categories | orderBy: 'name'"
         placeholder="- Select -"
         max-length="1"
         ng-model="moreSearch.categories"
         ng-change="setSubcategories()"
         bs-select
        ></button>
      </div>
    </div>
		<div class="clearfix">&nbsp;</div>
    <div
      class="container-fluid">
      <div class="col-xs-12 col-sm-4">
      <label
        for="ProductCategories"
        class="control-label">
        Subcategory
      </label>
      </div>
      <div class="col-xs-12 col-sm-8" >
        <div bs-tooltip="'Select a product or service subcategory'">
          <button  
            template="/sites/all/modules/custom/solution_finder/view/smart-select.html"
            title="'Select a product or service subcategory'"
            data-placement="bottom"
            data-multiple="1"
            class="form-control btn btn-default"
            placeholder="- Select -"
            ng-disabled="!moreSearch.categories"
            class="form-control"
            max-length="1"
            id="productSubcategory"
            bs-select
            bs-options="subCategory as subCategory.name for subCategory in subCategories"
            ng-model="moreSearch.subcategories"
          ></button>
         </div>
      </div>
    </div>

  <div class="clearfix">&nbsp;</div>
  <div class="col-xs-12 col-sm-3">
    <input ng-click="submitQuery('app',{ agency: moreSearch.availableTo.id, category: moreSearch.categories, 
    subcategory: moreSearch.subcategories })" class="btn btn-default btn-block" type="submit" value="View"/>
  </div>
   <div class="col-xs-12 col-sm-8 counter"> 
    <button type="submit" class="btn btn-default btn-xs pull-right" ng-click="toggleSearch(true)">Reset</button>
    <strong class="solutions-counter">{{(solutions | searchSolutions: moreSearch).length + (allSolutions | filter: { pinned: 'true' }).length || 0 }}</strong>
    Solutions available
   </div>
    <div class="clearfix">&nbsp;</div>
  </div> 
</form>
