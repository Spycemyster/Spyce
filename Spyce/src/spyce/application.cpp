#include "scpch.h"
#include "application.h"
#include "spyce/log.h"

#include <GLFW/glfw3.h>

namespace Spyce
{
#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application() :
		mIsRunning(false)
	{
		mWindow = std::unique_ptr<Window>(Window::Create());
		mWindow->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		mIsRunning = true;
		while (mIsRunning)
		{
			glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->OnUpdate();
		}

		SC_LOG_CORE_INFO("Main loop has terminated... Thank you for using {0}", SC_API_NAME);
	}

	void Application::OnEvent(Event& evt)
	{
		EventDispatcher ed(evt);
		ed.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));
		SC_LOG_CORE_TRACE("{0}", evt);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		mIsRunning = false;
		return true;
	}
}