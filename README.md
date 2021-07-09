# ricerco-utils
C++ bindings for the Ricerco application.

Allows to access OS specific filesystem features which are not present on Node.js applications.

Install
```shell
yarn add ricerco-utils
npm i ricerco-utils
```
Usage
```javascript
const { ricerco_utils } = require("ricerco-utils"); // Electron and other Node apps
const { ricerco_utils } = nw.require("ricerco-utils"); // NW.JS

console.log(filemanager.WinSelectFolderDialogue( --> leave empty <-- )); // Cannot freeze the window input.
// or
console.log(filemanager.WinSelectFolderDialogue( '--> Buffer containing a window handle (Only supports HWND for now) <--' ));
// or
console.log(filemanager.WinSelectFolderDialogue( '--> JS Number with a window PID (Only supports Windows PID for now) <--' ));
```

Example in electron:
```javascript
const { ricerco_utils } = require("ricerco-utils");
const folderPath = ricerco_utils.WinSelectFolderDialogue(
    mainWindow?.getNativeWindowHandle() // This line gets the buffer
);
```

Example in NW.JS:
```javascript
const { ricerco_utils } = nw.require("ricerco-utils");
// NW.JS Window does not have a method for obtaining the window handle so
// We use the parent window PID.
const folderPath = ricerco_utils.WinSelectFolderDialogue(
    process.ppid // Important to use ppid instead of pid ; ppid returns the parent window PID.
);
```

TODO:
  - MacOS and Linux support.
  - pre-built binaries.

Dependencies:
  - [header-only filesystem by gulrak](https://github.com/gulrak/filesystem)
