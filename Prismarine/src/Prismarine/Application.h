#pragma once

#include "Core.h"

namespace Prismarine {

	class PRISMARINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}