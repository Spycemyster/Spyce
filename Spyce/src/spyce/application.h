#pragma once
#include "core.h"
#include "spyce/events/window_event.h"
#include "window.h"

namespace Spyce 
{
	class SC_API Application
	{
		public:
			/// <summary>
			/// Creates a new instance of an application.
			/// </summary>
			Application();
			~Application();

			/// <summary>
			/// Runs the application
			/// </summary>
			void Run();

			/// <summary>
			/// An event has occured.
			/// </summary>
			/// <param name="e"></param>
			void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& evt);
		std::unique_ptr<Window> mWindow;
		bool mIsRunning;
	};

	// to be defined in client
	Application* CreateApplication();
}

