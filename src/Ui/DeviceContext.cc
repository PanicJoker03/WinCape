#include "defines.h"
#include "Ui/DeviceContext.h"
//#ifdef WINCAPE_USES_WGL
#include "Ui/GlRenderContext.h"
//#endif
#include "Ui/Window.h"
namespace w_cape{
namespace ui{
	//-------------------------------------------------------------------------
	//DeviceContext
	//-------------------------------------------------------------------------
	ui::DeviceContext::DeviceContext() {}
	ui::DeviceContext::DeviceContext(DCX_HND value)
	{
		handle(value);
	}
	void ui::DeviceContext::bitBlt(BMP_HND bitmapHandle, DCX_HND destiny, const CAPE_RECT& rect)
	{
		BMP_HND hbmOld = (BMP_HND)SelectObject(destiny, bitmapHandle);
		BitBlt(handle(), rect.position.x, rect.position.y, rect.size.x, rect.size.y, destiny, 0, 0, SRCCOPY);
		SelectObject(destiny, hbmOld);
	}
	ui::DeviceContext::~DeviceContext(){
		//if(handle() != NullPointer)
		//	ReleaseDC(WindowFromDC(handle()), handle());
	}
	//void DeviceContext::drawBitmap(const Bitmap& bitmap)
	//{
	//	Int2 bitmapSize = bitmap.dimension();
	//	drawBitmap(bitmap, CAPE_RECT{ 0, 0, bitmapSize });
	//}
	void ui::DeviceContext::drawBitmap(const ui::Bitmap& bitmap, const I_VEC_2& padding)
	{
		DCX_HND devContextMemory = CreateCompatibleDC(handle());
		I_VEC_2 bmpSize = bitmap.dimension();
		bitBlt(bitmap.handle(), devContextMemory, CAPE_RECT( padding, bmpSize ));
		DeleteDC(devContextMemory);
	}
	void ui::DeviceContext::drawText(WCH_STR_CONST text, DRW_TXT_4MAT flags){
		CAPE_RECT rec = bounds();
		SetTextColor(handle(), 0x00000000);
		SetBkMode(handle(), TRANSPARENT);
		DrawTextW(handle(), text, -1, reinterpret_cast<RECT*>(&rec), flags);
	}
	CAPE_RECT ui::DeviceContext::bounds() const {
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
	//GlRenderContext
	//-------------------------------------------------------------------------
	GlRenderContext
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
		return GlRenderContext(wglCreateContext(handle()));
	}

	void DeviceContext::applyRenderContext(GlRenderContext context){
		wglMakeCurrent(handle(), context.handle());
	}
	//#endif
	//ui::GlRenderContext ui::DeviceContext::createRenderContext() const {
	//	return ui::GlRenderContext(wglCreateContext(handle()));
	//}
}}

