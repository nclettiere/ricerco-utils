{
    "targets": [
        {
            "target_name": "filemanager",
            "cflags!": ["-fexceptions"],
            "cflags_cc!": ["-fexceptions", "-std=c++17"],
            "sources": [
                "<!@(node -p \"require('fs').readdirSync('./src/Structure').map(f=>'src/Structure/'+f).join(' ')\")",
                "<!@(node -p \"require('fs').readdirSync('./src/Project').map(f=>'src/Project/'+f).join(' ')\")",
                "<!@(node -p \"require('fs').readdirSync('./src').map(f=>'src/'+f).join(' ')\")"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "./include",
                "vendor/filesystem/include",
                "vendor/boost"
            ],
            "defines": ["NAPI_CPP_EXCEPTIONS"],
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "ExceptionHandling": 1,
                    "AdditionalOptions": ["-std:c++17"]
                }
            },
            "copies":
            [
                {
                    "destination": "<(module_root_dir)/build/Release/default",
                    "files": ["<(module_root_dir)/default/project_default.json"]
                }
            ],
            "conditions": [
                ["OS=='win' and OS=='win'", {
                    "defines": [
                        "_HAS_EXCEPTIONS=1"
                    ],
                    "libraries": ["<(module_root_dir)/vendor/boost/libs/win/libboost_filesystem-vc142-mt-s-x64-1_76.lib"],
                }]
            ]
        }
    ]
}
