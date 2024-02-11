# ricerco-utils

### Project is archived as modern electron and NW.js provides access to this bindings.

---

Allows to access OS specific filesystem features which are not present on normal electron/nw.js applications.

#### Features
 - Open a native 'Select Folder' dialogue

#### Install
```shell
yarn add ricerco-utils
npm i ricerco-utils
```

#### Configure for your needs
Take a look at Cmake-js [docs](https://github.com/cmake-js/cmake-js)
<p>This project uses Cmake-Js and targets a NW.JS runtime.<br>
You can build for a lot platforms and architectures.<br></p>

```shell
# modify node_modules/ricerco-utils/package.json file to fit your needs.
  "cmake-js": {
    "runtime": "nw", # "node" | "electron" | "nw"
    "runtimeVersion": "0.59.1",
    "arch": "x64" # "x64" | "ia32" | "arm64" | "arm"
  }
# Then you should rebuild the module or do an 'npm install' to apply the changes.
```

#### Usage
```javascript
const { ricerco_utils } = require("ricerco-utils"); // Electron and other Node apps
const { ricerco_utils } = nw.require("ricerco-utils"); // NW.JS (in some cases, the 'nw.' part can be omitted)

console.log(filemanager.WinSelectFolderDialogue( '--> leave empty <--' )); // The main window remains active while the PickFolder dialogue is showing.
// or
console.log(filemanager.WinSelectFolderDialogue( '--> JS Number with a window PID <--' ));
```

#### Example in Electron:
```javascript
const { ricerco_utils } = require("ricerco-utils");
const folderPath = ricerco_utils.WinSelectFolderDialogue(
    require('electron').remote.getCurrentWebContents().getOSProcessId() // Not tested
);
```

#### Example in NW.JS:
```javascript
const { ricerco_utils } = nw.require("ricerco-utils");
// NW.JS Window does not have a method for obtaining the window handle so
// We use the parent window PID.
const folderPath = ricerco_utils.WinSelectFolderDialogue(
    process.ppid // Important to use ppid instead of pid ; ppid returns the parent window PID.
);
```

#### TODO:
  - Implement more APIs.
  - Remove junk.
  - Implement CMake variables to customize the library.
  - MacOS and Linux support.
  - pre-built binaries.

#### Dependencies (see the vendor folder for more info):
  - [Native File Dialog Extended](https://github.com/btzy/nativefiledialog-extended)
