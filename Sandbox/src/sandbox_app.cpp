#include <spyce.h>

class ExampleLayer : public Spyce::Layer 
{
public:
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
	}

	void OnEvent(Spyce::Event& evt) override
	{
		SC_LOG_TRACE("{0}", evt);
	}
private:


};

class Sandbox : public Spyce::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Spyce::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Spyce::Application* Spyce::CreateApplication()
{
	return new Sandbox();
}