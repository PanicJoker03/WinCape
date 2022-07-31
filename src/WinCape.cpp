#include "defines.hpp"
#include "Application.hpp"
#include "Manager.hpp"
#include <vector>
#include <iostream>
#include <map>
#include "Gui/Window.hpp"
#include "Gui/WindowFrame.hpp"

using namespace std;
namespace WinCape
{
	namespace Base
	{
		const Gui::Window Console(){
			return Gui::Window(GetConsoleWindow());
		}
	}
	wchar_t *textCopy(wchar_t* dest, const wchar_t* src){
        return wcscpy(dest, src);
	}
	//--------------------------------------------------------------------------
	//Avoiding template linkage errors
	//--------------------------------------------------------------------------
	template class HasHandle<WindowHandle>;
	template class HasHandle<IconHandle>;
	template class HasHandle<BitmapHandle>;
	template class HasHandle<FontHandle>;
	template class HasHandle<DeviceContextHandle>;
//#ifdef WINCAPE_USES_WGL
	template class HasHandle<GlRenderContextHandle>;
//#endif
	template class HasHandle<MenuHandle>;
}
