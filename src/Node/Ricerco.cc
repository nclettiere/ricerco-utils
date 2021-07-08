#include <Node/Ricerco.hpp>
#include <Project/Project.hpp>
#include <Structure/ProjectStructure.hpp>
#include <napi.h>

#include <stdio.h>

namespace rus
{
    Napi::Value CreateProject(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();

        if (!info.Length() == 1)
            return Napi::String::New(env, "ERRNO_INVALID_ARGUMENT_NUMBER");

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
            bool success;

            if (options.Has("path"))
            {
                std::wstring path;
                std::string u16path = options.Get("path").As<Napi::String>().Utf16Value();
                path.assign(u16path.begin(), u16path.end());
                success = newProj.CreateProject(path, ec);
            }
            else
            {
                success = newProj.CreateProject(ec);
            }
            if (!success)
                return Napi::String::New(env, "ERRNO_INVALID_ARGUMENT_NUMBER");
            return Napi::String::New(env, "API_CreateProject_SUCCESS");
        }
        return Napi::String::New(env, "ABC 1");
    }

    Napi::Value DiscoverProjects(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        printf("XD   DiscoverProjects\n");
        return Napi::String::New(env, "ABC 12");
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