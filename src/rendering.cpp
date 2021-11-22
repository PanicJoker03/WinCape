#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "rendering.hpp"
#include "WinCape.hpp"
namespace WinCape
{
	namespace Gui 
	{
		class RenderContext;
		////-------------------------------------------------------------------------
		////RenderContext
		////-------------------------------------------------------------------------
		Gui::RenderContext::RenderContext() {}
		Gui::RenderContext::RenderContext(GlRenderContextHandle value)
		{
			handle(value);
		}

		//-------------------------------------------------------------------------
		//DeviceContext
		//-------------------------------------------------------------------------
		Gui::RenderContext Gui::DeviceContext::createRenderContext() const {
			return Gui::RenderContext(wglCreateContext(handle()));
		}
	}
	template class HasHandle<GlRenderContextHandle>;
}
#endif
