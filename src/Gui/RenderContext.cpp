//#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "Gui/RenderContext.hpp"
namespace WinCape{
namespace Gui
{
	////-------------------------------------------------------------------------
	////RenderContext
	////-------------------------------------------------------------------------
	Gui::RenderContext::RenderContext() {}
	Gui::RenderContext::RenderContext(GlRenderContextHandle value)
	{
		handle(value);
	}
	Gui::RenderContext::~RenderContext(){
		//Solo hasta haber implementado el move constructor...
		//wglDeleteContext(handle());
	}	
}}
//#endif
