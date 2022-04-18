#pragma once

#include "core.h"

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
	};

	// to be defined in client
	Application* CreateApplication();
}

