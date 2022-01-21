#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "Gui/Window.hpp"
#include "Gui/WindowFrame.hpp"


namespace WinCape{

	//To singleton...
	struct Application
	{
		/// <summary>
		/// Starts the application loop
		/// </summary>
		///
		static void init(const TextChar* name = Defaults::WindowName);
		static Gui::Window console();
		static int run();
		static int run(WinCape::Gui::WindowFrame& window);
		static InstanceHandle instance();
		//Really poor function, must be called at the application beginning in order to work...
		static void defaultFont(const TextChar* fontName);
		static Gui::Window createWindow(const TextChar* windowName = Defaults::WindowName, const TextChar* title = Text("Default"), const Rect & rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle, WindowExtendedStyle exStyle = 0);
		static void quit();
	};
}
#endif
