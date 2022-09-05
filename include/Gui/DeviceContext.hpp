#ifndef DEVICECONTEXT_HPP
#define DEVICECONTEXT_HPP
//#include "defines.hpp"
#include "Gui/Bitmap.hpp"
//#ifdef WINCAPE_USES_WGL
#include "Gui/RenderContext.hpp"
//#endif
namespace cap{
namespace usr{
	class Window;
	class DeviceContext : public HasHandle<DCX_HND>
	{
	public:
		DeviceContext();
		explicit DeviceContext(DCX_HND value);
		//void drawBitmap(const Bitmap& bitmap);
		void drawBitmap(const Bitmap& bitmap,
				const VEC_2I& padding = VEC_2I());
		void drawText(WSTR_CON text, DRW_TXT_FMAT format);
		CAPE_RECT bounds() const;
		Window window() const;
		//drawBitmapClipped...
		//#ifdef WINCAPE_USES_WGL
		RenderContext createRenderContext(const PIXEL_FORMAT& format) const;
		void swapBuffers();
		void applyRenderContext(RenderContext context);
		//#endif
		~DeviceContext();
		friend Window;
	private:
		void bitBlt(BMP_HND bitmapHandle, DCX_HND destiny,
				const CAPE_RECT& rect);
	};
}}
#endif
