#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Gui/GuiDefaults.hpp"
#include "WinCape.hpp"

namespace wcape{
	//To singleton...
	class Application
	{
	public:
		/// <summary>
		/// Starts the application loop
		/// </summary>
		void init(WSTR_CON name = Defaults::WINDOW_NAME);
		usr::Window console();
		int run();
		int run(wcape::usr::WindowFrame& window);
		ISC_HND instance();
		//Really poor function, must be called at the application beginning in
		//order to work...
		void defaultFont(WSTR_CON fontName);

		usr::Window createWindow(
			WSTR_CON windowName = Defaults::WINDOW_NAME,
			WSTR_CON title = L"Default",
			const CAPE_RECT & rect = usr::Defaults::WINDOW_RECT,
			WND_STY style = usr::Defaults::DEFWINDOW_STYLE,
			WNDX_STY exStyle = 0
		);
		//Do not touch it
		static usr::WindowFrame * functorWnd;
		static void wndOnPaint(EVENT e);

		void quit();
	};
}
#endif
