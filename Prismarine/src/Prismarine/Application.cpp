#include "pmpch.h"
#include "Application.h"

#include "Prismarine/Events/ApplicationEvent.h"
#include "Prismarine/Log.h"

namespace Prismarine {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PM_TRACE(e);

		while (true);
	}

}