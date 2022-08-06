#include "defines.hpp"
#include "Gui/Manager.hpp"
//#include <vector>
//#include <iostream>
//#include <map>
#include "Gui/Window.hpp"
#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
namespace WinCape{   
     //Some crazy stuff to make WinCape c++98 compiles
     Gui::WindowFrame * Application::functorWnd = NULL;
     void Application::wndOnPaint(Event e){
        PAINTSTRUCT paintStruct;
        Gui::DeviceContext deviceContext = Gui::DeviceContext(
            (BeginPaint(functorWnd->handle(), &paintStruct))
        );
        functorWnd->onDraw(functorWnd->deviceContext());
        EndPaint(functorWnd->handle(), &paintStruct);
     }
    
	//--------------------------------------------------------------------------
	//Application
	//--------------------------------------------------------------------------
	void Application::init(const wchar_t* name)
	{
		Gui::Manager::instance().registerClass(name);
	}
	Gui::Window Application::createWindow(const wchar_t* windowName,
		const wchar_t* title, const Rect& rect, WindowStyle style,
		WindowExtendedStyle exStyle)
	{
		Gui::Window window;
		window = Gui::Window(Gui::Manager::instance().createHandle(
			windowName, title, style, rect, Gui::Base::Null, exStyle)
		);
		return window;
	}
	int Application::run()
	{
		return Gui::Manager::instance().startListening();
	}
	int Application::run(Gui::WindowFrame& window)
	{
		using namespace WinCape;
		Application::functorWnd = &window;
		window.onCreate();
		window.onPaint(wndOnPaint);
		//window.onCreate();
		return Gui::Manager::instance().startListening();
	}
	InstanceHandle Application::instance()
	{
		return GetModuleHandle(NULL);
	}
	void Application::defaultFont(const wchar_t* fontName)
	{
		Gui::Manager::instance().defaultFont(fontName);
	}

	void Application::quit() {
		PostQuitMessage(0);
	}
}
