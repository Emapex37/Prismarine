#pragma once

#ifdef PM_PLATFORM_WINDOWS

extern Prismarine::Application* Prismarine::CreateApplication();

int main(int argc, char** argv) {

	Prismarine::Log::Init();
	PM_CORE_WARN("Initialized log");
	int a = 5;
	PM_INFO("Hello var={0}", a);

	auto app = Prismarine::CreateApplication();
	app->Run();

	delete app;
}

#endif // PM_PLATFORM_WINDOWS
