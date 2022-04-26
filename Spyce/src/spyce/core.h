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

#define SC_API_NAME "Spyce Engine v0.1a"


// assertion statements
#ifdef SC_ENABLE_ASSERTS
	#define SC_ASSERT(x, ...) { if(!(x)) { SC_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define SC_CORE_ASSERT(x, ...) { if(!(x)) { SC_LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define SC_ASSERT(x, ...)
	#define SC_CORE_ASSERT(x, ...)
#endif

// a bit shift by x
#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)