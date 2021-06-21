# ricerco-utils
C++ bindings for the Ricerco application.

Allows to access OS specific code.

Install
```
yarn add ricerco-utils
npm i ricerco-utils
```
Usage
```javascript
const filemanager = require('ricerco-utils').filemanager;
console.log(filemanager.select_folder_dialogue());
```

Current libraries: 
  - filemanager features:
    <p>allows user to access OS "select folder" which is forbidden by modern browsers and cannot be accessed by JS itself.</p>
  
TODO:
  MacOS and Linux support and pre-built binaries.
