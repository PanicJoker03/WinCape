#ifndef BITMAP_H
#define BITMAP_H
#include "defines.h"
#include "HasHandle.h"
namespace w_cape{
namespace ui{
	class Bitmap : public HasHandle<BMP_HND>
	{
	private:
		Bitmap(const Bitmap&);
		//Bitmap& operator=(const Bitmap&) = delete;
		void getBitmapInfo(const DCX_HND& deviceContext,
				BITMAPINFO& bmpInfo) const;
	public:
		Bitmap(const I_VEC_2& dimensions = I_VEC_2());
		Bitmap& operator = (const Bitmap& bitmap);
		void load(WCH_STR_CON sourcePath);
		I_VEC_2 dimension() const;
		void clonePixels(void* buffer) const;
		void setPixels(void* buffer);
		~Bitmap();
	};
}}
#endif
