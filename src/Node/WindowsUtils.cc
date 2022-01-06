#include <Node/WindowsUtils.hpp>
#include <napi.h>

#include <iostream>

#include <sstream>
#include <codecvt>

#ifdef RUS_WIN
namespace rus
{
    /**
     * @brief Converts a wstring to a std string. (Only supports english characters and it's very limited.)
     * 
     * @deprecated In favor of std::u16string and napi support. This method souldn't be used. See the Win_SelFolder method.
     */
    //std::string wstr2str(const std::wstring &wstr)
    //{
    //    std::string strTo;
    //    char *szTo = new char[wstr.length() + 1];
    //    szTo[wstr.size()] = '\0';
    //    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, szTo, (int)wstr.length(), NULL, NULL);
    //    strTo = szTo;
    //    delete[] szTo;
    //    return strTo;
    //}

    // Structure used to communicate data from and to enumeration procedure
    //struct EnumData
    //{
    //    DWORD dwProcessId;
    //    HWND hWnd;
    //};
	//
    //// Application-defined callback for EnumWindows
    //BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam)
    //{
    //    // Retrieve storage location for communication data
    //    EnumData &ed = *(EnumData *)lParam;
    //    DWORD dwProcessId = 0x0;
    //    // Query process ID for hWnd
    //    GetWindowThreadProcessId(hWnd, &dwProcessId);
    //    // Apply filter - if you want to implement additional restrictions,
    //    // this is the place to do so.
    //    if (ed.dwProcessId == dwProcessId)
    //    {
    //        // Found a window matching the process ID
    //        ed.hWnd = hWnd;
    //        // Report success
    //        SetLastError(ERROR_SUCCESS);
    //        // Stop enumeration
    //        return FALSE;
    //    }
    //    // Continue enumeration
    //    return TRUE;
    //}
	//
    //HWND FindWindowFromProcessId(DWORD dwProcessId)
    //{
    //    EnumData ed = {dwProcessId};
    //    if (!EnumWindows(EnumProc, (LPARAM)&ed) &&
    //        (GetLastError() == ERROR_SUCCESS))
    //    {
    //        return ed.hWnd;
    //    }
    //    return NULL;
    //}

    // Select folder dialogue for Windows. (Min req. Win >= Vista)
    //std::wstring SelectFolderDialogue(HWND hWndParent)
    //{
    //    if (hWndParent != NULL)
    //        EnableWindow(hWndParent, FALSE);
	//
    //    std::wostringstream woss;
    //    PWSTR pszFilePath;
	//
    //    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
    //                                          COINIT_DISABLE_OLE1DDE);
    //    if (SUCCEEDED(hr))
    //    {
    //        IFileOpenDialog *pFileOpen;
	//
    //        // Create the FileOpenDialog object.
    //        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
    //                              IID_IFileOpenDialog, reinterpret_cast<void **>(&pFileOpen));
	//
    //        if (SUCCEEDED(hr))
    //        {
    //            pFileOpen->SetOptions(FOS_PICKFOLDERS);
    //            // Show the Open dialog box.
    //            hr = pFileOpen->Show(NULL);
	//
    //            // Get the file name from the dialog box.
    //            if (SUCCEEDED(hr))
    //            {
    //                IShellItem *pItem;
    //                hr = pFileOpen->GetResult(&pItem);
    //                if (SUCCEEDED(hr))
    //                {
    //                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
	//
    //                    // Display the file name to the user.
    //                    if (SUCCEEDED(hr))
    //                    {
    //                        woss << pszFilePath;
    //                        CoTaskMemFree(pszFilePath);
    //                    }
    //                    pItem->Release();
    //                }
    //            }
    //            pFileOpen->Release();
    //        }
    //        CoUninitialize();
    //    }
	//
    //    if (hWndParent != NULL)
    //        EnableWindow(hWndParent, TRUE);
	//
    //    return woss.str();
    //}
	//
    //Napi::Value Win_SelFolder(const Napi::CallbackInfo &info)
    //{
    //    Napi::Env env = info.Env();
    //    Napi::String resultStringPath;
	//
    //    // Get HWND of the parent window to disable it while the dialogue box is open.
    //    HWND hWndParent;
    //    if (info[0].IsBuffer())
    //    {
    //        // With Buffer Handle
    //        Napi::Buffer<HWND> buf = info[0].As<Napi::Buffer<HWND>>();
    //        hWndParent = *buf.Data();
    //    }
    //    else if (info[0].IsNumber())
    //    {
    //        // With PID
    //        Napi::Number pid = info[0].As<Napi::Number>();
    //        hWndParent = FindWindowFromProcessId((DWORD)pid.Uint32Value());
    //    }
	//
    //    std::wstring folderPath = SelectFolderDialogue(hWndParent);
    //    /**
    //     * For a cross-platform support read:
    //     * https://stackoverflow.com/questions/42734715/how-can-i-convert-wstring-to-u16string/42743775#42743775
    //     * 
    //     */
    //    std::u16string u16str(folderPath.begin(), folderPath.end());
    //    /***/
	//
    //    resultStringPath = Napi::String::From(env, u16str);
	//
    //    if (hWndParent != NULL)
    //        SetFocus(hWndParent);
	//
    //    return resultStringPath;
    //}
	//
    //std::wstring GetProjectPath(const std::wstring &relative)
    //{
    //    std::wstring res;
    //    WCHAR basePath[MAX_PATH];
    //    GetModuleFileNameW(NULL, basePath, MAX_PATH);
	//
    //    if (!PathRemoveFileSpecW(basePath))
    //        return res;
    //    if (!PathAppendW(basePath, relative.c_str()))
    //        return res;
	//
    //    res = std::wstring(basePath);
    //    return res;
    //}
} // namespace rus
#endif