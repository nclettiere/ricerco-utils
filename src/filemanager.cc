#include <napi.h>
#include <iostream>
#include <string>
#include <sstream>
#include <codecvt>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include <boost/filesystem/operations.hpp>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define ISWIN
#include <windows.h>
#include <shobjidl.h>
#endif

// Filesystem library
namespace fs = boost::filesystem;

std::string wstr2str(const std::wstring &wstr)
{
  using convert_typeX = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<convert_typeX, wchar_t> converterX;

  return converterX.to_bytes(wstr);
}

#ifdef ISWIN
// Select folder dialogue for Windows. (Min req. Win > XP)
std::string SelectFolderDialogue(HWND *hWndParent)
{
  if (hWndParent != NULL)
    EnableWindow(*hWndParent, FALSE);

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

  if (hWndParent != NULL)
    EnableWindow(*hWndParent, TRUE);

  return wstr2str(woss.str());
}
#elif defined(__APPLE__) // |
#elif defined(__linux__) // ---> TODO !
#endif

static HWND UnpackParentWindow(void *wndHandle)
{
  return static_cast<HWND>(*reinterpret_cast<void **>(wndHandle));
}

Napi::Value SelFolder(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::String resultStringPath;

  boost::uuids::random_generator generator;

  boost::uuids::uuid uuid1 = generator();
  std::cout << uuid1 << std::endl;

  boost::uuids::uuid uuid2 = generator();
  std::cout << uuid2 << std::endl;

  std::cout << "sizeof(intmax_t) is " << sizeof(boost::intmax_t) << '\n';

  fs::path p("C:\\Users\\Nicolini\\Documents\\Projects\\ricerco-utils\\binding.gp");

  if (fs::exists(p))
  {
    if (fs::is_regular(p))
    {

      std::cout << "size of "
                << p
                << " is " << fs::file_size(p)
                << std::endl;
    }
    else
    {
      std::cout << "not a regular file: "
                << "C:\\Users\\Nicolini\\Documents\\Projects\\ricerco-utils\\binding.gyp" << std::endl;
    }
  }
  else
  {
    std::cout << "not found: "
              << p 
              << std::endl;
  }

#ifdef ISWIN
  // Get HWND of the parent window to disable it while the dialogue box is open.
  HWND *hWndParent;
  if (info[0].IsBuffer())
  {
    Napi::Buffer<HWND> buf = info[0].As<Napi::Buffer<HWND>>();
    hWndParent = buf.Data();
  }

  const char *folderPath = SelectFolderDialogue(hWndParent).c_str();

  resultStringPath = Napi::String::New(env, folderPath);

  if (hWndParent != NULL)
  {
    SetFocus(*hWndParent);
  }
#endif

  return resultStringPath;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "select_folder_dialogue"),
              Napi::Function::New(env, SelFolder));
  return exports;
}

NODE_API_MODULE(filemanager, Init)
