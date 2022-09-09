#ifndef BITMAP_HPP
#define BITMAP_HPP
#include "defines.hpp"
#include "HasHandle.hpp"
namespace wcape{
namespace usr{
	class Bitmap : public HasHandle<BMP_HND>
	{
	private:
		Bitmap(const Bitmap&);
		//Bitmap& operator=(const Bitmap&) = delete;
		void getBitmapInfo(const DCX_HND& deviceContext,
				BITMAPINFO& bmpInfo) const;
	public:
		Bitmap(const VEC_2I& dimensions = VEC_2I());
		Bitmap& operator = (const Bitmap& bitmap);
		void load(WSTR_CON sourcePath);
		VEC_2I dimension() const;
		void clonePixels(void* buffer) const;
		void setPixels(void* buffer);
		~Bitmap();
	};
}}
#endif
