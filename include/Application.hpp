#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Gui/GuiDefaults.hpp"
#include "WinCape.hpp"
//#include "Gui/Window.hpp"
//#include "Gui/WindowFrame.hpp"


namespace WinCape{
	//To singleton...
	struct Application
	{
		/// <summary>
		/// Starts the application loop
		/// </summary>
		static void init(const wchar_t* name = Defaults::WindowName);
		static Gui::Window console();
		static int run();
		static int run(WinCape::Gui::WindowFrame& window);
		static InstanceHandle instance();
		//Really poor function, must be called at the application beginning in
		//order to work...
		static void defaultFont(const wchar_t* fontName);

		static Gui::Window createWindow(
			const wchar_t* windowName = Defaults::WindowName,
			const wchar_t* title = L"Default",
			const Rect & rect = Gui::Defaults::WindowRect,
			WindowStyle style = Gui::Defaults::DefWindowStyle,
			WindowExtendedStyle exStyle = 0
		);
		//Do not touch it
		static Gui::WindowFrame * functorWnd;
		static void wndOnPaint(Event e);

		static void quit();
	};
}
#endif
