#ifndef DEVICECONTEXT_HPP
#define DEVICECONTEXT_HPP
#include "defines.hpp"
#include "Gui/Bitmap.hpp"
//#ifdef WINCAPE_USES_WGL
#include "Gui/RenderContext.hpp"
//#endif
namespace WinCape
{
	namespace Gui{
		class Window;
		class DeviceContext final : public HasHandle<DeviceContextHandle>
		{
		public:
			DeviceContext();
			DeviceContext(DeviceContextHandle value);
			DeviceContext(WindowHandle handle);
			//void drawBitmap(const Bitmap& bitmap);
			void drawBitmap(const Bitmap& bitmap, const Vector2I& padding = Vector2I{});
			void drawText(const TextChar* text, DrawTextFormat format);
			Rect bounds() const;
			Window window() const;
			//drawBitmapClipped...
			//#ifdef WINCAPE_USES_WGL
			RenderContext createRenderContext() const;
			//#endif
			~DeviceContext();
			friend Window;
		private:
			void bitBlt(BitmapHandle bitmapHandle, DeviceContextHandle destiny, const Rect& rect);
		};
	}
}
#endif
