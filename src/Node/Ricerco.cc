#include <Node/Ricerco.hpp>
#include <napi.h>

#include <stdio.h>

namespace rus
{
    Napi::Value CreateProject(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::Object o;

        if(!info.Length >= 1)
            return false;

        if (info[0].IsObject())
        {
            Napi::Buffer<HWND> buf = info[0].As<Napi::Buffer<HWND>>();
            hWndParent = buf.Data();
        }

        printf("XD   CreateProject\n");
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