//#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "Ui/RenderContext.hpp"
namespace w_cape{
namespace ui
{
	////-------------------------------------------------------------------------
	////RenderContext
	////-------------------------------------------------------------------------
	ui::RenderContext::RenderContext() {}
	ui::RenderContext::RenderContext(GL_RCX_HND value)
	{
		handle(value);
	}
	ui::RenderContext::~RenderContext(){
		//Solo hasta haber implementado el move constructor...
		//wglDeleteContext(handle());
	}	
}}
//#endif
