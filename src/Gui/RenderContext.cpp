//#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "Gui/RenderContext.hpp"
namespace WinCape::Gui
{
	////------------------------------------------------------------------------
	////RenderContext
	////------------------------------------------------------------------------
	RenderContext::RenderContext() {}
	RenderContext::RenderContext(GlRenderContextHandle value)
	{
		handle(value);
	}

}
//#endif
