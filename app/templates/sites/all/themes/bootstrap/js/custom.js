/*
 Custom fa icon toggle handeler.
 */
(function($){
	"use strict";
	$(document).ready(function(){
		$('body.page-node-172 .link').click(function(){
			var icon = $(this).find('i'); 
			icon.toggleClass("fa-angle-double-right fa-angle-double-down");
		});
		/**
		 * [if jr_overlay div exist]
		 * @param  {[null]} $('#jr_overlay') [none]
		 * @return {[null]}                  [none]
		 */
		if( $('#jr_overlay').length !== 0 ){
			var str = $("#jr_close p").html(),
			regex = /(hallways_site_manager@gsa.gov)/,
			chromeurl = 'https://support.google.com/chrome/answer/95346?hl=en',
			safariurl = 'https://support.apple.com/downloads/safari';
			/**
			 * Replace Safari or Chrome links dynamically. 
			 */
			$('#jr_safari').find('a').attr('href',safariurl);
			$('#jr_chrome').find('a').attr('href',chromeurl);
			/*
				Wrap mailto:mail around contact email string.
			 */
			$("#jr_close p").html(str.replace(regex,'<a style="display:inline; color:#428bca;" href="mailto:$1">$1</a>'));
		}
	});
}(jQuery));
