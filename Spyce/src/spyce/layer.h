#pragma once

#include "core.h"
#include "events/event.h"

namespace Spyce
{
	class SC_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& evt) {}

		inline const std::string& GetName() const { return mName; }
	protected:
		std::string mName;
	};
}

