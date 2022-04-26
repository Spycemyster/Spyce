#pragma once

#include "spyce/window.h"
#include "spyce/core.h"

#include <GLFW/glfw3.h>

namespace Spyce
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		// window properties
		inline unsigned int GetWidth() const override { return mData.Width; }
		inline unsigned int GetHeight() const override { return mData.Height; }
		inline void SetEventCallback(const EventCallbackFunc& callback) override
		{
			mData.EventCallback = callback;
		}
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	protected:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		GLFWwindow* mWindow;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			EventCallbackFunc EventCallback;
		};
		WindowData mData;
	};
}