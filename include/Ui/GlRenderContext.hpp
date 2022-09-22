#ifndef GLRENDERCONTEXT_HPP
#define GLRENDERCONTEXT_HPP
#include "HasHandle.hpp"
namespace w_cape{
namespace ui{
	class Window;
	class GlRenderContext : public HasHandle<GL_RCX_HND> {
	public:
		GlRenderContext();
		GlRenderContext(GL_RCX_HND GlRenderContext);
		~GlRenderContext();
		friend Window;
	};
}}
#endif
