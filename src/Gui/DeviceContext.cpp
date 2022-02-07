#include "defines.hpp"
#include "Gui/DeviceContext.hpp"
//#ifdef WINCAPE_USES_WGL
#include "Gui/RenderContext.hpp"
//#endif
#include "Gui/Window.hpp"
namespace WinCape::Gui
{
	//-------------------------------------------------------------------------
	//DeviceContext
	//-------------------------------------------------------------------------
	DeviceContext::DeviceContext() {}
	DeviceContext::DeviceContext(WindowHandle value)
	{
		handle(GetDC(value));
	}
	DeviceContext::DeviceContext(DeviceContextHandle value)
	{
		handle(value);
	}
	void DeviceContext::bitBlt(BitmapHandle bitmapHandle,
		DeviceContextHandle destiny, const Rect& rect)
	{
		BitmapHandle hbmOld = (BitmapHandle)SelectObject(destiny, bitmapHandle);
		BitBlt(
			handle(),
			rect.position.x,
			rect.position.y,
			rect.size.x,
			rect.size.y,
			destiny,
			0,
			0,
			SRCCOPY
		);
		SelectObject(destiny, hbmOld);
	}
	DeviceContext::~DeviceContext(){
		//if(handle() != NullPointer)
		//	ReleaseDC(WindowFromDC(handle()), handle());
	}
	//void DeviceContext::drawBitmap(const Bitmap& bitmap)
	//{
	//	Int2 bitmapSize = bitmap.dimension();
	//	drawBitmap(bitmap, Rect{ 0, 0, bitmapSize });
	//}
	void DeviceContext::drawBitmap(const Gui::Bitmap& bitmap,
		const Vector2I& padding)
	{
		DeviceContextHandle deviceContextMemory = CreateCompatibleDC(handle());
		Vector2I bitmapSize = bitmap.dimension();
		bitBlt(bitmap.handle(), deviceContextMemory,
			Rect{
				padding,
				bitmapSize
			}
		);
		DeleteDC(deviceContextMemory);
	}
	void DeviceContext::drawText(const TextChar* text, DrawTextFormat flags){
		Rect rect = bounds();
		SetTextColor(handle(), 0x00000000);
		SetBkMode(handle(), TRANSPARENT);
#ifndef UNICODE
		DrawTextA(handle(), text, -1, reinterpret_cast<RECT*>(&rect), flags);
#else
		DrawTextW(handle(), text, -1, reinterpret_cast<RECT*>(&rect), flags);
#endif
	}
	Rect DeviceContext::bounds() const {
		Rect rect;
		GetClientRect(window().handle(), reinterpret_cast<RECT*>(&rect));
		return rect;
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
	DeviceContext::createRenderContext(const PixelFormat& format) const {
		PIXELFORMATDESCRIPTOR descriptor = {
			sizeof(PIXELFORMATDESCRIPTOR),
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
		const int formatId = ChoosePixelFormat(handle(), &descriptor);
		SetPixelFormat(handle(), formatId, &descriptor);
		return RenderContext(wglCreateContext(handle()));
	}

	void DeviceContext::applyRenderContext(RenderContext context){
		wglMakeCurrent(handle(), context.handle());
	}
	//#endif
	//Gui::RenderContext Gui::DeviceContext::createRenderContext() const {
	//	return Gui::RenderContext(wglCreateContext(handle()));
	//}
}

