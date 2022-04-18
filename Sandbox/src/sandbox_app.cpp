#include <spyce.h>

class Sandbox : public Spyce::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Spyce::Application* Spyce::CreateApplication()
{
	return new Sandbox();
}