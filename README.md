# ricerco-utils
C++ bindings for the Ricerco application.

Allows to access OS specific filesystem features which are not present on Node.js applications.

Install
```shell
yarn add ricerco-utils
npm i ricerco-utils
```

#### Configure for your needs
Take a look at Cmake-js [docs](https://github.com/cmake-js/cmake-js)
<p>This project uses Cmake-Js and targets a NW.JS runtime.<br>
You can build for a lot platforms and architectures.<br></p>

```shell
# modify package.json to fit your needs.
  "cmake-js": {
    "runtime": "nw", # "node" | "electron" | "nw"
    "runtimeVersion": "0.54.1",
    "arch": "x64" # "x64" | "ia32" | "arm64" | "arm"
  }
```

#### Usage
```javascript
const { ricerco_utils } = require("ricerco-utils"); // Electron and other Node apps
const { ricerco_utils } = nw.require("ricerco-utils"); // NW.JS

console.log(filemanager.WinSelectFolderDialogue( '--> leave empty <--' )); // Cannot freeze the window input and bring the dialogue on top.
// or
console.log(filemanager.WinSelectFolderDialogue( '--> Buffer containing a window handle <--' ));
// or
console.log(filemanager.WinSelectFolderDialogue( '--> JS Number with a window PID <--' ));
```

#### Example in Electron:
```javascript
const { ricerco_utils } = require("ricerco-utils");
const folderPath = ricerco_utils.WinSelectFolderDialogue(
    mainWindow?.getNativeWindowHandle() // This line gets the buffer
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
  - MacOS and Linux support.
  - pre-built binaries.

#### Dependencies (see the vendor folder for more info):
  - [Boost Filesystem](https://github.com/boostorg/filesystem)
  - [nlohmann's json lib](https://github.com/nlohmann/json)
  - [cereal lib](https://github.com/USCiLab/cereal)