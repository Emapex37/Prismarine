#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Prismarine {

	class PRISMARINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define PM_CORE_TRACE(...)   ::Prismarine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PM_CORE_INFO(...)    ::Prismarine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PM_CORE_WARN(...)    ::Prismarine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PM_CORE_ERROR(...)   ::Prismarine::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define PM_CORE_FATAL(...)   ::Prismarine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define PM_TRACE(...)        ::Prismarine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PM_INFO(...)         ::Prismarine::Log::GetClientLogger()->info(__VA_ARGS__)
#define PM_WARN(...)         ::Prismarine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PM_ERROR(...)        ::Prismarine::Log::GetClientLogger()->error(__VA_ARGS__)
//#define PM_FATAL(...)        ::Prismarine::Log::GetClientLogger()->fatal(__VA_ARGS__)