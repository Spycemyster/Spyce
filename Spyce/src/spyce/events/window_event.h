#pragma once

#include "scpch.h"
#include "spyce/core.h"
#include "event.h"

namespace Spyce
{
	class SC_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int window_width, unsigned int window_height) :
			mWindowWidth(window_width),
			mWindowHeight(window_height)
		{  }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << mWindowWidth << ", " << mWindowHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryWindow)
	private:
		unsigned int mWindowWidth;
		unsigned int mWindowHeight;
	};

	class SC_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int window_x, int window_y) :
			mWindowX(window_x),
			mWindowY(window_y)
		{  }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << mWindowX << ", " << mWindowY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	private:
		int mWindowX;
		int mWindowY;
	};

	class SC_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowClosedEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};


	class SC_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowFocus)
			EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};

	class SC_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowLostFocusEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowLostFocus)
			EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};

}