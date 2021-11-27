#ifndef WINCAPE_HPP
#define WINCAPE_HPP
#include "defines.hpp"
#include "defaults.hpp"

#include "Gui.hpp"
#ifdef WINCAPE_USES_WGL
#include "rendering.hpp"
#endif
#include "Application.hpp"

//TODO...
//Use lower case on static methods
namespace WinCape
{
	namespace Gui
	{
	/*
		//forward declarations
		class Window;
		class Button;
		class RadioButton;
		class Menu;
		class Icon;
		class DeviceContext;
		class Bitmap;
		class WindowFrame;

#ifdef WINCAPE_USES_WGL
		class RenderContext;
#endif
*/

	}
}

namespace WinCape{
	namespace Base
	{
		const Gui::Window Console();
	}
}
#endif
