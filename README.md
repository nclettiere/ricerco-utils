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
console.log(filemanager.select_folder_dialogue( --> Buffer containing a window handle (Only supports HWND for now) <-- ));
```

Example in electron:
```javascript
const folderPath = filemanager.select_folder_dialogue(
    mainWindow?.getNativeWindowHandle()
);
```

TODO:
  - MacOS and Linux support.
  - pre-built binaries.

Dependencies:
  - [header-only filesystem by gulrak](https://github.com/gulrak/filesystem)
