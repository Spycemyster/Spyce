#pragma once

#include "scpch.h"
#include "core.h"
#include "events/event.h"

namespace Spyce
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& window_title = SC_API_NAME,
			unsigned int window_width = 1365,
			unsigned int window_height = 768)
			: Title(window_title), Width(window_width), Height(window_height) {}
	};
	class SC_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// window properties
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}