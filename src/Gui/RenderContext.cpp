//#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "Gui/RenderContext.hpp"
namespace WinCape
{
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
	}
}
//#endif
