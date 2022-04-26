#pragma once
#include "events/window_event.h"
#include "window.h"
#include "layer.h"
#include "layer_stack.h"

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

			inline static Application& Get() { return *sInstance; }
			inline Window& GetWindow() { return *mWindow; }

			// layer system
			void PushLayer(Layer* layer);
			void RemoveLayer(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& evt);
		std::unique_ptr<Window> mWindow;
		bool mIsRunning;
		LayerStack mStack;
		static Application* sInstance;
	};

	// to be defined in client
	Application* CreateApplication();
}

