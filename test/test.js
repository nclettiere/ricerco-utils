var filemanager = undefined;
// Load the precompiled binary for windows.
if(process.platform == "win32" && process.arch == "x64") {
	filemanager = require('../bin/win/x64/Release/filemanager.node');  
    console.log("Using x64 pre-built binary");
} else if(process.platform == "win32" && process.arch == "ia32") {
	filemanager = require('../bin/win/x86/Release/filemanager.node'); 
    console.log("Using x86 pre-built binary");
} else {
	// Load the new built binary for other platforms.
	filemanager = require('../build/Release/filemanager.node');  
    console.log("Using local build binary.");
}

console.log(filemanager?.select_folder_dialogue());