#ifndef RENDERCONTEXT_HPP
#define RENDERCONTEXT_HPP
#include "HasHandle.hpp"
namespace w_cape{
namespace ui{
	class Window;
	class RenderContext : public HasHandle<GL_RCX_HND> {
	public:
		RenderContext();
		RenderContext(GL_RCX_HND renderContext);
		~RenderContext();
		friend Window;
	};
}}
#endif
