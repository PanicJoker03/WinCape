#include "Gui/Bitmap.hpp"
namespace WinCape{
	namespace Gui{
		//-------------------------------------------------------------------------
		//Bitmap
		//-------------------------------------------------------------------------
		Gui::Bitmap::Bitmap(const Vector2I& dimensions)
		{
			BitmapHandle bitmapHandle = CreateBitmap(dimensions.x, dimensions.y, 1, 32, NULL);
			handle(bitmapHandle);
		}

		Gui::Bitmap& Bitmap::operator = (const Bitmap& bitmap)
		{
			DeleteObject(handle());
			BitmapHandle bitmapHandle = (BitmapHandle)CopyImage(bitmap.handle(), IMAGE_BITMAP, 0, 0, NULL);
			handle(bitmapHandle);
			return *this;
		}
		void Gui::Bitmap::getBitmapInfo(const DeviceContextHandle& deviceContext, BITMAPINFO& bmpInfo) const
		{
			bmpInfo.bmiHeader.biSize = sizeof(bmpInfo.bmiHeader);
			GetDIBits(deviceContext, handle(), 0, 0, NULL, &bmpInfo, DIB_RGB_COLORS);
			bmpInfo.bmiHeader.biCompression = BI_RGB;
		}
		void Gui::Bitmap::load(const TextChar* sourcePath)
		{
			DeleteObject(handle());
			handle((BitmapHandle)LoadImage(NULL, sourcePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
		}
		Vector2I Gui::Bitmap::dimension() const
		{
			//Wonderfull code source from:
			//http://forums.codeguru.com/showthread.php?348350-Bitmap-Dimensions-after-using-LoadImage-How
			//check for handle nullity?
			BITMAP bitmap = {};
			GetObject(handle(), sizeof(bitmap), &bitmap);
			return Vector2I{ bitmap.bmWidth, bitmap.bmHeight };
		}
		void Gui::Bitmap::clonePixels(void* buffer) const
		{
			//Must call GetDIBits twice...
			//https://stackoverflow.com/questions/26233848/c-read-pixels-with-getdibits
			const DeviceContextHandle deviceContext = GetDC(NULL); //Safe?
			BITMAPINFO bitmapInfo = {};
			getBitmapInfo(deviceContext, bitmapInfo);
			GetDIBits(deviceContext, handle(), 0, bitmapInfo.bmiHeader.biHeight, buffer, &bitmapInfo, DIB_RGB_COLORS);
		}
		void Gui::Bitmap::setPixels(void* buffer)
		{
			const DeviceContextHandle deviceContext = GetDC(NULL); //Safe?
			BITMAPINFO bitmapInfo = {};
			getBitmapInfo(deviceContext, bitmapInfo);
			SetDIBits(deviceContext, handle(), 0, bitmapInfo.bmiHeader.biHeight, buffer, &bitmapInfo, DIB_RGB_COLORS);
		}
		Gui::Bitmap::~Bitmap()
		{
			DeleteObject(handle());
		}
	}
}
