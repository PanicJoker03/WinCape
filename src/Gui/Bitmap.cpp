#include "Gui/Bitmap.hpp"
namespace cap{
namespace usr{
	//-------------------------------------------------------------------------
	//Bitmap
	//-------------------------------------------------------------------------
	Bitmap::Bitmap(const Bitmap&){
        throw "Can't do that";
    };
	Bitmap::Bitmap(const VEC_2I& dimensions)
	{
		BMP_HND hnd = CreateBitmap(
			dimensions.x, dimensions.y,
			1, 32,
			NULL
		);
		handle(hnd);
	}

	Bitmap& Bitmap::operator = (const Bitmap& bitmap)
	{
		DeleteObject(handle());
		BMP_HND hnd = (BMP_HND)CopyImage(bitmap.handle(),
				IMAGE_BITMAP, 0, 0, 0);
		handle(hnd);
		return *this;
	}
	void Bitmap::getBitmapInfo(const DCX_HND& deviceContext,
		BITMAPINFO& bmpInfo) const
	{
		bmpInfo.bmiHeader.biSize = sizeof(bmpInfo.bmiHeader);
		GetDIBits(deviceContext, handle(), 0, 0, NULL, &bmpInfo,
			DIB_RGB_COLORS);
		bmpInfo.bmiHeader.biCompression = BI_RGB;
	}
	void Bitmap::load(WSTR_CON sourcePath)
	{
		DeleteObject(handle());
		handle((BMP_HND)LoadImageW(NULL, sourcePath, IMAGE_BITMAP, 0, 0,
			LR_LOADFROMFILE));
	}
	VEC_2I Bitmap::dimension() const
	{
		//Wonderfull code source from:
		//http://forums.codeguru.com/showthread.php?348350-Bitmap-Dimensions-after-using-LoadImage-How
		//check for handle nullity?
		BITMAP bitmap = {};
		GetObject(handle(), sizeof(bitmap), &bitmap);
		return VEC_2I( bitmap.bmWidth, bitmap.bmHeight );
	}
	void Bitmap::clonePixels(void* buffer) const
	{
		//Must call GetDIBits twice...
		//https://stackoverflow.com/questions/26233848/c-read-pixels-with-getdibits
		const DCX_HND deviceContext = GetDC(NULL); //Safe?
		BITMAPINFO bitmapInfo = {};
		getBitmapInfo(deviceContext, bitmapInfo);
		GetDIBits(
			deviceContext,
			handle(),
			0,
			bitmapInfo.bmiHeader.biHeight,
			buffer,
			&bitmapInfo,
			DIB_RGB_COLORS
		);
	}
	void Bitmap::setPixels(void* buffer)
	{
		const DCX_HND deviceContext = GetDC(NULL); //Safe?
		BITMAPINFO bitmapInfo = {};
		getBitmapInfo(deviceContext, bitmapInfo);
		SetDIBits(
			deviceContext,
			handle(),
			0,
			bitmapInfo.bmiHeader.biHeight,
			buffer,
			&bitmapInfo,
			DIB_RGB_COLORS
		);
	}
	Bitmap::~Bitmap()
	{
		DeleteObject(handle());
	}
}}
