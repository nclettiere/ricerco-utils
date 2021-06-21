{
    "targets": [
        {
            "target_name": "filemanager",
            "sources": ["<!@(node -p \"require('fs').readdirSync('./src').map(f=>'src/'+f).join(' ')\")"],
        }
    ]
}
