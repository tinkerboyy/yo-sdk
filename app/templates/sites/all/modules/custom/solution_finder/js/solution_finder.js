//Define following block of code as a module.
//Load module dependencies
define(['angular', 'app'],
    //callback once dependencies are done loading.
  function (angular, app) {
    app.controller('SolutionFinderController',
      function($scope, $controller, $window, $filter) {
        'use strict';
        var groups = {
          itGroup:[ 'itsoftware', 'ithardware', 'itconsulting', 'telecommunications',
          "itsecurity","itoutsourcingandconsulting","itservices" ],
          offceGroup: [ 'administrativesupport', 'workplaceenvironment' ],
          professionalGroup: [ "professionalservices","cardservices" ],
          transportationLogistics: [ "smallpackagedelivery","freight","employeerelocation","motorvehicles" ],
          adminSupport: [ "adminsupport","workplaceenvironment" ]
        };

        //Defining our settings obj.
        var settings = {
          //All Hallways Groups
          itGroup: { category: '1' },
          offceGroup: { category: '6' },
          professionalGroup:{ category: '2' },
          transportationLogistics:{ category: '7' },
          adminSupport:{ category: '6' },

          //ITHallways subcategory only.
          itsoftware:{ subcategory: '20' },
          ithardware:{ subcategory: '21' },
          itconsulting:{ subcategory : '24' }, //Ask why.
          telecommunications:{ subcategory: '25' },    
          itsecurity:{ subcategory: '23' },
          itoutsourcingandconsulting:{ subcategory: '24 '},
          itservices:{ subcategory: '24' },
         
          //OffceHallways subcategory only.
          administrativesupport:{ subcategory: '51' },
          workplaceenvironment:{ subcategory: null },
         
          //ProfessionalHallways subcategory only.
          professionalservices:{ subcategory: null },
          cardservices:{ subcategory: '34' },
         
          //TransportationHallways subcategory only.
          smallpackagedelivery:{ subcategory: '54' },
          freight:{ subcategory: '57' },
          employeerelocation:{ subcategory: '55' },
          motorvehicles:{ subcategory: '58' },
         
          //Other category & subcatagory.
          toolsandhardware: { category: '5', subcategory: null },
          travel: { category: '8', subcategory: null },
          talentdevelopment: { category: '9', subcategory: '68' },
          cleaningsuppliesandchemicals: { category: '4',subcategory: '41' },
        };
        //instantiating ContractSolutionSearchController.
        $controller('SolutionsFinderController', { $scope: $scope });
        
        //Dynamic function for trigger auto select
        $scope.autoSelect = function() {
          //Assign currenthallways value coming from drupal to var currenthallways.
          if(Drupal.settings.hasOwnProperty('solution_finder')){
            var currenthallways = Drupal.settings.solution_finder.hallways;
            if(settings[currenthallways]){
              //Assign currenthallways category and subcategory to selcategory and selsubcategory.
              var selectCategory = settings[currenthallways].category,
                  selectSubCategory = settings[currenthallways].subcategory;


              //Conditionally assign category id's.
              if (typeof selectCategory !== "number"){
                for(var group in groups){
                  if(groups.hasOwnProperty(group) && groups[group].indexOf(currenthallways) !== -1) {
                    selectCategory = settings[group].category;
                    break;
                  }
                }
              }

              $scope.moreSearch.categories = [selectCategory && selectCategory.toString()];
              $scope.moreSearch.subcategories = $filter('filter')($scope.allSubcategories, { id: selectSubCategory}, true);
              $scope.setSubcategories();
            }
          }
        }

        //SubmitQuery event handler.
        $scope.submitQuery = function(url,parameters) {
            var query = '/#/solutionsfinder?';
            for(var key in parameters) {
                if(parameters.hasOwnProperty(key)) {
                  if(parameters[key] !== undefined && parameters[key] !== null) {
                    var param;
                    if (!angular.isObject(parameters[key])) { 
                      param = parameters[key];
                    }
                    else {
                      param = _.map(parameters[key], function(parameter) { 
                        if (!angular.isObject(parameter)) {
                          return parameter;
                        } else {
                          return parameter.id;
                        }
                      });
                    }
                   query += key + '=' + param + '&';
                  }
                }
            }
            query = query.substr(0, query.length - 1);
            $window.location.replace(url + query);
        };
      }
    );
  }
);
