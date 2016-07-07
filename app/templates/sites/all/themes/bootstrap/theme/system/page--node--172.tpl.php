<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
 global $user;
 if (array_search('Public User', $user->roles)) {
    header('Location: ' . $GLOBALS['base_url']);
 }

//Sanitice the forwarding URL
$url = urlencode($_REQUEST['url']);
/**
 *  Store HTTP_REFERER value in cookie.
 */

if(isset($url)) {
  //$expiry = new \DateTime('+30 second');
  //$referrerUrl = parse_url($_REQUEST['url'], PHP_URL_FRAGMENT);
  setcookie('referrerUrl', $_GET['url']);
}

/**
 * 
 * Login page specific css stylesheet
 */
$css = "body {min-width: 980px; }";
drupal_add_css($css, 'inline');


?>
<header id="navbar" role="banner" class="navbar-fixed-top navbar-inverse">
  <div class="container">
    <div class="navbar-header" style="margin:0;padding:0">

      <?php if (!empty($site_name)): ?>
      <a class="name navbar-brand" style="height: 40px; line-height: 13px;" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    </div>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
      </div>
    <?php endif; ?>
  </div>
</header>
<?php if ($page['featured']): ?>
  <!-- JT 9/13/14 to dynamically change hallways image -->
  <?php
  $path = current_path();
  $path_alias = drupal_lookup_path('alias',$path);
  $addclass = "";

  switch ($path_alias) {
    case "AdministrativeSupport":
      $addclass = "headBoxIn-as";
      break;
    case "ITHardware":
      $addclass = "headBoxIn-ithard";
      break;
    case "ITSoftware":
      $addclass = "headBoxIn-itsoft";
      break;
    case "TalentDevelopment":
      $addclass = "headBoxIn-et";
      break;
    case "SmallPackageDelivery":
      $addclass = "headBoxIn-spd";
      break;
    case "ProfessionalServices":
      $addclass = "headBoxIn-ps";
    case "ToolsandHardware":
      $addclass = "headBoxIn-th";
      break;
    case "CleaningSuppliesandChemicals":
      $addclass = "headBoxIn-cs";
      break;
    case "WorkplaceEnvironment":
      $addclass = "headBoxIn-we";
      break;
    case "Telecommunications":
      $addclass = "headBoxIn-tel";
      break;
    case "EmployeeRelocation":
      $addclass = "headBoxIn-epr";
      break;
    case "Freight":
      $addclass = "headBoxIn-fre";
      break;
    case "ITSecurity":
      $addclass = "headBoxIn-cyb";
      break;
    case "ITServices":
      $addclass = "headBoxIn-ioc";
    case "MotorVehicles":
      $addclass = "headBoxIn-mov";
      break;
    case "Travel":
      $addclass = "headBoxIn-trv";
      break;
    case "CardServices":
      $addclass = "headBoxIn-crs";
      break;
    default:
      $addclass = "";
  }
  $headtext = "<div id=\"headBoxIn\" class=\"column featuredbanner container-fluid $addclass\">";
  print $headtext;
  ?>
  <!-- <div id="headBoxIn" class="column featuredbanner container-fluid"> -->
  <div class="section">
    <?php print render($page['featured']); ?>
  </div> <!-- /section -->
  </div> <!-- /#headBoxIn -->
<?php endif; ?> <!-- featured -->

<?php if ($page['bottom_featured']): ?>
      <div id="lca-block" class="container-fluid"><div class="section">
        <?php print render($page['bottom_featured']); ?>
      </div></div> <!-- /.section, /#sidebar-first -->
    <?php endif; ?>
<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-xs-12 col-sm-12 col-md-4 col-lg-4" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
          <!-- Begin login-page-body -->
  <div class="content-wrapper">
  <div class="container">
  <div class="col-xs-12 col-sm-12 col-lg-12">
  <div class="logininfo-wrapper">
  <?php  global $user; if ($user->uid != 0) : ?>
    <!-- code for the logout button -->
    <div class="col-lg-push-4 col-lg-2" style=" border:2px solid rgba(19,3,3,0.2); border-radius:10px; color:orange; background:rgba(69,69,69,0.2); line-height:1; margin-top:30px; ">
    <a href="/user/logout"><button class="btn btn-link center-block" style="line-height:50px; font-size:20px; font-weight:bold; color:black;">Sign Out</button></a></div>
  <?php else: ?>
  <!--  code for the login button -->
 <div class="col-md-6">
 <form accept-charset="UTF-8" action="/cas?destination=<?= $url ? rawurlencode($url) : 'node/172'?>" id="cas-login-form" method="post">
    <input name="form_build_id" type="hidden" value="form-RSeOoFPmmhDxKPkrFXdUYevjryrV1659qBosC8T3B7g" />
    <input name="form_id" type="hidden" value="cas_login_block" />
    <input name="url" type="hidden" value=<?= $url; ?>>
    <input name="service" type="hidden" value=<?= $url ? $url : '/cas?destination=node/172'?>>
    <button class="btn btn-block btn-lg login-information-button" >
      <span><b>Federal Government Users</b></span>
      <center>Click here to sign in for full access</center>
    </button>
  </form>
  </div>
  <div class="col-md-6 pub-btn-login">
    <a href="/public-gateway.php?url=<?= $url ? $url : '/'?>" class="btn btn-block btn-lg login-information-button" >
      <span><b>Non-Federal Government & Public Users</b></span>
      <center>Click here for public access</center>
    </a>
  </div>
 <?php endif; ?>
   <div class="clearfix">&nbsp;</div>
<!-- Begin login-infomation content  -->
<div class="login-information-page-wrapper">
  <div data-toggle="collapse" data-target="#need-help" class="link need-help-link">
    Need help signing in? <i class="fa fa-angle-double-right"></i>
  </div>
    <div id="need-help" class="collapse">
      <p>For full, unrestricted access to the Acquisition Gateway's content, resources, digital tools, and prices paid data, Federal
      Government users are encouraged to sign in.</p>
      <p>The Gateway authenticates Federal Government users via OMB MAX.</p>
      <p>To sign in and gain full, unrestricted access to the Gateway, follow the steps below:</p>
      <ol>
        <li><strong>Register</strong> an account with <a href="https://max.omb.gov/maxportal/registrationForm.action">OMB MAX</a>.</li>
        <li><strong>Insert</strong> your PIV/CAC card (card reader required).</li>
        <li><strong>Select "Federal Government Users" button.</strong> You may be prompted to enter a PIN in a pop-up window.</li>
        <li><strong>Enter PIN and select OK</strong> to sign in and enter the Gateway.</li>
        <li>Experiencing any sign in issues? Please watch this <a target="_blank" href="https://www.youtube.com/watch?v=VoO902NCKpY">video </a>for additional support.</li>
      </ol>
      <p>We want to help, so if you continue to encounter any sign in problems, <a href="mailto:hallways_site_manager@gsa.gov">hallways_site_manager@gsa.gov</a>. We aim to respond to every message within one working day.</p>
  </div>
   <div class="rules">
    <h4>
       Rules of Behavior for the Acquisition Gateway
    </h4>
    <p>
      Acquisition Gateway Terms and Conditions of Use: This computer system is the property of the United States Government. Logging in to the Federal Government Users sign-on section of this site is restricted to authorized Government users only. Otherwise click the Non-Federal Government & Public Users button to accept the terms and proceed.</p>
  </div>

    <div data-toggle="collapse" data-target="#usage-agreement" class="link user-agreement-link">
      Usage Agreement <i class="fa fa-angle-double-right"></i>
    </div>
    <div id="usage-agreement" class="collapse">
      <p>
This computer system is property of the United States Government. It is intended for authorized use only. Unauthorized use of this system is prohibited and may constitute a violation of 18 U.S.C. § 1030 - Fraud and related activity in connection with computers. Violations of Federal Government laws and regulations and may result in criminal, civil, and/or administrative action.
      </p>
      <p>
Portions of this web site are restricted to Federal Government employees and pre-approved contractors. By accessing restricted portions of the site, contractors are agreeing to abide by the terms under which they were granted access. Unauthorized disclosure of company confidential information is subject to the penalties set forth in 18 U.S.C. § 1905 - Disclosure of confidential information generally and 41 U.S.C. § 2105 - Penalties and administrative actions. Information downloaded or otherwise obtained from the system must be protected in accordance with this agreement and may also be considered source selection sensitive pursuant to 41 USC 2101(7) - Definitions and FAR Part 3 - Improper Business Practices and Personal Conflicts of Interest, in accordance with agency procedures.
      </p>

      <p>
By accessing and using this system, you acknowledge your awareness of and consent to these terms and conditions. There is no reasonable expectation of privacy in the access or use of this computer system. Users (authorized or unauthorized) have no explicit or implicit expectation of privacy in anything viewed, created, downloaded, or stored on this system, including e-mail, Internet, and Intranet use. Any or all uses of this system (including all peripheral devices and output media) and all files on this system may be intercepted, monitored, read, captured, recorded, disclosed, copied, audited, and/or inspected by authorized agency personnel, the Office of Inspector General (OIG), and/or other law enforcement personnel, as well as authorized officials of other agencies. Access or use of this computer by any person, whether authorized or unauthorized, constitutes consent to such interception, monitoring, reading, capturing, recording, disclosure, copying, auditing, and/or inspection at the discretion of authorized agency personnel, law enforcement personnel (including the OIG), and/or authorized officials other agencies.
      </p>
  </div>
</div>
  <!-- End -->
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-xs-12 col-sm-12 col-md-4 col-lg-4" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>
  </div>
</div>
<?php if ($page['content_bottom']): ?>
      <div id="hallway-landing-pg-bottom" class="container-fluid">
<div class="container">
    <div class="row">
<?php print render($page['content_bottom']); ?>
</div>
</div>
      </div> <!-- /.section, /#footer-first -->
    <?php endif; ?>
<?php if ($page['top_footer']): ?>
      <div id="hallway-landing-pg-foot" class="container-fluid">
        <?php print render($page['top_footer']); ?>
      </div> <!-- /.section, /#footer-first -->
    <?php endif; ?>

<footer id="r_footer">
<div class="container">
  <?php print render($page['footer']); ?>
</div>
</footer>

<!-- Google Tag Manager -->
<?php
  require(DRUPAL_ROOT . '/sites/default/settings.php');
?>
<noscript>
  <iframe src="//www.googletagmanager.com/ns.html?id=<?=$container_id;?>" height="0" width="0" style="display:none;visibility:hidden"></iframe>
</noscript>

<script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
'//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
})(window,document,'script','tm','<?= $container_id?>');</script>

<script>
  if (window.tm) {
    window.tm.push({
      appState: {
        appName: 'Login Information',
        search: window.location.search
      }
    });
  }
</script>
<!-- End Google Tag Manager -->

<script>

var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-51490338-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script>

<script>
/*
* Begin E-Nor
* v1.74 131022 : Fix for multiple PUA loop
* v1.75 140221 : Added option to use dc.js for demographic data
* v1.76 140514 : Fix for bug in routine triggered by sdor=true. Routine wrote an extra sub-domain cookie in addition to the cross-sub-domain cookie.
*/

var _gaq = _gaq || [];
var _gas = _gas || [];

var GSA_CPwrapGA = (function () {

		var domainHash;
		var dlh = document.location.hostname;

        var oCONFIG = {
				// System parameters - don't change without discussion with CP
            VERSION : 'v1.76 140514 : Fix for extra sub-domain cookie in cross-sub-domain tracking',
            SEARCH_PARAMS : 'q|querytext|nasaInclude|k|QT', // ver 1.4 Normalize query params
            HOST_DOMAIN_OR : dlh, // default is to track sub-domains individually - override set in _setParams()
            LEADING_PERIOD : '.',
            GWT_UAID 	   : ['UA-33523145-1'],

				// GSA Configurable parameters - ver 1.6 - extended in 1.7x with external parameters
            AGENCY : '',				// Singular, consistent, succinct, user-friendly abbreviation for the agency.  E.g. DOJ, DOI, Commerce
            VISITOR_TIMEOUT 	: -1,	// Specified in months, 0 = session = when browser closes, -1 = don't change default (24 months)
            CAMPAIGN_TIMEOUT 	: -1,	// Specified in months, 0 = session = when browser closes, -1 = don't change default (6 months)
										// CAMPAIGN_TIMEOUT must be <= VISITOR_TIMEOUT
            VISIT_TIMEOUT		: -1,	// Specified in minutes, 0 = session = when browser closes, -1 = don't change default (30 minutes)
			ANONYMIZE_IP		: true,	// only change to false in rare circumustances where GeoIP location accuracy is critical
			YOUTUBE 			: true,

		};

			// Object for centralized control of all Custom Variables reported in this sript file.
			// Since GSA code only ever sets page level CVs, scope is always 3
        var oCVs = {
            agency		: { key : 'Agency', slot : 33, scope : 3},
            sub_agency	: { key : 'Sub-Agency',slot : 34, scope : 3},
            version		: { key : 'Code Ver',slot : 35, scope : 3
          }
        }

        /**
         *  Sets up _gas and configures accounts, domains, etc,
         * In effect, ensures functions are compiled before being called
         * @private
         */
        var _init = function () {

			_setParams();

            oCONFIG.HOST_DOMAIN_OR = oCONFIG.HOST_DOMAIN_OR.replace(/^www\./i, '');

            var ary = setHashAndPeriod(oCONFIG.HOST_DOMAIN_OR);
            oCONFIG.LEADING_PERIOD = ary[1];

            // ver 1.73 allows QS UA ids: _gas.push(['GSA_CP1._setAccount', oCONFIG.GWT_UAID]);
			for (var i=0;i<oCONFIG.GWT_UAID.length;i++) {
				_gas.push(['GSA_CP' + (i+1) + '._setAccount', oCONFIG.GWT_UAID[i]]);
			}

			if (oCONFIG.PARALLEL_UA && !oCONFIG.DEBUG_MODE)
				for (i=oCONFIG.GWT_UAID.length;i<oCONFIG.PARALLEL_UA.length + oCONFIG.GWT_UAID.length;i++) {
					_gas.push(['GSA_CP' + (i+1) + '._setAccount', oCONFIG.PARALLEL_UA[i-1]]);
				}

            if (oCONFIG.ANONYMIZE_IP) {
				_gaq.push (['_gat._anonymizeIp']);
			}
            _gas.push(['_setDomainName', oCONFIG.LEADING_PERIOD + oCONFIG.HOST_DOMAIN_OR]);
			_gaq.push(['_setDomainName', oCONFIG.LEADING_PERIOD + oCONFIG.HOST_DOMAIN_OR]);


			setGAcookieTimeouts();

            if (ary[0]) {
                _gas.push(['_setAllowHash', false]);
            }

            _gas.push(['_gasTrackOutboundLinks']);

			if (oCONFIG.EXTS) {
				_gas.push(['_gasTrackDownloads',{'extensions': oCONFIG.EXTS.split(',')}]);
			} else {
				_gas.push(['_gasTrackDownloads']);
			}

            _gas.push(['_gasTrackMailto']);
			if (oCONFIG.YOUTUBE) {
				_gas.push(['_gasTrackYoutube', {percentages: [33, 66, 90], force:true}]);
			}

			// Filter out sub-domain links tracked as Outbound
			_gas.push(['_addHook', '_trackEvent', function (cat, act) {
					var linkDomain = act.match(/([^.]+\.(gov|mil)$)/);
					if (cat === 'Outbound' && typeof act === "string" && linkDomain) {
						return (document.location.hostname.indexOf(linkDomain[1]) === -1);
					}
				}
			]);

            // Add hook to _trackPageview to standardize search parameters
            _gas.push(['_addHook', '_trackPageview', function (pageName) {
                        var re = new RegExp('([?&])(' + oCONFIG.SEARCH_PARAMS + ')(=[^&]*)', 'i');
                        if (re.test(pageName)) {
                            pageName = pageName.replace(re, '$1query$3');
                        }
                        return [pageName];
                    }
                ]);
        };


        /**
         *  Sets the cookie timeouts if values have been set in oCONFIG at the top of this file
         *
         * @private
         */
		var setGAcookieTimeouts = function() {
            if (oCONFIG.VISIT_TIMEOUT > -1) _gaq.push(['_setSessionCookieTimeout', oCONFIG.VISIT_TIMEOUT*1000*60]);					// Specified in minutes
            if (oCONFIG.VISITOR_TIMEOUT > -1) _gaq.push(['_setVisitorCookieTimeout', oCONFIG.VISITOR_TIMEOUT*1000*60*60*24*30.416667]);	// Specified in months - GA uses 30.416.. as the number of days/month
            if (oCONFIG.CAMPAIGN_TIMEOUT > -1) _gaq.push(['_setCampaignCookieTimeout', oCONFIG.CAMPAIGN_TIMEOUT*1000*60*60*24*30.416667]);	// Specified in months
		}


        /**
         *  Returns the domain and top-level domain  - eg example.com, example.ca example.co.uk, example.com.au or ipaddress
         *
         * @private
         * @param {string} strURL a hostname or full url
         */
        var getDomainNameGovMil = function (strURL) {
            strURL = strURL || dlh;

            // extract the host name since full url may have been provided
            strURL = strURL.match(/^(?:https?:\/\/)?([^\/:]+)/)[1]; // this cannot error unless running as file://

            if (strURL.match(/(\d+\.){3}(\d+)/) || strURL.search(/\./) == -1)
                return strURL; // ipaddress


            try {
                if (/\.(gov|mil)$/i.test(strURL)) { // Customized for .gov and .mil
                    strURL = strURL.match(/\.([^.]+\.(gov|mil)$)/i)[1];
                } else {
                    strURL = strURL.match(/(([^.\/]+\.[^.\/]{2,3}\.[^.\/]{2})|(([^.\/]+\.)[^.\/]{2,4}))(\/.*)?$/)[1];
                }

            } catch (e) {}
            return strURL.toLowerCase();
        };

        /**
         *  Returns the GA hash for the Cookie domain passed
         *
         * @private
         * @param {string} strCookieDomain -  the hostname used for the cookie domain
         */
        var getDomainHash = function (strCookieDomain) {
            var fromGaJs_h = function (e) {
                return undefined == e || "-" == e || "" == e;
            };
            var fromGaJs_s =
            function (e) {
                var k = 1,
                a = 0,
                j,
                i;
                if (!fromGaJs_h(e)) {
                    k = 0;
                    for (j = e.length - 1; j >= 0; j--) {
                        i = e.charCodeAt(j);
                        k = (k << 6 & 268435455) + i + (i << 14);
                        a = k & 266338304;
                        k = a !== 0 ? k^a >> 21 : k;
                    }
                }
                return k;
            };
            return fromGaJs_s(strCookieDomain);
        };

        /**
         *  Returns an array [bool, str] where bool indicates value for setAllowHash and str is either blank or a leading period
         *
         * @private
         * @param {string} strCookieDomain -  the hostname used for the cookie domain WITHOUT  the leading period
         */
        var setHashAndPeriod = function (strCookieDomain) {
            var utmaCookies = document.cookie.match(/__utma=[^.]+/g);
            var retVals = [false, '']; // setAllowHash = false and leading period = ''

				// if no cookies found
            if (!utmaCookies)
                return retVals;

            domainHash = getDomainHash(strCookieDomain);

            for (var elm = 0; elm < utmaCookies.length ; elm++) {
                utmaCookies[elm] = utmaCookies[elm].substr(7); // strip __utma= leaving only the hash

                // look for the cookie with the matching domain hash
                var hashFound = (domainHash == utmaCookies[elm]);
                // if found, there's a hash and we're done
                if (hashFound) {
                    retVals[0] = false;
                    return retVals;
                } else { // check for period
                    hashFound = (getDomainHash('.' + strCookieDomain) == utmaCookies[elm]);
                    retVals[1] = hashFound ? '.' : '';
                }

                // if not found, check for setAllowHashFalse - aka hash = 1
                retVals[0] = retVals[0] || ('1' == utmaCookies[elm]); // true if hash == 1
            }

            return retVals;
        };

        /**
         *  Sets the Custom Variables for Agency and sub-Agency based on the agency and sub_agency objects in oCVs
         *
         * @private
         */
        var setAgencyVars = function() {
            setCustomVar(oCONFIG.AGENCY, oCVs.agency); // Page level variable sent only to GSA account
            setCustomVar(oCONFIG.SUB_AGENCY, oCVs.sub_agency); // Page level variable sent only to GSA account
        }
                  /**
         *  Single generic method to set all custom vars based on single control object for all CVs - see oCVs near the top of the file
         *	To keep the cookies synchronized, first check that agency is not already using the slot for a Vistor Level Varialbe
		 *  If it is, even a PLCV will remove the value from their cookie.  In that case we don't set the variable.

         * @private
         * @param {string} value -  the only argument set outside of oCVs
         * @param {object} oCV -  the object in oCVs for a particular variable
         */
        var setCustomVar = function (value, oCV) {
			if (!value) return;

			var pageTracker = _gat._getTrackerByName(); // Gets the default tracker.
			var visitorCustomVarValue = pageTracker._getVisitorCustomVar(oCV.slot);

			if (!visitorCustomVarValue)
				_gas.push(['_setCustomVar', oCV.slot, oCV.key, value, oCV.scope]); // Record version in Page Level (oCV.scope ) Custom Variable specified in oCV.slot
        }

        /**
         * Reports a page view and detects if page is a 404 Page not found
         * @public
         */
        this.onEveryPage = function () {

            var pageName = document.location.pathname + document.location.search + document.location.hash;

            // ... Page Not Found
            // Track as a pageview because we need to see if it's a landing page.
            if (document.title.search(/404|not found/i) !== -1) {
                var vpv404 = '/vpv404/' + pageName;
                pageName = vpv404.replace(/\/\//g, '/') + '/' + document.referrer;
            }

            setCustomVar(oCONFIG.VERSION, oCVs.version)
			setAgencyVars();
            _gas.push(['_trackPageview', pageName]);
        };


        /**
         * Retrieves the params from the script block src
         * @private
		*/
        var _setParams = function _setParams () {
			var src = document.getElementById('_fed_an_js_tag');
			var tags;
			if (!src) tags = document.getElementsByTagName('script');
			for (var i = 0; tags && !src && i < tags.length; i++) {
				var tag = tags[i];
				if (/federated-analytics.*\.js/i.test(tag.src)) src = tag;
			}

			if (src) {
				src = src.src.split(/[?&]/);
				src.shift();
				for (var i = 0; i < src.length; i++) {

					var param = src[i].split('=');
					src[0] = src[0].toLowerCase();

						// params in the query string
					if ('agency' == param[0]) {
						oCONFIG.AGENCY = param[1].toUpperCase();
					} else if (/sub(-?agency)?/.test(param[0])) {
						oCONFIG.SUB_AGENCY = param[1].toUpperCase();
					} else if ('sp' == param[0]) {
						param[1] = param[1].replace(/[,;\/]/g,'|');
						oCONFIG.SEARCH_PARAMS = oCONFIG.SEARCH_PARAMS + '|' + param[1];
						oCONFIG.SEARCH_PARAMS = oCONFIG.SEARCH_PARAMS.replace(/\|\|/g, '|');
					} else if ('vcto' == param[0]) {
						oCONFIG.VISITOR_TIMEOUT = parseInt(param[1]);
					} else if ('camto' == param[0]) {
						oCONFIG.CAMPAIGN_TIMEOUT = parseInt(param[1]);
					} else if ('pua' == param[0]) {
						oCONFIG.PARALLEL_UA = param[1].toUpperCase();
						oCONFIG.PARALLEL_UA = oCONFIG.PARALLEL_UA.split(',');
					} else if ('devua' == param[0]) {
						oCONFIG.GWT_UAID = param[1].toUpperCase();
						oCONFIG.GWT_UAID = oCONFIG.GWT_UAID.split(',');
						oCONFIG.DEBUG_MODE = true;
					} else if ('exts' == param[0]) {
						oCONFIG.EXTS = param[1].toLowerCase();
						oCONFIG.EXTS = oCONFIG.EXTS.replace(/ /g,'');
					} else if ('aip' == param[0]) {
						oCONFIG.ANONYMIZE_IP = ('true' == param[1]) ? true : !('false' == param[1]);
					} else if ('yt' == param[0]) {
						oCONFIG.YOUTUBE = ('true' == param[1]) ? true : !('false' == param[1]);
					} else if ('sdor' == param[0]) {	// subdomain override
							// default is false - tracking will be at the sub-domain level
						if (('true' == param[1]) ? true : !('false' == param[1])) {
							// getDomainNameGovMil() returns domain name, not sub-domains and with no leading period e.g.  returns usa.gov on http://xyz.usa.gov
							oCONFIG.HOST_DOMAIN_OR = getDomainNameGovMil();
						} else {
							oCONFIG.HOST_DOMAIN_OR = dlh;
						}
					}
				}
			}

				// Defaults for Agency and Sub-Agency.  Others are in the oCONFIG object
			oCONFIG.AGENCY = oCONFIG.AGENCY || 'unspecified:' + oCONFIG.HOST_DOMAIN_OR;
			oCONFIG.SUB_AGENCY = oCONFIG.SUB_AGENCY || ('' + dlh);

			oCONFIG.SUB_AGENCY = oCONFIG.AGENCY + ' - ' + oCONFIG.SUB_AGENCY

			oCONFIG.CAMPAIGN_TIMEOUT = Math.min(oCONFIG.CAMPAIGN_TIMEOUT, oCONFIG.VISITOR_TIMEOUT);
		}
        _init();

    });
</script>
