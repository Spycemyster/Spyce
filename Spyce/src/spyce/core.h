#pragma once

#ifdef SC_PLATFORM_WINDOWS
	#ifdef SC_BUILD_DLL
		#define SC_API __declspec(dllexport)
	#else
		#define SC_API __declspec(dllimport)
	#endif
#else
	#error Platform unsupported by Spyce Engine
#endif