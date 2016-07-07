# Acquisition-Gateway-Toolkit

### AngularJS Drupal Fullstack generator

> Acquisition-gateway-Toolkit generators are what give its platform flexibility, allowing you to reuse the same tool for any kind of project you may be working on.

There are many starting points for building a new Angular single page app, in addition to this one. To see a comparison 
of the popular options, have a look at 
[this comparison](http://www.dancancro.com/comparison-of-angularjs-application-starters).

## Instructions to setup your local workspace

#### 1. Install Node.js

[![Gitter](https://badges.gitter.im/Join Chat.svg)](https://gitter.im/nodejs/node?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Node.js is a JavaScript runtime built on Chrome's V8 JavaScript engine. Node.js
uses an event-driven, non-blocking I/O model that makes it lightweight and
efficient. The Node.js package ecosystem, npm, is the largest ecosystem of open
source libraries in the world.

The Node.js project is supported by the
[Node.js Foundation](https://nodejs.org/en/foundation/). Contributions,
policies and releases are managed under an
[open governance model](./GOVERNANCE.md). We are also bound by a
[Code of Conduct](./CODE_OF_CONDUCT.md).

If you need help using or installing Node.js, please use the
[nodejs/help](https://github.com/nodejs/help) issue tracker.

**Download**

Binaries, installers, and source tarballs are available at
<https://nodejs.org>.

**Stable** and **LTS** releases are available at
<https://nodejs.org/download/release/>, listed under their version strings.
The [latest](https://nodejs.org/download/release/latest/) directory is an
alias for the latest Stable release. The latest LTS release from an LTS
line is available in the form: latest-_codename_. For example:
<https://nodejs.org/download/release/latest-argon>

**Nightly** builds are available at
<https://nodejs.org/download/nightly/>, listed under their version
string which includes their date (in UTC time) and the commit SHA at
the HEAD of the release.

**API documentation** is available in each release and nightly
directory under _docs_. <https://nodejs.org/api/> points to the API
documentation of the latest stable version.

In terminal type:
```
node --version
v5.7.1

npm --version
3.6.0
```

#### 2. Install gulp globally

<p align="center">
   <img height="257" width="114" src="https://raw.githubusercontent.com/gulpjs/artwork/master/gulp.png">
  <p align="center">The streaming build system</p>
</p>

__If you have previously installed a version of gulp globally, please run `npm rm --global gulp`
to make sure your old version doesn't collide with gulp-cli.__

```sh
$ npm install --global gulp-cli
```
In terminal type:
```
gulp --version

CLI version 1.2.1
Local version 3.9.0
```
For API specific documentation you can check out the [documentation for that](API.md).

**Available Plugins**

The gulp community is growing, with new plugins being added daily. See the [main website](http://gulpjs.com/plugins/) for a complete list.

#### 3. Install bower globally

<img align="right" height="100" src="http://bower.io/img/bower-logo.png">

Bower offers a generic, unopinionated solution to the problem of **front-end package management**, while exposing the package dependency model via an API that can be consumed by a more opinionated build stack. There are no system wide dependencies, no dependencies are shared between different apps, and the dependency tree is flat.

Bower runs over Git, and is package-agnostic. A packaged component can be made up of any type of asset, and use any type of transport (e.g., AMD, CommonJS, etc.).

```sh
$ npm install -g bower
```
If permissions required, 
```
Run

sudo npm install -g bower
```

**View complete docs on [bower.io](http://bower.io)**

[View all packages available through Bower's registry](http://bower.io/search/).

Bower depends on [Node.js](http://nodejs.org/) and [npm](http://npmjs.org/). Also make sure that [git](http://git-scm.com/) is installed as some bower
packages require it to be fetched and installed.

See complete command line reference at [bower.io/docs/api/](http://bower.io/docs/api/)

#### 4. Install Yeoman Globally

Yeoman helps you to kickstart new projects, prescribing best practices and tools to help you stay productive.

To do so, we provide a generator ecosystem. A generator is basically a plugin that can be run with the `yo` command to scaffold complete projects or useful parts.

**Usage**

```sh
# install yo
sudo npm install --global yo

# install a generator
sudo npm install --global generator-ag-sdk

# run it
yo ag-sdk
```
<img align="center" width="300" height="257" src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image1.png"/>

**Enter the prompted question for your Application**

<img align="center" width="300" height="257" src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image2.png"/>

<img align="center" width="300" height="257" src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image3.png"/>

#### After scaffolding the ag-sdk
<img align="center" width="300" 
src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image4.png" />

#### Install project dependencies

`cd` into `ag-app` **folder**

type `ls` to see `package.json` and `bower.json`

**Now Install Project dependencies by typing**

`npm install` and `bower install`

Now the project setup is complete.

#### How to create a feature

In terminal type

```
yo ag-sdk:feature --help

```

<img align="center" width="300" 
src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image5.png" />

```
yo ag-sdk:feature myFeature

```

<img align="center" width="300" 
src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image6.png" />


#### How to create a directive

`cd` into `ag-app` **folder**

```
yo ag-sdk:directive --help

```
<img align="center" width="300" 
src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image7.png" />

```
yo ag-sdk:directive myDirective

```

<img align="center" width="300" 
src="https://github.com/GSA/Acquisition-Gateway-Toolkit/blob/master/app/images/image8.png" />




## Usage

Install `yo`, `gulp-cli`, `bower`, and `generator-ag-sdk`:
```
sudo npm install -g yo gulp-cli bower generator-ag-sdk
```

Make a new directory, and `cd` into it:
```
mkdir my-new-project && cd $_
```

```
yo ag-sdk


```


## Prerequisites


## Supported Configurations

**General**

* Build Systems: `Gulp`
* Testing: 
  * `Jasmine`
  * `Mocha + Chai + Sinon`
    * Chai assertions:
      * `Expect`
      * `Should`

**Client**

* Scripts: `TypeScript`
* Markup:  `HTML`
* Stylesheets: `CSS`, `Less`
* Angular Routers: `ngRoute`
* CSS Frameworks: `Bootstrap`
  * Option to include `Angular-Strap`

**Server**

* Scripts: `Babel`
* Database:
  * `None`,
  * `MySQL`
    * Authentication boilerplate: `Yes`, `No`
    * Socket.io integration: `Yes`, `No`

## Injection

* `less` files into `client/app/app.less`
* `css` files into `ag-app/index.php`
* `js` files into `ag-app/index.php`
