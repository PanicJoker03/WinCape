//#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "Ui/GlRenderContext.hpp"
namespace w_cape{
namespace ui
{
	////-------------------------------------------------------------------------
	////GlRenderContext
	////-------------------------------------------------------------------------
	ui::GlRenderContext::GlRenderContext() {}
	ui::GlRenderContext::GlRenderContext(GL_RCX_HND value)
	{
		handle(value);
	}
	ui::GlRenderContext::~GlRenderContext(){
		//Solo hasta haber implementado el move constructor...
		//wglDeleteContext(handle());
	}	
}}
//#endif
