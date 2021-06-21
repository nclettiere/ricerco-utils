var filemanager = undefined;

if(process.platform == "win32" && process.arch == "x64")
	filemanager = require('./bin/win/x64/Release/filemanager.node'); 
else if(process.platform == "win32" && process.arch == "ia32")
	filemanager = require('./bin/win/x86/Release/filemanager.node');
else
	filemanager = require('./build/Release/filemanager.node');

module.exports = filemanager;