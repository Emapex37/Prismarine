#include <Prismarine.h>

class Sandbox : public Prismarine::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

int main() {

	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}