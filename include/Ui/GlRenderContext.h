#ifndef GLRENDERCONTEXT_H
#define GLRENDERCONTEXT_H
#include "HasHandle.h"
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
