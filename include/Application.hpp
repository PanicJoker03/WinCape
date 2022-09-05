#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Gui/GuiDefaults.hpp"
#include "WinCape.hpp"

namespace cap{
	//To singleton...
	struct Application
	{
		/// <summary>
		/// Starts the application loop
		/// </summary>
		static void init(WSTR_CON name = Defaults::WINDOW_NAME);
		static usr::Window console();
		static int run();
		static int run(cap::usr::WindowFrame& window);
		static ISC_HND instance();
		//Really poor function, must be called at the application beginning in
		//order to work...
		static void defaultFont(WSTR_CON fontName);

		static usr::Window createWindow(
			WSTR_CON windowName = Defaults::WINDOW_NAME,
			WSTR_CON title = L"Default",
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
