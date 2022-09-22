#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Ui/GuiDefaults.hpp"
#include "WinCape.hpp"

namespace w_cape{
	//To singleton...
	class Application
	{
	public:
		/// <summary>
		/// Starts the application loop
		/// </summary>
		void init(WSTR_CON name = Defaults::WND_NAM);
		ui::Window console();
		int run();
		int run(w_cape::ui::WindowFrame& window);
		INS_HND instance();
		//Really poor function, must be called at the application beginning in
		//order to work...
		void defaultFont(WSTR_CON fontName);

		ui::Window createWindow(
			WSTR_CON windowName = Defaults::WND_NAM,
			WSTR_CON title = L"Default",
			const CAPE_RECT & rect = ui::Defaults::WINDOW_RECT,
			WND_STY style = ui::Defaults::DEFWINDOW_STYLE,
			WNDX_STY exStyle = 0
		);
		//Do not touch it
		static ui::WindowFrame * functorWnd;
		static void wndOnPaint(EVENT e);

		void quit();
	};
}
#endif
