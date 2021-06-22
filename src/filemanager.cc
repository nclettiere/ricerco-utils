#include <napi.h>
#include <iostream>
#include <string>
#include <sstream>
#include <codecvt>
#include <windows.h>
#include <shobjidl.h>

std::string wstr2str(const std::wstring &wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    // Select folder dialogue for Windows. (Min req. Win > XP)
    std::string SelectFolderDialogue()
    {
        std::wostringstream woss;

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
                pFileOpen->SetOptions(FOS_PICKFOLDERS);
                // Show the Open dialog box.
                hr = pFileOpen->Show(NULL);

                // Get the file name from the dialog box.
                if (SUCCEEDED(hr))
                {
                    IShellItem *pItem;
                    hr = pFileOpen->GetResult(&pItem);
                    if (SUCCEEDED(hr))
                    {
                        PWSTR pszFilePath;
                        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                        // Display the file name to the user.
                        if (SUCCEEDED(hr))
                        {
                            //MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);
                            woss << pszFilePath;
                            CoTaskMemFree(pszFilePath);
                        }
                        pItem->Release();
                    }
                }
                pFileOpen->Release();
            }
            CoUninitialize();
        }
        return wstr2str(woss.str());
    }
#elif defined(__APPLE__) // |
#elif defined(__linux__) // ---> TODO !
#endif

Napi::Value SelFolder(const Napi::CallbackInfo& info) {
Napi::Env env = info.Env();

const char * folderPath = SelectFolderDialogue().c_str();

Napi::String resultStringPath = Napi::String::New(env, folderPath);
return resultStringPath;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
exports.Set(Napi::String::New(env, "select_folder_dialogue"),
			Napi::Function::New(env, SelFolder));
return exports;
}

NODE_API_MODULE(filemanager, Init)