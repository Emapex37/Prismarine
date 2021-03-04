#include <Prismarine.h>

class Sandbox : public Prismarine::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Prismarine::Application* Prismarine::CreateApplication() {
	return new Sandbox();
}