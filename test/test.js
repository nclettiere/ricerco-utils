//const ricerco_utils = require("../index").ricerco_utils;
const { ricerco_utils } = require("../index");

const { describe } = require("mocha");
const chai = require("chai");
chai.use(require("chai-match"));

describe("Testing Ricerco Utils libs:", function () {
  it("The return value should be a valid windows path, an empty string or\n\tan error string (when platform is not windows ERRNO_WINDOWS_SUPPORT)", function () {
    chai
      .expect(ricerco_utils?.WinSelectFolderDialogue())
      .to.satisfy(function (path) {
        console.log("  Returned path from dialogue: '" + path + "'");
        return (
          path.match(/^([a-zA-Z]:)?(\\[^<>:"/\\|?*]+)+\\?$/i) ||
          path === "" ||
          path === "ERRNO_WINDOWS_SUPPORT" ||
          path === null
        );
      }, "A valid path or an empty string.");
  }).timeout(Number.MAX_SAFE_INTEGER);
});

describe("Testing - CreateNewProject() with english characters:", function () {
  it("The return value should be a valid windows path, an empty string or\n\tan error string (when platform is not windows ERRNO_WINDOWS_SUPPORT)", function () {
    chai
      .expect(ricerco_utils?.CreateProject({ name: "ElPersa", description: "NÑóEl Abdul de las arenas."}))
      .to.satisfy(function (path) {
        console.log("  Returned path from dialogue: '" + path + "'");
        return (
          path.match(/^([a-zA-Z]:)?(\\[^<>:"/\\|?*]+)+\\?$/i) ||
          path === "" ||
          path === "ERRNO_WINDOWS_SUPPORT" ||
          path === null
        );
      }, "A valid path or an empty string.");
  }).timeout(Number.MAX_SAFE_INTEGER);
});