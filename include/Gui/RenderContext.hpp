#ifndef RENDERCONTEXT_HPP
#define RENDERCONTEXT_HPP
#include "HasHandle.hpp"
namespace WinCape{
	namespace Gui{
		class Window;
		class RenderContext final : public HasHandle<GlRenderContextHandle> {
		public:
			RenderContext();
			RenderContext(GlRenderContextHandle renderContext);
			~RenderContext();
			friend Window;
		};
	}
}
#endif
