#include <node.h>
#include <windows.h>
#include <shobjidl.h>

namespace filemanager
{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::Value;

    // Select folder dialogue for Windows. (Min req. Win > XP)
    void SelectFolderDialogue()
    {
        HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
                                              COINIT_DISABLE_OLE1DDE);
        if (SUCCEEDED(hr))
        {
            IFileOpenDialog *pFileOpen;

            // Create the FileOpenDialog object.
            hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
                                  IID_IFileOpenDialog, reinterpret_cast<void **>(&pFileOpen));

            if (SUCCEEDED(hr))
            {
                // Show the Open dialog box.
                hr = pFileOpen->Show(NULL);

                // Get the file name from the dialog box.
                if (SUCCEEDED(hr))
                {
                    pFileOpen->SetOptions(FOS_PICKFOLDERS);

                    IShellItem *pItem;
                    hr = pFileOpen->GetResult(&pItem);
                    if (SUCCEEDED(hr))
                    {
                        PWSTR pszFilePath;
                        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                        // Display the file name to the user.
                        if (SUCCEEDED(hr))
                        {
                            MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);
                            CoTaskMemFree(pszFilePath);
                        }
                        pItem->Release();
                    }
                }
                pFileOpen->Release();
            }
            CoUninitialize();
        }
        return 0;
    }

    void SelFolder(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        int i;
        double x = 20, y = 2;

        for (i = 0; i < 200; i++)
        {
            x += y;
        }

        auto total = Number::New(isolate, x);
        args.GetReturnValue().Set(total);
    }

    void Initialize(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "select_folder_dialogue", SelFolder);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}