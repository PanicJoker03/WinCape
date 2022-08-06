#ifndef DEVICECONTEXT_HPP
#define DEVICECONTEXT_HPP
//#include "defines.hpp"
#include "Gui/Bitmap.hpp"
//#ifdef WINCAPE_USES_WGL
#include "Gui/RenderContext.hpp"
//#endif
namespace WinCape
{
	namespace Gui{
		class Window;
		class DeviceContext : public HasHandle<DeviceContextHandle>
		{
		public:
			DeviceContext();
			explicit DeviceContext(DeviceContextHandle value);
			explicit DeviceContext(WindowHandle handle);
			//void drawBitmap(const Bitmap& bitmap);
			void drawBitmap(const Bitmap& bitmap,
					const Vector2I& padding = Vector2I());
			void drawText(const wchar_t* text, DrawTextFormat format);
			Rect bounds() const;
			Window window() const;
			//drawBitmapClipped...
			//#ifdef WINCAPE_USES_WGL
			RenderContext createRenderContext(const PixelFormat& format) const;
			void swapBuffers();
			void applyRenderContext(RenderContext context);
			//#endif
			~DeviceContext();
			friend Window;
		private:
			void bitBlt(BitmapHandle bitmapHandle, DeviceContextHandle destiny,
					const Rect& rect);
		};
	}
}
#endif
