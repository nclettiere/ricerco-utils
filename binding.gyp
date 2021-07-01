{
    "targets": [
        {
            "target_name": "filemanager",
            "cflags!": ["-fexceptions"],
            "cflags_cc!": ["-fexceptions"],
            "sources": [
                "<!@(node -p \"require('fs').readdirSync('./src').map(f=>'src/'+f).join(' ')\")"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "vendor/filesystem/include",
                "vendor/boost"
            ],
            "defines": ["NAPI_CPP_EXCEPTIONS"],
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "ExceptionHandling": 1
                }
            },
            "conditions": [
                ["OS=='win'", {
                    "defines": [
                        "_HAS_EXCEPTIONS=1"
                    ],
                    "libraries": ["<(module_root_dir)/vendor/boost/libs/win/libboost_filesystem-vc142-mt-s-x64-1_76.lib"],
                }]
            ]
        }
    ]
}
