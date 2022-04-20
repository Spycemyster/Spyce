#pragma once

#include "spyce/core.h"

namespace Spyce
{
	// type definition for all events
	enum class EventType
	{
		None = 0,
		
		// window specific events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

		// keyboard specific events
		KeyPressed, KeyReleased,

		// mouse button specific events
		MouseButtonPressed, MouseButtonReleased,

		// mouse specific events
		MouseMoved, MouseScrolled
	};

	// category checking
	enum EventCategory
	{
		None = 0,
		EventCategoryWindow	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};
	
	// event type definition macro
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }
	// event category macro
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	/// <summary>
	/// Base class for all types of events.
	/// </summary>
	class SC_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		/// <summary>
		/// This event has the specified category.
		/// </summary>
		/// <param name="category"></param>
		/// <returns></returns>
		inline bool IsInCategory(unsigned int category)
		{
			return GetCategoryFlags() & category;
		}
	private:
		bool mHandled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : mEvent(event) {}

		template<typename T>
		/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="function"></param>
		/// <returns></returns>
		bool Dispatch(EventFunc<T> function)
		{
			if (mEvent.GetEventType() == T::GetStaticType())
			{
				mEvent.mHandled = function(*(T*)&mEvent);
				return true;
			}

			return false;
		}
	private:
		Event& mEvent;
	};

	inline std::ostream& operator<< (std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}