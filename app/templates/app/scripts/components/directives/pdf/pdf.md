---
title: Pdf
slug: pdf-directive
---

Pdf directive provides a  functionality to change the behaviour of the iframe that can be used across the application.  The directive takes as parameters an object of document embed url and pdf url options.

### Usage
```html
<iframe ag-pdf
        data-embed-url="document.pdf.embed_url"
        data-pdf-url="document.pdf.url">
</iframe>
```

### OPTIONS
| Options                  | Type         	   | Default/Values      |   Description              |
| ------------------------ | ----------------- | ------------------- | -------------------------- |      
| embedUrl                 | object            |                     | The place to embed the document|
| pdfUrl                   | Object            |                     | To display the document pdf url|


### Demo
<iframe ag-pdf
        ng-if="isMSIE"
        data-embed-url="document.pdf.embed_url"
        data-pdf-url="document.pdf.url">
</iframe>
