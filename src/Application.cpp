#include "defines.hpp"
#include "Gui/Manager.hpp"
//#include <vector>
//#include <iostream>
//#include <map>
#include "Gui/Window.hpp"
#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
namespace cape{   
     //Some crazy stuff to make WinCape c++98 compiles
     usr::WindowFrame * Application::functorWnd = NULL;
     void Application::wndOnPaint(EVENT e){
        PAINTSTRUCT paintStruct;
        usr::DeviceContext deviceContext = usr::DeviceContext(
            (BeginPaint(functorWnd->handle(), &paintStruct))
        );
        functorWnd->onDraw(functorWnd->deviceContext());
        EndPaint(functorWnd->handle(), &paintStruct);
     }
    
	//--------------------------------------------------------------------------
	//Application
	//--------------------------------------------------------------------------
	void Application::init(CON_WSTR name)
	{
		usr::Manager::instance().registerClass(name);
	}
	usr::Window Application::createWindow(CON_WSTR windowName,
		CON_WSTR title, const CAPE_RECT& rect, WND_STY style,
		WNDX_STY exStyle)
	{
		usr::Window window;
		window = usr::Window(usr::Manager::instance().createHandle(
			windowName, title, style, rect, usr::Base::Null, exStyle)
		);
		return window;
	}
	int Application::run()
	{
		return usr::Manager::instance().startListening();
	}
	int Application::run(usr::WindowFrame& window)
	{
		using namespace cape;
		Application::functorWnd = &window;
		window.onCreate();
		window.onPaint(wndOnPaint);
		//window.onCreate();
		return usr::Manager::instance().startListening();
	}
	ISC_HND Application::instance()
	{
		return GetModuleHandle(NULL);
	}
	void Application::defaultFont(CON_WSTR fontName)
	{
		usr::Manager::instance().defaultFont(fontName);
	}

	void Application::quit() {
		PostQuitMessage(0);
	}
}
