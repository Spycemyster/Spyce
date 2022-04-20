#include "scpch.h"
#include "log.h"

namespace Spyce
{
	std::shared_ptr<spdlog::logger> Log::mClientLogger;
	std::shared_ptr<spdlog::logger> Log::mCoreLogger;

	void Log::Init()
	{
		// Format is: Timestamp+Message+Color/Formatting
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// for the engine log messages
		mCoreLogger = spdlog::stdout_color_mt("SPYCE");
		mCoreLogger->set_level(spdlog::level::trace);

		// for app related messages
		mClientLogger = spdlog::stdout_color_mt("APP");
		mClientLogger->set_level(spdlog::level::trace);
	}


}