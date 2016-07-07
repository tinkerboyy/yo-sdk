---
title: File Upload
slug: file-upload-directive
---

The file upload directive provides a file input widget with built in validation for file extensions and file size. It also provides an angular service to upload files to the file service (/api/v1.0/file).

### Usage

```html
<ag-file-upload
  data-input-name="sowUploadWord"
  data-max-file-size="102400000"
  data-allowed-file-extensions="doc,docx"
  data-target="sow.word"></ag-file-upload>
```

### Demo
<ag-file-upload
  data-input-name="sowUploadWord"
  data-max-file-size="102400000"
  data-allowed-file-extensions="doc,docx"
  data-target="sow.word"></ag-file-upload>

### OPTIONS

  | Options                  | Type         	   | Default/Values      |   Description              |
  | ------------------------ | ----------------- | ------------------- | -------------------------- |      
  | inputName | String | | Name of the file input. This will be used as the "name" attribute for the input element |
  | maxFileSize | Integer | | Maximum allowed file size (For IE browsers this will only be used in IE10 and above) |
  | allowedFileExtensions | String | | Comma separated list of allowed file extensions (we're using file extensions rather than mime types so this validator will work in IE9) |
  | target | Object | | Will update the target property with the HTMLInputElement for the file input
