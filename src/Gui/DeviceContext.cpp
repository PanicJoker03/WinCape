#include "defines.hpp"
#include "Gui/DeviceContext.hpp"
//#ifdef WINCAPE_USES_WGL
#include "Gui/RenderContext.hpp"
//#endif
#include "Gui/Window.hpp"
namespace w_cape{
namespace usr{
	//-------------------------------------------------------------------------
	//DeviceContext
	//-------------------------------------------------------------------------
	usr::DeviceContext::DeviceContext() {}
	usr::DeviceContext::DeviceContext(DCX_HND value)
	{
		handle(value);
	}
	void usr::DeviceContext::bitBlt(BMP_HND bitmapHandle, DCX_HND destiny, const CAPE_RECT& rect)
	{
		BMP_HND hbmOld = (BMP_HND)SelectObject(destiny, bitmapHandle);
		BitBlt(handle(), rect.position.x, rect.position.y, rect.size.x, rect.size.y, destiny, 0, 0, SRCCOPY);
		SelectObject(destiny, hbmOld);
	}
	usr::DeviceContext::~DeviceContext(){
		//if(handle() != NullPointer)
		//	ReleaseDC(WindowFromDC(handle()), handle());
	}
	//void DeviceContext::drawBitmap(const Bitmap& bitmap)
	//{
	//	Int2 bitmapSize = bitmap.dimension();
	//	drawBitmap(bitmap, CAPE_RECT{ 0, 0, bitmapSize });
	//}
	void usr::DeviceContext::drawBitmap(const usr::Bitmap& bitmap, const VEC_2I& padding)
	{
		DCX_HND devContextMemory = CreateCompatibleDC(handle());
		VEC_2I bmpSize = bitmap.dimension();
		bitBlt(bitmap.handle(), devContextMemory, CAPE_RECT( padding, bmpSize ));
		DeleteDC(devContextMemory);
	}
	void usr::DeviceContext::drawText(WSTR_CON text, DRW_TXT_FMAT flags){
		CAPE_RECT rec = bounds();
		SetTextColor(handle(), 0x00000000);
		SetBkMode(handle(), TRANSPARENT);
		DrawTextW(handle(), text, -1, reinterpret_cast<RECT*>(&rec), flags);
	}
	CAPE_RECT usr::DeviceContext::bounds() const {
		CAPE_RECT rec;
		GetClientRect(window().handle(), reinterpret_cast<RECT*>(&rec));
		return rec;
	}

	Window DeviceContext::window() const{
		return Window(WindowFromDC(handle()));
	}

	void DeviceContext::swapBuffers(){
		//Do not use SWAP_OVERLAY ni SWAP_UNDERLAY, I do not know their usage
		wglSwapLayerBuffers(handle(), WGL_SWAP_MAIN_PLANE);
	}
	//#ifdef WINCAPE_USES_WGL
	//-------------------------------------------------------------------------
	//RenderContext
	//-------------------------------------------------------------------------
	RenderContext
	DeviceContext::createRenderContext(const PIXEL_FORMAT& format) const {
		PIXELFORMATDESCRIPTOR dscriptor = {
			sizeof(dscriptor),
			1,
			format.flags,
			format.type, 		//Tipo de buffer
			format.colorBits,	//Profundidad de bits de framebuffer
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			format.depthBits,	//número de bits de buffer de profundidad
			format.stencilBits,	//número de bits de buffer de stencil
			0,					//número de bits auxiliares en el framebuffer
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};
		const int fmatId = ChoosePixelFormat(handle(), &dscriptor);
		SetPixelFormat(handle(), fmatId, &dscriptor);
		return RenderContext(wglCreateContext(handle()));
	}

	void DeviceContext::applyRenderContext(RenderContext context){
		wglMakeCurrent(handle(), context.handle());
	}
	//#endif
	//usr::RenderContext usr::DeviceContext::createRenderContext() const {
	//	return usr::RenderContext(wglCreateContext(handle()));
	//}
}}

