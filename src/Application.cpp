#include "defines.hpp"
#include "Ui/Manager.hpp"
#include "Ui/Window.hpp"
#include "Ui/WindowFrame.hpp"
#include "Application.hpp"
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
	void Application::init(WSTR_CON name)
	{
		ui::Manager::instance().registerClass(name);
	}
	ui::Window Application::createWindow(WSTR_CON windowName,
		WSTR_CON title, const CAPE_RECT& rect, WND_STY style,
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
	void Application::defaultFont(WSTR_CON fontName)
	{
		ui::Manager::instance().defaultFont(fontName);
	}

	void Application::quit() {
		PostQuitMessage(0);
	}
}
