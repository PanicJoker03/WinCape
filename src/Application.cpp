#include "defines.hpp"
#include "Gui/Manager.hpp"
//#include <vector>
//#include <iostream>
//#include <map>
#include "Gui/Window.hpp"
#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
namespace WinCape{
	//--------------------------------------------------------------------------
	//Application
	//--------------------------------------------------------------------------
	void Application::init(const wchar_t* name)
	{
		Manager::instance().registerClass(name);
	}
	Gui::Window Application::createWindow(const wchar_t* windowName,
		const wchar_t* title, const Rect& rect, WindowStyle style,
		WindowExtendedStyle exStyle)
	{
		Gui::Window window;
		window = Gui::Window(Manager::instance().createHandle(
			windowName, title, style, rect, nullptr, exStyle)
		);
		return window;
	}
	int Application::run()
	{
		return WinCape::Manager::instance().startListening();
	}
	int Application::run(WinCape::Gui::WindowFrame& window)
	{
		using namespace WinCape;
		window.onCreate();
		window.onPaint([&](Event e) {
			PAINTSTRUCT paintStruct;
			Gui::DeviceContext deviceContext{
				(BeginPaint(window.handle(), &paintStruct))
			};
			window.onDraw(window.deviceContext());
			EndPaint(window.handle(), &paintStruct);
			});
		//window.onCreate();
		return WinCape::Manager::instance().startListening();
	}
	InstanceHandle Application::instance()
	{
		return GetModuleHandle(NULL);
	}
	void Application::defaultFont(const wchar_t* fontName)
	{
		WinCape::Manager::instance().defaultFont(fontName);
	}

	void Application::quit() {
		PostQuitMessage(0);
	}
}
