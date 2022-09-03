#ifndef WINDOWFRAME_HPP
#define WINDOWFRAME_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "GuiDefaults.hpp"
#include "Window.hpp"
namespace cape{
struct Application;
namespace usr{
	//////////////////////////
	//High level abstraction//
	//////////////////////////
	class WindowFrame : public Window
	{
	public:
		friend cape::Application;
	private:
		CON_WSTR windowName;
		const CAPE_RECT rect;
	    WND_STY style;
	protected:
		WindowFrame(CON_WSTR windowName = cape::Defaults::WINDOW_NAME,
			CON_WSTR title = L"Default",
			const CAPE_RECT& rect = usr::Defaults::WINDOW_RECT,
			WND_STY style = usr::Defaults::DEFWINDOW_STYLE
		);

		virtual void onCreate() = 0;
		virtual void onDraw(DeviceContext deviceContext) = 0;
		virtual void onDispose();
		virtual ~WindowFrame() = 0;
	};
}}
#endif
