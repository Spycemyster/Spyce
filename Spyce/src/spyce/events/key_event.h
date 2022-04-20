#pragma once

#include "event.h"
#include "scpch.h"

namespace Spyce
{
	class SC_API KeyEvent 
		: public Event
	{
	public:
		inline int GetKeyCode() const { return mKeyCode; }

		// keyboard and input event
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int key_code) : mKeyCode(key_code) {}
		int mKeyCode;
	};

	class SC_API KeyPressedEvent : public KeyEvent
	{
	public:
		/// <summary>
		/// Creates a new key pressed event.
		/// </summary>
		/// <param name="key_code"></param>
		/// <param name="repeat_count">The number of times the system is repeating the key.</param>
		KeyPressedEvent(int key_code, int repeat_count) : KeyEvent(key_code), mRepeatCount(repeat_count) {}

		inline int GetRepeatCount() const { return mRepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << GetKeyCode() << " (" << mRepeatCount << " repeats" << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int mRepeatCount;
	};


	class SC_API KeyReleasedEvent : public KeyEvent
	{
	public:
		/// <summary>
		/// Creates a new key released event.
		/// </summary>
		/// <param name="key_code"></param>
		KeyReleasedEvent(int key_code) : KeyEvent(key_code) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased:" << GetKeyCode();
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int mRepeatCount;
	};
}