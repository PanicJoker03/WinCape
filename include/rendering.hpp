#ifdef WINCAPE_USES_WGL
#ifndef RENDERING_HPP
#define RENDERING_HPP
#include "WinCape.hpp"
//TODO...
//Use lower case on static methods
namespace WinCape
{
	namespace Gui
	{
		class RenderContext final : public HasHandle<GlRenderContextHandle> {
		public:
			RenderContext();
			RenderContext(GlRenderContextHandle renderContext);
			friend Window;
		};
	}
}
#endif
#endif
