#pragma once

#define CORE_LIB "core"
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

// dynamic library export
#if defined(_MSC_VER)
	#ifdef CORE_DLL
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_IMPORT __declspec(dllimport)
	#endif
#elif defined(__GNUC__)
	#ifdef CORE_DLL
		#define CORE_API __attribute__((visibility("default")))
	#else
		#define CORE_IMPORT
	#endif
#else
	#define CORE_API
	#define CORE_IMPORT
	#pragma warning Unknown dynamic link import/export semantics.
#endif