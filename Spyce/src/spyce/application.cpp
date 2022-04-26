#include "scpch.h"
#include "application.h"
#include "spyce/log.h"
#include "spyce/shapes/triangle.h"
#include "spyce/vector2.h"

#include <glad/glad.h>

namespace Spyce
{
	#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::sInstance = nullptr;

	Application::Application() :
		mIsRunning(false)
	{
		SC_CORE_ASSERT(!sInstance, "Application already exists.");
		sInstance = this;
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

			for (Layer* layer : mStack)
				layer->OnUpdate();

			mWindow->OnUpdate();
		}

		SC_LOG_CORE_INFO("Main loop has terminated... Thank you for using {0} :D", SC_API_NAME);
	}

	void Application::OnEvent(Event& evt)
	{
		EventDispatcher ed(evt);
		ed.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));

		for (auto it = mStack.end(); it != mStack.begin(); )
		{
			Layer* layer = (*--it);
			layer->OnEvent(evt);
			if (evt.IsHandled())
			{
				break;
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		mIsRunning = false;
		return true;
	}

	void Application::RemoveLayer(Layer* layer)
	{
		mStack.RemoveLayer(layer);
	}

	void Application::PushLayer(Layer* layer)
	{
		mStack.PushLayer(layer);
	}
}