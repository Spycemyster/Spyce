#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Spyce
{
	class SC_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return mCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return mClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> mCoreLogger;
		static std::shared_ptr<spdlog::logger> mClientLogger;
	};
}

// Core log macros
#define SC_LOG_CORE_ERROR(...)  ::Spyce::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SC_LOG_CORE_WARN(...)   ::Spyce::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SC_LOG_CORE_INFO(...)   ::Spyce::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SC_LOG_CORE_TRACE(...)  ::Spyce::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define SC_LOG_ERROR(...)  ::Spyce::Log::GetClientLogger()->error(__VA_ARGS__)
#define SC_LOG_WARN(...)   ::Spyce::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SC_LOG_INFO(...)   ::Spyce::Log::GetClientLogger()->info(__VA_ARGS__)
#define SC_LOG_TRACE(...)  ::Spyce::Log::GetClientLogger()->trace(__VA_ARGS__)