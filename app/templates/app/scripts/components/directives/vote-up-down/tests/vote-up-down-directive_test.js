define(
  [
    'angular',
    'angularMocks',
    'components/components-module',
    'components/directives/vote-up-down/vote-up-down-directive'
    ],
    function(angular) {
      describe('$agVotes service', function() {
        var $rootScope,
          DataService,
          $agVotes;

        beforeEach(module('gateways.components'));

        beforeEach(inject(function(_$rootScope_, _DataService_, _$agVotes_, _$httpBackend_) {
          $rootScope = _$rootScope_;
          DataService = _DataService_;
          $agVotes = _$agVotes_;
          $httpBackend = _$httpBackend_;
          $httpBackend.when('GET', '/api/v1.0/preferences').respond({ data: [] });
        }));

        it('should merge loaded votes with collection', function() {
          var sows = [
              {id: 123},
              {id: 234},
              {id: 345}
            ],
            votes = {
              data: [
                {itemId: 123, votes: 5},
                {itemId: 234, votes: 10},
                {itemId: 345, votes: -3}
              ]
            },
            sowsWithVotes = [
              {id: 123, votes: 5},
              {id: 234, votes: 10, highestVoted: true},
              {id: 345, votes: -3}
            ];

          spyOn(DataService.Votes, 'get').and.callFake(function () {
            return {
              $promise: {
                then: function (callback) {
                    return callback(votes);
                }
              }
            };
          });

          $agVotes.mergeVotesWithCollection('sow', sows);
          $rootScope.$apply();

          expect(DataService.Votes.get).toHaveBeenCalledWith({type: 'sow'});

          expect(sows).toEqual(sowsWithVotes);
        });
      });

      describe('Vote Up/Down Directive', function() {
        var target = {};
        var $scope = {};
        var $attrs = {};
        var changeSpy = jasmine.createSpy('changeSpy');

        beforeEach(module('gateways.components'));

        beforeEach(inject(function($rootScope, $controller, AGService) {
          $scope = $rootScope.$new();
          $scope = {
            collection: [
              { name: 'item 1', id: 1 },
              { name: 'item 2', id: 2 },
              { name: 'item 3', id: 3 },
              { name: 'item 4', id: 4 },
            ],
            targetField: 'test',
            valueField: 'id',
            target: target,
            displayTextField: 'name',
            change: changeSpy,
            orderBy: 'name'
          };

          $controller('VoteUpDownController', {
            $scope: $scope,
            $attrs: $attrs
          });
        }));


      });
    }
)
