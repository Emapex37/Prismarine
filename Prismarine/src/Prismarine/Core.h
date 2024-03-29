#pragma once

//DLL macros
#ifdef PM_PLATFORM_WINDOWS
	#ifdef PM_BUILD_DLL
		#define PRISMARINE_API __declspec(dllexport)
	#else
		#define PRISMARINE_API __declspec(dllimport)
	#endif // PM_BUILD_DLL
#else
	#error Prismarine only supports Windows
#endif

#ifdef PM_DEBUG
	#define PM_ENABLE_ASSERTS
#endif // PM_DEBUG

//Asserts
#ifdef PM_ENABLE_ASSERTS
	#define PM_ASSERT(x, ...) {if(!(x)) {PM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define PM_CORE_ASSERT(x, ...) {if(!(x)) {PM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define PM_ASSERT(x, ...)
	#define PM_CORE_ASSERT(x, ...)
#endif // PM_ENABLE_ASSERTS

//Bit stuff
#define BIT(x) (1 << x)

#define PM_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)