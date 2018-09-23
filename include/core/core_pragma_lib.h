#pragma once

#define CORE_LIB "core"
#define LIB_EXT ".lib"

#ifdef RY_DEBUG
	#define LIB_MODE "d"
#else
	#define LIB_MODE ""
#endif

#if defined(_WIN64) || defined(__amd64__)
	#define LIB_ARCH "_x64"
#else
	#define LIB_ARCH ""
#endif

// dynamic library export
#if defined(_MSC_VER)
	#ifdef CORE_DLL
		#define CORE_API __declspec(dllexport)
		#define STL_EXP_TEMPLATE
	#else
		#define CORE_API __declspec(dllimport)
		#define STL_EXP_TEMPLATE extern
	#endif
#elif defined(__GNUC__)
	#ifdef CORE_DLL
		#define CORE_API __attribute__((visibility("default")))
		#define STL_EXP_TEMPLATE
	#else
		#define CORE_API
		#define STL_EXP_TEMPLATE extern
	#endif
#else
	#define CORE_API
	#pragma warning Unknown dynamic link import/export semantics.
#endif