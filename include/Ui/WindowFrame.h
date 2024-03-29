#ifndef WINDOWFRAME_H
#define WINDOWFRAME_H
#include "defines.h"
#include "defaults.h"
#include "UiDefaults.h"
#include "Window.h"
namespace w_cape{
struct Application;
namespace ui{
	//////////////////////////
	//High level abstraction//
	//////////////////////////
	class WindowFrame : public Window
	{
	public:
		friend w_cape::Application;
	private:
		WCH_STR_CONST windowName;
		const CAPE_RECT rect;
	    WND_STY style;
	protected:
		WindowFrame(WCH_STR_CONST windowName = w_cape::Defaults::WND_NAM,
			WCH_STR_CONST title = L"Default",
			const CAPE_RECT& rect = ui::Defaults::WINDOW_RECT,
			WND_STY style = ui::Defaults::DEFWINDOW_STYLE
		);

		virtual void onCreate() = 0;
		virtual void onDraw(DeviceContext deviceContext) = 0;
		virtual void onDispose();
		virtual ~WindowFrame() = 0;
	};
}}
#endif
