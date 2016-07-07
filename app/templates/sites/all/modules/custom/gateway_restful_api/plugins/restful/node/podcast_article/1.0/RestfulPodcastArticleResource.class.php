<?php

class RestfulPodcastArticleResource extends AGRestfulEntityBase {
	public function publicFieldsInfo() {
		$public_fields = parent::publicFieldsInfo();
		
		$public_fields['body'] = array(
	      'property' => 'body',
	      'sub_property' => 'value',
	      'full_view' => TRUE,
	    );

	    $public_fields['status'] = array(
	      'property' => 'status',
	      'full_view' => TRUE,
   		 );

	   	$public_fields['description'] = array(
	      'property' => 'field_podcast_description',
	      'full_view' => TRUE,
   		 );

	   	$public_fields['group'] = array(
	      'property' => 'field_podcast_group',
	      'full_view' => TRUE,
   		 );

	return $public_fields;
	} 
}