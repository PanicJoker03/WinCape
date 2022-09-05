#include "defines.hpp"
#include "Gui/Manager.hpp"
#include "Gui/Window.hpp"
#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
namespace cap{   
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
	void Application::init(WSTR_CON name)
	{
		usr::Manager::instance().registerClass(name);
	}
	usr::Window Application::createWindow(WSTR_CON windowName,
		WSTR_CON title, const CAPE_RECT& rect, WND_STY style,
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
		using namespace cap;
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
	void Application::defaultFont(WSTR_CON fontName)
	{
		usr::Manager::instance().defaultFont(fontName);
	}

	void Application::quit() {
		PostQuitMessage(0);
	}
}
