#include <Node/Ricerco.hpp>
#include <napi.h>

#include <stdio.h>

namespace rus
{
    Napi::Value CreateProject(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        printf("CreateProject\n");
        return Napi::String::New(env, "ABC");
    }

    Napi::Value DiscoverProjects(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        printf("DiscoverProjects\n");
        return Napi::String::New(env, "ABC");
    }

    Napi::Value IsProjectAvailable(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        printf("IsProjectAvailable\n");
        return Napi::String::New(env, "ABC");
    }

    Napi::Value ReadProjectContents(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        printf("ReadProjectContents\n");
        return Napi::String::New(env, "ABC");
    }

    Napi::Value UpdateProject(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        printf("UpdateProject\n");
        return Napi::String::New(env, "ABC");
    }
} // namespace rus

Napi::Object Init_Ricerco(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "CreateProject"),
                Napi::Function::New(env, rus::CreateProject));

    exports.Set(Napi::String::New(env, "DiscoverProjects"),
                Napi::Function::New(env, rus::DiscoverProjects));

    exports.Set(Napi::String::New(env, "IsProjectAvailable"),
                Napi::Function::New(env, rus::IsProjectAvailable));

    exports.Set(Napi::String::New(env, "ReadProjectContents"),
                Napi::Function::New(env, rus::ReadProjectContents));

    exports.Set(Napi::String::New(env, "UpdateProject"),
                Napi::Function::New(env, rus::UpdateProject));

    return exports;
}

NODE_API_MODULE(ricerco_utils, Init_Ricerco)