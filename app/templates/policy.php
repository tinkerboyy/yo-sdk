<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Acquisition Gateway - Policy</title>
    <link rel="icon"
          type="image/png"
          href="favicon.png">

    <!--================ RENDER SETTINGS ========================-->
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!--================ CSS ========================-->

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->

    <!--[if lt IE 9]>
    <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
    <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
    <link rel="stylesheet" type="text/css" href="assets/css/cap-os-v1-design-time.css">
    <link rel="stylesheet" type="text/css" href="assets/css/cap-os-v1.css">

    <style>
        .faq-section {
            padding-top: 40px;
        }

        ul.affix {
            position: fixed;
            top: 40px;
            left: 15px;
            width: 360px;
        }

        ul.affix-top {
            position: static;
        }

        ul.affix-bottom {
            position: absolute;
        }

        /* First level of nav */
        .sidenav {
            margin-top: 20px;
            margin-bottom: 30px;
            padding-top: 10px;
            padding-bottom: 10px;
            /*background-color: #f7f5fa;*/
            border-radius: 5px;
        }

        /* All levels of nav */
        .sidebar .nav > li > a {
            display: block;
            /*color: #716b7a;*/
            padding: 5px 20px;
            font-size: 13px !important;
            margin-right: 45px;
        }

        .sidebar .nav > li > a:hover,
        .sidebar .nav > li > a:focus {
            text-decoration: none;
            background-color: #e5e3e9;
        }

        .sidebar .nav > .active > a,
        .sidebar .nav > .active:hover > a,
        .sidebar .nav > .active:focus > a {
            font-weight: bold;
            /*color: #563d7c;*/
            background-color: transparent;

        }

        .sidebar .nav > .active > a::before {
            font-family: "fontAwesome";
            content: "\f054";
            margin-left: -20px;
            margin-right: 10px;
        }

        /* Nav: second level */
        .sidebar .nav .nav {
            display: none;
        }

        .sidebar .nav > li.active .nav {
            display: block;
        }

        .sidebar .nav .nav {
            margin-bottom: 8px;
        }

        .sidebar .nav .nav > li > a {
            padding-top: 3px;
            padding-bottom: 3px;
            padding-left: 30px;
            font-size: 0.6 ems;
        }

        #content {
            margin-top: 0px;
        }

        .progress {
            background-color: #f5f5f5;
            border-radius: 4px;
            box-shadow: 0 1px 2px rgba(0, 0, 0, 0.1) inset;
            height: 5px;
            margin-bottom: 20px;
            overflow: hidden;
        }

        .scrollToTop {

            background: rgba(35, 180, 240, 0.6);
            border-radius: 50px;
            bottom: 75px;

            color: rgba(255, 255, 255, 0.76);

            font-weight: bold;
            height: auto;
            padding: 5px 0 10px;
            position: fixed;
            right: 40px;
            text-align: center;
            text-decoration: none;
            width: 37px;
            -webkit-box-shadow: 0px 0px 2px 1px rgba(0, 0, 0, 0.0);
            -moz-box-shadow: 0px 0px 2px 1px rgba(0, 0, 0, 0.0);
            box-shadow: 0px 0px 2px 1px rgba(0, 0, 0, 0.0);

        }

        .scrollToTop a {
            color: rgba(255, 255, 255, 0.76);
        }

        .scrollToTop:hover {
            text-decoration: none;
            background: rgba(35, 180, 240, 1.00);

            -webkit-box-shadow: 0px 0px 8px 0px rgba(0, 0, 0, 0.45);
            -moz-box-shadow: 0px 0px 8px 0px rgba(0, 0, 0, 0.45);
            box-shadow: 0px 0px 8px 0px rgba(0, 0, 0, 0.45);
            color: #fff;
        }

    </style>
    <!--================ /END CSS ========================-->

    <script src="assets/js/cap-os-v1-head.js"></script>
    <noscript>
    </noscript>
</head>

<body data-spy="scroll" data-target="#affix-nav">
<a href="#content" class="sr-only">Skip to content</a>


<!--================ NAVBAR ========================-->
<!-- NAVABR -->
<header id="navbar" style="min-height: 40px; padding-left: 10px;padding-right: 10px;" role="banner" class="navbar container-fluid navbar-default navbar-fixed-top navbar-inverse" bs-collapse="" start-collapsed="true" data-name="'main-menu'">
    <div class="container">
        <div class="navbar-header">
            <a class="name navbar-brand" href="/homepage/welcome.html" title="Home" style="height: 40px; line-height: 13px;">Acquisition Gateway</a>
            <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
            <button type="button" class="navbar-toggle" bs-collapse-toggle="" data-toggle="collapse">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
        </div>

        <div class="navbar-collapse collapse am-collapse" bs-collapse-target="">
            <nav role="navigation">
                <ul class="menu nav navbar-nav">
                    <!-- ngRepeat: item in mainMenuItems | filter: {p2: '0'}: true -->


                    <li><a style="line-height: 10px;" href="#about-us" data-toggle="modal">About Us</a></li>
                    <li><a style="line-height: 10px;" href="#explore" data-toggle="modal">Explore</a></li>

                </ul>
                <div class="region region-navigation">
                    <section id="block-boxes-header-modal-links" class="block block-boxes block-boxes-simple clearfix">
                        <div id="boxes-box-header_modal_links" class="boxes-box">
                            <div class="boxes-box-content">
                                <ul class="nav navbar-nav navbar-right">

                                    <li>
                                        <a href="mailto:hallways_site_manager@gsa.gov">
                                            <span class="nav-link-icon"><span clas="fa fa-envelope"></span></span> <span class="nav-link-text"></span>
                                        </a>
                                    </li>

                                    <li class="hidden-sm hidden-md hidden-lg"><a href="mailto:hallways_site_manager@gsa.gov">
                                        <div>Help</div>
                                    </a></li>

                                    <li class="help dropdown hidden-xs">
                                        <a style="line-height: 10px;" class="dropdown-toggle" href="/faq.php" title="Please take a few minutes to learn more about the Acquisition Gateway by reviewing the Frequently Asked Questions.">
                                            FAQs
                                        </a>
                                    </li>
                                    <li class="dropdown hidden-xs">
                                        <a style="line-height: 10px;" data-toggle="dropdown" class="dropdown-toggle"><span class="nav-link-text">Help</span></a>
                                        <ul style="min-width:450px; opacity:1; margin-right:10px;" role="menu" class="dropdown-menu">
                                            <li>
                                                <div class=" panel-body">
                                                    <h3 class="DINCondensedBold">How Can We Help?</h3>
                                                    <p>Are you having trouble? We want to help you succeed. Whether it is a sign in issue, problems finding what you need, or a concern about the accuracy or usefulness of an item, please let us know. If it affects you, we care.</p>
                                                    <p>Email us at:</p>
                                                    <p><a href="mailto:hallways_site_manager@gsa.gov" class="btn btn-block btn-warning">hallways_site_manager@gsa.gov</a></p>
                                                    <p>Thank you for your support. We aim to respond to every message within one working day. </p>
                                                </div>
                                            </li>
                                        </ul>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </section>
                </div>
            </nav>
        </div>
    </div>
</header>



<!-- /END NAVABR -->
<!--================ HEADER ========================-->
<!-- #Header/Search Block -->
<div class="homepage-headBox-box" style="margin-top:-48px;">
    <div class="container">
        <h1 class="DINCondensedBold" style="font-size:36px; line-height:40px; margin-bottom:0;">ACQUISITION GATEWAY</h1>

        <h3 style="font-size:20px; margin-top:0; margin-bottom:0;">Act as One for smarter acquisition</h3>
        <p style="font-size:1em;">Our vision is to provide a workspace with accurate, useful, and unbiased advice. Check
            back often to see the latest progress.</p>
    </div>

</div>
<!-- /END #Header/Search Block -->
<!-- #LEARN-CONNECT-ACT BLOCK -->
<div id="lca-block" class="container-fluid">
    <div class="lca-bar">
        <div class="lca-color-bar">
            <div class="col-xs-4 col-sm-4">
                <div class="progress">
                    <div style="width: 100%" class="progress-bar progress-bar-primary"></div>
                </div>
            </div>
            <div class="col-xs-4  col-sm-4">
                <div class="progress">
                    <div style="width: 100%" class="progress-bar progress-bar-warning"></div>
                </div>
            </div>
            <div class="col-xs-4 col-sm-4">
                <div class="progress">
                    <div style="width: 100%" class="progress-bar progress-bar-success"></div>
                </div>
            </div>
        </div>
    </div>
</div>
<!-- /END #LEARN-CONNECT-ACT BLOCK -->

<!--================ CONTENT ========================-->
<div class="content-wrapper">
    <div class="container" id="content_top">
        <div class="row">
            <!-- CONTENT STARTS HERE -->
            <!-- ================ LEFT COLUMN ================ -->

            <!--
                <div class="list-group" id="sidebar" data-spy="affix"  data-offset-bottom="200">
                <a href="#" class="list-group-item">1</a>
                <a href="#" class="list-group-item">2</a>
                <a href="#" class="list-group-item">3</a>
                <a href="#" class="list-group-item">4</a>
                <a href="#" class="list-group-item">5</a>
                <a href="#" class="list-group-item">6</a>
                <a href="#" class="list-group-item">7</a>
                <a href="#" class="list-group-item">8</a>
                <a href="#" class="list-group-item">9</a>
                <a href="#" class="list-group-item">10</a>
              </div>
            -->

            <nav id="affix-nav" class="sidebar col-md-4 hidden-sm hidden-xs" style="padding-right:30px;">
                <ul class="nav sidenav">
                    <!--
                    data-spy="affix"
                    data-offset-top="200"
                    data-offset-bottom="-2200"
                    -->
                    <li>
                        <a href="#one">
                            Linking Policy
                        </a>
                    </li>
                    <li>
                        <a href="#two">
                            Privacy Policy
                        </a>
                    </li>
                    <li>
                        <a href="#three">
                            Accessibility Policy
                        </a>
                    </li>
                    <li>
                        <a href="#four">
                            External Links
                        </a>
                    </li>
                    <li>
                        <a href="#five">
                            Social Media Sites
                        </a>
                    </li>
                    <li>
                        <a href="#six">
                            If You Send Us Personal Information
                        </a>
                    </li>
                </ul>
            </nav>


            <!-- ================ RIGHT COLUMN ================ -->
            <section id="content" class="col-md-8 col-sm-12 col-xs-12">

                <h1 id="start">Policy</h1>

                <div id="one" class="faq-section">
                    <h3>Linking Policy</h3>
                    <h4>Links to Government Websites</h4>
                    <p>
                        The Acquisition Gateway links to publicly available websites that are government-owned or
                        government-sponsored. Government-owned and government-sponsored website domains include .gov,
                        .mil and .fed.us.
                    </p>

                    <p>
                        The Gateway may also link to:
                    </p>
                    <ul>
                        <li>
                            quasi-government agencies and websites created by public sector-private sector
                            partnerships
                        </li>
                        <li>
                            state and local government sites<br/>
                            e.g., www.maryland.gov
                        </li>
                        <li>
                            government-sponsored websites that end in .com, .org, or .net<br/>
                            e.g., www.usps.com
                        </li>
                    </ul>

                    <h4>Links to Non-government Websites</h4>
                    <p>
                        The Acquisition Gateway may link to websites that are not government-owned or
                        government-sponsored when these websites provide government information or services that are not
                        available on an official government website. The Gateway provides these links as a public
                        service only.
                    </p>
                    <p>
                        The U.S. government, including the U.S. General Services Administration&mdash;the primary sponsoring
                        federal agency of the Acquisition Gateway&mdash;neither endorses nor guarantees in any way the
                        external organizations, services, advice, or products included in such websites. Furthermore,
                        the U.S. government neither controls nor guarantees the accuracy, relevance, timeliness or
                        completeness of the information contained in non-government websites.
                    </p>

                    <h4>Evaluation Criteria</h4>
                    <p>
                        Acquisition Gateway staff or other federal government employees such as subject-matter experts
                        evaluate all links using the following criteria:
                    </p>
                    <ul>
                        <li>
                            Is the website an official government-owned or supported website? If not, does the website
                            provide government information and/or services in a way that is not available on an official
                            government website?
                        </li>
                        <li>
                            Does the website complement existing information, products and services on the Acquisition
                            Gateway?
                        </li>
                        <li>
                            Is the website accessible and applicable to a wide audience?
                        </li>
                        <li>
                            Is the website&apos;s content relevant, useful and authoritative for citizens, businesses or
                            government officials?
                        </li>
                        <li>
                            Does the website&apos;s information appear to be accurate and current?
                        </li>
                        <li>
                            Is the website's approach to the privacy of personal information consistent with the
                            government's privacy and security policies?
                        </li>
                        <li>
                            Is the primary intent of the website to educate and inform, rather than persuade, convert,
                            or sell? The site may include advertising but must be free from heavy marketing or promotion
                            of products.
                        </li>
                        <li>
                            Does the website provide information free of charge?
                        </li>
                    </ul>

                    <h4>Prohibitions</h4>
                    <p>
                        The Acquisition Gateway will not link to any website that exhibits hate, bias, discrimination,
                        specific religious views, or social agendas. Furthermore, the Gateway reserves the right to deny
                        or remove any link that contains misleading information or unsubstantiated claims, or is
                        determined to be in conflict with the Acquisition Gateway&apos;s mission or policies.
                    </p>

                    <h4>Reciprocal Links</h4>
                    <p>
                        Though any site is welcome to link to the Acquisition Gateway, we do not engage in reciprocal
                        linking. The Gateway is an official web portals for the U.S. government. This a a public domain
                        website. There is no cost or special permission required to link to the site.
                    </p>

                </div>

                <div id="two" class="faq-section">
                    <h3>Privacy Policy</h3>
                    <h4>Information Collected and Stored Automatically</h4>
                    <p>
                        When you visit the Acquisition Gateway, we may store some or all of the following:
                    </p>
                    <ul>
                        <li>
                            the IP address from which you accessed the Gateway
                        </li>
                        <li>
                            the date and time of your visit
                        </li>
                        <li>
                            the name of the web site from which you navigated to the Gateway, the name of the file or
                            words you searched, items clicked on a page, and the browser and operating system used
                        </li>
                        <li>
                            information you entered in tools or services on the Gateway
                        </li>
                    </ul>
                    <p>
                        This information is used to measure the number of visitors to the various sections of our site
                        and identify system performance or problem areas. We also use this information to help us
                        develop the site, analyze patterns of usage, and to make the site more useful. This information
                        is not used for associating search terms or patterns of site navigation with individual users.
                        The Acquisition Gateway may anonymize and provide this information to third party entities for
                        the purposes of research analysis. We do not share or sell visitor data for the purposes of
                        advertising, marketing, or any other commercial purpose.
                    </p>

                    <h4>Site Security</h4>
                    <p>
                        For site security purposes and to ensure that this service remains available to all users, this
                        government computer system employs commercial software programs to monitor network traffic to
                        identify unauthorized attempts to upload or change information, or otherwise cause damage.
                    </p>
                    <p>
                        Except for authorized law enforcement investigations, no other attempts are made to identify
                        individual users or their usage habits. Raw data logs are used for no other purposes and are
                        scheduled for regular destruction in accordance with National Archives and Records
                        Administration guidelines.
                    </p>
                    <p>
                        Unauthorized attempts to upload information or change information on this service are strictly
                        prohibited and may be punishable under the Computer Fraud and Abuse Act of 1986 and the National
                        Information Infrastructure Protection Act.
                    </p>

                    <h4>Use of Persistent Cookies</h4>
                    <p>
                        Like many websites, the Acquisition Gateway uses persistent cookie technology. A cookie is a
                        small text file that the website sends to your web browser so that it can recognize return
                        visits from the same browser. Cookies uniquely identify a browser on a computer, but never a
                        person. If an individual visits the Gateway from two different computers, or from two different
                        browsers on a single computer, unique browser cookies will be created for each visit.
                    </p>
                    <p>
                        The Acquisition Gateway use persistent cookies to enhance your user experience, while protecting
                        your privacy:
                    </p>
                    <ul>
                        <li>
                            To remember you when your browser comes back to the site.
                        </li>
                        <li>
                            To get aggregate metrics on site usage to understand how people are using the site and how
                            we can make it better. We use web metrics services to track activity on the Acquisition
                            Gateway. Government agencies only ever receive traffic statistics anonymously and in the
                            aggregate.
                        </li>
                        <li>
                            To gather anonymous summary demographic information about our visitors such as gender, age
                            range, and areas of interest for adults over the age of 18. We do this by using Google
                            Demographic and Interests reports. When you visit a website that has partnered with the
                            Google Display Network, Google stores a number in your browser using a persistent cookie to
                            remember your visits. This number uniquely identifies a web browser, not a specific person.
                            Browsers may be associated with a demographic category, such as gender or age range, based
                            on the sites that were visited. This demographic information is used to help us better
                            understand our visitors&apos; interests and needs to more effectively develop content to serve
                            you.
                        </li>
                    </ul>
                    <p>
                        Most Internet browsers automatically accept persistent cookies. Although using persistent
                        cookies creates a better experience for visitors, the Gateway works without them. If you
                        don&apos;t want to accept cookies, you can edit your browser&apos;s options to stop accepting
                        persistent cookies or to prompt you before accepting a cookie from the websites you visit.
                        Here&apos;s how you can
                        <a href="https://www.usa.gov/optout-instructions" target="_blank">disable cookies and/or Google Demographic and Interests reports</a>.
                    </p>

                </div>


                <div id="three" class="faq-section">
                    <h3>Accessibility Policy</h3>
                    <p>
                        The Acquisition Gateway is committed to providing access to all individuals&mdash;with or without
                        disabilities&mdash;seeking information on the Acquisition Gateway. To provide this information,
                        we&apos;ve built the Acquisition Gateway to conform to
                        <a href="http://www.section508.gov/" target="_blank">Section 508 of the Rehabilitation Act</a>
                        (as amended). Section 508 requires that all individuals with disabilities (whether federal
                        employees or members of the general public) have access to, and use of, information and data
                        comparable to that provided to individuals without disabilities, unless an undue burden would be
                        imposed on us.
                    </p>
                    <p>
                        If you use assistive technology (such as a screen reader, eye tracking device, voice recognition
                        software, etc.) and have difficulty accessing information on the Acquisition Gateway, please
                        <a href="mailto:hallways_site_manager@gsa.gov" target="_blank">e-mail us</a> and provide the URL
                        (web address) of the material you tried to access, the problem you experienced, and your contact
                        information. We&apos;ll contact you and attempt to provide the information you&apos;re seeking.
                    </p>
                </div>

                <div id="four" class="faq-section">
                    <h3>External Links</h3>
                    <p>
                        The Acquisition Gateway links to many websites created and maintained by other public and/or
                        private organizations as outlined in our Linking Policy (above). If you click a link to an
                        outside website, you will leave the Acquisition Gateway site and are subject to the privacy and
                        security policies of the owners/sponsors of the outside website.
                    </p>
                </div>

                <div id="five" class="faq-section">
                    <h3>Social Media Sites</h3>
                    <p>
                        The Acquisition Gateway may maintain a presence on social media sites such as Facebook, Twitter,
                        YouTube and others to share government information and engage with the public. We do not collect
                        any Personally Identifiable Information through those sites, and we do not use personal
                        information made available by the third-party sites.
                    </p>
                </div>

                <div id="six" class="faq-section">
                    <h3>If You Send Us Personal Information</h3>
                    <p>
                        We do not collect personal information for any purpose other than to respond to your request.
                        The only personal information that we collect is what you decide to give us by
                        <a href="mailto:hallways_site_manager@gsa.gov" target="_blank">sending us an e-mail</a>. If you choose
                        to provide us with personal information &mdash; like your name and an email address, and are
                        submitting it to us through the website &mdash; we use that information to respond to your
                        message, and to help get you the information you requested.
                    </p>
                    <p>
                        We only share the information you give us with another government agency if your question
                        relates to that agency, or as otherwise required by law. The Acquisition Gateway never collects
                        information or creates individual profiles for commercial marketing.
                    </p>

                </div>


                <p>&nbsp;</p>
                <p>&nbsp;</p>

            </section>

        </div>
        <!-- CONTENT ENDS HERE -->
    </div>

    <div class="clearfix">&nbsp;</div>

    <div id="hallway-landing-pg-bottom">
        <div class="container">
            <!--<h2 class="title-banner">The Philosophy - defined.</h2>-->
            <div class="col-xs-12 col-sm-4">
                <div class="panel-body">
                    <h4 class="title-banner">LEARN.</h4>
                    <div><img src="assets/art/article-tiles/lrn.png" class="img-responsive"/></div>
                </div>
            </div>
            <div class="col-xs-12 col-sm-4">
                <div class="panel-body">
                    <h4 class="title-banner">CONNECT.</h4>
                    <div><img src="assets/art/article-tiles/connect.png" class="img-responsive"/></div>
                </div>
            </div>
            <div class="col-xs-12 col-sm-4">
                <div class="panel-body">
                    <h4 class="title-banner">ACT.</h4>
                    <div><img src="assets/art/article-tiles/act.png" class="img-responsive"/></div>
                </div>
            </div>
            <div class="col-xs-12 col-sm-12">
                <div class="panel-body">
                    <p>The Acquisition Gateway, built by GSA, is a workspace designed to let Federal acquisition
                        professionals learn what they need to know, connect with others to to collaborate and
                        communicate, and act to accomplish their tasks effectively. Organized to match the government’s
                        category management structure, the content in the Gateway was developed for you and by you—the
                        acquisition professional. We are building the Gateway with an Agile approach that incorporates
                        user-centered design and iterative development. We conduct continuous user-testing and encourage
                        feedback from users, so that the Acquisition Gateway can grow and change to best serve your
                        needs.
                    </p>
                    <p>
                        We encourage you to explore the solution comparisons, tools, templates, success stories, prices
                        paid data, and more to achieve successful outcomes at each step of the acquisition lifecycle.
                        Thank you for helping us as we build your place to learn, connect, and act with others in the
                        acquisition community. </p>
                </div>
            </div>
        </div>
    </div>
    <div class="clearfix">&nbsp;</div>
</div>
<!--==================================================
					FOOTER
================================================== -->

<div id="r_footer">
    <div class="container">
        <!--<div class="col-xs-12 col-sm-6 col-md-3 col-lg-2">
            <h3 class="title-banner DINCondensedBold"> CAP </p><p>
                <small>
                <span class="fa fa-dot-circle-o" ></span>&nbsp;AQUISITION GATEWAY</p><p><span class="fa fa-crosshairs" ></span>&nbsp;NAVIGATOR</p><p><span class="fa fa-institution" ></span>&nbsp;STATEMENT OF WORK LIBRARY</small></h3>


        </div>-->

        <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
            <h2 class="DINCondensedBold">ACQUISITION GATEWAY</h2>
        </div>
        <div class="col-xs-12 col-sm-3 col-md-3 col-lg-3">
            <h3>About Us</h3>

            <p>The Acquisition Gateway is managed by GSA’s Acquisition Gateway Team.<br><br><a
                    href="policy.php">Website Policies</a></p>
            <p><a href="#about-us" data-toggle="modal">Learn More</a></p>
        </div>
        <div class="col-xs-12 col-sm-3 col-md-3 col-lg-3">
            <h3>Explore</h3>
            <p>The Acquisition Gateway is intended to be your workspace for accurate, useful, and unbiased advice.
                <br><br>For the online guide to government information and services, visit <a href="http://www.USA.gov"
                                                                                              target="_blank">www.USA.gov</a>.<br><br>
            </p>
            <p><a href="#explore" data-toggle="modal">Learn More</a></p>
        </div>
        <div class="col-xs-12 col-sm-3 col-md-3 col-lg-3">
            <h3>Contact Us</h3>
            <p>Have a question about the Acquisition Gateway?<br><br>Check out our FAQs.<br><br><a
                    href="mailto:hallways_site_manager@gsa.gov" target="_blank">Email</a> us with your question.<br><br><a
                    href="https://foiaonline.regulations.gov" target="_blank">Submit</a> a FOIA request.</p>
            <p><a href="#help" data-toggle="modal">Learn More</a></p>
        </div>
        <div class="col-xs-12 col-sm-3 col-md-3 col-lg-3">
            <h3>Contribute &amp; Share</h3>
            <p>Share your expertise and advice.</p>
            <p><a href="#share" data-toggle="modal">Learn More</a></p>
            <!--<div class="hi-icon-wrap hi-icon-effect-1 hi-icon-effect-1b"> <a href="#set-1" class="hi-icon hi-icon-facebook">Facebook</a> <a href="#set-1" class="hi-icon hi-icon-twitter">Twitter</a> <a href="#set-1" class="hi-icon hi-icon-google">Google</a>  </div>-->
        </div>

    </div>
</div>

<!--================ FOOTER MODALS ==================-->
<div id="r_modal-container">

    <!-- about us modal -->
    <div id="about-us" class="cap-modal modal  fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog ">
            <div class="modal-content">
                <div class="modal-body ">

                    <div class="close"><a href="#" data-dismiss="modal">X</a></div>
                    <div class=" mheadBox app-head-box-image">
                        <div class="container">


                            <div id="b_head-box-content">


                                <h1 id="app-name">About Us</h1>
                            </div>


                        </div>
                    </div>

                    <div class="container-fluid" id="r_lca">



                        <div id="b_lca-bar">


                            <div id="lca-state">

                                <div class="col-xs-12 col-sm-12">
                                    <div class="progress">
                                        <div class="progress-bar progress-bar-primary"></div>
                                    </div>
                                    <span class="lca-title">LEARN</span>
                                </div>
                            </div>
                        </div>



                    </div>


                    <div id="r_content-main">
                        <div class="container">
                            <p dir="ltr" style="line-height:1.44;margin-top:0pt;margin-bottom:0pt;"><span style="color:#000000;"><span style="font-size:18px;"><strong><span style="font-family:verdana,geneva,sans-serif;"><span id="docs-internal-guid-164530b4-46b3-1e16-624b-cbb60a673e1f"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: rgb(249, 249, 244);">The Acquisition Gateway is managed by GSA’s Acquisition Gateway Team.  Using the practice of frequent, iterative development we let customer feedback inform how and what we build.  </span></span></span></strong></span></span></p>

                            <hr /><ul style="margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: circle; font-size: 14.6666666666667px; font-family: 'Helvetica Neue'; color: rgb(0, 0, 0); vertical-align: baseline; background-color: rgb(249, 249, 244);">
                            <p dir="ltr" style="line-height:1.44;margin-top:0pt;margin-bottom:0pt;"><span style="font-size:18px;"><span style="font-family:verdana,geneva,sans-serif;"><span id="docs-internal-guid-164530b4-46b3-a6cf-88af-b199a74b58da"><span style="color:#000000;"><span style="vertical-align: baseline; white-space: pre-wrap;">GSA’s Acquisition Gateway Team is building the Gateway to be the hub of an acquisition professional’s daily activities.  We are revamping how the government approaches procurement, replacing the decades-old model of a fragmented and scattered approach to acquisition. Join us and </span></span><a href="https://youtu.be/QtRIU_o01xk" style="text-decoration:none;" target="_blank"><span style="color:#0000CD;"><span style="font-style: italic; text-decoration: underline; vertical-align: baseline; white-space: pre-wrap;">Act as One</span></span></a><span style="color:#000000;"><span style="vertical-align: baseline; white-space: pre-wrap;">!</span></span></span></span></span><br />
                            </p>
                        </li>
                            <li dir="ltr" style="list-style-type: circle; font-size: 14.6667px; font-family: 'Helvetica Neue'; color: rgb(0, 0, 0); vertical-align: baseline; background-color: rgb(249, 249, 244);">
                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-46b3-a6cf-88af-b199a74b58da"><span style="vertical-align: baseline; white-space: pre-wrap;">We connect federal acquisition </span></span></span></span><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span style="vertical-align: baseline; white-space: pre-wrap;">professionals who want to share advice, success stories, and lessons learned. Federal government users, join the conversation today in our Community </span><span style="vertical-align: baseline; white-space: pre-wrap;">section of the Gateway!</span></span></span><br>
                            &nbsp;</p>
                            </li>
                            <li dir="ltr" style="list-style-type: circle; font-size: 14.6666666666667px; font-family: 'Helvetica Neue'; color: rgb(0, 0, 0); vertical-align: baseline; background-color: rgb(249, 249, 244);">
                                <p dir="ltr" style="line-height:1.656;margin-top:0pt;margin-bottom:0pt;"><span style="color:#000000;"><span style="font-size:18px;"><span style="font-family:verdana,geneva,sans-serif;"><span id="docs-internal-guid-164530b4-46b3-a6cf-88af-b199a74b58da"><span style="vertical-align: baseline; white-space: pre-wrap;">While GSA is building the Acquisition Gateway, we are approaching it from an absolutely unbiased perspective.  We want to present all of Government’s advice and knowledge in a given market and to allow you, the customer, to make informed decisions and act with confidence.<span id="docs-internal-guid-164530b4-46b3-a6cf-88af-b199a74b58da"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: rgb(249, 249, 244);">​</span></span></span></span></span></span></span><br />
                                </p>
                            </li>
                            <li dir="ltr" style="list-style-type: circle; font-size: 14.6666666666667px; font-family: 'Helvetica Neue'; color: rgb(0, 0, 0); vertical-align: baseline; background-color: rgb(249, 249, 244);">
                                <p dir="ltr" style="line-height:1.656;margin-top:0pt;margin-bottom:0pt;"><span style="color:#000000;"><span style="font-size:18px;"><span style="font-family:verdana,geneva,sans-serif;"><span id="docs-internal-guid-164530b4-46b3-a6cf-88af-b199a74b58da"><span style="vertical-align: baseline; white-space: pre-wrap;">We are a working example of the government’s adoption of Agile. The Acquisition Gateway Team follows the principles of frequent iterative feedback from across government as we build the Gateway using a collaborative and transparent process.  </span></span></span></span></span></p>
                            </li>
                        </ul>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>


    <!-- explore modal -->
    <div id="explore" class="cap-modal modal  fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog ">
            <div class="modal-content">
                <div class="modal-body ">

                    <div class="close"><a href="#" data-dismiss="modal">X</a></div>
                    <div class=" mheadBox app-head-box-image">
                        <div class="container">


                            <div id="b_head-box-content">


                                <h1 id="app-name">Explore</h1>
                            </div>


                        </div>
                    </div>

                    <div class="container-fluid" id="r_lca">



                        <div id="b_lca-bar">


                            <div id="lca-state">

                                <div class="col-xs-12 col-sm-12">
                                    <div class="progress">
                                        <div class="progress-bar progress-bar-primary"></div>
                                    </div>
                                    <span class="lca-title">LEARN</span>
                                </div>
                            </div>
                        </div>



                    </div>


                    <div id="r_content-main">
                        <div class="container">
                            <p><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><strong><span style="font-size:18px;">The Acquisition Gateway is intended to be your workspace for accurate, useful, and unbiased advice.  Take a look at what we have today and check back often to see the latest progress.</span></strong></span></span></p>

                            <hr /><p><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><span style="font-size:18px;"><em>Learn. Connect. Act.</em> The Acquisition Gateway is intended to be your workspace where you can Learn from those who do it best across Government, Connect with others who want to share their experiences, and Act with confidence knowing that you have consulted the best resources, information, and expertise available.</span></span></span><br /><br /><span style="font-size: 18px; font-family: verdana, geneva, sans-serif; color: rgb(0, 0, 0); line-height: 1.6;">Explore the ‘hallways’ of the Acquisition Gateway and preview what we have collected so far. The effort is far from over and we welcome your submissions and ideas as we collaboratively build your workspace for accurate, useful and unbiased advice.</span></p>

                            <ul><li><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><span style="font-size:18px;">​Solution Transparency:   government-wide expertise and guidance to help government buyers evaluate and select from the vast range of tools, contracts, products and services available in the market.</span></span></span></li>
                                <li><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><span style="font-size:18px;">Prices Paid:  for the first time ever, historical transactional pricing data from buys made by actual COs.</span></span></span></li>
                                <li><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><span style="font-size:18px;">Curated Expertise:   unbiased advice to find the best answer: from market trends, to starting points, to real-life guidance, to contract vehicle comparisons, (and more!) collected from across government.</span></span></span></li>
                                <li><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><span style="font-size:18px;">Community:  the connections necessary to share expertise, ideas, feedback, and support in making smart acquisition decisions.</span></span></span></li>
                            </ul><p><br /><span style="color:#000000;"><span style="font-family:verdana,geneva,sans-serif;"><span style="font-size:18px;">Don’t forget to check back often to see the latest progress!  And as always, we welcome your feedback and submissions.</span></span></span></p>

                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <!-- share connect and contribute -->
    <div id="share" class="cap-modal modal  fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog ">
            <div class="modal-content">
                <div class="modal-body ">
                    <!-- MODAL CLOSE BUTTON-->
                    <div class="close"><a href="#" data-dismiss="modal">X</a></div>
                    <div class=" mheadBox app-head-box-image">
                        <div class="container">
                            <!-- BLOCK - Headbox Content
       ################################################-->

                            <div id="b_head-box-content">

                                <!-- NODE - App Name
            ++++++++++++++++++++++++++++++++++++++++++++-->
                                <h1 id="app-name">Contribute &amp; Share</h1>

                            </div>

                            <!--  /END BLOCK - Headbox Content
       ###############################################-->
                        </div>
                    </div>
                    <!-- #LEARN-CONNECT-ACT BLOCK -->
                    <div class="container-fluid" id="r_lca">

                        <!-- BLOCK - LCA Bar
       ################################################-->

                        <div id="b_lca-bar">

                            <!-- NODE - LCA State
            ++++++++++++++++++++++++++++++++++++++++++++-->
                            <div id="lca-state">
                                <!-- default state shown in example -->
                                <div class="col-xs-12 col-sm-12">
                                    <div class="progress">
                                        <div class="progress-bar progress-bar-warning" style="width: 100%"></div>
                                    </div>
                                    <span class="lca-title">CONNECT</span> </div>
                            </div>
                        </div>

                        <!--  /END BLOCK - LCA Bar
       ###############################################-->

                    </div>
                    <!-- /END #LEARN-CONNECT-ACT BLOCK -->
                    <!-- CONTENT -->
                    <div id="r_content-main">
                        <div class="container">
                            <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12" id="right-content">
                                <div class="title-banner">Contribute</div>
                                <div class="subHead">Share your expertise.</div>
                                <p>Share your guides, templates, and tools with your community as an Acquisition Gateway "contributing member". Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.

                                    Thank you for your support. Let&apos;s start Acting as One!</p>

                                <hr /><div class="title-banner">Share</div>
                                <div class="subHead">Tell others about the Acquisition Gateway.</div>
                                <p></p>
                                <hr /><div class="hi-icon-wrap hi-icon-effect-1 hi-icon-effect-1b">
                                <a href="http://facebook.com/sharer.php?u=https://hallways.cap.gsa.gov/homepage/welcome.php&amp;t=Acquisition%20Gateway" class="hi-icon hi-icon-facebook" title="Facebook">Facebook</a> <a href="http://twitter.com/intent/tweet?url=https://hallways.cap.gsa.gov/homepage/welcome.php&amp;text=Acquisition%20Gateway" class="hi-icon hi-icon-twitter" title="Twitter">Twitter</a> <a href="https://plus.google.com/share?url=https://hallways.cap.gsa.gov/homepage/welcome.php" class="hi-icon hi-icon-google" title="Google Plus">Google Plus</a>
                            </div>


                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <!-- help contact us -->
    <div id="help" class="cap-modal modal  fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog ">
            <div class="modal-content">
                <div class="modal-body ">

                    <div class="close"><a href="#" data-dismiss="modal">X</a></div>
                    <div class=" mheadBox app-head-box-image">
                        <div class="container">


                            <div id="b_head-box-content">


                                <h1 id="app-name">Contact Us</h1>
                            </div>


                        </div>
                    </div>

                    <div class="container-fluid" id="r_lca">



                        <div id="b_lca-bar">


                            <div id="lca-state">

                                <div class="col-xs-12 col-sm-12">
                                    <div class="progress">
                                        <div class="progress-bar progress-bar-primary"></div>
                                    </div>
                                    <span class="lca-title">LEARN</span>
                                </div>
                            </div>
                        </div>



                    </div>


                    <div id="r_content-main">
                        <div class="container">
                            <p style="line-height: 20.8px;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><strong><span style="line-height: 1.38; color: rgb(0, 0, 0); vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Don’t see your question below, contact us </span><a href="mailto:hallways_site_manager@gsa.gov" style="font-family: arial, helvetica, sans-serif; line-height: 1.38; text-decoration: none;"><span style="color: rgb(17, 85, 204); text-decoration: underline; vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">here</span></a><span style="line-height: 1.38; color: rgb(0, 0, 0); vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">.</span></strong></span></span></p>

                            <hr style="line-height: 20.8px;"><p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><strong><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Why is GSA launching the Acquisition Gateway?</span></span></strong></span></span></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The mission of GSA’s F</span></span><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">ederal Acquisition Service (FAS) is to make it easier, faster and less costly to do government acquisition. &nbsp;</span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway is an online workplace that will help deliver the benefits of category management and, in the future, make it easier and faster for government buyers to get through every step of the full acquisition process.</span></span></span></span><br>
                                    &nbsp;</p>
                            </li>
                                <li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                    <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">A view of all the existing contract vehicles from across government, current market trends and expertise, transactional data, and good practices will help buyers navigate the cluttered acquisition landscape and drive the government to </span><a href="https://youtu.be/QtRIU_o01xk" style="text-decoration: none;" target="_blank"><span style="color: rgb(0, 0, 205);"><span style="font-style: italic; text-decoration: underline; vertical-align: baseline; white-space: pre-wrap;">Act as One</span></span></a><span style="font-style: italic; vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">.</span><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;"> This will lead to improved requirements, stronger negotiations, less redundancy, and data-driven purchasing decisions.</span></span></span></span></p>
                                </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><strong><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">What is the Acquisition Gateway?</span></span></strong></span></span></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway is a workplace for the federal acquisition community. Through the Acquisition Gateway, we'll empower the federal government to </span><a href="https://youtu.be/QtRIU_o01xk" style="text-decoration: none;" target="_blank"><span style="color: rgb(0, 0, 205);"><span style="font-style: italic; text-decoration: underline; vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Act as One</span></span></a><span style="font-style: italic; vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">-- </span><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">working smarter, faster, and better. &nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Gateway is one common portal that provides online access to the Category Hallways- a single location and online workspace for government procurement professionals with resources like a matrix of existing contracts from across government, data and prices paid information, market trends and analysis, and best practices. &nbsp;&nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Gateway will help buyers navigate the cluttered acquisition landscape, leading to improved requirements, stronger negotiations, less redundancy, and data-driven purchasing decisions.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">To date, GSA has launched 19 category hallways. &nbsp;They include: Administrative Support, Card Services, Cleaning Supplies &amp; Chemicals, Employee Relocation, Facilities Maintenance Services, Freight, Human Capital, IT Hardware, IT Security, IT Services, IT Software, Motor Vehicles, Professional Services, Security &amp; Protection, Small Package Delivery, Telecommunications, Tools &amp; Hardware, Travel, and Workplace Environment.</span><br><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">&nbsp;</span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><strong><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Why should I register as a user of the Acquisition Gateway?</span></span></strong></span></span></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(34, 34, 34); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">GSA is building the Acquisition Gateway to be the hub of an acquisition professional’s daily activities. &nbsp;The tools, expertise and content in the hallways comes from agencies all across government to form an agnostic, bias-free place for contracting professionals to do their work.</span></span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(34, 34, 34); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway will guide federal procurement professionals through data-driven procurement actions that help agencies comply with regulations, meet socio-economic acquisition goals, and support program teams delivering on the agency mission.</span></span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(34, 34, 34); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Gateway will help buyers navigate the cluttered acquisition landscape, leading to improved requirements, stronger negotiations, less redundancy, and data-driven purchasing decisions.</span></span></span></span></span><br>
                                    &nbsp;</p>
                            </li>
                                <li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                    <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">GSA wants government contracting professionals to help us build the Acquisition Gateway. We want this to be their tool filled with their best practices. If you’re an acquisition professional, we need your thoughts and feedback. Tell us what you need to make this tool work great for you, and we will make it happen. &nbsp;</span></span></span></span></p>
                                </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway will eventually evolve into a community of practice for procurement. &nbsp;In order to make this tool the best it can be for everyone, we need the collective wisdom and expertise of government acquisition professionals from across every federal agency.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><strong><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Is this just another website?</span></span></span></span></strong></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway and the category hallways are more than just another website. They were developed as a resource and a shared service that provides decision support to acquisition professionals by integrating both content and digital services.</span></span></span></span><br class="kix-line-break">
                                    &nbsp;</p>
                            </li>
                            </ul><ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">A community feature has been added to allow contracting professionals and government buyers to talk to other members of the acquisition community.</span></span></span></span></p>
                        </li>
                        </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway is the first step in building a community of expertise, based on transparency, that shares the collective knowledge everyone needs to conduct smarter acquisitions.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><strong><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Is this tool for GSA only?</span></span></span></span></strong></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(34, 34, 34); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway and the hallways are being developed for use by all acquisition professionals in the federal government.</span></span></span></span></span><br class="kix-line-break">
                                    &nbsp;</p>
                            </li>
                            </ul><ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(34, 34, 34); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">GSA is leading the development of the platform in collaboration with the OMB Office of Federal Procurement Policy (OFPP) and the Category Management Leadership Council (CMLC) which is made up of representatives from agencies across government. The Office of Personnel Management (OPM) built a Human Capital&nbsp;hallway and Department of Defense (DoD) built &nbsp;a Small Package Delivery hallway in partnership with GSA, using the Acquisition Gateway platform. &nbsp;However, GSA does not intend to exert ownership or bias related to the content and expertise in the hallways.</span></span></span></span></span></p>
                        </li>
                        </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(34, 34, 34); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The site’s content has been developed in partnership with category experts across the government to ensure we are collecting and providing the expertise and data that contracting professionals need, regardless of the agency in which the expertise resides.</span></span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;"><strong>How is GSA working with other agencies?</strong> &nbsp;</span></span></span></span></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Because expertise resides across the government, GSA’s partner agency relationships are critical to the success of the Acquisition Gateway and hallways.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Collaboration and sharing of data, contracts and expertise between agencies is the foundation of the Gateway and category hallways. &nbsp;</span></span></span></span><br>
                                    &nbsp;</p>
                            </li>
                                <li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                    <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">We're working with the category managers and teams at DoD (Small Package Delivery hallway) and OPM (Human Capital hallway) to identify contract vehicles, data, trends, content and expertise in those categories. &nbsp;</span></span></span></p>
                                </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Category managers and </span><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">content experts from across government are curating the resources and tools available through the hallways, constantly updating the information to ensure it’s both relevant and valuable to the acquisition workforce.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><strong><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Why is GSA developing this tool?</span></span></span></span></strong></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Federal procurement is complicated and challenging. &nbsp;</span><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">GSA’s Federal Acquisition Service is the only civilian agency in the federal government whose mission is acquisition and we </span><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">want to work with all of our stakeholders to make it easier. &nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">We know what contracting professionals need to do their job and to make tough decisions and we have insight into the needs and priorities of the federal buyer.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">We're building tools, resources, and communities that truly help acquisition professionals achieve better outcomes for the American people. &nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><strong style="color: rgb(0, 0, 0); line-height: 1.656;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">What is Category Management?</span></span></span></span></strong></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Category Management groups similar goods and services as business units, or categories, in order to manage spending and leverage the government’s buying power.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Category Management is all about leveraging data, best practices, subject matter expertise and existing contract vehicles, leading to smarter decisions, better purchasing options, and lower costs. &nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><strong><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">How do the Acquisition Gateway and Category Management work together?</span></span></span></span></strong></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Category Management is a fundamental transformation of the way the GSA and the government buys goods and services.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway will help us transform our buying behaviors by pulling all of the purchasing data, buying activity, best practices and contracts available into one place.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway &nbsp;will assist acquisition professionals by providing all of the curated category expertise and data that is available governmentwide in one single tool.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><br class="kix-line-break"><span style="color: rgb(0, 0, 0);"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><strong><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">How can members of the workforce make this tool work better for them?</span></span></strong></span></span></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway provides a single workspace where contracting professionals become informed, connect with colleagues and experts, and then complete acquisition. &nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">We’ve taken the first step with the launch of the 19 category hallways, which include </span></span></span></span><span style="font-family: verdana, geneva, sans-serif; font-size: 18px; line-height: 29.808px; white-space: pre-wrap;">Administrative Support, Card Services, Cleaning Supplies &amp; Chemicals, Employee Relocation, Facilities Maintenance Services, Freight, Human Capital, IT Hardware, IT Security, IT Services, IT Software, Motor Vehicles, Professional Services, Security &amp; Protection, Small Package Delivery, Telecommunications, Tools &amp; Hardware, Travel, and Workplace Environment. </span><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">Now, the Acquisition Gateway Team needs the wisdom of the crowd, and the expertise hidden across the acquisition community, to make the Gateway and the hallways the best they can be. &nbsp;</span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">We want contracting professionals to explore, comment, critique, and share their ideas and tools. This is just the beginning, and working together we can build a site that fits the needs of contracting professionals and that helps the government act as one. We would like them to join us and contribute their knowledge and expertise to make the hallways better.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt; margin-left: 72pt;"><span style="color: rgb(0, 0, 0);"><strong><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">When will the Acquisition Gateway and the hallways be completed?</span></span></span></span></strong></span></p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">What users see in the Acquisition Gateway today is only the beginning. GSA is moving forward on building more functionality into the Gateway. &nbsp;</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.656; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">The Acquisition Gateway and the hallways are being built through an agile and iterative process. What users see in the Gateway today is the foundation from which we have started, what they will see next week or six months from now will be different, perhaps easier to navigate and more robust.</span></span></span></span></p>
                            </li>
                            </ul><p dir="ltr" style="line-height: 1.38; margin-top: 0pt; margin-bottom: 8pt;">&nbsp;</p>

                            <ul style="line-height: 20.8px; margin-top: 0pt; margin-bottom: 0pt;"><li dir="ltr" style="list-style-type: disc; font-size: 16px; font-family: Arial; color: rgb(0, 0, 0); vertical-align: baseline; margin-left: 96px; background-color: transparent;">
                                <p dir="ltr" style="line-height: 1.63636; margin-top: 0pt; margin-bottom: 0pt;"><span style="font-size: 18px;"><span style="font-family: verdana, geneva, sans-serif;"><span id="docs-internal-guid-164530b4-4754-07df-84cf-77d829b3590c"><span style="vertical-align: baseline; white-space: pre-wrap; background-color: transparent;">How this tool evolves will depend on what the federal workforce tells GSA what we need to do to make it a better tool to support them and their work.</span></span></span></span></p>
                            </li>
                            </ul>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<a href="#" class="scrollToTop"><span class="fa fa-chevron-up"></span></a>
<!--==================================================
					MY GATEWAY MENU
================================================== -->
<!--<div id="container" class="container"></div>-->
<!--<div class="morph-button morph-button-sidebar morph-button-fixed">
	<button type="button" ><span class="fa fa-dot-circle-o fa-2x"></span></button>
	<div class="morph-content">
		<div>
			<div class="content-style-sidebar"> <span class="fa fa-close icon-close"></span>
				<h2><span class="fa fa-dot-circle-o"></span> &nbsp; My Gateway</h2>
				<ul>
					<li><a href="#"><span class="fa fa-filter"></span> Default filters</a></li>
					<li><a href="#"><span class="fa fa-heart"></span> Favorites</a></li>
					<li><a href="#"><span class="fa fa-upload"></span> Uploads</a></li>
					<li><a href="#"><span class="fa fa-pagelines"></span> Documents</a></li>
					<li><a href="#"><span class="fa fa-user"></span> Profile</a></li>
					<li><a href="#"><span class="fa fa-globe"></span> Global Options</a></li>
				</ul>
			</div>
		</div>
	</div>
</div>-->

<!--==================================================
					SCRIPTS
================================================== -->

<!-- CORE THEME SCRIPTS   
------------------------------------------------------------------------------------------>
<script src="assets/js/cap-os-v1-foot.js"></script>
<noscript>
</noscript>
<!---->
<script src="assets/js/cap-os-v1-custom.js"></script>
<noscript>
</noscript>
<!---->
<script>
    $(document).ready(
            $('a.toggleview').click(function () {
                var value = $(this).html();
                if (value == 'View Less') {
                    $(this).html('View All');
                    $('#hallway-tiles #cvt .grid').css('height', "200px");

                }
                else {
                    $(this).html('View Less');
                    $('#hallway-tiles #cvt .grid').css('height', "100%");

                }


            })
    );

    $(document).ready(
            $('a#toggleView').click(function () {
                var value = $(this).html();
                if (value == 'View Less') {
                    $(this).html('...');
                    $('#hallway-tiles #cvt .grid').css('height', "200px");

                }
                else {
                    $(this).html('View Less');
                    $('#hallway-tiles #cvt .grid').css('height', "100%");

                }


            })
    );


    $(document).ready(function () {
        var elem = $('#cvt ul');
        $('#viewcontrols a').on('click', function (e) {
            if ($(this).hasClass('gridview')) {
                elem.fadeOut(400, function () {
                    $('#cvt ul').removeClass('list').addClass('grid');
                    $('#viewcontrols').removeClass('view-controls-list').addClass('view-controls-grid');
                    $('#viewcontrols .gridview').addClass('active');
                    $('#viewcontrols .allview').show();
                    $('#viewcontrols .toggleview').removeClass('hide');
                    $('#toggleView').removeClass('hide');
                    $('#toggleView').html('...');
                    elem.fadeIn(700);
                    $('#hallway-tiles #cvt .grid').css('height', "200px");
                });
            }
            else if ($(this).hasClass('listview')) {
                elem.fadeOut(400, function () {
                    $('#cvt ul').removeClass('grid').addClass('list');
                    $('#viewcontrols').removeClass('view-controls-grid').addClass('view-controls-list');
                    $('#viewcontrols .gridview').removeClass('active');
                    $('#viewcontrols .listview').addClass('active');
                    $('#viewcontrols .toggleview').addClass('hide');
                    $('#toggleView').addClass('hide');
                    $('#hallway-tiles #cvt .list').css('height', "auto");

                    elem.fadeIn(700);

                });
            }


        });
    });

</script>


<!-- THUMBNAIL FLIP OUT SCRIPT -->
<!--<script type="text/javascript">
$(function()
{ 
    $('ul.grid li').mouseover(function()
    {
        var newimg = $('div.hallway',this);
        $('div.hallway',this).addClass('grow');
		$('div.hallway-push',this).addClass('grow');
		$('ul.grid').addClass('stunt');
    });
	$('ul.grid li').mouseout(function()
    {
        var newimg = $('div.hallway',this);
        $('div.hallway',this).removeClass('grow');
		$('div.hallway-push',this).removeClass('grow');

		$('ul.grid').removeClass('stunt');
    });
});
</script>-->
<!---->

<script type="text/javascript">
    $('#ebuOpenDesc').hide();
    $('#techFarDesc').hide();
    $('#sharedRecDesc').hide();
    $('#ebuyOpenBtn').hover(
            function () {
                $('#ebuOpenDesc').show();
            },
            function () {
                $('#ebuOpenDesc').hide();
            }
    );

    $('#techFarBtn').hover(
            function () {
                $('#techFarDesc').show();
            },
            function () {
                $('#techFarDesc').hide();
            }
    );

    $('#sharedRecBtn').hover(
            function () {
                $('#sharedRecDesc').show();
            },
            function () {
                $('#sharedRecDesc').hide();
            }
    );

    $('#sidebar').affix({
        offset: {
            top: 0,

        }
    });

</script>

<script>
    $(document).ready(function () {

        //Check to see if the window is top if not then display button
        $(window).scroll(function () {
            if ($(this).scrollTop() > 100) {
                $('.scrollToTop').fadeIn();
            } else {
                $('.scrollToTop').fadeOut();
            }
        });

        //Click event to scroll to top
        $('.scrollToTop').click(function () {
            $('html, body').animate({scrollTop: 0}, 800);
            return false;
        });

    });
</script>
<!-- Google Tag Manager -->
<?php 
  require('./sites/default/settings.php');
?>
<noscript>
    <iframe src="//www.googletagmanager.com/ns.html?id=<?=$container_id;?>"
            height="0" width="0" style="display:none;visibility:hidden"></iframe>
</noscript>

<script>(function (w, d, s, l, i) {
    w[l] = w[l] || [];
    w[l].push({
        'gtm.start': new Date().getTime(), event: 'gtm.js'
    });
    var f = d.getElementsByTagName(s)[0],
            j = d.createElement(s), dl = l != 'dataLayer' ? '&l=' + l : '';
    j.async = true;
    j.src =
            '//www.googletagmanager.com/gtm.js?id=' + i + dl;
    f.parentNode.insertBefore(j, f);
})(window, document, 'script', 'dataLayer', '<?= $container_id?>');</script>
<!-- End Google Tag Manager -->
</body>
</html>