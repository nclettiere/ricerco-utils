const ricerco_utils = require("../index").ricerco_utils;
const ricerco_utils = require("../index").ricerco_utils;

const { describe } = require("mocha");
const chai = require("chai");
chai.use(require("chai-match"));

describe("Testing Ricerco Utils libs:", function () {
  it("The return value should be a valid windows path, an empty string or\n\tan error string (when platform is not windows ERRNO_WINDOWS_SUPPORT)", function () {
    chai
        .expect(ricerco_utils?.select_folder_dialogue())
        .to.satisfy(function (path) {
            console.log("  Returned path from dialogue: '"+ path +"'");
            return path.match((/^([a-zA-Z]:)?(\\[^<>:"/\\|?*]+)+\\?$/i)) || path === "" || path === "ERRNO_WINDOWS_SUPPORT" || path === null;
        }, "A valid path or an empty string.");
  }).timeout(Number.MAX_SAFE_INTEGER);
});

describe("Testing - CreateNewProject():", function () {
  it("The return value should be a valid windows path, an empty string or\n\tan error string (when platform is not windows ERRNO_WINDOWS_SUPPORT)", function () {
    chai
        .expect(ricerco_utils?.CreateNewProject())
        .to.satisfy(function (path) {
            console.log("  Returned path from dialogue: '"+ path +"'");
            return path.match((/^([a-zA-Z]:)?(\\[^<>:"/\\|?*]+)+\\?$/i)) || path === "" || path === "ERRNO_WINDOWS_SUPPORT" || path === null;
        }, "A valid path or an empty string.");
  }).timeout(Number.MAX_SAFE_INTEGER);
});