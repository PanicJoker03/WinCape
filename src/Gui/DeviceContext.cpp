#include "defines.hpp"
#include "Gui/DeviceContext.hpp"
//#ifdef WINCAPE_USES_WGL
#include "Gui/RenderContext.hpp"
//#endif
#include "Gui/Window.hpp"
namespace WinCape{
	namespace Gui {
		//-------------------------------------------------------------------------
		//DeviceContext
		//-------------------------------------------------------------------------
		Gui::DeviceContext::DeviceContext() {}
		Gui::DeviceContext::DeviceContext(WindowHandle value)
		{
			handle(GetDC(value));
		}
		Gui::DeviceContext::DeviceContext(DeviceContextHandle value)
		{
			handle(value);
		}
		void Gui::DeviceContext::bitBlt(BitmapHandle bitmapHandle, DeviceContextHandle destiny, const Rect& rect)
		{
			BitmapHandle hbmOld = (BitmapHandle)SelectObject(destiny, bitmapHandle);
			BitBlt(handle(), rect.position.x, rect.position.y, rect.size.x, rect.size.y, destiny, 0, 0, SRCCOPY);
			SelectObject(destiny, hbmOld);
		}
		Gui::DeviceContext::~DeviceContext(){
			//if(handle() != NullPointer)
			//	ReleaseDC(WindowFromDC(handle()), handle());
		}
		//void DeviceContext::drawBitmap(const Bitmap& bitmap)
		//{
		//	Int2 bitmapSize = bitmap.dimension();
		//	drawBitmap(bitmap, Rect{ 0, 0, bitmapSize });
		//}
		void Gui::DeviceContext::drawBitmap(const Gui::Bitmap& bitmap, const Vector2I& padding)
		{
			DeviceContextHandle deviceContextMemory = CreateCompatibleDC(handle());
			Vector2I bitmapSize = bitmap.dimension();
			bitBlt(bitmap.handle(), deviceContextMemory, Rect{ padding, bitmapSize });
			DeleteDC(deviceContextMemory);
		}
		void Gui::DeviceContext::drawText(const TextChar* text, DrawTextFormat flags){
			Rect rect = bounds();
			SetTextColor(handle(), 0x00000000);
			SetBkMode(handle(), TRANSPARENT);
	#ifndef UNICODE
			DrawTextA(handle(), text, -1, reinterpret_cast<RECT*>(&rect), flags);
	#else
			DrawTextW(handle(), text, -1, reinterpret_cast<RECT*>(&rect), flags);
	#endif
		}
		Rect Gui::DeviceContext::bounds() const {
			Rect rect;
			GetClientRect(window().handle(), reinterpret_cast<RECT*>(&rect));
			return rect;
		}

		Window Gui::DeviceContext::window() const{
			return Window(WindowFromDC(handle()));
		}
		#ifdef WINCAPE_USES_WGL
		//-------------------------------------------------------------------------
		//DeviceContext
		//-------------------------------------------------------------------------
		RenderContext Gui::DeviceContext::createRenderContext() const {
			return RenderContext(wglCreateContext(handle()));
		}
		#endif
		//Gui::RenderContext Gui::DeviceContext::createRenderContext() const {
		//	return Gui::RenderContext(wglCreateContext(handle()));
		//}
	}
}
