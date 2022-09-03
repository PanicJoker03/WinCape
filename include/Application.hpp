#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Gui/GuiDefaults.hpp"
#include "WinCape.hpp"
//#include "Gui/Window.hpp"
//#include "Gui/WindowFrame.hpp"


namespace cape{
	//To singleton...
	struct Application
	{
		/// <summary>
		/// Starts the application loop
		/// </summary>
		static void init(CON_WSTR name = Defaults::WINDOW_NAME);
		static usr::Window console();
		static int run();
		static int run(cape::usr::WindowFrame& window);
		static ISC_HND instance();
		//Really poor function, must be called at the application beginning in
		//order to work...
		static void defaultFont(CON_WSTR fontName);

		static usr::Window createWindow(
			CON_WSTR windowName = Defaults::WINDOW_NAME,
			CON_WSTR title = L"Default",
			const CAPE_RECT & rect = usr::Defaults::WINDOW_RECT,
			WND_STY style = usr::Defaults::DEFWINDOW_STYLE,
			WNDX_STY exStyle = 0
		);
		//Do not touch it
		static usr::WindowFrame * functorWnd;
		static void wndOnPaint(EVENT e);

		static void quit();
	};
}
#endif
