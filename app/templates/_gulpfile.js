/* <%= title %> */

var gulp = require('gulp');
var concat = require('gulp-concat');
var minifyCSS = require('gulp-minify-css');
var clean = require('gulp-clean');
var jshint = require('gulp-jshint');
var stylish = require('jshint-stylish');
var imagemin = require('gulp-imagemin');
var jpegtran = require('imagemin-jpegtran');
var merge = require('merge-stream');
var less = require('gulp-less');
var autoprefix = require('gulp-autoprefixer');
var tar = require('gulp-tar');
var gzip = require('gulp-gzip');
var copy = require('gulp-copy');
var flatten = require('gulp-flatten');
var karma = require('karma');
var requirejs = require('requirejs');
var ngAnnotate = require('ng-annotate');
var templateCache = require('gulp-angular-templatecache');
var jscs = require('gulp-jscs');
var htmlreplace = require('gulp-html-replace');
var livereload = require('gulp-livereload');
var bump = require('gulp-bump');
var fs = require('fs');
var addsrc = require('gulp-add-src');
var rename = require('gulp-rename');
var argv = require('yargs').argv;
var markdown = require('gulp-markdown-to-json');
var gutil = require('gulp-util');
var runSequence = require('run-sequence');
var protractor = require('gulp-protractor').protractor;
var webdriver = require('gulp-protractor').webdriver_standalone;
var webdriver_update = require('gulp-protractor').webdriver_update;
var baseUrl = argv.baseUrl || 'http://hallways.localhost';
var run = require('gulp-run');
var publicUser = argv['public-user'];
var username = argv.username || publicUser ? 'publicE2eUser' : 'e2eUser';
var password = argv.password || 'PassW0rd';
var browser = argv.browser || 'chrome';

var getVersion = function() {
  return JSON.parse(fs.readFileSync('./package.json', 'utf8')).version;
};

//Initialize version string
var version = getVersion();
var bumpType = argv.release === 'yes' ? 'minor' : 'patch';

var appRoot = 'app/';
var build = 'deploy';
var drupalDeploy = '/var/www/html/hallways';

var paths = {
  docs: [
    '*.md',
    appRoot + '*.md',
    appRoot + '**/*.md',
    '!' + appRoot + 'vendor/**/*.md',
    '!' + appRoot + 'public/**/*.md',
    '!' + appRoot + '**/*_test.md',
    '!' + appRoot + '**/*_e2e_spec.md'
  ],
  js: [
    appRoot + '*.js',
    appRoot + '**/*.js',
    '!' + appRoot + 'vendor/**/*.js',
    '!' + appRoot + 'public/**/*.js',
    '!' + appRoot + '**/*_test.js',
    '!' + appRoot + '**/*.e2e.js'
  ],
  css: appRoot + 'assets/css/*.css',
  html: appRoot + '**/*.html',
  images: appRoot + 'assets/images/**/*',
  fonts: [
    appRoot + 'assets/fonts/*',
    appRoot + '**/*.eot',
    appRoot + '**/*.svg',
    appRoot + '**/*.ttf',
    appRoot + '**/*.woff',
    appRoot + '**/*.woff2',
  ],
  components: [
    appRoot + 'scripts/components/*.js',
    appRoot + 'scripts/components/**/*.js',
    '!' + appRoot + '**/*_test.js',
    '!' + appRoot + '**/*_e2e_spec.js'
  ],
  templates: [
    appRoot + '**/*.html',
    '!' + appRoot + 'index.html'
  ],
  build: {
    css: 'assets/css',
    images: 'assets/images',
    fonts: 'assets/fonts',
    js: 'scripts/main',
    publicJs: 'scripts/public-main',
    index: 'index.php',
    docs: './' + build + '/docs'
  },
  // what CSS files to concat and minify for solutionmatrix.min.css
  index: appRoot + 'index.php',
  less: {
    vendor: [
      appRoot + 'vendor/bootstrap/less/bootstrap.less',
      appRoot + 'vendor/fontawesome/less/font-awesome.less',
      appRoot + 'vendor/angular-motion/**/*.less'
    ],
    app: [
      appRoot + 'assets/less/*.less',
      appRoot + 'scripts/**/*.less'
    ]
  },
  drupal: {
    base: '../',
    vendorBin: '../sites/all/vendor/bin/',
    sitesAll: '../sites/all/',
    modules: '../sites/all/modules',
    themes: '../sites/all/themes',
    deploy: '../sites/all/deploy',
    homepage: '../homepage',
    publicGateway: '../public-gateway.php',
    themeDeploy: drupalDeploy + '/sites/all',
    moduleDeploy: drupalDeploy + '/sites/all',
    deployDeploy: drupalDeploy + '/sites/all',
    homepageDeploy: drupalDeploy
  },
  docroot: build + '/app',
  drupalRoot: build + '/drupal',
  ui: '/var/www/html/hallways/ag-app'
};

gulp.task('default', ['clean'], function() {
  // place code for your default task here
  return gulp.start(
    'build'
  );
});

gulp.task('bump:major', function() {
  var stream = gulp.src('./package.json')
    .pipe(bump({ type: 'major' }))
    .pipe(gulp.dest('./'));

  stream.on('end', function() {
    version = getVersion();
  });

  return stream;
});

gulp.task('bump:minor', function() {
  var stream = gulp.src(['./package.json', './bower.json'])
    .pipe(bump({ type: 'minor' }))
    .pipe(gulp.dest('./'));

  stream.on('end', function() {
    version = getVersion();
  });

  return stream;
});


gulp.task('bump:patch', function() {
  var stream = gulp.src(['./package.json', './bower.json'])
    .pipe(bump({ type: 'patch' }))
    .pipe(gulp.dest('./'));

  stream.on('end', function() {
    version = getVersion();
  });

  return stream;

});

// runs the build whenever one of our custom JavaScript or CSS files changes
gulp.task('watch', function() {
  var watchFiles = paths.js.concat(paths.less);
  gulp.watch(watchFiles, ['less', 'test']);
});

//deleted the build artifact folder
gulp.task('clean', function () {
  return gulp.src(build, {read: false})
    .pipe(clean());
});

var createLessTasks = function(prefix, dest) {
  //Copy any images referenced relatively in any CSS into main CSS folder
  gulp.task(prefix + 'copy-css-images', function() {
    return gulp.src(appRoot + 'vendor/jquery-ui/themes/base/images/*')
      .pipe(gulp.dest(appRoot + paths.build.css + '/images/'));
  });

  //Generate vendor CSS
  gulp.task(prefix + 'less-vendor', function() {
    return gulp.src(paths.less.vendor)
      .pipe(less())
      .pipe(autoprefix())
      .pipe(addsrc(appRoot + 'vendor/bootstrap-additions/dist/bootstrap-additions.min.css'))
      .pipe(addsrc(appRoot + 'vendor/angular-toasty/dist/angular-toasty.css'))
      .pipe(addsrc(appRoot + 'vendor/jquery-ui/themes/base/jquery-ui.css'))
      .pipe(addsrc(appRoot + 'vendor/jquery-asScrollable/css/asScrollable.css'))
      .pipe(concat('vendor.css'))
      .pipe(gulp.dest(appRoot + '/' + paths.build.css));
  });

  //compile less files into main CSS
  gulp.task(prefix + 'less', [prefix + 'copy-css-images', prefix + 'less-vendor'], function() {
    return gulp.src(paths.less.app)
      .pipe(less())
      .pipe(autoprefix())
      .pipe(concat('main.css'))
      .pipe(gulp.dest(appRoot + '/' + paths.build.css));
  });
};
createLessTasks('', appRoot + '/' + paths.build.css);

//may want to update
gulp.task('gather-templates', function (){
  var TEMPLATE_HEADER = 'define(["angular", "app"], function(angular, app) { return app.run(function($templateCache) {',
    TEMPLATE_FOOTER = '});});';

  return gulp.src(paths.templates)
    .pipe(templateCache({
      templateHeader: TEMPLATE_HEADER,
      templateFooter: TEMPLATE_FOOTER
    }))
    .pipe(gulp.dest(build));
});

gulp.task('minify-js', ['bump:' + bumpType, 'gather-templates'], function(cb) {
  console.log('Minifying JavaScript files ...');

  requirejs.optimize({
    name: 'main',
    mainConfigFile: appRoot + 'scripts/main.js',
    basePath: appRoot + 'scripts',
    optimize: 'uglify2',
    uglify2: { mangle: true },
    insertRequire: [ 'main' ],
    include: [ '../../deploy/templates', '../vendor/requirejs/require' ],
    onBuildRead: function(moduleName, path, contents) {
      if (moduleName === 'main') {
        contents = contents.replace(/define\(\'main\'\,(\s*)\[(\s*)\'angular\',(\s*)/, 'define(\'main\', [\'angular\', \'../../deploy/templates\',');
      }

      return ngAnnotate(contents, { add: true, remove: false }).src;
    },
    out: paths.docroot + '/' + paths.build.js + '-v' + version + '.js'
  }, function() { cb(); });
});

gulp.task('minify-public', ['minify-js', 'gather-templates'], function(cb) {
  console.log('Minifying Public JavaScript files ...');

  requirejs.optimize({
    name: 'public-main',
    mainConfigFile: appRoot + 'scripts/public-main.js',
    basePath: appRoot + 'scripts',
    //optimize: 'uglify2',
    //uglify2: { mangle: false },
    insertRequire: [ 'public-main' ],
    include: [ '../../deploy/templates', '../vendor/requirejs/require' ],
    onBuildRead: function(moduleName, path, contents) {
      if (moduleName === 'public-main') {
        contents = contents.replace(/define\(\'public-main\'\,(\s*)\[(\s*)\'angular\',(\s*)/, 'define(\'public-main\', [\'angular\', \'../../deploy/templates\',');
      }

      return ngAnnotate(contents, { add: true, remove: false }).src;
    },
    out: paths.docroot + '/' + paths.build.publicJs + '-v' + version + '.js'
  }, function() { cb(); });
});

gulp.task('minify-css', ['less'], function() {
  console.log('Minifying CSS files...');
  return gulp.src(paths.css)
    .pipe(minifyCSS())
    .pipe(rename(function (path) {
      path.basename += '-v' + version;
      return path;
    }))
    .pipe(gulp.dest(paths.docroot + '/' + paths.build.css));
});

gulp.task('copy-requirejs', function() {
  return gulp.src(appRoot + 'vendor/requirejs/require.js')
    .pipe(gulp.dest(paths.docroot + '/vendor/requirejs'));
});

gulp.task('imagemin', function() {
  console.log('Minifying Images files...');
  return gulp.src(paths.images)
    //.pipe(imagemin())
    .pipe(gulp.dest(paths.docroot + '/' + paths.build.images));
});

gulp.task('copy-fonts', function() {
  console.log('Copying Fonts files...');
  return gulp.src(appRoot + 'assets/fonts/**/*')
    .pipe(gulp.dest(paths.docroot + '/' + paths.build.fonts));
});

gulp.task('copy-fonts-old', function() {
  console.log('Copying Fonts files...');
  return gulp.src(paths.fonts)
    .pipe(gulp.dest(paths.docroot + '/' + paths.build.fonts))
    .pipe(flatten())
    .pipe(gulp.dest(paths.docroot + '/' + paths.build.fonts));
});

//Run unit tests
gulp.task('unit', function(done) {
  console.log('running unit tests...');
  karma.server.start({
    configFile: __dirname + '/karma.conf.js',
    singleRun: true
  }, done);
});

//Run JSCS
gulp.task('jscs', function() {
  console.log('running JSCS...');
  return gulp.src(paths.js)
    .pipe(jscs());
});


// lints files and parks at you if you did something bad
gulp.task('jshint', function() {
  console.log('running JSHint...');
  return gulp.src(paths.js)
    .pipe(jshint())
    .pipe(jshint.reporter('jshint-stylish'))
    .pipe(jshint.reporter('fail'));
});

gulp.task('test', [
  'jshint',
  'jscs',
  'unit'
]);

gulp.task('copy-index', ['bump:' + bumpType], function() {
  return gulp.src(paths.index)
    .pipe(htmlreplace({
      js: '<script src="scripts/<?php if ($publicUser) echo "public-"; ?>main-v' + version + '.js"></script>',
      vendorcss: '<link rel="stylesheet" href="assets/css/vendor-v' + version + '.css" />',
      maincss: '<link rel="stylesheet" href="assets/css/main-v' + version + '.css" />',
      appVersion: '<!-- App Version: ' + version + '-->'
    }))
    .pipe(gulp.dest(paths.docroot));
});

//Make sure CSS is minified then copy over CSS images from CSS folder to deploy CSS folder
gulp.task('deploy-css-and-images', ['minify-css'], function() {
  return gulp.src(appRoot + paths.build.css + '/images/*')
    .pipe(gulp.dest(paths.docroot + '/' + paths.build.css + '/images/'));
});

gulp.task('deploy-app', ['bump:' + bumpType, 'minify-js', 'minify-public', 'deploy-css-and-images', 'imagemin', 'copy-fonts', 'copy-index', 'copy-requirejs'], function() {
  return gulp.src([
      paths.docroot + '/**/*',
      '!' + paths.docroot + '/templates.js'
    ])
    .pipe(tar('ui.tar'))
    .pipe(gzip())
    .pipe(gulp.dest(paths.ui));
});


gulp.task('pack-modules', function() {
  return gulp.src(paths.drupal.modules + '/**/*')
    .pipe(tar('modules.tar'))
    .pipe(gzip())
    .pipe(gulp.dest(paths.drupal.moduleDeploy));
});

gulp.task('pack-themes', function() {
  return gulp.src(paths.drupal.themes + '/**/*')
    .pipe(tar('themes.tar'))
    .pipe(gzip())
    .pipe(gulp.dest(paths.drupal.themeDeploy));
});

gulp.task('pack-deploy', function() {
  return gulp.src(paths.drupal.deploy + '/**/*')
    .pipe(tar('deploy.tar'))
    .pipe(gzip())
    .pipe(gulp.dest(paths.drupal.deployDeploy));
});

gulp.task('pack-homepage', function() {
  return gulp.src(paths.drupal.homepage + '/**/*')
    .pipe(tar('homepage.tar'))
    .pipe(gzip())
    .pipe(gulp.dest(paths.drupal.homepageDeploy));
});

//deploy drupal artifacts
gulp.task('deploy-drupal', function() {
  gulp.start([
    'pack-modules',
    'pack-themes',
    'pack-deploy',
    'pack-homepage'
  ]);
});

gulp.task('deploy-public-gateway', function() {
  gulp.src(paths.drupal.publicGateway)
    .pipe(gulp.dest('/var/www/html/hallways'));
});

//Run all deploy tasks
gulp.task('deploy', ['clean'], function() {
  console.log('Deploying files ...');
  return gulp.start([
    'deploy-app',
    'deploy-drupal',
    'deploy-public-gateway'
  ]);
});

//DOCUMENTATION TASKS
//Compile components
gulp.task('compile-components-js', ['gather-templates'], function() {
  gulp.src(paths.components)
    .pipe(gulp.dest('./docs/components'))
    .on('end', function() {
      gulp.src('./deploy/templates.js')
        .pipe(gulp.dest('./docs/'))
        .on('end', function() {
          requirejs.optimize({
            name: 'main',
            uglify: false,
            mainConfigFile: './docs/main.js',
            basePath: appRoot + 'scripts/components',
            insertRequire: [ 'main', 'templates' ],
            include: [ './templates', '../app/vendor/requirejs/require' ],
            onBuildRead: function(moduleName, path, contents) {
              return ngAnnotate(contents, { add: true, remove: false }).src;
            },
            out: './docs/app/scripts/main.js'
          });
        })
    });;
});

//compile components LESS files
createLessTasks('compile-components-', './docs/app/assets/css');

//copy documentation template over
gulp.task('copy-docs-template', function() {
  gulp.src('docs/*.html')
    .pipe(gulp.dest('docs/app'));
});

//copy mock data file
gulp.task('copy-docs-data', function() {
  gulp.src('docs/data.js')
    .pipe(gulp.dest('docs/app/scripts'));
});

//copy fonts
gulp.task('copy-docs-fonts', function() {
  console.log('Copying Fonts files...');
  return gulp.src(paths.fonts)
    .pipe(flatten())
    .pipe(gulp.dest('docs/app/' + paths.build.fonts));
});

//Read all markdown into JSON
gulp.task('markdown', function() {
  gulp.src(paths.docs)
    .pipe(gutil.buffer())
    .pipe(markdown('docs.json', {
        sanitize: false
    }))
    .pipe(gulp.dest('docs/app/scripts'));
});

//Generate Swagger JSON for APIs
gulp.task('swagger-generate', function() {
  run(paths.drupal.vendorBin + 'swagger --bootstrap ' + paths.drupal.sitesAll +
    '/swagger_settings.php --output ' + paths.drupal.base + '/api-v1.0-swagger.json ' +
    paths.drupal.modules + '/custom/gateway_restful_api/').exec();
});

gulp.task('copy-swagger-ui', ['swagger-generate'], function() {
  gulp.src('/assets/js/swagger-ui/**/*')
    .pipe(gulp.dest('/var/www/html/hallways/assets/js/swagger-ui'));
});

gulp.task('copy-swagger-json', ['swagger-generate'], function() {
  gulp.src('/api-v1.0-swagger.json')
    .pipe(gulp.dest('/var/www/html/hallways/'));
});

//deploy documentation app
gulp.task('docs', [
  'markdown',
  'compile-components-less',
  'compile-components-js',
  'copy-docs-template',
  'copy-docs-fonts',
  'copy-docs-data',
  'swagger-generate',
  'copy-swagger-ui',
  'copy-swagger-json'
],
function() {

});

gulp.task('deploy-docs', ['docs', 'copy-swagger-ui', 'copy-swagger-json'], function() {
  return gulp.src('./docs/**/*')
    .pipe(gulp.dest(paths.ui + '/docs'));
});

gulp.task('webdriver_update', webdriver_update);
gulp.task('webdriver', ['webdriver_update'], webdriver);

gulp.task('copy-csv-reporter', function() {
  return gulp.src('./jasmine-csv-reporter/**/*', { base: '.' })
    .pipe(gulp.dest('./node_modules/'));
});

gulp.task('e2e', ['copy-csv-reporter'], function() {
  runSequence('webdriver_update', 'webdriver');
  return gulp.src(['./nothing'])
    .pipe(protractor({
      configFile: 'protractor.conf.js',
      keepAlive: true,
      args: ['--baseUrl', baseUrl, '--params.username', username, '--params.password', password, '--params.browser', browser, '--params.publicUser', publicUser]
    }))
    .on('end', function() {
      console.log('E2E Testing complete');
      process.exit();
    })
    .on('error', function(error) {
      console.log('E2E Tests failed');
      process.exit(1);
    });
});
