#pragma once

#include <string>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define RUS_WIN
#include <windows.h>
#include <shobjidl.h>
#endif
extern const std::string G_homeVar;