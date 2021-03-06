#include <Prismarine.h>


class ExampleLayer : public Prismarine::Layer {

public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		PM_INFO("ExampleLayer::Update");
	}

	void OnEvent(Prismarine::Event& event) override {
		PM_TRACE("{0}", event);
	}

};

class Sandbox : public Prismarine::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}

};

Prismarine::Application* Prismarine::CreateApplication() {
	return new Sandbox();
}