#include <Node/Ricerco.hpp>
#include <Project/Project.hpp>
#include <Structure/ProjectStructure.hpp>
#include <napi.h>

#include <stdio.h>

#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>
namespace fs = boost::filesystem;

namespace rus
{
  Napi::Value CreateProject(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();

    if (!info.Length() == 1)
      return Napi::String::New(env, "ERRNO_INVALID_METHOD_OVERLOADING");

    if (info[0].IsObject())
    {
      Napi::Object options = info[0].As<Napi::Object>();

      if (!options.Has("name"))
        return Napi::String::New(env, "ERRNO_INVALID_ARGUMENT : Required entry 'name' could not be found.");
      if (!options.Has("description"))
        return Napi::String::New(env, "ERRNO_INVALID_ARGUMENT : Required entry 'description' could not be found.");

      std::wstring name;
      std::u16string u16name = options.Get("name").As<Napi::String>().Utf16Value();
      name.assign(u16name.begin(), u16name.end());
      std::wstring desc;
      std::u16string u16desc = options.Get("description").As<Napi::String>().Utf16Value();
      desc.assign(u16desc.begin(), u16desc.end());

      Project newProj(name, desc);

      boost::system::error_code ec;
      bool pCreationSuccess;

      // Create the project
      if (options.Has("path"))
      {
        std::wstring path;
        std::u16string u16path = options.Get("path").As<Napi::String>().Utf16Value();
        path.assign(u16path.begin(), u16path.end());
        pCreationSuccess = newProj.CreateProject(path, ec);
      }
      else
      {
        pCreationSuccess = newProj.CreateProject(ec);
      }
      if (!pCreationSuccess)
        return Napi::String::New(env, ec.message());

      // Copy the selected template (or use the default)
      if (!options.Has("template"))
      {
        // load default
        rus::CopyTemplate(newProj, rus::ProjectTemplate::Default);
      }

      return Napi::String::New(env, "API_CreateProject_SUCCESS");
    }
    return Napi::String::New(env, "ABC 1");
  }

  Napi::Value DiscoverProjects(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();

    fs::path whereToFind;

    if (info.Length() == 1)
    {
      if (info[0].IsString())
      {
        Napi::String path = info[0].As<Napi::String>();
        whereToFind = fs::path(path.Utf8Value().c_str());
      }
      else
      {
        return Napi::String::New(env, "ERRNO_INVALID_ARGUMENT_TYPE");
      }
    }
    else if (info.Length() > 1)
    {
      return Napi::String::New(env, "ERRNO_INVALID_METHOD_OVERLOADING");
    }
    else
    {
      // Default path
      whereToFind = rus::GetRicercoDir(RicercoDir::Projects);
    }

    std::vector<fs::path> projectsPaths;
    Napi::Array JS_projectsPaths;

    FindProjects(projectsPaths, whereToFind);

    if (projectsPaths.size() > 0)
    {
      JS_projectsPaths = Napi::Array::New(info.Env(), projectsPaths.size());

      size_t i = 0;
      for (auto it = projectsPaths.begin(); it != projectsPaths.end(); ++it)
      {
        JS_projectsPaths[i] = Napi::String::New(env, it->string());
        i++;
      }
    }else {
      JS_projectsPaths = Napi::Array::New(info.Env(), 0);
    }

    return JS_projectsPaths;
  }

  Napi::Value IsProjectAvailable(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();
    printf("XD   IsProjectAvailable\n");
    return Napi::String::New(env, "ABC 123");
  }

  Napi::Value ReadProjectContents(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();
    printf("XD   ReadProjectContents\n");
    return Napi::String::New(env, "ABC 1234");
  }

  Napi::Value UpdateProject(const Napi::CallbackInfo &info)
  {
    Napi::Env env = info.Env();
    printf("XD   UpdateProject\n");
    return Napi::String::New(env, "ABC 12345");
  }
} // namespace rus
