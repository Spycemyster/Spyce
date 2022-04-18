#pragma once

#ifdef SC_PLATFORM_WINDOWS

extern Spyce::Application* Spyce::CreateApplication();

int main(int argc, char** argv)
{
	printf("Using the Spyce Engine v0.1a\n");
	auto app = Spyce::CreateApplication();

	app->Run();
	delete app;
}

#endif