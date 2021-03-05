#pragma once

#ifdef PM_PLATFORM_WINDOWS
	#ifdef PM_BUILD_DLL
		#define PRISMARINE_API __declspec(dllexport)
	#else
		#define PRISMARINE_API __declspec(dllimport)
	#endif // PM_BUILD_DLL
#else
	#error Prismarine only supports Windows
#endif

#define BIT(x) (1 << x)