Setting Up Your Development Environment
==================

##Table of Contents##

 1. Introduction
 2. Required Software
 3. Attaining Permissions and Access
 4. Installing Apache
 5. Installing PHP
 6. Installing MySQL
 7. Installing Node.js
 8. Installing Git
 9. Cloning the Hallways Repository
 10. Configuring Drupal and MySQL
 11. Setting up the Angular application
 12. Testing Your Work

##Introduction##
The Acquisition Gateway a.k.a the "hallways" application is a hybrid of a headless Drupal installation that feeds a front-end AngularJs client.  To make the application run on your local environment, you will need all software required to run Drupal and AngularJS on your machine.

Along with this, there are unit tests and end-to-end (e2e) tests that are run locally.  Your local environment must support the execution of these tests.

This document will guide you towards setting up your local environment to get all of the above mentioned running.

##Required Software##
In order to have your local environment running, you will need the following required software to run on your machine:

 1. Node.js - Version 4.0 or above.
 2. PHP - Version 6.0 or above
 3. Apache - Version 2.4 or above
 4. MySQL - Version 5.6 or above
 5. Git - Version 2.5 or above

##Attaining Permissions and Access##
Setting up your local environment and being able to contribute to the project repository will require you to have access to the following:

 1. An e-mail address
 2. A github.com account
 3. Access to the hallways github repository.

###Getting an e-mail address###
Obtaining an email address is quite self explanatory.  If you need one, you can simply get a [GMail](http://gmail.com/) address to get you going.
### Getting a github.com account###
If you don't already have one, please create a new [github](http://github.com) account.  You will need this to continue working on the hallways project.
###Access to the hallways github repository###
Once you have created an email address and a github account, please email Wendell Armstrong at [wendell.armstrong@gsa.gov](mailto:wendell.armstrong@gsa.gov) to receive access to the hallways github repository.

After your access is granted, you will receive an email, which will ask you to join the GSA organization.  This will complete your access verification to the github repository.

##Installing Apache##
This section will guide you on how to setup Apache web server on your local environment
###Windows###
There are many ways of setting up Apache on Windows, including using stacks such as WAMP or XAMP.  However, please **do not** install Apache with these packages as they can lead to inflexibility, unnecessary dependencies and trouble in updgrading.

There are many guides available online that show you how to install Apache on Windows without using a  WAMP or XAMP stack.  One great guide is provided by SitePoint [here](http://www.sitepoint.com/how-to-install-apache-on-windows/).
###Mac###
Perhaps the best way to install Apache on Mac is through homebrew.  Follow the steps below to install apache on your machine:

 1. Open terminal
 2. Install xcode if you don't already have it:
     `xcode-select --install`
 3. Install Homebrew - If you don't already have homebrew, install it by typing the following commands in your terminal:
` ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
 4. Update homebrew
   ` brew doctor
   brew update && brew upgrade`
 5. Install Apache
 `brew tap homebrew/apache `
 `brew install httpd22`

###Linux (Ubuntu)###
1. Open terminal
2. Type
`sudo apt-get install apache2`
3. Press <kbd>Enter</kbd> and follow the command prompts to complete installation
##Installing PHP##
###Windows###
Once again, there are many guides available for installing PHP on your Windows machine.  One great guide is provided by SitePoint, which walks you through the process of installing PHP manually on your Windows machine.  It can be found [here](http://www.sitepoint.com/how-to-install-php-on-windows/).
###Mac###
The homebrew PHP package provides an excellent guide on installing php using homebrew.  To view this guide, please navigate to https://github.com/Homebrew/homebrew-php#installation

###Linux (Ubuntu)###
1. Open terminal
2. Type
`sudo apt-get install php5`
3. Press <kbd>Enter</kbd> and follow the command prompts to complete installation
##Installing MySQL##
###Windows###
The folks over at MySQL have provided a very simple guide on how to install MySQL on your Windows machine.  You can access this guide [here](http://dev.mysql.com/doc/refman/5.7/en/windows-installation.html#idm140604114247856).
###Mac###
We will use homebrew to install mysql on your Mac.  Follow the directions below:
1. Open terminal
2. Type the following commands one after the next:
`brew doctor`
`brew update`
`brew install mysql`
`unset TMPDIR`
`mysql_install_db --verbose --user=`whoami` --basedir="$(brew --prefix mysql)" --datadir=/usr/local/var/mysql --tmpdir=/tmp`
`mysql.server start`

###Linux (Ubuntu)###
1. Open terminal
2. Type
`sudo apt-get install mysql-server libapache2-mod-auth-mysql php5-mysql`
`sudo mysql_install_db`
`sudo /usr/bin/mysql_secure_installation`
3. Press <kbd>Enter</kbd> and follow the command prompts to complete installation
4. At some point in the installation, you will be asked to provide a password for the root user.  If you choose to create this password, please be sure to remember or write it down.

##Installing Node.js##
###Windows###
Installing Node on Windows is as easy as downloading the installer and double-clicking on it.  You can download the installer on Node's website [here](https://nodejs.org/en/download/package-manager/#windows).
###Mac###
We will use homebrew to install node on your Mac.  Follow the directions below:
1. Open terminal
2. Type the following commands one after the next:
`brew doctor`
`brew update`
`brew install node`

###Linux (Ubuntu)###
1. Open terminal
2. Type
`sudo apt-get install -y nodejs`
3. Press <kbd>Enter</kbd> and follow the command prompts to complete installation
##Installing Git##
###Windows###
Install Git on your Windows using the "Git for Windows" project. It is simple and effective.  Instructions can be found on their website [here](https://git-for-windows.github.io/).
###Mac###
We will use homebrew to install git on your Mac.  Follow the directions below:
1. Open terminal
2. Type the following commands one after the next:
`brew doctor`
`brew update`
`brew install git`

###Linux (Ubuntu)###
1. Open terminal
2. Type
`sudo apt-get install -y git-all`
3. Press <kbd>Enter</kbd> and follow the command prompts to complete installation

##Cloning the Hallways Repository##
###Creating and Setting Up SSH Keys###
You will need to create and setup SSH keys in order to clone the hallways repository.  Creating SSH keys is different for each operating system and there are plenty of guides on the internet that will guide you on how to create one for your operating system.

However, the [Github.com](https://help.github.com/articles/generating-ssh-keys/) website provides clear instructions for **all operating systems** on how to create SSH keys and insert them into your user settings.

Follow the instructions [here](https://help.github.com/articles/generating-ssh-keys/) to accomplish this.

###Cloning the repo###
Once you have your SSH keys established in GitHub.com, follow these steps to clone your repo:
1. Open your terminal or command prompt
2. Navigate to where you want to clone your repo.

> **Note:** This is the location your Apache will point the virtualhost to
> (explained later).  So make sure this location can have the
> appropriate read-write-execute permissions.


Clone the repo by typing
 `git clone git@github.com:GSA/CAP-ACQUISITION_GATEWAY.git`

##Configuring Drupal and MySQL##
###Configuring Drupal###
You now have the code installed for Drupal after you just cloned the hallways repository.  You will need to update the settings.php file for this Drupal installation to get it to work with the hallways application.  To do so:

 - Download the settings.php file here: http://dummyurl-does-not-work/
 - Replace the existing settings.php (or the default settings.php file) file in your cloned repo with this new file.

###Configuring MySQL###
To configure your MySQL to work with your new Drupal installation, you will need to perform the following steps:

 - Create two new databases in mysql: **hallways** and **dbSolutionMatrix**
 - For **both** of these databases, you will need to **create a new user** called **cap_db_user**
 - The password for cap_db_user should be PassW0rd (or whatever you have it set in your settings.php file for your local Drupal installation).  By the way, that's a 0 (zero) after the W in PassW0rd.
 - Now import the tables and data into the new databases that you just created.  This can be done importing the two sql files listed below:
   - The hallways database import can be downloaded at: http://dummyurl-does-not-work/
   - The dbSolutionMatrix database import can be downloaded at: http://dummyurl-does-not-work/

##Configuring Apache##
You should now have the following complete:
1. You cloned the repo to your web directory where Apache can reach it
2. You've successfully installed Apache, MySQL and PHP.
3. You've created the necessary databases and users in MySQL
4. You've replaced your settings.php file with the one needed for this project.

  - **Next**, configure a new virtual host in your Apache configuration and point the virtual host's web directory to the directory in which you have cloned your hallways repository.

    >Note: You will probably need to install additional modules and make changes to config files for this.  There are plenty of guides online that help you setup virtual hosts in Apache.  Here are a few recommendations:
      - Windows: http://foundationphp.com/tutorials/apache_vhosts.php
      - Linux(Ubuntu): https://help.ubuntu.com/community/ApacheMySQLPHP#Virtual_Hosts
      - Mac: http://foundationphp.com/tutorials/vhosts_leopard.php
  - If you haven't done so already, configure your hosts file and make an entry for your hallways application, i.e. hallways.local using your local ip 127.0.0.1.
  - Enable mod_rewrite module for Apache (this is a **must**)
  - Restart Apache

##Setting Up the Angular Application ##
We are now set to spin up your Angular environment and finish up this whole thing.
  - Open up command line prompt
  - Navigate to the directory you had cloned your repo in.
  - Now, within that directory, navigate to /ag-app/
  - Run the following commands

   > Note if you are in linux or Mac, you have have to add "sudo" before all commands.

  `npm install -g gulp bower phantomjs`
  `npm install`
  `bower install`

##Testing Your Work##
If you followed all the aforementioned steps, you should now be able to access the hallways application by visiting your localhost at http://hallways.localhost or whatever you configured in your hosts file.





