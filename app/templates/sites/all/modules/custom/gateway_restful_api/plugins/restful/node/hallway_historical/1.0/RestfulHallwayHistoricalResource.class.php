<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class RestfulHallwayHistoricalResource extends AGRestfulEntityBase {
  /**
  *
  *   @SWG\Definition(
  *   definition="histfile",
  *   @SWG\Property(
  *     property="fid",
  *     type="string",
  *     description="fid"
  *   ),
  *   @SWG\Property(
  *     property="uid",
  *     type="string",
  *     description="uid"
  *   ),
  *   @SWG\Property(
  *     property="filename",
  *     type="string",
  *     description="filename"
  *   ),
  *   @SWG\Property(
  *     property="uri",
  *     type="string",
  *     description="uri",
  *   ),
  *   @SWG\Property(
  *     property="filemime",
  *     type="string",
  *     description="mime type of file"
  *   ),
  *   @SWG\Property(
  *     property="filesize",
  *     type="string",
  *     description="size of file"
  *   ),
  *   @SWG\Property(
  *     property="status",
  *     type="string",
  *     description="status"
  *   ),
   *   @SWG\Property(
  *     property="timestamp",
  *     type="string",
  *     description="timestamp"
  *   ),
  *   @SWG\Property(
  *     property="origname",
  *     type="string",
  *     description="origname",
  *   ),
  *   @SWG\Property(
  *     property="type",
  *     type="string",
  *     description="type"
  *   ),
  *   @SWG\Property(
  *     property="uuid",
  *     type="string",
  *     description="uuid"
  *   ),
  *   @SWG\Property(
  *     property="rdf_mapping",
  *     type="array",
  *     description="rdf_mapping"
  *   ),
  *   @SWG\Property(
  *     property="display",
  *     type="string",
  *     description="display"
  *   ),
  *   @SWG\Property(
  *     property="description",
  *     type="string",
  *     description="description"
  *   ),
  *  )
  * 
  * @SWG\Definition(
  *   definition="HallwayHistorical",
  *   @SWG\Property(
  *     property="id",
  *     type="integer",
  *     description="Id of hallway-historical resource"
  *   ),
  *   @SWG\Property(
  *     property="label",
  *     type="string",
  *     description="Display name of the hallway history resource"
  *   ),
  *   @SWG\Property(
  *     property="self",
  *     type="string",
  *     description="permalink to the hallway-historical with a specific id"
  *   ),
  *   @SWG\Property(
  *     property="author",
  *     type="object",
  *     description="Provides author/user information for the hallway historical",
  *     ref="#/definitions/author"
  *   ),
  *   @SWG\Property(
  *     property="uid",
  *     type="string",
  *     description="Id of user"
  *   ),
  *   @SWG\Property(
  *     property="status",
  *     type="string",
  *     description="Status"
  *   ),
  *   @SWG\Property(
  *     property="histlinkabletitle",
  *     type="object",
  *     description="Display the linkable historical title"
  *   ),
  *   @SWG\Property(
  *     property="histtitleasfile",
  *     type="string",
  *     description="history title as file"
  *   ),
  *   @SWG\Property(
  *     property="histtitlefilelabel",
  *     type="string",
  *     description="Label of history title file"
  *   ),
  *   @SWG\Property(
  *     property="histurl",
  *     type="string",
  *     description="history url"
  *   ),
  *   @SWG\Property(
  *     property="histfile",
  *     type="array",
  *     description="List of history file",
  *     @SWG\Items(ref="#/definitions/histfile")
  *   ),
  *   @SWG\Property(
  *     property="body",
  *     type="string",
  *     description="Body text of hallway historical"
  *   ),
  *   @SWG\Property(
  *     property="url",
  *     type="string",
  *     description="Url of hallway"
  *   ),
  *   
  * )
  *
  */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();
    
    $public_fields['histlinkabletitle'] = array(
      'property' => 'field_historical_linkable_title',
      'full_view' => TRUE,
    );

    $public_fields['histtitleasfile'] = array(
      'property' => 'field_historical_title_as_file',
      'full_view' => TRUE,
    );

    $public_fields['histtitlefilelabel'] = array(
      'property' => 'field_historical_title_file_labe',
      'full_view' => TRUE,
    );  

    $public_fields['histurl'] = array(
      'property' => 'field_historical_url',
      'full_view' => TRUE,
    );

    $public_fields['histfile'] = array(
      'property' => 'field_historical_file',
      'full_view' => TRUE,
    );
    
    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'full_view' => TRUE,
    );
    
    $public_fields['url'] = array(
      'property' => 'url',
      'full_view' => TRUE,
    );

   /**
    *     @SWG\Path(
    *    path="/hallway-historical",
    *    @SWG\Get(
    *      tags={"Hallway Historical"},
    *      summary="Provides a list of hallways history objects",
    *      @SWG\Response(
    *        response=200,
    *        description="list of hallways history objects",
    *        @SWG\Schema(
    *          type="object",
    *          @SWG\Property(
    *            property="data",
    *            type="array",
    *            @SWG\Items(ref="#/definitions/Hallway-Historical")
    *          )
    *        )
    *      )
    *    )
    *  )
    */

    return $public_fields;
  }
}