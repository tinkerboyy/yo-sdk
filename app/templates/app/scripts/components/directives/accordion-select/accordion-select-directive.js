define(
  [
    'angular',
    'lodash',
    'jqueryUi',
    'components/components-module'
  ],
  function(angular, _) {
    angular.module('gateways.components')
      .directive('agAccordionSelectScrollToSelected', function($timeout) {
        return {
          restrict: 'AE',
          link: function($scope, $element) {

            $scope.$on('agAccordionSelect.initialResize', function() {
              /**
               * Directive will scroll to the selected list item within the UL
               * for the accordian select control
               */
              $timeout(function() {
                var parentElem = $element.parent(),
                  selectedItem = $element[0].querySelector('.selected'),
                  computedStyle = window.getComputedStyle(parentElem[0]),
                  computedDisplay = computedStyle.display,
                  origDisplay = $element[0].style.display;

                if (selectedItem) {
                  if (computedDisplay === 'none') {
                    parentElem[0].style.setProperty('display', 'block', 'important');
                  }

                  if (angular.isArray(selectedItem) && selectedItem.length > 0) {
                    selectedItem = selectedItem[0];
                  }

                  $element[0].scrollTop = $element[0].scrollTop +
                    (selectedItem.offsetTop - $element[0].offsetTop) -
                    ($element[0].offsetHeight / 2) + (selectedItem.offsetHeight / 2);

                  if (computedDisplay === 'none') {
                    parentElem[0].style.display = origDisplay;
                  }
                }
              }, 1);
            });
          }
        };
      })
      .controller('AccordionSelectCtrl', function($scope, $filter, $attrs) {
        if ($scope.orderBy) {
          $scope.collection = $filter('orderBy')($scope.collection, $scope.orderBy);
        }
        if (_.isUndefined($scope.model)) {
          $scope.model = {};
        }

        $scope.model.expanded = angular.copy($scope.expanded);

        //Track selected items
        $scope.selectedItems = [];

        //Default filterCountKey to 'id' if not specified
        if (typeof $scope.filterCountKey !== 'string' || $scope.filterCountKey.length === 0) {
          $scope.filterCountKey = 'id';
        }

        $scope.doSelect = function(item, valueField) {
          var data
            , items = $scope.selectedItems;
          if ($attrs.multiple) {

            //If current item is selected, unselect
            if (items.indexOf(item) >= 0) {
              items.splice(items.indexOf(item), 1);
            } else {
              items.push(item);
            }

            data = _.map($scope.selectedItems, function(i) {
              return i[valueField] || i;
            });
          } else {

            if (items.indexOf(item) >= 0) {
              items.splice(0, 1);
              data = null;
            } else {
              //for single select, always reset selections array
              items.splice(0, 1);
              items.push(item);
              data = item[valueField] || item;
            }
          }

          if (typeof $scope.target === 'object' && $scope.targetField) {
            $scope.target[$scope.targetField] = data;
          } else {
            $scope.target = data;
          }

          if ($scope.change) {
            $scope.change();
          }
        };

        //Set selected state of option
        $scope.checkSelected = function(item, valueField) {
          if (angular.isArray($scope.target[$scope.targetField])) {
            if ($scope.target[$scope.targetField] && $scope.target[$scope.targetField].length > 0 && ($scope.target[$scope.targetField].indexOf(item[valueField]) >= 0 || $scope.target[$scope.targetField].indexOf(item) >= 0 )) {
              if ($scope.selectedItems.indexOf(item) < 0) {
                $scope.selectedItems.push(item);
              }
            } else {
              if ($scope.selectedItems.indexOf(item) < 0 && $scope.target[$scope.targetField].length === 0) {
                $scope.selectedItems.splice($scope.selectedItems.indexOf(item), 1);
              }
            }
          } else {
            if ($scope.target[$scope.targetField] && ($scope.target[$scope.targetField] === item[valueField] || $scope.target[$scope.targetField] === item)) {
              if ($scope.selectedItems.indexOf(item) < 0) {
                $scope.selectedItems.push(item);
              }
            } else {
              if ($scope.selectedItems.indexOf(item) >= 0 || $scope.selectedItems.length === 0) {
                $scope.selectedItems.length = 0;
              }
            }
          }
        };

        $scope.checkAllSelected = function() {
          $scope.selectedItems = [];
          angular.forEach($scope.collection, function(item) {
            $scope.checkSelected(item, $scope.valueField);
          });
        };

        $scope.toggle = function() {
          $scope.model.expanded = !$scope.model.expanded;
          $scope.$emit('agContentUpdated');
        };
      })
      .directive('agAccordionSelect', function() {
        return {
          restrict: 'AE',
          controller: 'AccordionSelectCtrl',
          replace: true,
          templateUrl: 'scripts/components/directives/accordion-select/accordion-select.html',
          scope: {
            target: '=',
            targetField: '@',
            multiple: '=',
            placeholder: '@',
            displayTextField: '@',
            valueField: '@',
            collection: '=',
            change: '=',
            isParentOnEmpty: '@',
            help: '@',
            helpData: '=',
            orderBy: '@',
            filterCounts: '=',
            filterCountKey: '@',
            model: '=?',
            expanded: '=',
            id: '@',
            tooltipField: '@'
          },
          link: function(scope) {
            scope.$watch('target', function() {
              scope.checkAllSelected();
            }, true);
          }
        };
      })
      .directive('agAccordionSelectResizable', function(DataService, AGService, $timeout) {
        return {
          restrict: 'A',
          link: function(scope, elem, attrs) {
            var expandedOnce = false
              , screenData = AGService.data.user.preferences.screen[scope.id]

            //Resize event handler
              , onResize = function(e, ui) {
                ui.size.expanded = true;
                DataService.Preferences.create({
                  action: 'screen',
                  type: scope.id,
                  itemId: Date.now().toString().substr(0, 10),
                  data: ui.size
                }, function(data) {
                  var dat = data.data[0];
                  AGService.data.user.preferences.screen[dat.type] = dat.data;
                });
              };

            if (screenData) {
              scope.model.expanded = screenData.expanded;
            }

            //Calculates the computed mix/max height of the scrollable area
            //based on the height of the items in the list
            function getMinMaxHeight(elem) {
              var hideAgain = false,
                origDisplay = elem.css('display'),
                totalVerticalPaddingMargin,
                maxHeight = 0,
                minHeight = 0,
                i = 0,
                lastElem = null,
                origHeight;

              if (origDisplay === 'none') {
                elem[0].style.setProperty('display', 'block', 'important');
                hideAgain = true;
              }

              totalVerticalPaddingMargin = elem.outerHeight(false) - elem.height();

              //Change height of list to 10px so we force a scrollbar so that it
              //calculates the heights of the elements as if the scrollbar is
              //enabled, otherwise it will not account for wrapping that can
              //occur when scrollbar is visible
              origHeight = elem.find('ul')[0].style.height;
              elem.find('ul').css('height', '10px');

              //Loop through items and calculate min/max height
              elem.find('li').each(function() {
                var $this = $(this),
                  elemHeight = $this.outerHeight(false),
                  lastBottomMargin = lastElem ? parseInt(lastElem.css('marginBottom').replace('px', ''), 10) : 0,
                  topMargin = parseInt($this.css('marginTop').replace('px', ''), 10),
                  bottomMargin = 0;

                if (isNaN(lastBottomMargin)) {
                  lastBottomMargin = 0;
                }
                if (isNaN(topMargin)) {
                  topMargin = 0;
                }

                if ($this.is(':last-child')) {
                  bottomMargin = parseInt($this.css('marginBottom').replace('px', ''), 10);
                  if (isNaN(bottomMargin)) {
                    bottomMargin = 0;
                  }
                }

                elemHeight += Math.max(lastBottomMargin, topMargin) + bottomMargin;
                maxHeight += elemHeight;
                if (i < 2) {
                  minHeight += elemHeight;
                }
                i++;
                lastElem = $this;
              });
              if (hideAgain) {
                elem[0].style.removeProperty('display');
              }

              //Reset height of list back to orig value
              if (origHeight) {
                elem.find('ul').css('height');
              } else {
                elem.find('ul')[0].style.removeProperty('height');
              }

              return {
                min: minHeight + totalVerticalPaddingMargin,
                max: maxHeight + totalVerticalPaddingMargin
              };
            }

            scope.$watch('collection', function() {
              $timeout(function() {
                //If the collection has changed and resizable plugin has already
                //been initialized then update min/max height to make sure it
                //matches current select option
                if (elem.hasClass('ui-resizable')) {
                  var heights = getMinMaxHeight(elem);

                  elem.resizable({
                    minHeight: heights.min,
                    maxHeight: heights.max,
                    stop: onResize
                  });
                }
              }, 0);
            });

            scope.$watch('model.expanded', function() {
              $timeout(function() {
                var heights = getMinMaxHeight(elem);

                if (scope.model.expanded) {
                  if (!expandedOnce) {
                    //First time we expand initialize resizable plugin and set
                    //the height to initial value
                    if (heights.max !== heights.min || true) {
                      elem.resizable({
                        maxHeight: heights.max,
                        maxWidth: elem.outerWidth(false),
                        minHeight: heights.min,
                        minWidth: elem.outerWidth(false),
                        handle: 's,se',
                        stop: onResize
                      });
                    }

                    //If height exists in preferences, use that
                    if (screenData) {
                      elem.css('height', screenData.height);
                    } else {
                      elem.css('height', Math.min(attrs.height || 100 , heights.max));
                    }
                    expandedOnce = true;

                    scope.$broadcast('agAccordionSelect.initialResize');
                  }
                }

                DataService.Preferences.create({
                  type: scope.id,
                  action: 'screen',
                  itemId: Date.now().toString().substr(0, 10),
                  data: { expanded: scope.model.expanded }
                }, function(data) {
                  var dat = data.data[0];
                  AGService.data.user.preferences.screen[dat.type] = dat.data;
                });
              }, 0);
            });
          }
        };
      });

  }
);
