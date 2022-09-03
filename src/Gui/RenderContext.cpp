//#ifdef WINCAPE_USES_WGL
#include "defines.hpp"
#include "Gui/RenderContext.hpp"
namespace cape{
namespace usr
{
	////-------------------------------------------------------------------------
	////RenderContext
	////-------------------------------------------------------------------------
	usr::RenderContext::RenderContext() {}
	usr::RenderContext::RenderContext(GL_RCX_HND value)
	{
		handle(value);
	}
	usr::RenderContext::~RenderContext(){
		//Solo hasta haber implementado el move constructor...
		//wglDeleteContext(handle());
	}	
}}
//#endif
