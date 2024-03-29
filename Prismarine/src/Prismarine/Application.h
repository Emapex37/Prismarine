#pragma once

#include "Core.h"

#include "Window.h"
#include "Prismarine/LayerStack.h"
#include "Prismarine/Events/Event.h"
#include "Prismarine/Events/ApplicationEvent.h"

#include "Prismarine/ImGui/ImGuiLayer.h"


namespace Prismarine {

	class PRISMARINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }


	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;

	};

	//To be defined in CLIENT
	Application* CreateApplication();

}