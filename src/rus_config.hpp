#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define RUS_WIN
#include <windows.h>
#include <shobjidl.h>

const char * G_homeVar = "USERPROFILE";
#else
const char * G_homeVar = "~";
#endif

const char * G_Path_RicercoBase = ".Ricerco";
const char * G_Path_RicercoProjectsBase = ".Ricerco/Projects";
const char * G_Path_RicercoCacheBase = ".Ricerco/Cache";