#pragma once
#include "scpch.h"
#include "spyce/core.h"
#include "event.h"

namespace Spyce
{
	class SC_API MouseMovedEvent
		: public Event
	{
	public:
		MouseMovedEvent(float mouse_x, float mouse_y)
		{
			mMouseX = mouse_x;
			mMouseY = mouse_y;
		}

		inline float GetMouseX() const { return mMouseX; }
		inline float GetMouseY() const { return mMouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved: " << GetMouseX() << ", " << GetMouseY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mMouseX, mMouseY;
	};

	class SC_API MouseScrolledEvent
		: public Event
	{
	public:
		MouseScrolledEvent(float scroll_x, float scroll_y)
		{
			mMouseX = scroll_x;
			mMouseY = scroll_y;
		}

		inline float GetScrollX() const { return mMouseX; }
		inline float GetScrollY() const { return mMouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled: " << GetScrollX() << ", " << GetScrollY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mMouseX, mMouseY;
	};


	class SC_API MouseButtonPressedEvent
		: public Event
	{
	public:
		MouseButtonPressedEvent(int button) : mButton(button)
		{
		}

		inline int GetButton() const { return mButton; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed: " << GetButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		int mButton;
	};

	class SC_API MouseButtonReleasedEvent
		: public Event
	{
	public:
		MouseButtonReleasedEvent(int button) : mButton(button)
		{
		}

		inline int GetButton() const { return mButton; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released: " << GetButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		int mButton;
	};
}