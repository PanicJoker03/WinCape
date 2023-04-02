#ifndef DEVICECONTEXT_H
#define DEVICECONTEXT_H
//#include "defines.h"
#include "Ui/Bitmap.h"
//#ifdef WINCAPE_USES_WGL
#include "Ui/GlRenderContext.h"
//#endif
namespace w_cape{
namespace ui{
	class Window;
	class DeviceContext : public HasHandle<DCX_HND>
	{
	public:
		DeviceContext();
		explicit DeviceContext(DCX_HND value);
		//void drawBitmap(const Bitmap& bitmap);
		void drawBitmap(const Bitmap& bitmap,
				const I_VEC_2& padding = I_VEC_2());
		void drawText(WCH_STR_CON text, DRW_TXT_4MAT format);
		CAPE_RECT bounds() const;
		Window window() const;
		//drawBitmapClipped...
		//#ifdef WINCAPE_USES_WGL
		GlRenderContext createRenderContext(const PIXEL_FORMAT& format) const;
		void swapBuffers();
		void applyRenderContext(GlRenderContext context);
		//#endif
		~DeviceContext();
		friend Window;
	private:
		void bitBlt(BMP_HND bitmapHandle, DCX_HND destiny,
				const CAPE_RECT& rect);
	};
}}
#endif
