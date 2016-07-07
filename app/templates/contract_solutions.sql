INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("AbilityOne",
                  1,
                  "The AbilityOne Program is a Federal initiative to help people who are blind or have other significant disabilities find employment by working within a national network of over 600 Nonprofit Agencies that sell products and services to the U.S. government. The Committee for Purchase From People Who Are Blind or Severely Disabled is the Federal agency authorized to administer the AbilityOne Program.",
                  5,
                  "Varies (embedded in catalog price)",
                  "Products Offered:
Aircraft, Vehicular and Electrical Equipment and Supplies
Clothing, Textiles and Individual Equipment
Food Processing, Packaging and Distribution
Office Supplies and Furnishings
Services Offered:
Administrative
Contact Centers
Contract Management Support (CMS) Services
Custodial
Document Management
Fleet Management
Food Services
Grounds Maintenance
Healthcare Environmental
Laundry
Secure Document Destruction
Secure Mail/Digital Document
Supply Chain Management and Warehouse
Total Facilities Management",
                  "https://www.abilityone.com/OA_HTML/xxnib_ibeCCtpSctDspRte.jsp?section=11703&sitex=10040:22372:US&NIBPROD=MWNoOkBJvWonWZjCyAUbrsTSwJ&NIBPROD_pses=ZG9F6A98EC56DD747701106A0D582C080E50DD7B8B0C230D231DC26AA9FB428A5526EC56ECCB53F3C7FA0DED57087515CAF44799F5524C3038",
                  "Varies",
                  "customerservice@abilityone.org
(800) 999-5963",
                  "Varies");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),16);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Adobe BPA",
                  2,
                  "",
                  33,
                  "None",
                  "This vehicle provides pre-negotiated, discounted pricing for the full suite of Adobe software and maintenance and enables Components to access ancillary training and consulting services.",
                  "N/A",
                  "7/1/2018",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Air Force Tool and Parts Program (AFTAPP)",
                  3,
                  "Air Force Tools and Parts Program (AFTAPP) Five (5) pre-competed BPAs awarded by the Air Force Civil Engineering Commodity Council for use in supplying Maintenance, Repair, and Operations (MRO) tools and parts for the DoD community. Products have no minimum purchase/delivery limit and may be micropurchased via the GPC or quotes sought using eBuy RFQs. ",
                  5,
                  "Varies (embedded in catalog price)",
                  "Products available on GSA Schedules 51V and 56, such as Hardware, Hand Tools, Electrical Supplies, HVAC Parts and Filters, Adhesives and Sealants, Containers and Storage, Rope, Chain, Cable, and Wire, Grinding and Polishing Materials, Industrial Pumps, Compressors, Gaskets and Seals, Plumbing Fixtures, Workshop Supplies, Fluid and Gas Distribution, Industrial Filtering, Lubricants, Oils, and Grease, Paint, Primers, and Finishes, and more.",
                  "https://www.afadvantage.gov/advantage/main/start_page.do?store=AIRFORCE",
                  "Varies by vendor contract.",
                  "ESG.AFTAPP@wpafb.af.mil",
                  "None");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Army CECOM Strategic Services Sourcing S3",
                  4,
                  "",
                  5,
                  "None",
                  "Logistics services
Engineering services
Business operations support services",
                  "http://www.army.mil/info/organization/cecom/",
                  "3/6/2016",
                  "Robert DiMichele, Chief Public Affairs& Communications Media
US. Army Communications-Electronics Command
robert.e.dimichele.civ@mail.mil, ARMY
443-861-6757 

Cynthia Jackson, CECOM Competition Advocate 443 861 5256
cynthia.a.jackson64.civ@mail.mil

Patrick Morse, (732) 532-8381",
                  "$3,000 for Supplies
$2,500 for Services
$2,000 for Construction 
");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Army First - Field and Installation Readiness Support Team (FIRST)",
                  4,
                  "FIRST is an Enterprise Solution to provide innovative and responsive logistics support to meet the evolving mission needs of the war fighter. The Scope of Work provides Task Areas that define functional and programmatic services that may be required by Headquarters Army Material Command (AMC); Headquarters, Forces Command (HQ FORSCOM); Headquarters Installation Management Command (IMCOM) (Logistics); Headquarters, U.S. Army Reserve Command (HQ USARC); Headquarters, Third Army U.S. Army Central Command (ARCENT), Headquarters, U.S. First Army, and all other Army or Department of Defense (DOD) Agencies, authorized to place orders against FIRST contracts. Services may be required in Continental United States (CONUS) or outside the Continental United States (OCONUS) locations. Specific requirements and standards of performance will be provided in each task order. FIRST was solicited and awarded as a result of two separate solicitations: one that was a Total set-aside for small business and the other as a full and open competition.",
                  5,
                  "None",
                  "Logistics Program Management and Operations
Logistics Quality Assurance Support 
Logistics Information/Technology Support 
Logistics Training Support
Logistics Army Transformation Logistics Support
Logistics Program Support
Logistics Transportation/Supply Support 
Logistics Parts Support
(S) Logistics/Maintenance
(U) Logistics/Maintenance 
Comprehensive Support for Centrally Managed Programs
Command Wide Logistics Enterprise System Support",
                  "http://www.bragg.army.mil/units/micc/Pages/FIRST.aspx",
                  "7/6/2026",
                  "Ronnell Booker, PCO
404-464-2063 / DSN 367-2063
ronnell.booker@us.army.mil

Karen D. Thomas, Admin
404-464-1708 / DSN 367-1708
karen.d.thomas@us.army.mil",
                  "$100,000");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Army Logistics Civil Augmentation Program (LOGCAP IV)",
                  4,
                  "",
                  5,
                  "None",
                  "Deliberate planning
Preparation of the Worldwide Management and Staffing Plan (WMSP)
Contingency event support, training and exercise participation
Technical support including cost analysis and pre-award task order proposal review",
                  "http://www.aschq.army.mil/home/default.aspx",
                  "6/24/20117",
                  "Brandon Kettler, kettlerb@afsc.army.mil, 782-6420
Executive Director (309) 782 0929
Deputy Executive Director (309) 782-7853
Director, Policy & Programs (309) 782-8552
Director, Operations & Plans (309) 782-8415
Director, Quality Assurance (309) 782-0688",
                  "$613,677");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("CHESS: Computer Hardware Enterprise Software & Solutions",
                  4,
                  "The Primary Source to support the Warfighter's information dominance objectives by developing, implementing and managing commercial Information Technology contracts that provide enterprise-wide net-centric hardware, software and support services for the Army.",
                  5,
                  "None",
                  "Information Technology Enterprise Solutions (ITES-2H) - provides IT hardware solutions and services. Army Desktop and Mobile Computing (ADMC-2) - utilized for consolidated hardware commodity buys. Multifunctional Devices (MFD) - includes devices with printing, scanning, copying and/or faxing capabilities.",
                  "https://chess.army.mil/Account/LogOn?returnUrl=https://chess.army.mil/RFQ",
                  "ADMC-2 4/23/2016 ITES-2H 6/23/2015 MFD 10/31/2016",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Client, Computing & Servers",
                  3,
                  "",
                  9,
                  "GSA Fee is rolled into item costs",
                  "Product based with incidental services",
                  "https://www.afway.af.mil/",
                  "6/30/2015",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Commodity Enterprise Contract",
                  5,
                  "",
                  94,
                  "None",
                  "CEC ensures standardization and interoperability of commercial information technology (IT) hardware and associated installation, configuration, warranty, maintenance, and technical support services solutions across the VA Enterprise. Further, VA seeks to take advantage of technological advances and new business practices that promise to increase productivity and/or reduce costs. The IT hardware commodities available under CEC are as follows: end user devices (e.g., laptops and thin clients), mobile tablets, servers, networking appliances (i.e., switches and routers), storage arrays/storage appliances, and security platforms. Additionally, the following types of services are also available: installation, warranty support, and incidental technical support services such as site surveys, custom installation, training, and application support.",
                  "Contact TAC",
                  "3/1/2018",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Connections II",
                  6,
                  "Connections II provides telecommunications in a building or campus, while GWACs provide a broad spectrum of IT solutions",
                  5,
                  "1.5% Associated Government Fee (AGF) capped at $150K per year per order (applies to orders in excess of $10M per year)",
                  "Network and telecom equipment, labor, building, and campus infrastructure solution needs, including: Infrastructure design, installation, and implementation; Professional services to support existing networks; Professional services to support existing networks; Transition planning and integration services; Customized client-specific systems",
                  "http://www.gsa.gov/portal/content/113287",
                  "Base Period 1/19/2015 Option Periods Six 1-year option periods",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Continuous Diagnostics and Mitigation (CDM)",
                  6,
                  "The CDM Program helps transform the way federal and other government entities manage their cyber networks through strategically sourced tools and services, and enhances the ability of government entities to strengthen the posture of their cyber networks. The CDM Program brings an enterprise approach to continuous diagnostics, and allows consistent application of best practices.",
                  5,
                  "None",
                  "The CDM BPA provides government programs with specialized information technology (IT) tools and continuous monitoring services (CMaaS) to enhance cyber-security efforts. The CDM BPA includes 15 Tool Functional Areas and 11 Service Task Areas.",
                  "http://www.gsa.gov/portal/content/176671",
                  "8/11/2018",
                  "cdm@gsa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Defense Logistics Agency (DLA) - Document Services",
                  7,
                  "DLA Document Services' mission is to transform the Department of Defense (DoD) from high volume printing to on-demand documents and on-line, electronic content and records management.",
                  5,
                  "Varies (embedded in catalog price)",
                  "Printing, Design Services, Electronic Document Management, and Equipment Management Solutions",
                  "http://www.documentservices.dla.mil/",
                  "Varies by vendor contract.",
                  "DLA Print Solutions Help877-DAPS-CAN
custinfo.docsvcs@dla.mil",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Department of Navy: Enterprise Software Licensing (ESL)",
                  8,
                  "The Department of the Navy is establishing Enterprise Licensing Agreements (ELAs) with IT hardware and software vendors to achieve cost savings, improve management, streamline procurement and enhance security. ",
                  5,
                  "2% Acquisition, Contracting and Technical (ACT) Fee",
                  "IT Software and in some cases may include software related services and hardware components",
                  "https://www.peoeis.portal.navy.mil/pmm110/default.aspx NOTE: Updated link not yet available.",
                  "Varies by contract vehicle. See Terms & Conditions.",
                  "Oracle - Steve Cabrian@usmc.mil, Axway - Ross.Orvik@navy.mil, Microsoft - Patricia.Lyons@usmc.mil, Symantec - Lynda.Potters@navy.mil, ActivIdentity - Robert.Franco@navy.mil",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),17);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Department of Navy: Furniture BPA",
                  8,
                  "The DON Furniture BPAs have achieved an initial discount at the BPA level and will allow the Department to reduce use of redundant vehicles. These BPAs were competitively awarded against Federal Supply Schedules and to the Federal Prison Industries d/b/a UNICOR for office, dorm and quarters, child development, and industrial and institutional furniture as part of Spiral II of the Navy's Strategic Sourcing Initiative for Furniture.",
                  5,
                  "0.75% fee (included in catalog prices)",
                  "Office, dorm and quarters, child development, and industrial and institutional furniture.",
                  "http://www.secnav.navy.mil/rda/OneSource/Pages/Strategic%20Sourcing/DON-Furniture-Acquisition.aspx",
                  "Varies by vendor contract.",
                  "Navy Furniture Program POC 757-443-1319
flcn.furniture@navy.mil",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("DHS ELAs for Specific Publishers",
                  2,
                  "",
                  33,
                  "Internal Acquisition, Contracting and Technical (ACT) fee",
                  "Software: Adobe, ESRI, Microsoft, Oracle (single-award, brand-name justified), F5 Networks, IBM, McAfee, NetApp, Quantum, Symantec, VMWare (multiple-award, based upon technical capability)",
                  "N/A",
                  "N/A",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),17);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("DHS First Source II",
                  2,
                  "FirstSource II provides the Department with access to a full array of value-added reseller services and access to a wide and renewable variety of IT commodities and solutions (hardware and software) from multiple Original Equipment Manufacturers (OEMs).",
                  33,
                  "None",
                  "Includes, but not limited to: Networking equipment; Wireless technology; Imaging products; Voice recognition technology; On-line data reporting services for order, delivery, warranty, asset, and spend tracking; and all associated product maintenance, installation, and support",
                  "http://www.dhs.gov/firstsource-ii",
                  "Varies by contract vehicle. See Terms & Conditions.",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Digital Printing & Imaging (DPI)",
                  3,
                  "",
                  9,
                  "GSA Fee is rolled into item costs",
                  "Product based with incidental services",
                  "https://www.afway.af.mil/",
                  "4/10/2019",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("DISA Encore II",
                  9,
                  "The objective of the Encore II contract is to provide global net-centric capabilities, attributes or services under multiple award, Indefinite-Delivery/Indefinite-Quantity (ID/IQ) task order type contracts that support the military services, the DoD and other Federal agencies. DISA actively facilitates the migration of information systems and common, standard data into an integrated and interoperable GIG that supports the Department‰Ûªs Joint Vision 2020 (JV2020) concept.",
                  5,
                  "2.0% processing fee; Additional 1.0% when using a local contracting office",
                  "20 Task areas including: Enterprise IT Policy & Planning, Integrated Solutions Management, Performance Benchmarking, Business Process Reengineering (BPR), Requirements Analysis, Market Research & Prototyping, Information and Knowledge Engineering, Customer Application Development, Product Integration, Test & Evaluation, Asset Management, Communications Engineering, Security Engineering C&A, Telecommunications Support, Computer Telephony Integration, Web Services, Operations Support, Hardware, Software, Managed services",
                  "http://www.dsaencore2.com/index.html",
                  "Five year base period starting 4/24/2008, with five 1-year options",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("DoD EMALL",
                  7,
                  "",
                  5,
                  "Varies (embedded in catalog price)",
                  "DoD EMALL provides everything from office supplies to aircraft parts. NSNs can be purchased using government purchase card or MILSTRIP Requisition from dedicated DLA Customer Service at 1-877-352-2255 or DSN 661-7766 or via the EMALL website.",
                  "https://dod.emall.dla.mil/acct/",
                  "Varies by vendor contract.",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),9);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("DoD Enterprise Software Initiative (ESI)",
                  9,
                  "",
                  5,
                  "2% Acquisition, Contracting and Technical (ACT) fee built into pricing",
                  "Commercial Off-the-Shelf Information Technology Agreements, Assets and policies for the purpose of lowering total cost of ownership across the DoD, Coast Guard, Intelligence Community and Federal buyers",
                  "http://www.esi.mil/Default.aspx",
                  "Varies by contract vehicle. See Terms & Conditions.",
                  "Ask a Product Manager http://www.esi.mil/askSPM.aspx Mr. Bob Smith robert.j.smith84@mail.mil",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("DoD ESI SEAMLS",
                  3,
                  "",
                  5,
                  "2% Acquisition, Contracting and Technical (ACT) Fee",
                  "Primary Air Force Point of Contact for Adobe X Pro, Microsoft, and Oracle software license agreemnents. See www.esi.mil for ELAs available to the USAF",
                  "http://www.esi.mil/Default.aspx",
                  "Varies by contract vehicle. See Terms & Conditions.",
                  "Ask a Product Manager http://www.esi.mil/askSPM.aspx",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),17);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Domestic Delivery Service (DDS)",
                  6,
                  "The third generation Domestic Delivery Service (DDS3) has awarded a new best value Blanket Purchase Agreement to UPS and FedEx and provides domestic delivery services for both air and ground shipments between the Continental U.S. and Alaska, Hawaii, and Puerto Rico. DDS3 continues to provide agencies with data around usage patterns in order to give customers the visibility they need to reduce shipping costs and improve business practices in managing shipments.",
                  ,
                  "2% Industrial Funding Fee from vendors",
                  "DDS3 provides domestic time- and day-definite delivery services for both air and ground shipments of extremely Urgent Letters, Small Packages and Heavyweight items,  including available accessorial services between the Continental U.S. and Alaska, Hawaii, and Puerto Rico . Service Categories include: Express Next Day, Express Second Day, Express Third Day, Ground and Other Delivery.",
                  "http://www.gsa.gov/portal/content/105105",
                  "9/30/2017",
                  "Senior Program Executive: Ronnie Palmer,(703) 605 5661, ronnie.palmer@gsa.gov 
Program Manager: Stevie Graham  fssi.domesticdeliveryservices@gsa.gov",
                  "None");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1/3/2015);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Encore II",
                  9,
                  "The Encore II contract provides technical solutions for the Department of Defense (DoD) in support of its migration to an integrated and interoperable Global Information Grid (GIG), as well as other Federal agencies having similar Information Technology (IT) migration and integration needs.",
                  5,
                  "",
                  "",
                  "http://www.dsaencore2.com/Contract/External%20Ordering.html",
                  "",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Enterprise PRISM Instance (EPI) Perpetual Licenses and Maintenance BPA",
                  2,
                  "",
                  33,
                  "None",
                  "This single-award BPA provides PRISM Perpetual Software Licenses, associated Perpetual License Maintenance, and other PRISM related Software Modules and associated Maintenance in support of DHS‰Ûªs Enterprise PRISM Instance (EPI).",
                  "N/A",
                  "9/17/2019",
                  "Sharon.aiken@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Dept of Navy - Enterprise Software Licensing (ESL)",
                  8,
                  "",
                  79,
                  "",
                  "",
                  "http://www.esi.mil/Default.aspx",
                  "",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Enterprise Software Solutions BPAs - Application Infrastructure",
                  2,
                  "",
                  33,
                  "None",
                  "The agreement provides software licenses, software maintenance, training and consulting services.",
                  "N/A",
                  "9/22/2018",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Enterprise Software Solutions BPAs - Backup and Storage",
                  2,
                  "",
                  33,
                  "None",
                  "The agreement provides software licenses, software maintenance, training and consulting services.",
                  "N/A",
                  "9/22/2018",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Enterprise Software Solutions BPAs - Security",
                  2,
                  "",
                  33,
                  "None",
                  "The agreement provides software licenses, software maintenance, training and consulting services.",
                  "N/A",
                  "9/22/2018",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Enterprise Talent Management System (ETMS)",
                  2,
                  "",
                  33,
                  "None",
                  "Software as a Service (SaaS) available under this BPA includes but is not limited to a vendor hosted solution including user access, configuration, data migration, training, change management, program management, and IT professional services to support the capabilities (as needed).",
                  "N/A",
                  "5/27/2018",
                  "LaTanya.Taylor@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("ESRI Enterprise Agreement BPA",
                  2,
                  "",
                  33,
                  "None",
                  "Provides the DHS with continued maintenance of the capped number of ESRI GIS desktop software licenses along with unlimited maintenance of desktop extensions maintained for those licenses, unlimited Server licenses, and associated tiered technical support for all the licenses.",
                  "N/A",
                  "9/29/2016",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Federal Acquisition Institute (FAI) Commercial Off-The-Shelf (COTS)",
                  6,
                  "Courses for Federal Acquisition Certification for Contracting Officer‰Ûªs Representatives (FAC-COR) and for Project and Program Managers (FAC-P/PM)",
                  5,
                  "None",
                  "Courses for Federal Acquisition Certification for Contracting Officer‰Ûªs Representatives (FAC-COR) and for Project and Program Managers (FAC-P/PM)",
                  "To use FAI's IDIQ, your contracting officer must obtain a Delegation of Procurement Authority from the PCO.  To obtain information about a delegation, please contact Ernesto.Martinez@gsa.gov",
                  "2018",
                  "Please contact Ernesto.Martinez@gsa.gov for the terms and conditions of this MAC",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("First Source II",
                  2,
                  "",
                  5,
                  "None",
                  "The FirstSource II contracts offer a total array of IT commodity products including, but not limited to hardware, software, peripherals, networking, and infrastructure support services across an array of commodity and service categories, including: Small Form Factor Devices, Static Devices, Domain Devices, Virtual Desktop Infrastructure (VDI) Devices (desktop virtualization), and Peripheral Devices.",
                  "N/A",
                  "1/7/2018",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("FSSI OS3 Acquisition Channel",
                  6,
                  "GSA has awarded multiple Indefinite Delivery-Indefinite Quantity (IDIQ) contracts for office supply products and commodities through the purchasing channel acquisition. Twenty-three of the twenty-four awards have gone to small business entities.",
                  5,
                  "2% fee (included in catalog prices)",
                  "Office Paper; Toner and Inkjet Cartridges; General Office Supplies Capturing economies of scale; Ensuring compliance with applicable regulations to include the AbilityOne Program, sustainable purchasing requirements and the Trade Agreements Act; Fostering markets for sustainable technologies and environmentally preferable products; Simplifying data collection and enhancing transparency by enabling agencies to better manage expenditures and measure cost-savings; Aligning purchasing with existing agency procurement practices; Enabling achievement of socioeconomic goals; Providing ease of ordering; and Providing point of sale compliance, ensuring that purchase card users automatically receive the FSSI price.",
                  "https://www.gsaadvantage.gov/advantage/department/main.do?cat=ADV.FSSI",
                  "Varies by vendor contract.",
                  "Robert Woodside
fssi.officesupplies@gsa.gov
(212) 264-2693",
                  "$25, $50 or $100 depending on vendor");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("FSSI Print Management Functional Area 1 Conduct Fleet Assessment",
                  6,
                  "FSSI Print Management is a holistic commodity management approach that allows federal agencies to achieve cost and environmental savings through the implementation of a behavior change management program, and improvements to the acquisition of print and copy devices and services.",
                  5,
                  "2% (0.75% Schedule fee and 1.25% program fee included in pricing)",
                  "Device (i.e. copier, printer) discovery, data collection, spend analysis, baseline identification, cost reduction plans and optimization",
                  "http://www.gsa.gov/portal/content/203331",
                  "Varies by vendor contract.",
                  "National Customer Service Center
(800) 488-3111
mashelpdesk@gsa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("FSSI Print ManagementFunctional Area 2 Device Plus",
                  6,
                  "FSSI Print Management is a holistic commodity management approach that allows federal agencies to achieve cost and environmental savings through the implementation of a behavior change management program, and improvements to the acquisition of print and copy devices and services.",
                  5,
                  "2% (0.75% Schedule fee and 1.25% program fee included in pricing)",
                  "Document imaging solutions complete with devices, maintenance and repairs, consumables (excluding paper) and usage reporting, including energy usage.",
                  "http://www.gsa.gov/portal/content/203331",
                  "Varies by vendor contract.",
                  "National Customer Service Center
(800) 488-3111
mashelpdesk@gsa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("GPO Online Paper Store",
                  10,
                  "",
                  5,
                  "",
                  "A variety of paper options and products Green options for federal consumers looking to follow federal guidelines and sustainable requirements, 24 hour or next-day delivery in major U.S. cities and 48-hour delivery for other locations across the continental U.S., 24/7 online ordering with the GPO Online Paper Store Web site, Dedicated Customer Service Center at 866.805.9498, Competitive pricing, Payment by Credit Card, IPAC, or Deposit Account",
                  "https://gpo.unisourcelink.com/login.html",
                  "Varies by vendor contract.",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("GPOExpress",
                  10,
                  "GPO program offers access to deeply discounted copying, binding, signs, and more from over 1,800 FedEx OfficeSM locations nationwide.",
                  5,
                  "Varies (embedded in catalog price)",
                  "Scanning and Archiving of documents, direct mail services, on-site document solutions.",
                  "http://www.gpo.gov/customers/express.htm",
                  "Varies by vendor contract.",
                  "GPOExpress Program Manager, 202.512.2159, GPOExpress@gpo.gov",
                  "Varies");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("GSA 4th Party Logistics (4PL)",
                  6,
                  "The 4PL program is targeted at segments of the federal supply market requiring full supply chain support. GSA provides customized solutions to client organizations involving multiple methods of fulfillment (brick and mortar stores, customized web storefronts, multiple/parallel commercial supplier contracts, etc.).",
                  5,
                  "Varies (embedded in catalog price)",
                  "Computer Products, Office Supplies, Furniture and Furnishings, Housewares and Cleaning, Industrial Supplies, Safety, Tools and Hardware, Wildland Fire items, Green items, Disaster Relief
",
                  "https://www.usmcservmart.gsa.gov/advantage/main/start_page.do?store=USMC",
                  "Varies by vendor contract.",
                  "866-370-8894, USMCServMart@gsa.gov",
                  "Varies");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("GSA CIO specific ELAs",
                  6,
                  "",
                  3,
                  "None",
                  "Adobe Connect, Agile Quest, BIT 9 (security agent), Fiberling MaaS360, Google, Mandiant (security agent), McAfee, Microsoft Windows & Servers (covers server operating systems and other server-based software like Project, Sharepoint, etc. Also covers Windows clients. Separate contract in place which covers Office for clients), Salesforce, Service Now",
                  "N/A",
                  "N/A",
                  "Mr. Brian Muolo brian.muolo@gsa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("GSA Global Supply",
                  6,
                  "GSA Global Supply provides federal users, military or civilian, worldwide access to common-use items like office products, tools and cleaning supplies. Users can requisition items and pay with a government purchase card or through direct billing via an Activity Address Code (AAC/DoDAAC)",
                  5,
                  "Varies (embedded in catalog price)",
                  "Computer Products, Office Supplies, Furniture and Furnishings, Housewares and Cleaning, Industrial Supplies, Safety, Tools and Hardware, Wildland Fire items, Green items, Disaster Relief
",
                  "www.gsaglobalsupply.gsa.gov",
                  "Varies by vendor contract.",
                  "1-800-525-8027, GSAglobalsupply@gsa.gov",
                  "Varies");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),9);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("JanSan FSSI",
                  6,
                  "GSA has established 18 blanket purchase agreements for a new strategic sourcing solution designed to help federal agencies purchase Janitorial and Sanitation (JanSan) supplies at discounted prices.",
                  5,
                  "Varies (embedded in catalog price)",
                  "Cleaning Compounds and Related Dispensers;
Non-Motorized Cleaning Equipment and Trash Receptacles;
Paper Products and Related Dispensers; and 
Motorized Floor Cleaning Equipment and Accessories. ",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "GSA National Customer Service Center (800) 488-3111, fssi.jansan@gsa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Maintenance, Repair & Operations (MRO) FSSI",
                  6,
                  "GSA has established blanket purchase agreements with 10 contractors to sell products under the Maintenance, Repair & Operations (MRO) strategic sourcing solution.",
                  5,
                  "Varies (embedded in catalog price)",
                  "Hardware; Tools and Tool Cabinets; and Paints, Adhesives and Sealants.",
                  "https://www.gsaadvantage.gov/advantage/main/start_page.do",
                  "Varies by vendor contract.",
                  "National Customer Service Center (800) 488-3111, FSSI.MRO@gsa.gov",
                  "Varies by vendor contract.");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Microsoft Enterprise License Agreement BPA",
                  2,
                  "",
                  33,
                  "None",
                  "The ELA provides immediate licensing for DHS Components over the term of the agreement and the option to purchase any of Microsoft‰Ûªs suite of products and associated software assurance (maintenance agreements).",
                  "N/A",
                  "6/26/2015",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("National IT Commodity Program",
                  6,
                  "Federal agencies can buy IT commodities such as laptops, servers, and integrated support services faster and at lower prices through GSA. Users may save 15-37% when using the IT Commodity Buy BPA (compared to ordering off multiple award schedules).",
                  5,
                  "0.75% (built into catalog prices)",
                  "Mobile Solutions: Computer Monitors, Tablets, Laptops, Desktops, Notebooks, Video Teleconference Equipment",
                  "Direct Solicitation, Reverse Auctions, eBuy, or Assisted Acquisition via ITSS",
                  "Ends in 2015",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Navy Seaport-E",
                  8,
                  "SeaPort-e is the Navy's electronic platform for acquiring support services in 22 functional areas including Engineering, Financial Management, and Program Management.",
                  5,
                  "None",
                  "SeaPort-e is the Navy's electronic platform for acquiring support services in 22 functional areas including Engineering, Financial Management, and Program Management.",
                  "http://www.seaport.navy.mil/default.aspx",
                  "Varies by vendor contract
5 year base + 2 5 year options",
                  "General Inbox:  seaport_pm@navy.mil
Naval Sea Systems Command
Attn: SEA 02651
1333 Isaac Hull Avenue SE Stop 2040
Washington Navy Yard DC 20376-2040

Seaport_ombudsman@navy.mil
Naval Sea Systems Command
Attn: SEA 021
1333 Isaac Hull Avenue SE Stop 2060
Washington Navy Yard DC 20376-2060",
                  "$2,501");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("NETCENTS-2",
                  3,
                  "",
                  9,
                  "None",
                  "COTS Hardware - Network equipment - Servers/Storage - Peripherals/Multimedia - Software (shrink wrapped) - Identify Managment/Biometric hardwware & ancillary SW, delivery, warranty, maintenace",
                  "http://www.netcents.af.mil/",
                  "6 Nov 15 (Ordering period ends)",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),5);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("NITAAC CIO-CS",
                  11,
                  "",
                  5,
                  "0.50%",
                  "",
                  "https://nitaac.nih.gov/nitaac/contracts/cio-cs",
                  "Ten years after date of award",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),5);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("NITAAC CIO-SP3 Small Business",
                  11,
                  "IT services and solutions including: Capital Planning and Investment, Cloud Computing, Cybersecurity, Health and Biomedical IT, Enterprise Data Management, ERP IT Infrastructure, Identity and Access Management, Mobility Solutions, Software Development, Systems Engineering, and Workforce Management   ",
                  5,
                  "1% (capped at $150k applicable to > $15M for any task order base or optional period (not to exceed 12 months) or:
0.75% (capped at $150k applicable to > $20M for any task order base or optional period (not to exceed 12 months) ",
                  "Anything and everything IT products and solutions. IT commodities and solutions as they apply to supporting the general fields of IT operation (security, infrastructure, telecommunications, and desktop applications)",
                  "https://ecsiii.od.nih.gov/",
                  "Ten year ordering period expires in 2022",
                  "NITAAC Customer Support Center at NITAACsupport@nih.gov or 1.888.773.6542",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),5);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("NITAAC ECS III",
                  11,
                  "6 lots including hardware, software, networking and telecommunications equipment, scientific research stations, warranties and maintenance service",
                  5,
                  "0.50% (capped at $10K per delivery order, modification, or exercise of option)",
                  "Covers 6 lots including hardware, software, networking and telecommunications equipment, scientific research stations, warranties and maintenance service and more",
                  "https://ecsiii.od.nih.gov/",
                  "5/9/2015",
                  "NITAAC Customer Support Center at NITAACsupport@nih.gov or 1.888.773.6542",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),5);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("One Acquisition Source for Integrated Solutions (OASIS)",
                  6,
                  "OASIS and OASIS Small Business (SB) are multiple award, Indefinite Delivery Indefinite Quantity (IDIQ) contracts that provide flexible and innovative solutions for complex professional services.",
                  5,
                  "0.10% - 0.75% based on obligation level.",
                  "Program management services, 
Management consulting services, 
Logistics services, 
Engineering services, 
Scientific services, 
Financial services.

These services:
Span many areas of expertise and mission spaces; 
Span multiple professional service disciplines;
Allow flexibility for all contract types, including hybrids and cost-reimbursement, at the task order level; and
Allow ancillary support components, commonly referred to as Other Direct Costs (ODC), at the task order level.",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME; Todd Richards; todd.richards@gsa.gov; 817-850-8382: SME; Valerie Bindel; valerie.bindel@gsa.gov; (817) 850-8375: Pre-Award SME; Tommy Thomas; tommy.thomas@gsa.gov;(817) 978-4656: Business Manager; Tariq Choudry; tariq.choudry@gsa.gov; (703) 603-8137: Business Manager; Debra Drake; debra.drake@gsa.gov; (703) 605-5459: Business Manager; Karla Qawar; karla.qawar@gsa.gov; (703) 605-0553",
                  "$150,000");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("One Acquisition Source for Integrated Solutions for Small Business (OASIS SB)",
                  6,
                  "OASIS and OASIS Small Business (SB) are multiple award, Indefinite Delivery Indefinite Quantity (IDIQ) contracts that provide flexible and innovative solutions for complex professional services.",
                  5,
                  "0.10% - 0.75% based on obligation level.",
                  "program management services, 
management consulting services, 
logistics services, 
engineering services, 
scientific services, 
financial services.

These services:
Span many areas of expertise and mission spaces; 
Span multiple professional service disciplines;
Allow flexibility for all contract types, including hybrids and cost-reimbursement, at the task order level; and
Allow ancillary support components, commonly referred to as Other Direct Costs (ODC), at the task order level.",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME; Valerie Bindel; valerie.bindel@gsa.gov; (817) 850-8375: Business Manager; Tariq Choudry; tariq.choudry@gsa.gov; (703) 603-8137: Business Manager; Debra Drake; debra.drake@gsa.gov; (703) 605-5459: Business Manager; Karla Qawar; karla.qawar@gsa.gov; (703) 605-0553",
                  "$150,000");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Oracle BPA",
                  2,
                  "",
                  33,
                  "None",
                  "Oracle products, maintenance and services.",
                  "N/A",
                  "9/24/2018",
                  "Jaclyn.Smyth@hq.dhs.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("OS3: Office Supplies FSSI",
                  6,
                  "",
                  5,
                  "",
                  "",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("PC Refresh - VA only",
                  5,
                  "",
                  94,
                  "None",
                  "The scope of this contract is to purchase a maximum of 600,000 PCs to cover the entire enterprise. These systems will be used across the agency to provide a standard operating environment for office automation, communications, access to departmental servers/hosts, and other IT applications. VA requires support and services associated with these workstations to accommodate gaps in internal capabilities. VA will operate these workstations in a 24x7 mission critical environment and requires maintenance commensurate with that operation. VA requires flexibility in use of these workstations, including quantities, configurations, operating locations, and lifecycle. The scope of this contract includes acquisition, operation, customization, maintenance, and deinstallation of the equipment identified. VA desires a steady delivery stream over the course of the ordering/delivery period of the contract.",
                  "Contact TAC",
                  "4/30/2015",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Performance Management / Continuous Process Improvement (PM/CPI) Blanket Purchase Agreement",
                  6,
                  "The PM/CPI Blanket Purchase Agreements (BPAs) offer a pool of well-qualified contractors who provide market-leading services to federal agencies, governmentwide.  PM/CPI accelerates business transformation by fostering an innovative culture of continuous, measurable improvement that eliminates low-value-added activities and improves quality and responsiveness for customers worldwide.",
                  5,
                  "None",
                  "Strategic Planning and Performance Management;
Strategic Business Analysis;
Process and Performance Improvement;
Communications and Change Management; and
Training, Certification and Recognition.",
                  "http://www.gsa.gov/portal/mediaId/173739/fileName/PM-CPI_BPA_B2_Ordering_Procedures.action",
                  "6/23/2018",
                  "Name: Kayleen Huggart
Title: Contracting Officer
Phone: 253-931-7530

Name: Paul Recklau
Title: Program Analyst
Phone: 703-605-3646
E-mail: pmcpibpa@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Program Support Center (PSC)",
                  12,
                  "",
                  5,
                  "Varies according to service",
                  "The Program Support Center (PSC), a component within the United States Department of Health and Human Services (HHS), which provides a full range of shared services to federal agencies including financial management, real estate, facilities and logistics, occupational health, acquisitions, and other administrative operations. Administrative Operations Portfolio services includes Board for Corrections, Customer Contact Center, Departmental Forms Management, Digital Document Management, Fleet Operations, Freedom of Information Act, Graphic Arts, Mail Operations, Mail Screening, Parking Services, Payroll Liaison, Printing Program",
                  "Link Broken",
                  "N/A",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 00CORP: The Consolidated Schedule",
                  6,
                  "The Consolidated Schedule encompasses the vast majority of services currently offered under GSA's Schedules program. The Consolidated Schedule is basically a roll up of some of the individual Schedules maintained by various GSA Acquisition Centers.",
                  5,
                  "0.75% (built into catalog price)",
                  "",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "SME; Kathy Jocoy; kathy.jocoy@gsa.gov; 253-931-7080: Pre-Award SME; Randy Sheppard; dillan.sheppard@gsa.gov; 253-931-7459:Business Manager; Staci Oetting;staci.oetting@gsa.gov; 253-931-7611
",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 03FAC:  Facilities Maintenance and Management",
                  6,
                  "Facilities Maintenance and Management is a Multiple Award Schedule that provides federal agencies a streamlined procurement device to acquire all of the services necessary to maintain and manage a facility",
                  5,
                  "0.75% (built into catalog price)",
                  "Cemetary and gound maintenance, complete facilities maintenance / management, dockside maintenance, repair and dry docking, energy management and audit services, facilities security, facilities furniture and furnishings, operations and logstics supporrt, facilities support products and facilities system maintenance and inspection.",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "National Customer Service Center
(800) 488-3111, mashelpdesk@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 36: Office Imaging and Document Solutions",
                  6,
                  "Schedule 36 covers THE OFFICE, IMAGING AND DOCUMENT SOLUTION",
                  5,
                  "0.75% (built into catalog price)",
                  "Office Equipment
Renting, Leasing and Purchasing of Copiers
Document Support and Management Services
Mail Products and Services",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "National Customer Service Center
(800) 488-3111, mashelpdesk@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 48: Transportation, Delivery and Relocation Solutions",
                  6,
                  "GSA's Schedule 48: Transportation, Delivery and Relocation Solutions provides agencies with good and services related to Long Term Lodging, Domestic Delivery Services, Employee Relocation, Ground Passenger Transportation; Local Courier Delivery, Office Relocation, and Rental Supplemental Vehicles Program. ",
                  5,
                  "0.75% (built into catalog price)",
                  "Consulting Services;
Long Term Lodging Services;
Domestic Delivery Services;
Employee Relocation Services;
Ground Passenger Transportation Services;
Local Courier Delivery Services;
Office Relocation Services; and
Rental Supplemental Vehicles Program.",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "Phone: (703) 605-5616
E-mail: onthego@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 51V: Hardware SuperStore",
                  6,
                  "GSA's Hardware SuperStore has the latest hardware items to help you maintain your units, offices, and buildings.  Purchase hardware products such as tools, appliances, lawn and garden equipment, paints, sealants, and adhesives with related services directly",
                  5,
                  "0.75% (built into catalog price)",
                  "Commercial Coatings, Adhesives, Sealants, and Lubricants
Hardware Store Products via Catalog or Right Out of the Hardware Store
Rental and Leasing of Equipment
Industrial Quality Hand Tools
Lawn and Garden Equipment & Nursery Products
Office, Commercial, and Household Appliances
Industrial Machinery",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "Center for Facilities Maintenance and Hardware (816) 926-6760, hssmarketing@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 520: Financial and Business Solutions (FABS)",
                  6,
                  "GSA's FABS Schedule 520 provides solutions to financial dilemmas through a wide range of auditing, financial management, financial asset, business information and credit monitoring services. The FABS Schedule accommodates financial services assistance. Additionally, this Multiple Award Schedule provides federal agencies with direct access to commercial experts that can thoroughly address the needs of the federal financial community",
                  5,
                  "0.75% (built into catalog price)",
                  "Asset Management Services
Financial Management & Audit Services
Business Information Services & Safeguarding Personal Data
Program Management for Financial Services
Grants Management Support Services",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME; Diran Arslanian; diran.arslanian@gsa.gov; (703) 603-8166
Business Manager; Jacqueline Austin; jacqueline.austin@gsa.gov; (703) 605-2820",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 541: Advertising & Integated Marketing Solutions (AIMS)",
                  6,
                  "GSA Advertising and Integrated Marketing Solutions (AIMS) Schedule contracts are used by federal agencies for website services, communications, outreach, public relations, advertising, and related services.  Agencies typically engage GSA AIMS contractors to help promote public awareness of an agency‰Ûªs mission and initiatives, enhance public understanding of technical and social issues, and to help the armed services with their recruitment campaigns",
                  5,
                  "0.75% (built into catalog price)",
                  "Public Relations Services
Web Based Marketing Services
Market Research and Analysis
Video/Film Production
Exhibit Design and Implementation Services
Conference, Events, and Trade Show Planning Services
Commercial Photography Services
Commercial Art and Graphic Design Services
Challenges and Competitions Services
Integrated Marketing Services
Introduction of New Services
",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME; Kim McFall; kimberly.mcfall@gsa.gov; (253) 931-7277 
Business Manager; Sandra Clerk-Brown; sandra.clerk-brown@gsa.gov; (817) 850-8211",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 70: Information Technology",
                  6,
                  "Schedule 70 covers GENERAL PURPOSE COMMERCIAL INFORMATION TECHNOLOGY EQUIPMENT, SOFTWARE, AND SERVICES",
                  5,
                  "0.75% (built into catalog price)",
                  "Term Software License(s), Perpetual Software License(s), Maintenance of Software as a Service, Associated ancillary services applicable to commercial software http://www.gsaelibrary.gsa.gov/ElibMain/scheduleSummary.do;jsessionid=9EE8535C226B38A87A9E822238494323.prd1pweb",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "Dennis Harrison; dennis.harrison@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 71:  Furniture",
                  6,
                  "Schedule 71 covers furniture and related services for offices, household and quarters, packaged furniture, special use furniture (hospitals, classrooms, etc.)",
                  5,
                  "0.75% (built into catalog price)",
                  "Furniture: Office, Filing, Training, Conference Room, Household and Dormitory, Day Care, Correctional, Healthcare, Educational, Installation.",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "National Customer Service Center
(800) 488-3111, mashelpdesk@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 73: Food Service, Hospitality, and Cleaning",
                  6,
                  "Schedule 73 offers federal customers a variety of cleaning equipment and accessories, Housing Managers and Facility Managers will enjoy the full range of Hospitality Solutions and all food service needs from eating utensils to an entire custom designed food court kiosk concept that supports new branding initiatives are available.",
                  5,
                  "0.75% (built into catalog price)",
                  "Chemicals and Chemical Products;
Cleaning Equipment and Accessories, Cleaning Chemicals and Sorbents, and Janitorial Supplies;
Toiletries, Personal Care Items, Linens, and Lodging and Hospitality Supplies and Services, and Hospitality Wear;
Food Service Equipment, Supplies and Services; and
Recycling Collection Containers and Waste Receptacles.",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "National Customer Service Center (800) 488-3111, mashelpdesk@gsa.gov",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 75: Office Solutions: Supplies & Services",
                  6,
                  "",
                  5,
                  "0.75% (built into catalog price)",
                  "Office Products, Office Services, Restroom Products, Numerous green solutions for office supplies (100% recycled paper, e.g.)",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 81: Shipping, Packaging, Packing Supplies",
                  6,
                  "",
                  5,
                  "0.75% (built into catalog price)",
                  "Bags & Sacks, Packaging Services, Maintenance, Repair & Modification of Containers, Pallets, Plastic & Wood, Unique Identification (UID) & Radio Frequency Identification (RFID), Bottles, Jars, Boxes, Cartons, Crates, Container Systems & Metal Drums, Wrapping & Strapping Materials, Packaging & Packing Bulk Materials, Performance Oriented Packaging (POP), Plastic Over Pack & Hazardous Material Packaging, Aluminum Foil, New Technology, Green solutions (plastic pallets, e.g.)",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 871: Professional Engineering Services",
                  6,
                  "Professional Engineering Services (PES) provides a streamlined approach for federal agencies to access qualified firms in many of the engineering disciplines, such as, but not limited to: mechanical, electrical, chemical, components of civil engineering, software and fire protection related to an engineered system, aerospace, nuclear, bioengineering, and marine architecture.",
                  5,
                  "0.75% (built into catalog price)",
                  "Strategic Planning for Technology Programs/Activities
Concept Development & Requirements Analysis
System Design, Engineering & Integration
Test & Evaluation
Integrated Logistics Support
Acquisition & Life Cycle Management
Construction Management and Engineering Consulting Services Related to Real Property
Ancillary Supplies and/or Services
",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME: Rebecca Randles; rebecca.randles@gsa.gov; (253) 931-7932 Business Manager; Barry Nelson; barry.nelson@gsa.gov; 253-931-7268",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 874 V: Logistics Worldwide (LOGWORLD)",
                  6,
                  "The Logistics Worldwide (LOGWORLD) Multiple Award Schedule 874 V assists federal agencies in procuring comprehensive logistics solutions.",
                  5,
                  "0.75% (built into catalog price)",
                  "Planning acquisition and management of logistics system; 
Providing expert advice, assistance, guidance, management; and
Providing operational support services.
Additionally, training is provided in the following areas:

System operations;
Automated tools for supply; 
Value chain management;
Property and inventory management; 
Distribution and transportation management; and
Maintenance of equipment and facilities supporting these activities. ",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME; Randy Sheppard; dillan.sheppard@gsa.gov; 253-931-7459: Business Manager; Barry Nelson; barry.nelson@gsa.gov; 253-931-7268",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 874: Mission Oriented Business Integrated Services (MOBIS)",
                  6,
                  "Mission Oriented Business Integrated Services (MOBIS) provides a full range of professional business services and related support products for consulting, facilitation, surveys, training, acquisition management support, integrated business program support services, and related support products.",
                  5,
                  "0.75% (built into catalog price)",
                  "Mission Oriented Business Integrated Services (MOBIS) provides a full range of professional business services and related support products for consulting, facilitation, surveys, training, acquisition management support, integrated business program support services, and related support products.",
                  "https://www.gsaadvantage.gov/advantage/main/home.do",
                  "Varies by vendor contract.",
                  "SME; Kristann Montague; kristann.montague@gsa.gov; 253-931-7180:
Business Manager; Barry Nelson; barry.nelson@gsa.gov; 253-931-7268",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Schedule 899: Environmental Services",
                  6,
                  "The Environmental Services schedule assists government agencies to meet demands for Environmental Consulting Services, Environmental Training Services, Materials and Waste Recycling and Disposal Services, Geographic Information Systems (GIS) Services, Remediation and Reclamation Services, and New Services to enable government agencies to meet their environmental needs.",
                  5,
                  "0.75% (built into catalog price)",
                  "Environmental Training Services NAICS 541620
Materials and Waste, Recycling & Disposal Services NAICS 562920, 562112
Geographic Information Systems (GIS) Services NAICS 541620
Remediation and Reclamation Services NAICS 562910, 541380
Ancillary Supplies and/or Services",
                  "www.ebuy.gsa.gov",
                  "Varies by vendor contract.",
                  "SME: Lisa Norgren; lisa.norgren@gsa.gov; (253) 931-7170
Business Manager; Staci Oetting; staci.oetting@gsa.gov; 253-931-7611
",
                  "$100");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1,3);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("SEWP",
                  13,
                  "Solutions for Enterprise-Wide Procurement (SEWP, pronounced 'soup'), is a multi-award Government-Wide Acquisition Contract (GWAC) vehicle focused on IT products and product based services. The 37 pre-competed Contract Holders offer a wide range of advanced technology including tablets, desktops and servers; IT peripherals; network equipment; storage systems; security tools; software products; cloud based services; video conferencing systems and other IT and Audio-Visual products. Product based services such as installation, training, maintenance and warranty are also available through SEWP. As an OMB authorized GWAC, the SEWP contracts are utilized by all Federal Agencies.",
                  5,
                  "0.45% (capped at $10,000)",
                  "Tablets, desktops and servers; IT peripherals; network equipment; storage systems; security tools; software products; cloud-based services; video conferencing systems, and other IT and audio-visual products; as well as related services such as installation, training and maintenance",
                  "http://www.sewp.nasa.gov/",
                  "SEWP IV 04/30/2015 SEWP V 04/30/2025",
                  "Helpline: (301) 286-1478 help@sewp.nasa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),5);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("SmartBuy",
                  6,
                  "SmartBUY is a Federal Strategic Sourcing Initiative (FSSI) featuring blanket purchase agreements (BPAs) for commercial off the shelf software.",
                  5,
                  "0.75% fee (included in catalog price) plus an additional 0-2.5% access fee",
                  "Database management, Enterprise Resource Planning (ERP), Geospatial Information Systems (GIS), Information Assurance (IA), Network Management",
                  "http://www.gsa.gov/portal/content/105119",
                  "Varies by vendor BPA.",
                  "Call: (855) ITaid4U (482-4348) Sunday 8:00 pm. to Friday 8:30 pm. Chat Available on website Email: ITCSC@gsa.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),7);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Source America (Mandatory Source)",
                  14,
                  "SourceAmerica (formerly NISH), is an AbilityOne authorized enterprise and a nonprofit nationwide network of more than 550 community nonprofit agency partners to fulfill contracting needs for the Federal Government, commercial businesses and government contractors. It markets the capabilities of products and services delivered by people with significant disabilities - Mandatory Source for most agencies.",
                  5,
                  "Varies (embedded in catalog price)",
                  "Product Offerings include a wide range of equipment and supplies associated with Aircraft, Vehicular, and Electrical Equipment and Supplies, Clothing, Textiles and Individual Equipment, Food Processing, Packaging and Distribution, Medical and Dental Supplies, and Office Supplies Services include: Administrative, Contract Center, Contract Management, Custodial, Document Management, Electronic Recycling, Fleet Management, Food Services, Grounds Maintenance, Healthcare Environmental, Hospitality, Laundry, Secure Mail/Digital Document, Supply Chain Management and Warehouse, Total Facilities Management.",
                  "https://www.abilityone.com/OA_HTML/xxnib_ibeCCtpSctDspRte.jsp?section=11703&sitex=10040:22372:US&NIBPROD=MWNoOkBJvWonWZjCyAUbrsTSwJ&NIBPROD_pses=ZG9F6A98EC56DD747701106A0D582C080E50DD7B8B0C230D231DC26AA9FB428A5526EC56ECCB53F3C7FA0DED57087515CAF44799F5524C3038",
                  "Varies",
                  "customerservice@SourceAmerica.org",
                  "Varies");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),16);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Support Which Implements Fast Transition (SWIFT IV)",
                  15,
                  "The Support Which Implements Fast Transitions IV (SWIFT IV) Indefinite Quantity Contract (IQC) is to provide the U.S. Agency for International Development's (USAID) Office of Transition Initiatives (OTI) with the means to support U.S. foreign policy objectives by helping local partners advance peace and democracy in priority countries undergoing political or post-conflict transitions.",
                  95,
                  "None",
                  "The contract provides the means to support U.S. foreign policy objectives by helping local partners advance peace
and democracy in priority countries in transition. 

Field Staffing, Administrative, and Management Structures
IQC Services
Transition Activities Pool (TAP)
Personnel
Financial Responsibilities
Activity Database
Geospatial Data and Geographic Information Systems (GIS)
Communications and Information Technology",
                  "N/A",
                  "2/1/2019",
                  "
Primary Point of Contact.:
Sharon Wharton-Smith,
Contracting/Agreement Officer
swharton-smith@usaid.gov
Phone: 2025675347

Secondary Point of Contact:
Chadwick C. Mills,
Contract Specialist
cmills@usaid.gov
Phone: 2025675076

",
                  "$100,000");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Tactical Communications (TacCom) Equipment & Services IDIQ",
                  2,
                  "",
                  33,
                  "None",
                  "Includes equipment and services in the following five technical categories (TCs): TC1 Subscriber Base ‰ÛÒ Portable/mobile radios, control/base stations, software, upgrades, etc.; TC2 Infrastructure ‰Û� Repeaters, routers, comparator systems, OTAR, etc.; TC3 Infrastructure Services ‰Û� Engineering, design, installation, etc.; TC4 O&M Services ‰ÛÒ Maintenance, frequency managers, spectrum managers, etc.; and TC5 Test Equipment.",
                  "N/A",
                  "3/25/2017",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Technical Investigative Surveillance Equipment (TechOps) IDIQ",
                  2,
                  "",
                  ,
                  "None",
                  "TechOps encompasses covert audio equipment, covert video equipment, and ancillary services.",
                  "N/A",
                  "9/17/2017",
                  "",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Total Delivery Services (TDS) - Domestic",
                  9,
                  "USTRANSCOM multiple award contracts for decentralized ordering of international and domestic small package delivery services.",
                  5,
                  "1%",
                  "TDS provide domestic commercial express package delivery service for the U.S. Government.  TDS services include time-definite, door-to-door pick-up and delivery, transportation, Intransit Visibility (ITV), Government Third Party Payment System (TPPS) participation, and customs clearance processing (if applicable).  The domestic segment consists of the following two contracts: Federal Express and United Parcel Service.  Domestic shipments include shipments up to 150 lbs within the Continental United States (CONUS), and up to 300 lbs between CONUS and Alaska, Hawaii, and Puerto Rico, and within Alaska, Hawaii, and Puerto Rico.",
                  "https://www.my.af.mil/gcss-af/USAF/AFP40/d/s6925EC1353610FB5E044080020E329A9/Files/express/tds/index.html",
                  "9/30/2017",
                  "Program Manager: Cathy Mitterer (618) 229-2543, mary.mitterer@us.af.mil
Contracting Officer: Lynda Lang (618) 220-7092, lynda.y.lang.civ@mail.mil",
                  "N/A");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Total Delivery Services (TDS) - International",
                  9,
                  "USTRANSCOM multiple award contracts for decentralized ordering of international and domestic small package delivery services.",
                  5,
                  "3%",
                  "TDS provide international commercial express package delivery service for the U.S. Government.  TDS services include time-definite, door-to-door pick-up and delivery, transportation, Intransit Visibility (ITV), Government Third Party Payment System (TPPS) participation, and customs clearance processing (if applicable).  The international segment consists of the following five contractors: Alaska Airlines (sub: Final Mile Logistics), Federal Express, National Air Cargo (sub: TNT Express), Polar Air Cargo (sub: DHL Express), and United Parcel Service.  International shipments include shipments up to 300 lbs.",
                  "https://www.my.af.mil/gcss-af/USAF/AFP40/d/s6925EC1353610FB5E044080020E329A9/Files/express/tds/index.html",
                  "9/30/2017",
                  "Program Manager: Cathy Mitterer (618) 229-2543, mary.mitterer@us.af.mil
Contracting Officer: Lynda Lang (618) 220-7092, lynda.y.lang.civ@mail.mil",
                  "N/A");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Transformation Twenty-One Total Technology (T4)",
                  5,
                  "The Transformation Twenty-One Total Technology (T4) Program provides a total solution, encompassing, but not limited to, required hardware, software, and IT products, in conjunction with all services needed to integrate a system, network, or other IT service in order to meet a client‰Ûªs mission requirements. ",
                  94,
                  "None",
                  "Contractor-provided solutions in support of Information Technology (IT) encompassing, but not limited to software and IT products incidental to the solution, in conjunction with all services needed to integrate a system, network, or other IT service in order to meet a client‰Ûªs mission requirements. Services shall include technical, systems engineering and other solutions encompassing the entire range of IT requirements. Services, as well as related IT products, may encompass the entire life-cycle of a system, including but not limited to program management and strategy planning, systems/software engineering, enterprise network, cyber security, operation and maintenance and IT facilities.",
                  "Contact TAC",
                  "6/29/2016",
                  "Patricia Meyer (email: Patricia.Meyer2@va.gov)",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("UNICOR (FPI)",
                  16,
                  "Varies",
                  5,
                  "Varies (embedded in catalog price)",
                  "Apparel and Accessories, Awards and Commemorative Items,Contact Center and Help Desk Services, Data Services, Distribution and Warehousing Logistics, Electronics Recycling, Electronics and Components, Energy Efficient and Green Products, Facilities and Warehouse Storage Solutions, Food Service Items, Interior and Exterior Signage,Mattresses, Linens and Draperies, Office Furniture, Seating and Accessories, Prescription and Safety Eyewear, Printing and Bindery Services, Training Site Solutions, Vehicle Upfit, Remanufacturing and Fleet Services",
                  "http://www.unicor.gov/Shopping/viewCat_m.asp?iStore=UNI",
                  "Varies by vendor contract.",
                  "(800) 827-3168, UNICOR.Customer.Service@usdoj.gov",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),16);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Veterans Administration specific ELAs",
                  5,
                  "",
                  94,
                  "None",
                  "Please see "Veterans Administration" section of the Software Enterprise License Agreements in Federal Agencies artifact",
                  "N/A",
                  "N/A",
                  "Please see "Veterans Administration" section of the Software Enterprise License Agreements in Federal Agencies artifact",
                  "");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),17);
INSERT INTO tbContractSolutions (name, fkManagingOrganizationId, description, availableToId, feeInfo, servicesProvided, onlineOrderingUrl, expiration, pocInfo, minOrderQty)
          VALUES ("Warfighter FOCUS",
                  4,
                  "The Warfighter FOCUS program provides worldwide integrated Live, Virtual, and Constructive training operations, maintenance, sustainment, instruction and other services for training devices, simulators, simulations on a global basis. These services primarily support the U.S. Army and include some training support for other U.S. services and Coalition partners.  FOCUS is run by the Program Executive Office for Simulation, Training & Instrumentation.",
                  5,
                  "Based on cost recovery model, depending on size of requirement",
                  "Manage, support, schedule, maintain, operate, and upgrade the L-V-C systems/devices
Provide facilities/warehouse management, and obsolescence management
Develop training support packages and associated training support tools
develop tactics, techniques, and procedures (TTP)
Develop combined arms training strategies
Provide training support in terms of battle master, semi-automated forces, role play, and instructor/operator activities",
                  "http://www.peostri.army.mil/OPS/",
                  "10/26/2017",
                  "
usarmy.orlando.peo-stri.list.ops@mail.mil

Larry Grauert, Contract Specialist, Phone 407-380-4603, Fax 407-380-4164, Email larry.grauert@peostri.army.mil - 

Susan Jaimungal, Contract Specialist, Phone 407-380-8176, Fax 407-384-3830, Email susan.jaimungal@peostri.army.mil",
                  "$400,000");

          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),1);