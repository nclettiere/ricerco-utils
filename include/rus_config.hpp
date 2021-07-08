#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define RUS_WIN
#include <Windows.h>
#include <Shobjidl.h>
#include <Shlwapi.h>
#endif

#include <string>

extern const std::string G_homeVar;