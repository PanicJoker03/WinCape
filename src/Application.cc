#include "defines.h"
#include "Ui/Manager.h"
#include "Ui/Window.h"
#include "Ui/WindowFrame.h"
#include "Application.h"
namespace w_cape{   
     //Some crazy stuff to make WinCape c++98 compiles
     ui::WindowFrame * Application::functorWnd = NULL;
     void Application::wndOnPaint(EVENT e){
        PAINTSTRUCT paintStruct;
        ui::DeviceContext deviceContext = ui::DeviceContext(
            (BeginPaint(functorWnd->handle(), &paintStruct))
        );
        functorWnd->onDraw(functorWnd->deviceContext());
        EndPaint(functorWnd->handle(), &paintStruct);
     }
    
	//--------------------------------------------------------------------------
	//Application
	//--------------------------------------------------------------------------
	void Application::init(WCH_STR_CONST name)
	{
		ui::Manager::instance().registerClass(name);
	}
	ui::Window Application::createWindow(WCH_STR_CONST windowName,
		WCH_STR_CONST title, const CAPE_RECT& rect, WND_STY style,
		WNDX_STY exStyle)
	{
		ui::Window window;
		window = ui::Window(ui::Manager::instance().createHandle(
			windowName, title, style, rect, ui::Base::Null, exStyle)
		);
		return window;
	}
	int Application::run()
	{
		return ui::Manager::instance().startListening();
	}
	int Application::run(ui::WindowFrame& window)
	{
		using namespace w_cape;
		Application::functorWnd = &window;
		window.onCreate();
		window.onPaint(wndOnPaint);
		//window.onCreate();
		return ui::Manager::instance().startListening();
	}
	INS_HND Application::instance()
	{
		return GetModuleHandle(NULL);
	}
	void Application::defaultFont(WCH_STR_CONST fontName)
	{
		ui::Manager::instance().defaultFont(fontName);
	}

	void Application::quit() const {
		PostQuitMessage(0);
	}
}
