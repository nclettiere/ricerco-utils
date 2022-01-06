#include <napi.h>

#include <Node/Ricerco.hpp>
#include <Node/WindowsUtils.hpp>

Napi::Value Win_PlatformErr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, "ERRNO_WINDOWS_SUPPORT");
}

Napi::Object Init_Ricerco(Napi::Env env, Napi::Object exports)
{
    // Ricerco
    //exports.Set(Napi::String::New(env, "CreateProject"),
    //            Napi::Function::New(env, rus::CreateProject));
	//
    //exports.Set(Napi::String::New(env, "DiscoverProjects"),
    //            Napi::Function::New(env, rus::DiscoverProjects));
	//
    //exports.Set(Napi::String::New(env, "IsProjectAvailable"),
    //            Napi::Function::New(env, rus::IsProjectAvailable));
	//
    //exports.Set(Napi::String::New(env, "ReadProjectContents"),
    //            Napi::Function::New(env, rus::ReadProjectContents));
	//
    //exports.Set(Napi::String::New(env, "UpdateProject"),
    //            Napi::Function::New(env, rus::UpdateProject));

    // WindowsUtils
#ifdef RUS_WIN
    exports.Set(Napi::String::New(env, "WinSelectFolderDialogue"),
                Napi::Function::New(env, rus::SelectFolder));
#else
    exports.Set(Napi::String::New(env, "SelectFolderDialogue"),
                Napi::Function::New(env, Win_PlatformErr));
#endif
    return exports;
}


NODE_API_MODULE(ricerco_utils, Init_Ricerco)