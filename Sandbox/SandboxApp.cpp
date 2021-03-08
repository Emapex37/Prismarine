#include <Prismarine.h>


class ExampleLayer : public Prismarine::Layer {

public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {

		PM_INFO("ExampleLayer::Update");

		if (Prismarine::Input::IsKeyPressed(PM_KEY_TAB))
			PM_INFO("Tab pressed");

	}

	void OnEvent(Prismarine::Event& event) override {
		//PM_TRACE("{0}", event);
	}

};

class Sandbox : public Prismarine::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Prismarine::ImGuiLayer());
	}

	~Sandbox() {

	}

};

Prismarine::Application* Prismarine::CreateApplication() {
	return new Sandbox();
}