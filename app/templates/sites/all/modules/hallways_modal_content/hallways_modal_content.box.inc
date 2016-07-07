<?php
/**
 * @file
 * hallways_modal_content.box.inc
 */

/**
 * Implements hook_default_box().
 */
function hallways_modal_content_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'administrative_resources';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Administrativ Resources Content';
  $box->options = array(
    'body' => array(
      'value' => '
<!--================ MODALS ========================--><!-- MODALS GO HERE  --><!--ADMINISTRATIVE SERVICS - PRICES PAID MODAL-->
<div class="modal fade" id="pricesPaid">
<div class="modal-dialog  modal-lg">
<div class="modal-content">
<div class="modal-header blue"><button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
<h3>Historical Prices Paid Data</h3>
</div>

<div class="modal-body resources">
<div class="row">
<div class="col-sm-4">GSA Advantage:
<ul>
	<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ1.xlsx">Advantage_FY2014FYQ1.xlsx</a></li>
	<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ2.xlsx" id="rf2">Advantage_FY2014FYQ2.xlsx</a></li>
	<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ3.xlsx" id="rf3">Advantage_FY2014FYQ3.xlsx</a></li>
</ul>
</div>

<div class="col-sm-8">These are GSA Advantage data sets that have purchases of commercial products and services from FSS Schedule contracts and GSA GWACs. The following categories are included: building &amp; industrial; furniture &amp; furnishings; cleaning &amp; chemicals; IT solutions &amp; electronics; laboratory, cleaning, medical; law enforcement, fire, security; office solutions; recreational &amp; apparel; services; tools, hardware, machinery; vehicles, watercraft. The data is published quarterly. You can visit GSA Advantage! <a href="https://www.gsaadvantage.gov/advantage/main/start_page.do" target="new">here</a>.</div>
</div>

<hr />
<div class="row">
<div class="col-sm-4">GSA Federal Supply System (FSS-19):
<ul>
	<li><a href="/system/files/resourcefiles/FSS19_FY2014_FYQ1.xlsx">FSS19_FY2014_FYQ1.xlsx</a></li>
	<li><a href="/system/files/resourcefiles/FSS19_FY2014_FYQ2.xlsx">FSS19_FY2014_FYQ2.xlsx</a></li>
	<li><a href="/system/files/resourcefiles/FSS19_FY2014_FYQ3.xlsx">FSS19_FY2014_FYQ3.xlsx</a></li>
</ul>
</div>

<div class="col-sm-8">These are data sets pulled from the FSS-19 system, a contract system for procurement and distribution of supplies. The data includes transactions and pricing of the GSA supply and schedule contracts. Specific details on stored stock orders, the Special Orders Program, expanded direct delivery, and schedule orders sales from the GSA Federal Supply System are of note. The data is updated on a quarterly basis.</div>
</div>

<hr />
<div class="row">
<div class="col-sm-4">OS2:
<ul>
	<li><a href="/system/files/resourcefiles/EDW_Products_OS2_FY2014_FYQ1.xls">EDW_Products_OS2_FY2014_FYQ1.xls</a></li>
	<li><a href="/system/files/resourcefiles/EDW_Products_OS2_FY2014_FYQ2.xls">EDW_Products_OS2_FY2014_FYQ2.xls</a></li>
	<li><a href="/system/files/resourcefiles/EDW_Products_OS2_FY2014_FYQ3.xls">EDW_Products_OS2_FY2014_FYQ3.xls</a></li>
</ul>
</div>

<div class="col-sm-8">These are data sets pulled from purchases associated with GSA\\\'s Second-Generation Office Supplies (OS2) program. The data sets have purchases from products in the office equipment and supplies category. These include: Ability One products; toner supplies; small business products; green products. The data focuses on contractor, product name, minimum order requirement, NSN/manufacturer part number, shipping, and variation in price. It centers on GSA\\\'s Schedule 75 for Office Supplies. The data is published quarterly. For more details on what OS2 includes, please <a href="https://www.gsaadvantage.gov/advantage/department/main.do?cat=ADV.FSSI" target="new">click here</a>.</div>
</div>

<hr />
<div class="row">
<div class="col-sm-4"><a href="http://public.tableausoftware.com/views/OfficeSupplies2ndGenerationsOS2FSSI/SecondGenerationOfficeSuppliesOS2FSSISavingsSmallBusinessSuccess?amp;:embed=y&amp;:display_count=no?:showVizHome=no#" target="new">OS2 Prices Paid Dashboard</a></div>

<div class="col-sm-8">The OS2 dashboard (updated August 2014) was developed as a key component of GSAís goal to increase transparency and demonstrate success with its ongoing support of small business, veterans, and taxpayers. The easy to use, interactive dashboard displays historical pricing and sales data that demonstrates cumulative cost savings and small business utilization goals across federal agencies, clearly illustrating GSAís commitment to maximizing opportunities for small business and veteran communities.</div>
</div>

<hr />
<div class="row">
<div class="col-sm-4">Reverse Auctions:
<ul>
	<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q1.xlsx">REVERSE_AUCTIONS_FY2014_Q1.xlsx</a></li>
	<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q2.xlsx">REVERSE_AUCTIONS_FY2014_Q2.xlsx</a></li>
	<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q3.xlsx">REVERSE_AUCTIONS_FY2014_Q3.xlsx</a></li>
</ul>
</div>

<div class="col-sm-8">GSA Reverse Auction is a platform for buying non-complex commodities and simple services. GSA Reverse Auction is an eTool and can be used to facilitate the request for and submission of quotes, offers or proposals for products, services, and solutions through GSA Multiple Award Schedules (MAS) and Blanket Purchase agreements (BPAs).</div>
</div>
</div>

<div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div>
</div>
</div>
</div>

<!--CONTRIBUTE MODAL-->

<div class="modal fade" id="contribute">
<div class="modal-dialog modal-lg">
<div class="modal-content">
<div class="modal-header orange"><button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
<h3>Connect &amp; Contribute</h3>
</div>

<div class="modal-body resources">
<div class="row">
<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Connect</h3>

<p>Join the conversation. Connect with peers in the <a href="https://interact.gsa.gov/group/acquisition-gateway">Interact</a> community.</p>
</div>
</div>

<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Want to contribute?</h3>

<p>Share your guides, templates, and tools with your community as a Acquisition Gateway "contributing member".  Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.</p>
</div>
</div>
</div>
</div>

<div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div>
</div>
</div>
</div>
<!-- /END MODALS GO HERE -->',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['administrative_resources'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'education_resource_content';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Education Resource Content';
  $box->options = array(
    'body' => array(
      'value' => '<!--TRAINING -->
<div class="modal fade" id="pricesPaid" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog  modal-lg">
    <div class="modal-content">
      <div class="modal-header blue">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3>Historical Prices Paid Data</h3>
      </div>
	  
      <div class="modal-body resources">
       
	   <div class="row">
	   <div class="col-sm-4">
		<a href="/sites/default/files/article_files/2013%20Prices%20Paid%20Matrix%20%284%29.xlsx">2013 Prices Paid Matrix </a></div>
	   <div class="col-sm-8">Data of prices paid for acquisition training courses based on an OMB data call.</div>
      </div>

	  
	  </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      
      </div>
    </div>
  </div>
</div>


<!--CONTRIBUTE MODAL-->

<div class="modal fade" id="contribute">
<div class="modal-dialog modal-lg">
<div class="modal-content">
<div class="modal-header orange"><button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">×</span><span class="sr-only">Close</span></button>
<h3>Connect &amp; Contribute</h3>
</div>

<div class="modal-body resources">
<div class="row">
<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Connect</h3>

<p>Join the conversation. Connect with peers in the <a href="https://interact.gsa.gov/group/acquisition-gateway">Interact</a> community.</p>
</div>
</div>

<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Want to contribute?</h3>

<p>Share your guides, templates, and tools with your community as a Acquisition Gateway "contributing member".  Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.</p>
</div>
</div>
</div>
</div>

<div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div>
</div>
</div>
</div>
<!-- /END MODALS GO HERE -->',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['education_resource_content'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'professional_resource_content';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Professional Resource Content';
  $box->options = array(
    'body' => array(
      'value' => '<!--PRO SERVICS -->
<div class="modal fade " id="pricesPaid" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog  modal-lg">
    <div class="modal-content">
      <div class="modal-header blue">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3>Historical Prices Paid Data</h3>
      </div>
	  
      <div class="modal-body resources">
       
	   <div class="row">
	   <div class="col-sm-4">
		<a href="/sites/default/files/article_files/PM%20CPI%20Task%20Order%20Pricing%20Breakout%20121814.xlsx">Performance Management/Continuous Process Improvement (PM/CPI) Blanket Purchase Agreement (BPA)</a></div>
	   <div class="col-sm-8"><p>The linked spreadsheet contains hourly rates and task order summaries for professional services ordered using GSA’s governmentwide PM/CPI BPA. Hourly rates are displayed next to GSA awarded schedule rates plus any negotiated discount. </p>

<p>The BPA is used for the following services:</p>
<ul>
<li>Strategic Planning and Performance Management;</li>
<li>Strategic Business Analysis;</li>
<li>Process and Performance Improvement;</li>
<li>Communications and Change Management; and</li>
<li>Training, Certification and Recognition.</li>
</ul>
<p>Agency and vendor names have been redacted. The information is updated quarterly.</p>

<p>Learn more about the PM/CPI BPA <a href="http://gsa.gov/portal/content/172831" target="new">here</a>.</p>

<p>Disclaimer: It is incumbent upon the contracting professional to use his/her discretion when making decisions and comparisons using the collected data.</p> 
</div>
      </div>

	  
	  </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      
      </div>
    </div>
  </div>
</div>



<!--CONTRIBUTE MODAL-->

<div class="modal fade" id="contribute">
<div class="modal-dialog modal-lg">
<div class="modal-content">
<div class="modal-header orange"><button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">×</span><span class="sr-only">Close</span></button>
<h3>Connect &amp; Contribute</h3>
</div>

<div class="modal-body resources">
<div class="row">
<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Connect</h3>

<p>Join the conversation. Connect with peers in the <a href="https://interact.gsa.gov/group/acquisition-gateway">Interact</a> community.</p>
</div>
</div>

<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Want to contribute?</h3>

<p>Share your guides, templates, and tools with your community as a Acquisition Gateway "contributing member".  Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.</p>
</div>
</div>
</div>
</div>

<div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div>
</div>
</div>
</div>
<!-- /END MODALS GO HERE -->',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['professional_resource_content'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'resources_ithardware_content';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'IT Hardware Resources Content';
  $box->options = array(
    'body' => array(
      'value' => '
<!--================ MODALS ========================--> 
<!-- MODALS GO HERE - currently incomplete in this version -->


<!--ITHW SERVICS - PRICES PAID MODAL-->
<div class="modal fade" id="pricesPaid" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog  modal-lg">
    <div class="modal-content">
      <div class="modal-header blue">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3>Historical Prices Paid Data</h3>
      </div>
	  
      <div class="modal-body resources">
       <div class="row">
	   <div class="col-sm-4"><a href="/system/files/AF%20QEB%202012B.pdf" id="resourcefiles">Air Force Quantum Enterprise Buy</a></div>
	   <div class="col-sm-8">The products offered in this catalog are under the Client Computing and Servers (CCS) Blanket Purchase Agreement (BPA) authority. The Quantum Enterprise Buy (QEB) team prepared this catalog to provide information on the specific QEB products available on AFWay. The IT Commodity Council (ITCC) conducted a product bid and selection cycle to identify the CCS vendor IT products which best met ITCC product specifications. The recommended products were presented to the Major Command (MAJCOM) representatives of the ITCC who made the final recommendation to the CCS Procuring Contracting Officer (PCO). The CCS PCO awarded the selected products to the applicable vendors. </div>
      </div>
	  <hr />
	   
	  
	  <div class="row">
	   <div class="col-sm-4">
GSA Advantage:
<ul class="list-unstyled">
<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ1.xlsx">Advantage_FY2014FYQ1.xlsx</a></li> 
<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ2.xlsx">Advantage_FY2014FYQ2.xlsx</a> </li>
<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ3.xlsx">Advantage_FY2014FYQ3.xlsx</a></li>
</ul>
</div>
	   <div class="col-sm-8">These are GSA Advantage data sets that have purchases of commercial products and services from FSS Schedule contracts and GSA GWACs. The following categories are included: building & industrial; furniture & furnishings; cleaning & chemicals; IT solutions & electronics; laboratory, cleaning, medical; law enforcement, fire, security; office solutions; recreational & apparel; services; tools, hardware, machinery; vehicles, watercraft. The data is published quarterly. You can visit GSA Advantage! <a href="https://www.gsaadvantage.gov/advantage/main/start_page.do" target="new">here</a>. </div>
      </div>
	   
	  <hr />
	  <div class="row">
	   <div class="col-sm-4">
	   NITCP:
	   <ul class="list-unstyled">
<li><a href="/system/files/resourcefiles/NITCP_OS2FY2014_FYQ1.xlsx">NITCP_OS2FY2014_FYQ1.xlsx</a></li> 
</ul>
</div>
	   <div class="col-sm-8">This data is from purchases associated with GSAs National IT Commodity Program (NITCP). NITCP is a collection of BPAs for IT Hardware. One avenue to purchase off of the BPA is through GSA Reverse Auctions. The data reports shared are inclusive of all NITCP BPA purchases regardless of procurement channel. Procurements focus on IT commodities and ancillary services for federal, state, and local governments using innovative solutions. Specific offerings include: computers, data center equipment, mobile solutions, monitors, tablets, and video teleconferencing equipment. This data is published quarterly.</div>
      </div>
	   
	  
	   
	 
	  
	  <hr />
	  <div class="row">
	   <div class="col-sm-4">
	   Reverse Auctions:
	   <ul class="list-unstyled">
<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q1.xlsx">REVERSE_AUCTIONS_FY2014_Q1.xlsx</a></li> 
<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q2.xlsx">REVERSE_AUCTIONS_FY2014_Q2.xlsx</a> </li>
<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q3.xlsx">REVERSE_AUCTIONS_FY2014_Q3.xlsx</a></li>
</ul>
	   </div>
	   
	   <div class="col-sm-8">GSA Reverse Auction is a platform for buying non-complex commodities and simple services. GSA Reverse Auction is an eTool and can be used to facilitate the request for and submission of quotes, offers or proposals for products, services, and solutions through GSA Multiple Award Schedules (MAS) and Blanket Purchase agreements (BPAs).</div>
      </div>
	  
	  </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      
      </div>
    </div>
  </div>
</div>

<!--ITHW SERVICS - TRANSACTIONAL PLATFORMS MODAL-->
<!--CONTRIBUTE MODAL-->
<div class="modal fade" id="contribute" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header orange">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3 class="modal-title" id="myModalLabel"> Connect &amp; Contribute </h3>
      </div>
<div class="modal-body resources">
<div class="row">
<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Connect</h3>

<p>Join the conversation. Connect with peers in the <a href="https://interact.gsa.gov/group/acquisition-gateway">Interact</a> community.</p>
</div>
</div>

<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Want to contribute?</h3>

<p>Share your guides, templates, and tools with your community as a Acquisition Gateway "contributing member".  Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.</p>
</div>
</div>
</div>
</div>
      <div class="modal-footer">
        <button type="button" class="btn btn-sm btn-default" data-dismiss="modal">Close</button>
        
      </div>
    </div>
  </div>
</div>
<!-- /END MODALS GO HERE - currently incomplete in this version --> ',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['resources_ithardware_content'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'resources_itsoftware_content';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'IT Software Resources Content';
  $box->options = array(
    'body' => array(
      'value' => '
<!--================ MODALS ========================--> 
<!-- MODALS GO HERE - currently incomplete in this version -->


<!--ITSW SERVICS - PRICES PAID MODAL-->
<div class="modal fade" id="pricesPaid" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog  modal-lg">
    <div class="modal-content">
      <div class="modal-header blue">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3>Historical Prices Paid Data</h3>
      </div>
	  
      <div class="modal-body resources">
       <div class="row">
	   <div class="col-sm-4">
	   DoD ESI Data:
	   <ul class="list-unstyled">
<li><a href="http://www.esi.mil/AskAnExpert.aspx" target="new">DoD ESI Software Prices Paid </a></li> 
</ul>
</div>
	   <div class="col-sm-8">The DoD ESI project, begun under the auspices of the then-brand new DoD CIO Council in 1998, has amassed a substantial amount of software sales data through DoD ESI vehicles.  This curated and normalized database is maintained by the Department of the Navy Software Product Manager for DoD ESI, and the information within can be useful for software buyers, CIO staff, or functional Program Manager personnel around the U.S. Government who seek meaningful comparisons to pricing they have received, or to view a spread of likely software pricing before solicitation.  Raw data by itself, though, is difficult to parse and draw meaning from, so access to this database is available only through this “Ask an Expert (Product Manager)” link on the DoD ESI website.</div>
      </div>
	   <hr />
	  <div class="row">
	   <div class="col-sm-4">
GSA Advantage:
<ul class="list-unstyled">
<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ1.xlsx">Advantage_FY2014FYQ1.xlsx</a></li> 
<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ2.xlsx">Advantage_FY2014FYQ2.xlsx</a> </li>
<li><a href="/system/files/resourcefiles/Advantage_FY2014FYQ3.xlsx">Advantage_FY2014FYQ3.xlsx</a></li>

</ul>
</div>
	   <div class="col-sm-8">These are GSA Advantage data sets that have purchases of commercial products and services from FSS Schedule contracts and GSA GWACs. The following categories are included: building & industrial; furniture & furnishings; cleaning & chemicals; IT solutions & electronics; laboratory, cleaning, medical; law enforcement, fire, security; office solutions; recreational & apparel; services; tools, hardware, machinery; vehicles, watercraft. The data is published quarterly. You can visit GSA Advantage! <a href="https://www.gsaadvantage.gov/advantage/main/start_page.do" target="new">here</a>. </div>
      </div>
	 
	   
	  
	  
	   
	  <hr />
	  
	   
	  
	   <div class="row">
	   <div class="col-sm-4">
	   GSA SmartBUY:
	   <ul class="list-unstyled">
	   <li><a href="/system/files/resourcefiles/GSA_SMARTBUY_AGENCY_SKU_LEVEL_PRICING.csv">GSA_SMARTBUY_AGENCY_SKU_LEVEL_PRICING.csv</a></li>
	   <li><a href="/system/files/resourcefiles/GSA_SMARTBUY_SCHEDULE_70_PRICING.csv<">GSA_SMARTBUY_SCHEDULE_70_PRICING.csv</a></li>
</ul>
</div>
	   <div class="col-sm-8">
Acquisition data from 14 different Agencies\\\' Microsoft Enterprise Agreements. Information on the the following areas is displayed: 
<ul>
<li>Basic contract information: 1) contract Size [Seats]; 2) annual spending; 3) length of contract; 4) date range of contract; 5) reseller name</li>
<li>SKU level pricing data: 1) product description; 2) quantity; 3) price paid</li>
<li>Schedule 70 average reseller data (10 resellers): 1) product description; 2) price</li>
</ul>
 </div>
      </div>
	 
	  
	  <hr />
	  <div class="row">
	   <div class="col-sm-4">
	   Reverse Auctions:
	   <ul class="list-unstyled">
<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q1.xlsx<">REVERSE_AUCTIONS_FY2014_Q1.xlsx</a></li> 
<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q2.xlsx">REVERSE_AUCTIONS_FY2014_Q2.xlsx</a> </li>
<li><a href="/system/files/resourcefiles/REVERSE_AUCTIONS_FY2014_Q3.xlsx">REVERSE_AUCTIONS_FY2014_Q3.xlsx</a></li>
</ul>
	   </div>
	   
	   <div class="col-sm-8">GSA Reverse Auction is a platform for buying non-complex commodities and simple services. GSA Reverse Auction is an eTool and can be used to facilitate the request for and submission of quotes, offers or proposals for products, services, and solutions through GSA Multiple Award Schedules (MAS) and Blanket Purchase agreements (BPAs).</div>
      </div>
	  
	  </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      
      </div>
    </div>
  </div>
</div>
<!--ITSW SERVICS - TRANSACTIONAL PLATFORMS MODAL-->

<!--CONTRIBUTE MODAL-->
<div class="modal fade" id="contribute" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header orange">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3 class="modal-title" id="myModalLabel"> Connect &amp; Contribute </h3>
      </div>
<div class="modal-body resources">
<div class="row">
<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Connect</h3>

<p>Join the conversation. Connect with peers in the <a href="https://interact.gsa.gov/group/acquisition-gateway">Interact</a> community.</p>
</div>
</div>

<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Want to contribute?</h3>

<p>Share your guides, templates, and tools with your community as a Acquisition Gateway "contributing member".  Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.</p>
</div>
</div>
</div>
</div>
      <div class="modal-footer">
        <button type="button" class="btn btn-sm btn-default" data-dismiss="modal">Close</button>
        
      </div>
    </div>
  </div>
</div>
<!-- /END MODALS GO HERE - currently incomplete in this version --> ',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['resources_itsoftware_content'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'small_package_modal';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Small Package Resource Content';
  $box->options = array(
    'body' => array(
      'value' => '
<!--SMALL PACKAGE -->
<div class="modal fade" id="pricesPaid" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog  modal-lg">
    <div class="modal-content">
      <div class="modal-header blue">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3>Historical Prices Paid Data</h3>
      </div>
	  
      <div class="modal-body resources">


    <div class="row">
     <div class="col-sm-4"><a href="/sites/default/files/article_files/TDS%20FY14%20Summary%20Report%20International%20%284%29.xlsx">DoD TDS FY14 Summary Report International</a>     </div>
     <div class="col-sm-8">
DoD TDS FY14 Summary Report International provides information on International Segment (formerly WWX) program usage, including volume, spend (including accessorial charges), and reliability by route by carrier and at the program level for fiscal year 2014.</a></div>
      </div>
    <hr />
    <div class="row">
     <div class="col-sm-4"><a href="/sites/default/files/article_files/DoD%20TDS%20FY14%20Summary%20Report%20Domestic.xlsx">DoD TDS FY14 Summary Report Domestic</a>     </div>
     <div class="col-sm-8"><span id="docs-internal-guid-2df543b2-785f-3b59-e89e-19b283baa4c5">DoD TDS FY14 Summary Report_Domestic provides information on Domestic Segment (formerly DOMEX) program usage, including volume, spend (including accessorial charges), and reliability by service level by carrier and at the program level for fiscal year 2014.</span></div>
      </div>
    <hr />
    
     <div class="row">
     <div class="col-sm-4">
     DoD DOMEX BPA Detail Reports:
     <ul class="list-unstyled">
<li><a  href="/sites/default/files/article_files/DOMEX_FEDEX_RATES.pdf">DOMEX_FEDEX_RATES.pdf</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2013_JANUARY_FEDEX_DETAIL_REPORT.xlsx">DOMEX_FY2013_JANUARY_FEDEX_DETAIL_REPORT.xlsx</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2013_FEBRUARY_FEDEX_DETAIL_REPORT.xlsx">DOMEX_FY2013_FEBRUARY_FEDEX_DETAIL_REPORT.xlsx</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2013_MARCH_FEDEX_DETAIL_REPORT.xlsx">DOMEX_FY2013_MARCH_FEDEX_DETAIL_REPORT.xlsx</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2014_JANUARY_FEDEX_DETAIL_REPORT.xlsx">DOMEX_FY2014_JANUARY_FEDEX_DETAIL_REPORT.xlsx</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2014_FEBRUARY_FEDEX_DETAIL_REPORT.xlsx">DOMEX_FY2014_FEBRUARY_FEDEX_DETAIL_REPORT.xlsx</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2014_MARCH_FEDEX_DETAIL_REPORT.xlsx">DOMEX_FY2014_MARCH_FEDEX_DETAIL_REPORT.xlsx</a></li> 
<li><a  href="/sites/default/files/article_files/DOMEX_FY2014_VOLREL_REPORT.xlsx">DOMEX_FY2014_VOLREL_REPORT.xlsx</a></li> 

</ul>
     </div>
     
     <div class="col-sm-8">The DOMEX BPA provides domestic express delivery services for the United States Department of Defense (DoD) and data sources include FedEx and UPS shipment sales from the Domestic Express Package Delivery Service (DOMEX) Blanket Purchase Agreement (BPA). Purchase data focuses on carrier, specific agency, content description, logistics, and variations in cost according to weight and time, etc.</div>
      </div>
    <hr />

	   <div class="row">
	   <div class="col-sm-4">
GSA Advantage:
<ul class="list-unstyled">
<li><a  href="/system/files/resourcefiles/Advantage_FY2014FYQ1.xlsx">Advantage_FY2014FYQ1.xlsx</a></li> 
<li><a  href="/system/files/resourcefiles/Advantage_FY2014FYQ2.xlsx">Advantage_FY2014FYQ2.xlsx</a> </li>
<li><a  href="/system/files/resourcefiles/Advantage_FY2014FYQ3.xlsx">Advantage_FY2014FYQ3.xlsx</a></li>
</ul>
</div>
	   <div class="col-sm-8">These are GSA Advantage data sets that have purchases of commercial products and services from FSS Schedule contracts and GSA GWACs. The following categories are included: building & industrial; furniture & furnishings; cleaning & chemicals; IT solutions & electronics; laboratory, cleaning, medical; law enforcement, fire, security; office solutions; recreational & apparel; services; tools, hardware, machinery; vehicles, watercraft. The data is published quarterly. You can visit GSA Advantage! <a href="https://www.gsaadvantage.gov/advantage/main/start_page.do" target="new">here</a>. </div>
      </div>
	  <hr />

     <div class="row">
     <div class="col-sm-4">GSA DDS3 Agency Spend Reports:
     <ul class="list-unstyled">
<li><a  href="/sites/default/files/article_files/Agency%20July%20Report14.pdf">July 2014 Agency Spend Report</a></li> 
<li><a  href="/sites/default/files/article_files/Agency%20August%20Report.pdf/resource-files/">August 2014 Agency Spend Report</a> </li>
<li><a  href="/sites/default/files/article_files/September%20Agency%20Report.pdf">September 2014 Agency Spend Report</a></li>
</ul></div>
     <div class="col-sm-8">Find monthly summary level information on agency spend by service type through the DDS3 program. For more in-depth information about your agency, GSA has created the FSSI/DDS3 Dashboard (see above). </div>
      </div>
    <hr />
            
     <div class="row">
     <div class="col-sm-4"><a href="https://fssiddsreports.fas.gsa.gov/fssi/login.jsf" target="new">GSA DDS3 Dashboard</a>     </div>
     <div class="col-sm-8">
GSA has created the FSSI/DDS3 Dashboard to help you track your agency\'s annual spend and savings, to gain access to the FSSI/DDS3 Dashboard portal, please email Stevie Graham at <a href="mailto:fssi.domesticdeliveryservices@gsa.gov">fssi.domesticdeliveryservices@gsa.gov.</a></div>
      </div>
    <hr />

	   <div class="row">
	   <div class="col-sm-4">
	   GSA Federal Supply System (FSS-19):
	   <ul class="list-unstyled">
<li><a href="/system/files/resourcefiles/FSS19_FY2014_FYQ1.xlsx">FSS19_FY2014_FYQ1.xlsx</a></li> 
<li><a href="/system/files/resourcefiles/FSS19_FY2014_FYQ2.xlsx">FSS19_FY2014_FYQ2.xlsx</a> </li>
<li><a href="/system/files/resourcefiles/FSS19_FY2014_FYQ3.xlsx">FSS19_FY2014_FYQ3.xlsx</a></li>
</ul>
</div>
	   <div class="col-sm-8">These are data sets pulled from the FSS-19 system, a contract system for procurement and distribution of supplies.  The data includes transactions and pricing of the GSA supply and schedule contracts. Specific details on stored stock orders, the Special Orders Program, expanded direct delivery, and schedule orders sales from the GSA Federal Supply System are of note. The data is updated on a quarterly basis.</div>
      </div>

	  </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      
      </div>
    </div>
  </div>
</div>

<!--CONTRIBUTE MODAL-->

<div class="modal fade" id="contribute">
<div class="modal-dialog modal-lg">
<div class="modal-content">
<div class="modal-header orange"><button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">×</span><span class="sr-only">Close</span></button>
<h3>Connect &amp; Contribute</h3>
</div>

<div class="modal-body resources">
<div class="row">
<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Connect</h3>

<p>Join the conversation. Connect with peers in the <a href="https://interact.gsa.gov/group/acquisition-gateway">Interact</a> community.</p>
</div>
</div>

<div class="col-xs-12 col-sm-6">
<div class="panel-body">
<h3>Want to contribute?</h3>

<p>Share your guides, templates, and tools with your community as a Acquisition Gateway "contributing member".  Email us at <a href="mailto:hallways_contribute@gsa.gov">hallways_contribute@gsa.gov</a>.</p>
</div>
</div>
</div>
</div>

<div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div>
</div>
</div>
</div>
<!-- /END MODALS GO HERE -->',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['small_package_modal'] = $box;

  return $export;
}
