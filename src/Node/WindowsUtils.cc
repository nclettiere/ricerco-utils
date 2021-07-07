#include <Node/WindowsUtils.hpp>
#include <napi.h>

#include <sstream>
#include <codecvt>

#include <rus_config.hpp>

#ifdef RUS_WIN
namespace rus
{
    /**
     * @brief Converts a wstring to a std string. (Only supports english characters and it's very limited.)
     * 
     * @deprecated In favor of std::u16string and napi support. This method souldn't be used. See the Win_SelFolder method.
     */
    std::string wstr2str(const std::wstring &wstr)
    {
        std::string strTo;
        char *szTo = new char[wstr.length() + 1];
        szTo[wstr.size()] = '\0';
        WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, szTo, (int)wstr.length(), NULL, NULL);
        strTo = szTo;
        delete[] szTo;
        return strTo;
    }

    // Select folder dialogue for Windows. (Min req. Win >= Vista)
    std::wstring SelectFolderDialogue(HWND *hWndParent)
    {
        if (hWndParent != NULL)
            EnableWindow(*hWndParent, FALSE);

        std::wostringstream woss;
        PWSTR pszFilePath;

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
                        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                        // Display the file name to the user.
                        if (SUCCEEDED(hr))
                        {
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

        if (hWndParent != NULL)
            EnableWindow(*hWndParent, TRUE);

        return woss.str();
    }

    Napi::Value Win_SelFolder(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::String resultStringPath;

        // Get HWND of the parent window to disable it while the dialogue box is open.
        HWND *hWndParent;
        if (info[0].IsBuffer())
        {
            Napi::Buffer<HWND> buf = info[0].As<Napi::Buffer<HWND>>();
            hWndParent = buf.Data();
        }

        std::wstring folderPath = SelectFolderDialogue(hWndParent);
        /**
         * WINDOWS ONLY
         * For a cross-platform support read:
         * https://stackoverflow.com/questions/42734715/how-can-i-convert-wstring-to-u16string/42743775#42743775
         * 
         */
        std::u16string u16str(folderPath.begin(), folderPath.end());
        /***/

        resultStringPath = Napi::String::From(env, u16str);

        if (hWndParent != NULL)
        {
            SetFocus(*hWndParent);
        }

        return resultStringPath;
    }
} // namespace rus
#endif