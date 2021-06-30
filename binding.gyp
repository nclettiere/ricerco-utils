{
    "targets": [
        {
            "target_name": "filemanager",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions", "-fno-rtti"],
            "sources": [
                "<!@(node -p \"require('fs').readdirSync('./src').map(f=>'src/'+f).join(' ')\")"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "vendor/filesystem/include"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
        }
    ]
}
