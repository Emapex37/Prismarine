#pragma once

#ifdef PM_PLATFORM_WINDOWS

extern Prismarine::Application* Prismarine::CreateApplication();

int main(int argc, char** argv) {

	auto app = Prismarine::CreateApplication();
	app->Run();

	delete app;
}

#endif // PM_PLATFORM_WINDOWS
