#include "scpch.h"
#include "windows_window.h"
#include "spyce/events/window_event.h"
#include "spyce/events/key_event.h"
#include "spyce/events/mouse_event.h"

namespace Spyce
{
	static bool g_GLFWInitialized = false;
	static void GLFWErrorCallback(int error, const char* desc)
	{
		SC_LOG_CORE_ERROR("GLFW Error ({0}): {1}", error, desc);
	}
	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}


	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		mData.Width = props.Width;
		mData.Height = props.Height;
		mData.Title = props.Title;

		SC_LOG_CORE_INFO("Creating a new Windows OS window titled '{0}' with size ({1}, {2})", props.Title, props.Width, props.Height);

		if (!g_GLFWInitialized)
		{
			int fail = glfwInit();

			SC_CORE_ASSERT(fail, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			g_GLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)props.Width, (int)props.Height, mData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mData);
		SetVSync(true);

		// set window callbacks
		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* handle, int w, int h)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);
				data.Width = w;
				data.Height = h;

				WindowResizeEvent e(w, h);
				data.EventCallback(e);
			});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* handle) 
			{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);
			WindowCloseEvent e;
			data.EventCallback(e);
			});

		glfwSetWindowPosCallback(mWindow, [](GLFWwindow* handle, int x, int y)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);

				WindowMovedEvent e(x, y);
				data.EventCallback(e);
			});

		glfwSetWindowFocusCallback(mWindow, [](GLFWwindow* handle, int focused)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);
				if (focused)
				{
					WindowFocusEvent e;
					data.EventCallback(e);
				}
				else
				{
					WindowLostFocusEvent e;
					data.EventCallback(e);
				}
			});

		glfwSetKeyCallback(mWindow, [](GLFWwindow* handle, int key, int scan_code, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent e(key, 0);
						data.EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent e(key);
						data.EventCallback(e);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent e(key, 1);
						data.EventCallback(e);
						break;
					}

					}
			});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* handle, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent e(button);
						data.EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent e(button);
						data.EventCallback(e);
						break;
					}
				}
			});

		glfwSetScrollCallback(mWindow, [](GLFWwindow* handle, double xOff, double yOff)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);

				MouseScrolledEvent e(xOff, yOff);
				data.EventCallback(e);
			});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* handle, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(handle);

				MouseMovedEvent e((float)xPos, (float)yPos);
				data.EventCallback(e);
			});

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(mWindow);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled);
		mData.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return mData.VSync;
	}
}