#include "defines.hpp"
#include "HasHandle.hpp"
#include "Application.hpp"

using namespace std;
namespace WinCape
{
	namespace Base
	{
		//const Gui::Window Console(){
		//	return Gui::Window(GetConsoleWindow());
		//}
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
	template class HasHandle<InstanceHandle>;
}
