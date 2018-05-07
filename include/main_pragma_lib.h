#pragma once

#include "core/core_pragma_lib.h"

#define LIB_EXT ".lib"

#ifdef _DEBUG
#define LIB_MODE "d"
#else
#define LIB_MODE ""
#endif

#if defined(_WIN64) || defined(__amd64__)
#define LIB_ARCH "_x64"
#else
#define LIB_ARCH ""
#endif

#pragma comment(lib, CORE_LIB LIB_MODE LIB_ARCH LIB_EXT)