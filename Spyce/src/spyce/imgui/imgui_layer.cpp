#include "scpch.h"
#include "imgui_layer.h"
#include "platform/opengl/imgui_opengl_renderer.h"
#include "imgui.h"
#include "GLFW/glfw3.h"
#include "spyce/application.h"

namespace Spyce
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer() { }

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = mTime > 0.0 ? (time - mTime) : (1.0f / 60.f);
		mTime = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnEvent(Event& evt)
	{
		EventDispatcher dispatcher(evt);
		dispatcher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
	}

	// input events
	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& evt)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[evt.GetButton()] = true;

		return false;
	}
	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& evt)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[evt.GetButton()] = false;

		return false;
	}
	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& evt)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(evt.GetMouseX(), evt.GetMouseY());

		return false;
	}
	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& evt)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += evt.GetScrollY();
		io.MouseWheelH += evt.GetScrollX();

		return false;
	}
	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& evt)
	{
		return false;
	}
	bool ImGuiLayer::OnKeyReleasedEvent(KeyPressedEvent& evt)
	{
		return false;
	}
	bool ImGuiLayer::OnKeyTypedEvent(KeyPressedEvent& evt)
	{
		return false;
	}
	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& evt)
	{
		return false;
	}
}