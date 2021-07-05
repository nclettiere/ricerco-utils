const ricerco_utils = require("../index").ricerco_utils;

const { describe } = require("mocha");
const chai = require("chai");
chai.use(require("chai-match"));

describe("Testing Ricerco Utils libs:", function () {
  it("The return value should be a valid path or an empty string", function () {
    chai
        .expect(ricerco_utils?.select_folder_dialogue())
        .to.satisfy(function (path) {
            console.log("  Testing: ", path);
            return path.match((/^([a-zA-Z]:)?(\\[^<>:"/\\|?*]+)+\\?$/i)) || path === "" || path === null;
        }, "A valid path or an empty string.");
  }).timeout(Number.MAX_SAFE_INTEGER);
});