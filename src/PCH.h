#pragma once

#include "BaseLibraries.h"

//local
#include "Util.h"

#undef cdecl  // Workaround for Clang 14 CMake configure error.

#define DLLEXPORT __declspec(dllexport)

using namespace std::literals;
using TRACE = SKSE::log::trace;
using INFO = SKSE::log::info;
using WARN = SKSE::log::warn;
using ERROR = SKSE::log::error;