#pragma once

#include "spyce/layer.h"
#include "spyce/events/mouse_event.h"
#include "spyce/events/key_event.h"
#include "spyce/events/window_event.h"

namespace Spyce
{
	class SC_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& evt) override;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& evt);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& evt);
		bool OnMouseMovedEvent(MouseMovedEvent& evt);
		bool OnMouseScrolledEvent(MouseScrolledEvent& evt);
		bool OnKeyPressedEvent(KeyPressedEvent& evt);
		bool OnKeyReleasedEvent(KeyPressedEvent& evt);
		bool OnKeyTypedEvent(KeyPressedEvent& evt);
		bool OnWindowResizeEvent(WindowResizeEvent& evt);

		float mTime = 0.f;
	};
}