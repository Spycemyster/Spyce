#pragma once

#ifdef SC_PLATFORM_WINDOWS

extern Spyce::Application* Spyce::CreateApplication();

int main(int argc, char** argv)
{
	Spyce::Log::Init();
	SC_LOG_CORE_WARN("Initialized logger functionality");
	SC_LOG_INFO(SC_API_NAME);
	auto app = Spyce::CreateApplication();
	app->Run();
	delete app;
}

#endif