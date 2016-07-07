$(document).ready(function () {    
var elem=$('#cvt ul');      
	$('#viewcontrols a').on('click',function(e) {
		if ($(this).hasClass('gridview')) {
			elem.fadeOut(400, function () {
				$('#cvt ul').removeClass('list').addClass('grid');
				$('#viewcontrols').removeClass('view-controls-list').addClass('view-controls-grid');
				$('#viewcontrols .gridview').addClass('active');
				$('#viewcontrols .listview').removeClass('active');
				elem.fadeIn(700);
			});						
		}
		else if($(this).hasClass('listview')) {
			elem.fadeOut(400, function () {
				$('#cvt ul').removeClass('grid').addClass('list');
				$('#viewcontrols').removeClass('view-controls-grid').addClass('view-controls-list');
				$('#viewcontrols .gridview').removeClass('active');
				$('#viewcontrols .listview').addClass('active');
				elem.fadeIn(700);
			});									
		}
	});
});

/* ========================================================================
 * Bootstrap: podcast.js v3.3.1
 * http://getbootstrap.com/javascript/#podcasts
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */


+function ($) {
  'use strict';

  // MODAL CLASS DEFINITION
  // ======================

  var Podcast = function (element, options) {
    this.options        = options
    this.$body          = $(document.body)
    this.$element       = $(element)
    this.$backdrop      = false
    this.isShown        = null
    this.scrollbarWidth = 0

    if (this.options.remote) {
      this.$element
        .find('.podcast-content')
        .load(this.options.remote, $.proxy(function () {
          this.$element.trigger('loaded.bs.podcast')
        }, this))
    }
  }

  Podcast.VERSION  = '3.3.1'

  Podcast.TRANSITION_DURATION = 300
  Podcast.BACKDROP_TRANSITION_DURATION = 150

  Podcast.DEFAULTS = {
    backdrop: false,
    keyboard: true,
    show: true
  }

  Podcast.prototype.toggle = function (_relatedTarget) {
    return this.isShown ? this.hide() : this.show(_relatedTarget)
  }

  Podcast.prototype.show = function (_relatedTarget) {
    var that = this
    var e    = $.Event('show.bs.podcast', { relatedTarget: _relatedTarget })

    this.$element.trigger(e)

    if (this.isShown || e.isDefaultPrevented()) return

    this.isShown = true

    this.checkScrollbar()
    this.setScrollbar()
    this.$body.addClass('podcast-open')

    this.escape()
    this.resize()

    this.$element.on('click.dismiss.bs.podcast', '[data-dismiss="podcast"]', $.proxy(this.hide, this))

    this.backdrop(function () {
      var transition = $.support.transition && that.$element.hasClass('fade')

      if (!that.$element.parent().length) {
        that.$element.appendTo(that.$body) // don't move podcasts dom position
      }

      that.$element
        .show()
        .scrollTop(0)

      if (that.options.backdrop) that.adjustBackdrop()
      that.adjustDialog()

      if (transition) {
        that.$element[0].offsetWidth // force reflow
      }

      that.$element
        .addClass('in')
        .attr('aria-hidden', false)

      that.enforceFocus()

      var e = $.Event('shown.bs.podcast', { relatedTarget: _relatedTarget })

      transition ?
        that.$element.find('.podcast-dialog') // wait for podcast to slide in
          .one('bsTransitionEnd', function () {
            that.$element.trigger('focus').trigger(e)
          })
          .emulateTransitionEnd(Podcast.TRANSITION_DURATION) :
        that.$element.trigger('focus').trigger(e)
    })
  }

  Podcast.prototype.hide = function (e) {
    if (e) e.preventDefault()

    e = $.Event('hide.bs.podcast')

    this.$element.trigger(e)

    if (!this.isShown || e.isDefaultPrevented()) return

    this.isShown = false

    this.escape()
    this.resize()

    $(document).off('focusin.bs.podcast')

    this.$element
      .removeClass('in')
      .attr('aria-hidden', true)
      .off('click.dismiss.bs.podcast')

    $.support.transition && this.$element.hasClass('fade') ?
      this.$element
        .one('bsTransitionEnd', $.proxy(this.hidePodcast, this))
        .emulateTransitionEnd(Podcast.TRANSITION_DURATION) :
      this.hidePodcast()
  }

  Podcast.prototype.enforceFocus = function () {
    $(document)
      .off('focusin.bs.podcast') // guard against infinite focus loop
      .on('focusin.bs.podcast', $.proxy(function (e) {
        if (this.$element[0] !== e.target && !this.$element.has(e.target).length) {
          this.$element.trigger('focus')
        }
      }, this))
  }

  Podcast.prototype.escape = function () {
    if (this.isShown && this.options.keyboard) {
      this.$element.on('keydown.dismiss.bs.podcast', $.proxy(function (e) {
        e.which == 27 && this.hide()
      }, this))
    } else if (!this.isShown) {
      this.$element.off('keydown.dismiss.bs.podcast')
    }
  }

  Podcast.prototype.resize = function () {
    if (this.isShown) {
      $(window).on('resize.bs.podcast', $.proxy(this.handleUpdate, this))
    } else {
      $(window).off('resize.bs.podcast')
    }
  }

  Podcast.prototype.hidePodcast = function () {
    var that = this
    this.$element.hide()
    this.backdrop(function () {
      that.$body.removeClass('podcast-open')
      that.resetAdjustments()
      that.resetScrollbar()
      that.$element.trigger('hidden.bs.podcast')
    })
  }

  Podcast.prototype.removeBackdrop = function () {
    this.$backdrop && this.$backdrop.remove()
    this.$backdrop = null
  }

  Podcast.prototype.backdrop = function (callback) {
    var that = this
    var animate = this.$element.hasClass('fade') ? 'fade' : ''

    if (this.isShown && this.options.backdrop) {
      var doAnimate = $.support.transition && animate

      this.$backdrop = $('<div class="podcast-backdrop ' + animate + '" />')
        .prependTo(this.$element)
        .on('click.dismiss.bs.podcast', $.proxy(function (e) {
          if (e.target !== e.currentTarget) return
          this.options.backdrop == 'static'
            ? this.$element[0].focus.call(this.$element[0])
            : this.hide.call(this)
        }, this))

      if (doAnimate) this.$backdrop[0].offsetWidth // force reflow

      this.$backdrop.addClass('in')

      if (!callback) return

      doAnimate ?
        this.$backdrop
          .one('bsTransitionEnd', callback)
          .emulateTransitionEnd(Podcast.BACKDROP_TRANSITION_DURATION) :
        callback()

    } else if (!this.isShown && this.$backdrop) {
      this.$backdrop.removeClass('in')

      var callbackRemove = function () {
        that.removeBackdrop()
        callback && callback()
      }
      $.support.transition && this.$element.hasClass('fade') ?
        this.$backdrop
          .one('bsTransitionEnd', callbackRemove)
          .emulateTransitionEnd(Podcast.BACKDROP_TRANSITION_DURATION) :
        callbackRemove()

    } else if (callback) {
      callback()
    }
  }

  // these following methods are used to handle overflowing podcasts

  Podcast.prototype.handleUpdate = function () {
    if (this.options.backdrop) this.adjustBackdrop()
    this.adjustDialog()
  }

  Podcast.prototype.adjustBackdrop = function () {
    this.$backdrop
      .css('height', 0)
      .css('height', this.$element[0].scrollHeight)
  }

  Podcast.prototype.adjustDialog = function () {
    var podcastIsOverflowing = this.$element[0].scrollHeight > document.documentElement.clientHeight

    this.$element.css({
      paddingLeft:  !this.bodyIsOverflowing && podcastIsOverflowing ? this.scrollbarWidth : '',
      paddingRight: this.bodyIsOverflowing && !podcastIsOverflowing ? this.scrollbarWidth : ''
    })
  }

  Podcast.prototype.resetAdjustments = function () {
    this.$element.css({
      paddingLeft: '',
      paddingRight: ''
    })
  }

  Podcast.prototype.checkScrollbar = function () {
    this.bodyIsOverflowing = document.body.scrollHeight > document.documentElement.clientHeight
    this.scrollbarWidth = this.measureScrollbar()
  }

  Podcast.prototype.setScrollbar = function () {
    var bodyPad = parseInt((this.$body.css('padding-right') || 0), 10)
    if (this.bodyIsOverflowing) this.$body.css('padding-right', bodyPad + this.scrollbarWidth)
  }

  Podcast.prototype.resetScrollbar = function () {
    this.$body.css('padding-right', '')
  }

  Podcast.prototype.measureScrollbar = function () { // thx walsh
    var scrollDiv = document.createElement('div')
    scrollDiv.className = 'podcast-scrollbar-measure'
    this.$body.append(scrollDiv)
    var scrollbarWidth = scrollDiv.offsetWidth - scrollDiv.clientWidth
    this.$body[0].removeChild(scrollDiv)
    return scrollbarWidth
  }


  // MODAL PLUGIN DEFINITION
  // =======================

  function Plugin(option, _relatedTarget) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.podcast')
      var options = $.extend({}, Podcast.DEFAULTS, $this.data(), typeof option == 'object' && option)

      if (!data) $this.data('bs.podcast', (data = new Podcast(this, options)))
      if (typeof option == 'string') data[option](_relatedTarget)
      else if (options.show) data.show(_relatedTarget)
    })
  }

  var old = $.fn.podcast

  $.fn.podcast             = Plugin
  $.fn.podcast.Constructor = Podcast


  // MODAL NO CONFLICT
  // =================

  $.fn.podcast.noConflict = function () {
    $.fn.podcast = old
    return this
  }


  // MODAL DATA-API
  // ==============

  $(document).on('click.bs.podcast.data-api', '[data-toggle="podcast"]', function (e) {
    var $this   = $(this)
    var href    = $this.attr('href')
    var $target = $($this.attr('data-target') || (href && href.replace(/.*(?=#[^\s]+$)/, ''))) // strip for ie7
    var option  = $target.data('bs.podcast') ? 'toggle' : $.extend({ remote: !/#/.test(href) && href }, $target.data(), $this.data())

    if ($this.is('a')) e.preventDefault()

    $target.one('show.bs.podcast', function (showEvent) {
      if (showEvent.isDefaultPrevented()) return // only register focus restorer if podcast will actually get shown
      $target.one('hidden.bs.podcast', function () {
        $this.is(':visible') && $this.trigger('focus')
      })
    })
    Plugin.call($target, option, this)
  })

}(jQuery);

/* ========================================================================
 * Bootstrap: videoplayer.js v3.3.1
 * http://getbootstrap.com/javascript/#videoplayers
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */


+function ($) {
  'use strict';

  // MODAL CLASS DEFINITION
  // ======================

  var Video = function (element, options) {
    this.options        = options
    this.$body          = $(document.body)
    this.$element       = $(element)
    this.$backdrop      = true
    this.isShown        = 
    this.scrollbarWidth = 0

    if (this.options.remote) {
      this.$element
        .find('.videoplayer-content')
        .load(this.options.remote, $.proxy(function () {
          this.$element.trigger('loaded.bs.videoplayer')
        }, this))
    }
  }

  Video.VERSION  = '3.3.1'

  Video.TRANSITION_DURATION = 300
  Video.BACKDROP_TRANSITION_DURATION = 150

  Video.DEFAULTS = {
    backdrop: false,
    keyboard: true,
    show: true
  }

  Video.prototype.toggle = function (_relatedTarget) {
    return this.isShown ? this.hide() : this.show(_relatedTarget)
  }

  Video.prototype.show = function (_relatedTarget) {
    var that = this
    var e    = $.Event('show.bs.videoplayer', { relatedTarget: _relatedTarget })

    this.$element.trigger(e)

    if (this.isShown || e.isDefaultPrevented()) return

    this.isShown = true

    this.checkScrollbar()
    this.setScrollbar()
    this.$body.addClass('videoplayer-open')

    this.escape()
    this.resize()

    this.$element.on('click.dismiss.bs.videoplayer', '[data-dismiss="videoplayer"]', $.proxy(this.hide, this))

    this.backdrop(function () {
      var transition = $.support.transition && that.$element.hasClass('fade')

      if (!that.$element.parent().length) {
        that.$element.appendTo(that.$body) // don't move videoplayers dom position
      }

      that.$element
        .show()
        .scrollTop(0)

      if (that.options.backdrop) that.adjustBackdrop()
      that.adjustDialog()

      if (transition) {
        that.$element[0].offsetWidth // force reflow
      }

      that.$element
        .addClass('in')
        .attr('aria-hidden', false)

      that.enforceFocus()

      var e = $.Event('shown.bs.videoplayer', { relatedTarget: _relatedTarget })

      transition ?
        that.$element.find('.videoplayer-dialog') // wait for videoplayer to slide in
          .one('bsTransitionEnd', function () {
            that.$element.trigger('focus').trigger(e)
          })
          .emulateTransitionEnd(Video.TRANSITION_DURATION) :
        that.$element.trigger('focus').trigger(e)
    })
  }

  Video.prototype.hide = function (e) {
    if (e) e.preventDefault()

    e = $.Event('hide.bs.videoplayer')

    this.$element.trigger(e)

    if (!this.isShown || e.isDefaultPrevented()) return

    this.isShown = false

    this.escape()
    this.resize()

    $(document).off('focusin.bs.videoplayer')

    this.$element
      .removeClass('in')
      .attr('aria-hidden', true)
      .off('click.dismiss.bs.videoplayer')

    $.support.transition && this.$element.hasClass('fade') ?
      this.$element
        .one('bsTransitionEnd', $.proxy(this.hideVideo, this))
        .emulateTransitionEnd(Video.TRANSITION_DURATION) :
      this.hideVideo()
  }

  Video.prototype.enforceFocus = function () {
    $(document)
      .off('focusin.bs.videoplayer') // guard against infinite focus loop
      .on('focusin.bs.videoplayer', $.proxy(function (e) {
        if (this.$element[0] !== e.target && !this.$element.has(e.target).length) {
          this.$element.trigger('focus')
        }
      }, this))
  }

  Video.prototype.escape = function () {
    if (this.isShown && this.options.keyboard) {
      this.$element.on('keydown.dismiss.bs.videoplayer', $.proxy(function (e) {
        e.which == 27 && this.hide()
      }, this))
    } else if (!this.isShown) {
      this.$element.off('keydown.dismiss.bs.videoplayer')
    }
  }

  Video.prototype.resize = function () {
    if (this.isShown) {
      $(window).on('resize.bs.videoplayer', $.proxy(this.handleUpdate, this))
    } else {
      $(window).off('resize.bs.videoplayer')
    }
  }

  Video.prototype.hideVideo = function () {
    var that = this
    this.$element.hide()
    this.backdrop(function () {
      that.$body.removeClass('videoplayer-open')
      that.resetAdjustments()
      that.resetScrollbar()
      that.$element.trigger('hidden.bs.videoplayer')
    })
  }

  Video.prototype.removeBackdrop = function () {
    this.$backdrop && this.$backdrop.remove()
    this.$backdrop = null
  }

  Video.prototype.backdrop = function (callback) {
    var that = this
    var animate = this.$element.hasClass('fade') ? 'fade' : ''

    if (this.isShown && this.options.backdrop) {
      var doAnimate = $.support.transition && animate

      this.$backdrop = $('<div class="videoplayer-backdrop ' + animate + '" />')
        .prependTo(this.$element)
        .on('click.dismiss.bs.videoplayer', $.proxy(function (e) {
          if (e.target !== e.currentTarget) return
          this.options.backdrop == 'static'
            ? this.$element[0].focus.call(this.$element[0])
            : this.hide.call(this)
        }, this))

      if (doAnimate) this.$backdrop[0].offsetWidth // force reflow

      this.$backdrop.addClass('in')

      if (!callback) return

      doAnimate ?
        this.$backdrop
          .one('bsTransitionEnd', callback)
          .emulateTransitionEnd(Video.BACKDROP_TRANSITION_DURATION) :
        callback()

    } else if (!this.isShown && this.$backdrop) {
      this.$backdrop.removeClass('in')

      var callbackRemove = function () {
        that.removeBackdrop()
        callback && callback()
      }
      $.support.transition && this.$element.hasClass('fade') ?
        this.$backdrop
          .one('bsTransitionEnd', callbackRemove)
          .emulateTransitionEnd(Video.BACKDROP_TRANSITION_DURATION) :
        callbackRemove()

    } else if (callback) {
      callback()
    }
  }

  // these following methods are used to handle overflowing videoplayers

  Video.prototype.handleUpdate = function () {
    if (this.options.backdrop) this.adjustBackdrop()
    this.adjustDialog()
  }

  Video.prototype.adjustBackdrop = function () {
    this.$backdrop
      .css('height', 0)
      .css('height', this.$element[0].scrollHeight)
  }

  Video.prototype.adjustDialog = function () {
    var videoplayerIsOverflowing = this.$element[0].scrollHeight > document.documentElement.clientHeight

    this.$element.css({
      paddingLeft:  !this.bodyIsOverflowing && videoplayerIsOverflowing ? this.scrollbarWidth : '',
      paddingRight: this.bodyIsOverflowing && !videoplayerIsOverflowing ? this.scrollbarWidth : ''
    })
  }

  Video.prototype.resetAdjustments = function () {
    this.$element.css({
      paddingLeft: '',
      paddingRight: ''
    })
  }

  Video.prototype.checkScrollbar = function () {
    this.bodyIsOverflowing = document.body.scrollHeight > document.documentElement.clientHeight
    this.scrollbarWidth = this.measureScrollbar()
  }

  Video.prototype.setScrollbar = function () {
    var bodyPad = parseInt((this.$body.css('padding-right') || 0), 10)
    if (this.bodyIsOverflowing) this.$body.css('padding-right', bodyPad + this.scrollbarWidth)
  }

  Video.prototype.resetScrollbar = function () {
    this.$body.css('padding-right', '')
  }

  Video.prototype.measureScrollbar = function () { // thx walsh
    var scrollDiv = document.createElement('div')
    scrollDiv.className = 'videoplayer-scrollbar-measure'
    this.$body.append(scrollDiv)
    var scrollbarWidth = scrollDiv.offsetWidth - scrollDiv.clientWidth
    this.$body[0].removeChild(scrollDiv)
    return scrollbarWidth
  }


  // MODAL PLUGIN DEFINITION
  // =======================

  function Plugin(option, _relatedTarget) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.videoplayer')
      var options = $.extend({}, Video.DEFAULTS, $this.data(), typeof option == 'object' && option)

      if (!data) $this.data('bs.videoplayer', (data = new Video(this, options)))
      if (typeof option == 'string') data[option](_relatedTarget)
      else if (options.show) data.show(_relatedTarget)
    })
  }

  var old = $.fn.videoplayer

  $.fn.videoplayer             = Plugin
  $.fn.videoplayer.Constructor = Video


  // MODAL NO CONFLICT
  // =================

  $.fn.videoplayer.noConflict = function () {
    $.fn.videoplayer = old
    return this
  }


  // MODAL DATA-API
  // ==============

  $(document).on('click.bs.videoplayer.data-api', '[data-toggle="videoplayer"]', function (e) {
    var $this   = $(this)
    var href    = $this.attr('href')
    var $target = $($this.attr('data-target') || (href && href.replace(/.*(?=#[^\s]+$)/, ''))) // strip for ie7
    var option  = $target.data('bs.videoplayer') ? 'toggle' : $.extend({ remote: !/#/.test(href) && href }, $target.data(), $this.data())

    if ($this.is('a')) e.preventDefault()

    $target.one('show.bs.videoplayer', function (showEvent) {
      if (showEvent.isDefaultPrevented()) return // only register focus restorer if videoplayer will actually get shown
      $target.one('hidden.bs.videoplayer', function () {
        $this.is(':visible') && $this.trigger('focus')
      })
    })
    Plugin.call($target, option, this)
  })

}(jQuery);

/*
	By Osvaldas Valutis, www.osvaldas.info
	Available for use under the MIT License
*/



;(function( $, window, document, undefined )
{
	var isTouch		  = 'ontouchstart' in window,
		eStart		  = isTouch ? 'touchstart'	: 'mousedown',
		eMove		  = isTouch ? 'touchmove'	: 'mousemove',
		eEnd		  = isTouch ? 'touchend'	: 'mouseup',
		eCancel		  = isTouch ? 'touchcancel'	: 'mouseup',
		secondsToTime = function( secs )
		{
			var hoursDiv = secs / 3600, hours = Math.floor( hoursDiv ), minutesDiv = secs % 3600 / 60, minutes = Math.floor( minutesDiv ), seconds = Math.ceil( secs % 3600 % 60 );
			if( seconds > 59 ) { seconds = 0; minutes = Math.ceil( minutesDiv ); }
			if( minutes > 59 ) { minutes = 0; hours = Math.ceil( hoursDiv ); }
			return ( hours == 0 ? '' : hours > 0 && hours.toString().length < 2 ? '0'+hours+':' : hours+':' ) + ( minutes.toString().length < 2 ? '0'+minutes : minutes ) + ':' + ( seconds.toString().length < 2 ? '0'+seconds : seconds );
		},
		canPlayType	  = function( file )
		{
			var audioElement = document.createElement( 'audio' );
			return !!( audioElement.canPlayType && audioElement.canPlayType( 'audio/' + file.split( '.' ).pop().toLowerCase() + ';' ).replace( /no/, '' ) );
		};

	$.fn.audioPlayer = function( params )
	{
		var params		= $.extend( { classPrefix: 'audioplayer', strPlay: 'Play', strPause: 'Pause', strVolume: 'Volume' }, params ),
			cssClass	= {},
			cssClassSub =
			{
				playPause:	 	'playpause',
				playing:		'playing',
				stopped:		'stopped',
				time:		 	'time',
				timeCurrent:	'time-current',
				timeDuration: 	'time-duration',
				bar: 			'bar',
				barLoaded:		'bar-loaded',
				barPlayed:		'bar-played',
				volume:		 	'volume',
				volumeButton: 	'volume-button',
				volumeAdjust: 	'volume-adjust',
				noVolume: 		'novolume',
				muted: 			'muted',
				mini: 			'mini'
			};

		for( var subName in cssClassSub )
			cssClass[ subName ] = params.classPrefix + '-' + cssClassSub[ subName ];

		this.each( function()
		{
			if( $( this ).prop( 'tagName' ).toLowerCase() != 'audio' )
				return false;

			var $this	   = $( this ),
				audioFile  = $this.attr( 'src' ),
				isAutoPlay = $this.get( 0 ).getAttribute( 'autoplay' ), isAutoPlay = isAutoPlay === '' || isAutoPlay === 'autoplay' ? true : false,
				isLoop	   = $this.get( 0 ).getAttribute( 'loop' ),		isLoop	   = isLoop		=== '' || isLoop	 === 'loop'		? true : false,
				isSupport  = false;

			if( typeof audioFile === 'undefined' )
			{
				$this.find( 'source' ).each( function()
				{
					audioFile = $( this ).attr( 'src' );
					if( typeof audioFile !== 'undefined' && canPlayType( audioFile ) )
					{
						isSupport = true;
						return false;
					}
				});
			}
			else if( canPlayType( audioFile ) ) isSupport = true;

			var thePlayer = $( '<div class="' + params.classPrefix + '">' + ( isSupport ? $( '<div>' ).append( $this.eq( 0 ).clone() ).html() : '<embed src="' + audioFile + '" width="0" height="0" volume="100" autostart="' + isAutoPlay.toString() +'" loop="' + isLoop.toString() + '" />' ) + '<div class="' + cssClass.playPause + '" title="' + params.strPlay + '"><a href="#">' + params.strPlay + '</a></div></div>' ),
				theAudio  = isSupport ? thePlayer.find( 'audio' ) : thePlayer.find( 'embed' ), theAudio = theAudio.get( 0 );

			if( isSupport )
			{
				thePlayer.find( 'audio' ).css( { 'width': 0, 'height': 0, 'visibility': 'hidden' } );
				thePlayer.append( '<div class="' + cssClass.time + ' ' + cssClass.timeCurrent + '"></div><div class="' + cssClass.bar + '"><div class="' + cssClass.barLoaded + '"></div><div class="' + cssClass.barPlayed + '"></div></div><div class="' + cssClass.time + ' ' + cssClass.timeDuration + '"></div><div class="' + cssClass.volume + '"><div class="' + cssClass.volumeButton + '" title="' + params.strVolume + '"><a href="#">' + params.strVolume + '</a></div><div class="' + cssClass.volumeAdjust + '"><div><div></div></div></div></div>' );

				var theBar			  = thePlayer.find( '.' + cssClass.bar ),
					barPlayed	 	  = thePlayer.find( '.' + cssClass.barPlayed ),
					barLoaded	 	  = thePlayer.find( '.' + cssClass.barLoaded ),
					timeCurrent		  = thePlayer.find( '.' + cssClass.timeCurrent ),
					timeDuration	  = thePlayer.find( '.' + cssClass.timeDuration ),
					volumeButton	  = thePlayer.find( '.' + cssClass.volumeButton ),
					volumeAdjuster	  = thePlayer.find( '.' + cssClass.volumeAdjust + ' > div' ),
					volumeDefault	  = 0,
					adjustCurrentTime = function( e )
					{
						theRealEvent		 = isTouch ? e.originalEvent.touches[ 0 ] : e;
						theAudio.currentTime = Math.round( ( theAudio.duration * ( theRealEvent.pageX - theBar.offset().left ) ) / theBar.width() );
					},
					adjustVolume = function( e )
					{
						theRealEvent	= isTouch ? e.originalEvent.touches[ 0 ] : e;
						theAudio.volume = Math.abs( ( theRealEvent.pageY - ( volumeAdjuster.offset().top + volumeAdjuster.height() ) ) / volumeAdjuster.height() );
					},
					updateLoadBar = function()
					{
						var interval = setInterval( function()
						{
							if( theAudio.buffered.length < 1 ) return true;
							barLoaded.width( ( theAudio.buffered.end( 0 ) / theAudio.duration ) * 100 + '%' );
							if( Math.floor( theAudio.buffered.end( 0 ) ) >= Math.floor( theAudio.duration ) ) clearInterval( interval );
						}, 100 );
					};

				var volumeTestDefault = theAudio.volume, volumeTestValue = theAudio.volume = 0.111;
				if( Math.round( theAudio.volume * 1000 ) / 1000 == volumeTestValue ) theAudio.volume = volumeTestDefault;
				else thePlayer.addClass( cssClass.noVolume );

				timeDuration.html( '&hellip;' );
				timeCurrent.html( secondsToTime( 0 ) );

				theAudio.addEventListener( 'loadeddata', function()
				{
					updateLoadBar();
					timeDuration.html( $.isNumeric( theAudio.duration ) ? secondsToTime( theAudio.duration ) : '&hellip;' );
					volumeAdjuster.find( 'div' ).height( theAudio.volume * 100 + '%' );
					volumeDefault = theAudio.volume;
				});

				theAudio.addEventListener( 'timeupdate', function()
				{
					timeCurrent.html( secondsToTime( theAudio.currentTime ) );
					barPlayed.width( ( theAudio.currentTime / theAudio.duration ) * 100 + '%' );
				});

				theAudio.addEventListener( 'volumechange', function()
				{
					volumeAdjuster.find( 'div' ).height( theAudio.volume * 100 + '%' );
					if( theAudio.volume > 0 && thePlayer.hasClass( cssClass.muted ) ) thePlayer.removeClass( cssClass.muted );
					if( theAudio.volume <= 0 && !thePlayer.hasClass( cssClass.muted ) ) thePlayer.addClass( cssClass.muted );
				});

				theAudio.addEventListener( 'ended', function()
				{
					thePlayer.removeClass( cssClass.playing ).addClass( cssClass.stopped );
				});

				theBar.on( eStart, function( e )
				{
					adjustCurrentTime( e );
					theBar.on( eMove, function( e ) { adjustCurrentTime( e ); } );
				})
				.on( eCancel, function()
				{
					theBar.unbind( eMove );
				});

				volumeButton.on( 'click', function()
				{
					if( thePlayer.hasClass( cssClass.muted ) )
					{
						thePlayer.removeClass( cssClass.muted );
						theAudio.volume = volumeDefault;
					}
					else
					{
						thePlayer.addClass( cssClass.muted );
						volumeDefault = theAudio.volume;
						theAudio.volume = 0;
					}
					return false;
				});

				volumeAdjuster.on( eStart, function( e )
				{
					adjustVolume( e );
					volumeAdjuster.on( eMove, function( e ) { adjustVolume( e ); } );
				})
				.on( eCancel, function()
				{
					volumeAdjuster.unbind( eMove );
				});
			}
			else thePlayer.addClass( cssClass.mini );

			thePlayer.addClass( isAutoPlay ? cssClass.playing : cssClass.stopped );

			thePlayer.find( '.' + cssClass.playPause ).on( 'click', function()
			{
				if( thePlayer.hasClass( cssClass.playing ) )
				{
					$( this ).attr( 'title', params.strPlay ).find( 'a' ).html( params.strPlay );
					thePlayer.removeClass( cssClass.playing ).addClass( cssClass.stopped );
					isSupport ? theAudio.pause() : theAudio.Stop();
				}
				else
				{
					$( this ).attr( 'title', params.strPause ).find( 'a' ).html( params.strPause );
					thePlayer.addClass( cssClass.playing ).removeClass( cssClass.stopped );
					isSupport ? theAudio.play() : theAudio.Play();
				}
				return false;
			});

			$this.replaceWith( thePlayer );
		});
		return this;
	};
})( jQuery, window, document );

$( function() { $( 'audio' ).audioPlayer(); } );


(function($) {
"use strict";
var toggle = '[data-toggle="dropdown"]',
disabled = '.disabled, :disabled',
backdrop = '.dropdown-backdrop',
menuClass = 'dropdown-menu',
subMenuClass = 'dropdown-submenu',
namespace = '.bs.dropdown.data-api',
eventNamespace = '.bs.dropdown',
openClass = 'open',
touchSupport = 'ontouchstart' in document.documentElement,
opened;
function Dropdown(element) {
$(element).on('click' + eventNamespace, this.toggle)
}
var proto = Dropdown.prototype;
proto.toggle = function(event) {
var $element = $(this);
if ($element.is(disabled)) return;
var $parent = getParent($element);
var isActive = $parent.hasClass(openClass);
var isSubMenu = $parent.hasClass(subMenuClass);
var menuTree = isSubMenu ? getSubMenuParents($parent) : null;
closeOpened(event, menuTree);
if (!isActive) {
if (!menuTree)
menuTree = [$parent];
if (touchSupport && !$parent.closest('.navbar-nav').length && !menuTree[0].find(backdrop).length) {
// if mobile we use a backdrop because click events don't delegate
$('<div class="' + backdrop.substr(1) + '"/>').appendTo(menuTree[0]).on('click', closeOpened)
}
for (var i = 0, s = menuTree.length; i < s; i++) {
if (!menuTree[i].hasClass(openClass)) {
menuTree[i].addClass(openClass);
positioning(menuTree[i].children('.' + menuClass), menuTree[i]);
}
}
opened = menuTree[0];
}
return false;
};
proto.keydown = function (e) {
if (!/(38|40|27)/.test(e.keyCode)) return;
var $this = $(this);
e.preventDefault();
e.stopPropagation();
if ($this.is('.disabled, :disabled')) return;
var $parent = getParent($this);
var isActive = $parent.hasClass('open');
if (!isActive || (isActive && e.keyCode == 27)) {
if (e.which == 27) $parent.find(toggle).trigger('focus');
return $this.trigger('click')
}
var desc = ' li:not(.divider):visible a';
var desc1 = 'li:not(.divider):visible > input:not(disabled) ~ label';
var $items = $parent.find(desc1 + ', ' + '[role="menu"]' + desc + ', [role="listbox"]' + desc);
if (!$items.length) return;
var index = $items.index($items.filter(':focus'));
if (e.keyCode == 38 && index > 0) index--; // up
if (e.keyCode == 40 && index < $items.length - 1) index++; // down
if (!~index) index = 0;
$items.eq(index).trigger('focus')
};
proto.change = function (e) {
var
$parent,
$menu,
$toggle,
selector,
text = '',
$items;
$menu = $(this).closest('.' + menuClass);
$toggle = $menu.parent().find('[data-label-placement]');
if (!$toggle || !$toggle.length) {
$toggle = $menu.parent().find(toggle);
}
if (!$toggle || !$toggle.length || $toggle.data('placeholder') === false)
return; // do nothing, no control
($toggle.data('placeholder') == undefined && $toggle.data('placeholder', $.trim($toggle.text())));
text = $.data($toggle[0], 'placeholder');
$items = $menu.find('li > input:checked');
if ($items.length) {
text = [];
$items.each(function () {
var str = $(this).parent().find('label').eq(0),
label = str.find('.data-label');
if (label.length) {
var p = $('<p></p>');
p.append(label.clone());
str = p.html();
}
else {
str = str.html();
}
str && text.push($.trim(str));
});
text = text.length < 4 ? text.join(', ') : text.length + ' selected';
}
var caret = $toggle.find('.caret');
$toggle.html(text || '&nbsp;');
if (caret.length)
$toggle.append(' ') && caret.appendTo($toggle);
};
function positioning($menu, $control) {
if ($menu.hasClass('pull-center')) {
$menu.css('margin-right', $menu.outerWidth() / -2);
}
if ($menu.hasClass('pull-middle')) {
$menu.css('margin-top', ($menu.outerHeight() / -2) - ($control.outerHeight() / 2));
}
}
function closeOpened(event, menuTree) {
if (opened) {
if (!menuTree) {
menuTree = [opened];
}
var parent;
if (opened[0] !== menuTree[0][0]) {
parent = opened;
} else {
parent = menuTree[menuTree.length - 1];
if (parent.parent().hasClass(menuClass)) {
parent = parent.parent();
}
}
parent.find('.' + openClass).removeClass(openClass);
if (parent.hasClass(openClass))
parent.removeClass(openClass);
if (parent === opened) {
opened = null;
$(backdrop).remove();
}
}
}
function getSubMenuParents($submenu) {
var result = [$submenu];
var $parent;
while (!$parent || $parent.hasClass(subMenuClass)) {
$parent = ($parent || $submenu).parent();
if ($parent.hasClass(menuClass)) {
$parent = $parent.parent();
}
if ($parent.children(toggle)) {
result.unshift($parent);
}
}
return result;
}
function getParent($this) {
var selector = $this.attr('data-target');
if (!selector) {
selector = $this.attr('href');
selector = selector && /#[A-Za-z]/.test(selector) && selector.replace(/.*(?=#[^\s]*$)/, ''); //strip for ie7
}
var $parent = selector && $(selector);
return $parent && $parent.length ? $parent : $this.parent()
}
// DROPDOWN PLUGIN DEFINITION
// ==========================
var old = $.fn.dropdown;
$.fn.dropdown = function (option) {
return this.each(function () {
var $this = $(this);
var data = $this.data('bs.dropdown');
if (!data) $this.data('bs.dropdown', (data = new Dropdown(this)));
if (typeof option == 'string') data[option].call($this);
})
};
$.fn.dropdown.Constructor = Dropdown;
$.fn.dropdown.clearMenus = function(e) {
$(backdrop).remove();
$('.' + openClass + ' ' + toggle).each(function () {
var $parent = getParent($(this));
var relatedTarget = { relatedTarget: this };
if (!$parent.hasClass('open')) return;
$parent.trigger(e = $.Event('hide' + eventNamespace, relatedTarget));
if (e.isDefaultPrevented()) return;
$parent.removeClass('open').trigger('hidden' + eventNamespace, relatedTarget);
});
return this;
};
// DROPDOWN NO CONFLICT
// ====================
$.fn.dropdown.noConflict = function () {
$.fn.dropdown = old;
return this
};
$(document).off(namespace)
.on('click' + namespace, closeOpened)
.on('click' + namespace, toggle, proto.toggle)
.on('click' + namespace, '.dropdown-menu > li > input[type="checkbox"] ~ label, .dropdown-menu > li > input[type="checkbox"], .dropdown-menu.noclose > li', function (e) {
e.stopPropagation()
})
.on('change' + namespace, '.dropdown-menu > li > input[type="checkbox"], .dropdown-menu > li > input[type="radio"]', proto.change)
.on('keydown' + namespace, toggle + ', [role="menu"], [role="listbox"]', proto.keydown)
}(jQuery));





// CAP OS CUSTOM SCRIPTS

